#include <weapon.h>
inherit BLADE;

void create() {
	set_name("�ر�ն����", ({ "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100000);
		set("weapon_prop/attack",20);
		set("level_required",30);
		set("material", "iron");
//		set("long", "����һѰ���ĵ�����������Լ�����߽��ء�\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
	::init_blade(40);
}