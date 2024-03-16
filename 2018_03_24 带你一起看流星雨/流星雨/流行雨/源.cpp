#include <graphics.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define MAXSTAR 100
#define MAXSTAR1 600
//流星
struct STAR
{
	int x, y;		//坐标
	int step;		//速度
	int style;		//样式
}star[MAXSTAR];
//星星
struct STAR1
{
	int x, y;
	int step;
	int color;
}star1[MAXSTAR1];

IMAGE image1, image2, image3;
void initData();		//初始化数据
//星星
void initStar1(int i);		//初始化星星
void moveStar1(int i);		//移动星星
//流星模块
void initStar(int i);
void drawStar();
void moveStar();

int main()
{
	initData();
	mciSendString("open 纯音乐最后的莫西干人纯音乐版.mp3 alias music", 0, 0, 0);
	mciSendString("play music repeat", 0, 0, 0);
	while (1)
	{
		BeginBatchDraw();
		cleardevice();
		for (int i = 0; i < MAXSTAR1; i++)
		{
			moveStar1(i);
		}
		moveStar();
		drawStar();
		Sleep(50);
		EndBatchDraw();
	}
	closegraph();
	return 0;
}
void initData()
{
	srand((unsigned int)time(NULL));//随机数设置
	initgraph(640, 480);
	//初始化数据--->初始化变量
	loadimage(&image1, "1.jpg",50,50);
	loadimage(&image2, "2.jpg", 50, 50);
	loadimage(&image3, "3.jpg", 50, 50);
	//初始化星星
	int i = 0;
	for (i = 0; i < MAXSTAR1; i++)
	{
		initStar1(i);
		star1[i].x = rand() % 640;
	}
	//初始化流星
	for (i = 0; i < MAXSTAR; i++)
	{
		initStar(i);
	}

}
//创建星星过程,就是初始化基本数据成员
void initStar1(int i)
{
	star1[i].x = 0;
	star1[i].y = rand() % 480;
	star1[i].step = rand() % 5;
	star1[i].color = RGB(star[i].step * 51, star[i].step * 51, star[i].step * 51);
}

//移动星星
void moveStar1(int i)
{
	putpixel(star1[i].x, star1[i].y, 0);
	//移动--->坐标变化
	star1[i].x += star1[i].step;
	if (star1[i].x > 640)
		initStar1(i);
	putpixel(star1[i].x, star1[i].y, star1[i].color);
}
void initStar(int i)
{
	star[i].x = rand() % 1280 - 640;		//-640,640
	star[i].y = -144;
	do
	{
		star[i].step = rand() % 30 + 1;
	} while (star[i].step < 5);
	//star[i].step = rand() % 30 + 5;
	star[i].style = rand() % 3+1;
}
void drawStar()
{
	for (int i = 0; i < MAXSTAR; i++)
	{
		switch (star[i].style)
		{
		case 1:
			putimage(star[i].x, star[i].y, &image1, SRCPAINT);
			break;
		case 2:
			putimage(star[i].x, star[i].y, &image2, SRCPAINT);
			break;
		case 3:
			putimage(star[i].x, star[i].y, &image3, SRCPAINT);
			break;
		}
	}
}

void moveStar()
{
	for (int i = 0; i < MAXSTAR; i++)
	{
		star[i].x += star[i].step;
		star[i].y += star[i].step*0.8;
	}
}
//2关门弟子
//1.你想学,想要学好
//2.能坚持学,如果连VIP 8个月课程,不能认真学习的
//3.不能过于内向,能够经常问问题人
//VIP: 内容: 
/*
		[官方VIP咨询老师]  茜茜老师:854971155
	C语言-->C++-->数据结构体与算符-->windows编程-->Qt编程-->Linux系统编程(内核)-->服务器编程
		       数据库编程,网络编程,多线程编程,并发编程 ---->软件
	学费:8880优惠学费,
			[官方VIP咨询老师]  茜茜老师:854971155
			并且申请零利息一种分期助学通道
			8880/24=370块每月  370/30=13块每天
			1.3小时晚上直播课程
			2.视频资源与代码
			3.老师随时随地的解答
			4.下午课程补课(申请1和1)
			5.老师指导:职业方向
			6.项目实战
			7.4年学习权限 :防止技术更新,U3D以前的学员免费


*/		

