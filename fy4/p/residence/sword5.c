

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",5);

  set ("short", "藏剑阁"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

人类最大的痛苦，也许就是永远无法控制自己的思想。
你若拼命想去回忆过去那些有趣的事情，但想到的偏总是那些辛酸和痛苦，
那时你心裡就会觉得好像有根针在刺着。

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
