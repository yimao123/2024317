#include "TcpChannel.h"
#include <cstring>
TcpChannel::TcpChannel()
{
	//
	m_Socket = new TcpSocket();
	memset(m_Socket, 0, sizeof(m_Socket));
	m_Server = new TcpServer();
	memset(m_Server, 0, sizeof(m_Server));
}

TcpChannel::~TcpChannel()
{
	if (m_Socket != nullptr)
	{
		delete m_Socket;
	}
	if (m_Server != nullptr)
	{
		delete m_Server;
	}
}

bool TcpChannel::init(void)
{
	//设置监听
	int ret = -1;
	ret=m_Server->setListen(10086);
	/*if (0!= ret)
	{
		cout << "serListen failed" << endl;
		return false;
	}*/
	//等待连接
	m_Socket=m_Server->acceptConn();
	
	if (nullptr != m_Socket)
	{
		cout << "客户端连接成功" << endl;
		cout << "m_Socket:" << m_Socket->m_socket << endl;
		
		return true;
	}

	return false;
}

bool TcpChannel::fini(void)
{
	m_Server->closefd();
	m_Socket->disConnect();
	return true;
}

string TcpChannel::readFd(string & data)
{
	//从客户端读取数据
	//char *buf = "nullptr";
	//int recvLen = 0;
	//m_Socket->sendMsg(buf, sizeof(buf));
	//cout <<"buf:"<< buf << endl;
	////处理数据
	//dataProcess(string(buf));
	
	char buf[128];
	int recvLen = 0;
	m_Socket->recvMsg((char**)&buf, recvLen);
	cout << "buf:" << buf << endl;
	//数据处理
	dataProcess(buf);
	return buf;
}

bool TcpChannel::writeFd(string & data)
{
	
	return false;
}

int TcpChannel::getFd(void)
{
	return m_Socket->m_socket;
}
