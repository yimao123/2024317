#include "Controller.h"
#include "Worker.h"
#include <QDebug>
Controller::Controller(QObject *parent)
	: QObject(parent)
{
	 auto *worker = new Worker;

	// ���� moveToThread �������񽻸� workThread
	worker->moveToThread(&workerThread);

	// operate �źŷ���������̹߳���
	connect(this, SIGNAL(operate(const int)), worker, SLOT(doWork(int)));

	// ���߳̽���ʱ����
	connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);

	// �߳̽��������źţ��Խ�����д���
	connect(worker, SIGNAL(resultReady(int)), this, SLOT(handleResults(int)));

	// �����߳�
	workerThread.start();

	// �����źţ���ʼִ��
	qDebug() << "emit the signal to execute!";
	qDebug() << "\tCurrent thread ID:" << QThread::currentThreadId() << '\n';

	 emit operate(0);
}

Controller::~Controller()
{
	workerThread.quit();
	workerThread.wait();
}
void Controller::handleResults(const int result)
{
	qDebug() << "receive the resultReady signal";
	qDebug() << "\tCurrent thread ID: " << QThread::currentThreadId() << '\n';
	qDebug() << "\tThe last result is: " << result;
}
