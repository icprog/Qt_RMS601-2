#include "AnalyzeGW103.h"

char descType[256][128] = {
	/*  0-  4*/	{"δ֪����"},{"�쳣�澯/�Լ�/��������λ/ѹ��״̬��λ/ͨѶ״̬��λ,����FUN/INF�ж�"},{"���������¼���Ϣ"},{"δ֪����"},{"���ϲ��ֵ"},
	/*  5-  9*/	{"δ֪����"},{"ʱ��ͬ��"},{"���ٻ�"},{"���ٻ�����"},{"δ֪����"},
	/* 10- 14*/	{"ͨ�÷�������"},{"δ֪����"},{"��Ҫ¼������"},{"�ٻ�¼���ļ�"},{"����¼���ļ�"},
	/* 15- 19*/	{"�ٻ�¼���ļ��б�"},{"����¼���ļ��б�"},{"�ٻ�װ�ù�����ʷ��Ϣ"},{"����װ�ù�����ʷ��Ϣ"},{"δ֪����"},
	/* 20- 24*/	{"δ֪����"},{"ͨ�÷�������"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
	/* 25- 29*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
	/* 30- 34*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
	/* 35- 39*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
	/* 40- 44*/	{"δ֪����"},{"δ֪����"},{"���ٻ�Ӧ��,����˫����Ϣ"},{"δ֪����"},{"δ֪����"},
	/* 45- 49*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
	/* 50- 54*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
	/* 55- 59*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
	/* 60- 64*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
	/* 65- 69*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
	/* 70- 74*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
	/* 75- 79*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
	/* 80- 84*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
	/* 85- 89*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
	/* 90- 94*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
	/* 95- 99*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
	/*100-104*/	{"δ֪����"},{"�ٻ�һ���ļ��б�"},{"����һ���ļ��б�"},{"�ٻ�һ���ļ�"},{"����һ���ļ�"},
	/*105-109*/	{"�´�һ���ļ���Ϣ"},{"�´��ļ���Ϣȷ��"},{"�´�һ���ļ�����"},{"�´��ļ�����ȷ��"},{"δ֪����"},
	/*110-114*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
	/*115-119*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
	/*120-124*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
	/*125-129*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
	/*130-134*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
	/*135-139*/	{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},{"δ֪����"},
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

char descCause[50][64] = {
	/*  0-  4*/	{"δ֪ԭ��"},{"ͻ��"},{"ѭ��"},{"��λ֡����λ"},{"��λͨѶ��Ԫ"},
	/*  5-  9*/	{"����/��������"},{"��Դ����"},{"����ģʽ"},{"ʱ��ͬ��"},{"���ٻ�"},
	/* 10- 14*/	{"���ٻ���ֹ"},{"���ز���"},{"Զ������"},{"δ֪ԭ��"},{"δ֪ԭ��"},
	/* 15- 19*/	{"δ֪ԭ��"},{"δ֪ԭ��"},{"δ֪ԭ��"},{"δ֪ԭ��"},{"δ֪ԭ��"},
	/* 20- 24*/	{"һ������/����϶��Ͽ�"},{"������Ͽ�"},{"δ֪ԭ��"},{"δ֪ԭ��"},{"δ֪ԭ��"},
	/* 25- 29*/	{"δ֪ԭ��"},{"δ֪ԭ��"},{"δ֪ԭ��"},{"δ֪ԭ��"},{"δ֪ԭ��"},
	/* 30- 34*/	{"δ֪ԭ��"},{"�Ŷ����ݵĴ���"},{"δ֪ԭ��"},{"δ֪ԭ��"},{"δ֪ԭ��"},
	/* 35- 39*/	{"δ֪ԭ��"},{"δ֪ԭ��"},{"δ֪ԭ��"},{"δ֪ԭ��"},{"δ֪ԭ��"},
	/* 40- 41*/	{"ͨ�÷���д����/ͨ�÷���д����϶��Ͽ�"},{"ͨ�÷���д������Ͽ�"},
	/* 42- 44*/ {"ͨ�÷��������/ͨ�÷����������Ч������Ӧ"},{"ͨ�÷����������Ч������Ӧ"},{"ͨ�÷���дȷ��"},
	/* 45- 49*/	{"δ֪ԭ��"},{"δ֪ԭ��"},{"δ֪ԭ��"},{"δ֪ԭ��"},{"δ֪ԭ��"},
};

char descKod[256][32] = {
	/*  0-  4*/	{"δ֪���"},{"ʵ��ֵ"},{"ȱʡֵ"},{"����(��Сֵ�����ֵ������)"},{"δ֪���"},
	/*  5-  9*/	{"����(n,m)"},{"����"},{"�α�"},{"�б�"},{"����"},
	/* 10- 14*/	{"����"},{"δ֪���"},{"������Ŀ"},{"ֻ��"},{"ֻд"},
	/* 15- 19*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"��Ӧ�Ĺ������ͺ���Ϣ���"},
	/* 20- 24*/	{"��Ӧ���¼�"},{"�б���ı�����"},{"�б��ֵ����"},{"���������Ŀ"},{"δ֪���"},
	/* 25- 29*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/* 30- 34*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/* 35- 39*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/* 40- 44*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/* 45- 49*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/* 50- 54*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/* 55- 59*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/* 60- 64*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/* 65- 69*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/* 70- 74*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/* 75- 79*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/* 80- 84*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/* 85- 89*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/* 90- 94*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/* 95- 99*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*100-104*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"���Խṹ"},{"δ֪���"},
	/*105-109*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*110-114*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*115-119*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*120-124*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*125-129*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*130-134*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*135-139*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*140-144*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*145-149*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*150-154*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*155-159*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*160-164*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*165-169*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*170-174*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*175-179*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*180-184*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*185-189*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*190-194*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*195-199*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*200-204*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*205-209*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*210-214*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*215-219*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*220-224*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*225-229*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*230-234*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*235-239*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*240-244*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*245-249*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*250-254*/	{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},{"δ֪���"},
	/*255-   */	{"δ֪���"}
};

char descGddType[256][32] = {
	/*  0-  4*/	{"������"},{"ASCII8λ��"},{"����8λ��"},{"�޷�������"},{"����"},
	/*  5-  9*/	{"�޷��Ÿ�����"},{"������"},{"IEEE��׼754��ʵ��"},{"IEEE��׼754ʵ��"},{"˫����Ϣ"},
	/* 10- 14*/	{"������Ϣ"},{"��˲��Ͳ���˫����Ϣ"},{"��Ʒ�������ʵı���ֵ"},{"δ֪"},{"������ʱ��"},
	/* 15- 19*/	{"ͨ�÷����ʶ���"},{"���ʱ��"},{"�������ͺ���Ϣ���"},{"��ʱ��ı���"},{"�����ʱ���ʱ�걨��"},
	/* 20- 24*/	{"�����ʱ���ʱ��ı���ֵ"},{"�ⲿ�ı����"},{"ͨ�÷���ش���"},{"���ݽṹ"},{"����"},
	/* 25- 29*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/* 30- 34*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/* 35- 39*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/* 40- 44*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/* 45- 49*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/* 50- 54*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/* 55- 59*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/* 60- 64*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/* 65- 69*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/* 70- 74*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/* 75- 79*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/* 80- 84*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/* 85- 89*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/* 90- 94*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/* 95- 99*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*100-104*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*105-109*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*110-114*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*115-119*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*120-124*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*125-129*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*130-134*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*135-139*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*140-144*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*145-149*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*150-154*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*155-159*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*160-164*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*165-169*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*170-174*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*175-179*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*180-184*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*185-189*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*190-194*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*195-199*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*200-204*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*205-209*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*210-214*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*215-219*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*220-224*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*225-229*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*230-234*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*235-239*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*240-244*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*245-249*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*250-254*/	{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},{"δ֪"},
	/*255-   */	{"δ֪"}
};
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

bool cp16time_nw_desc(char* DrawStr,CP16Time2a* tm16)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	
	szTemp.assign("���ʱ��: ");
	strcat(DrawStr,szTemp.c_str());
	
	sprintf(tmp,"%d��%d���� ",tm16->parts.ms/1000,tm16->parts.ms%1000);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	
    return true;
}

bool cp56time_nw_desc(char* DrawStr,CP56Time2a* tm56)
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

bool ngd_desc(char* DrawStr,NGD_t* ngd)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	
	szTemp.assign("ͨ�÷������ݼ�: ");
	strcat(DrawStr,szTemp.c_str());
	
	sprintf(tmp,"��Ŀ: %d, ������λ: %d, ����״̬λ: %d ",ngd->parts.num,ngd->parts.count,ngd->parts.cont);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	
    return true;
}

