mapping inquiry_msg = ([
        "小烟" : 		"小烟是村里的孩子，前些天忽然失踪了。",
         "欧阳豆腐铺" : "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
        "欧阳丁" :  	"欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
        "欧阳当" :  	"欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
        "哈哈酒楼": 	"哈哈酒楼当然是哈哈儿开的喽，听说他现在生意不好，正在为原料发愁呢。",
        "哈哈儿": 		"哈哈酒楼当然是哈哈儿开的喽，听说他现在生意不好，正在为原料发愁呢。",
        "娇娇客栈": 	"娇娇客栈是屠娇娇的女儿开的。",
        "屠小娇": 		"娇娇客栈是屠娇娇的女儿屠小娇开的。",
        "恶人谷": 		"恶人们都跑光了，这恶人谷三字早已没人提了。",
   		"燕南天": 		"燕大侠的名字谁人不晓，村里还有他的铁像呢。",
   		"万春流": 		"万神医有起死回生之能。",
   		"杜老爹": 		"杜老爹专打暗器，听说要打他的暗器，还得学好无有之术才行。",
   		"轩辕三光": 	"他输的只剩下那间当铺了。",
   		"铁萍姑": 		"李大嘴的女儿，一个人住在那儿，怪可怜的。",   	
   		"七枝一叶花":	"听说前两天村里的小孩儿挖到了一颗奇异的草，是不是那个？",		
]);


string query_inquiry_msg(string arg) {
	string *msg;
	int i;	
	msg=keys(inquiry_msg);
	for (i=0;i<sizeof(msg);i++) 
		if (msg[i]==arg) return inquiry_msg[msg[i]];
	return 0;
}	