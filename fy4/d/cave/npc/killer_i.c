inherit NPC;
#include <ansi.h>

void create()
{
	set_name("ţ����", ({ "killer i","killer" }) );
	set("title",HIC"����ɱ��"NOR);
	set("gender", "����" );
	set("age", 42);
	set("long",
		"���˺ڲ����棬����ڵĿӵ���ֻ�б��������⡣\n");
	set("attitude", "friendly");
	set("combat_exp", 1500000);
    set("attitude", "friendly");
    set("class","bat");
    set("cave_killer",1);
        
    set_skill("unarmed", 150);
    set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("blade",150);
	set_skill("bat-blade",120);
	set_skill("meng-steps",120);
	set_skill("move",120);
	set_skill("blade",150);
	set_skill("luoriquan",150);
	
	map_skill("dodge","meng-steps");
	map_skill("move","meng-steps");
	map_skill("blade","bat-blade");
	map_skill("parry","bat-blade");
	map_skill("unarmed","luoriquan");
	
	set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        	(: ccommand("perform shiwanshenmo") :),    
        }) );

	setup();
	
	carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/blade")->wield();
}

void die(){
	environment()->set("cave_mine",time());
	::die();
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",
		HIW + name() + "һ�������ںڰ�����ʧ�ˡ�\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}
