#pragma once
#include <iostream>
//前向声明
#include "AZinxHandler.h"
using namespace std;
//既然每个处理者都有自己的数据信息
//那么就可以将
//带方向的系统消息抽象到核心类中作为基类
/*核心类中在添加三个方法可以类比链表
1、主控制函数，基类不虚函数
2、纯虚函数，内部处理函数，
3、纯虚函数：获取下一个处理者的通道指针或者处理者指针*/
//带有方向的系统消息类
class SysIoMsg : public AZinxMsg
{//枚举值
public:
	enum SysIo { IO_IN, IO_OUT }sysIo;
};
//用户数据信息
class UserMsg : public SysIoMsg
{
public:
	string mData;
	int mLen;
};
//处理
//通道属性（功能）的处理封装
//将标准输入、标准输出、管道的特性封装成一个基类
//抽象通道类继承处理者类，实现三个纯虚函数
class IChannel :public AZinxHandler
{
public:
	IChannel();
	virtual ~IChannel();
	//初始化
	virtual bool init(void) = 0;
	//销毁
	virtual bool fini(void) = 0;
	//泛化读写
	virtual string readFd(string &data) = 0;
	virtual bool  writeFd(string &data) = 0;
	//通道重构新添加函数
	virtual AZinxHandler *getNextStep(AZinxMsg &_msg) = 0;
	
	//获取文件描述符
	virtual int getFd(void) = 0;
	//数据处理
	void dataProcess(string data);
	//数据发送
	void dataSendOUt(string data);
	//刷新缓冲区
	void fflushOut(void);
	// 通过 AZinxHandler 继承
	virtual AZinxMsg * internelHandle(AZinxMsg & _msg) override;
	virtual AZinxHandler * getNextHangler(AZinxMsg & _msg) override;
public:
	AZinxHandler *pNextHandler = nullptr;//自关联//参考链表

	//缓冲区
	string mBuf;


};

