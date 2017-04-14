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
	{ 1, "帝皇天烈剑", 1, 5, 5000, Weapon, .minAttack = 1, .maxAttack = 4,  "上古三皇五帝用过的宝剑" },					
	{ 2, "荆棘之甲", 2, 5, 10000, Armor, .minDefence = 2, .maxDefence = 6,  "取日月之精华，反弹伤害" },					
	{ 3, "玉液琼浆", 3, 5, 15000, Con, .minPower = 100, .maxPower = 500,  "蟠桃会上的御用品，王母娘娘都说好" }
};*/

/*Player players[] = { { 1, "李逍遥", { 3, 3 }, "少林派", "荆棘之甲", "男", 9, 900, 900, 900, 900, 6666,  },
{ 2, "典韦", { 4, 4 }, "武当派", "荆棘之甲", "男", 11, 1200, 1200, 1200, 1200, 10000,   }
};*/
Player players[] = { { 1, "李逍遥", { 3, 3 },   "男", 9, 900, 900, 900, 900, 26666, },
{ 2, "典韦", { 4, 4 },   "男", 11, 1200, 1200, 1200, 1200, 10000, }
};
Prop proparray[] = {
	{ 1, "帝皇天烈剑", 1, 5, 5000, Weapon, 1,4, "上古三皇五帝用过的宝剑" },
	{ 2, "三叉海神戟", 2, 5, 10000, Weapon, 10,15, "重达十万八千斤，威力无穷！" },
	{ 3, "荆棘之甲", 1, 5, 10000, Armor,  2,  6, "取日月之精华，反弹伤害" },
	{ 4, "乌蚕裙", 2,5,10000, Armor,5,8, "极其坚韧，刀枪不入，水火不侵！" },
	{ 5, "玉液琼浆", 3, 5, 15000, Con,  100, 500, "蟠桃会上的御用品，王母娘娘都说好" }
};
Bag bagarray[10] = {
	
	{ 1,2, "三叉海神戟", 2, 5, 10000, Weapon, 10, 15, "重达十万八千斤，威力无穷！" },
	
	{ 2,4, "乌蚕裙", 2, 5, 10000, Armor, 5, 8, "极其坚韧，刀枪不入，水火不侵！" },
	
};
Map maparray[8][8] = { {
						{ 1, "天山", 1, { 0, 0 }, "世界七大山系之一，位于欧亚大陆腹地，东西横跨中国、哈萨克斯坦、吉尔吉斯斯坦和乌兹别克斯坦四国，全长约2500公里，南北平均宽250-350公里，最宽处达800公里以上。" }, { 1, "楼兰", 1, { 1, 0 }, "这里充满了西域文化" },
						{ 1, "白驼山", 1, { 2, 0 }, "武侠小说中常出现的大山，还在游戏新武林外传中的剧本出现过。相关信息位于西域，一说西藏，胜产毒药，例如梁羽生书的神仙丸，金庸笔下的白驼山庄，皆用毒之门派。" }, { 1, "野猪林", 1, { 0, 0 }, "这里充满了西域文化" },
						{ 1, "水晶洞", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "天蚕洞", 1, { 0, 0 }, "这里充满了西域文化" },
						{ 1, "黑风寨", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "冰火岛", 1, { 0, 0 }, "这里充满了西域文化" },
						},				
					 { 
						{ 1, "迷宫", 1, { 0, 1 }, "这里充满了西域文化" }, { 1, "凌霄城", 1, { 0, 0 }, "这里充满了西域文化" },
						{ 1, "轩辕岭", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "华山", 1, { 0, 0 }, "这里充满了西域文化" },
						{ 1, "嵩山", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "紫禁城", 1, { 0, 0 }, "这里充满了西域文化" },
						{ 1, "快活林", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "神龙岛", 1, { 0, 0 }, "这里充满了西域文化" },
					 },
					 {
						 { 1, "西域", 1, { 0, 2 }, "这里充满了西域文化" }, { 1, "葫芦谷", 1, { 0, 0 }, "这里充满了西域文化" },
						 { 1, "唐门", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "终南山", 1, { 0, 0 }, "这里充满了西域文化" },
						 { 1, "石窟", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "客栈", 1, { 0, 0 }, "这里充满了西域文化" },
						 { 1, "玉皇顶", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "灵蛇岛", 1, { 0, 0 }, "这里充满了西域文化" },
					 },
					 {
						 { 1, "光明顶", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "摩天崖", 1, { 0, 0 }, "这里充满了西域文化" },
						 { 1, "聚贤庄", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "后山", 1, { 0, 0 }, "这里充满了西域文化" },
						 { 1, "武当山", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "开封府", 1, { 0, 0 }, "这里充满了西域文化" },
						 { 1, "二四桥", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "蓬莱境", 1, { 0, 0 }, "这里充满了西域文化" },
					 },
					 {
						 { 1, "擂鼓山", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "峨眉山", 1, { 0, 0 }, "这里充满了西域文化" },
						 { 1, "迷踪林", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "五虎岭", 1, { 0, 0 }, "这里充满了西域文化" },
						 { 1, "天宁寺", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "积善堂", 1, { 0, 0 }, "这里充满了西域文化" },
						 { 1, "镇江府", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "桃花岛", 1, { 0, 0 }, "这里充满了西域文化" },
					 },
					 {
						 { 1, "恶人谷", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "大理", 1, { 0, 0 }, "这里充满了西域文化" },
						 { 1, "百花谷", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "孔雀庄", 1, { 0, 0 }, "这里充满了西域文化" },
						 { 1, "五霸岗", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "万仞堂", 1, { 0, 0 }, "这里充满了西域文化" },
						 { 1, "千古刹", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "六合塔", 1, { 0, 0 }, "这里充满了西域文化" },
					 },
					 {
						 { 1, "玩偶庄", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "黑木崖", 1, { 0, 0 }, "这里充满了西域文化" },
						 { 1, "蝴蝶谷", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "铁花堡", 1, { 0, 0 }, "这里充满了西域文化" },
						 { 1, "霹雳堂", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "关帝庙", 1, { 0, 0 }, "这里充满了西域文化" },
						 { 1, "麒麟庄", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "销魂宫", 1, { 0, 0 }, "这里充满了西域文化" },
					 },
					 {
						 { 1, "石府", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "金三角", 1, { 0, 0 }, "这里充满了西域文化" },
						 { 1, "忏悔崖", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "通吃岛", 1, { 0, 0 }, "这里充满了西域文化" },
						 { 1, "通天观", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "紫霞亭", 1, { 0, 0 }, "这里充满了西域文化" },
						 { 1, "天弃庵", 1, { 0, 0 }, "这里充满了西域文化" }, { 1, "侠客岛", 1, { 0, 0 }, "这里充满了西域文化" },
					 },
					
};
Martial martials[20] = {
	{ 1, "少林派", "正派", {4,1}, 1, "中华武学的泰斗，明末，少林众多的人才中，以悟空和箭神二人排为一等。其中，悟空出家为僧，箭神乃俗家弟子。当时江湖人称少林双绝。少林寺中众僧在两大长老的带领下参加了江浙沿海抗击倭寇的战斗，在各路应募兵马中表现得最为骁勇。但正因抗倭之事，也使江湖中的众多门派产生了矛盾，其中首推少林和日月神教。悟空、箭神曾几度带领江湖同仁攻上光明顶，但由于日月神教和血河两派结为同盟，更何况邪派中高手如云，所以几次围剿未果而终，黑白两道都损失惨重" },
	{ 2, "武当派", "正派", {4,3}, 1, "武当在江湖上与少林齐名，有‘北崇少林’‘南尊武当’之说。 武当新一代的首领人物，是一位谦谦君子，一张轮廓分明的脸上总是带着爽朗的笑容，就连他的仇敌都不能不承认他是条少见的男子汉。凡人从十八岁崛起江湖，身经大小三十三战，至今从未败过一次。凡人一生中最不能忍受的两件事就是失败和错误。 " },
	{ 3, "丐帮", "正派", {6,2}, 1, "丐帮是中原武林中人数最为众多的一个门派，也是天下第一大帮派，以遍布天下乞丐的乞丐组成，分为污衣帮和净衣帮。丐帮中人大多都是社会地位比较低的人，但他们各个铮铮硬骨，品格高尚，很少出现卑劣之人。丐帮新一代众多弟子以天葵为首，除暴安良、行侠丈义、抑强扶弱，所作所为为天下人所津津乐道。" },
	{ 4, "全真教", "正派", {3,2}, 1, "全真属于道教的分支之一。现今全真教中最有权威的人是一个瘦瘦小小的人，长着一双冷冷淡淡好象永远不会有什么变化的眼睛，看起来仿佛是灰色的。但他又是一个非常讲究的人，他喜欢紫色，喜欢名马佳人华衣美酒，喜欢享受。对每一件事情他都非常的挑剔，做的每一件事都经过精密计划，绝不肯多浪费一分力气，也不会有一点疏忽。这就是全真海雅。" },
	{ 5, "五岳剑派", "正派", {3,1}, 1, "泰山派，恒山派，衡山派，华山派，嵩山派结为同气枝连的的五岳剑派，在江湖上扬名立万。五派中人一向面和心不和，所以五派的式微不是由于外敌入侵，而纯粹是内部矛盾激化走向内耗的结果，内部的勾心斗角虽然常常以抗倭为借口出现，实则是为了掌握五岳生杀大权。" },
	{ 6, "四川唐门", "正派", {2,2}, 1, "唐门在江湖上以暗器闻名。但自从唐门的唐老太太过世后唐家堡一度家道中落，加之唐甜为称霸武林挑起纷争，又使唐门陷入了再度的浩劫，几乎一蹶不振。在这种危难的时刻唐门出现了一群新生力量：唐纾、唐斩、唐缺、唐玉。他们整顿内务，肃清奸佞，打出了匡复武林正义的旗帜，并且在江湖上行侠仗义，挽回了唐门的声誉，使唐门成为了江湖上的名门正派。" },
	{ 7, "大理段氏", "正派", {1,5}, 1, "大理段氏人丁众多，高手如云。其中有一位名扬江湖顶尖女侠——香雪儿。香雪儿面相灵秀，肤色白皙，但微显瘦弱，看上去弱不禁风却身怀绝世武功，已深得大理武功心得。" },
	{ 8, "天山派", "正派", {0,0}, 1, "天山派是名门正派，也是目前江湖中最为团结的一个门派。天山派也是江湖中女弟子最为众多的一个门派，且各个武功造诣不凡，相貌清秀。" },
	{ 9, "古墓派", "正派", {3,3}, 1, "古墓派这一代的传人名叫暄雯，是一女子，来历不明。暄雯生性娴静，长相俊美，举止飘逸，但做事情却不似师祖小龙女，倒颇有一点杨过的风格，武功修为深不可测，同样喜穿白衣。此派轻功卓越，剑法、拳法灵动妙绝，更是全真教的克星。古墓传人的处世原则是“事不关己，高高挂起”，过着与世无争的日子，但是如果有人冒犯了古墓传人，那他一定会死得很惨。" },
	{ 10, "名捕门", "正派", {5,1}, 1, "名捕门历属与官府，但其中也不乏在江湖上闯出名堂的武林高手。名捕门一等一的人才中有一位绰号叫‘惊天泣鬼’的，此人从不以真面目视人，总是在幕后策划一些事情。" },
	{ 11, "日月神教", "邪派", {1,6}, 1, "由于该教高手众多，并彼此互不相服，所以教务混杂。教中弟子多为邪恶之徒，专与名门正派作对，杀人良多，罪恶昭彰，故被江湖正派之人贬为魔教。" },
	{ 12, "权力帮", "邪派", {6,6}, 1, "邪派之一，目前派中最高首脑为一叫阿飞的年轻人。阿飞，一个表面上异常忧悒的人。没有与其交过手的武林高手，无法想象他那弱不禁风的身躯隐藏着那么大的潜力，更不能想象他是如何用支撑起权利帮的担子的。" },
	{ 13, "五毒教", "邪派", {0,2}, 1, "一个以使毒为专长的门派，派中人各个都是用毒高手。此派高手人称梦魇，其人使毒已入化境，令人难以琢磨，江湖同道对其莫不绕道而行。此人品行时好时坏，但坚韧卓绝，嗜武成痴。" },
	{ 14, "神龙教", "邪派", {7,2}, 1, "神龙教是江湖邪派，由于教址远离中原，所以不大干预中原武林的血腥杀戮。目前神龙教有两位高手一为刀神，此人武功高深莫测，性格孤僻冷傲，不喜与人接近。二为恶龙，武功高强但脾气暴躁，做事没有耐性。" },
	{ 15, "青龙会", "邪派", {6,5}, 1, "江湖上绵延数百年的一个神秘组织。青龙会下分十二堂，分别以月为代号。" },
	{ 16, "桃花岛", "亦正亦邪", {7,4}, 1, "自从东邪黄药师扬名立万于此后，他的传人就在这里绵延不绝，竟将桃花岛建成了门派的总舵。桃花岛黄药师的关门弟子程英一生未嫁，在岛上收了几个徒弟，桃花岛的武功因此得到延续和发扬。" },
	{ 17, "锦衣卫", "亦正亦邪", {5,3}, 1, "大内锦衣卫中人才济济，尤其是雷神，此人野心勃勃，自幼练得一身大力金刚功，号称刀枪不入，武功实是深不可测。而且为人机智，精通兵法，行兵时能将千军万马人使得如同数十万般威力十足。" },
	{ 18, "血河派", "亦正亦邪", {4,2}, 1, "自从血河派的掌门一代大侠方歌吟飘然而去后，血河派日益衰落。血河派活动的范围也越来越少，基本上只限与龙门石窟。而江湖上的九大门派已经把血河派视为邪魔歪道。并已传出英雄令，只要九大门派的门人遇上血河派的人，一律格杀无论。在江湖上已经没有什么血河派的人在行走。除了无恨！没有人知道他来自何方，人们只知道他来自血河派。没有人知道他的武功有多高，因为看见他的剑的人都已经......无恨是武林中的一个谜，现隐居在天山，相传是为了一名叫若寒的女子。相传血河弟子花无缺已深得无恨真传，在无恨隐居江湖期间代理血河的一切帮中事务。花无缺为人善良真诚，在江湖上人缘甚好，并将血河派内外事务打理得井井有条。" },
	{ 19, "通通吃", "亦正亦邪", {3,7}, 1, "江湖上一个神秘的门派，创始人，武功不祥。总舵设在通吃岛，教中首领人物——辉翰。此人手段严酷，以威服人。平常不轻易踏足中原武林，潜心修炼武功。" },
	{ 20, "玩偶山庄", "亦正亦邪", {6,0}, 1, "江湖上一个神秘的门派，创始人，武功不祥。总舵就在玩偶山庄，教中首领人物——阳光。玩偶山庄门人众多，但大都绝迹江湖，只有阳光经常独自浪迹江湖并闯出了名堂，所以武林中人才知有这么一个门派存在。" }
};
Monster monsterarray[] = {
	{ 1, "稻草人", 1, 100, 3, 5, 5, 10, 5, 1, 0,0 },
	{ 2, "海牛大大", 2, 200, 3, 5, 5, 10, 5, 1, 0, 0 },
	{ 3, "飞天小魔女", 3, 300, 3, 5, 5, 10, 5, 1, 0, 0 },
	{ 4, "窜天猴", 4, 400, 3, 5, 5, 10, 5, 1, 0, 0 },
	{ 5, "远古巨龙", 5, 500, 50, 5, 5, 10, 5, 1, 0, 0 },
	{ 6, "纳什男爵", 6, 600, 99, 99, 200, 300, 200, 1, 0, 0 }
};

