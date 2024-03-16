#pragma once
#include "IChannel.h"
#include <arpa/inet.h>
#include "TcpSocket.h"
#include "TcpServer.h"
class TcpChannel :
	public IChannel
{
public:
	TcpChannel();
	virtual ~TcpChannel();


	// 通过 IChannel 继承
	virtual bool init(void) override;

	virtual bool fini(void) override;

	virtual string readFd(string & data) override;

	virtual bool writeFd(string & data) override;

	virtual int getFd(void) override;
private:
	TcpSocket* m_Socket;
	//做一个简单的服务器
	//要将通信套接字作为通道，标注输出作为二通道
	TcpServer* m_Server;

	


};

