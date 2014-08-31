/**
 *
 * �� �� �� : SLog.cpp
 * �������� : 2007-01-01
 * ��    �� : �ۿ���(skt001@163.com)
 * �޸����� : $Date: 2011/08/31 08:43:33 $
 * ��ǰ�汾 : $Revision: 1.1 $
 * �������� : ��־��¼����ϢԪ���У�
 *						1 ģ����
 *						2 ��־���ͣ�1:debug/2:warn/3:error/4:fault
 *						3 ����ʱ��
 *						4 Դ�ļ���
 *						5 Դ�ļ��к�
 *						6 ��־��������
 * �޸ļ�¼ : 
 *            $Log: SLog.cpp,v $
 *            Revision 1.1  2011/08/31 08:43:33  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.5  2011/04/21 02:14:17  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.4  2011/04/20 14:00:53  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.3  2011/04/20 05:37:57  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.2  2011/02/28 01:28:33  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2010/08/09 03:04:43  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2009/09/15 02:14:08  shaokt
 *            ͨѸ��¼����װ����Ŀ�״��ύ
 *
 *            Revision 1.2  2009/06/19 10:35:04  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.4  2009/01/23 03:36:35  shaokt
 *            �޸���־�ļ�д��ʱ�Ĵ���ʽ��ԭ����ʽΪ���ļ�ת��Ϊһ������10%��swap�ļ����������ǻᾭ��д�����ĳ�д�����ļ�ת��Ϊback�ļ�����ɾ����ǰ����־,�����ļ����ᾭ��д������߳���ִ��Ч��
 *
 *            Revision 1.3  2009/01/19 08:07:26  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.2  2009/01/16 06:16:02  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2008/09/02 01:50:08  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.7  2008/04/30 07:38:43  shaokt
 *            ���ӷּ���д��־�ļ�
 *
 *            Revision 1.6  2007/10/29 07:30:23  shaokt
 *            ��Ӷ����ַ�Ƿ�Ϊ4�ı����ļ�⺯����Ϊ���ARM������pack(1)��ɵ��ڴ�����
 *
 *            Revision 1.5  2007/10/19 06:18:33  shaokt
 *            ������־�ļ���С
 *
 *            Revision 1.4  2007/10/17 10:02:11  shaokt
 *            ����̨��������ģ����
 *
 *            Revision 1.3  2007/09/21 07:53:41  shaokt
 *            �������
 *
 *            Revision 1.2  2007/09/11 08:17:53  shaokt
 *            �������
 *
 *            Revision 1.1  2007/08/15 03:09:22  shaokt
 *            *** empty log message ***
 *
 **/

#include "SLog.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

static SLog g_skt_log;
SLock g_skt_LogLock;//��־��
short g_skt_CurrLogLevel;//��ǰ��־���������
std::string SLog::bufToHexString(BYTE *pBuffer, int iLen)
{
	std::string str="";
	char buf[4];
	memset(buf,0,4);
	bool b=false;
	if(iLen>1000)
	{
		b = true;
		iLen = 1000;
	}
	for(int i=0;i<iLen;i++)
	{
		sprintf(buf,"%02X ",pBuffer[i]);
		str += buf;
	}
	if(b)
		str += " ...... ";
	return str;
}

SLog::SLog()
{
	m_hUdpSocket = /*NULL*/0;
	m_hTcpSocket = /*NULL*/0;
	memset(&m_log,0,sizeof(stuLog));
	m_iLogLevel = LOG_ERROR;
	m_iMaxFileSize = 1024 * 1024;//��󱣴�1M����־�ļ�
	m_iMaxBackFiles = 5;
	init();
}

SLog::~SLog()
{
}

