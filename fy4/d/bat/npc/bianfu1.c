#include <ansi.h>
inherit NPC;
void use_poison();

void create()
{
        set_name(HIC"青翼蝙蝠"NOR, ({ "deadly bat", "bat" }) );
        set("race", "飞禽");
        set("age", 4);
        set("long", "一只非常可怕的青翼蝙蝠。\n");

        set("attitude", "aggressive");
        set_skill("dodge", 500+random(150));
        
        set("arrive_msg", "一声不响地飞过来");
        set("leave_msg", "一声不响地飞开了");
        set("combat_exp", 600000+random(400000));
		set("bellicosity", 3000 );
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );

        setup();
}

void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
		tell_object(ob,"血蝙蝠猛地冲下来，一口咬在你的脖颈上，你觉得一阵剧痛。。。。\n");
        ob->apply_condition("bat_poison",this_player()->query_condition("bat_poison")+ random(3)+20);
        return;
}


void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}

