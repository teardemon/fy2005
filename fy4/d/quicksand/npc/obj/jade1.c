// pink_cloth.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("����", ({ "jade"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ε�������\n");
		set("unit", "��");
		set("value", 10000);
		set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
		set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");

		set("female_only", 1);

	}
	::init_head();
}