bool asdu10DataSet_Gdd23_desc(char* DrawStr,unsigned char size,char* gid)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	unsigned char	pos = 0;
	unsigned int	uiTemp = 0;
	int				iTemp = 0;
	float			fTemp = 0;
	GDD23_t			gdd23;
	char			*data = gid;
	char			ginTemp[1024] = {'\0'};

	while (pos < size)
	{
		memset(ginTemp,0,1024);
		memcpy(&gdd23,data,sizeof(GDD23_t));
		gdd23.gid = data + sizeof(GDD23_t) - sizeof(unsigned int);
		pos  = pos + sizeof(GDD23_t) + gdd23.gdd.size*gdd23.gdd.num - sizeof(unsigned int);
		data = data + sizeof(GDD23_t) + gdd23.gdd.size*gdd23.gdd.num - sizeof(unsigned int);

		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"  ������������: %s, ���: %d, ��Ŀ: %d, ����״̬: %d, ",
			descGddType[gdd23.gdd.type],gdd23.gdd.size,gdd23.gdd.num,gdd23.gdd.cont);
		szTemp.assign(tmp);
		strcat(DrawStr,szTemp.c_str());

		szTemp.assign("����ֵ: ");
		strcat(DrawStr,szTemp.c_str());
		switch(gdd23.gdd.type)
		{
		case GDD_NONE:
			szTemp.assign("�� ");
			break;
		case GDD_ASCII:
			memcpy(ginTemp,gdd23.gid,gdd23.gdd.size*gdd23.gdd.num);
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"%s ",ginTemp);
			szTemp.assign(tmp);
			break;
		case GDD_UI:
			memcpy(&uiTemp,gdd23.gid,gdd23.gdd.size*gdd23.gdd.num);
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"%u ",uiTemp);
			szTemp.assign(tmp);
			break;
		case GDD_I:
			memcpy(&iTemp,gdd23.gid,gdd23.gdd.size*gdd23.gdd.num);
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"%d ",iTemp);
			szTemp.assign(tmp);
			break;
		case GDD_UF:
		case GDD_F:
		case GDD_IEEE754SP:
			memcpy(&fTemp,gdd23.gid,gdd23.gdd.size*gdd23.gdd.num);
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"%f ",fTemp);
			szTemp.assign(tmp);
			break;
		case GDD_IEEE754DP:
			memcpy(&fTemp,gdd23.gid,gdd23.gdd.size*gdd23.gdd.num);
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"%lf ",fTemp);
			szTemp.assign(tmp);
			break;
		default:
			szTemp.assign("������δ���� ");
			break;
		}
		strcat(DrawStr,szTemp.c_str());
		szTemp.assign("\r\n");
		strcat(DrawStr,szTemp.c_str());
	}

	return true;
}

