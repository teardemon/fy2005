inherit ITEM;

void create()
{
    set_name("��ľ��", ({ "table"}) );
    set_weight(500);
    set_max_encumbrance(80000);
    set("no_get", 1);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "��");
	set("long", "һ���������µĺ�ľ�������\n");
	set("value", 1);
    }
}

int is_container() { return 1; }