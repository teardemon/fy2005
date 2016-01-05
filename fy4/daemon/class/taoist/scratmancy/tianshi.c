#include <ansi.h>
inherit F_CLEAN_UP;
#define MAX_GUARD 1

int scribe(object me, object sheet)
{
	object newsheet;
	string err;

	if( me->query("class") != "taoist" ) {
		return notify_fail("只有三清宫弟子才可以画符。\n");
	}
	if( (int)me->query_skill("scratmancy",1) < 100 ) {
		return notify_fail("天师符需要100级的三清符术！\n");
	}
	if( sheet->name() != "桃符纸" ) {
		return notify_fail("天师符要画在桃符纸上！\n");
	}
	if( (int)me->query("mana") < 155 ) {
		return notify_fail("画天师符至少需要155点的法力！\n");
	}
	sheet->set_amount((int)sheet->query_amount() - 1);
	seteuid(geteuid(me));
	newsheet = new("/obj/item/magic_seal");
	newsheet->set_name(YEL"天师符"NOR, ({"tianshi sheet", "sheet"}));
	newsheet->set("burn_func", (: call_other, __FILE__, "do_burn" :));
	newsheet->move(me);
	newsheet->set("burn_person",me);
	me->add("mana", -150);
	me->force_status_msg("mana");
	me->save();
	message_vision("$N写了一道天师符。\n" NOR, me);
	return 1;
}

int do_burn(object sheet)
{
	object obj, soldier, soldier2, me;
	int spells;

	me = this_player();
	if( !me->is_fighting() ) {
		return notify_fail("没有人要杀你！\n");
	}
	if( me->query_temp("max_guard") >= MAX_GUARD ) {
		return notify_fail("你已经召唤太多天界精兵了！\n");
	}
	message_vision("$N集中精神，祭起三味真火，唿的一声" + sheet->name() + "着了起来！\n", this_player());
	me->start_busy(1);
	if( sheet->query("burn_person") != me || random(me->query("mana")) < 10 ) {
		message("vision", "但是什麽也没有发生。\n", environment(me));
		return 1;
	}
	spells = me->query_skill("scratching");
	seteuid(getuid());
	soldier = new("/obj/npc/heaven_soldier");
	if( soldier ) {
		soldier->set("no_purge", 1);
		soldier->move(environment(me));
		soldier->invocation(me, spells);
		soldier->set("init_shout", 1);
		soldier->smart_fight(); // self-buff 
		soldier->delete("init_shout");
		me->add_temp("max_guard", 1);
		message_vision(HIB "\n$N"HIB"躲在$n"HIB"的背后喊道：给我杀！\n" NOR, me, soldier);
		soldier->set("no_purge", 0);
	}
	return 1;
}


/*

　　　     /＼              ／\      
　　　   ▕   ＼＿＿　　　／  ︱       
　　　   ▕ ／￣    ◥██◤╲︱       
　　　    ∕                  ﹨       
　　　    ︳   /￣\    /￣\   ▕      
　　　    ︳   ︳●    ●  ︳ ▕       
　　　   ┼    \ /    \　/    ┼      
　　　    ﹨　      ●      　∕         
　　　    ˉ╲　    　   　／ˉ         
　　　    ╭─◤ˉˉˉ￣◥◤﹨           
　　　   （   ︳           /﹀﹀\◢█    
　　　  （____︳  ▕ ／  ▕ .. █◤     
　　　        \︿︿/ ︺︺︺＼●／         
                       ˉ             
　　　　　　　　- FengYun - 　　　
 　　　　　　　annie 06.2005
 　　　　dancing_faery@hotmail.com

*/
