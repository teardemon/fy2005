#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name(HIW"��ط���"NOR, ({ "qingci" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("value", 0);
		set("no_get",1);
	}
	::init_boots();
}

/*
int init()
{
	function f;
	set("armor_worn","̤");
	f = (: call_other, __FILE__, "dodge",attacker, victim :);
	set_temp("dodge_ob",bind(f, this_object()));
}

void dodge(object attacker,object victim)
{
	message_vision(HIW"\n$N == $n",attacker,victim);

}*/