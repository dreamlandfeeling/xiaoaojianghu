//用于定义游戏的核心结构和函数
#include<string.h>
#include<stdio.h>
#include<windows.h>
/*************************游戏结构类型***************************/

typedef enum _proptype//游戏道具类型-武器、道具、消耗品、卡片、碎片
{
	Weapon,Armor,Con,Card,Frag
}PropType;
typedef struct _prop//游戏道具
{
	int id;//道具编号
	char name[50];//道具名字
	int level;//道具等级	
	int stock;//道具容量（叠加数量）
	int price;//道具价格
	PropType type;//道具种类
	union {//联合 多选一
		int	minAttack;//如果是武器对应攻击力
		int minDefence;//如果是防具对应防御力
		int minPower;//如果是消耗品对应增加能量值
	};
	union {
		int maxAttack;
		int maxDefence;
		int maxPower;
	};
	char desc[300];//道具描述
}Prop;
typedef struct _bag//游戏道具
{
	int bagid;//背包格子号
	int id;//道具编号
	char name[50];//道具名字
	int level;//道具等级	
	int stock;//道具容量（叠加数量）
	int price;//道具价格
	PropType type;//道具种类
	union {//联合 多选一
		int	minAttack;//如果是武器对应攻击力
		int minDefence;//如果是防具对应防御力
		int minPower;//如果是消耗品对应增加能量值
	};
	union {
		int maxAttack;
		int maxDefence;
		int maxPower;
	};
	char desc[300];//道具描述
}Bag;
typedef struct _martial
{
	int id;         //门派编号
	char name[21];  //门派名称
	char type[11];  //门派类型：正派、邪派、亦正亦邪
	COORD hqCoord;  //总部坐标
	int isOpen;     //是否开放
	char description[1000];//门派描述
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
	COORD pcoord;//玩家所在地图坐标
	char sex[10];
	int level;
	int exp;
	int hp;
	int mp;//内力
	int maxmp;
	int gold;
	Prop weapon;//装备的武器
	Prop armor;//防具
	Martial martial;//门派
	char username[30];//用户名
	char password[30];//密码
}Player;
typedef struct _monster
{
	int id;
	char name[50];
	int level;
	int hp;
	int attack;
	int defence;
	int minmoney;//怪物掉落的最小金币数
	int maxmoney;
	int exp;//掉落经验
	int state;//怪物当前的状态0表示死亡，非0表示生存
	COORD coord;//怪物坐标
}Monster;

void init();//初始化游戏数据
void show();//显示全局数据
void showwelcome();//显示游戏的欢迎信息
void showmap();//显示游戏地图
void showinformation();//显示地图下方的游戏信息
void showmainmenu();//显示主菜单
void showmapinfo();//地图信息
void showplayerinfo();//展示玩家信息
void showmonster();//查找怪物
void monsterfight(Monster *fightmonster, int choice);//怪物战斗
void returnmartial();//回总部
void showmybag();//我的背包
void showshop();//游戏商店










