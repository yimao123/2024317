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


	// ͨ�� IChannel �̳�
	virtual bool init(void) override;

	virtual bool fini(void) override;

	virtual string readFd(string & data) override;

	virtual bool writeFd(string & data) override;

	virtual int getFd(void) override;
private:
	TcpSocket* m_Socket;
	//��һ���򵥵ķ�����
	//Ҫ��ͨ���׽�����Ϊͨ������ע�����Ϊ��ͨ��
	TcpServer* m_Server;

	


};

