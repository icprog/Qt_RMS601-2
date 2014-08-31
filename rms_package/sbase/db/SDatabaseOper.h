/**
 *
 * �� �� ��	: SDatabaseOper.h
 * ��������	: 2008-06-16
 * ��    �� : �ۿ���(skt001@163.com)
 * �޸�����	: $Date: $
 * ��ǰ�汾	: $Revision: $
 * �������� : ���ݿ����������
 * �޸ļ�¼ : 
 *            $Log: $
 *
 **/

#if !defined(AFX_SKTDATABASE_OPER_H__D6BE0D97_13A8_11D4_A5D2_002078B03530__INCLUDED_)
#define AFX_SKTDATABASE_OPER_H__D6BE0D97_13A8_11D4_A5D2_002078B03530__INCLUDED_

#include "SDatabase.h"

class CSDatabaseOper
{
public:

	CSDatabaseOper();
	~CSDatabaseOper();

	void SetDatabasePool(SDatabasePool<SDatabase> *pPool);

	//ȡ���ݿ�����ʵ����bTestConnect=trueʱ��ʾ�õ���������ʱ�ȼ������ԣ���ʧ�ܷ���NULL
	//bTestConnect=falseʱ����⣬ֱ��ʹ�ã����ϲ�����ٴε���GetDatabase(true)ȡ�ӿ�����
	SDatabase* GetDatabase(bool bTestConnect=false);

	//�ͷ�����
	void ReleaseDatabase(SDatabase* pDB);

	//ȡ��¼����ʧ�ܻط�<0
	int RetrieveRecordset(SString sql,SRecordset &rs);

	int SelectIntoI(SString sql,int col=0);
	float SelectIntoF(SString sql,int col=0);
	SString SelectInto(SString sql,int col=0);

	//ִ��SQL���ɹ�����true,ʧ�ܷ���false
	bool ExecuteSQL(SString sql);

private:
	SDatabasePool<SDatabase> *m_pDatabasePool;

};


#endif // !defined(AFX_SKTDATABASE_OPER_H__D6BE0D97_13A8_11D4_A5D2_002078B03530__INCLUDED_)
