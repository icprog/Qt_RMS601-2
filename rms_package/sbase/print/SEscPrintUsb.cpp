/**
 *
 * �� �� �� : EscPrintUsb.cpp
 * �������� : 2012-10-17 13:41
 * ��    �� : �ۿ���(skt001@163.com)
 * �޸����� : $Date: $
 * ��ǰ�汾 : $Revision: $
 * �������� : ESC(EPSON Standard Code for Printer)ָ�����USB�ڵĴ�ӡ��
 * �޸ļ�¼ : 
 *            $Log: $
 *
 * Ver  Date        Author  Comments
 * ---  ----------  ------  -------------------------------------------
 * 001	2012-10-17	�ۿ�������ļ�
 * 002  2014-02-21  �ۿ���  ���Ӵ��ڴ�ӡ֧��
 *
 **/

#include "SEscPrintUsb.h"

int g_printer_id[]={
	//vid,pid//��Ӧ������ID����ƷID
	0x00,0x00,//�ɴ����������������ָ����ӡ���ͺ�
	0x1bA0,0x1504,//ӳ��380
	0x04B8,0x0005//EPSON LQ300K+II
};

//////////////////////////////////////////////////////////////////////////
// ��    ��:  SEscPrintUsb
// ��    ��:  �ۿ���
// ����ʱ��:  2012-10-17 13:20
// ��    ��:  ESEָ���ӡ����
//////////////////////////////////////////////////////////////////////////
SEscPrintUsb::SEscPrintUsb()
{
	m_pUsbDev = NULL;
	m_iVendorId = 0x1BA0;
	m_iProductId = 0x1504;
	m_iPortOut = 0x01;
	m_iPortIn = 0x82;
}

SEscPrintUsb::~SEscPrintUsb()
{

}

//////////////////////////////////////////////////////////////////////////
// ��    ��:  ��ӡ��ʼ��
// ��    ��:  �ۿ���
// ����ʱ��:  2012-10-17 13:46
// ����˵��:  @sAttrΪ��չ���ԣ���ͬʵ�����ṩ��ͬ�Ĳ���
// �� �� ֵ:  true��ʾ��ʼ���ɹ�,false��ʾ��ʼ��ʧ��
//////////////////////////////////////////////////////////////////////////
bool SEscPrintUsb::Init(SString sAttr)
{
    usb_init();
// 	usb_set_debug(1);
    usb_find_busses();
    usb_find_devices();
	return true;
}

//////////////////////////////////////////////////////////////////////////
// ��    ��:  �򿪴�ӡ��
// ��    ��:  �ۿ���
// ����ʱ��:  2012-10-17 13:23
// ����˵��:  @sAttrΪ��ӡ������;�磺vid=1234;pid=5678;pout=1;pin=129;
// �� �� ֵ:  true�򿪳ɹ���false��ʧ��
//////////////////////////////////////////////////////////////////////////
bool SEscPrintUsb::Open(SString sAttr)
{
    struct usb_bus     *bus;
    struct usb_device  *dev;
	LOGDEBUG("��USB��ӡ��:%s",sAttr.data());
	if(SString::IsAttribute(sAttr,"vid"))
		m_iVendorId = (WORD)SString::GetAttributeValueI(sAttr,"vid");
	if(SString::IsAttribute(sAttr,"pid"))
		m_iProductId = (WORD)SString::GetAttributeValueI(sAttr,"pid");
	if(SString::IsAttribute(sAttr,"pout"))
		m_iPortOut = (WORD)SString::GetAttributeValueI(sAttr,"pout");
	if(SString::IsAttribute(sAttr,"pin"))
		m_iPortIn = (WORD)SString::GetAttributeValueI(sAttr,"pin");
	if(m_pUsbDev != NULL)
	{
		LOGWARN("��ӡ���Ѿ���!");
		return false;
	}
	m_pUsbDev = NULL;
	//�ɴ����ͺŸ�ΪԤ�ü���֧�ֵ��豸�ͺ�,��һ���Դ�ֱ���ɹ�Ϊֹ,�������ͺ���Ϊ��һ��ƥ���ͺ�
	g_printer_id[0] = m_iVendorId;
	g_printer_id[1] = m_iProductId;
	int drvs = sizeof(g_printer_id)/(sizeof(int)*2);
	for(bus = usb_get_busses(); bus != NULL && m_pUsbDev==NULL; bus = bus->next)
	{
		for(dev = bus->devices; dev != NULL /*&& m_pUsbDev==NULL*/; dev = dev->next)
		{
			LOGDEBUG("VID=%X; PID=%X", dev->descriptor.idVendor, dev->descriptor.idProduct);
			for(int drv=0;drv<drvs && m_pUsbDev==NULL;drv++)
			{
				m_iVendorId = g_printer_id[drv*2];
				m_iProductId = g_printer_id[drv*2+1];
				if(dev->descriptor.idVendor == m_iVendorId && dev->descriptor.idProduct == m_iProductId)
				{
					m_pUsbDev = usb_open(dev);
					if(m_pUsbDev == NULL)
					{
						LOGERROR("��USB��ӡ��ʧ��!%s",usb_strerror());
						return false;
					}
					break;
				}
			}
		}
	}
	if(m_pUsbDev == NULL)
	{
		//LOGWARN("δ�ҵ�ָ���ͺŵ�USB��ӡ��[VID:%04X,PID:%04X]!",m_iVendorId,m_iProductId);
		LOGWARN("δ�ҵ�ָ��֧�ֵ�USB��ӡ��!��ͨ������1��ӡ");
#ifndef WIN32
		if(!m_Com.Open("dev=/dev/ttyS0"))
		{
			LOGWARN("�򿪴���1ʧ��!");
			return false;
		}
#else
		if(!m_Com.Open("dev=com4"))
		{
			LOGWARN("�򿪴���1ʧ��!");
			return false;
		}
#endif
		return true;
	}
#ifndef WIN32
	usb_detach_kernel_driver_np(m_pUsbDev, 0);	// for Linux Only
#endif
	if(usb_set_configuration(m_pUsbDev, 1) < 0)
    {
        LOGERROR("usb_set_configuration����#%d: %s\n", 1, usb_strerror());
		Close();
        return false;
    }
    if(usb_claim_interface(m_pUsbDev, 0) < 0)
    {
        LOGERROR("usb_claim_interface����#%d:\n%s\n", 0, usb_strerror());
        Close();
        return false;
    }
	if(usb_clear_halt(m_pUsbDev, m_iPortOut) < 0)
    {
        LOGERROR("usb_clear_halt����#%d:\n%s\n", 0, usb_strerror());
        Close();
        return false;
    }


	if(SEscPrint::Open(sAttr))
	{
		LOGDEBUG("USB��ӡ���򿪳ɹ�!");
		return true;
	}
	else
	{
		LOGDEBUG("USB��ӡ����ʧ��!");
		return false;
	}
}

