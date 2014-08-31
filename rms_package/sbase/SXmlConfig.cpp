/**
 *
 * �� �� �� : SXmlConfig.cpp
 * �������� : 2008-03-28
 * ��    �� : �ۿ���(skt001@163.com)
 * �޸����� : $Date: 2011/08/31 08:43:35 $
 * ��ǰ�汾 : $Revision: 1.1 $
 * �������� : ʵ�������ļ�����ӿڵ�XML������
 * �޸ļ�¼ : 
 *            $Log: SXmlConfig.cpp,v $
 *            Revision 1.1  2011/08/31 08:43:35  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.3  2011/05/24 08:44:54  shaokt
 *            �޸�UTF-8��ʽ��XML��ǰ�����ֽ���0xEF BB BF�����
 *
 *            Revision 1.2  2011/04/11 12:08:36  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2011/02/25 03:12:07  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2010/08/09 03:04:44  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.3  2010/01/26 06:57:30  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.2  2010/01/22 01:24:26  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2009/09/15 02:14:09  shaokt
 *            ͨѸ��¼����װ����Ŀ�״��ύ
 *
 *            Revision 1.6  2009/05/19 02:50:38  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.5  2009/01/31 06:37:34  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.4  2008/12/22 08:54:13  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.3  2008/11/03 05:54:49  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.2  2008/10/06 08:48:29  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2008/09/01 11:38:29  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2008/09/01 08:58:04  shaokt
 *            *** empty log message ***
 *
 *
 **/

#include "SXmlConfig.h"

