// qload.c

inherit F_CLEAN_UP;

int main()
{
    write(query_load_average() + "\n");
    return 1;
}

int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	qload [0m
[0;1;37m����������������������������������������������������������������[0m   

��ʾ��Ŀǰ CPU �ĸ���, cmds/s ��ÿ����뼸�� cmds
comp lines/s ��ÿ�뼸�С�

[0;1;37m����������������������������������������������������������������[0m 
HELP
    );
    return 1;
}
