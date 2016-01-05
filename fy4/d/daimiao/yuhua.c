#include <ansi.h>

#include <room.h>
inherit ROOM;
void create()
{
  set("short","雨花道院");
  set("long","这是道士休息，饮食，打坐的处所，俭朴清净，有几个石砌的桌子，摆放着一
些简单的食品，饮料，小屋中一口老井，名为雨花，据说乃当年泰山封禅时皇帝御
用过的井水，清澈而甘甜。园中一棵千年"YEL"古槐"NOR"，浓荫蔽日。
"
  );
  	set("exits",([
         	"east":__DIR__"taiwei",
        ]));
        set("objects", ([
        	__DIR__"npc/daoshi":	3,
                
       	]) );
        set("item_desc", ([
        	"古槐":"
唐槐高大茂盛，蔽荫亩许，后逐渐衰枯，后人在枯槐内植一小槐，俗称『唐
槐抱子』，列为岱庙八景之一。今日新槐已扶疏郁茂，树前有双碑：一块是
明万历年间甘一骥书“唐槐”大字碑；另一块为清康熙年间张鹏翮题《唐槐
诗》：“潇洒名山日正长，烟霞为侣足徜徉。谁能欹枕清风夜，一任槐花满
地香。”\n",
        	"槐":"
唐槐高大茂盛，蔽荫亩许，后逐渐衰枯，后人在枯槐内植一小槐，俗称『唐
槐抱子』，列为岱庙八景之一。今日新槐已扶疏郁茂，树前有双碑：一块是
明万历年间甘一骥书“唐槐”大字碑；另一块为清康熙年间张鹏翮题《唐槐
诗》：“潇洒名山日正长，烟霞为侣足徜徉。谁能欹枕清风夜，一任槐花满
地香。”\n",
		"tree":"
唐槐高大茂盛，蔽荫亩许，后逐渐衰枯，后人在枯槐内植一小槐，俗称『唐
槐抱子』，列为岱庙八景之一。今日新槐已扶疏郁茂，树前有双碑：一块是
明万历年间甘一骥书“唐槐”大字碑；另一块为清康熙年间张鹏翮题《唐槐
诗》：“潇洒名山日正长，烟霞为侣足徜徉。谁能欹枕清风夜，一任槐花满
地香。”\n",
	]));
    	set("resource/water", 1);
    	set("liquid/container", "雨花井"); 
		set("liquid/name","雨花井水");
	set("coor/x",-20);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}
/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

