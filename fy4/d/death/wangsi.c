// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
ԶԶ��ȥ�����Թ�����죬������Ķ���������ԩ�꣬������������ս������
ʬ���������񣬼�����ɢ��������Թ�������𽥾ۼ���һ���־���Ϊ���������
Ҳ�����̷���ֻ�ǹ��������������У����к��������˼�ڿ�ˮ½�������������꣬
���в���ԩ����԰�Ϣ����ϧ����ս���������������е�ԩ�꾹ȻԽ��Խ�ࡣ����
�����ǣ�����ƽ�����ˡ�
LONG
        );
        set("exits", ([
		"southeast" : __DIR__"pingan",
        ]) );
        set("objects", ([
                __DIR__"npc/ghost" : 5,
                __DIR__"npc/meier" : 1,
        ]) );
        set("no_meal","���Ȼ���ֿ��е�ʳ����ˮ���˿�ɬ�����࣬�Ͽ����۵����˳�����\n");
	set("coor/x",-40);
	set("coor/y",0);
	set("coor/z",-190);
	set("no_fight",1);
	setup();
        
}
 