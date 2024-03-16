#include "ZinxKernel.h"
#include <sys/epoll.h>
#include <cstring>
#include <unistd.h>
//将修改监听事件实例化是优化的结果
//否则直接使用类成员方法修改即可，不构成单例模式
//静态成员初始化，预处理阶段
ZinxKernel *ZinxKernel::mZinx = new ZinxKernel;
ZinxKernel::ZinxKernel()
{
}

ZinxKernel::~ZinxKernel()
{
}
//获取静态实例
ZinxKernel * ZinxKernel::getInstance(void)
{
	return mZinx;
}
//创建专用文件描述符
bool ZinxKernel::init(void)
{//创建专用的文件描述符
	mEpollFd = epoll_create(1024);
	if (-1 == mEpollFd)
	{
		perror("epoll_create");
		return false;
	}
	return true;
}

bool ZinxKernel::addChannel(IChannel * _channel)
{
	struct epoll_event e;
	memset(&e, 0, sizeof(e));
	e.events = EPOLLIN;

	e.data.ptr = _channel;


	int ret = epoll_ctl(mEpollFd, EPOLL_CTL_ADD, _channel->getFd(), &e);
	if (-1 == ret)
	{
		perror("epoll_ctl");
		return false;
	}

	return true;
}

bool ZinxKernel::delChannel(IChannel * _channel)
{
	int ret = -1;
	ret = epoll_ctl(mEpollFd, EPOLL_CTL_DEL, _channel->getFd(), NULL);
	if (-1 == ret)
	{
		perror("epoll_ctl");
		return false;
	}
	return true;
}

bool ZinxKernel::modChannelIn(IChannel * _channel)
{
	int ret = -1;
	struct epoll_event e;
	memset(&e, 0, sizeof(e));
	e.events = EPOLLIN;
	e.data.ptr = _channel;
	ret = epoll_ctl(mEpollFd, EPOLL_CTL_MOD, _channel->getFd(), &e);
	if (-1 == ret)
	{
		perror("epoll_ctl");
		return false;
	}
	return true;
}

bool ZinxKernel::modChannelOUt(IChannel * _channel)
{
	int ret = -1;
	struct epoll_event e;
	memset(&e, 0, sizeof(e));
	e.events = EPOLLOUT;
	e.data.ptr = _channel;//监听标准输出写事件，并将通道指针付给ptr
	ret = epoll_ctl(mEpollFd, EPOLL_CTL_MOD, _channel->getFd(), &e);
	if (-1 == ret)
	{
		//错误原因：
		/*
		1、本实例对象的未作初始化
		2、一个对象去修改另一个对象的成员本身应该是非法的，对象之间独立*/
		perror("epoll_ctl");
		return false;
	}
	
	return true;
}

bool ZinxKernel::run()
{
	//循环监视
	struct epoll_event re[100];//定义传出事件监听集合
	AZinxHandler *pHandler = nullptr;//通道指针
	IChannel *pChannel = nullptr;
	int count = 0;
	while (1)
	{
		int ret = epoll_wait(mEpollFd, re, sizeof(re) / sizeof(struct epoll_event), 3000);
		if (-1 == ret)
		{
			perror("epoll_wait");
			break;
		}
		else if (0 == ret)
		{
			cout << "3秒等待即时" << endl;
			continue;
		}
		else
		{
			count = ret;
			for (int i = 0; i < count; i++)
			{
				if (re[i].events&EPOLLIN)
				{
					string str;
					pHandler = static_cast<IChannel*>(re[i].data.ptr);
					SysIoMsg *pSysloMsg = new SysIoMsg;
					pSysloMsg->sysIo = SysIoMsg::IO_IN;
					//传出参数//首先进来监听终端的读事件
					pHandler->handle(*pSysloMsg);
					
				}
				else
				{
					//写事件//通道添加标准输入通道
					//将在树上且符合写事件的的通道指针付给pChannel,刷新
					pChannel = static_cast<IChannel*>(re[i].data.ptr);
					pChannel->fflushOut();
					//标准输出文件描述符一直带有写属性，必须改变监视事件事件才能杜绝触发写事件
					ZinxKernel::getInstance()->modChannelIn(pChannel);
				}
			}
		}
	}
	return false;
}

bool ZinxKernel::destroy()
{
	if (mEpollFd > 0)
	{
		close(mEpollFd);
	}
	return false;
}

bool ZinxKernel::dataSendOut(IChannel * _channel, string & _data)
{
	//通道缓冲区
	_channel->mBuf = _data;
	//修改监听的事件为写事件
	modChannelOUt(_channel);
	return true;
}
