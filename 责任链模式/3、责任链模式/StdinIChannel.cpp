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
	//��׼������¼�
	cin >> data;
	cout << "StdinChannel readFd:" << data << endl;
	//���ݴ���
	//dataProcess(data);/���ع���ʧЧ
	return data;
}

bool StdinIChannel::writeFd(string & data)
{
	//д�¼��ڴ�ͨ���ر�
	return false;
}

int StdinIChannel::getFd(void)
{
	//�ļ�������Ϊ�����¼�����

	return STDIN_FILENO;//������׼������¼������Ļ�����
}

AZinxHandler * StdinIChannel::getNextStep(AZinxMsg & _msg)
{
	return pNextHandler;
}
