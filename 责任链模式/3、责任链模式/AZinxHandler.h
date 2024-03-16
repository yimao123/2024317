#pragma once
#include <iostream>
//消息类基类

class AZinxMsg
{
public:
	AZinxMsg();
	~AZinxMsg();
};
//处理者基类包含了通道类和普通定义处理类
class AZinxHandler
{
	//这个类重构之前就有了
	//重构的只是
	/*
	1、通道类共有继承处理者类，加入处理信息的一员
	2、加入通道类的方向，信息基类->带方向的信息类->处理者信息类
	*/
public:
	AZinxHandler();
	~AZinxHandler();
	//处理函数//床送数据，包括自定义数据类型，最好用
	//处理者入口函数
	void handle(AZinxMsg &_msg);
	//处理者内部处理函数
	virtual AZinxMsg *internelHandle(AZinxMsg &_msg) = 0;
	//获取下一个处理者函数
	virtual AZinxHandler *getNextHangler(AZinxMsg &_msg) = 0;

};