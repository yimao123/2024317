#pragma once

#include <QObject>
#include <QThread>
class Controller : public QObject
{
	Q_OBJECT

		QThread workerThread;
public:
	Controller(QObject *parent);
	~Controller();
	public slots:
	static void handleResults(int result);  // �������߳�ִ�еĽ��

signals:
	void operate(const int);  // �����źţ������߳�
};
