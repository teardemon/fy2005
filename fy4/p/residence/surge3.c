inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",3);

  set ("short", "怒涛阁"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
  
    郁孤台下清江水，中间多少行人泪！ 
    
    西北望长安，可怜无数山！ 
    
    青山遮不住，毕竟东流去。 
    
    江晚正愁余，山深闻鹧鸪。
    
LONG);
        set("exits", ([
"317" : __DIR__"userroom/rskk1323161892",
"316" : __DIR__"userroom/ssg1322900104",
"315" : __DIR__"userroom/wzb1322739922",
"314" : __DIR__"userroom/wza1322575164",
"313" : __DIR__"userroom/feixian1321970481",
"312" : __DIR__"userroom/coding1298582668",
"311" : __DIR__"userroom/fyang1296732842",
"310" : __DIR__"userroom/eyang1296732792",
"309" : __DIR__"userroom/dyang1296732732",
"308" : __DIR__"userroom/cyang1296732634",
"307" : __DIR__"userroom/byang1296732564",
"306" : __DIR__"userroom/ayang1296730044",
"303" : __DIR__"userroom/xdf1285244768",
"302" : __DIR__"userroom/jxychang1277568533",
"304" : __DIR__"userroom/slin1293251673",
"305" : __DIR__"userroom/nobu1293633383",
"301" : __DIR__"userroom/pandoucy1267259495",
  "down" : __DIR__"surge"+(query("floor")-1),
  "up" : __DIR__"surge"+(query("floor")+1), 
]));
        set("coor/x",-15);
        set("coor/y",-45);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
