/**
 *
 * 文 件 名 : SSvgDocument.h
 * 创建日期 : 2007-04-08 18:55
 * 作    者 : 邵凯田(skt001@163.com)
 * 修改日期 : $Date: $
 * 当前版本 : $Revision: $
 * 功能描述 : SVG文档类
 * 修改记录 : 
 *            $Log: $
 *
 **/

#include "SSvgDocument.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SSvgDocument::SSvgDocument()
{
	m_pSvgRoot = NULL;
}

SSvgDocument::~SSvgDocument()
{
	RemoveObjects();
}

bool SSvgDocument::LoadSvgFile(SString sSvgFile)
{
	if(sSvgFile == "")
	{
		return NewFile();
	}
	RemoveObjects();
	{
		//针对南思无效XML头的处理
		FILE *fp = fopen(sSvgFile.GetBuffer(0),"r+");
		if(fp == NULL)
			return false;
		fseek(fp,39,SEEK_SET);
		char buf[128];
		memset(buf,0,sizeof(buf));
		fread(buf,105,1,fp);
		SString str="";
		str+=buf;
		memset(buf,' ',sizeof(buf));
		if(str == "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.0//EN\" \"http://www.w3.org/TR/2001/PR-SVG-20010719/DTD/svg10.dtd\">")
		{
			fseek(fp,39,SEEK_SET);
			fwrite(buf,105,1,fp);
		}
		fclose(fp);
	}
	SXmlConfig xml;
	if(!xml.ReadConfig(sSvgFile))
		return false;
	m_sSvgFile = sSvgFile;
	m_sSvgPath = m_sSvgFile;
	int p0 = m_sSvgPath.findRev('/');
	if(p0>0)
	{
		m_sSvgPath = m_sSvgPath.Left(p0);
	}
	else
	{
		p0 = m_sSvgPath.findRev('\\');
		if(p0>0)
			m_sSvgPath = m_sSvgPath.Left(p0);
	}
	m_sSvgPath += "/";

	SBaseConfig* pRootNode=&xml;
	if(m_pSvgRoot == NULL)
		m_pSvgRoot = new SSvgObject();
	ReadSvgNode(m_pSvgRoot, pRootNode);
	if(m_pSvgRoot)
	{
		m_pSvgRoot->SetName("svg");
		m_pSvgRoot->BuildObject(m_pSvgRoot);
		m_pSvgRoot->CalcObjectRect();
	}
	return true;
}

bool SSvgDocument::SaveSvgFileAsUtf8(SString sSvgFile)
{
	m_bUtf8 = true;

	return true;
}

bool SSvgDocument::SaveSvgFile(SString sSvgFile)
{
	//return SaveSvgFileAsUtf8(sSvgFile);
	m_bUtf8 = false;
	SString sLine;
	if(sSvgFile == "")
		sSvgFile = m_sSvgFile;
	SFile file(sSvgFile);
	if(!file.open(IO_Truncate))
	{
		return false;
	}

	file.writeString("<?xml version=\"1.0\" encoding=\"GB2312\"?>\n");
	file.writeString("<!--\n");
	SString str;
	str = "Generated by : Skt-SVG图形编辑工具\n";
	file.writeString(str);
	file.writeString("Date         : "+SDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"\n");
	file.writeString("Version      : 1.0.4.18\n");
	file.writeString("-->\n");
	if(m_pSvgRoot != NULL)
		WriteSvgNode(m_pSvgRoot,&file,0);
	else
	{
		file.writeString("<svg />");
	}
	return true;
}

