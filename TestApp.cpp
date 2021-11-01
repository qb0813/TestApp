// TestApp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "DirOper.h"
#include "ComomFunction.h"

void ShowMenu();

int main()
{
    //ShowMenu();

    DirOper tDirOper;
    //tDirOper.SetOutPutPath("D:\\Test");
    //tDirOper.MakeTemplateDir(E_TemplateType::SSR_STARS);

    //tDirOper.SetIconForDir("D:\\Test\\★★_N");

    //tDirOper.listDirectory("D:\\Test\\*");

    //tDirOper.RenameFile("D:\\Test\\*", "哈哈");

    while (1)
    {
        ShowMenu();
        int iFunction = -1;
        std::cin >> iFunction;
        std::cin.ignore();
        std::string sCommand;
        std::vector<std::string> vecCommand;
        sCommand.clear();
        vecCommand.clear();
        switch (iFunction)
        {
        case 1:
        {
            std::cout << "请输入生成目录和模板名" << std::endl;
            std::cout << "e.g. D:\\Test | SSR_STARS" << std::endl;
            std::cin >> sCommand;
            std::cin.ignore();
            split(sCommand, vecCommand, "|");
            if (vecCommand.size() != 2)
            {
                std::cerr << "Invalid Param number = " << vecCommand.size() << std::endl;
                break;
            }
            tDirOper.SetOutPutPath(vecCommand[0]);
            tDirOper.MakeTemplateDir(mapTemplateType.at(vecCommand[1]));
            break;
        }
        case 2:
        {
            std::cout << "请输入需要应用图标的目录" << std::endl;
            std::cout << "功能说明: 将对指定目录下所有文件夹应用图标" << std::endl;
            char chrCmd[1024] = { 0 };
            std::cin.getline(chrCmd, sizeof(chrCmd));
            sCommand = chrCmd;
            std::string sPrefix = sCommand + "\\";
            sCommand += "\\*";
            std::vector<std::string> vecApplyDir;
            vecApplyDir = tDirOper.listDirectory(sCommand);
            for (auto& val : vecApplyDir)
            {
                tDirOper.SetIconForDir(sPrefix + val);
            }
            std::cout << "如果没有生效请清理C盘缩略图缓存" << std::endl;
            break;
        }   
        default:
            std::cout << "Undefined Command!!!" << std::endl;
        }
    }

    return 1;
}

void ShowMenu()
{
    std::cout << "================测试系统 version 1.0.0===================" << std::endl;

    std::cout << "1. 按模板生成目录" << std::endl;
    std::cout << "2. 指定目录应用图标" << std::endl;

    std::cout << "请输入需要执行的功能:" << std::endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
