#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;
do_fight();
void create()
{
	set_name("������", ({ "lv nanren","lv" }) );
	set("gender", "����" );
        set("nickname",RED"Ʈ�㽣����Ʈ��"NOR);
        set("title","Ʈ��ɽׯ     ����");
        set("quality","good");
	set("age", 33);
	set("int", 29);
	set("per", 30);
	set("str", 32);
	set("dur", 30);
	set("cor", 50);
	set("long",
"һ�����շ������ε�����ѹ��ӣ�����ʱȴֻ�Ǹ��������Ŀ͡�\n"
		);
        set("force_factor", 40);
        set("max_gin", 3000);
        set("max_kee", 4100);
        set("max_sen", 3000);
		set("max_force",2000);
		set("force",2000);

        set("combat_exp", 2000000);
        set("score", 1200);
        set_skill("unarmed", 80);
        set_skill("sword", 110);
        set_skill("force", 70);
        set_skill("parry", 110);
        set_skill("literate", 80);
	set_skill("dodge", 140);

        set_skill("feixian-sword", 180);
	set_skill("jingyiforce", 60);
        set_skill("feixian-steps",180);
	
//	map_skill("unarmed", "meihua-shou");
        map_skill("sword","feixian-sword");
        map_skill("force", "jingyiforce");
        map_skill("parry", "feixian-sword");
		map_skill("dodge","feixian-steps");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (:perform_action,"dodge.tianwaifeixian":),
        }) );
	setup();
    carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}