SXmlConfig::SXmlConfig()
{
	SKTOBJECT("SXmlConfig");
}
SXmlConfig::~SXmlConfig()
{
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ���ļ���ȡXML
// ��    ��:  �ۿ���
// ����ʱ��:  2010-1-7 14:12
// ����˵��:  @sXmlFile�ļ�����
// �� �� ֵ:  true��ȡ�ļ�
//////////////////////////////////////////////////////////////////////////
bool SXmlConfig::ReadConfig(SString sXmlFile)
{
    int nRead;
    char *szXMLData;

	SFile file(sXmlFile);
	if(!file.open(IO_ReadOnly))
	{
		printf("ReadConfig('%s') error, file not exist!\n",sXmlFile.data());
		return false;
	}
	int filelen = file.size();
	szXMLData = new char[filelen+1];
	memset(szXMLData,0,filelen+1);
	for(nRead=0;nRead<filelen;)
	{
		int size = filelen - nRead;
		if(size > 10240)
			size = 10240;
		int ret = file.readBlock((BYTE*)(szXMLData+nRead),size);
		if(ret <= 0)
			break;
		nRead += ret;
	}
	file.close();

    szXMLData[nRead] = 0;

	char *pEncoding = strstr(szXMLData,"encoding=");
	if(pEncoding != NULL)
	{
		pEncoding += strlen("encoding=");
		if(SString::toString(pEncoding,strlen("\"UTF-8\"")).toUpper() == "\"UTF-8\"")
		{
			//UTF-8����
	#ifdef WIN32
			//Windows��ֻ��ת��һ��
			SString::Utf82Gb(szXMLData,filelen+1);
	#else
			//char *pSrc = szXMLData;
			SString sTemp,sNew = "";
			int i=0,cnt=nRead;
			int s;
			int size = 10240;//10240
			for(i=0;i<cnt;i+=s)
			{
				s = nRead-i;
				if(s > size)
					s = size;
				while(((unsigned char)szXMLData[i+s-1]) >= 128 && s > size/2)
				{
					s --;
				}
				sTemp = SString::toString(szXMLData+i,s);
				sNew += sTemp.toGb2312();
			}
			while(sNew.length() > 0 && sNew.left(1) != "<")
				sNew = sNew.mid(1);
			memset(szXMLData,0,filelen+1);
			strcpy(szXMLData,sNew.data());
	#endif
		}
	}
	if(!LoadXmlByText(szXMLData))
	{
		printf("ReadConfig('%s') error, xml syntax error!\n",sXmlFile.data());
		delete[] szXMLData;
		return false;
	}
	
	delete[] szXMLData;
	return true;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ���ı��ַ�������XML
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-24 15:10
// ����˵��:  @szXmlTextΪ�ı�����
// �� �� ֵ:  true��ʾ��ȡ�ɹ���false��ʾ��ȡʧ��
//////////////////////////////////////////////////////////////////////////
bool SXmlConfig::LoadXmlByText(char * szXmlText)
{
	SString sXmlVer="";
	SBaseConfig *pNode = this;
	SBaseConfig *pParentNode = NULL;
	char prefix;
	char *pStr;
	char sNodeName[128];
	char sAttrName[128];
	char sAttrValue[1024];

	if(szXmlText[0] != '<')
		szXmlText = strstr(szXmlText,"<");
	if(szXmlText == NULL)
		return false;

	SString sNodeValue;
	while(1)
	{
		//ȥ�ո�
		while((*szXmlText> 0 && isspace(*szXmlText) && (unsigned char)*szXmlText<0x80) && *szXmlText!='\0')
			szXmlText++;
		if(*szXmlText == '\0')
		{
			if(this->GetNodeName().length() > 0)
				break;
			else
				return false;
		}
		if (*szXmlText != '\0' && *szXmlText != '<') // �Ҳ����ڵ���ʼ��־!
		{
			if(pParentNode != NULL)
			{
				//��ȡ�ڵ�ֵ�����ڵ�
				sAttrValue[0] = '\0';
				while(*szXmlText != '<' && *szXmlText != '\0')
				{
					if(*szXmlText == '&')
					{
						if(strstr(szXmlText,"&apos;") == szXmlText)
						{
							sAttrValue[strlen(sAttrValue)+1] = '\0';
							sAttrValue[strlen(sAttrValue)] = '\'';
							szXmlText += 6;
							continue;
						}
						else if(strstr(szXmlText,"&quot;") == szXmlText)
						{
							sAttrValue[strlen(sAttrValue)+1] = '\0';
							sAttrValue[strlen(sAttrValue)] = '\"';
							szXmlText += 6;
							continue;
						}
						else if(strstr(szXmlText,"&lt;") == szXmlText)
						{
							sAttrValue[strlen(sAttrValue)+1] = '\0';
							sAttrValue[strlen(sAttrValue)] = '<';
							szXmlText += 4;
							continue;
						}
						else if(strstr(szXmlText,"&gt;") == szXmlText)
						{
							sAttrValue[strlen(sAttrValue)+1] = '\0';
							sAttrValue[strlen(sAttrValue)] = '>';
							szXmlText += 4;
							continue;
						}
						else if(strstr(szXmlText,"&amp;") == szXmlText)
						{
							sAttrValue[strlen(sAttrValue)+1] = '\0';
							sAttrValue[strlen(sAttrValue)] = '&';
							szXmlText += 5;
							continue;
						}
					}
					sAttrValue[strlen(sAttrValue)+1] = '\0';
					sAttrValue[strlen(sAttrValue)] = *szXmlText;
					szXmlText++;
				}
				pParentNode->SetNodeValueEx(sAttrValue);
				continue;
			}
			return false;
		}
		szXmlText++;
		switch(*szXmlText)
		{
			case '?': // �����汾���
				sXmlVer += "<";
				while (*szXmlText!='>' && *szXmlText!='<' && *szXmlText!='\0')
				{
					sXmlVer += *szXmlText;
					szXmlText++;
				}
				if (*szXmlText++ !='>')
				{
					return false;
				}

				sXmlVer += '>';
				break;

			case '!': // ����ע��
				//<![CDATA[content]]>
				if(strstr(szXmlText,"![CDATA[") == szXmlText)
				{
					szXmlText += 8;
					pStr = strstr(szXmlText,"]]>");
					if(pStr == NULL)
					{
						//δ�رյ�ԭʼ�ı�
						return false;
					}
					//��Ϊ��ԭʼ�ı�
					sNodeValue = SString::toString(szXmlText,pStr-szXmlText);
					pParentNode->SetNodeValueEx(sNodeValue.data());
					szXmlText = pStr + 3;
					break;
				}
				szXmlText = strstr(szXmlText,"-->");
				if(szXmlText == NULL)
				{
					return false;
				}
				szXmlText += strlen("-->");
				break;

			case '/': // �ڵ�ջ���־: </XXX>
				//��ǰ��ǰ���ڵ�
				if(pParentNode == NULL)
				{
					//û��Ҫ�رյĽڵ�
					return false;
				}
				szXmlText++;
				sNodeName[0] = '\0';
				while(!((isspace(*szXmlText) && (unsigned char)*szXmlText<0x80) || '='==*szXmlText || '\n'==*szXmlText || '>'==*szXmlText || '/' == *szXmlText || '\0' == *szXmlText))
				{
					sNodeName[strlen(sNodeName)+1] = '\0';
					sNodeName[strlen(sNodeName)] = *szXmlText;
					szXmlText ++;
				}
				if(strlen(sNodeName) == 0)
				{
					//ȱ�ٽڵ�����
					return false;
				}
				if(strcmp(sNodeName, pParentNode->m_sNodeName) != 0)
				{
					//�رսڵ�������ȷ
					return false;
				}
				//ȥ�ո�
				while((isspace(*szXmlText) && (unsigned char)*szXmlText<0x80) && *szXmlText!='\0')
					szXmlText++;
				if(*szXmlText != '>')
				{
					//�رսڵ�û�з�װ
					return false;
				}
				szXmlText++;
				pParentNode = pParentNode->GetParentNode();
				break;

			default:
				//��ȡ�ڵ���Ϣ��pNode��
				sNodeName[0] = '\0';
				while(!((isspace(*szXmlText) && (unsigned char)*szXmlText<0x80) || '='==*szXmlText || '\n'==*szXmlText || '>'==*szXmlText || '/' == *szXmlText || '\0' == *szXmlText))
				{
					sNodeName[strlen(sNodeName)+1] = '\0';
					sNodeName[strlen(sNodeName)] = *szXmlText;
					szXmlText++;
				}
				if(strlen(sNodeName) == 0)
				{
					//ȱ�ٽڵ�����
					return false;
				}
				if(pParentNode == NULL)
				{
					pNode = this;
					pNode->SetNodeNameEx(sNodeName);
				}
				else
				{
					pNode = pParentNode->AddChildNodeEx(sNodeName);
				}
				//ȥ�ո�
				while((isspace(*szXmlText) && (unsigned char)*szXmlText<0x80) && *szXmlText!='\0')
					szXmlText++;
				//��ȡ����
				while(*szXmlText != '>' && *szXmlText != '/' && *szXmlText != '\0')
				{
					sAttrName[0] = '\0';
					while(!((isspace(*szXmlText) && (unsigned char)*szXmlText<0x80) || '='==*szXmlText || '\n'==*szXmlText || '>'==*szXmlText || '/' == *szXmlText))
					{
						sAttrName[strlen(sAttrName)+1] = '\0';
						sAttrName[strlen(sAttrName)] = *szXmlText;
						szXmlText++;
					}
					if(sAttrName[0] == '\0' || *szXmlText == '\0')
					{
						//ȱ��������
						return false;
					}
					//ȥ�ո�
					while((isspace(*szXmlText) && (unsigned char)*szXmlText<0x80) && *szXmlText!='\0')
						szXmlText++;
					if(*szXmlText != '=')
					{
						//ȱ������=
						return false;
					}
					szXmlText++;
					//ȥ�ո�
					while((isspace(*szXmlText) && (unsigned char)*szXmlText<0x80) && *szXmlText!='\0')
						szXmlText++;
					if(*szXmlText != '\'' && *szXmlText != '\"')
					{
						//ȱ������ֵ������
						return false;
					}
					prefix = *szXmlText;
					szXmlText++;
					sAttrValue[0] = '\0';
					while(*szXmlText != prefix && *szXmlText != '\0')
					{
						if(*szXmlText == '&')
						{
							if(strstr(szXmlText,"&apos;") == szXmlText)
							{
								sAttrValue[strlen(sAttrValue)+1] = '\0';
								sAttrValue[strlen(sAttrValue)] = '\'';
								szXmlText += 6;
								continue;
							}
							else if(strstr(szXmlText,"&quot;") == szXmlText)
							{
								sAttrValue[strlen(sAttrValue)+1] = '\0';
								sAttrValue[strlen(sAttrValue)] = '\"';
								szXmlText += 6;
								continue;
							}
							else if(strstr(szXmlText,"&lt;") == szXmlText)
							{
								sAttrValue[strlen(sAttrValue)+1] = '\0';
								sAttrValue[strlen(sAttrValue)] = '<';
								szXmlText += 4;
								continue;
							}
							else if(strstr(szXmlText,"&gt;") == szXmlText)
							{
								sAttrValue[strlen(sAttrValue)+1] = '\0';
								sAttrValue[strlen(sAttrValue)] = '>';
								szXmlText += 4;
								continue;
							}
							else if(strstr(szXmlText,"&amp;") == szXmlText)
							{
								sAttrValue[strlen(sAttrValue)+1] = '\0';
								sAttrValue[strlen(sAttrValue)] = '&';
								szXmlText += 5;
								continue;
							}
						}
						sAttrValue[strlen(sAttrValue)+1] = '\0';
						sAttrValue[strlen(sAttrValue)] = *szXmlText;
						szXmlText++;
					}
					if(*szXmlText != prefix)
					{
						//����ֵû�н���
						return false;
					}
					pNode->SetAttributeEx(sAttrName,sAttrValue);
					szXmlText++;
					//ȥ�ո�
					while((isspace(*szXmlText) && (unsigned char)*szXmlText<0x80) && *szXmlText!='\0')
						szXmlText++;
				}//end while
				if(*szXmlText == '/')
				{
					//���¼��ڵ㼰�ڵ�ֵ�������رյ�ǰ�ڵ�
					szXmlText++;
					if(*szXmlText != '>')
					{
						//'/'��û�и�'>'
						return false;
					}
					szXmlText++;
					pParentNode = pNode->GetParentNode();
					break;
				}
				if(*szXmlText != '>' )
				{
					//�ڵ�δ�ر�
					return false;
				}
				szXmlText++;
				//��ȡ�¼��ڵ�
				pParentNode = pNode;				
				break;
		}
		
	}
	return true;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ���ı��ַ�������XML
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-24 15:10
// ����˵��:  @sXmlTextΪ�ı�����
// �� �� ֵ:  true��ʾ��ȡ�ɹ���false��ʾ��ȡʧ��
//////////////////////////////////////////////////////////////////////////
bool SXmlConfig::ReadText(char* sXmlText)
{
	return LoadXmlByText(sXmlText);
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  �õ�ǰʵ������XML�����ļ�
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-24 15:11
// ����˵��:  @sXmlFileΪĿ���ļ���
//            @sEncoding�ַ�������,ȱʡΪGB
// �� �� ֵ:  true��ʾ����ɹ���falseΪʧ��
//////////////////////////////////////////////////////////////////////////
bool SXmlConfig::SaveConfig(SString sXmlFile,SString sEncoding/*="GB2312"*/)
{
	if(sEncoding.compareNoCase("UTF-8") == 0)
		m_iEncodeing = STR_ENCODING_UTF8;
	else
		m_iEncodeing = STR_ENCODING_GB2312;
	SFile file(sXmlFile);
	if(!file.open(IO_Truncate))
		return false;

	int level=0;
	if(m_iEncodeing == STR_ENCODING_UTF8)
		file.writeString("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
	else
		file.writeString("<?xml version=\"1.0\" encoding=\""+sEncoding+"\"?>\r\n");
	SaveNode(file,this,level);

	return true;
}

////////////////////////////////////////////////////////////////////////
// ��    ��:  ����ָ���Ľڵ�
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-24 15:12
// ����˵��:  @fileΪ�ļ�ʵ��
//            @pNodeΪ�ڵ�ʵ��
//            @levelΪ��ǰ����
// �� �� ֵ:  
//////////////////////////////////////////////////////////////////////////
bool SXmlConfig::SaveNode(SFile &file,SBaseConfig *pNode,int &level)
{
	SString sLine;
	SString sTab;
	int i,cnt = pNode->GetChildCount();
	sTab = "";
	for(i=0;i<level;i++)
		sTab += "\t";
	sLine.sprintf("%s<%s ",sTab.data(),pNode->GetNodeName().data());
	if(m_iEncodeing == STR_ENCODING_UTF8)
		sLine = sLine.toUtf8();
	file.writeString(sLine);
	int cols = pNode->GetAttributeCount();
	for(i=0;i<cols;i++)
	{
		if(pNode->GetAttributeName(i).length() > 0)
		{
			sLine.sprintf("%s=\"%s\" ",pNode->GetAttributeName(i).data(),pNode->GetAttribute(pNode->GetAttributeName(i)).data());
			if(m_iEncodeing == STR_ENCODING_UTF8)
				sLine = sLine.toUtf8();
			file.writeString(sLine);
		}
	}
#if 1
	if(cnt == 0 && pNode->GetNodeValue() == "")
	{
		file.writeString("/>\r\n");
		return true;
	}
	else if(pNode->GetNodeValue() != "")
	{
		file.writeString(">");
	}
	else
		file.writeString(">\r\n");
#else
	if(cnt == 0)
	{
		file.writeString(">");
	}
	else
		file.writeString(">\r\n");
#endif
	//node value
	if(pNode->GetNodeValue() != "")
	{
		sLine.sprintf("%s",pNode->GetNodeValue().data());
		if(m_iEncodeing == STR_ENCODING_UTF8)
			sLine = sLine.toUtf8();
		file.writeString(sLine);

	}
	if(cnt > 0)
	{
		for(i=0;i<cnt;i++)
		{
			level ++;
			SBaseConfig *p = pNode->GetChildNode(i);
			SaveNode(file,p,level);
			level --;
		}
		sLine.sprintf("%s</%s>\r\n",sTab.data(),pNode->GetNodeName().data());
		if(m_iEncodeing == STR_ENCODING_UTF8)
			sLine = sLine.toUtf8();
		file.writeString(sLine);
	}
	else
	{
		sLine.sprintf("</%s>\r\n",pNode->GetNodeName().data());
		if(m_iEncodeing == STR_ENCODING_UTF8)
			sLine = sLine.toUtf8();
		file.writeString(sLine);
	}
	return true;
}

