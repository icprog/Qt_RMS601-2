/**
 *
 * �� �� �� : SSvgObject.h
 * �������� : 2007-04-09 08:55
 * ��    �� : �ۿ���(skt001@163.com)
 * �޸����� : $Date: $
 * ��ǰ�汾 : $Revision: $
 * �������� : SVG�������,��װSVG�Ļ���Ԫ��
 * �޸ļ�¼ : 
 *            $Log: $
 *
 **/

#if !defined(AFX_SKTSVGOBJECT_H__486DC941_8FDD_4B7B_8C09_947ECDB2F642__INCLUDED_)
#define AFX_SKTSVGOBJECT_H__486DC941_8FDD_4B7B_8C09_947ECDB2F642__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../../SString.h"
#include "../../SFile.h"
#include "../../SXmlConfig.h"
#include "../SBaseDC.h"
#include "../SBaseWnd.h"

class SSvgAttribute
{
public:
	struct stuAttribute
	{
		SString name;
		SString value;
	};
	SSvgAttribute()
	{
		m_Attribute.setAutoDelete(true);
	}
	~SSvgAttribute()
	{
	}
	stuAttribute* Find(SString sName)
	{
		int i,cnt = m_Attribute.count();
		for(i=0;i<cnt;i++)
		{
			stuAttribute *pAttr = m_Attribute[i];
			if(pAttr->name == sName)
			{
				return pAttr;
			}
		}
		return NULL;
	}
	bool Lookup(SString sName,SString &sVal)
	{
		stuAttribute *pAttr = Find(sName);
		if(pAttr == NULL)
			return false;
		sVal = pAttr->value;
		return true;
	}
	void SetAt(SString sName,SString sValue)
	{
		stuAttribute *pAttr = Find(sName);
		if(pAttr != NULL)
		{
			pAttr->value = sValue;
		}
		else
		{
			pAttr = new stuAttribute();
			pAttr->name = sName;
			pAttr->value = sValue;
			m_Attribute.append(pAttr);
		}		
	}
	int GetCount()
	{
		return m_Attribute.count();
	}
	bool GetItem(int index,SString &sName,SString &sValue)
	{
		if(index<0 && index>=m_Attribute.count())
			return false;
		stuAttribute *pAttr = m_Attribute[index];
		if(pAttr == NULL)
			return false;
		sName = pAttr->name;
		sValue= pAttr->value;
		return true;
	}

private:
	SPtrList<stuAttribute> m_Attribute;
};
class SSvgObject : public SString
{
public:
	//����SVGԪ������
	enum SVG_TYPE
	{
		TYPE_SVG,				//������
		TYPE_GROUP,			//SVG��
		TYPE_RECT,			//����
		TYPE_TEXT,			//����
		TYPE_ELLIPSE,		//��Բ
		TYPE_LINE,			//ֱ��
		TYPE_POLYLINE,	//����
		TYPE_PATH,			//·��
		TYPE_PIC,				//ͼƬ
		TYPE_UNKNOWN		//δ֪
	};
	//����SVG��ʾ��Χ
	struct SVG_RECT
	{
		float left,top,right,bottom;
	};
	

public:
	SSvgObject();
	virtual ~SSvgObject();
	
public:
	bool IsExistObj(SSvgObject *pObj);
	//��������ֵ
	void SetAttributeValue(char* sAttribute, char* sValue, bool bSetNext=false,bool bSetChild=true);
	//��������ֵ
	void SetAttributeValue(char* sAttribute, SString sValue, bool bSetNext=false,bool bSetChild=true);
	//������һ������
	void SetNextObject(SSvgObject* pNewObj);
	//ȡ��һ������
	inline SSvgObject* GetNext(){return m_pNext;};
	inline void SetNext(SSvgObject* pNext){m_pNext = pNext;};
	//ȡ��һ�������׽ڵ�
	inline SSvgObject* GetChild(){return m_pChild;};
	//������һ�������׽ڵ�
	inline void SetChild(SSvgObject* pChild){m_pChild = pChild;};
	//ȡ���ڵ�
	inline SSvgObject* GetParent(){return m_pParent;};
	//���ø��ڵ�
	inline void SetParent(SSvgObject* pParent){m_pParent = pParent;};
	//�����¼��ڵ㣬ͬʱ�����¼���Z����ֵ����
	void AddChild(SSvgObject* pChild);
	//���ö�����������
	inline void SetName(SString sName){m_sName = sName;};
	inline SString GetName(){return m_sName;};
	//ɾ����ǰ����������ڵ㼰�¼��ڵ�
	void Detete();
	//ɾ��ָ�����ӽڵ�
	void DeleteChild(SSvgObject* pChild, bool bDestroy=false);
	//���ص�ǰ�������Ч����,��������͡���ʾ��Χ��
	bool BuildObject(SSvgObject *pObj);//
	//������������ȡ��������
	int GetObjectTypeByName(SString sName);
	//���ݵ�ǰ�������ͣ����㵱ǰ�������ʾ��Χ
	bool CalcObjectRect();
	//ȡָ�����Ƶ�����ֵ
	SString GetAttribute(SString sName);
	float GetAttributeF(SString sName);
	int GetAttributeI(SString sName);
	//ȡ��������
	inline int GetType(){return m_SvgType;};
	inline SVG_RECT* GetRect(){return &m_Rect;};

	static bool IsRectInRect(SVG_RECT *pRect1, SVG_RECT *pRect2);
	//����ǰ�������¼�ƫ��ָ����С
	bool Offset(float dx, float dy);
	//����ǰ�������ָ��λ�óɱ�������
	bool Scale(float scale,float x0=0,float y0=0);

	//��������������¼�
	SSvgObject* Clone(SSvgObject *pParentObj=NULL, bool bWithNext=false);
	inline bool IsFlash(){return m_bFlash;};
	inline void SetFlash(bool b){m_bFlash = b;};
	SSvgObject *m_pChild;//ָ���¼��ڵ���׽ڵ�
	SSvgObject *m_pLastChild;//ָ���¼��ڵ���׽ڵ�
private:
	SSvgAttribute m_mapAttribute;//�������Լ���
	SSvgObject *m_pNext;//ָ����һ�ڵ�
	//SSvgObject *m_pChild;//ָ���¼��ڵ���׽ڵ�
	SSvgObject *m_pParent;//ָ�򸸽ڵ�
	bool m_bFlash;//�Ƿ��Ƕ���ͼ��
	int m_SvgType;//��������
	SVG_RECT m_Rect;//��ǰԪ�ص���ʾ��Χ
	SString m_sName;//�����������ƣ�line/text/path/rect
};

#endif // !defined(AFX_SKTSVGOBJECT_H__486DC941_8FDD_4B7B_8C09_947ECDB2F642__INCLUDED_)
