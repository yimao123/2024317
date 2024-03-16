#include "AZinxHandler.h"

AZinxMsg::AZinxMsg()
{
}

AZinxMsg::~AZinxMsg()
{
}

AZinxHandler::AZinxHandler()
{
}

AZinxHandler::~AZinxHandler()
{
}
//处理者入口
void AZinxHandler::handle(AZinxMsg & _msg)
{
	AZinxMsg *pMsg = nullptr;
	AZinxHandler *pHandler = nullptr;
	//调用内部处理函数，返回消息类对象
	pMsg = internelHandle(_msg);
	//消息为空表示，不在向下传递，处理结束，
	//在此类中表示达到标准输出通道
	if (nullptr != pMsg)
	{
		//获取下一个处理函数
		pHandler = getNextHangler(*pMsg);
		if (nullptr != pHandler)
		{
			//下一个指针操作消息对象
			pHandler->handle(*pMsg);
		}
		
	}
}