bool asdu10DataSet_desc(char* DrawStr,ASDU10_DATASET_t* dataSet)
{
	int				i;
	unsigned int	uiTemp = 0;
	int				iTemp = 0;
	float			fTemp = 0;
	string			szTemp;
	char			ginTemp[1024] = {'\0'};	
	char			tmp[512] = {'\0'};
	
	sprintf(tmp,"���: %d, ��Ŀ��: %d, ���: %s, ��������: %s, ���: %d, ��Ŀ: %d, ����״̬: %d, ",
		dataSet->gin.group,dataSet->gin.entry,descKod[dataSet->kod],descGddType[dataSet->gdd.type],dataSet->gdd.size,dataSet->gdd.num,dataSet->gdd.cont);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	
	szTemp.assign("����ֵ: ");
	strcat(DrawStr,szTemp.c_str());
	switch(dataSet->gdd.type)
	{
	case GDD_NONE:
		szTemp.assign("�� ");
		break;
	case GDD_ASCII:
		memcpy(ginTemp,dataSet->gid,dataSet->gdd.size*dataSet->gdd.num);
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"%s ",ginTemp);
		szTemp.assign(tmp);
		break;
	case GDD_BSI:
		for (i = 0; i < dataSet->gdd.size*dataSet->gdd.num; i++)
		{
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"%02xH ",dataSet->gid[i]);
			szTemp.assign(tmp);
			strcat(DrawStr,szTemp.c_str());
		}
		szTemp.clear();
		break;
	case GDD_UI:
		memcpy(&uiTemp,dataSet->gid,dataSet->gdd.size*dataSet->gdd.num);
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"%u ",uiTemp);
		szTemp.assign(tmp);
		break;
	case GDD_I:
		memcpy(&iTemp,dataSet->gid,dataSet->gdd.size*dataSet->gdd.num);
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"%d ",iTemp);
		szTemp.assign(tmp);
		break;
	case GDD_UF:
	case GDD_F:
	case GDD_IEEE754SP:
		memcpy(&fTemp,dataSet->gid,dataSet->gdd.size*dataSet->gdd.num);
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"%f ",fTemp);
		szTemp.assign(tmp);
		break;
	case GDD_IEEE754DP:
		memcpy(&fTemp,dataSet->gid,dataSet->gdd.size*dataSet->gdd.num);
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"%lf ",fTemp);
		szTemp.assign(tmp);
		break;
	case GDD_DPI:
		if (dataSet->gid[0] == 2)
			szTemp.assign("�� ");
		else if (dataSet->gid[0] == 1)
			szTemp.assign("�� ");
		else
			szTemp.assign("δ֪");
		break;
	case GDD_SPI:
		if (dataSet->gid[0] == 1)
			szTemp.assign("�� ");
		else if (dataSet->gid[0] == 0)
			szTemp.assign("�� ");
		else
			szTemp.assign("δ֪");
		break;
	case GDD_DPI_TR:
		if (dataSet->gid[0] == 2)
			szTemp.assign("�� ");
		else if (dataSet->gid[0] == 1)
			szTemp.assign("�� ");
		else if (dataSet->gid[0] == 0)
			szTemp.assign("˲�� ");
		else if (dataSet->gid[0] == 3)
			szTemp.assign("��� ");
		else
			szTemp.assign("δ֪");
		break;
	case GDD_MEQ:
		MEA		mea;
		memcpy(&mea,dataSet->gid,sizeof(MEA));
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"%d ",mea.mval);
		szTemp.assign(tmp);
		strcat(DrawStr,szTemp.c_str());
		if (mea.OV)
		{
			szTemp.assign("��� ");
			strcat(DrawStr,szTemp.c_str());
		}
		if (mea.ER)
		{
			szTemp.assign("��� ");
			strcat(DrawStr,szTemp.c_str());
		}
		szTemp.clear();
		break;
	case GDD_BINTIME:
		CP56Time2a tm56;
		memcpy(&tm56,dataSet->gid,sizeof(CP56Time2a));
		cp56time_nw_desc(DrawStr,&tm56);
		szTemp.clear();
		break;
	case GDD_RET:
		CP16Time2a tm16;
		memcpy(&tm16,dataSet->gid,sizeof(CP16Time2a));
		cp16time_nw_desc(DrawStr,&tm16);
		szTemp.clear();
		break;
	case GDD_STRUCTURE:
		szTemp.assign("\r\n");
		strcat(DrawStr,szTemp.c_str());
		asdu10DataSet_Gdd23_desc(DrawStr,dataSet->gdd.size,dataSet->gid);
		szTemp.clear();
		break;
	default:
		szTemp.assign("������δ���� ");
		break;
	}
	strcat(DrawStr,szTemp.c_str());
	szTemp.assign("\r\n");
	strcat(DrawStr,szTemp.c_str());
	
    return true;
}

