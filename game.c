#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include<conio.h>
#include "game.h"
#include "gamelib.h"

extern int X, Y;
Player *currplayer;
Monster *currmonster;

/*Prop proparray[] = {
	{ 1, "�ۻ����ҽ�", 1, 5, 5000, Weapon, .minAttack = 1, .maxAttack = 4,  "�Ϲ���������ù��ı���" },					
	{ 2, "����֮��", 2, 5, 10000, Armor, .minDefence = 2, .maxDefence = 6,  "ȡ����֮�����������˺�" },					
	{ 3, "��Һ��", 3, 5, 15000, Con, .minPower = 100, .maxPower = 500,  "��һ��ϵ�����Ʒ����ĸ���ﶼ˵��" }
};*/

/*Player players[] = { { 1, "����ң", { 3, 3 }, "������", "����֮��", "��", 9, 900, 900, 900, 900, 6666,  },
{ 2, "��Τ", { 4, 4 }, "�䵱��", "����֮��", "��", 11, 1200, 1200, 1200, 1200, 10000,   }
};*/
Player players[] = { { 1, "����ң", { 3, 3 },   "��", 9, 900, 900, 900, 900, 26666, },
{ 2, "��Τ", { 4, 4 },   "��", 11, 1200, 1200, 1200, 1200, 10000, }
};
Prop proparray[] = {
	{ 1, "�ۻ����ҽ�", 1, 5, 5000, Weapon, 1,4, "�Ϲ���������ù��ı���" },
	{ 2, "���溣���", 2, 5, 10000, Weapon, 10,15, "�ش�ʮ���ǧ��������" },
	{ 3, "����֮��", 1, 5, 10000, Armor,  2,  6, "ȡ����֮�����������˺�" },
	{ 4, "�ڲ�ȹ", 2,5,10000, Armor,5,8, "������ͣ���ǹ���룬ˮ���֣�" },
	{ 5, "��Һ��", 3, 5, 15000, Con,  100, 500, "��һ��ϵ�����Ʒ����ĸ���ﶼ˵��" }
};
Bag bagarray[10] = {
	
	{ 1,2, "���溣���", 2, 5, 10000, Weapon, 10, 15, "�ش�ʮ���ǧ��������" },
	
	{ 2,4, "�ڲ�ȹ", 2, 5, 10000, Armor, 5, 8, "������ͣ���ǹ���룬ˮ���֣�" },
	
};
Map maparray[8][8] = { {
						{ 1, "��ɽ", 1, { 0, 0 }, "�����ߴ�ɽϵ֮һ��λ��ŷ�Ǵ�½���أ���������й���������˹̹��������˹˹̹�����ȱ��˹̹�Ĺ���ȫ��Լ2500����ϱ�ƽ����250-350��������800�������ϡ�" }, { 1, "¥��", 1, { 1, 0 }, "��������������Ļ�" },
						{ 1, "����ɽ", 1, { 2, 0 }, "����С˵�г����ֵĴ�ɽ��������Ϸ�������⴫�еľ籾���ֹ��������Ϣλ������һ˵���أ�ʤ����ҩ��������������������裬��ӹ���µİ���ɽׯ�����ö�֮���ɡ�" }, { 1, "Ұ����", 1, { 0, 0 }, "��������������Ļ�" },
						{ 1, "ˮ����", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "��϶�", 1, { 0, 0 }, "��������������Ļ�" },
						{ 1, "�ڷ�կ", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "����", 1, { 0, 0 }, "��������������Ļ�" },
						},				
					 { 
						{ 1, "�Թ�", 1, { 0, 1 }, "��������������Ļ�" }, { 1, "������", 1, { 0, 0 }, "��������������Ļ�" },
						{ 1, "��ԯ��", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "��ɽ", 1, { 0, 0 }, "��������������Ļ�" },
						{ 1, "��ɽ", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "�Ͻ���", 1, { 0, 0 }, "��������������Ļ�" },
						{ 1, "�����", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "������", 1, { 0, 0 }, "��������������Ļ�" },
					 },
					 {
						 { 1, "����", 1, { 0, 2 }, "��������������Ļ�" }, { 1, "��«��", 1, { 0, 0 }, "��������������Ļ�" },
						 { 1, "����", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "����ɽ", 1, { 0, 0 }, "��������������Ļ�" },
						 { 1, "ʯ��", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "��ջ", 1, { 0, 0 }, "��������������Ļ�" },
						 { 1, "��ʶ�", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "���ߵ�", 1, { 0, 0 }, "��������������Ļ�" },
					 },
					 {
						 { 1, "������", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "Ħ����", 1, { 0, 0 }, "��������������Ļ�" },
						 { 1, "����ׯ", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "��ɽ", 1, { 0, 0 }, "��������������Ļ�" },
						 { 1, "�䵱ɽ", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "���⸮", 1, { 0, 0 }, "��������������Ļ�" },
						 { 1, "������", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "������", 1, { 0, 0 }, "��������������Ļ�" },
					 },
					 {
						 { 1, "�޹�ɽ", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "��üɽ", 1, { 0, 0 }, "��������������Ļ�" },
						 { 1, "������", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "�廢��", 1, { 0, 0 }, "��������������Ļ�" },
						 { 1, "������", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "������", 1, { 0, 0 }, "��������������Ļ�" },
						 { 1, "�򽭸�", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "�һ���", 1, { 0, 0 }, "��������������Ļ�" },
					 },
					 {
						 { 1, "���˹�", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "����", 1, { 0, 0 }, "��������������Ļ�" },
						 { 1, "�ٻ���", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "��ȸׯ", 1, { 0, 0 }, "��������������Ļ�" },
						 { 1, "��Ը�", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "������", 1, { 0, 0 }, "��������������Ļ�" },
						 { 1, "ǧ��ɲ", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "������", 1, { 0, 0 }, "��������������Ļ�" },
					 },
					 {
						 { 1, "��żׯ", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "��ľ��", 1, { 0, 0 }, "��������������Ļ�" },
						 { 1, "������", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "������", 1, { 0, 0 }, "��������������Ļ�" },
						 { 1, "������", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "�ص���", 1, { 0, 0 }, "��������������Ļ�" },
						 { 1, "����ׯ", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "���깬", 1, { 0, 0 }, "��������������Ļ�" },
					 },
					 {
						 { 1, "ʯ��", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "������", 1, { 0, 0 }, "��������������Ļ�" },
						 { 1, "�����", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "ͨ�Ե�", 1, { 0, 0 }, "��������������Ļ�" },
						 { 1, "ͨ���", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "��ϼͤ", 1, { 0, 0 }, "��������������Ļ�" },
						 { 1, "������", 1, { 0, 0 }, "��������������Ļ�" }, { 1, "���͵�", 1, { 0, 0 }, "��������������Ļ�" },
					 },
					
};
Martial martials[20] = {
	{ 1, "������", "����", {4,1}, 1, "�л���ѧ��̩������ĩ�������ڶ���˲��У�����պͼ��������Ϊһ�ȡ����У���ճ���Ϊɮ���������׼ҵ��ӡ���ʱ�����˳�����˫��������������ɮ�������ϵĴ����²μ��˽����غ��������ܵ�ս�����ڸ�·Ӧļ�����б��ֵ���Ϊ���¡���������֮�£�Ҳʹ�����е��ڶ����ɲ�����ì�ܣ������������ֺ�������̡���ա����������ȴ��콭��ͬ�ʹ��Ϲ�������������������̺�Ѫ�����ɽ�Ϊͬ�ˣ����ο�а���и������ƣ����Լ���Χ��δ�����գ��ڰ���������ʧ����" },
	{ 2, "�䵱��", "����", {4,3}, 1, "�䵱�ڽ������������������С��������֡��������䵱��֮˵�� �䵱��һ�������������һλǫǫ���ӣ�һ�������������������Ǵ���ˬ�ʵ�Ц�ݣ��������ĳ�ж����ܲ������������ټ������Ӻ������˴�ʮ�������𽭺�������С��ʮ��ս�������δ�ܹ�һ�Ρ�����һ����������ܵ������¾���ʧ�ܺʹ��� " },
	{ 3, "ؤ��", "����", {6,2}, 1, "ؤ������ԭ������������Ϊ�ڶ��һ�����ɣ�Ҳ�����µ�һ����ɣ��Ա鲼������ؤ����ؤ��ɣ���Ϊ���°�;��°ؤ�����˴�඼������λ�Ƚϵ͵��ˣ������Ǹ�����Ӳ�ǣ�Ʒ����У����ٳ��ֱ���֮�ˡ�ؤ����һ���ڶ���������Ϊ�ף������������������塢��ǿ������������ΪΪ������������ֵ���" },
	{ 4, "ȫ���", "����", {3,2}, 1, "ȫ�����ڵ��̵ķ�֧֮һ���ֽ�ȫ���������Ȩ��������һ������СС���ˣ�����һ˫���䵭��������Զ������ʲô�仯���۾����������·��ǻ�ɫ�ġ���������һ���ǳ��������ˣ���ϲ����ɫ��ϲ��������˻������ƣ�ϲ�����ܡ���ÿһ�����������ǳ������ޣ�����ÿһ���¶��������ܼƻ��������϶��˷�һ��������Ҳ������һ������������ȫ�溣�š�" },
	{ 5, "��������", "����", {3,1}, 1, "̩ɽ�ɣ���ɽ�ɣ���ɽ�ɣ���ɽ�ɣ���ɽ�ɽ�Ϊͬ��֦���ĵ��������ɣ��ڽ���������������������һ������Ĳ��ͣ��������ɵ�ʽ΢��������������֣����������ڲ�ì�ܼ��������ںĵĽ�����ڲ��Ĺ��Ķ�����Ȼ�����Կ���Ϊ��ڳ��֣�ʵ����Ϊ������������ɱ��Ȩ��" },
	{ 6, "�Ĵ�����", "����", {2,2}, 1, "�����ڽ������԰������������Դ����ŵ�����̫̫�������Ƽұ�һ�ȼҵ����䣬��֮����Ϊ�ư����������������ʹ�����������ٶȵĺƽ٣�����һ�겻��������Σ�ѵ�ʱ�����ų�����һȺ������������磡���ն����ȱ�������������������������������˿︴������������ģ������ڽ������������壬��������ŵ�������ʹ���ų�Ϊ�˽����ϵ��������ɡ�" },
	{ 7, "�������", "����", {1,5}, 1, "��������˶��ڶ࣬�������ơ�������һλ���ｭ������Ů��������ѩ������ѩ���������㣬��ɫ��𪣬��΢������������ȥ��������ȴ�������书������ô����书�ĵá�" },
	{ 8, "��ɽ��", "����", {0,0}, 1, "��ɽ�����������ɣ�Ҳ��Ŀǰ��������Ϊ�Ž��һ�����ɡ���ɽ��Ҳ�ǽ�����Ů������Ϊ�ڶ��һ�����ɣ��Ҹ����书���費������ò���㡣" },
	{ 9, "��Ĺ��", "����", {3,3}, 1, "��Ĺ����һ���Ĵ���������������һŮ�ӣ�������������������浾������࿡������ֹƮ�ݣ���������ȴ����ʦ��С��Ů��������һ������ķ���书��Ϊ��ɲ⣬ͬ��ϲ�����¡������Ṧ׿Խ��������ȭ���鶯���������ȫ��̵Ŀ��ǡ���Ĺ���˵Ĵ���ԭ���ǡ��²��ؼ����߸߹��𡱣������������������ӣ������������ð���˹�Ĺ���ˣ�����һ�������úܲҡ�" },
	{ 10, "������", "����", {5,1}, 1, "������������ٸ���������Ҳ�����ڽ����ϴ������õ����ָ��֡�������һ��һ���˲�����һλ�ºŽС����������ģ����˴Ӳ�������Ŀ���ˣ�������Ļ��߻�һЩ���顣" },
	{ 11, "�������", "а��", {1,6}, 1, "���ڸý̸����ڶ࣬���˴˻�����������Խ�����ӡ����е��Ӷ�Ϊа��֮ͽ��ר�������������ԣ�ɱ�����࣬������ã��ʱ���������֮�˱�Ϊħ�̡�" },
	{ 12, "Ȩ����", "а��", {6,6}, 1, "а��֮һ��Ŀǰ�����������Ϊһ�а��ɵ������ˡ����ɣ�һ���������쳣��㨵��ˡ�û�����佻���ֵ����ָ��֣��޷������������������������������ô���Ǳ�����������������������֧����Ȩ����ĵ��ӵġ�" },
	{ 13, "�嶾��", "а��", {0,2}, 1, "һ����ʹ��Ϊר�������ɣ������˸��������ö����֡����ɸ����˳����ʣ�����ʹ�����뻯��������������ĥ������ͬ������Ī���Ƶ����С�����Ʒ��ʱ��ʱ����������׿��������ɳա�" },
	{ 14, "������", "а��", {7,2}, 1, "�������ǽ���а�ɣ����ڽ�ַԶ����ԭ�����Բ����Ԥ��ԭ���ֵ�Ѫ��ɱ¾��Ŀǰ����������λ����һΪ���񣬴����书����Ī�⣬�Ը��Ƨ�������ϲ���˽ӽ�����Ϊ�������书��ǿ��Ƣ�����꣬����û�����ԡ�" },
	{ 15, "������", "а��", {6,5}, 1, "�����������������һ��������֯���������·�ʮ���ã��ֱ�����Ϊ���š�" },
	{ 16, "�һ���", "������а", {7,4}, 1, "�ԴӶ�а��ҩʦ���������ڴ˺����Ĵ��˾����������Ӳ����������һ������������ɵ��ܶ档�һ�����ҩʦ�Ĺ��ŵ��ӳ�Ӣһ��δ�ޣ��ڵ������˼���ͽ�ܣ��һ������书��˵õ������ͷ��" },
	{ 17, "������", "������а", {5,3}, 1, "���ڽ��������˲żüã����������񣬴���Ұ�Ĳ�������������һ�������չ����ųƵ�ǹ���룬�书ʵ����ɲ⡣����Ϊ�˻��ǣ���ͨ�������б�ʱ�ܽ�ǧ��������ʹ����ͬ��ʮ�������ʮ�㡣" },
	{ 18, "Ѫ����", "������а", {4,2}, 1, "�Դ�Ѫ���ɵ�����һ������������ƮȻ��ȥ��Ѫ��������˥�䡣Ѫ���ɻ�ķ�ΧҲԽ��Խ�٣�������ֻ��������ʯ�ߡ��������ϵľŴ������Ѿ���Ѫ������Ϊаħ��������Ѵ���Ӣ���ֻҪ�Ŵ����ɵ���������Ѫ���ɵ��ˣ�һ�ɸ�ɱ���ۡ��ڽ������Ѿ�û��ʲôѪ���ɵ��������ߡ������޺ޣ�û����֪�������Ժη�������ֻ֪��������Ѫ���ɡ�û����֪�������书�ж�ߣ���Ϊ�������Ľ����˶��Ѿ�......�޺��������е�һ���գ�����������ɽ���ഫ��Ϊ��һ����������Ů�ӡ��ഫѪ�ӵ��ӻ���ȱ������޺��洫�����޺����ӽ����ڼ����Ѫ�ӵ�һ�а������񡣻���ȱΪ��������ϣ��ڽ�������Ե���ã�����Ѫ���������������þ���������" },
	{ 19, "ͨͨ��", "������а", {3,7}, 1, "������һ�����ص����ɣ���ʼ�ˣ��书���顣�ܶ�����ͨ�Ե�����������������Ժ��������ֶ��Ͽᣬ�������ˡ�ƽ��������̤����ԭ���֣�Ǳ�������书��" },
	{ 20, "��żɽׯ", "������а", {6,0}, 1, "������һ�����ص����ɣ���ʼ�ˣ��书���顣�ܶ������żɽׯ������������������⡣��żɽׯ�����ڶ࣬���󶼾���������ֻ�����⾭�������˼����������������ã������������˲�֪����ôһ�����ɴ��ڡ�" }
};
Monster monsterarray[] = {
	{ 1, "������", 1, 100, 3, 5, 5, 10, 5, 1, 0,0 },
	{ 2, "��ţ���", 2, 200, 3, 5, 5, 10, 5, 1, 0, 0 },
	{ 3, "����СħŮ", 3, 300, 3, 5, 5, 10, 5, 1, 0, 0 },
	{ 4, "�����", 4, 400, 3, 5, 5, 10, 5, 1, 0, 0 },
	{ 5, "Զ�ž���", 5, 500, 50, 5, 5, 10, 5, 1, 0, 0 },
	{ 6, "��ʲ�о�", 6, 600, 99, 99, 200, 300, 200, 1, 0, 0 }
};

