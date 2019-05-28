// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

//CTP的头文件定义
#include <ThostFtdcMdApi.h>
#include <ThostFtdcUserApiDataType.h>
#include <ThostFtdcUserApiStruct.h>

//femas的头文件定义
#include <USTPFtdcUserApiDataType.h>
#include <USTPFtdcUserApiStruct.h>
#include <USTPFtdcMduserApi.h>

#pragma comment(lib,"thostmduserapi.lib")
#pragma comment(lib, "USTPmduserapiAF.lib")

// TODO: 在此处引用程序需要的其他头文件
