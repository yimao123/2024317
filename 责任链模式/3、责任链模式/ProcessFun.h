#pragma once
#include "IChannel.h"
#include "AZinxHandler.h"
#if 0



class UserMsg : public AZinxMsg
{
public:
	string mData;
	int mLen;
};
#endif // 0

//2|添加模块输出字符串大小
class SizeData : public AZinxHandler
{
public:
	SizeData();
	~SizeData();


	// 通过 AZinxHandler 继承
	virtual AZinxMsg * internelHandle(AZinxMsg & _msg) override;

	virtual AZinxHandler * getNextHangler(AZinxMsg & _msg) override;
public:
	AZinxHandler *pNextHandler = nullptr;

};
//3、添加模块，输出ACII值
class AciiData : public AZinxHandler
{
public:
	AciiData();
	~AciiData();
	virtual AZinxMsg * internelHandle(AZinxMsg & _msg) override;
	virtual AZinxHandler * getNextHangler(AZinxMsg & _msg) override;
public:
	IChannel *pNextHandler= nullptr;

	// 通过 AZinxHandler 继承
	
};
class ProcessFun : public AZinxHandler
{
public:
	ProcessFun();
	virtual ~ProcessFun();
	// 通过 AZinxHandler 继承
	virtual AZinxMsg * internelHandle(AZinxMsg & _msg) override;
	virtual AZinxHandler * getNextHangler(AZinxMsg & _msg) override;
private:
	//大小写转换处理函数
	string upperOut(string &data);
	//原文输出
	string origOut(string &out);
public:
	AZinxHandler* pNextHandler = nullptr;

	
};

