#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include "game.h"
#include "gamelib.h"
#include<mmsystem.h>



//����ȫ�ֱ���
int X = 0, Y = 0;
int main()
{
	
	//system("mode con cols=150 lines=150");//�޸Ŀ���̨���ڴ�С ����
	SetConsoleWindowSize(121, 31);//�޸Ŀ���̨���ڴ�С
	settitle("Ц������֮���ұ���");//�޸Ŀ��ƴ��ڱ���
	setcolor(10, 0);//����������ɫ
	//init();//��ʼ����Ϸ��Ϣ
	entryInterface();//��¼ϵͳ
	showwelcome();//��ӭ����
	showmap();//��ͼ����
	
	showinformation();//��Ϸ��Ϣ����
	showmianmenu();//��Ϸ�˵�����
	showmapinfo();//��ͼ��Ϣ	
	while (1)
	{
		char key;
		key = _getch();
		//key = GetKey();
		//printf("%d",key);
		fflush(stdin);//��ջ�����
		if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7')
		{
			switch (key)
			{

			case '1':
				showplayerinfo();
				continue;
			case '2':
				showmonster();
				continue;
			case '3':
				returnmartial();
				showmap(X, Y);//��ͼ����
				showmapinfo();
				continue;
			case '4':
				showmybag();
				continue;
			case '5':
				showshop();
				continue;
			case '6':
				exit(0);
				continue;
				
			}
				
		}
		else if (key == 38 || key == 72){//��
			Y--;
		}
		else if (key == 39 || key ==77 ){//��
			X++;
		}
		else if (key == 40 || key == 80){//��
			Y++;
		}
		else if (key == 37||key==75){//��
			X--;
		}
	
		else if (key == '7'){
			exit(0);
		}
		else
		{
			continue;
		}

		if (X > 7) X = 0;
		if (X < 0) X = 7;
		if (Y > 7) Y = 0;
		if (Y < 0) Y = 7;
		system("cls");
		showwelcome();//��ӭ����
		showmap(X,Y);//��ͼ����	
		showinformation();//��Ϸ��Ϣ����
		showmapinfo();
		showmianmenu();//��Ϸ�˵�����
			
	}
}