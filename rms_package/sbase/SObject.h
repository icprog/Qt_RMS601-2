/**
 *
 * �� �� �� : SObject.h
 * �������� : 2007-10-26 19:09
 * ��    �� : �ۿ���(skt001@163.com)
 * �޸����� : $Date: 2011/08/31 08:43:34 $
 * ��ǰ�汾 : $Revision: 1.1 $
 * �������� : ����SObject���࣬�����������������������ڼ������ַ�Ƿ�4�ֽڶ���
 * �޸ļ�¼ : 
 *            $Log: SObject.h,v $
 *            Revision 1.1  2011/08/31 08:43:34  shaokt
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
 *            Revision 1.2  2008/09/01 11:48:22  taol
 *            *** empty log message ***
 *
 *            Revision 1.1  2008/09/01 11:38:28  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2008/09/01 08:58:02  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.2  2007/10/30 10:48:38  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2007/10/29 07:30:23  shaokt
 *            ��Ӷ����ַ�Ƿ�Ϊ4�ı����ļ�⺯����Ϊ���ARM������pack(1)��ɵ��ڴ�����
 *
 *
 **/

#ifndef __SKT_OBJECT_H__

/**
 *
 * �� �� �� : SObject.h
 * �������� : 2007-10-26 19:12
 * ��    �� : �ۿ���(skt001@163.com)
 * �޸����� : $Date: 2011/08/31 08:43:34 $
 * ��ǰ�汾 : $Revision: 1.1 $
 * �������� : ����SObject���࣬���ڼ������ַ�Ƿ�4�ֽڶ���
 * �޸ļ�¼ : 
 *            $Log: SObject.h,v $
 *            Revision 1.1  2011/08/31 08:43:34  shaokt
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
 *            Revision 1.2  2008/09/01 11:48:22  taol
 *            *** empty log message ***
 *
 *            Revision 1.1  2008/09/01 11:38:28  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2008/09/01 08:58:02  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.2  2007/10/30 10:48:38  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2007/10/29 07:30:23  shaokt
 *            ��Ӷ����ַ�Ƿ�Ϊ4�ı����ļ�⺯����Ϊ���ARM������pack(1)��ɵ��ڴ�����
 *
 *
 **/

#define __SKT_OBJECT_H__

#include "SLog.h"

void SObjectWarn();


#ifndef _CHECK_OBJECT_
#define _SKTOBJECT_
#define SKTOBJECT(cls) 
#else
#define _SKTOBJECT_ \
					if(((int)this) % 4 != 0) \
					{ \
						LOGWARN("�����ַ[%p]δ��4�ֽڶ���!�⽫���ARMƽ̨�ϵ����в��ȶ�!!!",this); \
						SObjectWarn(); \
					} \
						
#define SKTOBJECT(cls) \
					if(((int)this) % 4 != 0) \
					{ \
						LOGWARN("%s�����ַ[%p]δ��4�ֽڶ���!�⽫���ARMƽ̨�ϵ����в��ȶ�!!!",cls,this); \
						SObjectWarn(); \
					} \

#endif


#endif//__SKT_OBJECT_H__