//////////////////////////////////////////////////////////////////////////
// ��    ��:  �رմ�ӡ��
// ��    ��:  �ۿ���
// ����ʱ��:  2012-10-17 13:26
// ����˵��:  void
// �� �� ֵ:  true�رճɹ���false�ر�ʧ��
//////////////////////////////////////////////////////////////////////////
bool SEscPrintUsb::Close()
{
	m_Com.Close();
	if(m_pUsbDev == NULL)
		return false;
	LOGDEBUG("�ر�USB��ӡ��!");
    usb_release_interface(m_pUsbDev, 0);
	usb_close(m_pUsbDev);
	m_pUsbDev = NULL;
	return true;
}

//////////////////////////////////////////////////////////////////////////
// ��    ��:  ���ӡ��д����
// ��    ��:  �ۿ���
// ����ʱ��:  2012-10-17 13:31
// ����˵��:  @pBuffer��д�����ݻ�����ָ��
//            @iLenΪ�������ֽڳ���
// �� �� ֵ:  >0��ʾʵ�ʷ����ֽ�����<=0��ʾʧ��
//////////////////////////////////////////////////////////////////////////
int SEscPrintUsb::Write(BYTE *pBuffer,int iLen)
{
	if(m_Com.IsOpened())
		return m_Com.Write(pBuffer,iLen);
	if(m_pUsbDev == NULL)
		return -1;
    int send_len;
    send_len = usb_bulk_write(m_pUsbDev, m_iPortOut, (char*)pBuffer, iLen, USB_TIMEOUT);
	//LOGDEBUG("WRITE(len:%d):%s",send_len,SString::HexToStr(pBuffer,iLen).data());
    if (send_len < 0)
    {
		LOGERROR("��USB��ӡд����ʧ��%d:%s",send_len,usb_strerror());
		return -2;
    }

	return send_len;
}

//////////////////////////////////////////////////////////////////////////
// ��    ��:  �Ӵ�ӡ����ȡ����
// ��    ��:  �ۿ���
// ����ʱ��:  2012-10-17 13:35
// ����˵��:  @pBufferΪ�����뻺����ָ��
//            @iLenΪ������ȡ�ֽڳ���
// �� �� ֵ:  >0��ʾʵ�ʶ�ȡ�ֽ�����<0��ʾ��ȡʧ�ܣ�=0��ʾ��ȡ��ʱ
//////////////////////////////////////////////////////////////////////////
int SEscPrintUsb::Read(BYTE *pBuffer,int iLen)
{
	if(m_Com.IsOpened())
		return m_Com.Read(pBuffer,iLen);
	int recv_len;
    recv_len = usb_bulk_read(m_pUsbDev, m_iPortIn, (char*)pBuffer, iLen, USB_TIMEOUT);
    if (recv_len < 0)
    {
		LOGERROR("��USB��ӡд����ʧ��%d:%s",recv_len,usb_strerror());
		return -2;
    }

	return recv_len;
}



