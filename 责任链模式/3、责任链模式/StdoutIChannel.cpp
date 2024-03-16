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
	//读操作属于标准输入
	return string();
}

bool StdoutIChannel::writeFd(string & data)
{
	//标准输出
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