//递归写SVG节点
bool SSvgDocument::WriteSvgNode(SSvgObject *pSvgObj, SFile *pFile, int iLevel)
{
	if(pSvgObj == NULL)
		return false;
	SSvgObject *pObj = pSvgObj;
	SString str;
	int i;
	while(pObj)
	{
		for(i=1;i<=iLevel;i++)
			pFile->writeString("\t");
		pFile->writeString("<"+pObj->GetName()+" ");
		switch(pObj->GetType())
		{
		case SSvgObject::TYPE_SVG:
			WriteAttribute(pObj,pFile,"width");
			WriteAttribute(pObj,pFile,"height");
			break;
		case SSvgObject::TYPE_GROUP:
			WriteAttribute(pObj,pFile,"uri");
			WriteAttribute(pObj,pFile,"caption");
			WriteAttribute(pObj,pFile,"z");
			break;
		case SSvgObject::TYPE_RECT:
			WriteAttribute(pObj,pFile,"uri");
			WriteAttribute(pObj,pFile,"caption");
			WriteAttribute(pObj,pFile,"x");
			WriteAttribute(pObj,pFile,"y");
			WriteAttribute(pObj,pFile,"z");
			WriteAttribute(pObj,pFile,"width");
			WriteAttribute(pObj,pFile,"height");
			WriteAttribute(pObj,pFile,"stroke");
			WriteAttribute(pObj,pFile,"stroke-width");
			WriteAttribute(pObj,pFile,"stroke-dasharray");
			WriteAttribute(pObj,pFile,"fill");
			break;
		case SSvgObject::TYPE_PIC:
			WriteAttribute(pObj,pFile,"uri");
			WriteAttribute(pObj,pFile,"caption");
			WriteAttribute(pObj,pFile,"x");
			WriteAttribute(pObj,pFile,"y");
			WriteAttribute(pObj,pFile,"z");
			WriteAttribute(pObj,pFile,"width");
			WriteAttribute(pObj,pFile,"height");
			WriteAttribute(pObj,pFile,"href");
			break;
		case SSvgObject::TYPE_TEXT:
			WriteAttribute(pObj,pFile,"uri");
			WriteAttribute(pObj,pFile,"caption");
			WriteAttribute(pObj,pFile,"x");
			WriteAttribute(pObj,pFile,"y");
			WriteAttribute(pObj,pFile,"z");
			str = pObj->GetAttribute("font-family");
			{
				if(m_bUtf8)
				{
					//char *pStr = SString::translateCharToUTF_8(str.GetBuffer(0),str.GetLength());
					//char *pStr = SString::ConvertGBToUTF8(str.GetBuffer(0),str.GetLength());
					//WriteAttribute(pObj,pFile,"font-family");
					//delete[] pStr;
				}
				else
					WriteAttribute(pObj,pFile,"font-family",str);
			}
			WriteAttribute(pObj,pFile,"font-size");
			WriteAttribute(pObj,pFile,"font-weight");
			WriteAttribute(pObj,pFile,"fill");
			break;
		case SSvgObject::TYPE_ELLIPSE:
			WriteAttribute(pObj,pFile,"uri");
			WriteAttribute(pObj,pFile,"caption");
			WriteAttribute(pObj,pFile,"cx");
			WriteAttribute(pObj,pFile,"cy");
			WriteAttribute(pObj,pFile,"z");
			WriteAttribute(pObj,pFile,"rx");
			WriteAttribute(pObj,pFile,"ry");
			WriteAttribute(pObj,pFile,"stroke");
			WriteAttribute(pObj,pFile,"stroke-width");
			WriteAttribute(pObj,pFile,"stroke-dasharray");
			WriteAttribute(pObj,pFile,"fill");
			break;
		case SSvgObject::TYPE_LINE:
			WriteAttribute(pObj,pFile,"uri");
			WriteAttribute(pObj,pFile,"caption");
			WriteAttribute(pObj,pFile,"x1");
			WriteAttribute(pObj,pFile,"y1");
			WriteAttribute(pObj,pFile,"z");
			WriteAttribute(pObj,pFile,"x2");
			WriteAttribute(pObj,pFile,"y2");
			WriteAttribute(pObj,pFile,"stroke");
			WriteAttribute(pObj,pFile,"stroke-width");
			WriteAttribute(pObj,pFile,"stroke-dasharray");
			break;
		case SSvgObject::TYPE_POLYLINE:
			WriteAttribute(pObj,pFile,"uri");
			WriteAttribute(pObj,pFile,"caption");
			WriteAttribute(pObj,pFile,"z");
			WriteAttribute(pObj,pFile,"points");
			WriteAttribute(pObj,pFile,"stroke");
			WriteAttribute(pObj,pFile,"stroke-width");
			WriteAttribute(pObj,pFile,"stroke-dasharray");
			WriteAttribute(pObj,pFile,"fill");			
			break;
		case SSvgObject::TYPE_PATH:
			WriteAttribute(pObj,pFile,"uri");
			WriteAttribute(pObj,pFile,"caption");
			WriteAttribute(pObj,pFile,"x");
			WriteAttribute(pObj,pFile,"y");
			WriteAttribute(pObj,pFile,"z");
			WriteAttribute(pObj,pFile,"width");
			WriteAttribute(pObj,pFile,"height");
			WriteAttribute(pObj,pFile,"stroke");
			WriteAttribute(pObj,pFile,"stroke-width");
			WriteAttribute(pObj,pFile,"stroke-dasharray");
			WriteAttribute(pObj,pFile,"fill");
			WriteAttribute(pObj,pFile,"d");
			break;
		}
		//onmousedown="onmousedown(evt)"
		//onmouseover='change_attribut1(evt)'
		//onmouseout='change_attribut2(evt)'

		if(pObj->GetAttribute("uri") != "")
		{
			WriteAttribute(pObj,pFile,"onmousedown","onmousedown(evt)");
			WriteAttribute(pObj,pFile,"onmouseover","change_attribut1(evt)");
			WriteAttribute(pObj,pFile,"onmouseout","change_attribut2(evt)");
		}
		if(pObj->GetType() == SSvgObject::TYPE_TEXT)
		{
			//文字直接写内容并关闭
			str = pObj->GetAttribute("text");
			pFile->writeString(">");
			if(m_bUtf8)
			{
				//char *pStr = SString::translateCharToUTF_8(str.GetBuffer(0),str.GetLength());
				//char *pStr = SString::ConvertGBToUTF8(str.GetBuffer(0),str.GetLength());
				//pFile->writeString(pStr);
				//delete[] pStr;
			}
			else
				pFile->writeString(str);
			pFile->writeString("</text>\n");
			pObj = pObj->GetNext();
			continue;
		}
		else if(pObj->GetChild() == NULL)//没有下级，直接关闭节点
		{
			pFile->writeString("/>\n");
		}
		else
		{
			pFile->writeString(">\n");
			WriteSvgNode(pObj->GetChild(),pFile,iLevel+1);
			for(i=1;i<=iLevel;i++)
				pFile->writeString("\t");
			pFile->writeString("</"+pObj->GetName()+">\n");
		}

		pObj = pObj->GetNext();
	}
	return true;
}

