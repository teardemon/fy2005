// jinchui.c
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name(HIY"���"NOR, ({ "golden hammer", "hammer" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��ϵķ���ʮ�㣬�ҵ�ͷ�Ͽɲ����档\n");
                set("value", 3);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        ::init_hammer(15);
}