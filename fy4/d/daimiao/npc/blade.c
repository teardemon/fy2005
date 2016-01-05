#include <ansi.h>
inherit SMART_NPC;

int smart_fight();

void create()
{
	object weapon;
	set_name("һ����ɱ", ({ "wansha","wan sha" }) );
	set("title",HIB"����;��"NOR);
	set("gender", "����" );

	set("group","demon");

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
//		(: auto_smart_fight(100) :),
		(: smart_fight() :),
	}) );

	set("combat_exp", 10000000);

	setup();

	auto_npc_setup("disciple",200,220,0,"/obj/weapon/","fighter_w","spring-blade",4);

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("�����", ({ "armor"}) );
	weapon->set("long","\n");
	weapon->set("value",0);
	weapon->wear();


	weapon=carry_object("/obj/weapon/blade");
	weapon->set_name(HIR"ǧ����"NOR, ({ "blade"}) );
	weapon->set("long","\n");
	weapon->set("value",0);
	weapon->wield();

}

int kill_ob(object who)
{
	::kill_ob(who);
	auto_smart_fight(100);	// rascal design :p
	return 1;
}

void unconcious()
{
	die();
}

pf2(object tm)
{
	object ob,me=this_object();
	object* inv,target,*pros;
	int i;
	if (!tm)
		return;
	if (!is_fighting() && !tm->is_fighting())
		return;
	if (environment() != environment(tm))
		return;
	
//	message_vision(WHT"\n$N��$n����һ�ۣ�����ͬʱ������������ȥ��ס������������\n",me,tm);
	message_vision(WHT"\nī���뵭���������Ȼ���ǣ�"HIR"���������ԻͲ��õĹ⻡����������˷���\n"NOR,me,tm);
	inv=all_inventory(environment());
	for (i=0;i<sizeof(inv) ;i++ )
	{
		if (inv[i] == me)	continue;
		if (inv[i] == tm)	continue;
		if (!inv[i]->is_fighting(me) && !inv[i]->is_fighting(tm) )	continue;
		target = inv[i];

		target->receive_damage("kee",target->query("max_kee")/(5+random(2)),me);
		target->receive_damage("kee",target->query("max_kee")/(5+random(2)),tm);
		target->receive_wound("kee",target->query("max_kee")/(5+random(2)),me);
		target->receive_wound("kee",target->query("max_kee")/(5+random(2)),tm);
		

		COMBAT_D->report_status(target);
	}
	message_vision(WHT"\n",me,tm);
	return;
}

pf(object tm)
{
	object ob,me=this_object();
	object* inv;
	int i;
	if (!tm)
		return;
	if (!is_fighting() && !tm->is_fighting())
		return;
	if (environment() != environment(tm))
		return;
	
	message_vision(MAG"$N��$n΢΢������������˫ɫ�����⻭��һ����һ��������Բ�������֮�����������ص����ɣ�\n",me,tm);
	message_vision("������ؼ�����������ת�ĵ�������һ�㣬��Ȼ��ɡ������������ּ���������\n"NOR,me,tm);
	call_out("pf2",2,tm);
	return;
}

smart_fight()
{
	object ob,me=this_object(),tm;
	object* inv;
	int i;
	ob=select_opponent();
	if (present("wan sheng",environment()))
		tm=present("wan sheng",environment());
	if ((!SMART_D->check_health(me,30) || !SMART_D->check_health(ob,30)) && query("ac") + 60 < time())
		if (tm)
			if (tm->query_busy()<2 && tm->query("ac") + 60 < time())
			{
				set("ac",time());
				tm->set("ac",time());
				message_vision(HIB"\nī�൭��ĵ����Թ����������һ��һ�£�һ��һ������һ������Ĺ켣����໷����$N��$n��\n",me,tm);
 				message_vision("����ת��ɲ�Ǽ侹ʹ�����ִ��������ǵ����������Լ���˼�롢�Լ�����ʶ������\n\n"NOR,me,tm);
				inv=all_inventory(environment());
				for (i=0;i<sizeof(inv) ;i++ )
				{
//					if (inv[i] == me)	continue;
//					if (inv[i] == tm)	continue;
					if (!inv[i]->query("max_kee"))	continue;
					inv[i]->perform_busy(3);	// NO IMMUNE.
				}
				call_out("pf",2,tm);
				return;
//				message_vision(HIR"�����ĺ�ɫ",me);
			}
	ccommand("perform fengsiyunqi");
}

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