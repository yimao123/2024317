#pragma once
#include "IChannel.h"
//���Ŀ����Epollģ�ͷ�װ
//���ӱ�׼���루��),���ӱ�׼�����д�������ӹܵ�����д��
class ZinxKernel
{
	//��Ӽ���ͨ����
public:
	ZinxKernel();
	virtual ~ZinxKernel();
	//��ȡ��̬���ݳ�Ա��ֵ��ʵ���뾲̬��Աʱ��Ӧ�ģ������ǵ���ģʽ��
	//��ȡʵ��ֵmZinxֵ
	static ZinxKernel *getInstance(void);
	//��ʼ��
	bool init(void);
	//����
	bool addChannel(IChannel *_channel);
	//����
	bool delChannel(IChannel *_channel);
	//���Ӷ��¼�
	bool modChannelIn(IChannel *_channel);
	//����д�¼�
	bool modChannelOUt(IChannel *_channel);
	//�ı���ϢI/O�ķ���
	//ѭ������
	bool run();
	//�ͷ�
	bool destroy();
	//�ع�����Ӻ���
	//�ı���Ϣ��IO����ͬʱ�޸ļ������¼�
	bool dataSendOut(IChannel *_channel, string &_data);
private:
	int mEpollFd = -1;
	//��ָ̬��
	static ZinxKernel *mZinx;
};

