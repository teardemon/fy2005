// 2009 FengYun
// Edit by hippo 2009.11
// Т�� ����

inherit ITEM;
#include <ansi.h>

void create()
{
    set_name(BLK"�廨ʯ"NOR , ({ "ikebana stone","stone"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "һ��ɢ����������Ϣ�ĵĲ廨��ʯ����ʯ�ĺ���֣��ƺ����Բ���һ�£��ңң��Σǣš�\n");
        set("value", 500000);
        set("lore",1);
	}
	::init_item();
}


void init()
{
  if(this_player()==environment())
  add_action("do_arrange","arrange");
}

int do_arrange()
{
	int i,begonia=0,gardenia=0,daisy=0,lily=0,hyacinth=0,snowlotus,skillslv=0;
	object jade,me, *inv;
	object begoniai,gardeniai,daisyi,lilyi,hyacinthi,snowlotusi;
	me = this_player();
	if (me->query("bellicosity")>0) {
		message_vision("$Nɱ��̫�ߣ��ƺ��Բ廨�������������ⲻ�����\n",this_player());
		return 1;
		}
	if (me->query_skill("zen") < 50) {
		message_vision("$N�����������⻹�������̸���ϲ廨�ˡ�����\n",this_player());
		return 1;
	}
	inv = all_inventory(me);
	        for(i=0; i<sizeof(inv); i++)
                {
                	if(inv[i]->query("name") == HIG"����"NOR) {daisy = 1; daisyi = inv[i];}
                  if(inv[i]->query("name") == HIC"�ٺϻ�"NOR) {lily = 1; lilyi = inv[i];}
                  if(inv[i]->query("name") == HIY"�ﺣ��"NOR) {begonia = 1; begoniai = inv[i];}
                  if(inv[i]->query("name") == HIW"���ӻ�"NOR) {gardenia = 1;  gardeniai = inv[i];}
                  if(inv[i]->query("name") == HIB"������"NOR) {hyacinth = 1;  hyacinthi = inv[i];}
                  if(inv[i]->query("name") == HIC"��ɽѩ��"NOR) {snowlotus = 1;  snowlotusi = inv[i];}
                  if(me->query_skill("zen")>=50) {skillslv = 1;}
		}
	if( daisyi && gardeniai && begoniai && lilyi && hyacinthi && snowlotusi && skillslv)
	{
			destruct(begoniai);
	        destruct(daisyi);
	        destruct(lilyi);
	        destruct(gardeniai);
	        destruct(hyacinthi);
	        destruct(snowlotusi);
			jade = new(BOOKS"skill/xiaodao_75");
			jade->move(me);
			message_vision(HIG"$N��������仨����˳��ڷ��ڲ廨ʯ�ϣ�ͻȻһ���׹����������������ʱ$N�������г��ֵ��漣�������ѡ�\n"NOR,this_player());
			
			if (!REWARD_D->riddle_check(me,"Т�в���"))
				REWARD_D->riddle_set(me,"Т�в���",1);

			REWARD_D->riddle_done( this_player(),"ТŮ��", 30, 1);
			destruct(this_object());
	
	}
	else 
		message_vision("$N������ļ���С������İڷ���һ�£��ƺ�ȱ��ĳЩ����\n",this_player());
	return 1;
}
