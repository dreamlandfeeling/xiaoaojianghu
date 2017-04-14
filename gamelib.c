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


void clear(int a,int b,int line)
{
	int i, j;
	
	for (i = 0; i < line; i++)
	{
		setposition(a, b+i);
		for (j = 0; j < COL-2; j++)
		{
			printf(" ");
		}
	}
}
void settitle(char * title)//修改控制窗口标题
{
	SetConsoleTitle(title);
}
void setcolor(int forecolor, int backcolor)//修改字体颜色（前景色加背景色）
{
	HANDLE winHandle;
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(winHandle, forecolor + backcolor * 0x10);
}
void SetConsoleWindowSize(int width, int height)//设置控制台窗口大小
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置控制台窗口的缓冲区大小
	COORD size = { width, height };
	SetConsoleScreenBufferSize(handle, size);
	//设置控制台窗口大小,最大坐标是缓冲区大小-1
	SMALL_RECT rect = { 0, 0, width - 1, height - 1 };
	SetConsoleWindowInfo(handle, 1, &rect);
}

void setposition(int x, int y)//设置光标位置
{
	HANDLE winHandle;
	COORD pos = {x,y};
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(winHandle, pos);//设置光标坐标
}
void showwelcome()//欢迎界面
{
	setposition(MARGIN_X, 0);
	printf("%s", SEP);
	setposition(MARGIN_X, 1);
	printf("|");
	setposition(MARGIN_X+77, 1);
	printf("|");
	setposition(MARGIN_X + 30, 1);
	printf("%s", Gametitle);
	setposition(MARGIN_X, 2);
	printf("%s\n", SEP);
}

