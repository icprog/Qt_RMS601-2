/**
 *
 * �� �� �� : SSvgDocument.h
 * �������� : 2007-04-08 18:55
 * ��    �� : �ۿ���(skt001@163.com)
 * �޸����� : $Date: $
 * ��ǰ�汾 : $Revision: $
 * �������� : SVG�ĵ���
 * �޸ļ�¼ : 
 *            $Log: $
 *
 **/

#if !defined(AFX_SKTSVGDOCUMENT_H__F7C1AB6F_CEDE_4835_8D08_4D5EEA9BA80F__INCLUDED_)
#define AFX_SKTSVGDOCUMENT_H__F7C1AB6F_CEDE_4835_8D08_4D5EEA9BA80F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../../SString.h"
#include "../../SFile.h"
#include "../../SXmlConfig.h"

#include "SSvgObject.h"

class SSvgDocument  
{
public:
	void ParseStyle(SSvgObject *pObj, SString style);
	SSvgObject* AddObject(SString sName, SString sAttr);
	SString GetAllObjects();
	SSvgObject* SearchByURI(SString uri);
	SSvgObject* SearchByAttribute(char* attr,char* val);
	void SortObject(SSvgObject *pObj);
	bool NewFile();
	SSvgDocument();
	virtual ~SSvgDocument();

	//����SVG�ļ�
	bool LoadSvgFile(SString sSvgFile);
	//����SVG�ļ�
	bool SaveSvgFile(SString sSvgFile);
	bool SaveSvgFileAsUtf8(SString sSvgFile);
	//�ݹ�дSVG�ڵ�
	bool WriteSvgNode(SSvgObject *pSvgObj, SFile *pFile, int iLevel=0);
	//д���Ե��ļ�
	bool WriteAttribute(SSvgObject *pSvgObj, SFile *pFile, SString sAttrName, SString sAttrValue="'{<NONE>}'");
	//�ݹ����SVGԪ�ص���������
	bool ReadSvgNode(SSvgObject *pParentSvgObj, SBaseConfig *pXmlNode);
	//������ж���
	bool RemoveObjects();
	//ȡ������
	SSvgObject* GetRootObject(){return m_pSvgRoot;};
	SSvgObject* GetFirstObject()
	{
		SSvgObject *pObj = GetRootObject();
		if(pObj == NULL)
			return NULL;
		pObj = pObj->GetChild();
		return pObj;
	};
	inline SString GetSvgPath(){return m_sSvgPath;};

private:
	SString m_sSvgFile;//SVG�ļ���
	SString m_sSvgPath;//SVG·��
	SSvgObject *m_pSvgRoot;//SVG������
	bool m_bUtf8;
};

#endif // !defined(AFX_YSSVGDOCUMENT_H__F7C1AB6F_CEDE_4835_8D08_4D5EEA9BA80F__INCLUDED_)
