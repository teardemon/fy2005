// 2009 FengYun
// Edit by hippo 2009.11
// 孝道 关联

//inherit ITEM;
#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
    set_name(HIG"孝女花"NOR, ({ "xiaoflower"}));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "盆");
		set("no_split",1);
		set("long","一盆炫丽无比的插花，犹如仙女下凡，此并非人间凡物。\n");
		set("value", 200);
		set("material", "plant");
		set("armor_prop/personality", 20);
		set("armor_prop/armor", 0);
		set("wear_msg", "$N轻轻地把一盆$n戴在头上，瞬间绽放出"HIM"无"HIG"数"HIY"光"HIR"彩"NOR"。\n");
		set("unwield_msg", "$N小心地把$n从头上除了下来。\n");
		set("female_only", 1);   
		set("no_drop",1);
		set("no_get",1);
		set("no_sell",1);
		set("lore",1);

		set("skill", ([
            "name":         "xiaodao",    
           "exp_required": 2150000,      
			"sen_cost":	5,	
			"difficulty":	5,	
            "max_skill":    74,      
		]) );
	}
    	::init_head();
}
