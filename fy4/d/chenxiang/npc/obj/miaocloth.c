#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name(RED"�Ϻ���"NOR, ({ "magcloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        ::init_cloth();
}
