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
//���������
void AZinxHandler::handle(AZinxMsg & _msg)
{
	AZinxMsg *pMsg = nullptr;
	AZinxHandler *pHandler = nullptr;
	//�����ڲ���������������Ϣ�����
	pMsg = internelHandle(_msg);
	//��ϢΪ�ձ�ʾ���������´��ݣ����������
	//�ڴ����б�ʾ�ﵽ��׼���ͨ��
	if (nullptr != pMsg)
	{
		//��ȡ��һ��������
		pHandler = getNextHangler(*pMsg);
		if (nullptr != pHandler)
		{
			//��һ��ָ�������Ϣ����
			pHandler->handle(*pMsg);
		}
		
	}
}