void init()//��ʼ��
{
	
	currplayer = &players[0];
	currplayer->weapon = proparray[0];
	currplayer->armor = proparray[2];
	currplayer->martial = martials[0];
	setposition(MARGIN_X + 10, gameend_Y - 1);
	printf("����������뽭��");
	_getch();
}

void show()//��ʾȫ������
{
	int i;
	int propcount = sizeof(proparray) / sizeof(Prop);
	for (i = 0; i < propcount; i++)
	{
		printf("%d\t%s\t%d\t%d\t%.2lf\t\n", proparray[i].id, proparray[i].name, proparray[i].level, proparray[i].stock,proparray[i].price);
		switch (proparray[i].type)
		{
		case Weapon:
			printf("��С������:%d\t��󹥻���:%d\n",proparray[i].minAttack, proparray[i].maxAttack);
			break;
		case Armor:
			printf("��С������:%d\t��������:%d\n", proparray[i].minDefence, proparray[i].maxDefence);
			break;
		case Con:
			printf("��С������:%d\t���������:%d\n", proparray[i].minPower, proparray[i].maxPower);
			break;
		}
		printf("%s\n", proparray[i].desc);
	}
}




void showmap()
{
	
	int i, j;
	for (i = 0; i < 8; i++)
	{
		setposition(MARGIN_X, i + 3);
		printf("|");
		for (j = 0; j < 8; j++)
		{
			if (i == Y &&j == X)
			{
				setcolor(9, 0);
			}
			printf("%-10s", maparray[i][j].name);
			setcolor(10, 0);			
		}
		setposition(MARGIN_X + 77, i + mapstar_Y);
		printf("|");
		printf("\n");
		setposition(MARGIN_X, mapend_Y);
		printf("%s", SEP);
		
	}
}
void showmapinfo()//��ͼ��Ϣ
{
	int i;
	clear(MARGIN_X + 1, gamestar_Y, 7);
	setposition(MARGIN_X + 25, gamestar_Y);
	printf("��ǰ������ڵ�ͼΪ<<%s>>", maparray[Y][X].name);
	setposition(MARGIN_X + 10, gamestar_Y + 1);
	char *desc = maparray[Y][X].desc;
	int length = strlen(desc);//�ַ�������
	for (i = 0; i < length; i++)
	{
		if (i != 0 && i % 60 == 0)//�����ֻ���
		{
			setposition(MARGIN_X + 10, gamestar_Y + 1 + i / 60);
		}
		printf("%c", desc[i]);
	}
}
void showplayerinfo()
{	
	clear(MARGIN_X + 1, gamestar_Y, 7);
	setposition(MARGIN_X + 35, gamestar_Y);
	printf("�����Ϣ");
	setposition(MARGIN_X + 10, gamestar_Y+1);
	printf("���: %d", currplayer->id);
	setposition(MARGIN_X + 35, gamestar_Y + 1);
	printf("���֣�%s", currplayer->name);
	setposition(MARGIN_X + 60, gamestar_Y + 1);
	printf("�Ա�%s", currplayer->sex);
	setposition(MARGIN_X + 10, gamestar_Y + 2);
	printf("�ȼ���%d", currplayer->level);
	setposition(MARGIN_X + 35, gamestar_Y + 2);
	printf("���飺%d", currplayer->exp);
	setposition(MARGIN_X + 60, gamestar_Y + 2);
	printf("Ѫ����%d", currplayer->hp);
	setposition(MARGIN_X + 10, gamestar_Y + 3);
	printf("��ң�%d", currplayer->gold);
	setposition(MARGIN_X + 35, gamestar_Y + 3);
	printf("������%s", currplayer->weapon.name);
	setposition(MARGIN_X + 60, gamestar_Y + 3);
	printf("���ߣ�%s", currplayer->armor.name);
	setposition(MARGIN_X + 10, gamestar_Y + 4);
	printf("���ɣ�%s", currplayer->martial.name);
	setposition(MARGIN_X + 35, gamestar_Y + 4);
	printf("������:%d-%d", currplayer->weapon.minAttack, currplayer->weapon.maxAttack);
	setposition(MARGIN_X + 60, gamestar_Y + 4);
	printf("������:%d-%d", currplayer->armor.minDefence, currplayer->armor.maxDefence);
}

