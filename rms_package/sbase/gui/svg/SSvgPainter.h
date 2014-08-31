/**
 *
 * �� �� �� : SSvgPainter.h
 * �������� : 2007-04-08 15:46
 * ��    �� : �ۿ���(skt001@163.com)
 * �޸����� : $Date: $
 * ��ǰ�汾 : $Revision: $
 * �������� : SVG���ֶ���Ļ���,��װ��SVG���ֻ���Ԫ�صĻ��Ʒ���
 * �޸ļ�¼ : 
 *            $Log: $
 *
 **/

#if !defined(AFX_SKTSVGPAINTER_H__52A21C11_3038_48F4_9DD4_01C0BF478E71__INCLUDED_)
#define AFX_SKTSVGPAINTER_H__52A21C11_3038_48F4_9DD4_01C0BF478E71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <math.h>
#include "../SBaseWnd.h"
#include "../SBaseDC.h"
#include "SSvgObject.h"
#include "SSvgDocument.h"

#ifndef PS_DOT
#define PS_SOLID            0
#define PS_DASH             1       /* -------  */
#define PS_DOT              2       /* .......  */
#define PS_DASHDOT          3       /* _._._._  */
#define PS_DASHDOTDOT       4       /* _.._.._  */
#define PS_NULL             5
#define PS_INSIDEFRAME      6
#define PS_USERSTYLE        7
#define PS_ALTERNATE        8
#define PS_STYLE_MASK       0x0000000F
#endif

#ifndef NULL_BRUSH
#define WHITE_BRUSH         0
#define LTGRAY_BRUSH        1
#define GRAY_BRUSH          2
#define DKGRAY_BRUSH        3
#define BLACK_BRUSH         4
#define NULL_BRUSH          5
#define HOLLOW_BRUSH        NULL_BRUSH
#define WHITE_PEN           6
#define BLACK_PEN           7
#define NULL_PEN            8
#define OEM_FIXED_FONT      10
#define ANSI_FIXED_FONT     11
#define ANSI_VAR_FONT       12
#define SYSTEM_FONT         13
#define DEVICE_DEFAULT_FONT 14
#define DEFAULT_PALETTE     15
#define SYSTEM_FIXED_FONT   16
#endif

#define C_TAG_RECT_RADIUS 3 //ѡ����ļ����ǵĲ�������뾶

//ȥ��MINIGUI�ĺ궨��
//#ifdef DrawText
//#undef DrawText
//#endif

class SSvgPainter 
{
public:
	void SetScale(double scale);
	SString GetAttributeByLevel(SSvgObject* pObj, SString sAttr);
	SSvgPainter();
	virtual ~SSvgPainter();
	
	//����һ������
	void DrawObject(SBaseDC *pDC, SSvgObject *pObj, int x=0, int y=0, bool bOnlyOne=false);
	void DrawFlashObject(SBaseDC *pDC, SSvgObject *pObj, int x, int y);
	void DrawObjectSelected(SBaseDC *pDC, SSvgObject *pObj, int x, int y,SCOLOR colTag,bool bEditable);
	//���ݸ�������ƶ����
	void DrawAlignPoint(SBaseDC *pDC, SSvgObject *pObj, int x=0, int y=0);

	void DrawRect(SBaseDC *pDC, SSvgObject *pObj, int x=0, int y=0);
	void DrawSvgText(SBaseDC *pDC, SSvgObject *pObj, int x=0, int y=0);
	void DrawEllipse(SBaseDC *pDC, SSvgObject *pObj, int x=0, int y=0);
	void DrawLine(SBaseDC *pDC, SSvgObject *pObj, int x=0, int y=0);
	void DrawPolyLine(SBaseDC *pDC, SSvgObject *pObj, int x=0, int y=0);
	void DrawPath(SBaseDC *pDC, SSvgObject *pObj, int x=0, int y=0);
	void DrawPic(SBaseDC *pDC, SSvgObject *pObj, int x=0, int y=0);
	static YSSIZE GetTextSize(SBaseDC *pDC, SSvgObject *pObj);
	
	//����һ�������Ƿ����ʾ
	bool IsInViewRect(SSvgObject *pObj);

	SSvgObject* IsPointInObjectRect(SSvgObject *pObj, float x,float y);
	//���Ե�ǰ���Ƿ񾭹���ǰ�������µ��ֵܽڵ㣬x,yΪSVG����ϵ
	SSvgObject* IsObjectInPoint(SSvgObject *pObj, float x,float y);
	//���Ե�ǰ�����Ƿ����������ǰ�������µ��ֵܽڵ㣬x,yΪSVG����ϵ
	void SelectObjectInRect(SSvgObject *pObj, SSvgObject::SVG_RECT &selRect);

	//ת��SVG���굽��ǰ����
	int GetCoord(float x);
	//ת����ǰ���ڵ�SVG����
	float GetSvgCoord(float x);

	//ת����ɫ
	static SCOLOR GetColorByString(SString sColor);
	static SString GetStringByColor(SCOLOR color);
	static SString GetRGBStringByColor(SCOLOR color);

	//�����жϵ��Ƿ񿿽�
	bool IsNear(float v1, float v2);
	//�����ж�һ�����Ƿ���ָ�����߶���
	bool IsInLine(float x1, float y1, float x2, float y2, float px, float py);
	//����һ����Բ��һ�����㣬��λ�����Ӧ����Բ�ϵĵ�
	void GetEllipseByPoint(float x,float y, 
		float width,float height,float px, float py,float &ex,float &ey);

	static void SetBaseWnd(SBaseWnd *p);

	SSvgDocument m_Document;//SVG�ĵ�����
	//���ű���
	double m_dScale;
	//��ǰ�ӿڷ�Χ���˷�Χ��ӳ�䵽SVG����ϵ��
	SSvgObject::SVG_RECT m_ViewRect;
	//��ǰѡ�еĶ����б�ѡ�ж��������������У����Ƕ�̬ˢ��ʱ������ѡ���һ����ʾ
	SPtrList<SSvgObject> m_SelectedObjList;
	SPtrList<SSvgObject> m_MemObjList;
	bool m_bEditAllow;//�Ƿ�����༭����
	
};

#endif // !defined(AFX_SKTSVGPAINTER_H__52A21C11_3038_48F4_9DD4_01C0BF478E71__INCLUDED_)
