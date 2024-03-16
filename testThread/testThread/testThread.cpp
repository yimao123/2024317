#include "testThread.h"
#include "Controller.h"
testThread::testThread(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	Controller *c = new Controller(this);
	/*moveToThread方法，是把我们需要的工作全部封装在一个类中，
	将每个任务定义为一个的槽函数，再建立触发这些槽的信号，
	然后把信号和槽连接起来，最后将这个类调用moveToThread方法交给一个QThread对象，
	再调用QThread的start()函数使其全权处理事件循环。于是，任何时候我们需要让线程执行某个任务
	，只需要发出对应的信号就可以。其优点是我们可以在一个worker类中定义很多个需要做的工作
	，然后发出触发的信号线程就可以执行。相比于子类化的QThread只能执行run()函数中的任务，
	moveToThread的方法中一个线程可以做很多不同的工作（只要发出任务的对应的信号即可）。 
子类化QThread的方法，就是重写了QThread中的run()函数，在run()函数中定义了需要的工作。
这样的结果是，我们自定义的子线程调用start()函数后，便开始执行run()函数。
如果在自定义的线程类中定义相关槽函数，那么这些槽函数不会由子类化的QThread自身事件循环所执行，
而是由该子线程的拥有者所在线程（一般都是主线程）来执行。如果你不明白的话，请看，第二个例子中
，子类化的线程的槽函数中输出当前线程的ID，而这个ID居然是主线程的ID！！事实的确是如此，子类化的QThread只能执行run()函数中的任务直到run()函数退出，而它的槽函数根本不会被自己的线程执行。
————————————————

                            版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。
                        
原文链接：https://blog.csdn.net/qq_38410730*/
}
