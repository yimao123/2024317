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
	static void handleResults(int result);  // 处理子线程执行的结果

signals:
	void operate(const int);  // 发送信号，触发线程
};
