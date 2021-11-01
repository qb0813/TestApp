#include "DirOper.h"

#include <Windows.h>
#include <iostream>
#include <direct.h>
#include <io.h>

bool DirOper::SetOutPutPath(std::string sPath)
{
    std::cout << "SetOutPutPath = [" << sPath << "]" << std::endl;
    
    m_sOutPath = sPath;

    CreateDirectoryA(m_sOutPath.c_str(), NULL);

    return true;
}

bool DirOper::MakeTemplateDir(E_TemplateType eType)
{
    bool bRet = true;
    std::string sDirPrefix = m_sOutPath;

    switch (eType)
    {
    case E_TemplateType::SSR:
        m_vecDirName = vecSSRType;
        break;
    case E_TemplateType::STARS:
        m_vecDirName = vecSTARSType;
        break;
    case E_TemplateType::SSR_STARS:
        m_vecDirName = vecSSR_STARSType;
        break;
    default:
        std::cerr << "ERROR!!! Unknown Template!!!" << std::endl;
    }

    for (auto& val : m_vecDirName)
    {
        std::string sDirName = sDirPrefix + "\\" + val;
        std::cout << "Current Creating " << sDirName << std::endl;
        
        //// method 1:
        //std::string sCommand = "mkdir -p " + sDirName;
        //system(sCommand.c_str());

        //// method 2:
        //if (0 != _access(sDirName.c_str(), 0))
        //{
        //    bRet = _mkdir(sDirName.c_str());
        //}

        bRet = CreateDirectoryA(sDirName.c_str(), NULL);
    }

    return bRet;
}

bool DirOper::SetIconForDir(std::string sPath)
{
    if(GetFileAttributesA(sPath.c_str()) != INVALID_FILE_ATTRIBUTES)
    {
        std::string sIconName = getPostFixByKey(".ico", sPath);
        std::string sIconPath = sPath + "\\" + sIconName;
        std::string sIniPath = sPath + "\\desktop.ini";
        if (GetFileAttributesA(sIconPath.c_str()) != INVALID_FILE_ATTRIBUTES)
        {
            SetFileAttributesA(sIconPath.c_str(), FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_HIDDEN);
            if (WritePrivateProfileStringA(".ShellClassInfo", "IconResource", sIconName.c_str(), sIniPath.c_str()) == TRUE)
            {
                SetFileAttributesA(sIniPath.c_str(), FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_HIDDEN);
                std::cout << "Folder iCon setting success!" << std::endl;
            }
            else
            {
                std::cout << "Folder icon setting failed!" << std::endl;
            }
        }
    }

    if (sPath.find(" ") != std::string::npos)
    {
        sPath = '"' + sPath + '"';
    }

    std::string sCommand = "attrib " + sPath  + " +s /d";
    std::cout << "Command = " << sCommand << std::endl;
    system(sCommand.c_str());

    return true;
}

std::vector<std::string> DirOper::listDirectory(std::string sPath)
{
    std::cout << "listDirectoryBegin:: Path = " << sPath << std::endl;
    std::vector<std::string> vecDirName;

    HANDLE hFind;
    WIN32_FIND_DATAA findData;
    hFind = FindFirstFileA(sPath.c_str(), &findData);
    if (hFind == INVALID_HANDLE_VALUE)
    {
        std::cout << "Failed to find first file!\n";
       
    }
    else
    {
        do
        {
            // 忽略 "." 和 ".." 两个结果
            if (strcmp(findData.cFileName, ".") == 0 || strcmp(findData.cFileName, "..") == 0)
            {
                continue;
            }
            if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) // 是否目录
            {
                vecDirName.push_back(findData.cFileName);
                std::cout << findData.cFileName << std::endl;
            }
        } while (FindNextFileA(hFind, &findData));
    }

    return vecDirName;
}

std::string DirOper::getPostFixByKey(std::string sKey, std::string sPath)
{
    sPath.append("\\*");

    HANDLE hFind;
    WIN32_FIND_DATAA findData;
    hFind = FindFirstFileA(sPath.c_str(), &findData);
    if (hFind == INVALID_HANDLE_VALUE)
    {
        std::cout << "Failed to find fist file in Dir " << sPath << std::endl;
    }
    else
    {
        do
        {
            if (strcmp(findData.cFileName, ".") == 0 || strcmp(findData.cFileName, "..") == 0)
            {
                continue;
            }
            if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                std::cout << "skip Dir" << findData.cFileName << std::endl;
            }
            else
            {
                std::string sName = findData.cFileName;
                if (sName.find(sKey) != std::string::npos)
                {
                    std::cout << "Find File " << sName << std::endl;
                    return sName;
                }
            }

        } while (FindNextFileA(hFind, &findData));
    }
    return std::string();
}
