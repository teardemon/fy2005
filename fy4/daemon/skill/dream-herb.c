inherit SKILL;

void setup() {
	set("name","云梦五花锦");
	set("type","herb");
	set("effective_level",200);
	set("usage/herb",1);
	set("difficulty",200);
	set("skill_class","knight");
}


int valid_learn(object me)
{
	if( me->query_skill("herb", 1) < me->query_skill("dream-herb",1)) {
		return notify_fail("你的药道心法火候不足，无法练云梦五花锦。\n");
	}
	return 1;
}


int help(object me)
{
	write(@HELP   
学习云梦五花锦要求有相同等级的药道为基础。
L50『开谢花』（kaixiehua） 
利用药雾令对手忙乱2-3轮，若失败自身忙乱2轮

L100『朽木功』（xiumugong）
Ｉ：需100级五花锦，气血伤害的抵抗能力+5% 
ＩＩ：需150级五花锦，气血伤害的抵抗能力+10%
ＩＩＩ：需200级五花锦，气血伤害的抵抗能力+15%
		同时使用时不再有自我忙乱。

L100『残云碧』（canyunbi） 
利用毒雾攻击所有对手，如果成功自我忙乱三轮，
如果全部失败则自我忙乱两轮。
每三轮发作一次，持续八轮，
每轮伤害力＝有效药道／２＋random(有效药道/4)

L120『悲酥散』（beisusan）
以毒雾攻击对手，若击中后可吸取敌人内力，并将其转移给自身和队友，
每20秒钟使用一次，自我忙乱两轮
吸取内力＝五花锦等级*2

L140『幻梦落』（huanmengluo）
需结合轩辕斧法使用，召唤出毒灵辅助攻击敌人，
持续时间90秒或至战斗结束，每15分钟使用一次。
此特技阅读卷轴后可增加毒灵的数量。

L170『春去也』（chunquye）
冀药道之力，把人的生机封存起来，战斗中当精气神值小于20%时，
每次受到伤害有20%的几率瞬间恢复精气神，只能生效一次。等级
小于L100，恢复点数3000，等级在L100到L120之间，可恢复4500，
等级L120以上时可以恢复6000。
该特技每1小时才能使用一次，每次持续１小时或到生效为止。

L180『失魂引』(shihunyin)
利用药道将刚死之人的尸体制成药人，（相当于帝王谷的鬼降），
药人存活时间为5分钟，经验值为原来的110%。每5分钟使用一次。

L200『不自持』(buzichi)
另需240级基本药道
降低对手的才智、定力，
降低对手对气血伤害的抵抗能力10%
持续10回合，对BOSS持续时间减半
每10回合使用一次。

L200『玉肌凉』(yujiliang)
另需280级基本药道，利用毒雾攻击单个对手，自我忙乱两轮
此毒效为『残云碧』的一半，命中率更高
每两轮发作一次，持续八轮
伤害力的一半返回为自身气血恢复。

HELP
    );
    return 1;
}
