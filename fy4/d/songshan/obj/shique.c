// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;

void create()
{
        set_name("ʯ��", ({ "ʯ��", "shique"}) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "behind");
                set("unit", "��");
                set("long", "���С�����̫�����ǡ��������֡�\n");
                set("value", 1);
        }
}

int is_container() { return 1; }
