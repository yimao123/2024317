#pragma once
#include <iostream>
//ǰ������
#include "AZinxHandler.h"
using namespace std;
//��Ȼÿ�������߶����Լ���������Ϣ
//��ô�Ϳ��Խ�
//�������ϵͳ��Ϣ���󵽺���������Ϊ����
/*��������������������������������
1�������ƺ��������಻�麯��
2�����麯�����ڲ���������
3�����麯������ȡ��һ�������ߵ�ͨ��ָ����ߴ�����ָ��*/
//���з����ϵͳ��Ϣ��
class SysIoMsg : public AZinxMsg
{//ö��ֵ
public:
	enum SysIo { IO_IN, IO_OUT }sysIo;
};
//�û�������Ϣ
class UserMsg : public SysIoMsg
{
public:
	string mData;
	int mLen;
};
//����
//ͨ�����ԣ����ܣ��Ĵ����װ
//����׼���롢��׼������ܵ������Է�װ��һ������
//����ͨ����̳д������࣬ʵ���������麯��
class IChannel :public AZinxHandler
{
public:
	IChannel();
	virtual ~IChannel();
	//��ʼ��
	virtual bool init(void) = 0;
	//����
	virtual bool fini(void) = 0;
	//������д
	virtual string readFd(string &data) = 0;
	virtual bool  writeFd(string &data) = 0;
	//ͨ���ع�����Ӻ���
	virtual AZinxHandler *getNextStep(AZinxMsg &_msg) = 0;
	
	//��ȡ�ļ�������
	virtual int getFd(void) = 0;
	//���ݴ���
	void dataProcess(string data);
	//���ݷ���
	void dataSendOUt(string data);
	//ˢ�»�����
	void fflushOut(void);
	// ͨ�� AZinxHandler �̳�
	virtual AZinxMsg * internelHandle(AZinxMsg & _msg) override;
	virtual AZinxHandler * getNextHangler(AZinxMsg & _msg) override;
public:
	AZinxHandler *pNextHandler = nullptr;//�Թ���//�ο�����

	//������
	string mBuf;


};

