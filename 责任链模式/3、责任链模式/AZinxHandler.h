#pragma once
#include <iostream>
//��Ϣ�����

class AZinxMsg
{
public:
	AZinxMsg();
	~AZinxMsg();
};
//�����߻��������ͨ�������ͨ���崦����
class AZinxHandler
{
	//������ع�֮ǰ������
	//�ع���ֻ��
	/*
	1��ͨ���๲�м̳д������࣬���봦����Ϣ��һԱ
	2������ͨ����ķ�����Ϣ����->���������Ϣ��->��������Ϣ��
	*/
public:
	AZinxHandler();
	~AZinxHandler();
	//������//�������ݣ������Զ����������ͣ������
	//��������ں���
	void handle(AZinxMsg &_msg);
	//�������ڲ�������
	virtual AZinxMsg *internelHandle(AZinxMsg &_msg) = 0;
	//��ȡ��һ�������ߺ���
	virtual AZinxHandler *getNextHangler(AZinxMsg &_msg) = 0;

};