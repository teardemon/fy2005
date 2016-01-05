

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",2);

  set ("short", "笑浅楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

世界最快乐的，便是愚昧的人。
因为他毋庸忍受聪明人常会感到的寂寞，而他纵然常被人愚弄，
但他也不会因之失去什么，这正如愚弄别人的人其实也不曾得到什么一样。

LONG);
        set("exits", ([
"202" : __DIR__"userroom/zyu1397429462",
"201" : __DIR__"userroom/myu1397427856",
"217" : __DIR__"userroom/cantabil1310058765",
"216" : __DIR__"userroom/qiyan1308795670",
"215" : __DIR__"userroom/welltion1308065172",
"214" : __DIR__"userroom/qybb1307985177",
"213" : __DIR__"userroom/qyb1307115204",
"212" : __DIR__"userroom/hoy1258681512",
"211" : __DIR__"userroom/cqxucat1258356051",
"210" : __DIR__"userroom/shidi1258351882",
"209" : __DIR__"userroom/jansen1257421469",
"208" : __DIR__"userroom/zjing1257347282",
"207" : __DIR__"userroom/zwei1256821863",
"206" : __DIR__"userroom/jean1256146436",
"205" : __DIR__"userroom/hero1255730203",
"204" : __DIR__"userroom/fis1255713448",
"203" : __DIR__"userroom/fkuang1255564069",
"202" : __DIR__"userroom/emily1254722110",
"201" : __DIR__"userroom/bzt1253204507",
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
