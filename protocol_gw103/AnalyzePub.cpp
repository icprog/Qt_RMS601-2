#include "AnalyzePub.h"

char DescType[256][64] = {
/*  0-  4*/	{"δ֪����"},{"������Ϣ"},{"��ʱ��ĵ�����Ϣ"},{"˫����Ϣ"},{"��ʱ���˫����Ϣ"},
/*  5-  9*/	{"��λ����Ϣ"},{"��ʱ��Ĳ�λ����Ϣ"},{"32���ش�"},{"��ʱ���32���ش�"},{"����ֵ,��һ��ֵ"},
/* 10- 14*/	{"��ʱ��Ĳ���ֵ,��һ��ֵ"},{"����ֵ,��Ȼ�ֵ"},{"��ʱ��Ĳ���ֵ,��Ȼ�ֵ"},{"����ֵ,�̸�����"},{"��ʱ��Ĳ���ֵ,�̸�����"},
/* 15- 19*/	{"�ۼ���"},{"��ʱ����ۼ���"},{"��ʱ��ļ̵籣��װ���¼�"},{"��ʱ��ļ̵籣��װ�ó��������¼�"},{"��ʱ��ļ̵籣��װ�ó��������·��Ϣ"},
/* 20- 24*/	{"����λ����ĳ��鵥����Ϣ"},{"����ֵ,����Ʒ�������ʵĹ�һ��ֵ"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/* 25- 29*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/* 30- 34*/	{"��CP56Time2aʱ��ĵ�����Ϣ"},{"��CP56Time2aʱ���˫����Ϣ"},{"��CP56Time2aʱ��Ĳ�λ����Ϣ"},{"��CP56Time2aʱ���32���ش�"},{"��CP56Time2aʱ��Ĳ���ֵ,��һ��ֵ"},
/* 35- 39*/	{"��CP56Time2aʱ��Ĳ���ֵ,��Ȼ�ֵ"},{"��CP56Time2aʱ��Ĳ���ֵ,�̸�����"},{"��CP56Time2aʱ����ۼ���"},{"��CP56Time2aʱ��ļ̵籣��װ���¼�"},{"��CP56Time2aʱ��ļ̵籣��װ�ó��������¼�"},
/* 40- 44*/	{"��CP56Time2aʱ��ļ̵籣��װ�ó��������·��Ϣ"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/* 45- 49*/	{"��������"},{"˫������"},{"���ڲ�����"},{"�趨ֵ����,��һ��ֵ"},{"�趨ֵ����,��Ȼ�ֵ"},
/* 50- 54*/	{"�趨ֵ����̸�����"},{"�趨ֵ����,32���ش�"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/* 55- 59*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/* 60- 64*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/* 65- 69*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/* 70- 74*/	{"��ʼ������"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/* 75- 79*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/* 80- 84*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/* 85- 89*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/* 90- 94*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/* 95- 99*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*100-104*/	{"���ٻ�����"},{"�ۼ����ٻ�����"},{"������"},{"ʱ��ͬ������"},{"��������"},
/*105-109*/	{"��λ��������"},{"�ռ�������ʱ"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*110-114*/	{"����ֵ����,��һ��ֵ"},{"����ֵ��������Ȼ�ֵ"},{"����ֵ����,�̸�����"},{"��������"},{"δ֪����"},
/*115-119*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*120-124*/	{"�ļ���������"},{"�ڻ�������"},{"�ٻ�Ŀ¼,ѡ���ļ�,�ٻ��ļ��ٻ���"},{"���Ľ�,���Ķ�"},{"�Ͽ��ļ�,�Ͽɽ�"},
/*125-129*/	{"��"},{"Ŀ¼"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*130-134*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*135-139*/	{"δ֪����"},{"���������趨ֵ����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*140-144*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*145-149*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*150-154*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*155-159*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*160-164*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*165-169*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*170-174*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*175-179*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*180-184*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*185-189*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*190-194*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*195-199*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*200-204*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*205-209*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*210-214*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*215-219*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*220-224*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*225-229*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*230-234*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*235-239*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*240-244*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*245-249*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*250-254*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
/*255-   */	{"δ֪����"}
};

char* DescCause[50][64] = {
/*  0-  4*/	{"δ֪ԭ��"},{"ѭ��"},{"����ɨ��"},{"ͻ��"},{"��ʼ�����"},
/*  5-  9*/	{"������߱�����"},{"����"},{"����ȷ��"},{"ֹͣ����"},{"ֹͣ����ȷ��"},
/* 10- 14*/	{"������ֹ"},{"Զ����������ķ�����Ϣ"},{"������������ķ�����Ϣ"},{"�ļ�����"},{"δ֪ԭ��"},
/* 15- 19*/	{"δ֪ԭ��"},{"δ֪ԭ��"},{"δ֪ԭ��"},{"δ֪ԭ��"},{"δ֪ԭ��"},
/* 20- 24*/	{"��Ӧվ�ٻ�"},{"��Ӧ��1���ٻ�"},{"��Ӧ��2���ٻ�"},{"��Ӧ��3���ٻ�"},{"��Ӧ��4���ٻ�"},
/* 25- 29*/	{"��Ӧ��5���ٻ�"},{"��Ӧ��6���ٻ�"},{"��Ӧ��7���ٻ�"},{"��Ӧ��8���ٻ�"},{"��Ӧ��9���ٻ�"},
/* 30- 34*/	{"��Ӧ��10���ٻ�"},{"��Ӧ��11���ٻ�"},{"��Ӧ��12���ٻ�"},{"��Ӧ��13���ٻ�"},{"��Ӧ��14���ٻ�"},
/* 35- 39*/	{"��Ӧ��15���ٻ�"},{"��Ӧ��16���ٻ�"},{"��Ӧ������վ�ٻ�"},{"��Ӧ��1��������ٻ�"},{"��Ӧ��2��������ٻ�"},
/* 40- 44*/	{"��Ӧ��3��������ٻ�"},{"��Ӧ��4��������ٻ�"},{"δ֪ԭ��"},{"δ֪ԭ��"},{"δ֪�����ͱ�ʶ"},
/* 45- 49*/	{"δ֪�Ĵ���ԭ��"},{"δ֪��Ӧ�÷������ݵ�Ԫ������ַ"},{"δ֪����Ϣ�����ַ"},{"δ֪ԭ��"},{"δ֪ԭ��"}
};

bool cp16time_desc(char* DrawStr,CP16Time2a* tm16)
{
	char			tmp[512] = {'\0'};
	string			szTemp;

	szTemp.assign("ʱ��: ");
	strcat(DrawStr,szTemp.c_str());

	sprintf(tmp,"%d��%d���� ",tm16->parts.ms/1000,tm16->parts.ms%1000);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());

    return true;
}

bool cp24time_desc(char* DrawStr,CP24Time2a* tm24)
{
	char			tmp[512] = {'\0'};
	string			szTemp;

	szTemp.assign("ʱ��: ");
	strcat(DrawStr,szTemp.c_str());

	if (tm24->parts.IV)
	{
		szTemp.assign("��Ч ");
		strcat(DrawStr,szTemp.c_str());
	}

	sprintf(tmp,"%d��%d��%d���� ",tm24->parts.min,tm24->parts.ms/1000,tm24->parts.ms%1000);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());

    return true;
}

bool cp32time_desc(char* DrawStr,CP32Time2a* tm32)
{
	char			tmp[512] = {'\0'};
	string			szTemp;

	szTemp.assign("ʱ��: ");
	strcat(DrawStr,szTemp.c_str());

	if (tm32->parts.IV)
	{
		szTemp.assign("��Ч ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (tm32->parts.su)
	{
		szTemp.assign("����ʱ ");
		strcat(DrawStr,szTemp.c_str());
	}

	sprintf(tmp,"%dʱ%d��%d��%d���� ",tm32->parts.hour,tm32->parts.min,tm32->parts.ms/1000,tm32->parts.ms%1000);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());

    return true;
}

bool cp56time_desc(char* DrawStr,CP56Time2a* tm56)
{
	char			tmp[512] = {'\0'};
	string			szTemp;

	szTemp.assign("ʱ��: ");
	strcat(DrawStr,szTemp.c_str());

	if (tm56->parts.IV)
	{
		szTemp.assign("��Ч ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (tm56->parts.su)
	{
		szTemp.assign("����ʱ ");
		strcat(DrawStr,szTemp.c_str());
	}

	sprintf(tmp,"%d��%d��%d��(����%d)%dʱ%d��%d��%d���� ",
			tm56->parts.year+2000,tm56->parts.month,tm56->parts.day,tm56->parts.week,
			tm56->parts.hour,tm56->parts.min,tm56->parts.ms/1000,tm56->parts.ms%1000);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());

    return true;
}

bool qds_desc(char* DrawStr,QDS* qds)
{
	string			szTemp;

	if (qds->parts.IV)
	{
		szTemp.assign("��Ч ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (qds->parts.NT)
	{
		szTemp.assign("�ǵ�ǰֵ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (qds->parts.SB)
	{
		szTemp.assign("���滻 ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (qds->parts.BL)
	{
		szTemp.assign("������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (qds->parts.OV)
	{
		szTemp.assign("������� ");
		strcat(DrawStr,szTemp.c_str());
	}

    return true;
}

bool qdp_desc(char* DrawStr,QDP* qdp)
{
	string			szTemp;

	if (qdp->parts.IV)
	{
		szTemp.assign("��Ч ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (qdp->parts.NT)
	{
		szTemp.assign("�ǵ�ǰֵ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (qdp->parts.SB)
	{
		szTemp.assign("���滻 ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (qdp->parts.BL)
	{
		szTemp.assign("������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (qdp->parts.EI)
	{
		szTemp.assign("����ʱ����Ч ");
		strcat(DrawStr,szTemp.c_str());
	}

	return true;
}

bool qpm_desc(char* DrawStr,QPM* qpm)
{
	string			szTemp;

	if (qpm->parts.LPC)
		szTemp.assign("�ı� ");
	else
		szTemp.assign("δ�ı� ");
	strcat(DrawStr,szTemp.c_str());

	if (qpm->parts.POP)
		szTemp.assign("δ���� ");
	else
		szTemp.assign("���� ");
	strcat(DrawStr,szTemp.c_str());

	if (qpm->parts.KPA == 1)
		szTemp.assign("����ֵ ");
	else if (qpm->parts.KPA == 2)
		szTemp.assign("ƽ��ϵͳ ");
	else if (qpm->parts.KPA == 2)
		szTemp.assign("���Ͳ���ֵ������ ");
	else if (qpm->parts.KPA == 2)
		szTemp.assign("���Ͳ���ֵ������ ");
	else
		szTemp.assign("ʹ�ñ��� ");
	strcat(DrawStr,szTemp.c_str());

	return true;
}

//------------------ δ֪���ʹ��� -------------------
bool INVALID_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;

	szTemp.assign("�������û������ݲ�����!");
	strcat(DrawStr,szTemp.c_str());

    return true;
}
//------------------ ������Ϣ���� -------------------
bool M_SP_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;
	M_SP_NA_1_t		m_sp_na;

	memcpy(&m_sp_na,udata,SizeOfType(typid));

	if (m_sp_na.siq.parts.IV)
	{
		szTemp.assign("��Ч ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_sp_na.siq.parts.NT)
	{
		szTemp.assign("�ǵ�ǰֵ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_sp_na.siq.parts.SB)
	{
		szTemp.assign("���滻 ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_sp_na.siq.parts.BL)
	{
		szTemp.assign("������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_sp_na.siq.parts.SPI)
	{
		szTemp.assign("״̬:�� ");
	}
	else
	{
		szTemp.assign("״̬:�� ");
	}
	strcat(DrawStr,szTemp.c_str());	

	return true;
}
//------------------ ��ʱ��ĵ�����Ϣ���� -------------------
bool M_SP_TA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;
	M_SP_TA_1_t		m_sp_ta;

	memcpy(&m_sp_ta,udata,SizeOfType(typid));

	if (m_sp_ta.siq.parts.IV)
	{
		szTemp.assign("��Ч ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_sp_ta.siq.parts.NT)
	{
		szTemp.assign("�ǵ�ǰֵ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_sp_ta.siq.parts.SB)
	{
		szTemp.assign("���滻 ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_sp_ta.siq.parts.BL)
	{
		szTemp.assign("������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_sp_ta.siq.parts.SPI)
	{
		szTemp.assign("״̬:�� ");
	}
	else
	{
		szTemp.assign("״̬:�� ");
	}
	strcat(DrawStr,szTemp.c_str());

	cp24time_desc(DrawStr,&m_sp_ta.tm);

	return true;
}
//------------------ ˫����Ϣ���� -------------------
bool M_DP_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;
	M_DP_NA_1_t		m_dp_na;

	memcpy(&m_dp_na,udata,SizeOfType(typid));

	if (m_dp_na.diq.parts.IV)
	{
		szTemp.assign("��Ч ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_dp_na.diq.parts.NT)
	{
		szTemp.assign("�ǵ�ǰֵ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_dp_na.diq.parts.SB)
	{
		szTemp.assign("���滻 ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_dp_na.diq.parts.BL)
	{
		szTemp.assign("������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_dp_na.diq.parts.DPI == 2)
	{
		szTemp.assign("״̬:�� ");
	}
	else if (m_dp_na.diq.parts.DPI == 1)
	{
		szTemp.assign("״̬:�� ");
	}
	else
	{
		szTemp.assign("״̬:��̬ ");
	}
	strcat(DrawStr,szTemp.c_str());	

	return true;
}
//------------------ ��ʱ���˫����Ϣ���� -------------------
bool M_DP_TA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;
	M_DP_TA_1_t		m_dp_ta;

	memcpy(&m_dp_ta,udata,SizeOfType(typid));

	if (m_dp_ta.diq.parts.IV)
	{
		szTemp.assign("��Ч ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_dp_ta.diq.parts.NT)
	{
		szTemp.assign("�ǵ�ǰֵ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_dp_ta.diq.parts.SB)
	{
		szTemp.assign("���滻 ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_dp_ta.diq.parts.BL)
	{
		szTemp.assign("������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_dp_ta.diq.parts.DPI == 2)
	{
		szTemp.assign("״̬:�� ");
	}
	else if (m_dp_ta.diq.parts.DPI == 1)
	{
		szTemp.assign("״̬:�� ");
	}
	else
	{
		szTemp.assign("״̬:��̬ ");
	}
	strcat(DrawStr,szTemp.c_str());
	
	cp24time_desc(DrawStr,&m_dp_ta.tm);

	return true;
}
//------------------ ��λ����Ϣ���� -------------------
bool M_ST_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	M_ST_NA_1_t		m_st_na;

	memcpy(&m_st_na,udata,SizeOfType(typid));

	if (m_st_na.vti.parts.transient)
	{
		szTemp.assign("�豸��˲��״̬ ");
		strcat(DrawStr,szTemp.c_str());
	}

	sprintf(tmp,"ֵ:%d ",m_st_na.vti.parts.value);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	
	qds_desc(DrawStr,&m_st_na.qds);

	return true;
}
//------------------ ��ʱ��Ĳ�λ����Ϣ���� -------------------
bool M_ST_TA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	M_ST_TA_1_t		m_st_ta;

	memcpy(&m_st_ta,udata,SizeOfType(typid));

	if (m_st_ta.vti.parts.transient)
	{
		szTemp.assign("�豸��˲��״̬ ");
		strcat(DrawStr,szTemp.c_str());
	}

	sprintf(tmp,"ֵ:%d ",m_st_ta.vti.parts.value);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	
	qds_desc(DrawStr,&m_st_ta.qds);

	cp24time_desc(DrawStr,&m_st_ta.tm);

	return true;
}
//------------------ 32���ش����� -------------------
bool M_BO_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	M_BO_NA_1_t		m_bo_na;

	memcpy(&m_bo_na,udata,SizeOfType(typid));

	sprintf(tmp,"ֵ:%d(%08XH) ",m_bo_na.bsi.bits,m_bo_na.bsi.bits);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	
	qds_desc(DrawStr,&m_bo_na.qds);

	return true;
}
//------------------ ��ʱ���32���ش����� -------------------
bool M_BO_TA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	M_BO_TA_1_t		m_bo_ta;

	memcpy(&m_bo_ta,udata,SizeOfType(typid));

	sprintf(tmp,"ֵ:%d(%08XH) ",m_bo_ta.bsi.bits,m_bo_ta.bsi.bits);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	
	qds_desc(DrawStr,&m_bo_ta.qds);

	cp24time_desc(DrawStr,&m_bo_ta.tm);

	return true;
}
//------------------ ����ֵ,��һ��ֵ���� -------------------
bool M_ME_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	M_ME_NA_1_t		m_me_na;

	memcpy(&m_me_na,udata,SizeOfType(typid));

	sprintf(tmp,"ֵ:%d ",m_me_na.nva.value);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	
	qds_desc(DrawStr,&m_me_na.qds);

	return true;
}
//------------------ ��ʱ��Ĳ���ֵ,��һ��ֵ���� -------------------
bool M_ME_TA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	M_ME_TA_1_t		m_me_ta;

	memcpy(&m_me_ta,udata,SizeOfType(typid));

	sprintf(tmp,"ֵ:%d ",m_me_ta.nva.value);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	
	qds_desc(DrawStr,&m_me_ta.qds);

	cp24time_desc(DrawStr,&m_me_ta.tm);

	return true;
}
//------------------ ����ֵ,��Ȼ�ֵ���� -------------------
bool M_ME_NB_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	M_ME_NB_1_t		m_me_nb;

	memcpy(&m_me_nb,udata,SizeOfType(typid));

	sprintf(tmp,"ֵ:%d ",m_me_nb.sva.bits);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	
	qds_desc(DrawStr,&m_me_nb.qds);

	return true;
}
//------------------ ��ʱ��Ĳ���ֵ,��Ȼ�ֵ���� -------------------
bool M_ME_TB_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	M_ME_TB_1_t		m_me_tb;

	memcpy(&m_me_tb,udata,SizeOfType(typid));

	sprintf(tmp,"ֵ:%d ",m_me_tb.sva.bits);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	
	qds_desc(DrawStr,&m_me_tb.qds);

	cp24time_desc(DrawStr,&m_me_tb.tm);

	return true;
}
//------------------ ����ֵ,�̸��������� -------------------
bool M_ME_NC_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	M_ME_NC_1_t		m_me_nc;

	memcpy(&m_me_nc,udata,SizeOfType(typid));

	sprintf(tmp,"ֵ:%f ",m_me_nc.std.f);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	
	qds_desc(DrawStr,&m_me_nc.qds);

	return true;
}
//------------------ ��ʱ��Ĳ���ֵ,�̸��������� -------------------
bool M_ME_TC_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	M_ME_TC_1_t		m_me_tc;

	memcpy(&m_me_tc,udata,SizeOfType(typid));

	sprintf(tmp,"ֵ:%f ",m_me_tc.std.f);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	
	qds_desc(DrawStr,&m_me_tc.qds);

	cp24time_desc(DrawStr,&m_me_tc.tm);

	return true;
}
//------------------ �ۼ������� -------------------
bool M_IT_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	M_IT_NA_1_t		m_it_na;

	memcpy(&m_it_na,udata,SizeOfType(typid));

	if (m_it_na.bcr.parts.IV)
	{
		szTemp.assign("��Ч ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_it_na.bcr.parts.CY)
	{
		szTemp.assign("��λ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_it_na.bcr.parts.CA)
	{
		szTemp.assign("������������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_it_na.bcr.parts.SQ)
	{
		szTemp.assign("˳��� ");
		strcat(DrawStr,szTemp.c_str());
	}
	sprintf(tmp,"ֵ:%d ",m_it_na.bcr.parts.counter);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());

	return true;
}
//------------------ ��ʱ����ۼ������� -------------------
bool M_IT_TA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	M_IT_TA_1_t		m_it_ta;

	memcpy(&m_it_ta,udata,SizeOfType(typid));

	if (m_it_ta.bcr.parts.IV)
	{
		szTemp.assign("��Ч ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_it_ta.bcr.parts.CY)
	{
		szTemp.assign("��λ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_it_ta.bcr.parts.CA)
	{
		szTemp.assign("������������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_it_ta.bcr.parts.SQ)
	{
		szTemp.assign("˳��� ");
		strcat(DrawStr,szTemp.c_str());
	}
	sprintf(tmp,"ֵ:%d ",m_it_ta.bcr.parts.counter);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());

	cp24time_desc(DrawStr,&m_it_ta.tm);

	return true;
}
//------------------ ��ʱ��ļ̵籣��װ���¼����� -------------------
bool M_EP_TA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;
	M_EP_TA_1_t		m_ep_ta;

	memcpy(&m_ep_ta,udata,SizeOfType(typid));

	if (m_ep_ta.sep.parts.IV)
	{
		szTemp.assign("��Ч ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_ta.sep.parts.NT)
	{
		szTemp.assign("�ǵ�ǰֵ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_ta.sep.parts.SB)
	{
		szTemp.assign("���滻 ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_ta.sep.parts.BL)
	{
		szTemp.assign("������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_ta.sep.parts.EI)
	{
		szTemp.assign("����ʱ����Ч ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_ta.sep.parts.ES == 2)
	{
		szTemp.assign("״̬:�� ");
	}
	else if (m_ep_ta.sep.parts.ES == 1)
	{
		szTemp.assign("״̬:�� ");
	}
	else
	{
		szTemp.assign("״̬:��̬ ");
	}
	strcat(DrawStr,szTemp.c_str());

	szTemp.assign("����");
	strcat(DrawStr,szTemp.c_str());
	cp16time_desc(DrawStr,&m_ep_ta.tm16);

	cp24time_desc(DrawStr,&m_ep_ta.tm24);

	return true;
}
//------------------ ��ʱ��ļ̵籣��װ�ó��������¼����� -------------------
bool M_EP_TB_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;
	M_EP_TB_1_t		m_ep_tb;

	memcpy(&m_ep_tb,udata,SizeOfType(typid));

	if (m_ep_tb.spe.parts.GS)
	{
		szTemp.assign("������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_tb.spe.parts.SL1)
	{
		szTemp.assign("A�ౣ������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_tb.spe.parts.SL2)
	{
		szTemp.assign("B�ౣ������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_tb.spe.parts.SL3)
	{
		szTemp.assign("C�ౣ������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_tb.spe.parts.SIE)
	{
		szTemp.assign("�ӵص����������� ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_tb.spe.parts.SRD)
	{
		szTemp.assign("���򱣻����� ");
		strcat(DrawStr,szTemp.c_str());
	}

	qdp_desc(DrawStr,&m_ep_tb.qdp);

	szTemp.assign("�̵�����������");
	strcat(DrawStr,szTemp.c_str());
	cp16time_desc(DrawStr,&m_ep_tb.tm16);

	cp24time_desc(DrawStr,&m_ep_tb.tm24);

	return true;
}
//------------------ ��ʱ��ļ̵籣��װ�ó��������·��Ϣ���� -------------------
bool M_EP_TC_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;
	M_EP_TC_1_t		m_ep_tc;

	memcpy(&m_ep_tc,udata,SizeOfType(typid));

	if (m_ep_tc.oci.parts.GC)
	{
		szTemp.assign("����������������· ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_tc.oci.parts.CL1)
	{
		szTemp.assign("���������A�������· ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_tc.oci.parts.CL2)
	{
		szTemp.assign("���������B�������· ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_tc.oci.parts.CL3)
	{
		szTemp.assign("���������C�������· ");
		strcat(DrawStr,szTemp.c_str());
	}
	
	qdp_desc(DrawStr,&m_ep_tc.qdp);

	szTemp.assign("�̵�������");
	strcat(DrawStr,szTemp.c_str());
	cp16time_desc(DrawStr,&m_ep_tc.tm16);

	cp24time_desc(DrawStr,&m_ep_tc.tm24);

	return true;
}
//------------------ ����λ����ĳ��鵥����Ϣ���� -------------------
bool M_PS_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	M_PS_NA_1_t		m_ps_na;
	int				i,j;

	memcpy(&m_ps_na,udata,SizeOfType(typid));

	for (i = 1,j = 0; i <= 16; i++,j++)
	{
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"λ%02d״̬:%d ",j,(m_ps_na.scd.parts.ST >> j) & 0x01);
		szTemp.assign(tmp);
		strcat(DrawStr,szTemp.c_str());
		if (!(i % 8))
			strcat(DrawStr,"\r\n");
	}

	for (i = 1,j = 0; i <= 16; i++,j++)
	{
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"λ%02d���:%d ",j,(m_ps_na.scd.parts.CD >> j) & 0x01);
		szTemp.assign(tmp);
		strcat(DrawStr,szTemp.c_str());
		if (!(i % 8))
			strcat(DrawStr,"\r\n");
	}
	
	qds_desc(DrawStr,&m_ps_na.qds);

	return true;
}
//------------------ ����ֵ,����Ʒ�������ʵĹ�һ��ֵ���� -------------------
bool M_ME_ND_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	M_ME_ND_1_t		m_me_nd;

	memcpy(&m_me_nd,udata,SizeOfType(typid));

	sprintf(tmp,"ֵ:%d ",m_me_nd.nva.value);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());

	return true;
}
//------------------ ��CP56Time2aʱ��ĵ�����Ϣ���� -------------------
bool M_SP_TB_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;
	M_SP_TB_1_t		m_sp_tb;

	memcpy(&m_sp_tb,udata,SizeOfType(typid));

	if (m_sp_tb.siq.parts.IV)
	{
		szTemp.assign("��Ч ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_sp_tb.siq.parts.NT)
	{
		szTemp.assign("�ǵ�ǰֵ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_sp_tb.siq.parts.SB)
	{
		szTemp.assign("���滻 ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_sp_tb.siq.parts.BL)
	{
		szTemp.assign("������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_sp_tb.siq.parts.SPI)
	{
		szTemp.assign("״̬:�� ");
	}
	else
	{
		szTemp.assign("״̬:�� ");
	}
	strcat(DrawStr,szTemp.c_str());

	cp56time_desc(DrawStr,&m_sp_tb.tm);

	return true;
}
//------------------ ��CP56Time2aʱ���˫����Ϣ���� -------------------
bool M_DP_TB_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;
	M_DP_TB_1_t		m_dp_tb;

	memcpy(&m_dp_tb,udata,SizeOfType(typid));

	if (m_dp_tb.diq.parts.IV)
	{
		szTemp.assign("��Ч ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_dp_tb.diq.parts.NT)
	{
		szTemp.assign("�ǵ�ǰֵ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_dp_tb.diq.parts.SB)
	{
		szTemp.assign("���滻 ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_dp_tb.diq.parts.BL)
	{
		szTemp.assign("������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_dp_tb.diq.parts.DPI == 2)
	{
		szTemp.assign("״̬:�� ");
	}
	else if (m_dp_tb.diq.parts.DPI == 1)
	{
		szTemp.assign("״̬:�� ");
	}
	else
	{
		szTemp.assign("״̬:��̬ ");
	}
	strcat(DrawStr,szTemp.c_str());	

	cp56time_desc(DrawStr,&m_dp_tb.tm);

	return true;
}
//------------------ ��CP56Time2aʱ��Ĳ�λ����Ϣ���� -------------------
bool M_ST_TB_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	M_ST_TB_1_t		m_st_tb;

	memcpy(&m_st_tb,udata,SizeOfType(typid));

	if (m_st_tb.vti.parts.transient)
	{
		szTemp.assign("�豸��˲��״̬ ");
		strcat(DrawStr,szTemp.c_str());
	}

	sprintf(tmp,"ֵ:%d ",m_st_tb.vti.parts.value);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	
	qds_desc(DrawStr,&m_st_tb.qds);

	cp56time_desc(DrawStr,&m_st_tb.tm);

	return true;
}
//------------------ ��CP56Time2aʱ���32���ش����� -------------------
bool M_BO_TB_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	M_BO_TB_1_t		m_bo_tb;

	memcpy(&m_bo_tb,udata,SizeOfType(typid));

	sprintf(tmp,"ֵ:%d(%08XH) ",m_bo_tb.bsi.bits,m_bo_tb.bsi.bits);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	
	qds_desc(DrawStr,&m_bo_tb.qds);

	cp56time_desc(DrawStr,&m_bo_tb.tm);

	return true;
}
//------------------ ��CP56Time2aʱ��Ĳ���ֵ,��һ��ֵ���� -------------------
bool M_ME_TD_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	M_ME_TD_1_t		m_me_td;

	memcpy(&m_me_td,udata,SizeOfType(typid));

	sprintf(tmp,"ֵ:%d ",m_me_td.nva.value);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	
	qds_desc(DrawStr,&m_me_td.qds);

	cp56time_desc(DrawStr,&m_me_td.tm);

	return true;
}
//------------------ ��CP56Time2aʱ��Ĳ���ֵ,��Ȼ�ֵ���� -------------------
bool M_ME_TE_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	M_ME_TE_1_t		m_me_te;

	memcpy(&m_me_te,udata,SizeOfType(typid));

	sprintf(tmp,"ֵ:%d ",m_me_te.sva.bits);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	
	qds_desc(DrawStr,&m_me_te.qds);

	cp56time_desc(DrawStr,&m_me_te.tm);

	return true;
}
//------------------ ��CP56Time2aʱ��Ĳ���ֵ,�̸��������� -------------------
bool M_ME_TF_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	M_ME_TF_1_t		m_me_tf;

	memcpy(&m_me_tf,udata,SizeOfType(typid));

	sprintf(tmp,"ֵ:%f ",m_me_tf.std.f);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	
	qds_desc(DrawStr,&m_me_tf.qds);

	cp56time_desc(DrawStr,&m_me_tf.tm);

	return true;
}
//------------------ ��CP56Time2aʱ����ۼ������� -------------------
bool M_IT_TB_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	M_IT_TB_1_t		m_it_tb;

	memcpy(&m_it_tb,udata,SizeOfType(typid));

	if (m_it_tb.bcr.parts.IV)
	{
		szTemp.assign("��Ч ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_it_tb.bcr.parts.CY)
	{
		szTemp.assign("��λ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_it_tb.bcr.parts.CA)
	{
		szTemp.assign("������������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_it_tb.bcr.parts.SQ)
	{
		szTemp.assign("˳��� ");
		strcat(DrawStr,szTemp.c_str());
	}
	sprintf(tmp,"ֵ:%d ",m_it_tb.bcr.parts.counter);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());

	cp56time_desc(DrawStr,&m_it_tb.tm);

	return true;
}
//------------------ ��CP56Time2aʱ��ļ̵籣��װ���¼����� -------------------
bool M_EP_TD_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;
	M_EP_TD_1_t		m_ep_td;

	memcpy(&m_ep_td,udata,SizeOfType(typid));

	if (m_ep_td.sep.parts.IV)
	{
		szTemp.assign("��Ч ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_td.sep.parts.NT)
	{
		szTemp.assign("�ǵ�ǰֵ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_td.sep.parts.SB)
	{
		szTemp.assign("���滻 ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_td.sep.parts.BL)
	{
		szTemp.assign("������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_td.sep.parts.EI)
	{
		szTemp.assign("����ʱ����Ч ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_td.sep.parts.ES == 2)
	{
		szTemp.assign("״̬:�� ");
	}
	else if (m_ep_td.sep.parts.ES == 1)
	{
		szTemp.assign("״̬:�� ");
	}
	else
	{
		szTemp.assign("״̬:��̬ ");
	}
	strcat(DrawStr,szTemp.c_str());

	szTemp.assign("����");
	strcat(DrawStr,szTemp.c_str());
	cp16time_desc(DrawStr,&m_ep_td.tm16);

	cp56time_desc(DrawStr,&m_ep_td.tm56);

	return true;
}
//------------------ ��CP56Time2aʱ��ļ̵籣��װ�ó��������¼����� -------------------
bool M_EP_TE_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;
	M_EP_TE_1_t		m_ep_te;

	memcpy(&m_ep_te,udata,SizeOfType(typid));

	if (m_ep_te.spe.parts.GS)
	{
		szTemp.assign("������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_te.spe.parts.SL1)
	{
		szTemp.assign("A�ౣ������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_te.spe.parts.SL2)
	{
		szTemp.assign("B�ౣ������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_te.spe.parts.SL3)
	{
		szTemp.assign("C�ౣ������ ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_te.spe.parts.SIE)
	{
		szTemp.assign("�ӵص����������� ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_te.spe.parts.SRD)
	{
		szTemp.assign("���򱣻����� ");
		strcat(DrawStr,szTemp.c_str());
	}

	qdp_desc(DrawStr,&m_ep_te.qdp);

	szTemp.assign("�̵�����������");
	strcat(DrawStr,szTemp.c_str());
	cp16time_desc(DrawStr,&m_ep_te.tm16);

	cp56time_desc(DrawStr,&m_ep_te.tm56);

	return true;
}
//------------------ ��CP56Time2aʱ��ļ̵籣��װ�ó��������·��Ϣ���� -------------------
bool M_EP_TF_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;
	M_EP_TF_1_t		m_ep_tf;

	memcpy(&m_ep_tf,udata,SizeOfType(typid));

	if (m_ep_tf.oci.parts.GC)
	{
		szTemp.assign("����������������· ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_tf.oci.parts.CL1)
	{
		szTemp.assign("���������A�������· ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_tf.oci.parts.CL2)
	{
		szTemp.assign("���������B�������· ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (m_ep_tf.oci.parts.CL3)
	{
		szTemp.assign("���������C�������· ");
		strcat(DrawStr,szTemp.c_str());
	}
	
	qdp_desc(DrawStr,&m_ep_tf.qdp);

	szTemp.assign("�̵�������");
	strcat(DrawStr,szTemp.c_str());
	cp16time_desc(DrawStr,&m_ep_tf.tm16);

	cp56time_desc(DrawStr,&m_ep_tf.tm56);

	return true;
}
//------------------ ��������� -------------------
bool C_SC_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;
	C_SC_NA_1_t		c_sc_na;

	memcpy(&c_sc_na,udata,SizeOfType(typid));

	if (c_sc_na.sco.parts.QU == 1)
		szTemp.assign("���������ʱ�� ");
	else if (c_sc_na.sco.parts.QU == 2)
		szTemp.assign("���������ʱ�� ");
	else if (c_sc_na.sco.parts.QU == 2)
		szTemp.assign("������� ");
	strcat(DrawStr,szTemp.c_str());

	if (c_sc_na.sco.parts.SE)
		szTemp.assign("ѡ�� ");
	else 
		szTemp.assign("ִ�� ");
	strcat(DrawStr,szTemp.c_str());
	
	if (c_sc_na.sco.parts.SCS)
		szTemp.assign("ң��:�� ");
	else 
		szTemp.assign("ң��:�� ");
	strcat(DrawStr,szTemp.c_str());

	return true;
}
//------------------ ˫������� -------------------
bool C_DC_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;
	C_DC_NA_1_t		c_dc_na;

	memcpy(&c_dc_na,udata,SizeOfType(typid));

	if (c_dc_na.dco.parts.QU == 1)
		szTemp.assign("���������ʱ�� ");
	else if (c_dc_na.dco.parts.QU == 2)
		szTemp.assign("���������ʱ�� ");
	else if (c_dc_na.dco.parts.QU == 2)
		szTemp.assign("������� ");
	strcat(DrawStr,szTemp.c_str());

	if (c_dc_na.dco.parts.SE)
		szTemp.assign("ѡ�� ");
	else 
		szTemp.assign("ִ�� ");
	strcat(DrawStr,szTemp.c_str());
	
	if (c_dc_na.dco.parts.DCS == 2)
		szTemp.assign("ң��:�� ");
	else if (c_dc_na.dco.parts.DCS == 1)
		szTemp.assign("ң��:�� ");
	else
		szTemp.assign("ң��:������ ");
	strcat(DrawStr,szTemp.c_str());

	return true;
}
//------------------ ���ڲ������ -------------------
bool C_RC_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;
	C_RC_NA_1_t		c_rc_na;

	memcpy(&c_rc_na,udata,SizeOfType(typid));

	if (c_rc_na.rco.parts.QU == 1)
		szTemp.assign("���������ʱ�� ");
	else if (c_rc_na.rco.parts.QU == 2)
		szTemp.assign("���������ʱ�� ");
	else if (c_rc_na.rco.parts.QU == 2)
		szTemp.assign("������� ");
	strcat(DrawStr,szTemp.c_str());

	if (c_rc_na.rco.parts.SE)
		szTemp.assign("ѡ�� ");
	else 
		szTemp.assign("ִ�� ");
	strcat(DrawStr,szTemp.c_str());
	
	if (c_rc_na.rco.parts.RCS == 2)
		szTemp.assign("������:��һ�� ");
	else if (c_rc_na.rco.parts.RCS == 1)
		szTemp.assign("������:��һ�� ");
	else
		szTemp.assign("������:������ ");
	strcat(DrawStr,szTemp.c_str());

	return true;
}
//------------------ �趨ֵ����,��һ��ֵ���� -------------------
bool C_SE_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	C_SE_NA_1_t		c_se_na;

	memcpy(&c_se_na,udata,SizeOfType(typid));

	if (c_se_na.qos.parts.SE)
		szTemp.assign("ѡ�� ");
	else 
		szTemp.assign("ִ�� ");
	strcat(DrawStr,szTemp.c_str());
	
	sprintf(tmp,"��ֵ:%d ",c_se_na.nva.value);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());

	return true;
}
//------------------ �趨ֵ����,��Ȼ�ֵ���� -------------------
bool C_SE_NB_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	C_SE_NB_1_t		c_se_nb;

	memcpy(&c_se_nb,udata,SizeOfType(typid));

	if (c_se_nb.qos.parts.SE)
		szTemp.assign("ѡ�� ");
	else 
		szTemp.assign("ִ�� ");
	strcat(DrawStr,szTemp.c_str());
	
	sprintf(tmp,"��ֵ:%d ",c_se_nb.sva.bits);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());

	return true;
}
//------------------ �趨ֵ����̸��������� -------------------
bool C_SE_NC_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	C_SE_NC_1_t		c_se_nc;

	memcpy(&c_se_nc,udata,SizeOfType(typid));

	if (c_se_nc.qos.parts.SE)
		szTemp.assign("ѡ�� ");
	else 
		szTemp.assign("ִ�� ");
	strcat(DrawStr,szTemp.c_str());
	
	sprintf(tmp,"��ֵ:%f",c_se_nc.std.f);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());

	return true;
}
//------------------ �趨ֵ����,32���ش����� -------------------
bool C_BO_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	C_BO_NA_1_t		c_bo_na;

	memcpy(&c_bo_na,udata,SizeOfType(typid));
	
	sprintf(tmp,"��ֵ:%d(%08XH) ",c_bo_na.bsi.bits,c_bo_na.bsi.bits);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());

	return true;
}
//------------------ ��ʼ���������� -------------------
bool M_EI_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;
	M_EI_NA_1_t		m_ei_na;

	memcpy(&m_ei_na,udata,SizeOfType(typid));
	
	if (m_ei_na.coi.parts.cause == 0)
		szTemp.assign("���ص�Դ���� ");
	else if (m_ei_na.coi.parts.cause == 1)
		szTemp.assign("�����ֶ���λ ");
	else if (m_ei_na.coi.parts.cause == 2)
		szTemp.assign("Զ����λ ");
	strcat(DrawStr,szTemp.c_str());

	if (m_ei_na.coi.parts.state)
		szTemp.assign("�ı䵱�ز�����ĳ�ʼ�� ");
	else
		szTemp.assign("δ�ı䵱�ز�����ĳ�ʼ�� ");
	strcat(DrawStr,szTemp.c_str());

	return true;
}
//------------------ ���ٻ������ -------------------
bool C_IC_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	C_IC_NA_1_t		c_ic_na;

	memcpy(&c_ic_na,udata,SizeOfType(typid));
	
	if (c_ic_na.qoi.qoi >= 20 && c_ic_na.qoi.qoi <= 36)
	{
		if (c_ic_na.qoi.qoi == 20)
			szTemp.assign("վ�ٻ�(ȫ��) ");
		else
		{
			sprintf(tmp,"��%d���ٻ� ",c_ic_na.qoi.qoi);
			szTemp.assign(tmp);
		}
	}
	else
		szTemp.assign("ʹ�ñ��� ");
	strcat(DrawStr,szTemp.c_str());

	return true;
}
//------------------ �ۼ����ٻ������ -------------------
bool C_CI_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	C_CI_NA_1_t		c_ci_na;

	memcpy(&c_ci_na,udata,SizeOfType(typid));
	
	if (c_ci_na.qcc.parts.RQT > 0 && c_ci_na.qcc.parts.RQT <= 5)
	{
		if (c_ci_na.qcc.parts.RQT == 5)
			szTemp.assign("�ܵ���������� ");
		else
		{
			sprintf(tmp,"�����������%d�� ",c_ci_na.qcc.parts.RQT);
			szTemp.assign(tmp);
		}
	}
	else
		szTemp.assign("ʹ�ñ��� ");
	strcat(DrawStr,szTemp.c_str());

	if (c_ci_na.qcc.parts.FRZ == 0)
		szTemp.assign("�� ");
	else if (c_ci_na.qcc.parts.FRZ == 1)
		szTemp.assign("���������᲻����λ ");
	else if (c_ci_na.qcc.parts.FRZ == 2)
		szTemp.assign("�������������λ ");
	else if (c_ci_na.qcc.parts.FRZ == 3)
		szTemp.assign("��������λ ");
	strcat(DrawStr,szTemp.c_str());

	return true;
}
//------------------ ʱ��ͬ������� -------------------
bool C_CS_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;
	C_CS_NA_1_t		c_cs_na;

	memcpy(&c_cs_na,udata,SizeOfType(typid));
	
	cp56time_desc(DrawStr,&c_cs_na.tm);

	return true;
}
//------------------ ��������� -------------------
bool C_TS_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	C_TS_NA_1_t		c_ts_na;

	memcpy(&c_ts_na,udata,SizeOfType(typid));
	
	sprintf(tmp,"�̶�������: %4XH ",c_ts_na.fbp.HEX);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());

	return true;
}
//------------------ ��λ��������� -------------------
bool C_RP_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;
	C_RP_NA_1_t		c_rp_na;

	memcpy(&c_rp_na,udata,SizeOfType(typid));
	
	if (c_rp_na.qrp.qrp == 1)
		szTemp.assign("�����ܸ�λ ");
	else if (c_rp_na.qrp.qrp == 2)
		szTemp.assign("��λ�¼��������ȴ�����Ĵ�ʱ�����Ϣ ");
	else 
		szTemp.assign("ʹ�ñ��� ");
	strcat(DrawStr,szTemp.c_str());

	return true;
}
//------------------ �ռ�������ʱ���� -------------------
bool C_CD_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;
	C_CD_NA_1_t		c_cd_na;

	memcpy(&c_cd_na,udata,SizeOfType(typid));
	
	cp16time_desc(DrawStr,&c_cd_na.tm);

	return true;
}
//------------------ ����ֵ����,��һ��ֵ���� -------------------
bool P_ME_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	P_ME_NA_1_t		p_me_na;

	memcpy(&p_me_na,udata,SizeOfType(typid));

	qpm_desc(DrawStr,&p_me_na.qpm);

	sprintf(tmp,"ֵ:%d ",p_me_na.nva.value);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());

	return true;
}
//------------------ ����ֵ����,��Ȼ�ֵ���� -------------------
bool P_ME_NB_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	P_ME_NB_1_t		p_me_nb;

	memcpy(&p_me_nb,udata,SizeOfType(typid));

	qpm_desc(DrawStr,&p_me_nb.qpm);

	sprintf(tmp,"ֵ:%d ",p_me_nb.sva.bits);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());

	return true;
}
//------------------ ����ֵ����,�̸��������� -------------------
bool P_ME_NC_desc(char* DrawStr,unsigned char typid,char* udata)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	P_ME_NC_1_t		p_me_nc;

	memcpy(&p_me_nc,udata,SizeOfType(typid));

	qpm_desc(DrawStr,&p_me_nc.qpm);

	sprintf(tmp,"ֵ:%f ",p_me_nc.std.f);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());

	return true;
}
//------------------ ��������� -------------------
bool P_AC_NA_desc(char* DrawStr,unsigned char typid,char* udata)
{
	string			szTemp;
	P_AC_NA_1_t		p_ac_na;

	memcpy(&p_ac_na,udata,SizeOfType(typid));

	if (p_ac_na.qpa.qpa == 1)
		szTemp.assign("����/ֹͣ������֮ǰװ�صĲ��� ");
	else if (p_ac_na.qpa.qpa == 2)
		szTemp.assign("����/ֹͣ������Ѱַ��Ϣ����Ĳ��� ");
	else if (p_ac_na.qpa.qpa == 3)
		szTemp.assign("����/ֹͣ������Ѱַ�ĳ���ѭ�������ڴ������Ϣ���� ");
	else
		szTemp.assign("ʹ�ñ��� ");
	strcat(DrawStr,szTemp.c_str());

	return true;
}
//------------------ �������ͼ� -------------------
typedef bool (*USER_DATA_DESC)(char*,unsigned char,char*);
bool DescUserData(char* DrawStr,unsigned char typid,char* udata)
{
    static USER_DATA_DESC desc_handler[256] = {
        INVALID_desc, M_SP_NA_desc, M_SP_TA_desc, M_DP_NA_desc, M_DP_TA_desc,  /* 0 - 4 */
        M_ST_NA_desc, M_ST_TA_desc, M_BO_NA_desc, M_BO_TA_desc, M_ME_NA_desc,  /* 5 - 9 */
        M_ME_TA_desc, M_ME_NB_desc, M_ME_TB_desc, M_ME_NC_desc, M_ME_TC_desc,  /* 10 - 14 */
        M_IT_NA_desc, M_IT_TA_desc, M_EP_TA_desc, M_EP_TB_desc, M_EP_TC_desc,  /* 15 - 19 */
        M_PS_NA_desc, M_ME_ND_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 20 - 24 */
        INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 25 - 29 */
        M_SP_TB_desc, M_DP_TB_desc, M_ST_TB_desc, M_BO_TB_desc, M_ME_TD_desc,  /* 30 - 34 */
        M_ME_TE_desc, M_ME_TF_desc, M_IT_TB_desc, M_EP_TD_desc, M_EP_TE_desc,  /* 35 - 39 */
        M_EP_TF_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 40 - 44 */
        C_SC_NA_desc, C_DC_NA_desc, C_RC_NA_desc, C_SE_NA_desc, C_SE_NB_desc,  /* 45 - 49 */
        C_SE_NC_desc, C_BO_NA_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 50 - 54 */
        INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 55 - 59 */
        INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 60 - 64 */
        INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 65 - 69 */
        M_EI_NA_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 70 - 74 */
        INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 75 - 79 */
        INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 80 - 84 */
        INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 85 - 89 */
        INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 90 - 94 */
        INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 95 - 99 */
        C_IC_NA_desc, C_CI_NA_desc, INVALID_desc, C_CS_NA_desc, C_TS_NA_desc,  /* 100 - 104 */
        C_RP_NA_desc, C_CD_NA_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 105 - 109 */
        P_ME_NA_desc, P_ME_NB_desc, P_ME_NC_desc, P_AC_NA_desc, INVALID_desc,  /* 110 - 114 */
        INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 115 - 119 */
        INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 120 - 124 */															   
        INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 125 - 129 */
        INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 130 - 134 */
        INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 135 - 139 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 140 - 144 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 145 - 149 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 150 - 154 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 155 - 159 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 160 - 164 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 165 - 169 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 170 - 174 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 175 - 179 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 180 - 184 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 185 - 189 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 190 - 194 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 195 - 199 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 200 - 204 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 205 - 209 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 210 - 214 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 215 - 219 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 220 - 224 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 225 - 229 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 230 - 234 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 235 - 239 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 240 - 244 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 245 - 249 */
		INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc, INVALID_desc,  /* 250 - 254 */
		INVALID_desc														   /* 255 -     */
    };

    return desc_handler[typid](DrawStr,typid,udata);
}

size_t SizeOfType(unsigned char typid)
{
    static size_t typesize[256] = {
                          0, sizeof(M_SP_NA_1_t), sizeof(M_SP_TA_1_t), sizeof(M_DP_NA_1_t), sizeof(M_DP_TA_1_t),        /* 0 - 4 */
        sizeof(M_ST_NA_1_t), sizeof(M_ST_TA_1_t), sizeof(M_BO_NA_1_t), sizeof(M_BO_TA_1_t), sizeof(M_ME_NA_1_t),        /* 5 - 9 */
        sizeof(M_ME_TA_1_t), sizeof(M_ME_NB_1_t), sizeof(M_ME_TB_1_t), sizeof(M_ME_NC_1_t), sizeof(M_ME_TC_1_t),        /* 10 - 14 */
        sizeof(M_IT_NA_1_t), sizeof(M_IT_TA_1_t), sizeof(M_EP_TA_1_t), sizeof(M_EP_TB_1_t), sizeof(M_EP_TC_1_t),        /* 15 - 19 */
        sizeof(M_PS_NA_1_t), sizeof(M_ME_ND_1_t),                   0,                   0,                   0,        /* 20 - 24 */
                          0,                   0,                   0,                   0,                   0,        /* 25 - 29 */
        sizeof(M_SP_TB_1_t), sizeof(M_DP_TB_1_t), sizeof(M_ST_TB_1_t), sizeof(M_BO_TB_1_t), sizeof(M_ME_TD_1_t),        /* 30 - 34 */
        sizeof(M_ME_TE_1_t), sizeof(M_ME_TF_1_t), sizeof(M_IT_TB_1_t), sizeof(M_EP_TD_1_t), sizeof(M_EP_TE_1_t),        /* 35 - 39 */
        sizeof(M_EP_TF_1_t),                   0,                   0,                   0,                   0,        /* 40 - 44 */
        sizeof(C_SC_NA_1_t), sizeof(C_DC_NA_1_t), sizeof(C_RC_NA_1_t), sizeof(C_SE_NA_1_t), sizeof(C_SE_NB_1_t),        /* 45 - 49 */
        sizeof(C_SE_NC_1_t), sizeof(C_BO_NA_1_t),                   0,                   0,                   0,        /* 50 - 54 */
                          0,                   0,                   0,					 0,					  0,        /* 55 - 59 */
						  0,				   0,					0,					 0,					  0,        /* 60 - 64 */
                          0,                   0,                   0,                   0,                   0,        /* 65 - 69 */
        sizeof(M_EI_NA_1_t),                   0,                   0,                   0,                   0,        /* 70 - 74 */
                          0,                   0,                   0,                   0,                   0,        /* 75 - 79 */
                          0,                   0,                   0,                   0,                   0,        /* 80 - 84 */
                          0,                   0,                   0,                   0,                   0,        /* 85 - 89 */
                          0,                   0,                   0,                   0,                   0,        /* 90 - 94 */
                          0,                   0,                   0,                   0,                   0,        /* 95 - 99 */
        sizeof(C_IC_NA_1_t), sizeof(C_CI_NA_1_t),                   0, sizeof(C_CS_NA_1_t), sizeof(C_TS_NA_1_t),        /* 100 - 104 */
        sizeof(C_RP_NA_1_t), sizeof(C_CD_NA_1_t),					0,                   0,                   0,        /* 105 - 109 */
        sizeof(P_ME_NA_1_t), sizeof(P_ME_NB_1_t), sizeof(P_ME_NC_1_t), sizeof(P_AC_NA_1_t),                   0,        /* 110 - 114 */
                          0,                   0,                   0,                   0,                   0,        /* 115 - 119 */
						  0,				   0,					0,					 0,					  0,        /* 120 - 124 */
						  0,				   0,                   0,					 0,					  0,		/* 125 - 129 */
						  0,				   0,                   0,					 0,					  0,		/* 130 - 134 */
						  0,				   0,                   0,					 0,					  0,		/* 135 - 139 */
						  0,				   0,                   0,					 0,					  0,		/* 140 - 144 */
						  0,				   0,                   0,					 0,					  0,		/* 145 - 149 */
						  0,				   0,                   0,					 0,					  0,		/* 150 - 154 */
						  0,				   0,                   0,					 0,					  0,		/* 155 - 159 */
						  0,				   0,                   0,					 0,					  0,		/* 160 - 164 */
						  0,				   0,                   0,					 0,					  0,		/* 165 - 169 */
						  0,				   0,                   0,					 0,					  0,		/* 170 - 174 */
						  0,				   0,                   0,					 0,					  0,		/* 175 - 179 */
						  0,				   0,                   0,					 0,					  0,		/* 180 - 184 */
						  0,				   0,                   0,					 0,					  0,		/* 185 - 189 */
						  0,				   0,                   0,					 0,					  0,		/* 190 - 194 */
						  0,				   0,                   0,					 0,					  0,		/* 195 - 199 */
						  0,				   0,                   0,					 0,					  0,		/* 200 - 204 */
						  0,				   0,                   0,					 0,					  0,		/* 205 - 209 */
						  0,				   0,                   0,					 0,					  0,		/* 210 - 214 */
						  0,				   0,                   0,					 0,					  0,		/* 215 - 219 */
						  0,				   0,                   0,					 0,					  0,		/* 220 - 224 */
						  0,				   0,                   0,					 0,					  0,		/* 225 - 229 */
						  0,				   0,                   0,					 0,					  0,		/* 230 - 234 */
						  0,				   0,                   0,					 0,					  0,		/* 235 - 239 */
						  0,				   0,                   0,					 0,					  0,		/* 240 - 244 */
						  0,				   0,                   0,					 0,					  0,		/* 245 - 249 */
						  0,				   0,                   0,					 0,					  0,		/* 250 - 254 */
						  0																								/* 255 -     */

    };																												   

    return typesize[typid];
}
