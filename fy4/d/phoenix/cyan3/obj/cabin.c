
inherit ITEM;

void create()
{
	set_name("�ڹ��", ({"�ڳ�","�ڹ�","�ڹ��","closet"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown",1);
	set("prep","on");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ڹ��������ڵ��Ǹ��ָ����ľơ�\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
