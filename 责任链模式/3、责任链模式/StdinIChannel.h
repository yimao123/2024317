#pragma once
#include "IChannel.h"
class StdinIChannel:public IChannel
{
public:
	StdinIChannel();
	~StdinIChannel();
	virtual bool init(void) override;
	//����
	virtual bool fini(void) override;
	//������д
	virtual string readFd(string &data) override;
	virtual bool  writeFd(string &data) override;
	//��ȡ�ļ�������
	virtual int getFd(void) override;
	//ͨ���ع�ͨ���̳�


	// ͨ�� IChannel �̳�
	virtual AZinxHandler * getNextStep(AZinxMsg & _msg) override;

};

