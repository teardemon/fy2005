inherit ROOM;
void create()
{
    set("short", "Ʈ�㻨��");
    set("long", @LONG
��������ô���꣬�����ƺ�һ�㶼û�иı䣬�����������ϡ�δ��˴�������
�Ļ�����������Ƣ�����и���������������Ŀ�������������֡����Ͳ��ָߵ͹����
�������������Ц����ӭ��������е������˶�ϲ�����������������һ���һ���
�ή�������ϡ���������ϰ�˵����Ʈ�㻨���ɵ���Ե�Ѳ���ʤ�������ſں�ֽ
�����Ÿ�ʾ��������
LONG
    );
    set("exits", ([
	"west" : __DIR__"swind31",
      ]));
    set("objects", ([
	__DIR__"npc/flowerseller": 1,
      ]) );
    set("item_desc", ([
	"sign": @TEXT
[0;1;37m����������������������������������������������������������������[0m
[0;1;31m	�ع���𣚣�ں�֮�ޡ�����Ů�����Ӻ��ϡ�[0m
[0;1;37m����������������������������������������������������������������[0m
             
�������ɸ����ݹˣ�������¡����ȱ���������ͻ����أ�
�˵ؿ�ִ�е����

1��[37mdelivery[32m
���������У��ڹ涨ʱ�����ͻ���ָ����ͣ�����������Ԥ������һ����
�������Զ�ת�ˡ�
2��[37mask hua mancheng about deposit[32m
����ͻ��󣬿������������ѯ��ȡ�ض����Զ�ת������˺š�
3��[37mcancel delivery[32m
���������ԭ���޷���ɽ���֮�𣬿�ȡ���������
             
[0;1;37m����������������������������������������������������������������[0m             
TEXT
      ]) );
    set("no_fight",1);
    set("no_magic",1);
    set("NONPC", 1);
    set("coor/x",20);
    set("coor/y",-160);
    set("coor/z",0);
    set("map","fysouth");
    setup();

}