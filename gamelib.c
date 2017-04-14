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
void settitle(char * title)//�޸Ŀ��ƴ��ڱ���
{
	SetConsoleTitle(title);
}
void setcolor(int forecolor, int backcolor)//�޸�������ɫ��ǰ��ɫ�ӱ���ɫ��
{
	HANDLE winHandle;
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(winHandle, forecolor + backcolor * 0x10);
}
void SetConsoleWindowSize(int width, int height)//���ÿ���̨���ڴ�С
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ÿ���̨���ڵĻ�������С
	COORD size = { width, height };
	SetConsoleScreenBufferSize(handle, size);
	//���ÿ���̨���ڴ�С,��������ǻ�������С-1
	SMALL_RECT rect = { 0, 0, width - 1, height - 1 };
	SetConsoleWindowInfo(handle, 1, &rect);
}

void setposition(int x, int y)//���ù��λ��
{
	HANDLE winHandle;
	COORD pos = {x,y};
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(winHandle, pos);//���ù������
}
void showwelcome()//��ӭ����
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

void showinformation()//��Ϸ��Ϣ����
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
void showmianmenu()//��Ϸ���˵�����
{
	setposition(MARGIN_X, menustar_Y);
	printf("��Ϸ�˵���");
	setposition(MARGIN_X, menustar_Y+1);
	printf("1����������");
	setposition(MARGIN_X, menustar_Y+2);
	printf("2�����ҹ���");
	setposition(MARGIN_X, menustar_Y + 3);
	printf("3���ص��ܲ�");
	setposition(MARGIN_X, menustar_Y + 4);
	printf("4���ҵı���");
	setposition(MARGIN_X, menustar_Y + 5);
	printf("5������װ��");
	setposition(MARGIN_X, menustar_Y + 6);
	printf("6���˳���Ϸ");
	
}
void entryInterface()//��¼����
{
	showwelcome();//��ӭ����
	showmap();//��ͼ����
	showinformation();
	clear(MARGIN_X + 1, gamestar_Y, 7);
	setposition(MARGIN_X + 25, gamestar_Y);
	printf("��Ϸ��¼");
	setposition(MARGIN_X + 10, gamestar_Y+1);
	printf("1�������ע��");
	setposition(MARGIN_X + 10, gamestar_Y + 2);
	printf("2������һع�");
	setposition(MARGIN_X + 10, gamestar_Y + 3);
	printf("3���˳���Ϸ");

		char key;
		key = _getch();
		fflush(stdin);//��ջ�����
		if (key == '1' || key == '2' || key == '3' )
		{
			switch (key)
			{

			case '1':
				playerRegister();
				break;
			case '2':
				init();//��ʼ����Ϸ��Ϣ
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
void playerRegister()//���ע��
{
	char temppassword[30];//��֤�������������Ƿ�һ��
	int tempmartial;//ѡ����
	clear(MARGIN_X + 1, gamestar_Y, 7);
	setposition(MARGIN_X + 10, gamestar_Y);
	printf("����������ǳƣ�");
	scanf("%s",newplayer[newplayercount].name);
	setposition(MARGIN_X + 10, gamestar_Y + 1);
	printf("�Ա�");
	scanf("%s", newplayer[newplayercount].sex);
	setposition(MARGIN_X + 10, gamestar_Y+2);
	printf("�������û�����");
	scanf("%s", newplayer[newplayercount].username);
	setposition(MARGIN_X + 10, gamestar_Y+3);
	printf("���������룺");
	scanf("%s", newplayer[newplayercount].password);
	setposition(MARGIN_X + 10, gamestar_Y+4);
	printf("����һ���������룺");
	scanf("%s", temppassword);
	if (strcmp(newplayer[newplayercount].password, temppassword) == 0)
	{
		
		clear(MARGIN_X + 1, gamestar_Y, 7);
		setposition(MARGIN_X + 25, gamestar_Y);
		printf("�����б�");
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
		printf("������Ҫѡ������ɱ�ţ�");
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
		printf("������Ѷ������<<%s>>����",newplayer[newplayercount].name);
		setposition(MARGIN_X + 35, gamestar_Y+1);
		printf("�����Ϣ");
		setposition(MARGIN_X + 10, gamestar_Y + 2);
		printf("���: %d", newplayer[newplayercount].id);
		setposition(MARGIN_X + 35, gamestar_Y + 2);
		printf("���֣�%s", newplayer[newplayercount].name);
		setposition(MARGIN_X + 60, gamestar_Y + 2);
		printf("�Ա�%s", newplayer[newplayercount].sex);
		setposition(MARGIN_X + 10, gamestar_Y + 3);
		printf("�ȼ���%d", newplayer[newplayercount].level);
		setposition(MARGIN_X + 35, gamestar_Y + 3);
		printf("���飺%d", newplayer[newplayercount].exp);
		setposition(MARGIN_X + 60, gamestar_Y + 3);
		printf("Ѫ����%d", newplayer[newplayercount].hp);
		setposition(MARGIN_X + 10, gamestar_Y + 4);
		printf("��ң�%d", newplayer[newplayercount].gold);
		setposition(MARGIN_X + 35, gamestar_Y + 4);
		printf("������%s", newplayer[newplayercount].weapon.name);
		setposition(MARGIN_X + 60, gamestar_Y + 4);
		printf("���ߣ�%s", newplayer[newplayercount].armor.name);
		setposition(MARGIN_X + 10, gamestar_Y + 5);
		printf("���ɣ�%s", newplayer[newplayercount].martial.name);
		setposition(MARGIN_X + 35, gamestar_Y + 5);
		printf("������:%d-%d", newplayer[newplayercount].weapon.minAttack, newplayer[newplayercount].weapon.maxAttack);
		setposition(MARGIN_X + 60, gamestar_Y + 5);
		printf("������:%d-%d", newplayer[newplayercount].armor.minDefence, newplayer[newplayercount].armor.maxDefence);
		setposition(MARGIN_X + 10, gamestar_Y + 6);
		currplayer = &newplayer[newplayercount];
		printf("��������ɽ��뽭��");
		_getch();
		return;
	}
	if (strcmp(newplayer[newplayercount].password, temppassword) != 0)
	{
		setposition(MARGIN_X + 10, gamestar_Y + 4);
		printf("������������벻һ��,�����������ע��");
		_getch();
		playerRegister();
	}
	return;
}
void quitgame()//�˳���Ϸ
{
	exit(0);
}
/*int GetKey()

{
	HANDLE handle;          //��ǰ���ھ��
	handle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Read;
	INPUT_RECORD Event;
	//�õ�����̨������
	ReadConsoleInput(handle, &Event, 1, &Read);
	//��������¼���һ�������¼����ͽ����жϣ����ذ��¼����������
	if (Event.EventType == KEY_EVENT)
	{
		if (Event.Event.KeyEvent.bKeyDown)//����ֵΪtrue����ʾ�м�������
		{
			return Event.Event.KeyEvent.wVirtualKeyCode;//���ذ��¼����������
		}
	}
	return 0;
}*/
/*void setupgamemenu(char key)//��Ϸ�˵����߼�
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
