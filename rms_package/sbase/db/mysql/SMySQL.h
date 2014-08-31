/**
 *
 * �� �� �� : SMySQL.h
 * �������� : 2007-10-9 14:10
 * ��    �� : �ۿ���(skt001@163.com)
 * �޸����� : $Date: 2008/09/02 01:50:09 $
 * ��ǰ�汾 : $Revision: 1.1 $
 * �������� : MySQL���ݿ��YsDatabase�ӿ����ʵ��
 * �޸ļ�¼ : 
 *            $Log: SMySQL.h,v $
 *            Revision 1.1  2008/09/02 01:50:09  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2007/10/09 11:59:45  shaokt
 *            MYSQL���ݿ�����ӿ�
 *
 *
 **/

#if !defined(AFX_SKTMYSQL_H__D6BE0D97_13A8_11D4_A5D2_002078B03530__INCLUDED_)
#define AFX_SKTMYSQL_H__D6BE0D97_13A8_11D4_A5D2_002078B03530__INCLUDED_

#include "../SDatabase.h"
#include "../../SLog.h"
#include "../../SFile.h"

#include <mysql.h>

#ifdef WIN32
	#pragma comment(lib,"libmysql.lib")
#endif

#ifndef NULL
#define NULL 0
#endif

class SMySQL : public SDatabase
{
public:
	SMySQL();
	virtual ~SMySQL();

	virtual bool Connect();
	virtual bool DisConnect();
	virtual bool TestConnect();
	virtual int Retrieve(SString sql,SRecordset &rs);
	virtual bool Execute(SString sql);
	virtual bool UpdateLobFromFile(SString sTable,SString sLobField,SString sWhere,SString sFile);
	virtual bool ReadLobToFile(SString sTable,SString sLobField,SString sWhere,SString sFile);

private:
	MYSQL *m_pConn;//mysql struct
	int m_iTestTimes;
};


#endif // !defined(AFX_SKTMYSQL_H__D6BE0D97_13A8_11D4_A5D2_002078B03530__INCLUDED_)
