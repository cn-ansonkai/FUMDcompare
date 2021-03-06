// MDcompare.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "Fmdapi.h"
#include "Fmdspi.h"
#include "CMDApi.h"
#include "CMDSpi.h"
#include <iostream>
#include <thread>
#include "ConfigParse.h"

using namespace std;

//线程分支入口，通过不同的apitype标示，调用不同的api初始化
void mdtest(int num, string apitype)
{
	if (apitype.compare("ctp") == 0)
	{
		cout << "" << endl;
		cout << "启动第" << num << "个进程。" << "使用API为：" << apitype << endl;
		CMDapi* pMDApi = new CMDapi(num);
		pMDApi->Init();
	}
	else if (apitype.compare("femas") == 0)
	{
		cout << "" << endl;
		cout << "启动第" << num << "个进程。" << "使用API为：" << apitype << endl;
		Fmdapi* pMDApi = new Fmdapi(num);
		pMDApi->Init();
	}
	else
	{

		cout << "API类型设置有误，请检查，填写类型为：" << apitype << endl;
	}

}

//主程序段
int main()
{

	//创建ini文件读取实例
	ConfigParse* configset = new ConfigParse("MDconfig.ini");


	//声明两个字符串，用于对比config配置想要使用的api类型
	string apitype1;
	string apitype2;
	apitype1 = configset->readsetstring("apitype1");
	apitype2 = configset->readsetstring("apitype2");

	//按序启动两个对比进程
	thread t1(mdtest, 1, apitype1);
	t1.join();
	thread t2(mdtest, 2, apitype2);
	t2.join();

	getchar();

    return 0;
}


