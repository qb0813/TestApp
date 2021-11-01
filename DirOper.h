#pragma once

#ifndef _DIROPER_H
#define _DIROPER_H

#include <string>
#include <vector>
#include "DirTemplate.h"

class DirOper
{
public:
	// ���캯��
	DirOper()
	{
		m_sOutPath.clear();
		m_vecDirName.clear();
	}

	// ��������
	~DirOper()
	{
	}

	// �������Ŀ¼
	bool SetOutPutPath(std::string sPath);

	// ��ָ��ģ���ʽ����Ŀ¼
	bool MakeTemplateDir(E_TemplateType eType);

	// �޸�ָ��Ŀ¼�ļ���ͼ��
	bool SetIconForDir(std::string sPath);

	// ����ָ��Ŀ¼�������ļ�����
	std::vector<std::string> listDirectory(std::string sPath);

	// ��ȡָ����¼��, ָ����׺�ĵ�һ���ļ���
	std::string getPostFixByKey(std::string sKey, std::string sPath);

private:
	std::string m_sOutPath;
	std::vector<std::string> m_vecDirName;

};

#endif