/**
 *
 * �� �� �� : SApplication.h
 * �������� : 2009-8-20 13:36
 * ��    �� : �ۿ���(skt001@163.com)
 * �޸����� : $Date: 2011/08/31 08:43:32 $
 * ��ǰ�汾 : $Revision: 1.1 $
 * �������� : 
 * �޸ļ�¼ : 
 *            $Log: SApplication.h,v $
 *            Revision 1.1  2011/08/31 08:43:32  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.8  2011/04/27 02:58:48  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.7  2011/04/23 10:53:52  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.6  2011/04/22 06:32:33  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.5  2011/04/21 02:14:16  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.4  2011/04/11 12:08:34  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.3  2011/03/29 07:07:00  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.2  2011/03/29 01:03:26  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2011/02/25 03:12:05  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.2  2010/11/17 02:19:15  shaokt
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

#ifndef __SKT_APPLICATION_H__
#define __SKT_APPLICATION_H__

#include "SApi.h"
#include "SFile.h"
#include "SLog.h"
#include "SString.h"

#ifndef _WITHOUT_AGENT_CHANNEL_

//////////////////////////////////////////////////////////////////////////
// ��    ��:  CAgentPackage
// ��    ��:  �ۿ���
// ����ʱ��:  2011-3-29 9:54
// ��    ��:  ����ͨ��
//////////////////////////////////////////////////////////////////////////
struct CAgentPackage
{
public:
	CAgentPackage()
	{
		pBuffer = NULL;
		iLength = 0;
	}
	virtual ~CAgentPackage()
	{
		if(pBuffer != NULL)
		{
			delete[] pBuffer;
			pBuffer = NULL;
			iLength = 0;
		}
	}
	SString sMsg;
	BYTE *pBuffer;
	int iLength;
};

//////////////////////////////////////////////////////////////////////////
// ��    ��:  stuModuleInfo
// ��    ��:  �ۿ���
// ����ʱ��:  2011-3-29 9:53
// ��    ��:  ������Ϣ�ṹ
//////////////////////////////////////////////////////////////////////////
struct stuModuleInfo
{
	int handle;//���
	int pid;//���̺�
	SString name;//ģ����
	SString version;//�汾��
	SString desc;//ģ������
	SString crc;//ģ��CRC
	SString compile_time;//����ʱ��
	SString login_ip;//��¼����IP
	int login_port;//��¼���ж˿�
	SDateTime login_time;//��¼ʱ��
};

class SApplication;

class CSAgentClient
{
public:
	CSAgentClient();
	~CSAgentClient();

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ���մ�����Ϣ
	// ��    ��:  �ۿ���
	// ����ʱ��:  2010-7-1 16:59
	// ����˵��:  
	// �� �� ֵ:  
	//////////////////////////////////////////////////////////////////////////
	static int ReceiveMsg(SSocket *pSocket,SString &sMsg,BYTE* &pBuffer,int &iLength);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ���ʹ�����Ϣ
	// ��    ��:  �ۿ���
	// ����ʱ��:  2010-7-1 16:59
	// ����˵��:  
	// �� �� ֵ:  
	//////////////////////////////////////////////////////////////////////////
	static int SendMsg(SSocket *pSocket,SString &sMsg,BYTE* pBuffer=NULL,int iLength=0);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  �������̷�����Ϣ
	// ��    ��:  �ۿ���
	// ����ʱ��:  2010-7-1 16:56
	// ����˵��:  
	// �� �� ֵ:  
	//////////////////////////////////////////////////////////////////////////
	void AddMsgToAgent(SString &sMsg,BYTE* pBuffer=NULL,int iLength=0)
	{
		CAgentPackage *p = new CAgentPackage();
		p->sMsg = sMsg;
		p->pBuffer = pBuffer;
		p->iLength = iLength;
		m_SendList.append(p);
	}

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ��ȡ��ǰ�Ѿ���¼������Ľ���ģ���б���Ϣ
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-3-29 9:55
	// ����˵��:  ���÷��ص��б�
	// �� �� ֵ:  >=0��ʾ��������,<0��ʾʧ��
	//////////////////////////////////////////////////////////////////////////
	int GetModuleList(SPtrList<stuModuleInfo> &module_list);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ȡ�������˵�������Ϣ
	// ��    ��:  �ۿ���
	// ����ʱ��:  2012-9-26 11:44
	// ����˵��:  @sDisk ��ʾ��Ҫ��ȡ��Ӳ����Ϣ��disks=3;disk1=/dev/sda1;disk2=/dev/sda2;disk3=/dev/sda3;
	//            @sRunInfo���÷��ص����ַ���������������Ϣ,act=runinfo;cpu_used=%d;mem_all=%d;mem_used=%d;mem_free=%d;disk1_all=%d;disk1_used=%d;disk1_free=%d;disk1_per=%d;
	// �� �� ֵ:  1��ʾ�ɹ���0��ʾʧ��
	//////////////////////////////////////////////////////////////////////////
	bool GetRunInfo(SString sDisk,SString &sRunInfo);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ȡָ��ģ����ڴ�������ϵľ��
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-3-29 14:42
	// ����˵��:  ģ�����ƣ����������ƣ�WIN32ƽ̨�ϲ���Ҫ��.exe
	// �� �� ֵ:  =0��ʾģ��δ�ҵ���>0��ʾ���̾��
	//////////////////////////////////////////////////////////////////////////
	int GetModuleHandle(SString sModName);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ��ָ����ģ�鷢��һ����Ϣ
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-3-29 11:06
	// ����˵��:  handleΪĿ��ģ��ľ��
	// �� �� ֵ:  ���ͳɹ�����ture��ʧ�ܷ���false
	//////////////////////////////////////////////////////////////////////////
	bool AddMsgToModule(int handle,SString &sMsg,BYTE* pBuffer=NULL,int iLength=0);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ���ദ�������Ϣ
	// ��    ��:  �ۿ���
	// ����ʱ��:  2010-7-1 16:58
	// ����˵��:  
	// �� �� ֵ:  
	//////////////////////////////////////////////////////////////////////////
	bool ProcessAgentMsgBase(SString &sMsg,BYTE* pBuffer=NULL,int iLength=0);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  �����ദ�������Ϣ
	// ��    ��:  �ۿ���
	// ����ʱ��:  2010-7-1 16:58
	// ����˵��:  @from_handleΪ��Ϣ��Դģ��ľ��(0��ʾ��Ϣ���Դ������)
	//         :  @sMsgΪ��Ϣ�ַ���
	//         :  @pBufferΪ��ϢЯ���Ķ������������ݣ�NULL��ʾ�޶���������
	//         :  @iLengthΪ���������ݳ���
	// �� �� ֵ:  true��ʾ����ɹ���false��ʾ����ʧ��
	//////////////////////////////////////////////////////////////////////////
	virtual bool ProcessAgentMsg(int from_handle,SString &sMsg,BYTE* pBuffer=NULL,int iLength=0)=0;

	//////////////////////////////////////////////////////////////////////////
	// ��    ��:  �����̣߳�ִ�д��������߳�����ʱ��ռ��Run������Ҳ��ֱ������
	// ��    ��:  �ۿ���
	// ����ʱ��:  2012-5-30 11:00
	// ����˵��:  @lp��this
	// �� �� ֵ:  NULL
	//////////////////////////////////////////////////////////////////////////
	static void* ThreadAgent(void* lp);

	//////////////////////////////////////////////////////////////////////////
	// ��    ��:  �����������
	// ��    ��:  �ۿ���
	// ����ʱ��:  2012-5-31 10:13
	// ����˵��:  @bBlockΪtrue��ʾ�������У�ֱ�������˳���false��ʾ�����������߳����д������
	// �� �� ֵ:  true/false
	//////////////////////////////////////////////////////////////////////////
	bool StartAgent(bool bBlock);

public:
	bool m_bLogined;//�Ƿ��Ѿ���¼
	SString m_sAgentIp;//����IP��ַ��ȱʡΪ127.0.0.1
	int m_iAgentPort;//����˿�
	SPtrList<CAgentPackage> m_SendList;
	SString m_sWaitMsgAct;//�ȴ���Ϣ��act��־
	SString m_sWaitMsg;//�ȴ���Ϣ�ķ����ַ���
	int m_iCpuPercent;
	SApplication *m_pApp;
	int m_iThreads;//�߳�����
};
#endif

//////////////////////////////////////////////////////////////////////////
// ��    ��:  SApplication
// ��    ��:  �ۿ���
// ����ʱ��:  2008-10-10 14:16
// ��    ��:  Ӧ�ó��������
//////////////////////////////////////////////////////////////////////////
#ifndef _WITHOUT_AGENT_CHANNEL_
class SApplication : public CSAgentClient
{
public:
	friend class CSAgentClient;
#else
class SApplication
{
public:
#endif
	SApplication();
	virtual ~SApplication();
	
	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ����Ӧ�ó���
	// ��    ��:  �ۿ���
	// ����ʱ��:  2008-10-10 14:17
	// ����˵��:  @argc/argvΪmain�������
	//            @szDate/szTimeΪ��������ʱ��
	//            @bBlockΪ�Ƿ��������У�trueΪ������falseΪ������
	// �� �� ֵ:  true/false
	//////////////////////////////////////////////////////////////////////////
	bool Run(int argc, char* argv[],const char* szDate,const char* szTime,bool bBlock=true);
	
	////////////////////////////////////////////////////////////////////////
	// ��    ��:  �������񣬿�������Ӧ�õķ��񣬸ú���������������ʵ�֣�������������ɺ���뷵��
	// ��    ��:  �ۿ���
	// ����ʱ��:  2010-7-1 9:15
	// ����˵��:  
	// �� �� ֵ:  null
	//////////////////////////////////////////////////////////////////////////
	virtual bool Start()=0;

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ֹͣ���񣬹ر�����Ӧ�õķ���
	// ��    ��:  �ۿ���
	// ����ʱ��:  2010-7-1 9:18
	// ����˵��:  
	// �� �� ֵ:  null
	//////////////////////////////////////////////////////////////////////////
	virtual bool Stop()=0;

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ����ģ��汾��
	// ��    ��:  �ۿ���
	// ����ʱ��:  2009-5-19 10:56
	// ����˵��:  sVer(����:<��Ʒ�ڲ��ͺ�>.<�׶ΰ汾��>.<ģ��汾��>)
	// �� �� ֵ:  NULL
	//////////////////////////////////////////////////////////////////////////
	void SetVersion(SString sVer);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ����ģ������
	// ��    ��:  �ۿ���
	// ����ʱ��:  2009-5-19 12:29
	// ����˵��:  sDesc����
	// �� �� ֵ:  NULL
	//////////////////////////////////////////////////////////////////////////
	void SetModuleDesc(SString sDesc);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ����ģ����Ϣ
	// ��    ��:  �ۿ���
	// ����ʱ��:  2009-5-19 12:29
	// ����˵��:  sInfo = name=;ver=;crc=;date=
	// �� �� ֵ:  NULL
	//////////////////////////////////////////////////////////////////////////
	void SetModuleInfo(SString sInfo);
	////////////////////////////////////////////////////////////////////////
	// ��    ��:  �˳�ģ��
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-3-29 8:44
	// ����˵��:  
	// �� �� ֵ:  
	//////////////////////////////////////////////////////////////////////////
	void Quit()
	{
		m_bHalt = true;
	}
	inline bool IsDebugMode(){return m_bDebugMode;};
	inline bool IsLogToConsole(){return m_bLogToConsole;};
	bool IsParam(SString sParamName);
	bool IsParam(SString sParamName,SString &sParamValue);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ȡ�����в�������
	// ��    ��:  �ۿ���
	// ����ʱ��:  2014-5-19 10:13
	// ����˵��:  @sParamNameΪ������
	// �� �� ֵ:  ����ֵ
	//////////////////////////////////////////////////////////////////////////
	SString GetParam(SString sParamName);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ȡ���������Ͳ�������
	// ��    ��:  �ۿ���
	// ����ʱ��:  2014-5-19 10:13
	// ����˵��:  @sParamNameΪ������
	// �� �� ֵ:  ����ֵ
	//////////////////////////////////////////////////////////////////////////
	int GetParamI(SString sParamName);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ȡ�����и����Ͳ�������
	// ��    ��:  �ۿ���
	// ����ʱ��:  2014-5-19 10:13
	// ����˵��:  @sParamNameΪ������
	// �� �� ֵ:  ����ֵ
	//////////////////////////////////////////////////////////////////////////
	float GetParamF(SString sParamName);

	inline SString GetExePath(){return m_sExePath;};
	inline SString GetModule(){return m_sModule;};
	inline SString GetAppbaseVer(){return m_sAppbaseVer;};
	inline SString GetModuleVer(){return m_sModuleVer;};
	inline SString GetModuleCrc(){return m_sModuleCrc;};
	inline SString GetModuleTime(){return m_sModuleTime;};
	inline SString GetModuleDesc(){return m_sModuleDesc;};
	inline void SetFork(bool b){m_bFork = b;};
	inline SString GetInfo(){return m_sModuleInfo;};
	inline void SetInfo(SString info){m_sModuleInfo = info;};

	static bool ParseCommandLine(SString str);

	inline bool IsStarted(){return m_bStarted;};
	inline void SetStarted(bool b){m_bStarted=b;};
private:
	
	bool TouchClose();//����һ�������̵�close�ļ�����֪ͨԭ���̹ر�
	bool RemoveClose();//�Ƴ�close�ļ�
	bool IsClosedExist();//close�ļ��Ƿ���ڣ�
	bool SearchOldProcess(int &pid,int &ppid,SString &name);

	bool _Start();
	bool _Stop();

	SString m_sExePath;//ִ�г�������·��
	SString m_sModule;//ģ����
	SString m_sAppbaseVer;//�����汾
	SString m_sModuleVer;//ģ��汾
	SString m_sModuleCrc;//ģ��CRC
	SString m_sModuleTime;//ģ������ʱ��
	SString m_sModuleDesc;//ģ������
	SString m_sModuleInfo;//ģ����Ϣ
	bool m_bHalt;//�Ƿ�׼���˳�?

	bool m_bDebugMode;//�Ƿ��ڵ���ģʽ
	bool m_bLogToConsole;//�Ƿ�������־��Ϣ���������̨
	bool m_bFork;//LINUX���Ƿ�ִ��fork
	bool m_bStarted;//�Ƿ��Ѿ�����Ӧ��
	
public:
	int m_iArgc;
	char** m_ppArgv;
};



#endif//__YS_REC_APPLICATION_H__
