inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",1);

  set ("short", "ŭ�θ�ײ�");
  set ("long", @LONG

    �滨������  ͤͤ������  ��¶������  ����Ѭ��
    
    ���в�����  ��������ͨ  ���ﳯĺ��  �����˲���

LONG);
        set("exits", ([
"117" : __DIR__"userroom/grantc1318898350",
"116" : __DIR__"userroom/granta1316239372",
"115" : __DIR__"userroom/pws1311767914",
"114" : __DIR__"userroom/yhsd1310809737",
"113" : __DIR__"userroom/yhsb1309793222",
"112" : __DIR__"userroom/axyx1267001014",
"111" : __DIR__"userroom/secret1263886072",
"110" : __DIR__"userroom/wangkan1261981801",
"109" : __DIR__"userroom/ajump1261905026",
"108" : __DIR__"userroom/giniusdw1260315940",
"107" : __DIR__"userroom/giniusct1259538663",
"106" : __DIR__"userroom/hsgirl1259281331",
"105" : __DIR__"userroom/giniussl1259193282",
"104" : __DIR__"userroom/dwggirl1259132743",
"103" : __DIR__"userroom/andy1258325953",
"102" : __DIR__"userroom/xyun1257731191",
"101" : __DIR__"userroom/snow1257463189",
  "northwest" : __DIR__"enterance",
  "up" : __DIR__"surge"+(query("floor")+1), 
]));
        set("coor/x",-15);
        set("coor/y",-45);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
