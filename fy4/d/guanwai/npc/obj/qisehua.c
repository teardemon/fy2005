// medicine.c

#include <ansi.h>

inherit MEDICINE;


void create()
{
    	set_name(RED"��ɫ��绨"NOR,({"qisehua"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    	set("long",
"һ���߲ʵ���绨�����˴�˵���ֻ�ֻ�����������ʱ�������ţ�����ʱ����绨
������߹�Ч�ģ�������������1000�㾫�����ˡ�\n");
        	set("unit","��");
        	set("base_unit","��");
        	set("base_value", 6000);
        	set("base_weight",60);
        	set("field","gin");
	    	set("type","cure");
	    	set("effect",1000);
	    	set("heal_type","gin/1000");
	    	set("usage_type","herb");	
	    	set("volumn", 1);
	}
	set_amount(1);
}