//////////////////////////////////////////////////////////////////////////

SEscPrintCom::SEscPrintCom()
{

}

SEscPrintCom::~SEscPrintCom()
{
	m_Com.Close();
}

//////////////////////////////////////////////////////////////////////////
// ��    ��:  ��ӡ��ʼ��
// ��    ��:  �ۿ���
// ����ʱ��:  2014:2:21 13:46
// ����˵��:  @sAttrΪ��չ���ԣ���ͬʵ�����ṩ��ͬ�Ĳ���
// �� �� ֵ:  true��ʾ��ʼ���ɹ�,false��ʾ��ʼ��ʧ��
//////////////////////////////////////////////////////////////////////////
bool SEscPrintCom::Init(SString sAttr)
{
	return true;
}

//////////////////////////////////////////////////////////////////////////
// ��    ��:  �򿪴�ӡ��
// ��    ��:  �ۿ���
// ����ʱ��:  2014:2:21 13:23
// ����˵��:  @sAttrΪ��ӡ������
// �� �� ֵ:  true�򿪳ɹ���false��ʧ��
//////////////////////////////////////////////////////////////////////////
bool SEscPrintCom::Open(SString sAttr)
{
	SString dev = SString::GetAttributeValue(sAttr,"dev");
	int baud = SString::GetAttributeValueI(sAttr,"baud");
	if(baud == 0)
		baud = 19200;
	SString chk = SString::GetAttributeValue(sAttr,"chk");
	if(chk.length() == 0)
		chk = "N";
	if(!m_Com.Open(dev.data(),baud,chk.at(0)))
	{
		LOGERROR("�򿪴���ʱʧ��!attr=%s",sAttr.data());
		return false;
	}

	if(SEscPrint::Open(sAttr))
	{
		LOGDEBUG("���ڴ�ӡ���򿪳ɹ�!");
		return true;
	}
	else
	{
		LOGDEBUG("���ڴ�ӡ����ʧ��!");
		return false;
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////
// ��    ��:  �رմ�ӡ��
// ��    ��:  �ۿ���
// ����ʱ��:  2014:2:21 13:26
// ����˵��:  void
// �� �� ֵ:  true�رճɹ���false�ر�ʧ��
//////////////////////////////////////////////////////////////////////////
bool SEscPrintCom::Close()
{
	m_Com.Close();
	return true;
}

//////////////////////////////////////////////////////////////////////////
// ��    ��:  ���ӡ��д����
// ��    ��:  �ۿ���
// ����ʱ��:  2014:2:21 13:31
// ����˵��:  @pBuffer��д�����ݻ�����ָ��
//            @iLenΪ�������ֽڳ���
// �� �� ֵ:  >0��ʾʵ�ʷ����ֽ�����<=0��ʾʧ��
//////////////////////////////////////////////////////////////////////////
int SEscPrintCom::Write(BYTE *pBuffer,int iLen)
{
	if(m_Com.GetHandle() == 0)
		return -1;
	int send_len = m_Com.Send(pBuffer,iLen);
	LOGDEBUG("SEND(len=%d): %s",iLen,SString::HexToStr(pBuffer,iLen).data());
	LOGDEBUG("SEND(len=%d): %s",iLen,SString::toString((char*)pBuffer,iLen).data());
	if (send_len < 0)
	{
		LOGERROR("�򴮿ڴ�ӡд����ʧ��%d:%s",send_len,usb_strerror());
		return -2;
	}
#ifdef WIN32
	//	Sleep(10);
#else
	if(iLen == 1)
		usleep(100000);
	else if(iLen > 2000)
		usleep(300000);
	else 
		usleep(200000);
#endif


	return send_len;
}

//////////////////////////////////////////////////////////////////////////
// ��    ��:  �Ӵ�ӡ����ȡ����
// ��    ��:  �ۿ���
// ����ʱ��:  2014:2:21 13:35
// ����˵��:  @pBufferΪ�����뻺����ָ��
//            @iLenΪ������ȡ�ֽڳ���
// �� �� ֵ:  >0��ʾʵ�ʶ�ȡ�ֽ�����<0��ʾ��ȡʧ�ܣ�=0��ʾ��ȡ��ʱ
//////////////////////////////////////////////////////////////////////////
int SEscPrintCom::Read(BYTE *pBuffer,int iLen)
{
	int recv_len;
	recv_len = m_Com.Receive(pBuffer, iLen);
	if (recv_len < 0)
	{
		LOGERROR("�Ӵ��ڴ�ӡ������ʧ��%d:%s",recv_len,usb_strerror());
		return -2;
	}

	return recv_len;
}





