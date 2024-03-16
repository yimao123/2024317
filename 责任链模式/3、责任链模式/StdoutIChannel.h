#pragma once
#include "IChannel.h"
class StdoutIChannel :
	public IChannel
{
	//重构标准输出不需要重写getNextStep()函数
public:
	StdoutIChannel();
	virtual ~StdoutIChannel();
	// 通过 IChannel 继承
	virtual bool init(void) override;
	virtual bool fini(void) override;
	virtual string readFd(string & data) override;
	virtual bool writeFd(string & data) override;
	virtual int getFd(void) override;

	// 通过 IChannel 继承
	virtual AZinxHandler * getNextStep(AZinxMsg & _msg) override;
};