bool Analyze_GW(char* DrawStr,unsigned int Len,char* Data)
{
	char			tmp[512] = {'\0'};
	string			szTemp;
	APCI			apci;

	if (Data[0] == 0x68 && (unsigned short)Len == (unsigned short)(MAKEWORD(Data[1],Data[2])) + 3)
	{
		memcpy(&apci,Data,sizeof(APCI));
		apci.data = &Data[sizeof(APCI)-4];

		if (apci.control.U_parts.FLAG == 0x03)
		{
			szTemp.assign("U��ʽ���� ");
			strcat(DrawStr,szTemp.c_str());

			if (apci.control.U_parts.STARTVL)
			{
				szTemp.assign("������Ч ");
				strcat(DrawStr,szTemp.c_str());
			}
			if (apci.control.U_parts.STARTCN)
			{
				szTemp.assign("����ȷ�� ");
				strcat(DrawStr,szTemp.c_str());
			}
			if (apci.control.U_parts.STOPVL)
			{
				szTemp.assign("ֹͣ��Ч ");
				strcat(DrawStr,szTemp.c_str());
			}
			if (apci.control.U_parts.STOPCN)
			{
				szTemp.assign("ֹͣȷ�� ");
				strcat(DrawStr,szTemp.c_str());
			}
			if (apci.control.U_parts.TESTFRVL)
			{
				szTemp.assign("������Ч ");
				strcat(DrawStr,szTemp.c_str());
			}
			if (apci.control.U_parts.TESTFRCN)
			{
				szTemp.assign("����ȷ�� ");
				strcat(DrawStr,szTemp.c_str());
			}
			strcat(DrawStr,"\r\n");
			return true;
		}
		else if (apci.control.S_parts.FLAG == 0x01)
		{
			szTemp.assign("S��ʽ���� ");
			strcat(DrawStr,szTemp.c_str());

			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"�������к�: %d ",apci.control.S_parts.RXNO);
			szTemp.assign(tmp);
			strcat(DrawStr,szTemp.c_str());
			strcat(DrawStr,"\r\n");
			return true;
		}
		else if (apci.control.I_parts.FLAG == 0x00)
		{
			szTemp.assign("I��ʽ���� ");
			strcat(DrawStr,szTemp.c_str());

			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"�������к�: %d ",apci.control.I_parts.TXNO);
			szTemp.assign(tmp);
			strcat(DrawStr,szTemp.c_str());

			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"�������к�: %d ",apci.control.I_parts.RXNO);
			szTemp.assign(tmp);
			strcat(DrawStr,szTemp.c_str());
		}
		else 
		{
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"���������: %08XH ",apci.control.bits);
			szTemp.assign(tmp);
			strcat(DrawStr,szTemp.c_str());
			strcat(DrawStr,"\r\n");
			return true;
		}
		strcat(DrawStr,"\r\n");

		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"%s(%d) ",descType[apci.type_id],apci.type_id);
		szTemp.assign(tmp);
		strcat(DrawStr,szTemp.c_str());
		if (apci.type_id == ASDU1_M_TM_TA_3)
			strcat(DrawStr,"\r\n");

		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"�ɱ�ṹ�޶���:%d(%02xH) ",apci.vsq.bits,apci.vsq.bits);
		szTemp.assign(tmp);
		strcat(DrawStr,szTemp.c_str());
		
		if (apci.cause < 50) 
		{
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"%s(%d) ",descCause[apci.cause],apci.cause);
			szTemp.assign(tmp);
		}
		else 
		{
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"%s(%d) ","δ֪ԭ��",apci.cause);
			szTemp.assign(tmp);
		}
		strcat(DrawStr,szTemp.c_str());
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"ASDU������ַ[װ�õ�ַ:%d,CPU��:%d,��ֵ����:%d]",
			apci.asdu_addr.addr,apci.asdu_addr.cpu,apci.asdu_addr.area);
		szTemp.assign(tmp);
		strcat(DrawStr,szTemp.c_str());
		strcat(DrawStr,"\r\n");

		Analyze_GW_UserData(DrawStr,&apci);
	}
	else
	{
		strcat(DrawStr,"���ĸ�ʽ�����Ϲ��ҵ�������������Ϣͨ�Ź淶");
		return false;
	}

	return true;
}

bool Analyze_GW_UserData(char* DrawStr,APCI* apci)
{
	switch(apci->type_id)
	{
	case ASDU1_M_TM_TA_3:
		Analyze_ASDU1_UserData(DrawStr,apci);
		break;
	case ASDU2_M_TMR_TA_3:
		Analyze_ASDU2_UserData(DrawStr,apci);
		break;
	case ASDU4_M_TME_TA_3:
		Analyze_ASDU4_UserData(DrawStr,apci);
		break;
	case ASDU6_C_SYN_TA_3:
		Analyze_ASDU6_UserData(DrawStr,apci);
		break;
	case ASDU7_C_IGI_NA_3:
		Analyze_ASDU7_UserData(DrawStr,apci);
		break;
	case ASDU8_M_TGI_NA_3:
		Analyze_ASDU8_UserData(DrawStr,apci);
		break;
	case ASDU10_C_GD_NA_3:
		Analyze_ASDU10_UserData(DrawStr,apci);
		break;
	case ASDU12_M_LBS_NA_3:
		Analyze_ASDU12_UserData(DrawStr,apci);
		break;
	case ASDU13_C_LB_NA_3:
		Analyze_ASDU13_UserData(DrawStr,apci);
		break;
	case ASDU14_M_LB_NA_3:
		Analyze_ASDU14_UserData(DrawStr,apci);
		break;
	case ASDU15_C_LBL_NA_3:
		Analyze_ASDU15_UserData(DrawStr,apci);
		break;
	case ASDU16_M_LBL_NA_3:
		Analyze_ASDU16_UserData(DrawStr,apci);
		break;
	case ASDU17_C_HIS_NA_3:
		Analyze_ASDU17_UserData(DrawStr,apci);
		break;
	case ASDU18_M_HIS_NA_3:
		Analyze_ASDU18_UserData(DrawStr,apci);
		break;
	case ASDU42_M_TGI_NA_3:
		Analyze_ASDU42_UserData(DrawStr,apci);
		break;
	case ASDU101_C_FLL_NA_3:
		Analyze_ASDU101_UserData(DrawStr,apci);
		break;
	case ASDU102_M_FLL_NA_3:
		Analyze_ASDU102_UserData(DrawStr,apci);
		break;
	case ASDU103_C_FL_NA_3:
		Analyze_ASDU103_UserData(DrawStr,apci);
		break;
	case ASDU104_M_FL_NA_3:
		Analyze_ASDU104_UserData(DrawStr,apci);
		break;
	case ASDU105_C_DFI_NA_3:
		break;
	case ASDU106_M_DFI_NA_3:
		break;
	case ASDU107_C_DFD_NA_3:
		break;
	case ASDU108_M_DFD_NA_3:
		break;
	default:
		break;
	}

	return true;
}