void showmonster()//����̽��(BUG:������Ϣ��ӡ���)
{
	int temp;
	int i;
	clear(MARGIN_X + 1, gamestar_Y, 7);
	int searchindex = -1;
	int monstercount = sizeof(monsterarray) / sizeof(Monster);//�����й�������
	int monsterindex[9];//�����±�
	int currmonstercount = 0;//��ǰ��ͼ��������
	for (i = 0; i < monstercount; i++)
	{
		if (monsterarray[i].coord.X == X&&monsterarray[i].coord.Y == Y&&monsterarray[i].state != 0)
		{
			monsterindex[currmonstercount] = i;
			currmonstercount++;
		}
	}
	setposition(MARGIN_X + 35, gamestar_Y);
	printf("������Ϣ");
	if (currmonstercount == 0)
	{
		setposition(MARGIN_X + 4, gamestar_Y + 2);
		printf("�˵ؿյ�����");
		return;
	}
	setposition(MARGIN_X + 4, gamestar_Y + 2);
	for (i = 0; i < currmonstercount; i++)
	{	
		if (i !=0 &&i % 3 == 0)
		{
			setposition(MARGIN_X +4, gamestar_Y + 2+i/3);
		}
		printf("%d,%s(%d��)\t", i+1, monsterarray[i].name, monsterarray[i].level);
		
	}
	int pkchoice;//���������
	
	while (1)
	{
		clear(MARGIN_X + 1, gameend_Y - 1, 1);
		setposition(MARGIN_X + 4, gameend_Y - 1);
		printf("������Ҫ�����Ĺ�����:");
		
		scanf("%d", &pkchoice);
		for (i = 0; i < currmonstercount; i++)
		{
			if (monsterindex[i] == pkchoice-1)
			{
				searchindex = 1;
				break;
			}
		}
		if (searchindex == -1)
		{
			clear(MARGIN_X + 1, gameend_Y - 1, 1);
			setposition(MARGIN_X + 4, gameend_Y - 1);
			printf("δ�ҵ��ù���,����2����Ѱ�Ұ�0�˳�:");
			scanf("%d",&temp);
			if (temp == 2)
			{
				showmonster();
			}
			if (temp == 0)
			{
				showinformation();//��Ϸ��Ϣ����
				showmianmenu();//��Ϸ�˵�����
				showmapinfo();//��ͼ��Ϣ
			}
			return;
		}
		break;
	}
	monsterfight(&monsterarray[monsterindex[pkchoice - 1]], pkchoice);

}
int fightnum = 0;//ս���ɹ�����
void monsterfight(Monster *fightmonster, int choice )//����ս��
{
	int attack;//��ҹ�����
	int i;
	int length;//��������
	int temp;
	length = sizeof(monsterarray) / sizeof(Monster);
	clear(MARGIN_X + 1, gameend_Y - 1, 1);
	setposition(MARGIN_X + 4, gameend_Y - 1);
	
	while (1)
	{
		srand((unsigned)time(0));
		attack = rand() % (currplayer->weapon.maxAttack - currplayer->weapon.minAttack + 1) + currplayer->weapon.minAttack;
		fightmonster->hp -= attack;
		if (fightmonster->hp <= 0)
		{
			clear(MARGIN_X + 1, gameend_Y - 1, 1);
			setposition(MARGIN_X + 4, gameend_Y - 1);
			printf("����%s��������%d��Ҵ�����%s�����%d��������2����ս������0�˳�", fightmonster->name,fightmonster->maxmoney,currplayer->name,fightmonster->exp);
			currplayer->hp = 900;
			currplayer->exp += fightmonster->exp;
			currplayer->gold += fightmonster->maxmoney;
			for (i = 0; i < length; i++)//������������
			{
				strcpy(monsterarray[choice + i -1].name, monsterarray[choice + i ].name);
				monsterarray[choice + i - 1].id = monsterarray[choice + i].id;
				monsterarray[choice + i - 1].level = monsterarray[choice + i].level;
				monsterarray[choice + i - 1].attack = monsterarray[choice + i].attack;
				monsterarray[choice + i - 1].hp = monsterarray[choice + i].hp;
				
			}	
			monsterarray[length - 1 - fightnum].coord.X = 99;
			monsterarray[length - 1 - fightnum].coord.Y = 99;
			fightnum++;
			scanf("%d", &temp);
			if (temp == 2)
			{
				showmonster();
			}
			if (temp == 0)
			{
				showinformation();//��Ϸ��Ϣ����
				showmianmenu();//��Ϸ�˵�����
				showmapinfo();//��ͼ��Ϣ
			}
			break;
		}
		currplayer->hp -= fightmonster->attack;
		if (currplayer->hp <= 0)
		{
			clear(MARGIN_X + 1, gameend_Y - 1, 1);
			setposition(MARGIN_X + 4, gameend_Y - 1);
			printf("������Ѷ������%s������", currplayer->name);
			currplayer->hp = 900;
			break;
		}
	}
}
void returnmartial()//���ܲ�
{
	int i;
	int length=sizeof(martials)/sizeof(Martial);
	
	for (i = 0; i < length; i++)
	{
		if (strcmp(currplayer->martial.name, martials[i].name) == 0)
		{
			X = martials[i].hqCoord.X;
			Y = martials[i].hqCoord.Y;
		}
	}
}
int baglength = sizeof(bagarray) / sizeof(Bag);
void showmybag()//�ҵı���
{
	int tempchoice;//�Ƿ�ʹ�õ���
	char temp[50] = {"����"};//��ʱ����װ��ʱ���������
	int bagchoice;//ѡ�񱳰��еĵ���
	int i;
	
	clear(MARGIN_X + 1, gamestar_Y, 7);
	setposition(MARGIN_X + 35, gamestar_Y);
	printf("������Ϣ");
	setposition(MARGIN_X + 10, gamestar_Y + 1);
	for (i = 0; i < baglength; i++)
	{
		if (i != 0 && i % 3 == 0)
		{
			setposition(MARGIN_X + 10, gamestar_Y + 1 + i / 3);
		}
		if (bagarray[i].id == 0)
		{
			break;

		}
		printf("%d,%s\t\t", i+1, bagarray[i].name);
	}
	clear(MARGIN_X + 1, gameend_Y - 1, 1);
	setposition(MARGIN_X + 4, gameend_Y - 1);
	printf("������ߵı�ſɲ鿴��������(����0�˳�)��");
	scanf("%d",&bagchoice);
	if (bagchoice == 0)
	{
		showinformation();//��Ϸ��Ϣ����
		showmianmenu();//��Ϸ�˵�����
		showmapinfo();//��ͼ��Ϣ
		
	}
	if (bagchoice > 0)
	{
		switch (bagarray[bagchoice - 1].type)
		{
		case Weapon:
			clear(MARGIN_X + 1, gamestar_Y, 7);
			setposition(MARGIN_X + 35, gamestar_Y);
			printf("%s����", bagarray[bagchoice - 1].name);
			setposition(MARGIN_X + 5, gamestar_Y + 1);
			printf("�ȼ���%d\t\t��Я������%d", bagarray[bagchoice - 1].level,bagarray[bagchoice - 1].stock);
			setposition(MARGIN_X + 5, gamestar_Y + 2);
			printf("��С��������%d\t\t��󹥻�����%d", bagarray[bagchoice - 1].minAttack, bagarray[bagchoice - 1].maxAttack);
			clear(MARGIN_X + 1, gameend_Y - 1, 1);
			setposition(MARGIN_X + 4, gameend_Y - 1);
			printf("�ٴ�����1ʹ��,����0����");
			scanf("%d", &tempchoice);
			if (tempchoice ==1 )
			{
				strcpy(temp, currplayer->weapon.name);
				strcpy(currplayer->weapon.name, bagarray[bagchoice-1].name);
				strcpy(bagarray[bagchoice - 1].name, temp);
				bagarray[bagchoice - 1].id = proparray[bagchoice - 1].id;
				showmybag();
			}
			if (tempchoice == 0)
			{
				showmybag();
			}
			break;
		case Armor:
			clear(MARGIN_X + 1, gamestar_Y, 7);
			setposition(MARGIN_X + 35, gamestar_Y);
			printf("%s����", bagarray[bagchoice - 1].name);
			setposition(MARGIN_X + 5, gamestar_Y + 1);
			printf("�ȼ���%d\t\t��Я������%d", bagarray[bagchoice - 1].level, bagarray[bagchoice - 1].stock);
			setposition(MARGIN_X + 5, gamestar_Y + 2);
			printf("��С��������%d\t\t����������%d", bagarray[bagchoice - 1].minDefence, bagarray[bagchoice - 1].maxDefence);
			clear(MARGIN_X + 1, gameend_Y - 1, 1);
			setposition(MARGIN_X + 4, gameend_Y - 1);
			printf("�ٴ�����1ʹ��,����0����");
			scanf("%d", &tempchoice);
			if (tempchoice == 1)
			{
				strcpy(temp, currplayer->armor.name);
				strcpy(currplayer->armor.name, bagarray[bagchoice - 1].name);
				strcpy(bagarray[bagchoice - 1].name, temp);
				showmybag();
			}
			if (tempchoice == 0)
			{
				showmybag();
			}
			break;
		}
	}
	
}
int bag=2;//������������

