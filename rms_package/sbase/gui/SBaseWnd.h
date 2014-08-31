/**
 *
 * �� �� �� : SBaseWnd.h
 * �������� : 2007-12-20 14:25
 * ��    �� : �ۿ���(skt001@163.com)
 * �޸����� : $Date: $
 * ��ǰ�汾 : $Revision: $
 * �������� : ͨ�õĴ�����ӿڣ��������׼�Ĵ��ڲ�����������ʵ��
 * �޸ļ�¼ : 
 *            $Log: $
 *
 **/

#ifndef __SKT_BASE_WND_INC_H__
#define __SKT_BASE_WND_INC_H__

#include "SBaseDC.h"
#include "../SApi.h"
class SBaseWnd
{
public:
	SBaseWnd()
	{
	}
	virtual ~SBaseWnd()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	// ��    ��:  ���麯�����ɵײ���ʵ��
	// ��    ��:  �ۿ���
	// ����ʱ��:  2008-1-18
	// ����˵��:  
	// �� �� ֵ:  
	//////////////////////////////////////////////////////////////////////////
	virtual bool IsWindowVisible(){return false;};
	virtual SBaseDC* CreateDC(){return NULL;};
	virtual void ReleaseDC(SBaseDC *pDC){};
	virtual bool OnPaint(SBaseDC *pDC){return true;};
	virtual bool OnCommand(DWORD wParam, DWORD lParam){return true;};
	virtual bool OnMessage(int message,DWORD wParam, DWORD lParam){return true;};
	virtual int OnCreate(){return 1;};
	virtual int OnClose(){return 1;};
	virtual int OnSize(int type,int cx,int cy){return 1;};
	virtual int OnKeyDown(int nVirtKey,int iKeyData){return 1;};
	virtual int OnKeyUp(int nVirtKey,int iKeyData){return 1;};
	virtual int OnLButtonDblClk(int nFlag,SPoint point){return 1;};
	virtual int OnLButtonDown(int nFlag,SPoint point){return 1;};
	virtual int OnLButtonUp(int nFlag,SPoint point){return 1;};
	virtual int OnMouseMove(int nFlag,SPoint point){return 1;};
	virtual int OnMouseWheel(int nFlag,int delta){return 1;}
	virtual int OnRButtonDblClk(int nFlag,SPoint point){return 1;};
	virtual int OnRButtonDown(int nFlag,SPoint point){return 1;};
	virtual int OnRButtonUp(int nFlag,SPoint point){return 1;};
	virtual int OnTimer(int nIDEvent){return 1;};
	virtual bool SendMessage(int message,DWORD wParam,DWORD lParam){return true;};
	virtual bool SetTimer(int nIDEvent,int nElapse){return 1;};

private:
	
};



#endif//__SKT_BASE_WND_INC_H__
