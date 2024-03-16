#pragma once
#include "IChannel.h"
//核心框架类Epoll模型封装
//监视标准输入（读),监视标准输出（写），监视管道（读写）
class ZinxKernel
{
	//添加监视通道类
public:
	ZinxKernel();
	virtual ~ZinxKernel();
	//获取静态数据成员的值。实例与静态成员时对应的，（考虑单例模式）
	//获取实例值mZinx值
	static ZinxKernel *getInstance(void);
	//初始化
	bool init(void);
	//上树
	bool addChannel(IChannel *_channel);
	//下树
	bool delChannel(IChannel *_channel);
	//监视读事件
	bool modChannelIn(IChannel *_channel);
	//监视写事件
	bool modChannelOUt(IChannel *_channel);
	//改变消息I/O的方向
	//循环监视
	bool run();
	//释放
	bool destroy();
	//重构新添加函数
	//改变消息的IO方向，同时修改监听的事件
	bool dataSendOut(IChannel *_channel, string &_data);
private:
	int mEpollFd = -1;
	//静态指针
	static ZinxKernel *mZinx;
};

