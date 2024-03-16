#pragma once
#include "IChannel.h"
class StdinIChannel:public IChannel
{
public:
	StdinIChannel();
	~StdinIChannel();
	virtual bool init(void) override;
	//销毁
	virtual bool fini(void) override;
	//泛化读写
	virtual string readFd(string &data) override;
	virtual bool  writeFd(string &data) override;
	//获取文件描述符
	virtual int getFd(void) override;
	//通过重构通道继承


	// 通过 IChannel 继承
	virtual AZinxHandler * getNextStep(AZinxMsg & _msg) override;

};