void Analyze_ASDU1_UserData(char* DrawStr,APCI* apci)
{
	char		tmp[512] = {'\0'};
	string		szTemp;
	ASDU1_t		asdu1;
	char		*data = apci->data;
	
	memcpy(&asdu1,data,sizeof(ASDU1_t));
	
	sprintf(tmp,"��������(Fun): %d, ��Ϣ���(Inf): %d \r\n",asdu1.fun,asdu1.inf);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	

	switch(asdu1.dpi)
	{
	case 1:
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"״̬: ��/����/�˳�(%d) ",asdu1.dpi);
		szTemp.assign(tmp);
		break;
	case 2:
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"״̬: ��/����/Ͷ��(%d) ",asdu1.dpi);
		szTemp.assign(tmp);
		break;
	default:
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"״̬: ��ȷ��(%d) ",asdu1.dpi);
		szTemp.assign(tmp);
		break;
	}
	strcat(DrawStr,szTemp.c_str());	

	cp56time_nw_desc(DrawStr,&asdu1.tm56);

	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"������ϢSIN: %d \r\n",asdu1.sin);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	
}

void Analyze_ASDU2_UserData(char* DrawStr,APCI* apci)
{
	char		tmp[512] = {'\0'};
	string		szTemp;
	ASDU2_t		asdu2;
	char		*data = apci->data;
	
	memcpy(&asdu2,data,sizeof(ASDU2_t));
	
	sprintf(tmp,"��������(Fun): %d, ��Ϣ���(Inf): %d \r\n",asdu2.fun,asdu2.inf);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	
	
	switch(asdu2.dpi)
	{
	case 1:
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"״̬: ��/����/�˳�(%d) ",asdu2.dpi);
		szTemp.assign(tmp);
		break;
	case 2:
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"״̬: ��/����/Ͷ��(%d) ",asdu2.dpi);
		szTemp.assign(tmp);
		break;
	default:
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"״̬: ��ȷ��(%d) ",asdu2.dpi);
		szTemp.assign(tmp);
		break;
	}
	strcat(DrawStr,szTemp.c_str());	

	cp16time_nw_desc(DrawStr,&asdu2.tm16);

	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"�������: %d \r\n",asdu2.fan);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	

	cp56time_nw_desc(DrawStr,&asdu2.tm56);
	
	szTemp.assign("�����������: ");
	strcat(DrawStr,szTemp.c_str());	
	if (asdu2.fpt & 0x01)
	{
		szTemp.assign("A����� ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (asdu2.fpt & 0x02)
	{
		szTemp.assign("B����� ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (asdu2.fpt & 0x04)
	{
		szTemp.assign("C����� ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (asdu2.fpt & 0x08)
	{
		szTemp.assign("�ӵع��� ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (asdu2.fpt & 0x10)
	{
		szTemp.assign("������� ");
		strcat(DrawStr,szTemp.c_str());
	}
	if (asdu2.fpt & 0x80)
	{
		szTemp.assign("��Ч ");
	}
	else
	{
		szTemp.assign("��/δ֪ ");
	}
	strcat(DrawStr,szTemp.c_str());
}

void Analyze_ASDU4_UserData(char* DrawStr,APCI* apci)
{
	char		tmp[512] = {'\0'};
	string		szTemp;
	ASDU4_t		asdu4;
	char		*data = apci->data;
	
	memcpy(&asdu4,data,sizeof(ASDU4_t));
	
	sprintf(tmp,"��������(Fun): %d, ��Ϣ���(Inf): %d \r\n",asdu4.fun,asdu4.inf);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	

	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"��·λ��: %f ",asdu4.scl);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	
	cp16time_nw_desc(DrawStr,&asdu4.tm16);
	
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"�������: %d \r\n",asdu4.fan);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	
	
	cp56time_nw_desc(DrawStr,&asdu4.tm56);
}

void Analyze_ASDU6_UserData(char* DrawStr,APCI* apci)
{
	char		tmp[512] = {'\0'};
	string		szTemp;
	ASDU6_t		asdu6;
	char		*data = apci->data;
	
	memcpy(&asdu6,data,sizeof(ASDU6_t));
	
	sprintf(tmp,"��������(Fun): %d, ��Ϣ���(Inf): %d \r\n",asdu6.fun,asdu6.inf);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	
	
	cp56time_nw_desc(DrawStr,&asdu6.tm56);
	szTemp.assign("\r\n");
	strcat(DrawStr,szTemp.c_str());	
}

void Analyze_ASDU7_UserData(char* DrawStr,APCI* apci)
{
	char		tmp[512] = {'\0'};
	string		szTemp;
	ASDU7_t		asdu7;
	char		*data = apci->data;
	
	memcpy(&asdu7,data,sizeof(ASDU7_t));
	
	sprintf(tmp,"��������(Fun): %d, ��Ϣ���(Inf): %d, ɨ�����(scn): %d \r\n",asdu7.fun,asdu7.inf,asdu7.scn);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	
}

void Analyze_ASDU8_UserData(char* DrawStr,APCI* apci)
{
	char		tmp[512] = {'\0'};
	string		szTemp;
	ASDU8_t		asdu8;
	char		*data = apci->data;
	
	memcpy(&asdu8,data,sizeof(ASDU8_t));
	
	sprintf(tmp,"��������(Fun): %d, ��Ϣ���(Inf): %d, ɨ�����(scn): %d \r\n",asdu8.fun,asdu8.inf,asdu8.scn);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	
}

void Analyze_ASDU10_UserData(char* DrawStr,APCI* apci)
{
	char				tmp[512] = {'\0'};
	string				szTemp;
	ASDU10_t			asdu10;
	ASDU10_DATASET_t	dataSet;
	char				*data = apci->data;
	
	memcpy(&asdu10,data,sizeof(ASDU10_t));
	data += sizeof(ASDU10_t);
	
	sprintf(tmp,"��������(Fun): %d, ��Ϣ���(Inf): %d, ������Ϣ��ʶ��(Rii): %d \r\n",asdu10.fun,asdu10.inf,asdu10.rii);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	

	ngd_desc(DrawStr,&asdu10.ngd);
	szTemp.assign("\r\n");
	strcat(DrawStr,szTemp.c_str());

	for (int i = 0; i < asdu10.ngd.parts.num; i++)
	{
		memcpy(&dataSet,data,sizeof(ASDU10_DATASET_t));
		dataSet.gid = data + sizeof(ASDU10_DATASET_t) - sizeof(unsigned int);
		data = data + sizeof(ASDU10_DATASET_t) + dataSet.gdd.size*dataSet.gdd.num - sizeof(unsigned int);

		asdu10DataSet_desc(DrawStr,&dataSet);
	}
}

void Analyze_ASDU12_UserData(char* DrawStr,APCI* apci)
{
	char		tmp[512] = {'\0'};
	string		szTemp;
	ASDU12_t	asdu12;
	char		name[128] = {'\0'};	
	char		*data = apci->data;

	memcpy(&asdu12,data,sizeof(ASDU12_t));

	sprintf(tmp,"��������(Fun): %d, ��Ϣ���(Inf): %d, �������(FPT): %d, ��բ���(JPT): %d, ���Ͼ���(SCL): %f, �غ�բ: %d, �غ�բʱ��: %dms\r\n",
		asdu12.fun,asdu12.inf,asdu12.fpt,asdu12.jpt,asdu12.scl,asdu12.dpi,asdu12.msh*256+asdu12.msl);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());

	szTemp.assign("����");
	strcat(DrawStr,szTemp.c_str());
	cp56time_nw_desc(DrawStr,&asdu12.faultTm56);
	szTemp.assign("\r\n");
	strcat(DrawStr,szTemp.c_str());

	memcpy(name,asdu12.accName,sizeof(asdu12.accName));
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"¼���ļ���: %s\r\n",name);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	memset(name,0,sizeof(name));
	memcpy(name,asdu12.gapName,sizeof(asdu12.gapName));
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"�����: %s\r\n",name);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());

	szTemp.assign("��վ����");
	strcat(DrawStr,szTemp.c_str());
	cp56time_nw_desc(DrawStr,&asdu12.recvTm56);
}

void Analyze_ASDU13_UserData(char* DrawStr,APCI* apci)
{
	char		tmp[512] = {'\0'};
	string		szTemp;
	ASDU13_t	asdu13;
	char		name[64] = {'\0'};	
	char		*data = apci->data;
	
	memcpy(&asdu13,data,sizeof(ASDU13_t));
	
	sprintf(tmp,"��������(Fun): %d, ��Ϣ���(Inf): %d, ������Ϣ��ʶ��(Rii): %d \r\n",asdu13.fun,asdu13.inf,asdu13.rii);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	

	memcpy(name,asdu13.name,40);
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"¼���ļ���: %s, ��ʼ����λ��: %d \r\n",name,asdu13.startPos);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
}

