
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//��Ƽ���������
class Operator
{
public:
	Operator(){}
	Operator(int _x,int _y)
	{
		numA = _x;
		numB = _y;
	}
	virtual ~Operator(){}
	//������
	virtual int getResult() = 0;//���麯��
public:
	int numA;
	int numB;
};
//�ӷ���
class AddOperator :public Operator
{
public:
	AddOperator() {}
	AddOperator(int _x, int _y) :Operator(_x, _y) {}
	~AddOperator(){}
	virtual int getResult() override
	{
		int result = 0;
		result = numA + numB;
		return result;
	}
};
//������
class SubOperator :public Operator
{
public:
	SubOperator() {}
	SubOperator(int _x, int _y) :Operator(_x, _y) {}
	~SubOperator() {}
	virtual int getResult() override
	{
		int result = 0;
		result = numA - numB;
		return result;
	}
};
//�˷���
class MulOperator :public Operator
{
public:
	MulOperator() {}
	MulOperator(int _x, int _y) :Operator(_x, _y) {}
	~MulOperator() {}
	virtual int getResult() override
	{
		int result = 0;
		result = numA * numB;
		return result;
	}
};
//������
class DivOperator :public Operator
{
public:
	DivOperator() {}
	DivOperator(int _x, int _y) :Operator(_x, _y) {}
	~DivOperator() {}
	virtual int getResult() override
	{
		if (0 == numB)
		{
			return -1;
		}
		int result = 0;
		result = numA / numB;
		return result;
	}
};
//��������ļ򵥹�����
class OperatorFactory
{
public:
	//ʹ��Ĭ�Ϲ��������
	Operator *createOperator(int _x, int _y, string op)
	{
		Operator *pOperator = nullptr;
		switch (op[0])
		{
		case '+':
			pOperator = new AddOperator(_x, _y);
			break;
		case '-':
			pOperator = new SubOperator(_x, _y);
			break;
		case '*':
			pOperator = new MulOperator(_x, _y);
			break;
		case '/':
			pOperator = new DivOperator(_x, _y);
			break;
		}
	}
};
int main()
{
	//�����򵥹�����
	OperatorFactory factory;
	//�������
	Operator *pOperator = factory.createOperator(15, 3, "/");
	cout << "15/3=" << pOperator->getResult() << endl;



	return 0;
}