

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",6);

  set ("short", "笑浅楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

人们在遭遇到困难和不幸的时候，眼泪并不能解决任何问题，
只有笑声才是对付困难和不幸的最好武器。

LONG);
        set("exits", ([
  "down" : __DIR__"smile"+(query("floor")-1),
  "up" : __DIR__"smile"+(query("floor")+1), 
]));
  	set("coor/x",-20);
	set("coor/y",-30);
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
