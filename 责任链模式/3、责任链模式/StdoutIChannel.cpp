#include "StdoutIChannel.h"
#include <unistd.h>
StdoutIChannel::StdoutIChannel()
{
}

StdoutIChannel::~StdoutIChannel()
{
}

bool StdoutIChannel::init(void)
{
	return true;
}

bool StdoutIChannel::fini(void)
{
	return true;
}

string StdoutIChannel::readFd(string & data)
{
	//���������ڱ�׼����
	return string();
}

bool StdoutIChannel::writeFd(string & data)
{
	//��׼���
	cout << "StdoutIChannel:writeFd:" << data << endl;

	return true;
}

int StdoutIChannel::getFd(void)
{
	return STDOUT_FILENO;
}

AZinxHandler * StdoutIChannel::getNextStep(AZinxMsg & _msg)
{
	return nullptr;
}
