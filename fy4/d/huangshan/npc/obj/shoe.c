// shoe.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( "¹ƤСѥ", ({"boots", "shoes" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "˫");
		set("value", 3000);
		set("armor_prop/armor", 2 );
		set("female_only", 1);
	}
	::init_boots();
}
