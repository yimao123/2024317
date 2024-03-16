#include "StdinIChannel.h"
#include <unistd.h>
StdinIChannel::StdinIChannel()
{
}

StdinIChannel::~StdinIChannel()
{
}

bool StdinIChannel::init(void)
{
	return true;
}

bool StdinIChannel::fini(void)
{
	return true;
}

string StdinIChannel::readFd(string & data)
{
	//标准输入读事件
	cin >> data;
	cout << "StdinChannel readFd:" << data << endl;
	//数据处理
	//dataProcess(data);/因重构而失效
	return data;
}

bool StdinIChannel::writeFd(string & data)
{
	//写事件在此通道关闭
	return false;
}

int StdinIChannel::getFd(void)
{
	//文件描述符为监听事件复制

	return STDIN_FILENO;//监听标准输入读事件阻塞的缓冲区
}

AZinxHandler * StdinIChannel::getNextStep(AZinxMsg & _msg)
{
	return pNextHandler;
}
