#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("血石祝融", ({ "ruby statuette"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set("unit", "个");
	set("desc", "一个用鲜红如血的玉石雕成的祝融像，摸一下也许有什么用？（touch ruby statuette）。\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","n");
	set("size",0);
	set("value", 1000000);
set("tax",15);
set("score_tax",2);
	seteuid(getuid());
}


/*

void init()
{
	::init();
	if (environment() != this_player())
	   	add_action("do_touch","touch");
}

int do_touch(string arg)
{
	object me = this_player(),env=environment(me),ob=this_object();
	mapping buff;

	if (!env->is_owner(me->query("id")))
		return notify_fail("屋子里的物件只有主人才能使用。\n");
	if (!arg)
		return 0;
	if (present(arg,env) != ob)
		return 0;
	if (me->is_fighting() || me->is_busy()) return 1;

	message_vision(CYN"$N小心翼翼的用手碰了一下"+name()+"。\n"NOR, me);

	if (!ANNIE_D->check_buff(me,"statue"))
	{
			buff =
			([
				"caster":ob,
				"who":me,
				"type":"statue",
				"att":"bless",
				"name":"夕颜家居·"+name(),
				"buff1":"apply/damage",
				"buff1_c":10,
				"time":900,
				"buff_msg":CYN"$N"CYN"只觉一道寒气慢慢流过身体．．．\n"NOR,
			]);
			ANNIE_D->buffup(buff);
	}else
		tell_object(me,"触手冰冷，但什么也没发生。\n");

	return 1;
}

*/

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
