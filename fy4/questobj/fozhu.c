// TIE@FY3
#include <armor.h>
inherit NECK;
#include <ansi.h>
void create()
{
	set_name(HIW"���÷���"NOR, ({ "fozhu" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
�������ظ�ɮ������������ķ��飬�����ع��϶����ص��ڽ̴�ͳ�У���������
������λ��ͨ�����ĸ�ɮ��Ҳ����������Ĵ��������ĵ�λ���������ǵĻ���
������һ�����Ϊ����⴮�����ע��Ҫ����������һ����Ҳ��ǧ���������
�ء����������ʱ�������ֵĵط�����һƬ�ȷ�Ѫ�꣬��Ϊ��˵���������ǵ�
�����������ͬ�����ǲ���ɱ������Ϊ��ɱ���Ͳ��ܽ�ħ�����ǶԸ���ħ������
ͽ��еķ�����ֻ��һ�֣�ͬ����һ��----���ۻ��ۣ���������������Ψһ����
���������ڡ��Ľ������Ժ󣬲�ӥ��һ��ʹ���Ȼ������Ӵ�רע�ڷ�ѧ�����
�׾����⴮���������Ψһ�Ļ�飬�����󻬵ı����Ƕ���Ħ���Ľ�������ĵģ�
��˸�Ű���Ĺ�â��
������а˫���˽ǽ�һս���ݻ��յ��������������⴮����Ҳ�ʹ˲�֪���١���
Ү��аҮ����Ү����Ү��˭���ֵܷ��壿��Ȼ˵����������ÿ��Ϧ���ڴ�Į����
���µ�ʱ�򣬸�����������������......
LONG);
		set("material", "stone");
		set("armor_prop/armor", 10);
	}
	::init_neck();
}