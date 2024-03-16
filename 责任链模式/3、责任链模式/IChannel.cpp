#include "IChannel.h"
#include "ZinxKernel.h"
#include "ProcessFun.h"
IChannel::IChannel()
{
	mBuf.clear();
	
}

IChannel::~IChannel()
{
}


void IChannel::dataProcess(string data)
{
	//数据处理两种方案，1、读完了就完了，不做处理，2、种通道关联指针不为空交给他处理
	if (nullptr == pNextHandler)
	{
		dataSendOUt(data);
		return;//通道指针为空，监视读事件
	}
	
	UserMsg *pMsg = new UserMsg;
	pMsg->mData = data;
	pMsg->mLen = data.length();
	pNextHandler->handle(*pMsg);
	delete pMsg;
}

void IChannel::dataSendOUt(string data)
{
	//pOut自关联通道指针将数据归置到通道关联的缓冲区
	//改变二次通道指针的监听事件，进入循环监听
	//发送数据
	mBuf.append(data);
	//写监视事件
	//将通道对象监视写事件
	ZinxKernel::getInstance()->modChannelOUt(this);

}
//
void IChannel::fflushOut(void)
{
	writeFd(mBuf);
	mBuf.clear();
}
//内部处理函数
AZinxMsg * IChannel::internelHandle(AZinxMsg & _msg)
{
	UserMsg *pUserMsg = nullptr;
	SysIoMsg *pSysloMsg = static_cast<SysIoMsg*>(&_msg);
	//判断读写方向
	if (SysIoMsg::IO_IN == pSysloMsg->sysIo)
	{
		string data;
		pUserMsg = new UserMsg;
		pUserMsg->sysIo = pSysloMsg->sysIo;
		pUserMsg->mData = readFd(data);
	}
	else
	{
		UserMsg *pMsg = static_cast<UserMsg*>(&_msg);
		writeFd(pMsg->mData);
	}
	return pUserMsg;
}

AZinxHandler * IChannel::getNextHangler(AZinxMsg & _msg)
{
	return getNextStep(_msg);
}
