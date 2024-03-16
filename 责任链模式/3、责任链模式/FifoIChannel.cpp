#include "FifoIChannel.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
FifoIChannel::FifoIChannel()
{
}

FifoIChannel::FifoIChannel(string _fileName)
{
	m_FileName = _fileName;
}

FifoIChannel::~FifoIChannel()
{
}

bool FifoIChannel::init(void)
{
	//打开管道
	m_Fd = open(m_FileName.c_str(), O_RDWR);
	if (-1 == m_Fd)
	{
		perror("open");
		return false;
	}
	cout << "打开管道成功" << endl;
	return true;
}

bool FifoIChannel::fini(void)
{
	if (m_Fd >= 0)
	{
		close(m_Fd);
		return true;
	}
	return false;
}

string FifoIChannel::readFd(string & data)
{

	int ret = -1;
	char buf[128];
	memset(buf, 0, sizeof(buf));
	//从文件中读取数据
	ret = read(m_Fd, buf, sizeof(buf));
	if (-1 == ret)
	{
		perror("read");
		return string();
	}

	data = string(buf);

	//数据处理
	dataProcess(data);


	return data;
}

bool FifoIChannel::writeFd(string & data)
{
	int ret = -1;
	ret = write(m_Fd, data.c_str(), data.size());
	if (-1 == ret)
	{
		perror("write");
		return false;
	}
	return true;
}

int FifoIChannel::getFd(void)
{
	return m_Fd;
}