SLog* SLog::getLog()
{
	return &g_skt_log;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ������־����
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-18 22:17
// ����˵��:  @lΪ�µ���־����
// �� �� ֵ:  void
//////////////////////////////////////////////////////////////////////////
void SLog::setLogLevel(SLog::LOG_LEVEL l)
{
	getLog()->m_iLogLevel = l;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ������־�ļ�����С
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-18 22:17
// ����˵��:  @size�ļ���С����λ�ֽ�
// �� �� ֵ:  void
//////////////////////////////////////////////////////////////////////////
void SLog::setLogFileMaxSize(int size)
{
	getLog()->m_iMaxFileSize = size;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ���ñ����ļ����������
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-18 22:18
// ����˵��:  @files��ʾ�����ļ��������
// �� �� ֵ:  void
//////////////////////////////////////////////////////////////////////////
void SLog::setLogFileMaxBackFiles(int files)
{
	getLog()->m_iMaxBackFiles = files;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ���õ�ǰģ������
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-18 22:19
// ����˵��:  @name�µ�ģ������
// �� �� ֵ:  void
//////////////////////////////////////////////////////////////////////////
void SLog::setModuleName(char* name)
{
	getLog()->m_sModuleName = name;
	int p=getLog()->m_sModuleName.find_last_of('\\',getLog()->m_sModuleName.length());
	if(p>=0)
		getLog()->m_sModuleName = getLog()->m_sModuleName.substr(p+1,getLog()->m_sModuleName.length()-p-1);
	p=getLog()->m_sModuleName.find_last_of('/',getLog()->m_sModuleName.length());
	if(p>=0)
		getLog()->m_sModuleName = getLog()->m_sModuleName.substr(p+1,getLog()->m_sModuleName.length()-p-1);
#ifdef WIN32
	if(getLog()->m_sModuleName.length()>4 && getLog()->m_sModuleName.substr(getLog()->m_sModuleName.length()-4,4) == ".exe")
		getLog()->m_sModuleName = getLog()->m_sModuleName.substr(0,getLog()->m_sModuleName.length()-4);
#endif
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ȡ��ǰģ������
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-18 22:19
// ����˵��:  void
// �� �� ֵ:  ģ������
//////////////////////////////////////////////////////////////////////////
char* SLog::getModuleName()
{
	return (char*)getLog()->m_sModuleName.c_str();
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ��ʼ��־�����UDP������
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-18 22:20
// ����˵��:  @ipΪ������IP��ַ
//            @port��ʾ�˿�
// �� �� ֵ:  true��ʾ�ɹ���false��ʾʧ��
//////////////////////////////////////////////////////////////////////////
bool SLog::startLogToUDPSvr(char* ip,int port)
{
	SLog *p = getLog();
	if(p == /*NULL*/0)
		return false;

	#ifdef _WIN32
		WSADATA WSAData;
		WSAStartup( MAKEWORD( 1, 1 ), &WSAData );
	#endif
	p->m_hUdpSocket = ::socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if(p->m_hUdpSocket == INVALID_SOCKET)
	{
	  p->m_hUdpSocket = /*NULL*/0;
		return false;
	}
	memset(&p->m_udp_dest_sin, 0 ,sizeof(p->m_udp_dest_sin));
	p->m_udp_dest_sin.sin_family 			= AF_INET;
	p->m_udp_dest_sin.sin_addr.s_addr = inet_addr(ip);
	p->m_udp_dest_sin.sin_port 				= htons(port); 
	p->m_bToLogUDPSvr=true;
	return true;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ��ʼ��־�����TCP������
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-18 22:24
// ����˵��:  @ipΪ������IP��ַ
//            @port��ʾ�˿�
// �� �� ֵ:  true��ʾ�ɹ���false��ʾʧ��
//////////////////////////////////////////////////////////////////////////
bool SLog::startLogToTCPSvr(char* ip,int port)
{
	SLog *p = getLog();
	if(p == /*NULL*/0)
		return false;
	#ifdef _WIN32
		WSADATA WSAData;
		WSAStartup( MAKEWORD( 1, 1 ), &WSAData );
	#endif
	p->m_hTcpSocket = ::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	printf("log tcp af=%d,type=%d,protocol=%d,handle=%X",AF_INET,SOCK_STREAM,IPPROTO_TCP,p->m_hTcpSocket);
	if(p->m_hTcpSocket == INVALID_SOCKET)
	{
		p->m_hTcpSocket = /*NULL*/0;
	  return false;
	}
#ifdef WIN32
  int bNodelay = 1;  
	int err = setsockopt(p->m_hTcpSocket,IPPROTO_TCP,TCP_NODELAY,(char *)&bNodelay,sizeof(bNodelay));//��������ʱ�㷨 
	if ( err == SOCKET_ERROR ) 
	{
	  stopLogToTCPSvr();
		return false;       
	} 		
#endif
	int ret;
	sockaddr_in dest_sin;
	memset(&dest_sin, 0 ,sizeof(dest_sin));
	dest_sin.sin_family 		= AF_INET;
	dest_sin.sin_addr.s_addr = inet_addr(ip);
	dest_sin.sin_port 			= htons(port); 
	ret = ::connect(p->m_hTcpSocket, (sockaddr *)&dest_sin, sizeof(dest_sin));
	if( ret < 0)
	{
	  stopLogToTCPSvr();
		return false;
	}

	p->m_bToLogTCPSvr=true;
	return true;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ��ʼ��־�����ָ�����ļ�
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-18 22:25
// ����˵��:  @file��ʾ��־�ļ�����
// �� �� ֵ:  true��ʾ�ɹ���false��ʾʧ��
//////////////////////////////////////////////////////////////////////////
bool SLog::startLogToFile(char* file)	
{
	getLog()->m_sLogFile = file;
	getLog()->m_bToFile=true;
	return true;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ��ʼ��־���������̨
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-18 22:25
// ����˵��:  void
// �� �� ֵ:  true��ʾ�ɹ���false��ʾʧ��
//////////////////////////////////////////////////////////////////////////
bool SLog::startLogToConsole()	
{
	getLog()->m_bToConsole = true;
	return true;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ֹͣ��־�����UDP������
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-18 22:25
// ����˵��:  void
// �� �� ֵ:  true��ʾ�ɹ���false��ʾʧ��
//////////////////////////////////////////////////////////////////////////
bool SLog::stopLogToUDPSvr()
{
	SLog *p = getLog();
	if(p->m_hUdpSocket != /*NULL*/0)
	{
		shutdown(p->m_hUdpSocket, 2);
		#ifdef WIN32
			closesocket(p->m_hUdpSocket);
		#else
			close(p->m_hUdpSocket);
		#endif
	}
	p->m_bToLogUDPSvr=false;
	return true;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ֹͣ��־�����TCP������
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-18 22:26
// ����˵��:  void
// �� �� ֵ:  true��ʾ�ɹ���false��ʾʧ��
//////////////////////////////////////////////////////////////////////////
bool SLog::stopLogToTCPSvr()
{
	SLog *p = getLog();
	if(p->m_hTcpSocket != /*NULL*/0)
	{
		shutdown(p->m_hTcpSocket, 2);
		#ifdef WIN32
			closesocket(p->m_hTcpSocket);
		#else
			close(p->m_hTcpSocket);
		#endif
	}
	p->m_bToLogTCPSvr=false;
	return true;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ֹͣ��־������ļ�
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-18 22:27
// ����˵��:  void
// �� �� ֵ:  true��ʾ�ɹ���false��ʾʧ��
//////////////////////////////////////////////////////////////////////////
bool SLog::stopLogToFile()
{
	getLog()->m_bToFile=false;
	return true;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ֹͣ��־���������̨
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-18 22:27
// ����˵��:  void
// �� �� ֵ:  true��ʾ�ɹ���false��ʾʧ��
//////////////////////////////////////////////////////////////////////////
bool SLog::stopLogToConsole()
{
	getLog()->m_bToConsole=false;
	return true;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ��ʼ��
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-18 22:28
// ����˵��:  void
// �� �� ֵ:  void
//////////////////////////////////////////////////////////////////////////
void SLog::init()
{
	m_sModuleName = "";
	m_bToConsole = true;
	m_bToFile	 = false;
	m_bToLogUDPSvr  = false;
	m_bToLogTCPSvr  = false;
#ifdef WIN32
	char buf[1205];
	memset(buf,0,1025);
	GetModuleFileName(/*NULL*/0,buf,1024);
	setModuleName(buf);
#endif
}

//������־ͷ
void SLog::logHead(short logtype,const char* file,int line,const char* func)
{
	g_skt_LogLock.lock();
	if(logtype<m_iLogLevel)
	{
		m_log.logtype = 100;
		return;
	}
	string str;
#ifdef WIN32
	m_log.threadid = (long)GetCurrentThreadId();
#else
	m_log.threadid = (long)pthread_self();
#endif
	m_log.logtype = (char)logtype;
	str = file;
	int p;
	p=str.find_last_of('\\',str.length());
	if(p>=0)
	{
		p++;
		str = str.substr(p,str.length()-p);
	}
	p=str.find_last_of('/',str.length());
	if(p>=0)
	{
		p++;
		str = str.substr(p,str.length()-p);
	}
	if(str.length()>=sizeof(m_log.filename))
		str = str.substr(0,sizeof(m_log.filename)-1);
	strcpy(m_log.filename,str.c_str());
	m_log.line = line;
	str = m_sModuleName;
	if(str.length()>=sizeof(m_log.modulename))
		str = str.substr(0,sizeof(m_log.modulename)-1);
	strcpy(m_log.modulename,str.c_str());
	struct  tm *t;
	time_t now;
	time(&now);
	t = localtime(&now);
	m_log.datetime.year = t->tm_year;
	m_log.datetime.month = t->tm_mon;
	m_log.datetime.day = t->tm_mday;
	m_log.datetime.hour = t->tm_hour;
	m_log.datetime.minute = t->tm_min;
	m_log.datetime.second = t->tm_sec;
	
	g_skt_CurrLogLevel = logtype;
	if(m_bToConsole||m_bToFile)
	{
		string type;
		switch(logtype)
		{
		case LOG_BASEDEBUG:
			type="basedebug";
			break;
		case LOG_DEBUG:
			type="debug";
			break;
		case LOG_WARN:
			type="warn ";
			break;
		case LOG_ERROR:
			type="error";
			break;
		case LOG_FAULT:
			type="fault";
			break;
		}
		char buf[1024];
		memset(buf,0,1024);
		sprintf(buf,"%04d-%02d-%02d %02d:%02d:%02d[%p] %s at %s(%s line:%d):\t",t->tm_year+1900,t->tm_mon+1,t->tm_mday,
					t->tm_hour,t->tm_min,t->tm_sec,(void*)m_log.threadid, type.c_str(),
					m_log.filename,func,m_log.line);
		if(m_bToConsole)
			printf("{%s}%s",m_log.modulename,buf);
		if(m_bToFile)
			logFile(buf);
	}
}

void SLog::logBody(const char * cformat, ...)
{
	if(m_log.logtype == 100)
	{
		g_skt_LogLock.unlock();
		return;
	}
	memset(m_log.msg,0x00,sizeof(m_log.msg));
	va_list ap;
	va_start(ap, cformat);
	//PPCƽ̨�£�vprintf����������Ա���ʹ�øú���
    //if(m_bToConsole)
    //      vprintf(cformat,ap);
    vsprintf(m_log.msg,cformat,ap);
	va_end(ap);
    if(m_bToConsole)
            printf(m_log.msg);
	if(m_bToConsole /*&& strlen(cformat) > 0 && cformat[strlen(cformat)-1] != '\n'*/)
		printf("\n");
	strcat(m_log.msg,"\r\n");
	m_log.msg[sizeof(m_log.msg)-1] = '\0';

	//ȥ����Ч�Ļس�����
//	while(strlen(m_log.msg)>0 && (m_log.msg[strlen(m_log.msg)-1] == '\r' || m_log.msg[strlen(m_log.msg)-1] == '\n'))
//		m_log.msg[strlen(m_log.msg)-1] = '\0';

	if(m_bToFile)
	{
		logFile(m_log.msg);
		//if(strlen(cformat) > 1 && (cformat[strlen(cformat)-2] != '\r' || cformat[strlen(cformat)-1] != '\n'))
		//	logFile("\r\n");
	}
	if(m_bToLogUDPSvr)
	{
		m_log.size = (sizeof(m_log) - sizeof(m_log.msg))+strlen(m_log.msg);
		int size = m_log.size;
		m_log.size = htonl(m_log.size);
		//LOG_SWAP_DWORD(m_log.size);
		LOG_SWAP_DWORD(m_log.line);
		LOG_SWAP_DWORD(m_log.threadid);
		int ret = sendto(m_hUdpSocket, (char *)&m_log, size, 0, (sockaddr*)&m_udp_dest_sin, sizeof(m_udp_dest_sin));
		//LOG_SWAP_DWORD(m_log.size);
		LOG_SWAP_DWORD(m_log.line);
		LOG_SWAP_DWORD(m_log.threadid);
		if(ret != sizeof(stuLog))
		{
			stopLogToUDPSvr();//����ʧ�ܲ��ٷ��͵�UDP
		}
	}
	if(m_bToLogTCPSvr)
	{
		m_log.size = (sizeof(m_log) - sizeof(m_log.msg))+strlen(m_log.msg);
		int size = m_log.size;
		m_log.size = htonl(m_log.size);
		//LOG_SWAP_DWORD(m_log.size);
		LOG_SWAP_DWORD(m_log.line);
		LOG_SWAP_DWORD(m_log.threadid);
		int ret=::send(m_hTcpSocket, (char *)&m_log, size, 0);
		//LOG_SWAP_DWORD(m_log.size);
		LOG_SWAP_DWORD(m_log.line);
		LOG_SWAP_DWORD(m_log.threadid);
		if(ret != size)
		{
			stopLogToTCPSvr();//����ʧ�ܲ��ٷ��͵�TCP
		}
	}
	g_skt_LogLock.unlock();
}

void SLog::logFile(char *buff)
{
	for(int i=0;i<=1;i++)
	{
		string pathfile = m_sLogFile;
		if(i==0)
		{
			string type;
			switch(g_skt_CurrLogLevel)
			{
			case LOG_BASEDEBUG:
				type=".basedebug";
				break;
			case LOG_DEBUG:
				type=".debug";
				break;
			case LOG_WARN:
				type=".warn ";
				break;
			case LOG_ERROR:
				type=".error";
				break;
			case LOG_FAULT:
				type=".fault";
				break;
			}
			pathfile += type;
		}
		FILE *fp=fopen(pathfile.c_str(),"ab+");
		if(fp == /*NULL*/0)
			return;
		fseek(fp,0,SEEK_END);
		fwrite(buff,sizeof(char),strlen(buff),fp);
		long len = ftell(fp);
		fclose(fp);
		//�ļ��Ƿ񳬹���󳤶�?
		int t;
		if(len > m_iMaxFileSize)
		{
			char tmpfile0[512];
			char tmpfile1[512];

			for(t=2;t<=m_iMaxBackFiles;t++)
			{
				memset(tmpfile0,0,sizeof(tmpfile0));
				memset(tmpfile1,0,sizeof(tmpfile1));
				sprintf(tmpfile0,"%s.back%d.zip",pathfile.c_str(),t-1);
				sprintf(tmpfile1,"%s.back%d.zip",pathfile.c_str(),t);
				::remove(tmpfile0);
				::rename(tmpfile1,tmpfile0);
			}
			char cmd[1024];
			memset(cmd,0,sizeof(cmd));
#ifndef WIN32
			//tar zcvf X.zip X.back
			sprintf(cmd,"tar zcvf \"%s\" \"%s\" ",tmpfile1,pathfile.c_str());
			::system(cmd);
#else
			//�Ƿ�winrar����
			FILE *fp2 = fopen("C:\\Program Files\\WinRAR\\winrar.exe","rb");
			if(fp2 == 0)
			{
				printf("@ERROR, [C:\\Program Files\\WinRAR\\winrar.exe]������!���޷�������־ѹ��!");
				::rename(pathfile.c_str(),tmpfile1);
			}
			else
			{
				fclose(fp2);
				//"C:\Program Files\WinRAR\winrar.exe" a c:\ysr_dgs_local.rar c:\ysr_dgs_local.log
				sprintf(cmd,"\"C:\\Program Files\\WinRAR\\winrar.exe\" a \"%s\" \"%s\" ",tmpfile1,pathfile.c_str());
				::system(cmd);
			}
#endif
			::remove(pathfile.c_str());
			/*
			//���ļ����Ƶ���һ��
			string tmpfile = pathfile+".back";
			FILE *fptmp=fopen(tmpfile.c_str(),"wb");
			if(fptmp == NULL)
			{
				printf("@@@@@@@@@@ ���������ļ�ʧ�ܣ������־�ļ�!");
				::remove(pathfile.c_str());
				return;
			}
			fp=fopen(pathfile.c_str(),"rb");
			if(fp == NULL)
			{
				printf("@@@@@@@@@@ �ٴδ���־�ļ�ʧ�ܣ������־�ļ�!");
				::remove(pathfile.c_str());
				return;
			}
			BYTE buf[1024];
			int ret;
			//����С�ļ� fseek(fp,(m_iMaxFileSize/10),SEEK_SET);
			while(1)
			{
				ret = fread(buf,1,1024,fp);
				if(ret <= 0)
					break;
				fwrite(buf,1,ret,fptmp);
			}
			fclose(fp);
			fclose(fptmp);
			::remove(pathfile.c_str());
			//�ļ�������󣬲�����������ֱ��ɾ��ԭ�ļ����������´δ����ļ����Ͳ�����Ҫ���������ļ���
			//::rename(tmpfile.c_str(),pathfile.c_str());		
			*/
		}
	}
}

void SLog::writeFileLine(char * filename,char *buff)
{
	FILE *fp=fopen(filename,"ab+");
	if(fp == /*NULL*/0)
		return;
	fseek(fp,0,SEEK_END);
	fwrite(buff,sizeof(char),strlen(buff),fp);
	fclose(fp);
}


