// bat_drug.c

inherit COMBINED_ITEM;

void create()
{
	set_name("���𶾽�ҩ", ({ "bat drug", "drug" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
      		set("long",    	"����һ�����������𶾵�ҩ,������(cure)��������!\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 10);
		set("volumn",20);
	}
	set_amount(20);
}


void init()
{
  	if(this_player()==environment())
  		add_action("do_cure","cure");
}


int do_cure()
{
  	object me;
  	me = this_player();
 	if  (((int) me->query_condition("bat_poison")) <= 0)
  		return notify_fail("��û�������𶾡�\n");
  	message_vision("$N���½�ҩ����ʱ�о��ö��ˡ�",me);
        me->change_condition_duration("bat_poison",-5);
  	 	
  	if(me->query_condition("bat_poison")>1)
       	tell_object(me,"�������е����𶾲�û����ȫ�����\n");
  	else
    {
        tell_object(me,"������������������е����𶾣�\n");
  		me->change_condition_duration("bat_poison",0);
  	}
  		
  	add_amount(-1);
  	return 1;
}
