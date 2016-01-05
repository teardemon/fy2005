#include <ansi.h>
inherit SMART_NPC;

void do_bite();

void create()
{
    	set_name("�߽�ʬ",({"zombie"}));
	set("title","�˼����");
   	set("long","�����������۾���һ����ƽ�������������������Ǳ��Ӻͱǿף�һ���ѷ�
������ͣ��촽û���ˣ���������¶�����档һֻ�ֱ�Ť������������
��һ��һ�ͣ������˻��Ǵӹ��Ź����߻����Ľ�ʬ��\n");

     	set("gender","����");
    	set("attitude", "aggressive");
    	
    	set("combat_exp",4000000);  
    	set("age",42);
	    	
		set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
			10: name()+"�����﷢��ϣ��������������ɱ������ɱ����������\n",
			20: (: do_bite() :),
        ]) );    	
    	
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(30) :),    
        }) );
	
		auto_npc_setup("guardian",200,170,0,"/obj/weapon/","fighter_w","necromancy",1); 
    	setup();
    
}

void do_bite()
{
        object *enemy;
        message_vision(HIB"$N�������һ��������Ż�ĳ�����ʹ�����ͷ�����͡�\n"NOR,this_object());
        enemy = query_enemy();
        for(int i=0; i<sizeof(enemy); i++) {
                if( !enemy[i] ) continue;
                enemy[i]->receive_damage("sen", 250,this_object());
                COMBAT_D->report_status(enemy[i]);
        }
}

void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
			me = owner;
		} 
        if (me)
        	me->add("marks/wanma/zombie",3);
        message_vision("$N�����ص���ȥ��ʧ�ˡ�\n",this_object());
        ::die();
}