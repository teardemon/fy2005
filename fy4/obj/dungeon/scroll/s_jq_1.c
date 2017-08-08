#include <ansi.h>
inherit "/obj/dungeon/scroll.c";

void create()
{
        set_name("静行心法（静志诀）", ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",(: description() :));
                set("value", 1000);
                set("material", "paper");
                
                set("teaching", "fearless");
		set("required_exp", 5000000);
                set("required_class","assassin");
                set("fy41","jq_fearless");
                    
        }
}