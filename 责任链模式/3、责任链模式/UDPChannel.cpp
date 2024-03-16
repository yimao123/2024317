#include "UDPChannel.h"
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

UDPChannel::UDPChannel()
{
	memset(&addr, 0, sizeof(addr));
}

UDPChannel::UDPChannel(string ip, unsigned short port)
{
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	inet_pton(AF_INET, ip.data(), &addr.sin_addr.s_addr);
}

UDPChannel::~UDPChannel()
{
}

bool UDPChannel::init(void)
{
	//创建套接字
	m_Sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (-1 == m_Sockfd)
	{
		perror("socket");
		return false;
	}
	//连接服务器
	return true;
}

bool UDPChannel::fini(void)
{
	if (m_Sockfd >= 0)
	{
		close(m_Sockfd);
		return true;
	}
	return false;
}

string UDPChannel::readFd(string & data)
{
	int ret = -1;
	char buf[128];
	ret = recvfrom(m_Sockfd, buf, sizeof(buf), 0, NULL, NULL);
	if (-1 == ret)
	{
		perror("recvfrom");
		return string();
	}

	return string(buf);
}

bool UDPChannel::writeFd(string & data)
{
	int ret = -1;
	ret = sendto(m_Sockfd, data.c_str(), data.size(), 0, (struct sockaddr*)&addr, sizeof(addr));
	if (-1 == ret)
	{
		perror("sendto");
		return false;
	}
	return true;
}

int UDPChannel::getFd(void)
{
	return m_Sockfd;
}
