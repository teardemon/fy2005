#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name(RED"±����"NOR, ({ "pigtongue" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
        set("long", "һ��±�������˱ǵ�����ͷ��\n");
        set("unit", "��");
        set("value", 5000);
	set("food_remaining", 3);
	set("food_supply", 60);
	}
	::init_item();
}
