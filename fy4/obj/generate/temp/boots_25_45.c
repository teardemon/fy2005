#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(YEL"马靴"NOR, ({ "boots"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 20);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 0);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 2);
		set("armor_prop/karma", 1);
		set("armor_prop/max_gin", 40);
		set("armor_prop/max_kee", 30);
		set("armor_prop/max_sen", 0);
		set("long","沙漠商队中常见的马靴。\n");	// 已废弃
	}
	::init_boots();
}
