#pragma once

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

private:
	std::string m_sOutPath;
	std::vector<std::string> m_vecDirName;

};

