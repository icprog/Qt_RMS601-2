/**
 *
 * �� �� �� : SLog.h
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
 *            $Log: SLog.h,v $
 *            Revision 1.1  2011/08/31 08:43:33  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.3  2011/04/29 08:53:08  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.2  2011/04/20 14:00:54  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2011/02/25 03:12:07  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2010/08/09 03:04:43  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2009/09/15 02:14:08  shaokt
 *            ͨѸ��¼����װ����Ŀ�״��ύ
 *
 *            Revision 1.2  2009/06/19 10:35:05  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2008/09/02 01:50:08  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.5  2008/02/18 01:07:55  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.4  2007/10/19 06:18:33  shaokt
 *            ������־�ļ���С
 *
 *            Revision 1.3  2007/09/11 08:17:53  shaokt
 *            �������
 *
 *            Revision 1.2  2007/09/04 01:43:38  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2007/08/15 03:09:22  shaokt
 *            *** empty log message ***
 *
 **/

#ifndef SKTLOGGER_H_
#define SKTLOGGER_H_

#ifdef WIN32
	#define WIN32_LEAN_AND_MEAN 
	#include <stdio.h> 
	#include <stdlib.h> 
	#include <winsock2.h> 
	#pragma comment(lib,"ws2_32.lib")
#else
	#include <sys/socket.h>
	#include <arpa/inet.h>
	#include <sys/select.h>
	#include <unistd.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <stdarg.h>
#include <time.h>

#ifdef _POWERPC
#ifndef DWORD
#define DWORD unsigned long
#endif
#define LOG_SWAP_DWORD(dw) dw = (((DWORD)dw) << 24 | ((DWORD)dw) >> 24) | ((((DWORD)dw)&0x0000ff00) << 8 | (((DWORD)dw)&0x00ff0000) >> 8);
#else
#define LOG_SWAP_DWORD(dw)
#endif

using namespace std;

#ifdef WIN32
#ifndef __FUNCTION__
#define __FUNCTION__ ""
#endif
#endif

#ifdef _SKT_WITHOUT_BASEDEBUG
	#define LOGBASEDEBUG 
#else
	#define LOGBASEDEBUG SLog::getLog()->logHead(0,__FILE__,__LINE__,__FUNCTION__);SLog::getLog()->logBody
#endif
#ifdef _SKT_WITHOUT_DEBUG
	#define LOGDEBUG 
#else
	#define LOGDEBUG SLog::getLog()->logHead(1,__FILE__,__LINE__,__FUNCTION__);SLog::getLog()->logBody
#endif
#ifdef _SKT_WITHOUT_WARN
	#define LOGWARN  
#else
	#define LOGWARN  SLog::getLog()->logHead(2,__FILE__,__LINE__,__FUNCTION__);SLog::getLog()->logBody
#endif
#ifdef _SKT_WITHOUT_ERROR
	#define LOGERROR 
#else
	#define LOGERROR SLog::getLog()->logHead(3,__FILE__,__LINE__,__FUNCTION__);SLog::getLog()->logBody
#endif
#ifdef _SKT_WITHOUT_FAULT
	#define LOGFAULT 
#else
	#define LOGFAULT SLog::getLog()->logHead(4,__FILE__,__LINE__,__FUNCTION__);SLog::getLog()->logBody
#endif

#include "SLock.h"

#ifndef SOCKET 
#define SOCKET int
#endif

#ifndef NULL 
#define NULL 0
#endif

#ifndef INVALID_SOCKET
#define INVALID_SOCKET -1
#endif

#ifndef SOCKET_ERROR
#define SOCKET_ERROR -1
#endif

#ifndef BYTE
#define BYTE unsigned char
#endif

#define MAX_PACKAGE_SIZE 1020


#pragma pack(push)
#pragma pack(1)
class SLog  
{
public:
	enum LOG_LEVEL
	{
		LOG_BASEDEBUG=0,
		LOG_DEBUG=1,
		LOG_WARN=2,
		LOG_ERROR=3,
		LOG_FAULT=4,
		LOG_NONE=5
	};
	struct stuDateTime
	{
		char year;
		char month;
		char day;
		char hour;
		char minute;
		char second;
	};
	struct stuLog
	{
		int	size;
		long	threadid;
		char	logtype;
		stuDateTime		datetime;
		char	modulename[20];
		char	filename[40];
		int		line;
		char	msg[10240];//attr:m=xxx;f=xxx;t=xxx;
	};
	struct stuLogDetail
	{
	public:
		stuLogDetail()
		{
			pNext = NULL;
		}
		string	clientip;
		string	modulename;
		long	threadid;
		string	datetime;
		short	logtype;
		string	filename;
		string	field1;
		string	field2;
		string	field3;
		string	field4;
		string	field5;
		int		line;
		string	msg;
		stuLogDetail *pNext;
	};

	SLog();
	virtual ~SLog();


