// wuchen-steps.c

inherit SKILL;
void setup(){
	set("name","�����޳���");
	set("practice_limit",100);
	set("type","step");
	set("difficulty",200);
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",100);
	set("skill_class","task");
	set("dodge_msg", ({
		"$n�������ĵ���������һ�����պñܹ�$N���������ơ�\n",
		"����$nǡ����������һ���������$N��һ�С�\n",
		"ֻ��$n�������ϱ�ֱ���������࣬�����$N��һ�С�\n",
		"$n����ݳ�����֮Զ���ܿ���$N���������ơ�\n",
		"$n��һ��ƮȻ�ݳ��������ŵء�\n"
        	"����$n����Ʈ��������һ�ݣ����ѱܿ���\n",
        	"$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
        	"����$n����һ�ã�$N��һ�����˸��ա�\n",
        	"ȴ��$n�㲻��أ����Դܿ����ߣ����˿�ȥ��\n",
        	"$n����΢�Σ��о����յرܿ���$N��һ�С�\n"
	}) );
}