#include "ZinxTimer.h"

#include <sys/timerfd.h>
#include <stdint.h>
#include <unistd.h>
#include <cstring>

#include "ZinxTimerDeliver.h"


using namespace std;

//构造函数
ZinxTimer::ZinxTimer()
{
}

//析构函数
ZinxTimer::~ZinxTimer()
{
}

//初始化 1秒超时1次
bool ZinxTimer::Init()
{
	int ret = -1;
	struct itimerspec tmo = { {1, 0}, {1, 0} };

	//创建一个定时器
	mFd = timerfd_create(CLOCK_MONOTONIC, 0);
	if (-1 == mFd)
	{
		perror("timerfd_create");
		return false;
	}

	//设置超时时间
	ret = timerfd_settime(mFd, 0, &tmo, NULL);
	if (-1 == ret)
	{
		perror("timerfd_settime");
		return false;
	}

	return true;
}

//读数据
bool ZinxTimer::ReadFd(std::string & _input)
{
	int ret = -1;
	uint64_t val;

	memset(&val, 0, sizeof(val));

	ret = read(mFd, &val, sizeof(val));
	if (ret != sizeof(val))
	{
		perror("read");
		return false;
	}

	cout << "超时: " << val << endl;

	_input.append((char*)&val, sizeof(val));

	return true;
}

//不需要事先
bool ZinxTimer::WriteFd(std::string & _output)
{
	return false;
}

//释放资源
void ZinxTimer::Fini()
{
	if (mFd >= 0)
	{
		close(mFd);
	}
}

//获取文件描述符
int ZinxTimer::GetFd()
{
	return mFd;
}

//获取通道的信息
std::string ZinxTimer::GetChannelInfo()
{
	return std::string("ZinxTimer");
}

//获取下一个处理者
AZinxHandler * ZinxTimer::GetInputNextStage(BytesMsg & _oInput)
{
	return &ZinxTimerDeliver::GetInstance();
}
