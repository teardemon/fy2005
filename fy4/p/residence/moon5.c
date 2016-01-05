inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",5);

  set ("short", "新月楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
  
    碧水连天静无浪   转东风   滟纹微张

    个中趣   莫遣人知   年年日日   兰舟共上
    
LONG);
        set("exits", ([
"512" : __DIR__"userroom/cemm1297099133",
"511" : __DIR__"userroom/zixia1296988681",
"510" : __DIR__"userroom/bon1296987354",
"509" : __DIR__"userroom/plate1296951368",
"508" : __DIR__"userroom/swk1296848888",
"507" : __DIR__"userroom/tsz1296833504",
"506" : __DIR__"userroom/shs1296724286",
"505" : __DIR__"userroom/zbj1296680770",
"504" : __DIR__"userroom/naga1296372807",
"503" : __DIR__"userroom/gene1296310653",
"502" : __DIR__"userroom/ruth1284550191",
"501" : __DIR__"userroom/alec1283130767",
  "down" : __DIR__"moon"+(query("floor")-1),
  "up" : __DIR__"moon"+(query("floor")+1), 
]));
        set("coor/x",-15);
        set("coor/y",-35);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
