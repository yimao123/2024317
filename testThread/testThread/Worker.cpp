# include "Worker.h"
#include <QDebug>
Worker::Worker()
{
}

Worker::~Worker()
{
}
void Worker::doWork(int parameter)
{
	qDebug() << "receive the execute signal";
	qDebug() << "\tCurrent thread ID: " << QThread::currentThreadId();

	// ѭ��һ�����
	for (int i = 0; i != 1000000; ++i)
	{
		++parameter;
	}

	// ���ͽ����ź�  
	qDebug() << "\tFinish the work and sent the result Ready signal\n";

	emit resultReady(parameter);
}