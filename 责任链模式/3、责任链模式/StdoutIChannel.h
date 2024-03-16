#pragma once
#include "IChannel.h"
class StdoutIChannel :
	public IChannel
{
	//�ع���׼�������Ҫ��дgetNextStep()����
public:
	StdoutIChannel();
	virtual ~StdoutIChannel();
	// ͨ�� IChannel �̳�
	virtual bool init(void) override;
	virtual bool fini(void) override;
	virtual string readFd(string & data) override;
	virtual bool writeFd(string & data) override;
	virtual int getFd(void) override;

	// ͨ�� IChannel �̳�
	virtual AZinxHandler * getNextStep(AZinxMsg & _msg) override;
};

