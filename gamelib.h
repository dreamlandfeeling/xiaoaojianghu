#include<string.h>
#include<stdio.h>
#include<stdio.h>
#include<windows.h>

#define SEP "------------------------------------------------------------------------------"
#define COL 78
#define MARGIN_X  20
#define Gametitle "��ӭ����Ц������"
#define mapstar_Y 3
#define mapend_Y 11
#define gamestar_Y 12
#define gameend_Y 19
#define menustar_Y 20
#define martialcount 20
#define playercount 2



void settitle(char *title);//�޸Ŀ��ƴ��ڱ���
void setcolor(int forecolor,int backcolor);//�������ֵ�ǰ��ɫ�ͱ���ɫ
/* 0-��ɫ, 1-��ɫ,   2-��ɫ,      3-ǳ��ɫ,     4-��ɫ,   5-��ɫ,   6-��ɫ,   7-��ɫ,
* 8-��ɫ, 9-����ɫ, 10-����ɫ,   11-��ǳ��ɫ   12-����ɫ 13-����ɫ 14-����ɫ 15-����ɫ
*/
void setposition(int x, int y);//���ù������
void SetConsoleWindowSize(int width, int height);//���ÿ���̨���ڴ�С
void showwelcome();//��ӭ����
void showmap();//��ͼ����
void showinformation();//��Ϸ��Ϣ����
void showmianmenu();//��Ϸ���˵�
void clear(int a, int b, int line);//���
void setupgamemenu(char key);//���˵�����
void entryInterface();//��¼����
void playerRegister();//���ע��
void quitgame();//�˳���Ϸ