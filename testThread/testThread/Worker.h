#pragma once

#include <QObject>
#include <QThread>
class Worker : public QObject
{
	Q_OBJECT

public:
	Worker();
	~Worker();
	public slots:
	void doWork(int parameter);  // doWork 定义了线程要执行的操作

signals:
	void resultReady(const int result);  // 线程完成工作时发送的信号

};