//写属性到文件
bool SSvgDocument::WriteAttribute(SSvgObject *pSvgObj, SFile *pFile, SString sAttrName, SString sAttrValue)
{
	if(sAttrValue == "'{<NONE>}'")
		pFile->writeString(sAttrName+"=\""+pSvgObj->GetAttribute(sAttrName)+"\" ");
	else
		pFile->writeString(sAttrName+"=\""+sAttrValue+"\" ");
	return true;
}

/************************************************************************/
/*
	递归加载SVG元素到根对象下
*/
/************************************************************************/
bool SSvgDocument::ReadSvgNode(SSvgObject *pParentSvgObj, SBaseConfig* pXmlNode)
{
	if(pXmlNode == NULL)
		return false;
	
	//加载当前及及其后续节点
	//SSvgObject *pPrev=NULL;
	SString sName,sNodeName;
	//int i,cnt = pXmlNode->GetChildCount();
	unsigned long pos,pos2;
	SSvgObject *pNewObj;
	SBaseConfig::SConfigAttribute *pAttr;
	SBaseConfig *pNode = pXmlNode->GetChildPtr()->FetchFirst(pos);
	while(pNode)
	//for(i=0;i<cnt;i++)
	{
		//SBaseConfig* pNode = pXmlNode->GetChildNode(i);
		sName = pNode->GetNodeName();
		if(sName == "#text")
		{
			//文字内容或注释
			pNode = pXmlNode->GetChildPtr()->FetchNext(pos);
			continue;
		}
		pNewObj = new SSvgObject();
		pNewObj->SetName(sName);
		//加载当前节点属性到SVG对象
#if 1
		pAttr = pNode->GetAttributePtr()->FetchFirst(pos2);
		while(pAttr)
		{
			if(pAttr->m_sName == "style")//样式表
			{
				ParseStyle(pNewObj,pAttr->m_sValue);
			}
			else
				pNewObj->SetAttributeValue(pAttr->m_sName.data(),pAttr->m_sValue.data());
			pAttr = pNode->GetAttributePtr()->FetchNext(pos2);
		}
#else
		int j,cnt2 = pNode->GetAttributeCount();
		for(j=0;j<cnt2;j++)
		{
			sNodeName = pNode->GetAttributeName(j);
			if(sNodeName == "style")//样式表
			{
				sNodeName = "";
				sNodeName += pNode->GetAttribute(sNodeName);
				ParseStyle(pNewObj,sNodeName);
			}
			else
				pNewObj->SetAttributeValue(sNodeName.data(),pNode->GetAttribute(sNodeName).data());
		}
#endif

		//插入对象树
		if(m_pSvgRoot == NULL)
		{
			m_pSvgRoot = pNewObj;
		}
		else
		{
			pParentSvgObj->AddChild(pNewObj);
		}
		//如果是文字需要读取其下级的文字内容，文字不需要读取下级
		if(sName == "text")
		{
			//why? if(pNode->GetChildCount()>0)
			{
				//固定加一个text属性用来存放文字的内容
				pNewObj->SetAttributeValue("text",pNode->GetNodeValue());
			}
		}
		else
		{
			//加载当前节点的下级节点
			ReadSvgNode(pNewObj,pNode);		
		}
		pNode = pXmlNode->GetChildPtr()->FetchNext(pos);
	}

	return true;
}

