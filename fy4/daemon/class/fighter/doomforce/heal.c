#include <ansi.h>
#include "/daemon/class/GENERIC/FORCE/generic_heal.c"

int exert(object me, object target, int amount)
{
		string msg_self, msg_target,limit, type;
		int cost;
		
		limit = "self";
		amount = me->query_skill("doomforce",1);
		cost = 50;
		msg_self = WHT"$N�������˹����ˣ�����һ���һ��ף����ã��³�һ����Ѫ����ɫ�������ö��ˡ�\n" NOR;
		msg_target = "";
		type = "kee";
		
		general_heal( me, target, "self", amount, cost, msg_self, msg_target, type);				
		return 1;
}