void showinformation()//游戏信息界面
{
	int i;
	for (i = 0; i < 7; i++)
	{
		setposition(MARGIN_X, gamestar_Y+i);
		printf("|");
		setposition(MARGIN_X+77, gamestar_Y + i);
		printf("|");
	}
	setposition(MARGIN_X, gameend_Y);
	printf("%s",SEP);
}
void showmianmenu()//游戏主菜单界面
{
	setposition(MARGIN_X, menustar_Y);
	printf("游戏菜单：");
	setposition(MARGIN_X, menustar_Y+1);
	printf("1、自我欣赏");
	setposition(MARGIN_X, menustar_Y+2);
	printf("2、查找怪物");
	setposition(MARGIN_X, menustar_Y + 3);
	printf("3、回到总部");
	setposition(MARGIN_X, menustar_Y + 4);
	printf("4、我的背包");
	setposition(MARGIN_X, menustar_Y + 5);
	printf("5、购买装备");
	setposition(MARGIN_X, menustar_Y + 6);
	printf("6、退出游戏");
	
}
void entryInterface()//登录界面
{
	showwelcome();//欢迎界面
	showmap();//地图界面
	showinformation();
	clear(MARGIN_X + 1, gamestar_Y, 7);
	setposition(MARGIN_X + 25, gamestar_Y);
	printf("游戏登录");
	setposition(MARGIN_X + 10, gamestar_Y+1);
	printf("1、新玩家注册");
	setposition(MARGIN_X + 10, gamestar_Y + 2);
	printf("2、老玩家回归");
	setposition(MARGIN_X + 10, gamestar_Y + 3);
	printf("3、退出游戏");

		char key;
		key = _getch();
		fflush(stdin);//清空缓存区
		if (key == '1' || key == '2' || key == '3' )
		{
			switch (key)
			{

			case '1':
				playerRegister();
				break;
			case '2':
				init();//初始化游戏信息
				break;
			case '3':
				exit(0);
				break;
			}
		}
		return;
}
Player newplayer[10];
int newplayercount = 0;
extern Martial martials[];
extern Prop proparray[];
extern Player *currplayer;
void playerRegister()//玩家注册
{
	char temppassword[30];//验证两次密码输入是否一样
	int tempmartial;//选门派
	clear(MARGIN_X + 1, gamestar_Y, 7);
	setposition(MARGIN_X + 10, gamestar_Y);
	printf("请输入玩家昵称：");
	scanf("%s",newplayer[newplayercount].name);
	setposition(MARGIN_X + 10, gamestar_Y + 1);
	printf("性别：");
	scanf("%s", newplayer[newplayercount].sex);
	setposition(MARGIN_X + 10, gamestar_Y+2);
	printf("请输入用户名：");
	scanf("%s", newplayer[newplayercount].username);
	setposition(MARGIN_X + 10, gamestar_Y+3);
	printf("请输入密码：");
	scanf("%s", newplayer[newplayercount].password);
	setposition(MARGIN_X + 10, gamestar_Y+4);
	printf("请再一次输入密码：");
	scanf("%s", temppassword);
	if (strcmp(newplayer[newplayercount].password, temppassword) == 0)
	{
		
		clear(MARGIN_X + 1, gamestar_Y, 7);
		setposition(MARGIN_X + 25, gamestar_Y);
		printf("门派列表");
		setposition(MARGIN_X + 10, gamestar_Y+1);
		for (int i = 0; i < martialcount; i++)
		{
			if (i != 0 && i % 4 == 0)
			{
				setposition(MARGIN_X + 10, gamestar_Y + 1 + i/4);
			}
			printf("%-2d,%-10s",i+1,martials[i].name);
		}
		setposition(MARGIN_X + 10, gameend_Y - 1 );
		printf("请输入要选择的门派编号：");
		scanf("%d",&tempmartial);
		newplayer[newplayercount].martial = martials[tempmartial - 1];
		newplayer[newplayercount].id = playercount + 1;
		newplayer[newplayercount].level = 1;
		newplayer[newplayercount].exp = 0;
		newplayer[newplayercount].hp = 100;
		newplayer[newplayercount].mp = 100;
		newplayer[newplayercount].maxmp = 100;
		newplayer[newplayercount].gold = 500000;
		newplayer[newplayercount].weapon = proparray[0];
		newplayer[newplayercount].armor = proparray[2];
		clear(MARGIN_X + 1, gamestar_Y, 7);
		setposition(MARGIN_X + 10, gamestar_Y);
		printf("江湖快讯：大侠<<%s>>诞生",newplayer[newplayercount].name);
		setposition(MARGIN_X + 35, gamestar_Y+1);
		printf("玩家信息");
		setposition(MARGIN_X + 10, gamestar_Y + 2);
		printf("编号: %d", newplayer[newplayercount].id);
		setposition(MARGIN_X + 35, gamestar_Y + 2);
		printf("名字：%s", newplayer[newplayercount].name);
		setposition(MARGIN_X + 60, gamestar_Y + 2);
		printf("性别：%s", newplayer[newplayercount].sex);
		setposition(MARGIN_X + 10, gamestar_Y + 3);
		printf("等级：%d", newplayer[newplayercount].level);
		setposition(MARGIN_X + 35, gamestar_Y + 3);
		printf("经验：%d", newplayer[newplayercount].exp);
		setposition(MARGIN_X + 60, gamestar_Y + 3);
		printf("血量：%d", newplayer[newplayercount].hp);
		setposition(MARGIN_X + 10, gamestar_Y + 4);
		printf("金币：%d", newplayer[newplayercount].gold);
		setposition(MARGIN_X + 35, gamestar_Y + 4);
		printf("武器：%s", newplayer[newplayercount].weapon.name);
		setposition(MARGIN_X + 60, gamestar_Y + 4);
		printf("防具：%s", newplayer[newplayercount].armor.name);
		setposition(MARGIN_X + 10, gamestar_Y + 5);
		printf("门派：%s", newplayer[newplayercount].martial.name);
		setposition(MARGIN_X + 35, gamestar_Y + 5);
		printf("攻击力:%d-%d", newplayer[newplayercount].weapon.minAttack, newplayer[newplayercount].weapon.maxAttack);
		setposition(MARGIN_X + 60, gamestar_Y + 5);
		printf("防御力:%d-%d", newplayer[newplayercount].armor.minDefence, newplayer[newplayercount].armor.maxDefence);
		setposition(MARGIN_X + 10, gamestar_Y + 6);
		currplayer = &newplayer[newplayercount];
		printf("按任意键可进入江湖");
		_getch();
		return;
	}
	if (strcmp(newplayer[newplayercount].password, temppassword) != 0)
	{
		setposition(MARGIN_X + 10, gamestar_Y + 4);
		printf("两次输入的密码不一致,按任意键重新注册");
		_getch();
		playerRegister();
	}
	return;
}
void quitgame()//退出游戏
{
	exit(0);
}
/*int GetKey()

{
	HANDLE handle;          //当前窗口句柄
	handle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Read;
	INPUT_RECORD Event;
	//得到控制台的输入
	ReadConsoleInput(handle, &Event, 1, &Read);
	//如果输入事件是一个键盘事件，就进行判断，返回按下键的虚拟键码
	if (Event.EventType == KEY_EVENT)
	{
		if (Event.Event.KeyEvent.bKeyDown)//返回值为true，表示有键被按下
		{
			return Event.Event.KeyEvent.wVirtualKeyCode;//返回按下键的虚拟键码
		}
	}
	return 0;
}*/
/*void setupgamemenu(char key)//游戏菜单主逻辑
{
	while (1)
	{
		switch (key)
		{
		
		case '1':
			showplayerinfo();
			continue;
		case '2':
			showmonster();
			continue;
		}
	}

}*/
