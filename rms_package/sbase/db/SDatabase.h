/**
 *
 * �� �� ��	: SDatabase.h
 * ��������	: 2007-07-23
 * ��    �� : �ۿ���(skt001@163.com)
 * �޸�����	: $Date: 2009/01/16 06:16:02 $
 * ��ǰ�汾	: $Revision: 1.2 $
 * �������� : ͨ�����ݿ�ӿ��༰�ײ���
 * �޸ļ�¼ : 
 *            $Log: SDatabase.h,v $
 *            Revision 1.2  2009/01/16 06:16:02  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2008/09/02 01:50:08  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.6  2008/04/03 02:44:34  shaokt
 *            LINUX�½�ysbase����Ϊ.so���������룬�豸�����ڱ���ʱ���Ӹ�so������Ŀ�������ɵ�ִ���ļ��У�WIN32��Ϊ���Է��㻹ֱ�ӱ������Դ��
 *
 *            Revision 1.5  2007/12/10 06:40:28  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.4  2007/10/29 07:30:23  shaokt
 *            ��Ӷ����ַ�Ƿ�Ϊ4�ı����ļ�⺯����Ϊ���ARM������pack(1)��ɵ��ڴ�����
 *
 *            Revision 1.3  2007/09/11 08:17:52  shaokt
 *            �������
 *
 *            Revision 1.2  2007/08/27 09:51:07  shaokt
 *            �������
 *
 *            Revision 1.1  2007/08/15 03:09:22  shaokt
 *            *** empty log message ***
 *
 **/

#if !defined(AFX_SKTDATABASE_H__D6BE0D97_13A8_11D4_A5D2_002078B03530__INCLUDED_)
#define AFX_SKTDATABASE_H__D6BE0D97_13A8_11D4_A5D2_002078B03530__INCLUDED_

#include "../SString.h"
#include "../SList.h"
#include "../SLock.h"

//��¼��
class SRecord
{
public:
	SRecord(int iCols);
	SRecord();
	~SRecord();

	//��������
	void SetColumns(int iCols);

	//ȡ�ڼ����ֶε�ֵ��iCol��0��ʼ
	SString GetValue(int iCol );

	//���õڼ����ֶε�ֵ��iCol��0��ʼ
	bool SetValue(int iCol,SString val);

	void clear();

	//ȡ����
	inline int GetCount()	{	return m_iCols;};
private:
	SString *m_pFields;
	int m_iCols;//����
};

//��¼����
class SRecordset
{
public:
	SRecordset();
	SRecordset(int iCols);
	~SRecordset();

	//��������
	inline void SetColumnName(int iCol,SString val){m_ColNames.SetValue(iCol,val);};

	//ȡ����
	inline SString GetColumnName(int iCol){return m_ColNames.GetValue(iCol);};
	void clear();

	//�����¼
	void SetSize(int iRows,int iCols);

	inline int GetRows(){return m_RecordArray.count();};
	inline int GetColumns(){return m_ColNames.GetCount();};

	//ȡ��¼
	SRecord* GetRecord(int iRow);

	SString GetValue(int iRow,int iCol);
	bool SetValue(int iRow,int iCol,SString val);

private:
	SRecord m_ColNames;
	
	SPtrArray<SRecord> m_RecordArray;
};

//���ݿ�����࣬�����ӳؽӿ�
class SDatabase
{
public:
	enum STATUS
	{
		UNCONNECT,
		IDLE,
		BUSY,
		DBERROR
	};
	SDatabase();
	virtual ~SDatabase();

	inline void SetParams(SString sParams)	{m_sParams = sParams;};
	inline SString GetParams()				{return m_sParams;};

	virtual bool Connect()=0;
	virtual bool DisConnect(){return false;};
	virtual bool TestConnect()=0;
	virtual int Retrieve(SString sql,SRecordset &rs)=0;
	virtual bool Execute(SString sql)=0;
	virtual bool UpdateLobFromFile(SString sTable,SString sLobField,SString sWhere,SString sFile)=0;
	virtual bool ReadLobToFile(SString sTable,SString sLobField,SString sWhere,SString sFile)=0;

	SString SelectInto(SString sql,int col=0);
	bool Reconnect();

	int SelectIntoI(SString sql,int col=0);

	float SelectIntoF(SString sql,int col=0);

	STATUS GetStatus()																	{return m_Status;};
	inline void SetStatus(STATUS stu)		{m_Status = stu;};
	SLock* GetLock()																		{return &m_Lock;};

private:
	STATUS m_Status;
	SLock m_Lock;//ʵ����
	SString m_sParams;//���Ӳ���������:dbname=znl4;user=postgres;password=123456;
};

template <class type>
class SDatabasePool
{
public:
	SDatabasePool()
	{
		SKTOBJECT("SDatabasePool");
		m_DatabasePool.setAutoDelete(true);
	}

	~SDatabasePool()
	{
		m_DatabasePool.clear();
	}

	void SetParams(SString sParams)
	{
		m_sParams = sParams;
	}

	int GetPoolSize()
	{
		return m_DatabasePool.count();
	}

	//����ָ����С�����ӳ�
	bool CreateDatabasePool(int iPools)
	{
		m_Lock.lock();
		m_DatabasePool.clear();
		m_DatabasePool.setSize(iPools);
		for(int i=0;i<iPools;i++)
		{
			m_DatabasePool.setAt(i,new type());//ȱ�����´�������ʵ��
			m_DatabasePool.getAt(i)->SetParams(m_sParams);
			m_DatabasePool.getAt(i)->DisConnect();
			if(m_DatabasePool.getAt(i)->Connect())
			{
				m_DatabasePool.getAt(i)->SetStatus(SDatabase::IDLE);
			}
			else
			{
				m_DatabasePool.getAt(i)->SetStatus(SDatabase::DBERROR);
			}
		}
		m_Lock.unlock();
		return true;
	}

	//ȡ��������ʵ��
	SDatabase* GetDatabase(bool bTestConnect/*=false*/)
	{
		//bTestConnect = true;//add by skt
		SDatabase *pDb = NULL;
		int iPools;
		int times=0;
		m_Lock.lock();
	begin:
		iPools = m_DatabasePool.count();
		if(iPools <= 0)
		{
			m_Lock.unlock();
			return NULL;
		}
		for(int i=0;i<iPools;i++)
		{
			pDb = (SDatabase*)m_DatabasePool.getAt(i);
			if(pDb->GetLock()->trylock())
			{
				//�п�������ֱ��ʹ��
				if(pDb->GetStatus() == SDatabase::DBERROR)//���ݿ����
				{
					pDb->Reconnect();
				}
				m_Lock.unlock();

				if(bTestConnect && !pDb->TestConnect())
				{
					pDb->GetLock()->unlock();
					return NULL;//������Ч
				}
				return pDb;//����
			}
		}
		//û�п��У��ȴ�
		#ifdef WIN32
			Sleep(100);
		#else
			usleep(100000);
		#endif
		times++;
		if(times < 600)	
			goto begin;
		m_Lock.unlock();
		return NULL;
	}

	void Release(SDatabase* pDb)
	{
		if(pDb)
			pDb->GetLock()->unlock();
	}

public:
	SLock m_Lock;//����
	SPtrArray<type> m_DatabasePool;//���ӳ�ʵ����
	SString m_sParams;//���Ӳ�������:dbname=znl4;user=postgres;password=123456;
	
};

#endif // !defined(AFX_SKTDATABASE_H__D6BE0D97_13A8_11D4_A5D2_002078B03530__INCLUDED_)
