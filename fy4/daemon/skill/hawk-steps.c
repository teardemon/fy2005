// hawk-steps.c

inherit SKILL;
void setup() {
	set("name","��������");
	set("practice_limit",100);
	set("usage/dodge",1);
	set("usage/move",1);
	set("type","step");
	set("difficulty",200);
	set("effective_level",200);
	set("skill_class","fugui");
	set("dodge_msg", ({
		"$n����˫�ۣ�ʹ������ã��ľ��������������ɵر��˿�ȥ��\n",
		"ֻ��$n��Ӱһ�Σ�һʽ�����亮ɽ����뻡����ѱ����߳�֮�⡣\n",
		"$n��������ľ���,˲�����λ�λ��ʹ�����������ճ���Ȫ�����������ɵ�������\n",
		"$n����һ�㣬Ư������������ǡ�ơ�����򣴨��ʹ�ơ����ڿն��𣬱��˿�ȥ��\n",
		"����$nʹһ�С�����ɽ�������ơ����⾳�Ѵ������綯��Ĺ���,����Ʈ�˿�ȥ��\n",
		"$n��Ӱ΢�����Ѿ���һ�С���ϭ������Ϧ�š�����������\n",
		"$n������в��ȣ�����ʫ�⡸�Է�������ѩɫ��������˶�ȥ��\n",
		"$n˫������һ�ᣬ���α任���ĳֱ��������ġ�����ʱ����Ҷ�ɣ�ѩ���Ƕ���������Ӱ���١�\n",
	}) );
}


int help(object me)
{
	write(@HELP   
L100��ӥ����졻��dodge.yingxiangjiutian����������ٶ�

L160����ӥ���á���dodge.jiyingbotu��
��10�غ��ڷ�������������ʽ��ÿ������ʹ��һ��

HELP
    );
    return 1;
}