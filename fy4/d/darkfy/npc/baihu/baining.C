//Tushen@Fygroup
//Based on Silencer's code.Copyright all reserved.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("����", ({ "bai ning" }) );
        set("gender", "����");
        set("age", 22);   
      	set("chat_chance", 1);
	set("chat_msg", ({
"�������ɴ����������Ƕ������ľƣ���������̧ͷ������˭������\n",
	}) );
        set("attitude", "friendly");
        set("condition","drunk");
        set("title",WHT"����"NOR);
        set("nickname", HIG"һҶ�� ������"NOR);
        set("score", 80000);
        set("reward_npc", 1);
		    set("difficulty",20);
		    set("class","bat");
        set("death_msg",CYN"\n$N̾�����������������Σ�Ҳ��ʧΪһ�����ʵ��¡�\n"NOR);
        set("combat_exp", 12000000);        
    set("perform_busy_d", "shaolin/dodge/fengyu-piaoxiang/zonghengsihai");
    set("perform_weapon_attack", "bat/unarmed/luoriquan/changrijiangjin");    
		set("perform_weapon_attack", "bat/unarmed/luoriquan/luori");

		
		  set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 200);
        set_skill("unarmed", 200);
        set_skill("blade", 300);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic", 200); 
        set_skill("perception", 200);
        
        set_skill("yiqiforce", 75);
        set_skill("fengyu-piaoxiang", 200);
		    set_skill("luoriquan", 200);
        set_skill("luoriquan", 220);
        set_skill("iron-cloth", 150);
        
        map_skill("unarmed","luoriquan");
        map_skill("force", "yiqiforce");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("move","fengyu-piaoxiang");
        map_skill("parry","luoriquan");
        map_skill("unarmed","luoriquan");
        map_skill("iron-cloth","yiqiforce");
        setup();


       	carry_object("/obj/armor/cloth",([	
    						"name":  "��֮��",
    						 ]))->wear();  

}
