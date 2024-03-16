#include <iostream>
#include "ZinxKernel.h"
#include "StdinIChannel.h"
#include "ProcessFun.h"

#include "StdoutIChannel.h"

//问题，结构体可以直接赋值吗？答案：不可以，必须要给指定空间才可以
using namespace std;

int main(void)
{
	//对象之间是独立的，如果用一个对象的成员方法去修改另一个对象的成员属性，应该会失败，而且是私有属性
	//定义监听
	ZinxKernel *pZinx;
	//创建标准输入通道对象
	//创建有名管道对象
	StdinIChannel in;
	
	//1、输出字符串长度
	SizeData strlen;
	//2、小写转大小
	ProcessFun fun;//
	//3、输出ASCII码值
	AciiData aci;
	StdoutIChannel out;
	//将标准输入通道类督导数据之后由标准输出处理输出

	in.pNextHandler = &strlen;
	strlen.pNextHandler = &fun;
	fun.pNextHandler = &aci;
	aci.pNextHandler = &out;
	//获取实例
	pZinx=ZinxKernel::getInstance();//返回一个静态成员充当实例
	//初始化
	pZinx->init();
	//添加通道
	in.init();
	pZinx->addChannel(&in);

	pZinx->addChannel(&out);
	//运行
	pZinx->run();
	//销毁
	pZinx->destroy();

	return 0;
}