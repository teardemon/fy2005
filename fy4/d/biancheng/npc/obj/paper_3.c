inherit ITEM;
#include <ansi.h>

void create()
{
    	set_name("��ֽƬ���Ͻ�", ({ "paper" }) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
		 set("long", "һ��˺���˵�ֽƬ������д�š�����������\n");
	}
	
	::init_item();
}

/* ��ʮ����ǰ÷����Ѫ������ʮ����Χ�����ð����������ѩ�µúܴ�
����һƬ���ף�����ս������������һƬ����ɫ�Ĵ�أ���������ѪȾ
���ˡ�Ⱦ����һƬѩ�ص���Ѫ���������ǰ׼��˵ģ����˵�Ѫ���ø��࣬
�ܻ��Ż�ȥ��ֻ���߸��ˣ����Ѳ��������״󾭣�Ѧ���һ����ӣ�����
����������Ľ���ֵ�����Ⱥ������һ�����ص�Ļ�������*/