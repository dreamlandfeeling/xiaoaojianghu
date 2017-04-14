#include<string.h>
#include<stdio.h>
#include<stdio.h>
#include<windows.h>

#define SEP "------------------------------------------------------------------------------"
#define COL 78
#define MARGIN_X  20
#define Gametitle "欢迎来到笑傲江湖"
#define mapstar_Y 3
#define mapend_Y 11
#define gamestar_Y 12
#define gameend_Y 19
#define menustar_Y 20
#define martialcount 20
#define playercount 2



void settitle(char *title);//修改控制窗口标题
void setcolor(int forecolor,int backcolor);//设置文字的前景色和背景色
/* 0-黑色, 1-蓝色,   2-绿色,      3-浅绿色,     4-红色,   5-紫色,   6-黄色,   7-白色,
* 8-灰色, 9-淡蓝色, 10-淡绿色,   11-淡浅绿色   12-淡红色 13-淡紫色 14-淡黄色 15-亮白色
*/
void setposition(int x, int y);//设置光标坐标
void SetConsoleWindowSize(int width, int height);//设置控制台窗口大小
void showwelcome();//欢迎界面
void showmap();//地图界面
void showinformation();//游戏信息界面
void showmianmenu();//游戏主菜单
void clear(int a, int b, int line);//清除
void setupgamemenu(char key);//主菜单设置
void entryInterface();//登录界面
void playerRegister();//玩家注册
void quitgame();//退出游戏