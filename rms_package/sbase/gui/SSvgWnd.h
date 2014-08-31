/**
 *
 * �� �� �� : SSvgWnd.h
 * �������� : 2008-02-15 14:25
 * ��    �� : �ۿ���(skt001@163.com)
 * �޸����� : $Date: $
 * ��ǰ�汾 : $Revision: $
 * �������� : ͨ�õĴ�����ӿڣ��������׼�Ĵ��ڲ�����������ʵ��
 * �޸ļ�¼ : 
 *            $Log: $
 *
 **/

#ifndef __SKT_SVGWND_INC_H__
#define __SKT_SVGWND_INC_H__

#include "SGui.h"
#include "svg/SSvgDefine.h"
#include "svg/SSvgDocument.h"
#include "svg/SSvgPainter.h"

class SSvgWnd : public SWnd, public SSvgPainter
{
public:

	bool SetSvgText(SString sCaption,SString sText);
	void SetMovable(bool b);
	SSvgWnd();
#ifdef QT_GUI_LIB
	SSvgWnd(QWidget *parent) : SWnd(parent)
	{
		m_bMovable = false;
		m_iMoving = 0;
		m_iOffsetX = m_iOffsetY = 0;
	}
#endif
	~SSvgWnd();

	inline void SetSvgPath(SString sPath){m_sSvgPath = sPath;};
	bool Load(SString sSvgFile);

	SSvgObject* GetSvgObjectByCaption(SString sCaption);
	SSvgObject* GetSvgObjectByUri(SString sUri);
	
	virtual bool OnPaint(SBaseDC *pDC);
	virtual int OnLButtonDown(int nFlag,SPoint point);
	virtual int OnLButtonUp(int nFlag,SPoint point);
	virtual int OnMouseMove(int nFlag,SPoint point);
	virtual int OnMouseWheel(int nFlag,int delta);

	virtual void OnClickObject(SSvgObject *pSvgObj){};
	virtual int OnTimer(int nIDEvent){/*printf("@@@@@@@@@@@@@@@@@@@@@SSvgWnd::OnTimer(),this=%p\n",this);*/return 1;};
	SPoint  GetOffsetPoint();
	void SetOffset(int x,int y)
	{
		m_iOffsetX = x;
		m_iOffsetY = y;
	}
	int GetOffsetX(){return m_iOffsetX;}
	int GetOffsetY(){return m_iOffsetY;}
	void ToCenter();

private:
	SString m_sSvgPath;//svg�ļ��ľ���·��
	bool m_bMovable;//�Ƿ���ƶ�
	int m_iMoving;//�Ƿ������ƶ���0δ�ƶ���1׼���ƶ���2�Ѿ��ƶ�������׼���ƶ�
	int m_iOffsetX,m_iOffsetY;//X��Y�����ƫ��
	SPoint m_ptLast;
};


#endif//__YS_SVGWND_INC_H__
