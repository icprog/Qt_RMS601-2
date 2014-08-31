/**
 *
 * �� �� �� : SApplication.cpp
 * �������� : 2009-8-20 13:36
 * ��    �� : �ۿ���(skt001@163.com)
 * �޸����� : $Date: 2011/08/31 08:43:32 $
 * ��ǰ�汾 : $Revision: 1.1 $
 * �������� : 
 * �޸ļ�¼ : 
 *            $Log: SApplication.cpp,v $
 *            Revision 1.1  2011/08/31 08:43:32  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.11  2011/05/09 11:08:27  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.10  2011/04/27 02:58:48  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.9  2011/04/23 10:53:52  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.8  2011/04/22 06:32:33  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.7  2011/04/21 02:14:16  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.6  2011/04/11 12:08:34  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.5  2011/04/04 08:20:57  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.4  2011/04/03 07:33:12  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.3  2011/03/29 07:07:00  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.2  2011/03/03 12:07:39  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2011/02/25 03:12:05  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.6  2011/01/17 01:20:49  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.5  2010/12/20 08:37:09  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.4  2010/11/19 02:03:22  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.3  2010/11/17 02:19:15  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.2  2010/11/16 08:08:55  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2010/08/09 03:04:39  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2009/09/15 02:14:09  shaokt
 *            ͨѸ��¼����װ����Ŀ�״��ύ
 *
 *
 **/


#include "SApplication.h"

//////////////////////////////////////////////////////////////////////////
// History
// 1.0.0	2011-xx-xx  �ۿ��Ӧ�ó�������
// 2.0.0	2013-08-xx  �ۿ��Ӧ�ó���������������
//////////////////////////////////////////////////////////////////////////

#define SKTBASE_VERSION "2.0.0"

#ifndef _WITHOUT_AGENT_CHANNEL_

CSAgentClient::CSAgentClient()
{
	m_sAgentIp = "127.0.0.1";
	m_iAgentPort = 6666;
	m_SendList.setShared(true);
	m_SendList.setAutoDelete(true);
	m_pApp = NULL;
	m_iThreads = 0;
}

CSAgentClient::~CSAgentClient()
{
	if(m_pApp != NULL)
	{
		m_pApp->m_bHalt = true;
		while(m_iThreads > 0)
			SApi::UsSleep(1000);
	}
}

//////////////////////////////////////////////////////////////////////////
// ��    ��:  �����������
// ��    ��:  �ۿ���
// ����ʱ��:  2012-5-31 10:13
// ����˵��:  @bBlockΪtrue��ʾ�������У�ֱ�������˳���false��ʾ�����������߳����д������
// �� �� ֵ:  true/false
//////////////////////////////////////////////////////////////////////////
bool CSAgentClient::StartAgent(bool bBlock)
{
	if(bBlock)
	{
		ThreadAgent(this);
	}
	else
	{
		SKT_CREATE_THREAD(ThreadAgent,this);
	}
	return true;
}


