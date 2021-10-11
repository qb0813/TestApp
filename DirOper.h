#pragma once

#include <string>
#include <vector>
#include "DirTemplate.h"

class DirOper
{
public:
	// 构造函数
	DirOper()
	{
		m_sOutPath.clear();
		m_vecDirName.clear();
	}

	// 析构函数
	~DirOper()
	{
	}

	// 设置输出目录
	bool SetOutPutPath(std::string sPath);

	// 按指定模板格式创建目录
	bool MakeTemplateDir(E_TemplateType eType);

	// 修改指定目录文件夹图标
	bool SetIconForDir(std::string sPath);

private:
	std::string m_sOutPath;
	std::vector<std::string> m_vecDirName;

};

