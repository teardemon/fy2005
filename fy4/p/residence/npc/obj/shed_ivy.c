#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("常青藤棚架", ({ "ivy shed"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set("unit", "个");
	set("desc", "一个木棚子，架上爬满了翠绿色的常青藤。\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","j");
	set("outdoors",1);
	set("size",1);
	set("value", 50000);
set("tax",5);
set("score_tax",1);
seteuid(getuid());
}
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