//////////////////////////////////////////////////////////////////////////
// ��    ��:  �����̣߳�ִ�д��������߳�����ʱ��ռ��Run������Ҳ��ֱ������
// ��    ��:  �ۿ���
// ����ʱ��:  2012-5-30 11:00
// ����˵��:  @lp��this
// �� �� ֵ:  NULL
//////////////////////////////////////////////////////////////////////////
void* CSAgentClient::ThreadAgent(void* lp)
{
	CSAgentClient *pThis = (CSAgentClient*)lp;
	if(pThis->m_pApp == NULL)
	{
		LOGERROR("m_pAppδ����!");
		return NULL;
	}
	pThis->m_iThreads ++;
	//����ͨ��
	SSocket skt;
	SString sMsg,sRet;
	BYTE *pBuffer=NULL;
	int ret,iLength,i,cnt,from_handle;
	while(!pThis->m_pApp->m_bHalt)
	{
		pThis->m_bLogined = false;
		pThis->m_iCpuPercent = SApi::GetCpuUsedPercent();
		if(pThis->m_pApp != NULL && pThis->m_pApp->IsClosedExist())
		{
			LOGWARN("�յ��˳��ź�! ׼���رյ�ǰ����!");
			pThis->m_pApp->Stop();
			//׼���رյ�ǰ����
			pThis->m_pApp->RemoveClose();
			goto halt;
		}
		if(!skt.Create() || !skt.Connect(pThis->m_sAgentIp.data(),pThis->m_iAgentPort))
		{
			for(i=0;i<200 && !pThis->m_pApp->m_bHalt;i++)
				SApi::UsSleep(10000);
			continue;
		}
		//���͵�¼��Ϣ
		sMsg.sprintf("act=login;pid=%d;modname=%s;modver=%s;moddesc=%s;modcrc=%s;modtime=%s;",
			SApi::GetPid(),pThis->m_pApp->m_sModule.data(),pThis->m_pApp->m_sModuleVer.data(),pThis->m_pApp->m_sModuleDesc.data(),
			pThis->m_pApp->m_sModuleCrc.data(),pThis->m_pApp->m_sModuleTime.data());
		sRet = "";
		skt.SetTimeout(10,2000);
		if( !pThis->SendMsg(&skt,sMsg) || 
			!pThis->ReceiveMsg(&skt,sRet,pBuffer,iLength) || 
			SString::GetAttributeValueI(sRet,"result") != 1)
		{
			skt.Close();
			if(pBuffer != NULL)
			{
				delete[] pBuffer;
				pBuffer = NULL;
			}
			for(i=0;i<100 && !pThis->m_pApp->m_bHalt;i++)
				SApi::UsSleep(10000);
			continue;
		}
		if(pBuffer != NULL)
		{
			delete[] pBuffer;
			pBuffer = NULL;
		}
		time_t lastsoc = ::time(NULL);
		pThis->m_bLogined = true;
		while(!pThis->m_pApp->m_bHalt)
		{
			if(abs((long)(::time(NULL)-lastsoc)) > 2)
			{
				lastsoc = ::time(NULL);
				pThis->m_iCpuPercent = SApi::GetCpuUsedPercent();
			}
			//ѭ����������Ϣ����
			ret = pThis->ReceiveMsg(&skt,sMsg,pBuffer,iLength);
			if(ret < 0)
				break;
			if(ret > 0)
			{
				LOGDEBUG("�յ�������Ϣ:%s",sMsg.data());
				from_handle = SString::GetAttributeValueI(sMsg,"from_handle");
				if(!pThis->ProcessAgentMsgBase(sMsg,pBuffer,iLength))
					pThis->ProcessAgentMsg(from_handle,sMsg,pBuffer,iLength);
				if(pBuffer != NULL)
				{
					delete[] pBuffer;
					pBuffer = NULL;
				}
			}
			//�Ƿ�����Ҫ���͵ı���
			cnt = pThis->m_SendList.count();
			if(cnt == 0)
			{
				for(i=0;i<100;i++)
				{
					SApi::UsSleep(2000);
					if(skt.CheckForRecv() > 0 || pThis->m_SendList.count() > 0 || pThis->m_pApp->m_bHalt)
						break;
				}
			}
			else
			{
				for(i=0;i<cnt&&!pThis->m_pApp->m_bHalt;i++)
				{
					CAgentPackage *p = pThis->m_SendList[0];
					if(p == NULL)
						continue;
					if(pThis->SendMsg(&skt,p->sMsg,p->pBuffer,p->iLength) < 0)
						break;
					pThis->m_SendList.remove(0);
				}
			}
		}
	}
halt:
	pThis->m_iThreads --;
	return NULL;
}


