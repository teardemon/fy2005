inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "ç��֮��");
        set("long", @LONG
���ܹ������죬�����ܲ���Ũ�ܿ������Ҷ�ڱ��������ǳ���ʹ�˷ֲ�����ҹ��
��������һ��ļž���ֻ�з紵�����ҵ�ɳɳ֮����ż��һ������Х�Ǻ������ȷ�
Ʈ�����ʡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"groupn1",
  "south" : __DIR__"groups1",
  "east" : __DIR__"groupe1",
  "west" : __DIR__"groupw1",
]));
        set("outdoors", "manglin");
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}