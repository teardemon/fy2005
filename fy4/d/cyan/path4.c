// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "ɽ��");
    set("long", @LONG
�����ɽ�������ɽ�������������ɽ϶��ǡ��Щ����·���м��������
���Ǽ�Ӳ�Ļ��ң�Ω��һ˿΢���Ĺ�â��ͷ����ʯ����©�¡�����΢�⣬����
�ɿ���խ�������������Ҷ��ҷ�������ʯ���ڽ����ߣ���֪ͨ��η���ɽ����
����һ����Ӱ��
LONG
NOR
        );
	set("objects", ([
	__DIR__"npc/ei":1,
	__DIR__"obj/container":1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"eastdown" : __DIR__"forest3",
  		"westup" : __DIR__"forest4",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-30);
	set("coor/y",30);
	set("coor/z",60);
	setup();
}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;
	if (!random(3))
	{
		tell_object(me,CYN"������խ��ɽ���м���ǰ�С�\n"NOR);
		me->perform_busy(1);
	}
	else if (!random(3))
	{
		tell_object(me,CYN"��Ŭ������һ����խ��ɽ·����С�Ĳȵ���������ʯ��ʹ�����顣\n"NOR);
		me->receive_wound("kee",20);
		me->set_temp("last_damage_from","��ɽ��������ͷ��Ѫ�������߶�����");
	}
	return ::valid_leave(who,dir);
}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