////////////////////////////////////////////////////////////////////////
// ��    ��:  ��ȡ��ǰ�Ѿ���¼������Ľ���ģ���б���Ϣ
// ��    ��:  �ۿ���
// ����ʱ��:  2011-3-29 9:55
// ����˵��:  ���÷��ص��б�
// �� �� ֵ:  >=0��ʾ��������,<0��ʾʧ��
//////////////////////////////////////////////////////////////////////////
int CSAgentClient::GetModuleList(SPtrList<stuModuleInfo> &module_list)
{
	SString sMsg = "act=ps;";
	m_sWaitMsgAct = "ps";
	m_sWaitMsg = "";
	this->AddMsgToAgent(sMsg);
	//int times = 0;
	int i;
	for(i=0;i<200;i++)
	{
		if(m_sWaitMsg.length() > 0)
			break;
		SApi::UsSleep(10000);
	}
	if(m_sWaitMsg.length() > 0)
	{
		SString key,sLine;
		//�յ��ظ�
		int size = SString::GetAttributeValueI(m_sWaitMsg,"size");
		for(i=0;i<size;i++)
		{
			key.sprintf("item%d",i+1);
			sLine = SString::GetAttributeValue(m_sWaitMsg,key);
			if(sLine.length() == 0)
				continue;
			stuModuleInfo *pNew = new stuModuleInfo();
			pNew->handle = SString::GetIdAttributeI(1,sLine,",");
			pNew->pid = SString::GetIdAttributeI(2,sLine,",");
			pNew->name = SString::GetIdAttribute(3,sLine,",");
			pNew->version = SString::GetIdAttribute(4,sLine,",");
			pNew->crc = SString::GetIdAttribute(5,sLine,",");
			pNew->compile_time = SString::GetIdAttribute(6,sLine,",");
			pNew->desc = SString::GetIdAttribute(7,sLine,",");
			pNew->login_ip = SString::GetIdAttribute(8,sLine,",");
			pNew->login_port = SString::GetIdAttributeI(9,sLine,",");
			key = SString::GetIdAttribute(10,sLine,",");
			pNew->login_time = SDateTime::makeDateTime("yyyy-MM-dd hh:mm:ss.zzz",key);
			module_list.append(pNew);
		}
	}
	else
	{
		return -1;
	}
	m_sWaitMsgAct = "";
	return module_list.count();
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ȡ�������˵�������Ϣ
// ��    ��:  �ۿ���
// ����ʱ��:  2012-9-26 11:44
// ����˵��:  @sDisk ��ʾ��Ҫ��ȡ��Ӳ����Ϣ��disks=3;disk1=/dev/sda1;disk2=/dev/sda2;disk3=/dev/sda3;
//            @sRunInfo���÷��ص����ַ���������������Ϣ,act=runinfo;cpu_used=%d;mem_all=%d;mem_used=%d;mem_free=%d;disk1_all=%d;disk1_used=%d;disk1_free=%d;disk1_per=%d;
// �� �� ֵ:  1��ʾ�ɹ���0��ʾʧ��
//////////////////////////////////////////////////////////////////////////
bool CSAgentClient::GetRunInfo(SString sDisk,SString &sRunInfo)
{
	SString sMsg = "act=runinfo;"+sDisk;
	m_sWaitMsgAct = "runinfo";
	m_sWaitMsg = "";
	this->AddMsgToAgent(sMsg);
	int i;
	for(i=0;i<200;i++)
	{
		if(m_sWaitMsg.length() > 0)
			break;
		SApi::UsSleep(10000);
	}
	if(m_sWaitMsg.length() > 0)
	{
		sRunInfo = m_sWaitMsg;
	}
	else
	{
		return false;
	}
	m_sWaitMsgAct = "";
	return true;
}


////////////////////////////////////////////////////////////////////////
// ��    ��:  ȡָ��ģ����ڴ�������ϵľ��
// ��    ��:  �ۿ���
// ����ʱ��:  2011-3-29 14:42
// ����˵��:  ģ�����ƣ����������ƣ�WIN32ƽ̨�ϲ���Ҫ��.exe
// �� �� ֵ:  =0��ʾģ��δ�ҵ���>0��ʾ���̾��
//////////////////////////////////////////////////////////////////////////
int CSAgentClient::GetModuleHandle(SString sModName)
{
	SPtrList<stuModuleInfo> module_list;
	module_list.setAutoDelete(true);
	if(GetModuleList(module_list) < 0)
		return 0;
	SString name2 = sModName+".exe";
	unsigned long pos;
	stuModuleInfo *pInfo = module_list.FetchFirst(pos);
	while(pInfo)
	{
		if(pInfo->name == sModName || pInfo->name == name2)
		{
			return pInfo->handle;
		}
		pInfo = module_list.FetchNext(pos);
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ��ָ����ģ�鷢��һ����Ϣ
// ��    ��:  �ۿ���
// ����ʱ��:  2011-3-29 11:06
// ����˵��:  to_handleΪĿ��ģ��ľ��
// �� �� ֵ:  ���ͳɹ�����ture��ʧ�ܷ���false
//////////////////////////////////////////////////////////////////////////
bool CSAgentClient::AddMsgToModule(int to_handle,SString &sMsg,BYTE* pBuffer/*=NULL*/,int iLength/*=0*/)
{
	sMsg.replace("act=","act2=");
	if(sMsg.right(1) != ";")
		sMsg += ";";
	sMsg += "act=prox;to_handle="+SString::toString(to_handle)+";";
	AddMsgToAgent(sMsg,pBuffer,iLength);
	return true;
}

bool CSAgentClient::ProcessAgentMsgBase(SString &sMsg,BYTE* pBuffer/*=NULL*/,int iLength/*=0*/)
{
	if(m_pApp == NULL)
		return false;
	SString sRet = "";
	//LOGDEBUG("�յ�������Ϣ:%s",sMsg.data());
	SString act = SString::GetAttributeValue(sMsg,"act");
	if(m_sWaitMsgAct == act)
	{
		m_sWaitMsg = sMsg;
		return true;
	}
	if(act == "start")
	{
		LOGWARN("������ϢҪ����������!");
		if(m_pApp->IsStarted() == true)
		{
			LOGERROR("Ӧ���Ѿ������������������");
		}
		else
		{
			m_pApp->m_bHalt = false;
			m_pApp->SetStarted(m_pApp->Start());
		}
	}
	else if(act == "stop")
	{
		LOGWARN("������ϢҪ��رճ���!");
		if(m_pApp->IsStarted() == false)
		{
			LOGERROR("Ӧ����δ���������Թر����");
		}
		else
		{
			m_pApp->m_bHalt = true;
			m_pApp->Stop();
			m_pApp->SetStarted(false);
		}
	}
	else if(act == "restart")
	{
		LOGWARN("�յ�������ϢҪ������Ӧ��!");
		m_pApp->Stop();
		if(!m_pApp->Start())
		{
			m_pApp->SetStarted(false);
			LOGFAULT("����Ӧ��ʧ��!");
			return false;
		}
		else
		{
			m_pApp->SetStarted(true);
		}
	}
	else if(act == "log")
	{
		SString cmd = SString::GetAttributeValue(sMsg,"cmd");
		m_pApp->ParseCommandLine(cmd);
	}
	else if(act == "cpupercent")
	{
		sRet.sprintf("cpu=%d;%s",m_iCpuPercent,sMsg.data());
		AddMsgToAgent(sRet);
	}
	else if(act == "info")
	{
		//�ȸ���ģ����Ϣ
		ProcessAgentMsg(0,sMsg,pBuffer,iLength);

		sRet = "info="+m_pApp->m_sModuleInfo+";"+sMsg;
		AddMsgToAgent(sRet);
	}
	else if(act == "putfile")
	{
		//��ָ��Ŀ¼д���ļ�
		SString pathfile = SString::GetAttributeValue(sMsg,"pathfile");
		SFile file(pathfile);
		if(!file.open(IO_Truncate))
		{
			sRet += ";result=0;";
		}
		else
		{
			if(pBuffer != NULL && iLength > 0)
				file.writeBlock(pBuffer,iLength);
			file.close();
			sRet += ";result=1;";
		}
		AddMsgToAgent(sRet);
	}
	else if(act == "getfile")
	{
		//��ȡָ�����ļ�
		SString pathfile = SString::GetAttributeValue(sMsg,"pathfile");
		SFile file(pathfile);
		if(!file.open(IO_ReadOnly))
		{
			sRet += ";result=0;";
			AddMsgToAgent(sRet);
		}
		else
		{
			int size = file.size();
			if(size == 0)
			{
				sRet += ";result=1;";
				AddMsgToAgent(sRet);
			}
			else
			{
				BYTE *pFileBuf = new BYTE[size];
				if(file.readBlock(pFileBuf,size) != size)
				{
					sRet += ";result=0;";
					AddMsgToAgent(sRet);
					delete[] pFileBuf;
				}
				else
				{
					sRet += ";result=1;";
					AddMsgToAgent(sRet,pFileBuf,size);

				}
				file.close();
			}
		}
	}
	else
		return false;
	return true;
}

int CSAgentClient::ReceiveMsg(SSocket *pSocket,SString &sMsg,BYTE* &pBuffer,int &iLength)
{
	BYTE buf[16];
	int ret,len1,len2;
	ret = pSocket->Receive(buf,10);
	if(ret == 0)
		return 0;
	if(ret != 10)
	{
		return -1;
	}
	if(buf[0] != 0xEC || buf[1] != 0x57)
	{
		return -2;
	}
	memcpy(&len1,buf+2,4);
	memcpy(&len2,buf+6,4);

	//����ֽ���
	SKT_SWAP_DWORD(len1);
	SKT_SWAP_DWORD(len2);
	//SApi::Ysntoh(SKT_LITTLE_ENDIAN,(DWORD)len1);
	//SApi::Ysntoh(SKT_LITTLE_ENDIAN,(DWORD)len2);

	sMsg.SetBuffer(len1+1);
	char *pStr = sMsg.data();
	ret = pSocket->Receive(pStr,len1);
	sMsg.PrepareStrLen();
	if(ret != len1)
	{
		int times = 0;
		while(ret == 0 && times < 1000)
		{
			times++;
			SApi::UsSleep(10000);
			ret = pSocket->Receive(pStr,len1);
		}
		if(ret != len1)
			return -3;
	}
	pStr[len1] = '\0';
	if(len2 > 0)
	{
		if(len2 > iLength)
		{
			if(pBuffer != NULL)
				delete[] pBuffer;
			pBuffer = new BYTE[len2];
		}
		iLength = len2;
		ret = pSocket->Receive(pBuffer,len2);
		iLength = len2;
	}
	else
	{
		pBuffer = NULL;
		iLength = 0;
	}
	//LOGDEBUG("RECV:%s",sMsg.data());
	return len1;
}

int CSAgentClient::SendMsg(SSocket *pSocket,SString &sMsg,BYTE* pBuffer/*=NULL*/,int iLength/*=0*/)
{
	BYTE buf[16];
	int ret,len1,len2;
	buf[0] = 0xEC;
	buf[1] = 0x57;
	len1 = sMsg.length();
	len2 = iLength;

	//����ֽ���
	SKT_SWAP_DWORD(len1);
	SKT_SWAP_DWORD(len2);
	//SApi::Yshton(SKT_LITTLE_ENDIAN,(DWORD)len1);
	//SApi::Yshton(SKT_LITTLE_ENDIAN,(DWORD)len2);

	memcpy(buf+2,&len1,4);
	memcpy(buf+6,&len2,4);

	//����ֽ���
	SKT_SWAP_DWORD(len1);
	SKT_SWAP_DWORD(len2);
	//SApi::Yshton(SKT_LITTLE_ENDIAN,(DWORD)len1);
	//SApi::Yshton(SKT_LITTLE_ENDIAN,(DWORD)len2);

	ret = pSocket->Send(buf,10);
	if(ret != 10)
		return -1;

	ret = pSocket->Send(sMsg.data(),len1);
	if(ret != len1)
		return -2;
	if(len2 != 0 && pBuffer != NULL)
	{
		ret = pSocket->Send(pBuffer,len2);
		if(ret != len2)
			return -3;
	}
	//LOGDEBUG("SEND:%s",sMsg.data());
	return len1;
}
#endif	

//////////////////////////////////////////////////////////////////////////
// ��    ��:  SApplication
// ��    ��:  �ۿ���
// ����ʱ��:  2008-10-10 14:16
// ��    ��:  Ӧ�ó��������
//////////////////////////////////////////////////////////////////////////

SApplication::SApplication()
{
	m_sAppbaseVer = SKTBASE_VERSION;
	m_iArgc = 0;
	m_ppArgv = NULL;
	m_bHalt = false;
	m_bDebugMode = false;
	m_bLogToConsole = true;
	m_bFork = true;
	m_bStarted = false;
#ifndef _WITHOUT_AGENT_CHANNEL_
	m_pApp = this;
#endif
}

SApplication::~SApplication()
{
	//SLog::WaitForLogEmpty();
}

bool SApplication::ParseCommandLine(SString str)
{
	if(str == "log level none")
	{
		SLog::setLogLevel(SLog::LOG_NONE);
	}
	else if(str == "log level fault")
	{
		SLog::setLogLevel(SLog::LOG_FAULT);
	}
	else if(str == "log level error")
	{
		SLog::setLogLevel(SLog::LOG_ERROR);
	}
	else if(str == "log level warn")
	{
		SLog::setLogLevel(SLog::LOG_WARN);
	}
	else if(str == "log level debug")
	{
		SLog::setLogLevel(SLog::LOG_DEBUG);
	}
	else if(str == "log level basedebug")
	{
		SLog::setLogLevel(SLog::LOG_BASEDEBUG);
	}
	else if(str == "log to console on")
	{
		SLog::startLogToConsole();
	}
	else if(str == "log to console off")
	{
		SLog::stopLogToConsole();
	}
	else if(str.left(12) == "log to file ")
	{
		SLog::startLogToFile(str.mid(12).data());
	}
	else if(str.left(14) == "log file size ")
	{
		SLog::setLogFileMaxSize(str.mid(14).toInt());
	}
	else if(str.left(19) == "log file back size ")
	{
		SLog::setLogFileMaxBackFiles(str.mid(19).toInt());
	}
	else if(str == "log to file off")
	{
		SLog::stopLogToFile();
	}
	else if(str == "log to tcp off" || str == "log to TCP off")
	{
		SLog::stopLogToTCPSvr();
	}
	else if(str.left(11) == "log to tcp " || str.left(11) == "log to TCP ")
	{
		SString ip = str.mid(11);
		int port=ip.find(":");
		if(port > 0)
		{
			port = ip.mid(ip.find(":")+1).toInt();
			ip = ip.left(ip.find(":"));
		}
		SLog::startLogToTCPSvr(ip.data(),port);
	}
	else if(str == "log to udp off" || str == "log to UDP off")
	{
		SLog::stopLogToUDPSvr();
	}
	else if(str.left(11) == "log to udp " || str.left(11) == "log to UDP ")
	{
		SString ip = str.mid(11);
		int port=ip.find(":");
		if(port > 0)
		{
			port = ip.mid(ip.find(":")+1).toInt();
			ip = ip.left(ip.find(":"));
		}
		SLog::startLogToUDPSvr(ip.data(),port);
	}
	
	return true;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ����ģ��汾��
// ��    ��:  �ۿ���
// ����ʱ��:  2009-5-19 10:56
// ����˵��:  sVer(����:<��Ʒ�ڲ��ͺ�>.<�׶ΰ汾��>.<ģ��汾��>)
// �� �� ֵ:  NULL
//////////////////////////////////////////////////////////////////////////
void SApplication::SetVersion(SString sVer)
{
	m_sModuleVer = sVer;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ����ģ������
// ��    ��:  �ۿ���
// ����ʱ��:  2009-5-19 12:29
// ����˵��:  sDesc����
// �� �� ֵ:  NULL
//////////////////////////////////////////////////////////////////////////
void SApplication::SetModuleDesc(SString sDesc)
{
	m_sModuleDesc = sDesc;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ����ģ����Ϣ
// ��    ��:  �ۿ���
// ����ʱ��:  2009-5-19 12:29
// ����˵��:   sInfo = name=;ver=;crc=;date=
// �� �� ֵ:  NULL
//////////////////////////////////////////////////////////////////////////
void SApplication::SetModuleInfo(SString sInfo)
{
	m_sModuleInfo	= sInfo;
	m_sModule		= SString::GetAttributeValue(sInfo,"name");
	m_sModuleVer	= SString::GetAttributeValue(sInfo,"ver");
	m_sModuleCrc	= SString::GetAttributeValue(sInfo,"crc");
	m_sModuleTime	=SString::GetAttributeValue(sInfo,"date");
	if (m_sModuleVer.left(1).toLower() == "v")
		m_sModuleVer= m_sModuleVer.mid(1);
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ����Ӧ�ó���
// ��    ��:  �ۿ���
// ����ʱ��:  2008-10-10 14:17
// ����˵��:  @argc/argvΪmain�������
//            @szDate/szTimeΪ��������ʱ��
//            @bBlockΪ�Ƿ��������У�trueΪ������falseΪ������
// �� �� ֵ:  true/false
//////////////////////////////////////////////////////////////////////////
bool SApplication::Run(int argc, char* argv[],const char* szDate,const char* szTime,bool bBlock/*=true*/)
{
	m_iArgc = argc;
	m_ppArgv = (char**)argv;
	m_sModule = argv[0];
	#ifndef _WITHOUT_AGENT_CHANNEL_
	m_sAgentIp = "127.0.0.1";
	#endif
	SString err;
	SString crc = SApi::GenerateCRCByFile(m_sModule,err);
	m_sModuleCrc = crc;
	m_sModuleTime.sprintf("%s %s",szDate,szTime);
	
	if(m_sModule.findRev('/') >= 0)
		m_sModule = m_sModule.mid(m_sModule.findRev('/')+1);
	if(m_sModule.findRev('\\') >= 0)
		m_sModule = m_sModule.mid(m_sModule.findRev('\\')+1);

	printf("#########################################################\n");
	printf("## SKTBASE Application frame\n");
	printf("## Module  Name: %s \n",m_sModule.data());
	printf("## Description : %s \n",m_sModuleDesc.data());
	printf("## Compile Time: %s %s\n",szDate,szTime);
	printf("## Appbase Ver : V%s \n",m_sAppbaseVer.data());
	printf("## Module  Ver : V%s \n",m_sModuleVer.data());
	printf("## CRC    Code : %s \n",crc.data());
	printf("#########################################################\n");

	SString sTemp="";
	if(IsParam("version",sTemp))
	{
		bool bWrite = false;
		SString sLine;
		SFile file;
		if(sTemp.length() > 0)
		{
			file.setFileName(sTemp);
			if(file.open(IO_Truncate))
				bWrite = true;
		}
		if(bWrite)
		{
			sLine.sprintf("#########################################################\n");
			file.writeString(sLine);
			sLine.sprintf("## SKTBASE Application frame\n");
			file.writeString(sLine);
			sLine.sprintf("## Module  Name: %s \n",m_sModule.data());
			file.writeString(sLine);
			sLine.sprintf("## Description : %s \n",m_sModuleDesc.data());
			file.writeString(sLine);
			sLine.sprintf("## Compile Time: %s %s\n",szDate,szTime);
			file.writeString(sLine);
			sLine.sprintf("## Appbase Ver : V%s \n",m_sAppbaseVer.data());
			file.writeString(sLine);
			sLine.sprintf("## Module  Ver : V%s \n",m_sModuleVer.data());
			file.writeString(sLine);
			sLine.sprintf("## CRC    Code : %s \n",crc.data());
			file.writeString(sLine);
			sLine.sprintf("#########################################################\n");
			file.writeString(sLine);
			file.close();
		}
		exit(0);
		abort();
	}


	if(m_sModuleDesc.length() == 0)
	{
		printf("ERROR!!! ȱ��ģ��������Ϣ!����û���CSRecApplication::SetModuleDesc����!\n\n\n");
	}
	if(m_sModuleVer.length() == 0)
	{
		printf("ERROR!!! ȱ��ģ��汾��Ϣ!����û���CSRecApplication::SetVersion����!\n\n\n");
	}
#ifndef WIN32
	signal(SIGPIPE,SIG_IGN);//���Թܵ��Ͽ��ź�
	signal(SIGCHLD,SIG_IGN);
	signal(SIGCLD, SIG_IGN);
#endif

#ifndef WIN32
	if(m_bFork)
	{
		//LINUX�½���������Ϊ�ػ�����
		//printf("@@@@@@@@@@@@begin fork()\n");
		if(fork())
		{
			//printf("@@@@@@@@@@@@fork()\n");
			exit(0);
		}
	}
	SApi::UsSleep(100000);
	signal(SIGCHLD,SIG_IGN);
#endif

	SLog::setLogLevel(SLog::LOG_DEBUG);
	SLog::setModuleName(m_sModule.data());

	//Ԥ��������
	SXmlConfig xml;
	SString sFileName;
	m_sExePath = SDir::currentDirPath();
	if(m_sExePath.right(1) != "/" && m_sExePath.right(1) != "\\")
		m_sExePath += "/";
	sFileName=m_sExePath + "logconfig.xml";
	if(!xml.ReadConfig(sFileName))
	{
		LOGWARN("��<logconfig.xml>�ļ�ʧ��!���޷�ʹ����־��¼����! file=%s",sFileName.data());
	}
	else
	{
		sFileName = m_sModule;
		SBaseConfig *pPrecommand = xml.SearchChild("log<module='"+sFileName+"'>");
		if(pPrecommand == NULL)
		{
			if(sFileName.right(4).toLower() == ".exe")
				sFileName = sFileName.left(sFileName.length()-4);
			pPrecommand = xml.SearchChild("log<module='"+sFileName+"'>");
		}

		if(pPrecommand == NULL)
		{
			//û��ר�õģ���ȱʡ��
			pPrecommand = xml.SearchChild("log<module=''>");
		}
		if(pPrecommand != NULL)
		{
			//Ԥ��������
			int i,cnt = pPrecommand==NULL?0:pPrecommand->GetChildCount("command");
			for(i=0;i<cnt;i++)
			{
				SBaseConfig *pCommand = pPrecommand->GetChildNode(i,"command");
				if(pCommand == NULL )
					continue;
				SString cmd = pCommand->GetNodeValue();
				if(cmd.find("[@modulename]") >= 0)
				{
					SString sModule = SLog::getModuleName();
					cmd = cmd.replace("[@modulename]",sModule);
				}
				ParseCommandLine(cmd);
			}
		}
	}

	//�Ƿ��ڵ���ģʽ
	if(IsParam("debug"))
		m_bDebugMode = true;

	if(IsParam("console",sTemp))
	{
		sTemp = sTemp.toLower();
		if(sTemp == "off")
		{
			//ǿ�ƹرտ���̨����־���
			m_bLogToConsole = false;
			ParseCommandLine("log to console off");
		}
	}
#ifndef _WITHOUT_AGENT_CHANNEL_
	if(IsParam("agentport",sTemp))
	{
		m_iAgentPort = sTemp.toInt();
		if(m_iAgentPort == 0)
			m_iAgentPort = 6666;
	}
#endif
	if(IsParam("stop"))
	{
		if(!_Stop())
		{
			LOGFAULT("ֹͣӦ��ʧ��!");
			//SLog::WaitForLogEmpty();
			return false;
		}
		return true;
	}
	else if(IsParam("restart"))
	{
		_Stop();
		if(!_Start())
		{
			LOGFAULT("����Ӧ��ʧ��!");
			//SLog::WaitForLogEmpty();
			return false;
		}
	}
	else
	{
		if(!_Start())
		{
			LOGFAULT("����Ӧ��ʧ��!");
			//SLog::WaitForLogEmpty();
			return false;
		}
	}
	LOGDEBUG("Ӧ�÷����������!");

	if(bBlock)
	{
		//������ʽ����
#ifndef _WITHOUT_AGENT_CHANNEL_
		StartAgent(bBlock);
#else
		while(!m_bHalt)
		{
			//�ȴ����˷����˳��ź�
			if(IsClosedExist())
			{
				LOGWARN("�յ��˳��ź�! ׼���رյ�ǰ����!");
				Stop();
				//׼���رյ�ǰ����
				this->RemoveClose();
				break;
			}
			SApi::UsSleep(2000000);
		}
#endif
	}
	else
	{
		//��������ʽ����
#ifndef _WITHOUT_AGENT_CHANNEL_
		StartAgent(bBlock);
#endif
	}

	LOGDEBUG("Ӧ�÷������˳�!");
	//SLog::WaitForLogEmpty();
	return true;
}


bool SApplication::IsParam(SString sParamName)
{
	SString sLine;
	for(int i=1;i<m_iArgc;i++)
	{
		sLine = m_ppArgv[i];
		if(sLine.left(1) == "-")
			sLine = sLine.mid(1);
		if(SString::GetIdAttribute(1,sLine,"=") == sParamName)
			return true;
	}
	return false;
}
bool SApplication::IsParam(SString sParamName,SString &sParamValue)
{
	SString sLine;
	for(int i=1;i<m_iArgc;i++)
	{
		sLine = m_ppArgv[i];
		if(sLine.left(1) == "-")
			sLine = sLine.mid(1);
		if(SString::GetIdAttribute(1,sLine,"=") == sParamName)
		{
			sParamValue = SString::GetIdAttribute(2,sLine,"=");
			return true;
		}
	}
	return false;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ȡ�����в�������
// ��    ��:  �ۿ���
// ����ʱ��:  2014-5-19 10:13
// ����˵��:  @sParamNameΪ������
// �� �� ֵ:  ����ֵ
//////////////////////////////////////////////////////////////////////////
SString SApplication::GetParam(SString sParamName)
{
	SString sLine;
	for(int i=1;i<m_iArgc;i++)
	{
		sLine = m_ppArgv[i];
		if(sLine.left(1) == "-")
			sLine = sLine.mid(1);
		if(SString::GetIdAttribute(1,sLine,"=") == sParamName)
		{
			return SString::GetIdAttribute(2,sLine,"=");
		}
	}
	return "";
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ȡ���������Ͳ�������
// ��    ��:  �ۿ���
// ����ʱ��:  2014-5-19 10:13
// ����˵��:  @sParamNameΪ������
// �� �� ֵ:  ����ֵ
//////////////////////////////////////////////////////////////////////////
int SApplication::GetParamI(SString sParamName)
{
	return GetParam(sParamName).toInt();
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ȡ�����и����Ͳ�������
// ��    ��:  �ۿ���
// ����ʱ��:  2014-5-19 10:13
// ����˵��:  @sParamNameΪ������
// �� �� ֵ:  ����ֵ
//////////////////////////////////////////////////////////////////////////
float SApplication::GetParamF(SString sParamName)
{
	return GetParam(sParamName).toFloat();
}

bool SApplication::TouchClose()
{
#ifdef WIN32
	SFile file(m_sExePath+"_skt_close_"+m_sModule);
#else
	SFile file("/proc/.skt_close_"+m_sModule);
#endif
	if(!file.open(IO_Truncate))
		return false;
	file.close();
	return true;
}

bool SApplication::RemoveClose()
{
#ifdef WIN32
	return SFile::remove(m_sExePath+"_skt_close_"+m_sModule);
#else
	return SFile::remove("/proc/.skt_close_"+m_sModule);
#endif
}

bool SApplication::IsClosedExist()
{
#ifdef WIN32
	SFile file(m_sExePath+"_skt_close_"+m_sModule);
#else
	SFile file("/proc/.skt_close_"+m_sModule);
#endif
	if(!file.open(IO_ReadOnly))
		return false;
	file.close();
	return true;
}

bool SApplication::SearchOldProcess(int &pid,int &ppid,SString &name)
{
	//�����Ƿ����
	SStringList plist;//pid,ppid,name;....
	SString sLine;
	int p,i,cnt = SApi::GetSystemProcess(plist);
	for(i=0;i<cnt;i++)
	{
		sLine = *plist[i];
		//LOGDEBUG("MOUDLE:%s",sLine.data());
		pid = SString::GetIdAttributeI(1,sLine,",");
		ppid= SString::GetIdAttributeI(2,sLine,",");
		name= SString::GetIdAttribute( 3,sLine,",");
#ifdef WIN32
		name += ".exe";
#endif

		if(pid == SApi::GetPid())
			continue;//��������Ľ���
		p = name.find(m_sModule);
		if(p < 0)
			continue;
		if(name.length() == p+m_sModule.length() ||
			 name.at(p+m_sModule.length()) == ' ')
		{
			LOGDEBUG("�õ���ǰ���̶�Ӧ�Ľ���!");
			return true;
		}
	}
	return false;
}

bool SApplication::_Start()
{
	if(m_bStarted)
		return false;

	//�����Ƿ����
	int pid,ppid;
	SString name;
	if(SearchOldProcess(pid,ppid,name) && m_sModule.Find("watch") < 0)
	{
		LOGWARN("��ǰ���̵���һ��ʵ��������(pid:%d,ppid%d,name:%s),��ǰ���̽���ֹ����!!!",pid,ppid,name.data());
		return false;
	}
	if(Start())
	{
		m_bStarted = true;
		return true;
	}
	else
	{
		return false;
	}
}

bool SApplication::_Stop()
{
	if(!m_bStarted)
		return false;

	//�����Ƿ����
	int pid,ppid;
	SString name;
	if(!SearchOldProcess(pid,ppid,name) && m_sModule.Find("watch") < 0)
		return false;

	//֪ͨpid���̹ر��������
	TouchClose();
	//�ȴ����
	time_t begin = ::time(NULL);
	while(1)
	{
		SApi::UsSleep(100000);
		if(!IsClosedExist())
			break;
		if(::time(NULL) - begin > 10)
		{
			LOGWARN("�ȴ����̹رճ�ʱ����ֱ��ɱ������(pid=%d,name=%s)",pid,name.data());
			SApi::SystemKillProcess(pid);
			RemoveClose();
			break;
		}
	}
	if(!IsClosedExist())
	{
		m_bStarted = false;
		return true;
	}
	else
	{
		RemoveClose();
		return false;
	}
}
