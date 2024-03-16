
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//设计计算器基类
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
	//计算结果
	virtual int getResult() = 0;//纯虚函数
public:
	int numA;
	int numB;
};
//加法类
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
//减法类
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
//乘法类
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
//除法类
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
//创建对象的简单工厂类
class OperatorFactory
{
public:
	//使用默认构造和析构
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
	//创建简单工厂类
	OperatorFactory factory;
	//运算符类
	Operator *pOperator = factory.createOperator(15, 3, "/");
	cout << "15/3=" << pOperator->getResult() << endl;



	return 0;
}