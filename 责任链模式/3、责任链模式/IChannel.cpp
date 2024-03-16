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
	//���ݴ������ַ�����1�������˾����ˣ���������2����ͨ������ָ�벻Ϊ�ս���������
	if (nullptr == pNextHandler)
	{
		dataSendOUt(data);
		return;//ͨ��ָ��Ϊ�գ����Ӷ��¼�
	}
	
	UserMsg *pMsg = new UserMsg;
	pMsg->mData = data;
	pMsg->mLen = data.length();
	pNextHandler->handle(*pMsg);
	delete pMsg;
}

void IChannel::dataSendOUt(string data)
{
	//pOut�Թ���ͨ��ָ�뽫���ݹ��õ�ͨ�������Ļ�����
	//�ı����ͨ��ָ��ļ����¼�������ѭ������
	//��������
	mBuf.append(data);
	//д�����¼�
	//��ͨ���������д�¼�
	ZinxKernel::getInstance()->modChannelOUt(this);

}
//
void IChannel::fflushOut(void)
{
	writeFd(mBuf);
	mBuf.clear();
}
//�ڲ�������
AZinxMsg * IChannel::internelHandle(AZinxMsg & _msg)
{
	UserMsg *pUserMsg = nullptr;
	SysIoMsg *pSysloMsg = static_cast<SysIoMsg*>(&_msg);
	//�ж϶�д����
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
