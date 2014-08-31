/**
 *
 * �� �� �� : SRawSocketRecv.cpp
 * �������� : 2011-12-1 10:38
 * ��    �� : �ۿ���(skt001@163.com)
 * �޸����� : $Date: $
 * ��ǰ�汾 : $Revision: $
 * �������� : 
 * �޸ļ�¼ : 
 *            $Log: $
 *
 **/

#include "SRawSocket.h"

SRawSocketRecv::SRawSocketRecv()
{
	m_pCallbackOnReceive = NULL;
	m_pCallbackUserPtr = NULL;
	m_iRecvBufferSize = 20*1024*1024;
#ifdef WIN32
	m_pCap=NULL;
#else
	m_pRawsock = NULL;
#endif
	m_pGetWriteBuffer = NULL;
	m_iMaxWriteBufferLen = 0;
	m_pFilterBytes = NULL;
	m_iFilterByteLen = 0;
}

SRawSocketRecv::~SRawSocketRecv()
{
#ifdef WIN32
	if(m_pCap != NULL)
	{
		pcap_close(m_pCap);
		m_pCap = NULL;
	}
#endif
	if(m_pFilterBytes != NULL)
		delete[] m_pFilterBytes;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ��������
// ��    ��:  �ۿ���
// ����ʱ��:  2011-12-1 10:37
// ����˵��:  void
// �� �� ֵ:  true��ʾ���������ɹ�,false��ʾ��������ʧ��
//////////////////////////////////////////////////////////////////////////
bool SRawSocketRecv::Start()
{
	if(!SService::Start())
		return false;
#ifdef WIN32
	if ((m_pCap = pcap_open_live(m_sDevName.data(),		// name of the device
							 65536,			// portion of the packet to capture. It doesn't matter in this case 
							 1,				// promiscuous mode (nonzero means promiscuous)
							 1000,			// read timeout
							 m_ErrBuf			// error buffer
							 )) == NULL)
	{
		LOGERROR("�޷�������. '%s' ����WinPcap֧�ֵ���Ч�豸��!", m_sDevName.data());
		return false;
	}
#else
	int eth_index = if_nametoindex(m_sDevName.data());
	if(eth_index == 0)
	{
		LOGERROR("��Ч�������豸��[%s]",m_sDevName.data());
		return false;
	}
#endif
	SKT_CREATE_THREAD_S(ThreadPcap,this,512000);
	return true;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ֹͣ����
// ��    ��:  �ۿ���
// ����ʱ��:  2011-12-1 10:37
// ����˵��:  void
// �� �� ֵ:  true��ʾ����ֹͣ�ɹ�,false��ʾ����ֹͣʧ��
//////////////////////////////////////////////////////////////////////////
bool SRawSocketRecv::Stop()
{
	if(!SService::Stop())
		return false;

#ifdef WIN32
	if(m_pCap != NULL)
	{
		pcap_breakloop(m_pCap);
		while(!IsStoped())
			SApi::UsSleep(1000);
		pcap_close(m_pCap);
		m_pCap = NULL;
	}
#else
	if(m_pRawsock != NULL && *m_pRawsock > 0)
	{
		shutdown(*m_pRawsock, 2);
		close(*m_pRawsock);
		while(!IsStoped())
			SApi::UsSleep(1000);
		*m_pRawsock = 0;
	}

#endif
	return true;
}

//////////////////////////////////////////////////////////////////////////
// ��    ��:  ���ù����ֽ�
// ��    ��:  �ۿ���
// ����ʱ��:  2012-2-1 8:47
// ����˵��:  @pFilterBytes�����ֽ��׵�ַ
//            @len�����ֽڳ���
//            @iFilterOffsetPos����λ�ã�����ԭʼ�����е�ƫ���ֽ���
//            @bFilterExcept:true��ʾ���˵�����ָ�����ݵı��ģ�false��ʾ���˵�����ָ�����ݵı���
// �� �� ֵ:  void
//////////////////////////////////////////////////////////////////////////
void SRawSocketRecv::SetFilterBytes(BYTE *pFilterBytes,int len,int iFilterOffsetPos,bool bFilterExcept)
{
	if(m_pFilterBytes != NULL)
	{
		delete[] m_pFilterBytes;
	}
	m_pFilterBytes = new BYTE[len];
	memcpy(m_pFilterBytes,pFilterBytes,len);
	m_iFilterByteLen = len;
	m_iFilterOffsetPos = iFilterOffsetPos;
	m_bFilterExcept = bFilterExcept;
}

#ifdef WIN32
void SRawSocketRecv::ys_packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
	SRawSocketRecv *pThis = (SRawSocketRecv*)param;
	if(pThis->m_pFilterBytes != NULL)
	{
		if(pThis->m_bFilterExcept)
		{
			if(memcmp(((BYTE*)pkt_data)+pThis->m_iFilterOffsetPos,pThis->m_pFilterBytes,pThis->m_iFilterByteLen) == 0)
				return;

		}
		else
		{
			if(memcmp(((BYTE*)pkt_data)+pThis->m_iFilterOffsetPos,pThis->m_pFilterBytes,pThis->m_iFilterByteLen) != 0)
				return;
		}
	}
	if(pThis->m_pGetWriteBuffer != NULL)
	{
		BYTE *pBuf = pThis->m_pGetWriteBuffer(pThis->m_pCallbackUserPtr);
		memcpy(pBuf,(BYTE*)pkt_data,header->len);
		if(pThis->m_pCallbackOnReceive == NULL)
		{
			pThis->OnReceive(header->ts.tv_sec,header->ts.tv_usec,(BYTE*)pkt_data,header->len);
			return;
		}
		pThis->m_pCallbackOnReceive(pThis->m_pCallbackUserPtr,header->ts.tv_sec,header->ts.tv_usec,pBuf,header->len);
		return;
	}
	if(pThis->m_pCallbackOnReceive == NULL)
	{
		pThis->OnReceive(header->ts.tv_sec,header->ts.tv_usec,(BYTE*)pkt_data,header->caplen);
		return;
	}
	pThis->m_pCallbackOnReceive(pThis->m_pCallbackUserPtr,header->ts.tv_sec,header->ts.tv_usec,(BYTE*)pkt_data,header->caplen);
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  PCAPץ���߳�
// ��    ��:  �ۿ���
// ����ʱ��:  2011-12-1 9:35
// ����˵��:  this
// �� �� ֵ:  NULL
//////////////////////////////////////////////////////////////////////////
void* SRawSocketRecv::ThreadPcap(void *lp)
{
	SRawSocketRecv *pThis = (SRawSocketRecv*)lp;
	if(pThis->m_pCap == NULL)
		return NULL;
	pThis->BeginThread();
	pcap_loop(pThis->m_pCap, 0, ys_packet_handler, (BYTE*)lp);
	pThis->EndThread();
	return NULL;
}

#else

void SRawSocketRecv::raw_die(char *why, int n) 
{ 
    perror(why); 
    exit(n); 
}

//�޸�������PROMISC(����)ģʽ 
bool SRawSocketRecv::raw_do_promisc(char *nif, int sock ) 
{
	LOGDEBUG("��������(%s)Ϊ����ģʽ!",nif);

    struct ifreq ifr; 
    strncpy(ifr.ifr_name, nif,strlen(nif)+1); 
    if ((ioctl(sock, SIOCGIFFLAGS, &ifr) == -1)) //���flag 
    { 
		LOGERROR("Error in raw_do_promisc");
        return false;//raw_die("ioctl", 2); 
    } 
    ifr.ifr_flags |= IFF_PROMISC; //����flag��־ 
    if (ioctl(sock, SIOCSIFFLAGS, &ifr) == -1 ) //�ı�ģʽ 
    { 
		LOGERROR("Error in raw_do_promisc");
        return false;//raw_die("ioctl", 3); 
    }
	return true;
}

void SRawSocketRecv::raw_set_recvbuffer(int sock,int iBufferSize)
{
	socklen_t sizelen = 4;
	int ret;
	ret = setsockopt(sock,SOL_SOCKET,SO_RCVBUF,(char*)&iBufferSize,sizelen);
	if (ret != 0)
	{
		int err;
		#ifdef WIN32
			err = WSAGetLastError();
		#else
			err = errno;
		#endif
		LOGWARN("Error in raw_set_recvbuffer(%d), err=%d",iBufferSize,err);
	}
	else
	{
		iBufferSize = 0;
		ret = getsockopt(sock,SOL_SOCKET,SO_RCVBUF,(char*)&iBufferSize,&sizelen);
		LOGDEBUG("getsockopt=%d bytes!",iBufferSize);
	}
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  PCAPץ���߳�
// ��    ��:  �ۿ���
// ����ʱ��:  2011-12-1 9:35
// ����˵��:  this
// �� �� ֵ:  NULL
//////////////////////////////////////////////////////////////////////////
void* SRawSocketRecv::ThreadPcap(void *lp)
{
	SRawSocketRecv *pThis = (SRawSocketRecv*)lp;
	pThis->BeginThread();
    struct sockaddr_ll addr; 

    char mac[16]; 
    int i,sock, r, len,soc_usec[2];
    char *data; 
    char *ptemp; 
    char ss[32],dd[32];
	soc_usec[0]=0;
	soc_usec[1]=0;
    if ((sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) == -1) //����socket//man socket���Կ������漸�������˼�Կ� 
    { 
        raw_die("socket", 1); 
    } 
	pThis->m_pRawsock = &sock;
	if(pThis->m_iRecvBufferSize > 0)
	{
		raw_set_recvbuffer(sock,pThis->m_iRecvBufferSize/4);
		raw_set_recvbuffer(sock,pThis->m_iRecvBufferSize/2);
		raw_set_recvbuffer(sock,pThis->m_iRecvBufferSize);
	}

    bool bethok = raw_do_promisc((char*)pThis->m_sDevName.data()/*"eth0"*/, sock); //eth0Ϊ������ 
	int eth_index = if_nametoindex(pThis->m_sDevName.data());
	if(!bethok || eth_index == 0)
	{
		LOGFAULT("��Ч�ļ�������(%s),����ԭʼץ��ʧ��!!!",pThis->m_sDevName.data());
		pThis->EndThread();
		return 0;
	}
	LOGDEBUG("��������(%s)��ifindex=%d��!",pThis->m_sDevName.data(),eth_index);
	//sll_ifindex; //�����ֽ���
    len = sizeof(addr);

	if(pThis->m_pGetWriteBuffer == NULL)
	{
		//û�л������ص�
		BYTE buffer[2100];//������
		while(!pThis->IsQuit())
		{
			r = recvfrom(sock,(char *)buffer,sizeof(buffer), 0, (struct sockaddr *)&addr,(socklen_t *)&len); 

			if(r <= 0 || addr.sll_ifindex != eth_index)
				continue;
			SDateTime::getSystemTime(soc_usec[0],soc_usec[1]);
			if(pThis->m_pFilterBytes != NULL)
			{
				if(pThis->m_bFilterExcept)
				{
					if(memcmp(&buffer[pThis->m_iFilterOffsetPos],pThis->m_pFilterBytes,pThis->m_iFilterByteLen) == 0)
						continue;
				}
				else
				{
					if(memcmp(&buffer[pThis->m_iFilterOffsetPos],pThis->m_pFilterBytes,pThis->m_iFilterByteLen) != 0)
						continue;
				}
			}

			if(pThis->m_pCallbackOnReceive == NULL)
			{
				pThis->OnReceive(soc_usec[0],soc_usec[1],buffer,r);
				continue;
			}
			pThis->m_pCallbackOnReceive(pThis->m_pCallbackUserPtr,soc_usec[0],soc_usec[1],buffer,r);

		} 
	}
	else
	{
		BYTE *pRecvBuffer;
		while(!pThis->IsQuit())
		{
			pRecvBuffer = pThis->m_pGetWriteBuffer(pThis->m_pCallbackUserPtr);
			if(pRecvBuffer == NULL)
			{
				LOGFAULT("ȱ���н��ջ�����!���������쳣����");
				exit(1);
				break;
			}
			r = recvfrom(sock,(char *)pRecvBuffer,pThis->m_iMaxWriteBufferLen, 0, (struct sockaddr *)&addr,(socklen_t *)&len); 
			if(r <= 0 || addr.sll_ifindex != eth_index)
				continue;
			SDateTime::getSystemTime(soc_usec[0],soc_usec[1]);
			if(pThis->m_pFilterBytes != NULL)
			{
				if(pThis->m_bFilterExcept)
				{
					if(memcmp(pRecvBuffer+pThis->m_iFilterOffsetPos,pThis->m_pFilterBytes,pThis->m_iFilterByteLen) == 0)
						continue;
				}
				else
				{
					if(memcmp(pRecvBuffer+pThis->m_iFilterOffsetPos,pThis->m_pFilterBytes,pThis->m_iFilterByteLen) != 0)
						continue;
				}
			}

			if(pThis->m_pCallbackOnReceive == NULL)
			{
				pThis->OnReceive(soc_usec[0],soc_usec[1],pRecvBuffer,r);
				continue;
			}
			pThis->m_pCallbackOnReceive(pThis->m_pCallbackUserPtr,soc_usec[0],soc_usec[1],pRecvBuffer,r);

		} 
	}
 	pThis->EndThread();
	if(sock > 0)
	{
		shutdown(sock, 2);
		close(sock);
		sock = 0;
	}
   return 0; 
}
#endif


//////////////////////////////////////////////////////////////////////////
// ��    ��:  SRawSocketSend
// ��    ��:  �ۿ���
// ����ʱ��:  2011-12-1 14:15
// ��    ��:  ԭʼ�׽��ֵķ�����
//////////////////////////////////////////////////////////////////////////

SRawSocketSend::SRawSocketSend()
{
#ifdef WIN32
	m_pCap = NULL;
#else
	m_sock = 0;
#endif
}

SRawSocketSend::~SRawSocketSend()
{
	Close();
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ����һ��ԭʼ�׽���
// ��    ��:  �ۿ���
// ����ʱ��:  2011-12-1 14:16
// ����˵��:  @sDevNameΪѡ�����ڷ��͵�Ŀ��������
// �� �� ֵ:  true��ʾ�����ɹ���false��ʾʧ�� 
//////////////////////////////////////////////////////////////////////////
bool SRawSocketSend::Create(SString sDevName/*="eth0"*/)
{
#ifdef WIN32
	if ((m_pCap = pcap_open_live(sDevName.data(),		// name of the device
							 65536,			// portion of the packet to capture. It doesn't matter in this case 
							 1,				// promiscuous mode (nonzero means promiscuous)
							 1000,			// read timeout
							 m_ErrBuf			// error buffer
							 )) == NULL)
	{
		LOGERROR("�޷�������. '%s' ����WinPcap֧�ֵ���Ч�豸��!", sDevName.data());
		return false;
	}

#else
    if ((m_sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) == -1) //����socket//man socket���Կ������漸�������˼�Կ� 
    { 
		LOGERROR("�޷�����ԭʼ�׽���!\n", sDevName.data());
		return false;
    } 

	int eth_index = if_nametoindex(sDevName.data());
	if(eth_index == 0)
	{
		LOGERROR("��Ч������(%s),����ԭʼ�׽���ʧ��!!!",sDevName.data());
		Close();
		return false;
	}
	LOGDEBUG("��������(%s)��ifindex=%d��!",sDevName.data(),eth_index);
	memset(&m_sll,0,sizeof(m_sll));
	m_sll.sll_family = AF_PACKET;
	m_sll.sll_ifindex = eth_index;
	m_sll.sll_protocol = htons(ETH_P_ALL);
	if(bind(m_sock,(struct sockaddr*)&m_sll,sizeof(m_sll)) == -1)
	{
		LOGERROR("������(%s,ifindex=%d)ʱʧ��!!",sDevName.data(),eth_index);
		Close();
		return false;
	}
	
#endif
	return true;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  �ر�ԭʼ�׽���
// ��    ��:  �ۿ���
// ����ʱ��:  2011-12-1 15:37
// ����˵��:  void
// �� �� ֵ:  void
//////////////////////////////////////////////////////////////////////////
void SRawSocketSend::Close()
{
#ifdef WIN32
	if(m_pCap != NULL)
	{
		pcap_close(m_pCap);
		m_pCap = NULL;
	}
#else
	if(m_sock != 0)
	{
		close(m_sock);
		m_sock = 0;
	}
#endif
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ����ָ����С��ԭʼ����
// ��    ��:  �ۿ���
// ����ʱ��:  2011-12-1 14:18
// ����˵��:  @pBufferΪԭʼ����ȫ�����ݣ���Ŀ�ꡢԴMAC��ַ
//            @iLenΪԭʼ�����ܳ��ȣ���λ�ֽ�
// �� �� ֵ:  >0��ʾ���ͳɹ����ֽ�����<0��ʾʧ�ܣ�=0��ʾ���ͳ�ʱ
//////////////////////////////////////////////////////////////////////////
int SRawSocketSend::SendRaw(BYTE *pBuffer,int iLen)
{
#ifdef WIN32
	if(m_pCap != NULL)
	{
		if(pcap_sendpacket(m_pCap,pBuffer,iLen) != -1)
			return iLen;
	}
#else
	if(m_sock != 0)
	{
		return ::sendto(m_sock,pBuffer,iLen,0,(struct sockaddr*)&m_sll,sizeof(m_sll));
	}
#endif
	return -1;
}
