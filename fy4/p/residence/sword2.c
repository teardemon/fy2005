

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",2);

  set ("short", "藏剑阁"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

一个人在真正寂寞时又沉醉，就像是在水时快被淹死时一样，
只要能抓住一样可以抓得住的东西，就再也不想放手了。
可是他抓住的东西，却往往会令他堕落得更快。

LONG);
        set("exits", ([
  "down" : __DIR__"sword"+(query("floor")-1),
  "up" : __DIR__"sword"+(query("floor")+1), 
]));
  	set("coor/x",-30);
	set("coor/y",-40);
	set("coor/z",query("floor")*40);
	setup();
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
