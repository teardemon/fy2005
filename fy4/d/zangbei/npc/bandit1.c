#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("ɽկ���",({"bandit"}));
		set("title",YEL"����կ"NOR);

   		set("long","һ���������£��������λθֵ���С���ˡ�\n");
     	set("gender","����");
    	set("age",32);
    	set("group","longhuzhai"); 	
    	
    	set("combat_exp",2000000);  
    	set("attitude", "aggressive");
    	    	
    	set("death_msg",CYN"\n$N�е�������֪�������Ͳ��������ˡ�����\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
			10: "ɽկ��޽е����������ŵķ��򣬵����ǲ�����ѽ����\n",
			15: "ɽկ��޽е������������������������ס�ˡ���\n",
        ]) );    	
    	set("inquiry", ([
        	"����" : 	"����ô���������ˣ�\n",
             	"����" : 	"������կ����ЪϢ�أ�\n",      
   		]));
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({

    	}) );    	    	
    	
    	
		auto_npc_setup("wang",150,130,1,"/obj/weapon/","fighter_w","bat-blade",1);
	
		setup();
    	carry_object("/obj/armor/cloth",([	"name": "�ڲ��̿�",
    						"long": "һ���ڲ��̿���\n",
    						 ]))->wear();     
    
}

