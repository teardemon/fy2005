inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",8);

  set ("short", "ժ��¥"+CHINESE_D->chinese_number(query("floor"))+"��");
  set ("long", @LONG

    ��ɪ�껪˭���
    
    Ī����鴦  ֻӰ��б��
    
    ��������  ���Ѵ���פ
    
LONG);
        set("exits", ([
"817" : __DIR__"userroom/zzzr1314848014",
"816" : __DIR__"userroom/zzzb1314790396",
"815" : __DIR__"userroom/zzza1314506738",
"814" : __DIR__"userroom/zzzo1312725791",
"813" : __DIR__"userroom/pang1308417805",
"812" : __DIR__"userroom/break1305425968",
"811" : __DIR__"userroom/insert1305354518",
"810" : __DIR__"userroom/dzjin1305307842",
"809" : __DIR__"userroom/xuehai1304766965",
"808" : __DIR__"userroom/blws1284777449",
"807" : __DIR__"userroom/whipper1284741234",
"806" : __DIR__"userroom/qinxin1284287776",
"805" : __DIR__"userroom/kean1267717269",
"804" : __DIR__"userroom/ham1255935989",
"803" : __DIR__"userroom/lumm1255357843",
"802" : __DIR__"userroom/yunpp1254926284",
"801" : __DIR__"userroom/fengxixi1254925353",
  "down" : __DIR__"star"+(query("floor")-1),
  "up" : __DIR__"star"+(query("floor")+1), 
]));
        set("coor/x",-25);
        set("coor/y",-35);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
