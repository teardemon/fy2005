

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",8);

  set ("short", "登天殿"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

一个人只要能成名，就能得到他所想要的一切，
他的生命就会完全改变，变得绚烂辉煌，多姿多彩，
只可惜他们的生命往往短暂如流星。

因为他们是江湖中人。

LONG);
        set("exits", ([
  "down" : __DIR__"cloud"+(query("floor")-1),
  "up" : __DIR__"cloud"+(query("floor")+1), 
]));
  	set("coor/x",-20);
	set("coor/y",-50);
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
