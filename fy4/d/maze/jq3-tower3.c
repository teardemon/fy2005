// Sinny-silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"�ƽ�������"NOR);
	set("long", @LONG
����һ���ƽ�����������������۵ĻԻ�����ѣĿ����֪���룬ÿһ�㶼 
����Ŀ��Ͼ�ӡ���Ů�������鱦������������������ľ�����Ŀ�Ļƽ𣬵ذ� 
�ǽ��Ӵ���ģ������ǻƽ����ġ������������һ���ƽ�����硣 
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"down" :  __DIR__"jq3-tower2",
		"up":	  __DIR__"jq3-tower4",
	]));
        set("item_desc", ([

	]) );
        set("objects", ([
                __DIR__"npc/jq3-lufengxian" : 1,

 	]) );
	setup();
	
}

int	valid_leave(object who, string dir) {
	object guard;
	if (dir == "up") {
		if ( !REWARD_D->riddle_check(who,"��ս�ƽ���"))
			return notify_fail("�ƽ�����ɱ����Ȼ���������������ֽ��������ٲ�ά�衣\n");
		if (guard = present("lu fengxian",this_object()))
			return notify_fail("��������Цһ��������¥���ȹ�������һ�أ�\n");
	}
	return ::valid_leave(who,dir);
}