bool SSvgDocument::RemoveObjects()
{
	if(m_pSvgRoot)
	{
		m_pSvgRoot->Detete();
		m_pSvgRoot = NULL;
	}
	return true;
}


/************************************************************************/
/* 
	创建新的SVG文件，即空文档
*/
/************************************************************************/
bool SSvgDocument::NewFile()
{
	RemoveObjects();
	m_pSvgRoot = new SSvgObject();
	m_pSvgRoot->SetName("svg");
	m_pSvgRoot->BuildObject(m_pSvgRoot);
	SSvgObject *pNewObj = new SSvgObject();
	pNewObj->SetName("rect");
	pNewObj->SetAttributeValue("x","0");
	pNewObj->SetAttributeValue("y","0");
	pNewObj->SetAttributeValue("width","1280");
	pNewObj->SetAttributeValue("height","1024");
	pNewObj->SetAttributeValue("stroke","#000000");
	pNewObj->SetAttributeValue("stroke-width","1");
	pNewObj->SetAttributeValue("stroke-dasharray","0");
	pNewObj->SetAttributeValue("fill","#000000");
	pNewObj->BuildObject(pNewObj);
	m_pSvgRoot->AddChild(pNewObj);
	m_pSvgRoot->CalcObjectRect();
	return true;
}

/************************************************************************/
/*
	对当前的SVG根对象按Z序进行重新排序，第一个页面对象保证在最前不参加排序 
*/
/************************************************************************/
void SSvgDocument::SortObject(SSvgObject *pObj)
{
	SSvgObject *pRoot = GetRootObject();
	if(pRoot == NULL )
		return;

	pRoot->DeleteChild(pObj);
	pRoot->AddChild(pObj);

}

SSvgObject* SSvgDocument::SearchByURI(SString uri)
{
	SSvgObject *pFirst = GetFirstObject();
	if(pFirst == NULL )
		return NULL;
	while(pFirst)
	{
		if(pFirst->GetAttribute("uri") == uri)
			return pFirst;
		pFirst = pFirst->GetNext();
	}
	return NULL;
}

SSvgObject* SSvgDocument::SearchByAttribute(char* attr,char* val)
{
	SSvgObject *pFirst = GetFirstObject();
	SSvgObject *pFirst1=pFirst;
	if(pFirst == NULL )
		return NULL;
	while(pFirst)
	{
		if(pFirst->GetAttribute(attr) == val)
			return pFirst;
		pFirst = pFirst->GetNext();
	}
	return NULL;
}

SString SSvgDocument::GetAllObjects()
{
	SSvgObject *pFirst = GetFirstObject();
	if(pFirst == NULL )
		return "";
	SString str="";
	while(pFirst)
	{
		str += SString::toString((long)pFirst)+",";
		pFirst = pFirst->GetNext();
	}
	if(str.GetLength()>0)
		str = str.Left(str.GetLength()-1);
	return str;
}

/************************************************************************/
/* 
	增加一个图元，name为rect/text/line..., attr表示属性如stroke=#FF0000;x=100;y=200;
	返回新增对象的句柄，0表示失败
*/
/************************************************************************/
SSvgObject* SSvgDocument::AddObject(SString sName, SString sAttr)
{
	SSvgObject *pRoot = GetRootObject();
	if(pRoot == NULL)
		return NULL;
	SSvgObject *pNewObj = new SSvgObject();
	pNewObj->SetName(sName);
	ParseStyle(pNewObj,sAttr);
	pNewObj->BuildObject(pNewObj);
	pNewObj->CalcObjectRect();
	pRoot->AddChild(pNewObj);
	return pNewObj;
}

void SSvgDocument::ParseStyle(SSvgObject *pObj, SString style)
{
	//加载当前节点属性到SVG对象
	SString sAttrName,sAttrVal;
	int i,cnt=SString::GetAttributeCount(style,";");
	for(i=1;i<=cnt;i++)
	{
		sAttrName = SString::GetIdAttribute(i,style,";");
		if(sAttrName == "")
			continue;
		if(sAttrName.Find("=")>0)
		{
			sAttrVal = SString::GetIdAttribute(2,sAttrName,"=");
			sAttrName = SString::GetIdAttribute(1,sAttrName,"=");
			if(sAttrName == "")
				continue;
		}
		else
		{
			sAttrVal = SString::GetIdAttribute(2,sAttrName,":");
			sAttrName = SString::GetIdAttribute(1,sAttrName,":");
			if(sAttrName == "")
				continue;
		}
		pObj->SetAttributeValue(sAttrName.GetBuffer(0),sAttrVal);
	}

}
