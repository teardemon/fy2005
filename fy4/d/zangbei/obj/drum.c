#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
	set_name("����", ({ "drum", "gu", "����" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 5);
		set("material", "wood");
		set("long", "һ�����ź�˿�������ģ������������ģ�play drum����\n");
	}
	::init_hammer(5);
}

void init()
{
   	if( this_player()==environment())
   		add_action("do_play","play");
}

int do_play(string arg)
{
   	object me, guard;
   	me = this_player();

   	if (!arg || (arg != "gu" && arg !="drum" && arg != "����")) {
      		return 0;
   	}
   	
	guard = present("guard",environment(me));
	if (guard && guard->query("group")=="baiyunzhuang") {
		message_vision(HIM"$N�����鳣����˵����������ģ�����һ����ϲ���š���\n"NOR,me);
		if (!me->query_temp("baiyunzhuang")) {
			me->set_temp("baiyunzhuang",1);
		}
		message_vision(CYN"ׯ����$N˵������ô��ô�����������ȥ�ɣ����Ͼ�Ҫ������ˣ���\n"NOR,me);
	} else
		message_vision("$N�����鳣����˵����������ġ�\n",me);
   	return 1;
}