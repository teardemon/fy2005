inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIG"����"+MAG"����"+HIG"��������"NOR, ({ "alien queen","queen" }) );
        set("gender", "Ů��" );
        
        set("age", 32);
        set("str", 25);
 	set("dur",100);
        set("cor", 14);
        set("per", 4);
        set("cps", 29);
        set("int", 25);
        set("long", "���Թ����������ģ������������ѹ��\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                "������������˵������һ�����ӣ�����һ�����ӡ�\n",               
                }) );	
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("max_force", 500);
        set("force", 500);
        set("force_factor", 10);
        set_skill("yoga",151);
        set_skill("dodge",50);
        set_skill("move",50);
        set_skill("unarmed",50);
        set("skill_public",1);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object who, object ob)
{
	object another;
	object *inv;
	int i,j;
	
	if (who->query("combat_exp")<=2500000) {
		ccommand("say �㻹�Ƕ�������ɣ��Ҷ���һ���ܳ�������");
		return 0;
	}	
	
	inv=all_inventory(environment(this_object()));
	for (i=0;i<sizeof(inv);i++) {
		if (inv[i]->query("dungeon_npc")) j++;
	}
	
	if (j>3) {
		ccommand("say �ȴ������ڳ�����˵��!");
		return 0;
	}
	
	if( ob->value() >= 10000) {
        	message_vision("$N˵���Ҿ���ʹ�һ�Ѱɡ�\n",this_object());
        	message_vision("$N�ߺ��˼�����\n",this_object());
        	another = new(__DIR__"fightnpc");
		another->move(environment(this_object()));
                message("vision",another->query("name")+"˵:��������ɱ˭����\n",environment(this_object()));              
                        return 1;
                } else {
                    	command("say �����Ӳ����װ�������\n");
                        return 0;
                }
        return 0;
} 

void die(){
	 message_vision("$N΢΢һ��������ɫ�ָֻ��˺���\n", this_object());
     this_object()->full_me();
//	"/cmds/imm/full"->main(this_object(),"");
}