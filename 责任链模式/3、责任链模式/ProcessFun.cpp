#include "ProcessFun.h"
#include <algorithm>
#include "ZinxKernel.h"
#include <string.h>



ProcessFun::ProcessFun()
{
}

ProcessFun::~ProcessFun()
{
}

//void ProcessFun::dataProc(string data)
//{

//}

string ProcessFun::upperOut(string & data)
{//双引号表示全局作用域
	transform(data.begin(), data.end(), data.begin(), ::toupper);
	
	return data;
}

string ProcessFun::origOut(string &out)
{
	//pOut->dataSendOUt(out);
	return out;
}

AZinxMsg * ProcessFun::internelHandle(AZinxMsg & _msg)
{
	UserMsg *pMsg = static_cast<UserMsg*>(&_msg);
		if (pMsg->mData[0] >= 'a'&&pMsg->mData[0] <= 'z')
	{
		upperOut(pMsg->mData);
	}
	else
	{
		origOut(pMsg->mData);
	}
		cout << "2、大写表示:  " << pMsg->mData << endl;
		UserMsg *pUserMsg = new UserMsg;
		pUserMsg->mData = pMsg->mData;
		pUserMsg->mLen = pMsg->mData.length();
		return pUserMsg;
	
}

AZinxHandler * ProcessFun::getNextHangler(AZinxMsg & _msg)
{
	
	return pNextHandler;
}

SizeData::SizeData()
{
}

SizeData::~SizeData()
{
}

AZinxMsg * SizeData::internelHandle(AZinxMsg & _msg)
{
	//计算字符串长度
	//类型转换只是为了改变读取的步长，并没有改变数据类型的内部结构
	UserMsg * pMsg = static_cast<UserMsg*>(&_msg);
	cout << "1.Strlen:  " << pMsg->mData.length() << endl;
	UserMsg * pUser = new UserMsg;
	pUser->mData = pMsg->mData;
	pUser->mLen = pMsg->mData.length();
	
	return pUser;
}

AZinxHandler * SizeData::getNextHangler(AZinxMsg & _msg)
{
	return pNextHandler;
}

AciiData::AciiData()
{
}

AciiData::~AciiData()
{
}

AZinxMsg * AciiData::internelHandle(AZinxMsg & _msg)
{
	//3、输出ACII码值
	UserMsg *pMsg = static_cast<UserMsg*>(&_msg);
	char buf[128];
	for (int i = 0; i < pMsg->mData.length(); i++)
	{
		sprintf(&buf[i * 2], "%02x", pMsg->mData[i]);
	}
	cout << "3、ASCII： " << buf << endl;
	//pOut->dataProcess(pMsg->mData);
	UserMsg *pUserMsg = new UserMsg;
	pUserMsg->mLen = strlen(buf);
	pUserMsg->mData = buf;

	return pUserMsg;
}

AZinxHandler * AciiData::getNextHangler(AZinxMsg & _msg)
{
	UserMsg *pMsg = static_cast<UserMsg*>(&_msg);
	//类内调用实例对象
	ZinxKernel::getInstance()->dataSendOut(pNextHandler, pMsg->mData);
	return nullptr;
}
