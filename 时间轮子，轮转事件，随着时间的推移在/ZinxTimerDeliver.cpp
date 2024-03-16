#include "ZinxTimerDeliver.h"

using namespace std;

#define ZINX_TIMER_WHELL_SIZE 8

//静态数据成员
ZinxTimerDeliver ZinxTimerDeliver::m_single;

//构造函数
ZinxTimerDeliver::ZinxTimerDeliver()
{

	m_TimerWheel.resize(ZINX_TIMER_WHELL_SIZE);
}

//任务注册
bool ZinxTimerDeliver::RegisterProcObject(TimerOutProc & _proc)
{
	int index = 0;

	WheelNode node;


	//获取超时时间
	int tmo = _proc.GetTimerSec();

	if (tmo <= 0)
	{
		return false;
	}

	memset(&node, 0, sizeof(node));
	//计算格子  格子 = (当前刻度 + 超时时间) % 轮子的格子总数
	index = (m_cur_index + tmo) % m_TimerWheel.size();

	//计算的圈数  圈数 = 超时时间 / 轮子的格子总数
	node.LastCount = tmo / m_TimerWheel.size();
	//超时执行任务
	node.pProc = &_proc;

	//注册
	m_TimerWheel[index].push_back(node);

	return true;
}

//注销任务
void ZinxTimerDeliver::UnRegisterProcObject(TimerOutProc & _proc)
{
	for (auto &v : m_TimerWheel)
	{
		for (auto l = v.begin(); l != v.end(); )
		{
			if (l->pProc == &_proc)
			{
				l = v.erase(l);
			}
			else
			{
				l++;
			}
		}
	}
}

//每隔一秒钟执行一次
IZinxMsg * ZinxTimerDeliver::InternalHandle(IZinxMsg & _oInput)
{
	uint64_t count;
	BytesMsg *pMsg = dynamic_cast<BytesMsg*>(&_oInput);

	list<TimerOutProc*> registerLists;

	pMsg->szData.copy((char*)&count, sizeof(count));

	cout << "count: " << count << endl;

	for (int i = 0; i < count; i++)
	{
		//自增当前刻度 0 - 7
		m_cur_index = (m_cur_index + 1) % m_TimerWheel.size();

		for (auto it = m_TimerWheel[m_cur_index].begin(); it != m_TimerWheel[m_cur_index].end();)
		{
			it->LastCount--;

			if (it->LastCount < 0)
			{
				//调用超时任务处理函数
				it->pProc->Proc();

				registerLists.push_back(it->pProc);

				it = m_TimerWheel[m_cur_index].erase(it);

			}
			else
			{
				it++;
			}
		}

		//重新注册
		for (auto it : registerLists)
		{
			RegisterProcObject(*it);
		}
	}


	return nullptr;
}

AZinxHandler * ZinxTimerDeliver::GetNextHandler(IZinxMsg & _oNextMsg)
{
	return nullptr;
}


ZinxTimerDeliver::~ZinxTimerDeliver()
{
}
