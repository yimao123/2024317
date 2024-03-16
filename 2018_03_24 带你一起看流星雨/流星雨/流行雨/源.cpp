#include <graphics.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define MAXSTAR 100
#define MAXSTAR1 600
//����
struct STAR
{
	int x, y;		//����
	int step;		//�ٶ�
	int style;		//��ʽ
}star[MAXSTAR];
//����
struct STAR1
{
	int x, y;
	int step;
	int color;
}star1[MAXSTAR1];

IMAGE image1, image2, image3;
void initData();		//��ʼ������
//����
void initStar1(int i);		//��ʼ������
void moveStar1(int i);		//�ƶ�����
//����ģ��
void initStar(int i);
void drawStar();
void moveStar();

int main()
{
	initData();
	mciSendString("open ����������Ī�����˴����ְ�.mp3 alias music", 0, 0, 0);
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
	srand((unsigned int)time(NULL));//���������
	initgraph(640, 480);
	//��ʼ������--->��ʼ������
	loadimage(&image1, "1.jpg",50,50);
	loadimage(&image2, "2.jpg", 50, 50);
	loadimage(&image3, "3.jpg", 50, 50);
	//��ʼ������
	int i = 0;
	for (i = 0; i < MAXSTAR1; i++)
	{
		initStar1(i);
		star1[i].x = rand() % 640;
	}
	//��ʼ������
	for (i = 0; i < MAXSTAR; i++)
	{
		initStar(i);
	}

}
//�������ǹ���,���ǳ�ʼ���������ݳ�Ա
void initStar1(int i)
{
	star1[i].x = 0;
	star1[i].y = rand() % 480;
	star1[i].step = rand() % 5;
	star1[i].color = RGB(star[i].step * 51, star[i].step * 51, star[i].step * 51);
}

//�ƶ�����
void moveStar1(int i)
{
	putpixel(star1[i].x, star1[i].y, 0);
	//�ƶ�--->����仯
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
//2���ŵ���
//1.����ѧ,��Ҫѧ��
//2.�ܼ��ѧ,�����VIP 8���¿γ�,��������ѧϰ��
//3.���ܹ�������,�ܹ�������������
//VIP: ����: 
/*
		[�ٷ�VIP��ѯ��ʦ]  ������ʦ:854971155
	C����-->C++-->���ݽṹ�������-->windows���-->Qt���-->Linuxϵͳ���(�ں�)-->���������
		       ���ݿ���,������,���̱߳��,������� ---->���
	ѧ��:8880�Ż�ѧ��,
			[�ٷ�VIP��ѯ��ʦ]  ������ʦ:854971155
			������������Ϣһ�ַ�����ѧͨ��
			8880/24=370��ÿ��  370/30=13��ÿ��
			1.3Сʱ����ֱ���γ�
			2.��Ƶ��Դ�����
			3.��ʦ��ʱ��صĽ��
			4.����γ̲���(����1��1)
			5.��ʦָ��:ְҵ����
			6.��Ŀʵս
			7.4��ѧϰȨ�� :��ֹ��������,U3D��ǰ��ѧԱ���


*/		

