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
	void doWork(int parameter);  // doWork �������߳�Ҫִ�еĲ���

signals:
	void resultReady(const int result);  // �߳���ɹ���ʱ���͵��ź�

};
