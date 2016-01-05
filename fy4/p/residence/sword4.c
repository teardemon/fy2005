

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",4);

  set ("short", "藏剑阁"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

寂寞是什么？一个人独处，无人陪喝酒聊天，寂寞得要命。
心事无人知，朋友虽一大堆，却没有一个可以倾吐心曲的，寂寞的要命。
这不是寂寞，这只是你感觉寂寞而已。
真正的寂寞是一种深入骨髓的空虚，一种令你发狂的空虚。
纵然在欢呼声中，也会感觉到内心的空虚、惆怅与沮丧。

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
