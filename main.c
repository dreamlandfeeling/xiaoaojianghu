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



//定义全局变量
int X = 0, Y = 0;
int main()
{
	
	//system("mode con cols=150 lines=150");//修改控制台窗口大小 两种
	SetConsoleWindowSize(121, 31);//修改控制台窗口大小
	settitle("笑傲江湖之精忠报国");//修改控制窗口标题
	setcolor(10, 0);//设置字体颜色
	//init();//初始化游戏信息
	entryInterface();//登录系统
	showwelcome();//欢迎界面
	showmap();//地图界面
	
	showinformation();//游戏信息界面
	showmianmenu();//游戏菜单界面
	showmapinfo();//地图信息	
	while (1)
	{
		char key;
		key = _getch();
		//key = GetKey();
		//printf("%d",key);
		fflush(stdin);//清空缓存区
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
				showmap(X, Y);//地图界面
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
		else if (key == 38 || key == 72){//上
			Y--;
		}
		else if (key == 39 || key ==77 ){//右
			X++;
		}
		else if (key == 40 || key == 80){//下
			Y++;
		}
		else if (key == 37||key==75){//左
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
		showwelcome();//欢迎界面
		showmap(X,Y);//地图界面	
		showinformation();//游戏信息界面
		showmapinfo();
		showmianmenu();//游戏菜单界面
			
	}
}