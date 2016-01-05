// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

// Last Modified	- 02/16/2003 by silencer
// This file should be inherited by a pawnowner, who should have the following add_action
/* void init()
{
        ::init();
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
}
*/

#define MAX_PAWN 9
#include <dbase.h>
#include <ansi.h>

int do_value(string arg)
{
	object ob;
	int value;
	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("��Ҫ��ʲ����Ʒ�����̹��ۣ�\n");
	if (ob->query("thief_obj"))
	{
		call_out( (: call_other, MONEY_D, "arresthim", this_player() :), 3);
		this_player()->perform_busy(2);
		return notify_fail("��о��е㲻�Ծ���������Χ���˽����ض�ס���㡣\n");
	}
	if( ob->query("money_id") )
		return notify_fail("���ǡ�Ǯ������û������\n");
	if( ob->query("generate_item") )
		return notify_fail("�ⲻ�ǣ������Ʒ�������ﲻ�գ�ȥ������ɡ�\n");

	value = ob->query("level_required");   //add by ldb ��ֵ�����൱��װ������
	if( !value || value < 4) printf("%s����ֵ����Ǯ��\n", ob->query("name"));
	else 	{
//		value = value * 10000   //add by ldb ��ֵ=�൱װ�������gold
		printf("%s��ֵ%s��\n �������(sell)�������õ�%s��\n",
			ob->query("name"), 
			MONEY_D->money_str(value * 10000),
//			MONEY_D->money_str(value * 25 / 100), 
			MONEY_D->money_str(value * 80 / 100 * 10000));
		if (ob->query("item_damaged"))
	       		tell_object(this_player(),"��������Ʒ�Ѿ����ˣ����޺�֮ǰ����û�˻����Ȥ�ġ�\n");
	}
	return 1;
}


int do_sell(string arg)
{
	object ob;
	int value,old, amount;
	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("��Ҫ����ʲ����Ʒ��\n");
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɣ���������Ʒ��\n");
	if (ob->query("thief_obj"))
	{
		call_out( (: call_other, MONEY_D, "arresthim", this_player() :), 3);
		this_player()->perform_busy(2);
		return notify_fail("��о��е㲻�Ծ���������Χ���˽����ض�ס���㡣\n");
	}
	if( ob->query("money_id") )	return notify_fail("��Ҫ����Ǯ����\n");
	if( ob->query("generate_item") )
		return notify_fail("�ⲻ�ǣ������Ʒ�������ﲻ�գ�ȥ������ɡ�\n");
    if (ob->query("no_sell")|| ob->query("no_drop")||ob->query("no_transfer"))
	       	return notify_fail("�㲻����������������\n");
	
	value = ob->query("level_required");
        if( value<4)       	
        	 return notify_fail("������������ֵ�ܶ�Ǯ��\n");
	if (ob->query("item_damaged"))
		return notify_fail(this_object()->name()+"˵�������겻�չ����˵Ķ�������\n");
		
// to make life more realistic
        if( ((int)this_object()->query("richness")) < (value*80/100*10000))
                return notify_fail(sprintf("%s����Ǯ�Ѿ������ˣ�����\n",this_object()->name()));
        this_object()->add("richness",-(value*80/100));

	if (this_player()->query_temp("timer/sale")+2 > time())
		return notify_fail(this_object()->name()+"��Ц�������͹��Ժ����Ͼ����к�����\n");
	this_player()->set_temp("timer/sale",time());

	message_vision("$N�����ϵ�" + ob->query("name") + "������\n",
		this_player());
	old = this_object()->query_with_slash("vendor_goods."+base_name(ob));
// modified combined and throwing items. If the amount>base volumn, then calculate it and put
// in inventory, otherwise disgard it.	-- by Silencer 12/19/2002
	amount = ob->query("base_unit")? 
		 ob->query_amount()/ob->query_volumn():
		 1;
	if (amount)
		this_object()->set_with_slash("vendor_goods."+base_name(ob), old + amount);
	
	MONEY_D->pay_player(this_player(), value  * 80 / 100 * 10000);
	ob->move(VOID_OB);
	destruct(ob);
//	this_player()->start_busy(1);	��timer����busy��ÿһ���ӽ���һ�Ρ�
	return 1;
}