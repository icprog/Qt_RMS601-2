/**
 * �� �� �� : PackageApplication.h
 * �������� : 2014-4-22 11:32
 * ��    �� : �ο�
 * �޸����� : $Date: $
 * ��ǰ�汾 : $Revision: $
 * �������� : ���ļ��ӵ�Ӧ�ó�����
 **/

#ifndef __PACKAGE_APPLICATION_H__
#define __PACKAGE_APPLICATION_H__

#include "PcapFile.h"
#include "sbase/SApplication.h"
#include "sbase/comm/SRawSocket.h"

#define	WRITEBUFFER		MBYTE1
#define	MAXBUFFER		(MBYTE1*2+1520)	//1520Ϊ��ֹ�������
#define	MAXETH			8				//���������
#define	MINCACHETIME	60				//��λ��
#define MILLISECOND		1000
#define SECOND			(MILLISECOND*1000)

typedef struct pcap_eth_t pcap_eth_t;
struct pcap_eth_t {
	CPcapFile		*pcapFile;
	SRawSocketRecv	*rawSock;
	string			name;
	string			eth;
	char			*recvBuffer;
	unsigned int	bufferLen;
	UINT64			flow; 
	int				soc;
	int				usec;
};

class CPackageApplication : public SApplication
{
public:
	CPackageApplication(void);
	~CPackageApplication(void);

	virtual bool Start();
	virtual bool Stop();
	virtual bool ProcessAgentMsg(int from_handle,SString &sMsg,BYTE* pBuffer=NULL,int iLength=0);

	bool	Init();
#ifdef WIN32
	void	Ifconfig(pcap_if_t *d,int cnt);
#else
	void	Ifconfig_linux(int cnt);
#endif
	void	ApplicationConfig();

	void	SetCompress(bool bCmp) { bCompress = bCmp; };
	void	SetEthNumber(int eNum) { ethNumber = eNum; };
	void	SetStorePath(SString sPath) { storePath = sPath; };
	void	SetStoreFileSize(int sSize) { storeFileSize = sSize; };
	void	SetStoreFileNum(int sNum) { storeFileNum = sNum; };
	void	SetFormat7z(bool bZip,bool b7z);
	static void* ThreadCommunicationRecv(void *lp);
	static void* ThreadCommunicationSend(void *lp);

private:
	bool		bInitOk;
	bool		bCompress;
	int			ethNumber;
	SString		storePath;
	int			storeFileSize;
	int			storeFileNum;
	pcap_eth_t	*pcapEth;
#ifndef WIN32
	string		m_ethName[MAXETH];
#endif
	SSocket		mSocket;
	SPtrList<SSocket> socketList;
};

#endif	//__PACKAGE_APPLICATION_H__