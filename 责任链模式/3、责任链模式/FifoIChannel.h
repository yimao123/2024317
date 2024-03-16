#pragma once
#include "IChannel.h"
class FifoIChannel :
	public IChannel
{
public:
	FifoIChannel();
	FifoIChannel(string _fileName);
	virtual ~FifoIChannel();




	// ͨ�� IChannel �̳�
	virtual bool init(void) override;

	virtual bool fini(void) override;

	virtual string readFd(string & data) override;

	virtual bool writeFd(string & data) override;

	virtual int getFd(void) override;
private:
	int m_Fd = -1;
	string m_FileName;

};