void Analyze_ASDU14_UserData(char* DrawStr,APCI* apci)
{
	char		tmp[512] = {'\0'};
	string		szTemp;
	ASDU14_t	asdu14;
	char		*data = apci->data;
	
	memcpy(&asdu14,data,sizeof(ASDU14_t));
	
	sprintf(tmp,"��������(Fun): %d, ��Ϣ���(Inf): %d, ������Ϣ��ʶ��(Rii): %d \r\n",asdu14.fun,asdu14.inf,asdu14.rii);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	
	
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"����λ��־: %d, ��ʼ����λ��: %d, ¼���ļ�����: ...... \r\n",asdu14.cont,asdu14.startPos);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
}

void Analyze_ASDU15_UserData(char* DrawStr,APCI* apci)
{
	char		tmp[512] = {'\0'};
	string		szTemp;
	ASDU15_t	asdu15;
	char		*data = apci->data;
	
	memcpy(&asdu15,data,sizeof(ASDU15_t));
	
	sprintf(tmp,"��������(Fun): %d, ��Ϣ���(Inf): %d, ������Ϣ��ʶ��(Rii): %d \r\n",asdu15.fun,asdu15.inf,asdu15.rii);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	
	
	szTemp.assign("��ʼ");
	strcat(DrawStr,szTemp.c_str());
	cp56time_nw_desc(DrawStr,&asdu15.startTm56);

	szTemp.assign("����");
	strcat(DrawStr,szTemp.c_str());
	cp56time_nw_desc(DrawStr,&asdu15.stopTm56);

	szTemp.assign("\r\n");
	strcat(DrawStr,szTemp.c_str());
}

void Analyze_ASDU16_UserData(char* DrawStr,APCI* apci)
{
	int			i;
	string		szTemp;
	ASDU16_t	asdu16;
	ASDU16_LB_t	asdu16Lb;
	char		name[64] = {'\0'};
	char		*data = apci->data;
	char		tmp[512] = {'\0'};
	
	memcpy(&asdu16,data,sizeof(ASDU16_t));
	data = data + sizeof(ASDU16_t);
	
	sprintf(tmp,"��������(Fun): %d, ��Ϣ���(Inf): %d, ������Ϣ��ʶ��(Rii): %d \r\n",asdu16.fun,asdu16.inf,asdu16.rii);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	
	
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"����λ��־: %d, ¼���ļ�����: %d, ",asdu16.cont,asdu16.num);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	szTemp.assign("��ʼ");
	strcat(DrawStr,szTemp.c_str());
	cp56time_nw_desc(DrawStr,&asdu16.startTm56);
	szTemp.assign("����");
	strcat(DrawStr,szTemp.c_str());
	cp56time_nw_desc(DrawStr,&asdu16.stopTm56);
	szTemp.assign("\r\n");
	strcat(DrawStr,szTemp.c_str());

	for (i = 0; i < asdu16.num; i++)
	{
		memcpy(&asdu16Lb,data,sizeof(ASDU16_LB_t));
		data += sizeof(ASDU16_LB_t);
		memset(name,0,40);
		memcpy(name,asdu16Lb.name,40);
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"����¼��װ�õ�ַ: %d, ¼������: %s, ��С: %d, ",asdu16Lb.iedNo,name,asdu16Lb.size);
		szTemp.assign(tmp);
		strcat(DrawStr,szTemp.c_str());
		szTemp.assign("����");
		strcat(DrawStr,szTemp.c_str());
		cp56time_nw_desc(DrawStr,&asdu16Lb.tm56);
		szTemp.assign("\r\n");
		strcat(DrawStr,szTemp.c_str());
	}
}