void init()//初始化
{
	
	currplayer = &players[0];
	currplayer->weapon = proparray[0];
	currplayer->armor = proparray[2];
	currplayer->martial = martials[0];
	setposition(MARGIN_X + 10, gameend_Y - 1);
	printf("按任意键进入江湖");
	_getch();
}

void show()//显示全局数据
{
	int i;
	int propcount = sizeof(proparray) / sizeof(Prop);
	for (i = 0; i < propcount; i++)
	{
		printf("%d\t%s\t%d\t%d\t%.2lf\t\n", proparray[i].id, proparray[i].name, proparray[i].level, proparray[i].stock,proparray[i].price);
		switch (proparray[i].type)
		{
		case Weapon:
			printf("最小攻击力:%d\t最大攻击力:%d\n",proparray[i].minAttack, proparray[i].maxAttack);
			break;
		case Armor:
			printf("最小防御力:%d\t最大防御力:%d\n", proparray[i].minDefence, proparray[i].maxDefence);
			break;
		case Con:
			printf("最小治疗量:%d\t最大治疗量:%d\n", proparray[i].minPower, proparray[i].maxPower);
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
void showmapinfo()//地图信息
{
	int i;
	clear(MARGIN_X + 1, gamestar_Y, 7);
	setposition(MARGIN_X + 25, gamestar_Y);
	printf("当前玩家所在地图为<<%s>>", maparray[Y][X].name);
	setposition(MARGIN_X + 10, gamestar_Y + 1);
	char *desc = maparray[Y][X].desc;
	int length = strlen(desc);//字符串长度
	for (i = 0; i < length; i++)
	{
		if (i != 0 && i % 60 == 0)//多少字换行
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
	printf("玩家信息");
	setposition(MARGIN_X + 10, gamestar_Y+1);
	printf("编号: %d", currplayer->id);
	setposition(MARGIN_X + 35, gamestar_Y + 1);
	printf("名字：%s", currplayer->name);
	setposition(MARGIN_X + 60, gamestar_Y + 1);
	printf("性别：%s", currplayer->sex);
	setposition(MARGIN_X + 10, gamestar_Y + 2);
	printf("等级：%d", currplayer->level);
	setposition(MARGIN_X + 35, gamestar_Y + 2);
	printf("经验：%d", currplayer->exp);
	setposition(MARGIN_X + 60, gamestar_Y + 2);
	printf("血量：%d", currplayer->hp);
	setposition(MARGIN_X + 10, gamestar_Y + 3);
	printf("金币：%d", currplayer->gold);
	setposition(MARGIN_X + 35, gamestar_Y + 3);
	printf("武器：%s", currplayer->weapon.name);
	setposition(MARGIN_X + 60, gamestar_Y + 3);
	printf("防具：%s", currplayer->armor.name);
	setposition(MARGIN_X + 10, gamestar_Y + 4);
	printf("门派：%s", currplayer->martial.name);
	setposition(MARGIN_X + 35, gamestar_Y + 4);
	printf("攻击力:%d-%d", currplayer->weapon.minAttack, currplayer->weapon.maxAttack);
	setposition(MARGIN_X + 60, gamestar_Y + 4);
	printf("防御力:%d-%d", currplayer->armor.minDefence, currplayer->armor.maxDefence);
}

void showmonster()//怪物探查(BUG:怪物信息打印间隔)
{
	int temp;
	int i;
	clear(MARGIN_X + 1, gamestar_Y, 7);
	int searchindex = -1;
	int monstercount = sizeof(monsterarray) / sizeof(Monster);//数组中怪物数量
	int monsterindex[9];//怪物下标
	int currmonstercount = 0;//当前地图怪物数量
	for (i = 0; i < monstercount; i++)
	{
		if (monsterarray[i].coord.X == X&&monsterarray[i].coord.Y == Y&&monsterarray[i].state != 0)
		{
			monsterindex[currmonstercount] = i;
			currmonstercount++;
		}
	}
	setposition(MARGIN_X + 35, gamestar_Y);
	printf("怪物信息");
	if (currmonstercount == 0)
	{
		setposition(MARGIN_X + 4, gamestar_Y + 2);
		printf("此地空荡荡的");
		return;
	}
	setposition(MARGIN_X + 4, gamestar_Y + 2);
	for (i = 0; i < currmonstercount; i++)
	{	
		if (i !=0 &&i % 3 == 0)
		{
			setposition(MARGIN_X +4, gamestar_Y + 2+i/3);
		}
		printf("%d,%s(%d级)\t", i+1, monsterarray[i].name, monsterarray[i].level);
		
	}
	int pkchoice;//输入怪物编号
	
	while (1)
	{
		clear(MARGIN_X + 1, gameend_Y - 1, 1);
		setposition(MARGIN_X + 4, gameend_Y - 1);
		printf("请输入要攻击的怪物编号:");
		
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
			printf("未找到该怪物,输入2继续寻找按0退出:");
			scanf("%d",&temp);
			if (temp == 2)
			{
				showmonster();
			}
			if (temp == 0)
			{
				showinformation();//游戏信息界面
				showmianmenu();//游戏菜单界面
				showmapinfo();//地图信息
			}
			return;
		}
		break;
	}
	monsterfight(&monsterarray[monsterindex[pkchoice - 1]], pkchoice);

}
int fightnum = 0;//战斗成功次数
void monsterfight(Monster *fightmonster, int choice )//怪物战斗
{
	int attack;//玩家攻击力
	int i;
	int length;//怪物数量
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
			printf("怪物%s死亡掉落%d金币大侠《%s》获得%d经验输入2继续战斗输入0退出", fightmonster->name,fightmonster->maxmoney,currplayer->name,fightmonster->exp);
			currplayer->hp = 900;
			currplayer->exp += fightmonster->exp;
			currplayer->gold += fightmonster->maxmoney;
			for (i = 0; i < length; i++)//怪物数组整理
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
				showinformation();//游戏信息界面
				showmianmenu();//游戏菜单界面
				showmapinfo();//地图信息
			}
			break;
		}
		currplayer->hp -= fightmonster->attack;
		if (currplayer->hp <= 0)
		{
			clear(MARGIN_X + 1, gameend_Y - 1, 1);
			setposition(MARGIN_X + 4, gameend_Y - 1);
			printf("江湖快讯大侠《%s》阵亡", currplayer->name);
			currplayer->hp = 900;
			break;
		}
	}
}
void returnmartial()//回总部
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
void showmybag()//我的背包
{
	int tempchoice;//是否使用道具
	char temp[50] = {"宝宝"};//临时变量装备时数组更改用
	int bagchoice;//选择背包中的道具
	int i;
	
	clear(MARGIN_X + 1, gamestar_Y, 7);
	setposition(MARGIN_X + 35, gamestar_Y);
	printf("背包信息");
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
	printf("输入道具的编号可查看道具属性(输入0退出)：");
	scanf("%d",&bagchoice);
	if (bagchoice == 0)
	{
		showinformation();//游戏信息界面
		showmianmenu();//游戏菜单界面
		showmapinfo();//地图信息
		
	}
	if (bagchoice > 0)
	{
		switch (bagarray[bagchoice - 1].type)
		{
		case Weapon:
			clear(MARGIN_X + 1, gamestar_Y, 7);
			setposition(MARGIN_X + 35, gamestar_Y);
			printf("%s属性", bagarray[bagchoice - 1].name);
			setposition(MARGIN_X + 5, gamestar_Y + 1);
			printf("等级：%d\t\t可携带数：%d", bagarray[bagchoice - 1].level,bagarray[bagchoice - 1].stock);
			setposition(MARGIN_X + 5, gamestar_Y + 2);
			printf("最小攻击力：%d\t\t最大攻击力：%d", bagarray[bagchoice - 1].minAttack, bagarray[bagchoice - 1].maxAttack);
			clear(MARGIN_X + 1, gameend_Y - 1, 1);
			setposition(MARGIN_X + 4, gameend_Y - 1);
			printf("再次输入1使用,输入0返回");
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
			printf("%s属性", bagarray[bagchoice - 1].name);
			setposition(MARGIN_X + 5, gamestar_Y + 1);
			printf("等级：%d\t\t可携带数：%d", bagarray[bagchoice - 1].level, bagarray[bagchoice - 1].stock);
			setposition(MARGIN_X + 5, gamestar_Y + 2);
			printf("最小防御力：%d\t\t最大防御力：%d", bagarray[bagchoice - 1].minDefence, bagarray[bagchoice - 1].maxDefence);
			clear(MARGIN_X + 1, gameend_Y - 1, 1);
			setposition(MARGIN_X + 4, gameend_Y - 1);
			printf("再次输入1使用,输入0返回");
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
int bag=2;//背包道具数量

void showshop()//游戏商店
{
	
	int shopchoice;//要购买的商品编号
	int i;
	int lengthprop;//道具数量
	lengthprop = sizeof(proparray) / sizeof(Prop);
	clear(MARGIN_X + 1, gamestar_Y, 7);
	setposition(MARGIN_X + 35, gamestar_Y);
	printf("百货商店");
	setposition(MARGIN_X + 8, gamestar_Y+1);
	for (i = 0; i < lengthprop; i++)
	{
		printf("%d,%-20s等级:%-10d", proparray[i].id, proparray[i].name, proparray[i].level);
		switch (proparray[i].type)
		{
		case Weapon:
			printf("攻击:%d-%d\t价格：%d", proparray[i].minAttack, proparray[i].maxAttack, proparray[i].price);
			break;
		case Armor:
			printf("防御:%d-%d\t价格：%d", proparray[i].minDefence, proparray[i].maxDefence, proparray[i].price);
			break;
		case Con:
			printf("治疗:%d-%d\t价格：%d", proparray[i].minPower, proparray[i].maxPower, proparray[i].price);
			break;

		}
		setposition(MARGIN_X + 8, gamestar_Y + 2 + i);
	}
		
	clear(MARGIN_X + 1, gameend_Y - 1, 1);
	setposition(MARGIN_X + 4, gameend_Y - 1);
	printf("输入要购买的商品编号（按0退出）：");
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
		showinformation();//游戏信息界面
		showmianmenu();//游戏菜单界面
		showmapinfo();//地图信息
		return;

	}
	
	baglength++;
	showmybag();
	return;
}
