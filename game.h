//���ڶ�����Ϸ�ĺ��Ľṹ�ͺ���
#include<string.h>
#include<stdio.h>
#include<windows.h>
/*************************��Ϸ�ṹ����***************************/

typedef enum _proptype//��Ϸ��������-���������ߡ�����Ʒ����Ƭ����Ƭ
{
	Weapon,Armor,Con,Card,Frag
}PropType;
typedef struct _prop//��Ϸ����
{
	int id;//���߱��
	char name[50];//��������
	int level;//���ߵȼ�	
	int stock;//��������������������
	int price;//���߼۸�
	PropType type;//��������
	union {//���� ��ѡһ
		int	minAttack;//�����������Ӧ������
		int minDefence;//����Ƿ��߶�Ӧ������
		int minPower;//���������Ʒ��Ӧ��������ֵ
	};
	union {
		int maxAttack;
		int maxDefence;
		int maxPower;
	};
	char desc[300];//��������
}Prop;
typedef struct _bag//��Ϸ����
{
	int bagid;//�������Ӻ�
	int id;//���߱��
	char name[50];//��������
	int level;//���ߵȼ�	
	int stock;//��������������������
	int price;//���߼۸�
	PropType type;//��������
	union {//���� ��ѡһ
		int	minAttack;//�����������Ӧ������
		int minDefence;//����Ƿ��߶�Ӧ������
		int minPower;//���������Ʒ��Ӧ��������ֵ
	};
	union {
		int maxAttack;
		int maxDefence;
		int maxPower;
	};
	char desc[300];//��������
}Bag;
typedef struct _martial
{
	int id;         //���ɱ��
	char name[21];  //��������
	char type[11];  //�������ͣ����ɡ�а�ɡ�������а
	COORD hqCoord;  //�ܲ�����
	int isOpen;     //�Ƿ񿪷�
	char description[1000];//��������
}Martial;
typedef struct _map
{
	int id;
	char name[50];
	int minlevel;
	COORD coord;
	char desc[500];
}Map;
typedef struct _player
{
	int id;
	char name[50];
	COORD pcoord;//������ڵ�ͼ����
	char sex[10];
	int level;
	int exp;
	int hp;
	int mp;//����
	int maxmp;
	int gold;
	Prop weapon;//װ��������
	Prop armor;//����
	Martial martial;//����
	char username[30];//�û���
	char password[30];//����
}Player;
typedef struct _monster
{
	int id;
	char name[50];
	int level;
	int hp;
	int attack;
	int defence;
	int minmoney;//����������С�����
	int maxmoney;
	int exp;//���侭��
	int state;//���ﵱǰ��״̬0��ʾ��������0��ʾ����
	COORD coord;//��������
}Monster;

void init();//��ʼ����Ϸ����
void show();//��ʾȫ������
void showwelcome();//��ʾ��Ϸ�Ļ�ӭ��Ϣ
void showmap();//��ʾ��Ϸ��ͼ
void showinformation();//��ʾ��ͼ�·�����Ϸ��Ϣ
void showmainmenu();//��ʾ���˵�
void showmapinfo();//��ͼ��Ϣ
void showplayerinfo();//չʾ�����Ϣ
void showmonster();//���ҹ���
void monsterfight(Monster *fightmonster, int choice);//����ս��
void returnmartial();//���ܲ�
void showmybag();//�ҵı���
void showshop();//��Ϸ�̵�










