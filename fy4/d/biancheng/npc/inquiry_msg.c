mapping inquiry_msg = ([
	       	"ǿ��" : 	"������ǿ��������Ҳ��ǿ���������ӿ���ô����ȥѽ��\n",
	       	"bandit" : 	"������ǿ��������Ҳ��ǿ���������ӿ���ô����ȥѽ��\n",
             	"�����ǿ��" : 	"������������կ����Щɽ��ô��\n",
             	"���ڵ�ǿ��" : 	"����˵������˵ѽ����\n",
             	"����ʵ":	"����ʵ������С��ݵ��ϰ塣\n",
             	"�θ���":	"�θ����������޻��е��ϰ塣\n",
             	"������":	"�������������ӻ��̵��ϰ塣\n",
             	"�´���":	"�´��������ϳ��ׯ���ϰ塣\n",
             	"����":		"�´���������һƷ����ϰ塣\n",
             	"������":	"������������С���ݵ��ϰ塣\n",
             	"������":	"���������������¥���ϰ塣\n",
             	"��Ũ":		"��Ũ����������ߵĺ�Ƕ���\n",
             	"�����":	"����������ϵĵ�ͷ�ߣ���˵�����������ӣ�û�¶��㻹�Ƕ�Զ��á�\n",
             	"������":	"�������������õĴ󵱼ҡ�\n",
             	"����Ⱥ":	"�������������õĴ󵱼ҡ�\n",
             	"������":	"�������������õĶ����ҡ�\n",
             	"������":	"�������������õ������ҡ�\n",
]);


string query_inquiry_msg(string arg) {
	string *msg;
	int i;	
	msg=keys(inquiry_msg);
	for (i=0;i<sizeof(msg);i++) 
		if (msg[i]==arg) return inquiry_msg[msg[i]];
	return 0;
}	