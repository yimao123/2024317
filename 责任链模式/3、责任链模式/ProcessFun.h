#pragma once
#include "IChannel.h"
#include "AZinxHandler.h"
#if 0



class UserMsg : public AZinxMsg
{
public:
	string mData;
	int mLen;
};
#endif // 0

//2|���ģ������ַ�����С
class SizeData : public AZinxHandler
{
public:
	SizeData();
	~SizeData();


	// ͨ�� AZinxHandler �̳�
	virtual AZinxMsg * internelHandle(AZinxMsg & _msg) override;

	virtual AZinxHandler * getNextHangler(AZinxMsg & _msg) override;
public:
	AZinxHandler *pNextHandler = nullptr;

};
//3�����ģ�飬���ACIIֵ
class AciiData : public AZinxHandler
{
public:
	AciiData();
	~AciiData();
	virtual AZinxMsg * internelHandle(AZinxMsg & _msg) override;
	virtual AZinxHandler * getNextHangler(AZinxMsg & _msg) override;
public:
	IChannel *pNextHandler= nullptr;

	// ͨ�� AZinxHandler �̳�
	
};
class ProcessFun : public AZinxHandler
{
public:
	ProcessFun();
	virtual ~ProcessFun();
	// ͨ�� AZinxHandler �̳�
	virtual AZinxMsg * internelHandle(AZinxMsg & _msg) override;
	virtual AZinxHandler * getNextHangler(AZinxMsg & _msg) override;
private:
	//��Сдת��������
	string upperOut(string &data);
	//ԭ�����
	string origOut(string &out);
public:
	AZinxHandler* pNextHandler = nullptr;

	
};

