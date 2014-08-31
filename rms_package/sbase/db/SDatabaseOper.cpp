/**
 *
 * �� �� ��	: SDatabaseOper.cpp
 * ��������	: 2008-06-16
 * ��    �� : �ۿ���(skt001@163.com)
 * �޸�����	: $Date: $
 * ��ǰ�汾	: $Revision: $
 * �������� : 
 * �޸ļ�¼ : 
 *            $Log: $
 *
 **/

#include "SDatabaseOper.h"

CSDatabaseOper::CSDatabaseOper()
{
}

CSDatabaseOper::~CSDatabaseOper()
{
}

void CSDatabaseOper::SetDatabasePool(SDatabasePool<SDatabase> *pPool)
{
	m_pDatabasePool = pPool;
}

SDatabase* CSDatabaseOper::GetDatabase(bool bTestConnect)
{
	SDatabase* p = m_pDatabasePool->GetDatabase(bTestConnect);
	return p;
}

//�ͷ�����
void CSDatabaseOper::ReleaseDatabase(SDatabase* pDB)
{
	m_pDatabasePool->Release(pDB);//ֻҪ�������һ���ص�Release���ɣ���Ϊ�ڲ�ֻ�Ƕ�pDB�µ�����unlock�������޹�
}

//ȡ��¼����ʧ�ܻط�<0
int CSDatabaseOper::RetrieveRecordset(SString sql,SRecordset &rs)
{
	SDatabase *pDB = GetDatabase();
	if(pDB == NULL)
	{
		LOGWARN("�޷���ȡ���õ����ݿ�����!ȡ��¼��ʧ��!sql=%s",sql.data());
		return -1;
	}
	int cnt = pDB->Retrieve(sql,rs);
	ReleaseDatabase(pDB);
	return cnt;
}

int CSDatabaseOper::SelectIntoI(SString sql,int col/*=0*/)
{
	return SelectInto(sql,col).toInt();
}
float CSDatabaseOper::SelectIntoF(SString sql,int col/*=0*/)
{
	return SelectInto(sql,col).toFloat();
}
//ȡ��¼����ʧ�ܻط�<0
SString CSDatabaseOper::SelectInto(SString sql,int col/*=0*/)
{
	SDatabase *pDB = GetDatabase();
	if(pDB == NULL)
	{
		LOGWARN("�޷���ȡ���õ����ݿ�����!ȡ��¼��ʧ��!sql=%s",sql.data());
		return "";
	}
	SString ret = pDB->SelectInto(sql,col);
	ReleaseDatabase(pDB);
	return ret;
}

//ִ��SQL���ɹ�����true,ʧ�ܷ���false
bool CSDatabaseOper::ExecuteSQL(SString sql)
{
	SDatabase *pDB = GetDatabase();
	if(pDB == NULL)
	{
		LOGWARN("�޷���ȡ���õ����ݿ�����!ִ��SQLʧ��!sql=%s",sql.data());
		return false;
	}
	bool cnt = pDB->Execute(sql);
	ReleaseDatabase(pDB);
	return cnt;
}


