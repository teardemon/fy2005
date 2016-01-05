// neon@fengyun.com

#include <ansi.h>
#include <combat.h>
inherit ITEM;

void generate_name();

void create()
{	set_name( HIB"����޼"NOR, ({ "du jili" , "jili"}) );
	set_weight(10);
	set("unit", "��");
    set("long", "һ�Ŵ����˾綾�İ�������������Ϊ����֮���ȼ���������������ʮ������֮����\n");
    set("desc_ext", "shootd ĳ��");
	set("value", 8000);
	set("level", 50);
	::init_item();
}

void init(){
	add_action("do_shoot", "shootd");
}


int do_shoot(string arg){
	object me, target;
	int level, exp, t_exp, damage, exp_bonus, resist;
	string msg;
	
	me = this_player();
	if (!arg) return notify_fail("��Ҫ��˭��\n");
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

	target = present(arg,environment(me));
	
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) ) 
		return notify_fail( this_object()->name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");	
	
	level = me->query_skill("theorem",1);
	if (level< query("level")){
		tell_object(me,"����Ҫ"+ query("level")+"������֮������ʹ�ô˰�����\n");
		return 1;
	}
	
   	damage = 0;
   
	t_exp = (int) target->query("combat_exp");
	exp   = (int) me->query("combat_exp");
	msg  = HIB"$N��ָһ�����������ĵĶ���޼�����������\n\n"NOR;
	if( random(exp*5) + exp/2 > t_exp ) {
		damage = level*3;
		damage = COMBAT_D->magic_modifier( me, target, "sen", damage);
		msg +=  HIM"$n���ܲ�����������޼���м�ͷ����ʱһ��ͷ���ۻ���\n" NOR;
		target->receive_damage("sen",damage,me);
		target->receive_wound("sen",damage,me);
	} else
		msg += YEL"���Ǳ�$n����ض㿪�ˡ�\n"NOR;

	message_vision(msg, me, target);
	if( damage > 0 ) {
           target->set_temp("damaged_during_attack", 2);
           COMBAT_D->report_status(target);
    }
   	me->perform_busy(2);
	destruct(this_object());
	return 1;
}