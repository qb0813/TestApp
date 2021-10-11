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
        std::string sIconPath = sPath + "\\icon.ico";
        std::string sIniPath = sPath + "\\desktop.ini";
        if (GetFileAttributesA(sIconPath.c_str()) != INVALID_FILE_ATTRIBUTES)
        {
            SetFileAttributesA(sIconPath.c_str(), FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_HIDDEN);
            if (WritePrivateProfileStringA(".ShellClassInfo", "IconResource", "icon.ico", sIniPath.c_str()) == TRUE)
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

    std::string sCommand = "attrib " + sPath + " +s /d";
    std::cout << "Command = " << sCommand << std::endl;
    system(sCommand.c_str());

    return true;
}