	static std::string bufToHexString(BYTE *pBuffer, int iLen);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ȡ��̬��־ʵ��
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-18 22:31
	// ����˵��:  void
	// �� �� ֵ:  SLog*
	//////////////////////////////////////////////////////////////////////////
	static SLog* getLog();

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  �����־ͷ
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-18 22:32
	// ����˵��:  
	// �� �� ֵ:  
	//////////////////////////////////////////////////////////////////////////
	void logHead(short logtype,const char* file,int line,const char* func);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  �����־��
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-18 22:32
	// ����˵��:  
	// �� �� ֵ:  
	//////////////////////////////////////////////////////////////////////////
	void logBody(const char * cformat, ...);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ��¼���ļ�
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-18 22:32
	// ����˵��:  
	// �� �� ֵ:  
	//////////////////////////////////////////////////////////////////////////
	inline void logFile(char *buff);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  д�ļ���
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-18 22:33
	// ����˵��:  
	// �� �� ֵ:  
	//////////////////////////////////////////////////////////////////////////
	static void writeFileLine(char * filename,char *buff);
	
	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ������־����
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-18 22:17
	// ����˵��:  @lΪ�µ���־����
	// �� �� ֵ:  void
	//////////////////////////////////////////////////////////////////////////
	static void setLogLevel(LOG_LEVEL l);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ������־�ļ�����С
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-18 22:17
	// ����˵��:  @size�ļ���С����λ�ֽ�
	// �� �� ֵ:  void
	//////////////////////////////////////////////////////////////////////////
	static void setLogFileMaxSize(int size);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ���ñ����ļ����������
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-18 22:18
	// ����˵��:  @files��ʾ�����ļ��������
	// �� �� ֵ:  void
	//////////////////////////////////////////////////////////////////////////
	static void setLogFileMaxBackFiles(int files);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ���õ�ǰģ������
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-18 22:19
	// ����˵��:  @name�µ�ģ������
	// �� �� ֵ:  void
	//////////////////////////////////////////////////////////////////////////
	static void setModuleName(char* name);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ȡ��ǰģ������
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-18 22:19
	// ����˵��:  void
	// �� �� ֵ:  ģ������
	//////////////////////////////////////////////////////////////////////////
	static char* getModuleName();

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ��ʼ��־�����UDP������
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-18 22:20
	// ����˵��:  @ipΪ������IP��ַ
	//            @port��ʾ�˿�
	// �� �� ֵ:  true��ʾ�ɹ���false��ʾʧ��
	//////////////////////////////////////////////////////////////////////////
	static bool startLogToUDPSvr(char* ip,int port=7001);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ��ʼ��־�����TCP������
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-18 22:24
	// ����˵��:  @ipΪ������IP��ַ
	//            @port��ʾ�˿�
	// �� �� ֵ:  true��ʾ�ɹ���false��ʾʧ��
	//////////////////////////////////////////////////////////////////////////
	static bool startLogToTCPSvr(char* ip,int port=7001);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ��ʼ��־�����ָ�����ļ�
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-18 22:25
	// ����˵��:  @file��ʾ��־�ļ�����
	// �� �� ֵ:  true��ʾ�ɹ���false��ʾʧ��
	//////////////////////////////////////////////////////////////////////////
	static bool startLogToFile(char* file);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ��ʼ��־���������̨
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-18 22:25
	// ����˵��:  void
	// �� �� ֵ:  true��ʾ�ɹ���false��ʾʧ��
	//////////////////////////////////////////////////////////////////////////
	static bool startLogToConsole();

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ֹͣ��־�����UDP������
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-18 22:25
	// ����˵��:  void
	// �� �� ֵ:  true��ʾ�ɹ���false��ʾʧ��
	//////////////////////////////////////////////////////////////////////////
	static bool stopLogToUDPSvr();

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ֹͣ��־�����TCP������
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-18 22:26
	// ����˵��:  void
	// �� �� ֵ:  true��ʾ�ɹ���false��ʾʧ��
	//////////////////////////////////////////////////////////////////////////
	static bool stopLogToTCPSvr();

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ֹͣ��־������ļ�
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-18 22:27
	// ����˵��:  void
	// �� �� ֵ:  true��ʾ�ɹ���false��ʾʧ��
	//////////////////////////////////////////////////////////////////////////
	static bool stopLogToFile();

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ֹͣ��־���������̨
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-18 22:27
	// ����˵��:  void
	// �� �� ֵ:  true��ʾ�ɹ���false��ʾʧ��
	//////////////////////////////////////////////////////////////////////////
	static bool stopLogToConsole();
//	SLock lock;

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ��ʼ��
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-18 22:28
	// ����˵��:  void
	// �� �� ֵ:  void
	//////////////////////////////////////////////////////////////////////////
	void init();
private:
	SOCKET m_hTcpSocket;
	SOCKET m_hUdpSocket;
	sockaddr_in m_dest_sin;//LOG�������ĵ�ַ

	string m_sModuleName;//ģ����

	string m_sLogFile;//LOG�ļ���

	bool m_bToConsole;//�Ƿ����������̨
	bool m_bToFile;//�Ƿ�������ļ�
	bool m_bToLogUDPSvr;//�Ƿ������UDP������
	bool m_bToLogTCPSvr;//�Ƿ������TCP������

	sockaddr_in m_udp_dest_sin;

	int m_iLogLevel;//��־����
	long m_iMaxFileSize;//������־�ļ���С
	int m_iMaxBackFiles;//���ı�����־�ļ�����ȱʡ5��
	stuLog m_log;
};
#pragma pack()
#pragma pack(pop)


#endif 
