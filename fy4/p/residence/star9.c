inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",9);

  set ("short", "ժ��¥"+CHINESE_D->chinese_number(query("floor"))+"��");
  set ("long", @LONG

    ���ķ����޹�·  ���׻�����  

    ����������  

    �����Ӵ�  ��Ե������ 

LONG);
        set("exits", ([
"917" : __DIR__"userroom/xjz1322550370",
"916" : __DIR__"userroom/losergod1322211757",
"915" : __DIR__"userroom/zzzc1316177608",
"914" : __DIR__"userroom/cool1315232430",
"913" : __DIR__"userroom/shanghai1309104716",
"912" : __DIR__"userroom/shift1305033404",
"911" : __DIR__"userroom/ctrl1304872957",
"910" : __DIR__"userroom/ysqf1304053487",
"909" : __DIR__"userroom/xff1299511052",
"908" : __DIR__"userroom/athena1280129777",
"907" : __DIR__"userroom/sqfive1276396770",
"906" : __DIR__"userroom/sqthree1276396628",
"905" : __DIR__"userroom/sqone1276396329",
"904" : __DIR__"userroom/ctone1266797562",
"903" : __DIR__"userroom/hsnn1258645737",
"902" : __DIR__"userroom/windrain1258439231",
"901" : __DIR__"userroom/voice1256975234",
  "down" : __DIR__"star"+(query("floor")-1),
]));
        set("coor/x",-25);
        set("coor/y",-35);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
