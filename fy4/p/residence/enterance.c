#include <ansi.h>


inherit ROOM;
void create ()
{
  set ("short", CYN"��"WHT"��ϼ֮��"CYN"��"NOR);
  set("name","��ϼ֮��");
  set("id","Residence Area");
  set("channel_id","��ϼ֮��(Residence Area)");
  
  set ("long", @LONG
�������ݣ�һ����΢���ķ����������̧����������ǹ⣬��Բ�����ܶ�����
����ѩ������С·�������������쿪����ͨ��Զ���Ըߵļ������أ�Ȼ��С·�µ�
����ֻ���������񣬾������ղ��䡣��Զ����ѩ�ر�Ե������ľ��[37m(Sign)[32m������ȥ
����ľ�ƴ�����ֻ������֮�£���ϡ�Ƿ��Ƴ�����˸�ĵƻ�
LONG);
        set("exits", ([ 
  "north" : __DIR__"smile1",
  "east" : __DIR__"tower1",
  "west" : __DIR__"sword1",
  "south" : __DIR__"cloud1",
//  "northeast" : __DIR__"moon1",
//  "northwest" : __DIR__"star1",
//  "southeast" : __DIR__"surge1",
//  "southwest" : __DIR__"cape1",
//  "down" : __DIR__"station",
  "down" : "/d/fy/station",

  "up" : __DIR__"annieshop",
]));
	set("item_desc", ([
			"sign": @LONG

���������������������X�������������������������������������[
����������������������������������ӭ������ϼ֮�ǡ�����������
���������������������������� ���������������������� ��������
���������������������������� ���������һ����ʮ���� ��������
���������������������^�������������������������������������a

LONG
	]) );
  	set("coor/x",-20);
	set("coor/y",-40);
	set("coor/z",10);
	set("NONPC",1);
	setup();
}


void process()
{
	BR_D->process();
	call_out("remove_x",43200);	// 12hr
}

void remove_x()
{
	set("ann",0);
}

void init()
{
	if (!query("ann"))
	{
		set("ann",1);
        CHANNEL_D->do_channel( this_object(), "announce",sprintf(NOR YEL"�L녳�ʽ����һ����ጦסլ�^�M�Йz�����������g������LAG���£�"NOR));
        CHANNEL_D->do_channel( this_object(), "announce",sprintf(NOR YEL"Ո�M���x�_Σ�U�^�򕺕r�ȴ������o��ȫ��"NOR));
		call_out("process",1);
	}
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/