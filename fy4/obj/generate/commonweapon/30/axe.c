#include <weapon.h>
inherit AXE;

void create() {
	set_name("���Ƹ�", ({ "axe" }) );
	set_weight(8000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 20000);
		set("weapon_prop/attack",15);
		set("level_required",20);
		set("material", "iron");
		set("wield_msg", "$N�ӱ�����$n��������������Ȼ���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
	::init_axe(30);
}