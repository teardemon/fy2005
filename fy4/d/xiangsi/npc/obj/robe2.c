#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��ҳ���", ({ "robe" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����ɫ�ĳ��ۡ�\n");
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("value", 1000);
	}
	::init_cloth();
}