void Analyze_ASDU17_UserData(char* DrawStr,APCI* apci)
{
	char		tmp[512] = {'\0'};
	string		szTemp;
	ASDU17_t	asdu17;
	char		*data = apci->data;
	
	memcpy(&asdu17,data,sizeof(ASDU17_t));
	
	sprintf(tmp,"��������(Fun): %d, ��Ϣ���(Inf): %d, ������Ϣ��ʶ��: %d, �¼�����: ",asdu17.fun,asdu17.inf,asdu17.rii);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	

	switch(asdu17.type)
	{
	case 1:
		szTemp.assign("�ٻ����϶�����Ϣ ");
		break;
	case 2:
		szTemp.assign("װ���Լ���Ϣ ");
		break;
	case 3:
		szTemp.assign("ң�ű�λ��Ϣ ");
		break;
	case 4:
		szTemp.assign("SOE��Ϣ ");
		break;
	case 5:
		szTemp.assign("���ϲ���¼� ");
		break;
	case 6:
		szTemp.assign("�澯�¼� ");
		break;
	case 255:
		szTemp.assign("װ�������¼� ");
		break;
	default:
		szTemp.assign("���� ");
		break;
	}
	strcat(DrawStr,szTemp.c_str());	
	
	szTemp.assign("��ʼ");
	strcat(DrawStr,szTemp.c_str());
	cp56time_nw_desc(DrawStr,&asdu17.startTm56);
	
	szTemp.assign("����");
	strcat(DrawStr,szTemp.c_str());
	cp56time_nw_desc(DrawStr,&asdu17.stopTm56);
	
	szTemp.assign("\r\n");
	strcat(DrawStr,szTemp.c_str());
}

void Analyze_ASDU18_UserData(char* DrawStr,APCI* apci)
{
	int				i;
	string			szTemp;
	ASDU18_t		asdu18;
	ASDU18_HIS_t	asdu18His;
	char			*data = apci->data;
	char			tmp[512] = {'\0'};
	
	memcpy(&asdu18,data,sizeof(ASDU18_t));
	data = data + sizeof(ASDU18_t);
	
	sprintf(tmp,"��������(Fun): %d, ��Ϣ���(Inf): %d, ������Ϣ��ʶ��: %d, ����λ��־: %d \r\n",
		asdu18.fun,asdu18.inf,asdu18.rii,asdu18.cont);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	
	szTemp.assign("��ʼ");
	strcat(DrawStr,szTemp.c_str());
	cp56time_nw_desc(DrawStr,&asdu18.startTm56);
	szTemp.assign("����");
	strcat(DrawStr,szTemp.c_str());
	cp56time_nw_desc(DrawStr,&asdu18.stopTm56);
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"��ʷ��Ŀ��: %d \r\n",asdu18.num);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	
	
	for (i = 0; i < asdu18.num; i++)
	{
		memcpy(&asdu18His,data,sizeof(ASDU18_HIS_t));
		data = data + sizeof(ASDU18_HIS_t);

		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"����װ�õ�ַ: %d, �¼�����: ",asdu18His.iedNo);
		szTemp.assign(tmp);
		strcat(DrawStr,szTemp.c_str());
		switch(asdu18His.type)
		{
		case 1:
			szTemp.assign("�ٻ����϶�����Ϣ ");
			break;
		case 2:
			szTemp.assign("װ���Լ���Ϣ ");
			break;
		case 3:
			szTemp.assign("ң�ű�λ��Ϣ ");
			break;
		case 4:
			szTemp.assign("SOE��Ϣ ");
			break;
		case 5:
			szTemp.assign("���ϲ���¼� ");
			break;
		case 6:
			szTemp.assign("�澯�¼� ");
			break;
		case 255:
			szTemp.assign("װ�������¼� ");
			break;
		default:
			szTemp.assign("���� ");
			break;
		}
		strcat(DrawStr,szTemp.c_str());	
		
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"��������(Fun): %d, ��Ϣ���(Inf): %d, ˫����Ϣ: %d ",asdu18His.fun,asdu18His.inf,asdu18His.dpi);
		szTemp.assign(tmp);
		strcat(DrawStr,szTemp.c_str());
		
		szTemp.assign("���");
		strcat(DrawStr,szTemp.c_str());
		cp16time_nw_desc(DrawStr,&asdu18His.ret);

		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"�������: %d, ��·λ��: %f, �������: %d ",asdu18His.fan,asdu18His.scl,asdu18His.fpt);
		szTemp.assign(tmp);
		strcat(DrawStr,szTemp.c_str());
		
		szTemp.assign("����");
		strcat(DrawStr,szTemp.c_str());
		cp56time_nw_desc(DrawStr,&asdu18His.tm56);
		
		szTemp.assign("\r\n");
		strcat(DrawStr,szTemp.c_str());
	}
}

