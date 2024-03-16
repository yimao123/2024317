#pragma once
#include "IChannel.h"
#include <arpa/inet.h>
class UDPChannel :
	public IChannel
{
public:
	UDPChannel();
	UDPChannel(string ip,unsigned short port);
	virtual ~UDPChannel();

	// Í¨¹ý IChannel ¼Ì³Ð
	virtual bool init(void) override;
	virtual bool fini(void) override;
	virtual string readFd(string & data) override;
	virtual bool writeFd(string & data) override;
	virtual int getFd(void) override;
private:
	int m_Sockfd = -1;
	struct sockaddr_in addr;
};

