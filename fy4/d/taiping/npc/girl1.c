inherit NPC;
void create()
{
        set_name( "翠花", ({ "cuihua","girl" }) );
	set("gender", "女性" );
	set("age", 20);
	set("long","鹦鹉楼的姑娘，虽然没有江南女子那么小巧玲珑，也别有风情。\n");
                    
        set("chat_chance", 1);
        set("chat_msg", ({
                "翠花甜甜地说：大爷喝，喝呀。\n"
        }) );

	set("attitude", "peaceful");
	set("combat_exp", 500000);
        
        set_skill("unarmed", 100);
        set_skill("nine-moon-claw", 90);
        set_skill("nine-moon-steps",150);
        set_skill("parry",100);
        set_skill("dodge",100);
        map_skill("unarmed", "nine-moon-claw");
        map_skill("dodge","nine-moon-steps");
	setup();
	carry_object(__DIR__"obj/skirt")->wear();
}
