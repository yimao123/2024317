#include <iostream>
#include "zinx.h"



#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>
#include "ZinxTimerDeliver.h"
#include "ZinxTimer.h"
using namespace std;
class TimeOut :public TimerOutProc
{
    public:


        // 通过 TimerOutProc 继承
        virtual void Proc() override
        {
            //		auto players = ZinxKernel::Zinx_GetAllRole();
            //		//如果所有的角色（文件描述符）（包含定时器）不存在，整体框架退出，
            //		if (0 == players.size())
            //		{
            //			ZinxKernel::Zinx_Exit();
            //		}
            printf("定时器倒计时\n");
        }

        virtual int GetTimerSec() override
        {
            return 30;
        }

};
class TimeOut2 :public TimerOutProc
{
    public:


        // 通过 TimerOutProc 继承
        virtual void Proc() override
        {
            //		auto players = ZinxKernel::Zinx_GetAllRole();
            //		//如果所有的角色（文件描述符）（包含定时器）不存在，整体框架退出，
            //		if (0 == players.size())
            //		{
            //			ZinxKernel::Zinx_Exit();
            //		}
            printf("第二个定时事件\n");
        }

        virtual int GetTimerSec() override
        {
            return 5;
        }

};



void Daemon(void)
{
    pid_t pid = -1;
    int ret = -1;
    int fd = -1;
    int status = 0;
    pid = fork();
    if (-1 == pid)
    {
        perror("fork");
        exit(1);
    }
    else if (pid > 0)
    {
        //父进程退出
        exit(1);
    }
    //创建会话
    ret = setsid();
    if (-1 == ret)
    {
        perror("setsid");
        exit(1);
    }
    //设置权限掩码
    umask(0);
    //改变当前进程工作目录

    //重定向文件描述符
    fd = open("./game.log", O_RDWR | O_CREAT | O_APPEND, 0644);
    if (-1 == fd)
    {
        perror("open");
        exit(1);
    }
    dup2(fd, STDIN_FILENO);
    dup2(fd, STDOUT_FILENO);
    dup2(fd, STDERR_FILENO);
    close(fd);
    while (1)
    {
        pid = fork();
        if (-1 == pid)
        {
            perror("fork");
            exit(1);
        }
        else if (pid > 0)
        {
            //父进程监视异常
            //如果异常会回收资源
            wait(&status);
            //但不会继续向下执行
            //并发的子进程，会跳出执行下一次循环使资源重新分配
            if (WIFEXITED(status))
            {
                //子进程正常终止，父进程也退出
                //正常结束
                exit(0);
            }

        }
        else if(pid==0)
        {
            break;
        }
        else
        {
            perror("fork");
            exit(1);
        }
    }
}
int main(int argc,char* argv[])
{
    if ((2 == argc) && "daemon" == string(argv[1]))
    {
        Daemon();
    }
    //创建一个定时器对象
    ZinxTimer *pTimer = new ZinxTimer;
    TimeOut tmo;
    TimeOut2 tmp2;
    //注册超时事件
    ZinxTimerDeliver::GetInstance().RegisterProcObject(tmo);
    ZinxTimerDeliver::GetInstance().RegisterProcObject(tmp2);

    //ZinxTCPListen *pServer = new ZinxTCPListen(11001, new TcpConnFactory);

    //初始化
    ZinxKernel::ZinxKernelInit();

    //添加通道
    //ZinxKernel::Zinx_Add_Channel(*pServer);
    ZinxKernel::Zinx_Add_Channel(*pTimer);

    //运行
    ZinxKernel::Zinx_Run();

    //释放资源
    ZinxKernel::ZinxKernelFini();
    //google::protobuf::ShutdownProtobufLibrary();

    return 0;
}