void Analyze_ASDU42_UserData(char* DrawStr,APCI* apci)
{
	char				tmp[512] = {'\0'};
	string				szTemp;
	unsigned short		pos = sizeof(APCI) - sizeof(unsigned int);
	unsigned short		len = apci->len + 3/*syn(1)+len(2)*/ - 1/*scn(1)*/;
	ASDU42_t			asdu42;
	char				*data = apci->data;
	
	while(pos < len)
	{
		memcpy(&asdu42,data,sizeof(ASDU42_t));
		data += sizeof(ASDU42_t);
		pos  += sizeof(ASDU42_t);
		
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"��������(Fun): %d, ��Ϣ���(Inf): %d ",asdu42.fun,asdu42.inf);
		szTemp.assign(tmp);
		strcat(DrawStr,szTemp.c_str());	
		
		switch(asdu42.dpi)
		{
		case 1:
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"˫����Ϣ: ��(%d) ",asdu42.dpi);
			szTemp.assign(tmp);
			break;
		case 2:
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"˫����Ϣ: ��(%d) ",asdu42.dpi);
			szTemp.assign(tmp);
			break;
		default:
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"˫����Ϣ: ��ȷ��(%d) ",asdu42.dpi);
			szTemp.assign(tmp);
			break;
		}
		strcat(DrawStr,szTemp.c_str());
		
		szTemp.assign("\r\n");
		strcat(DrawStr,szTemp.c_str());
	}
}

void Analyze_ASDU101_UserData(char* DrawStr,APCI* apci)
{
	char		tmp[512] = {'\0'};
	string		szTemp;
	ASDU101_t	asdu101;
	char		folder[128] = {'\0'};
	char		*data = apci->data;
	
	memcpy(&asdu101,data,sizeof(ASDU101_t));
	
	sprintf(tmp,"��������(Fun): %d, ��Ϣ���(Inf): %d, ������Ϣ��ʶ��(Rii): %d \r\n",asdu101.fun,asdu101.inf,asdu101.rii);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	
	
	szTemp.assign("��ʼ");
	strcat(DrawStr,szTemp.c_str());
	cp56time_nw_desc(DrawStr,&asdu101.startTm56);
	szTemp.assign("����");
	strcat(DrawStr,szTemp.c_str());
	cp56time_nw_desc(DrawStr,&asdu101.stopTm56);
	
	memcpy(folder,asdu101.folder,100);
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"Ŀ¼����ͨ���: %s \r\n",folder);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
}

void Analyze_ASDU102_UserData(char* DrawStr,APCI* apci)
{
	int				i;
	string			szTemp;
	ASDU102_t		asdu102;
	ASDU102_FILE_t	asdu102File;
	char			name[128] = {'\0'};
	char			*data = apci->data;
	char			tmp[512] = {'\0'};
	
	memcpy(&asdu102,data,sizeof(ASDU102_t));
	data = data + sizeof(ASDU102_t);
	
	sprintf(tmp,"��������(Fun): %d, ��Ϣ���(Inf): %d, ������Ϣ��ʶ��(Rii): %d \r\n",asdu102.fun,asdu102.inf,asdu102.rii);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	
	
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"����λ��־: %d, һ���ļ�����: %d, ",asdu102.cont,asdu102.num);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
	szTemp.assign("��ʼ");
	strcat(DrawStr,szTemp.c_str());
	cp56time_nw_desc(DrawStr,&asdu102.startTm56);
	szTemp.assign("����");
	strcat(DrawStr,szTemp.c_str());
	cp56time_nw_desc(DrawStr,&asdu102.stopTm56);
	szTemp.assign("\r\n");
	strcat(DrawStr,szTemp.c_str());
	
	for (i = 0; i < asdu102.num; i++)
	{
		memcpy(&asdu102File,data,sizeof(ASDU102_FILE_t));
		data += sizeof(ASDU102_FILE_t);
		memset(name,0,100);
		memcpy(name,asdu102File.name,100);
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"�����ļ�����: %s, ",name);
		szTemp.assign(tmp);
		strcat(DrawStr,szTemp.c_str());

		cp56time_nw_desc(DrawStr,&asdu102File.tm56);

		memset(tmp,0,sizeof(tmp));
        sprintf(tmp,"����: %d �ֽ�",asdu102File.length);
		szTemp.assign(tmp);
		strcat(DrawStr,szTemp.c_str());
        szTemp.assign("\r\n");
        strcat(DrawStr,szTemp.c_str());
	}
}

void Analyze_ASDU103_UserData(char* DrawStr,APCI* apci)
{
	string		szTemp;
	ASDU103_t	asdu103;
	char		name[128] = {'\0'};
	char		*data = apci->data;
	char		tmp[512] = {'\0'};
	
	memcpy(&asdu103,data,sizeof(ASDU103_t));
	
	sprintf(tmp,"��������(Fun): %d, ��Ϣ���(Inf): %d, ������Ϣ��ʶ��(Rii): %d \r\n",asdu103.fun,asdu103.inf,asdu103.rii);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	
	
	memcpy(name,asdu103.name,100);
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"�ļ���: %s, ��ʼ����λ��: %d \r\n",name,asdu103.startPos);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
}

void Analyze_ASDU104_UserData(char* DrawStr,APCI* apci)
{
	string		szTemp;
	ASDU104_t	asdu104;
	char		name[128] = {'\0'};
	char		*data = apci->data;
	char		tmp[512] = {'\0'};
	
	memcpy(&asdu104,data,sizeof(ASDU104_t));
	
	sprintf(tmp,"��������(Fun): %d, ��Ϣ���(Inf): %d, ������Ϣ��ʶ��(Rii): %d, ������־λ: %d, ��ʼλ��: %d \r\n",
		asdu104.fun,asdu104.inf,asdu104.rii,asdu104.cont,asdu104.startPos);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());	
	
	memcpy(name,asdu104.name,100);
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"�ļ���: %s ",name);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());

	cp56time_nw_desc(DrawStr,&asdu104.tm56);
	
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"����: %d �ֽ�, ����: ...... \r\n",asdu104.length);
	szTemp.assign(tmp);
	strcat(DrawStr,szTemp.c_str());
}