void showshop()//��Ϸ�̵�
{
	
	int shopchoice;//Ҫ�������Ʒ���
	int i;
	int lengthprop;//��������
	lengthprop = sizeof(proparray) / sizeof(Prop);
	clear(MARGIN_X + 1, gamestar_Y, 7);
	setposition(MARGIN_X + 35, gamestar_Y);
	printf("�ٻ��̵�");
	setposition(MARGIN_X + 8, gamestar_Y+1);
	for (i = 0; i < lengthprop; i++)
	{
		printf("%d,%-20s�ȼ�:%-10d", proparray[i].id, proparray[i].name, proparray[i].level);
		switch (proparray[i].type)
		{
		case Weapon:
			printf("����:%d-%d\t�۸�%d", proparray[i].minAttack, proparray[i].maxAttack, proparray[i].price);
			break;
		case Armor:
			printf("����:%d-%d\t�۸�%d", proparray[i].minDefence, proparray[i].maxDefence, proparray[i].price);
			break;
		case Con:
			printf("����:%d-%d\t�۸�%d", proparray[i].minPower, proparray[i].maxPower, proparray[i].price);
			break;

		}
		setposition(MARGIN_X + 8, gamestar_Y + 2 + i);
	}
		
	clear(MARGIN_X + 1, gameend_Y - 1, 1);
	setposition(MARGIN_X + 4, gameend_Y - 1);
	printf("����Ҫ�������Ʒ��ţ���0�˳�����");
	scanf("%d",&shopchoice);
	if (shopchoice > 0 || shopchoice <= lengthprop)
	{
		bagarray[bag].id = proparray[shopchoice - 1].id;
		strcpy(bagarray[bag].name, proparray[shopchoice - 1].name);
		bagarray[bag].bagid = bag;
		currplayer->gold -= proparray[shopchoice - 1].price;
		bagarray[bag].stock = proparray[shopchoice - 1].stock;
		bagarray[bag].level = proparray[shopchoice - 1].level;
		bagarray[bag].price = proparray[shopchoice - 1].price;
		strcpy(bagarray[bag].desc, proparray[shopchoice - 1].desc);
		switch (proparray[shopchoice-1].type)
		{
		case Weapon:
			bagarray[bag].minAttack = proparray[shopchoice - 1].minAttack;
			bagarray[bag].maxAttack = proparray[shopchoice - 1].maxAttack;
			bagarray[bag].type = Weapon;
			break;
			case Armor:
				bagarray[bag].minDefence = proparray[shopchoice - 1].minDefence;
				bagarray[bag].maxDefence = proparray[shopchoice - 1].maxDefence;
				bagarray[bag].type = Armor;
			break;
		case Con:
			bagarray[bag].minPower = proparray[shopchoice - 1].minPower;
			bagarray[bag].maxPower = proparray[shopchoice - 1].maxPower;
			bagarray[bag].type = Con;
			break;
		
		}
		
		bag++;
	}
	if (shopchoice == 0)
	{
		showinformation();//��Ϸ��Ϣ����
		showmianmenu();//��Ϸ�˵�����
		showmapinfo();//��ͼ��Ϣ
		return;

	}
	
	baglength++;
	showmybag();
	return;
}
