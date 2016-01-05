/*  OK, we need four ranges of SMART_NPCs,

(1) NPC_BAS, 
	0-5M,  menpai skill only, Can have defense-parry, 
(2) NPC_MID, 
	5-10M  + all free-master skills and couple skill. 
	random_allowed in (5-15M);
(3) NPC_ADV, 
	10-15M + advanced basic, + haste/double, + adv-perk. 
(4) NPC_041,
	5M+ free-master skills and couple skill,4.1 skills.

		ALL FOR ONE NPC
	
	此NPCLIST和相应的do_choose_attack_4 用以处理41型的NPC引用，
	比原来的NPC要强，有优化，强弱由chat_combat_chance决定。
	对一般NPC建议设置在30以下
	你也可以只引用auto_setup设置而不引用Smart_fight.
	
	5M+ 此表共计 个NPC，1个random NPC。

	------- by Silencer@fy4 workgroup 3/20/2003
	------- by Annie. 11/01/2003
	
*/

inherit SKILL;

string weapon_unarmed(string weapon_i,string unarmed_i);
int check_health(object target, int percent);
int accompany(object me);
int is_he_pet(object target);
int enemy_type(object enemy);
object *resort_enemy(string flag);
object *resort(object *group);

mapping *npctype = ({
//	随机的小喽罗。打法ok但并非优化。	
// This will generate a random skill NPC. Do not specify his weapon since he uses varies skills.
// He has some dodge/unarmed busy and a weapon attaack, difficulty moderate I would say.
// You can use it as 小喽罗.
	([      
		"group":		"fighter_w",
		"npc":                	"smallguy",
                "name":			"小喽罗",
                "class":	      	"wolfmount",
                "gender":		"男性",
                "force":		"manjianghong",
		"others1":		"bloodystrike",
		"others2":		"strategy",
		"others3":		"leadership",
		"perform_weapon_attack": "random",
		"perform_unarmed_attack":"random",
		"perform_busy_d":	 "random",
		"perform_busy_u":	 "random",
        ]),
        
//	BERSERKER: break weapon, team pfm, single pfm
	// powerup-one... 
	([      
		"group":		"fighter_w",
		"npc":                	"spring-blade",
                "name":			"天涯",
                "class":	      	"berserker",
                "gender":		"女性",
                "skill_type_w":	      	"blade/spring-blade",
                "skill_type_u":		"venusfinger",
                "skill_type_d":		"xifengying",
				"d_adjust":			15,
                "unarmed":		"venusfinger",
                "blade":		"spring-blade",
                "force":		"gaunforce",
                "parry":		"spring-blade",
                "dodge":		"xifengying",
				"dagger":		"dug",
		"perform_weapon_attack":"berserker/blade/spring-blade/fengsiyunqi",
		"perform_weapon_attack2":"berserker/blade/spring-blade/obliterate",
		"perform_weapon_attack3":"berserker/dagger/dug/deathtouch",
		"perform_unarmed_attack":	"berserker/unarmed/venusfinger/panguaxe",     
        ]), 
	// forceup-one
	([      
		"group":		"fighter_w",
		"npc":                	"tempestsword",
                "name":			"长庚",
                "class":	      	"berserker",
                "gender":		"男性",
                "skill_type_w":	      	"sword/tempestsword",
                "skill_type_u":		"venusfinger",
                "skill_type_d":		"xifengying",
				"d_adjust":			15,
                "unarmed":		"venusfinger",
                "sword":		"tempestsword",
                "force":		"gaunforce",
                "parry":		"tempestsword",
                "dodge":		"xifengying",
				"dagger":		"dug",
		"perform_weapon_attack":"berserker/sword/tempestsword/knockdown",
		"perform_weapon_attack2":"berserker/sword/tempestsword/obliterate",
		"perform_weapon_attack3":"berserker/dagger/dug/deathtouch",
		"perform_unarmed_attack":	"berserker/unarmed/venusfinger/panguaxe",     
        ]), 
//	MOON
	([      
		"group":		"fighter_w",
		"npc":                	"starrain",
                "name":			"素馨",
                "class":	      	"moon",
                "gender":		"女性",
                "skill_type_w":	      	"throwing/starrain",
                "skill_type_u":		"luoriquan",
				"u_adjust":		15,
                "skill_type_d":		"stormdance",
                "unarmed":		"luoriquan",
                "blade":		"chillblade",
                "force":		"snowforce",
                "spells":		"heart-listening",
                "parry":		"starrain",
                "move":		"stormdance",
                "dodge":		"stormdance",
				"throwing":		"starrain",
		"perform_weapon_attack":"moon/throwing/starrain/fengloufeiyan",
		"perform_weapon_attack2":"moon/throwing/starrain/qixingbanyue",
		"perform_weapon_attack3":"moon/blade/chillblade/qinghui",
		"perform_weapon_attack4":"moon/throwing/starrain/tianheyixian",
		"perform_unarmed_attack":	"moon/unarmed/luoriquan/changrijiangjin",     
		// cast qingshangxiehong,cast zhaoyuwanqing.
		// exert wufangbianhuan,yinlingkouming,shuanghuaningjie.
		"perform_unarmed_attack2":	"moon/force/snowforce/bingpojingbi",     
        ]), 
	([      
		"group":		"fighter_w",
		"npc":                	"chillblade",
                "name":			"映月",
                "class":	      	"moon",
                "gender":		"女性",
                "skill_type_w":	      	"blade/chillblade",
				"w_adjust":			13,
                "skill_type_u":		"luoriquan",
				"u_adjust":		15,
                "skill_type_d":		"stormdance",
                "unarmed":		"luoriquan",
                "blade":		"chillblade",
                "force":		"snowforce",
                "parry":		"chillblade",
                "spells":		"heart-listening",
                "dodge":		"xifengying",
                "move":		"stormdance",
                "dodge":		"stormdance",
				"throwing":		"starrain",
		"perform_weapon_attack":"moon/blade/chillblade/no,i use hasted normal attack",
		"perform_weapon_attack2":"moon/blade/chillblade/mingyue",
		"perform_weapon_attack3":"moon/blade/chillblade/qinghui",
		"perform_weapon_attack4":"moon/throwing/starrain/tianheyixian",
		"perform_unarmed_attack":	"moon/unarmed/luoriquan/changrijiangjin",     
		"perform_unarmed_attack2":	"moon/force/snowforce/bingpojingbi",     
		"perform_unarmed_attack3":	"moon/dodge/stormdance/hanlingluoxue",     
		"perform_unarmed_attack4":	"moon/dodge/stormdance/shuangtianxuewu",     
        ]), 
//	魔教  	
  	([      
		"group":		"fighter_w",
		"npc":                	"sheolmagic",
		"name":			"夜叉",
		"class":	      	"demon",
		"gender":		"男性",
		"skill_type_u":		"demon-strike",
		"u_adjust":		15,
		"skill_type_d":		"moon-blade",
		"d_adjust":		-50,
		"unarmed":		"demon-strike",
		"force":		"divineforce",
		"parry":		"demon-strike",
		"dodge":		"moon-blade",
		"magic":		"sheolmagic",
		"others1":		"bloodystrike",
		"others2":		"liangyi-force",
		"others3":		"demon-steps",
		"perform_unarmed_attack":"demon/unarmed/demon-strike/npc_summon1",
		"perform_unarmed_attack2":"demon/unarmed/demon-strike/npc_summon2",
		"perform_unarmed_attack3":"demon/unarmed/demon-strike/npc_summon3",
		"perform_unarmed_attack4":"demon/unarmed/demon-strike/npc_summon4",
		"perform_unarmed_attack5":"demon/unarmed/demon-strike/npc_summon5",
		"perform_busy_d": "demon/dodge/demon-steps/rufengsibi",
		"perform_busy_u1":"lama/unarmed/bloodystrike/fofawubian",
        ]),
  	([      
		"group":		"fighter_w",
		"npc":                	"feixiansword",
		"name":			"摩呼罗迦",
		"class":	      	"demon",
		"gender":		"男性",
		"skill_type_w":		"sword/feixiansword",
		"w_adjust":		11,
		"skill_type_u":		"demon-strike",
		"u_adjust":		15,
		"skill_type_d":		"moon-blade",
		"d_adjust":		-50,
		"sword":		"feixiansword",
		"unarmed":		"demon-strike",
		"force":		"divineforce",
		"parry":		"feixiansword",
		"dodge":		"moon-blade",
		"magic":		"sheolmagic",
		"others1":		"music",
		"others2":		"demon-steps",
		"others3":		"fall-steps",
		"perform_unarmed_attack":"demon/unarmed/spicyclaw/extrahit4",
		"perform_weapon_attack":"demon/sword/feixiansword/tianwaifeixian",
		"perform_busy_u":"demon/unarmed/demon-strike/npc_by_shimian",
//		"perform_busy_u":"demon/dodge/demon-steps/lianhuanbabu",
		"perform_busy_u1":"demon/dodge/fall-steps/luoyeqiufeng",
        ]),
  	([      
		"group":		"fighter_w",
		"npc":                	"demonblade",
		"name":			"迦楼罗",
		"class":	      	"demon",
		"gender":		"男性",
		"skill_type_w":		"blade/demon-blade",
		"skill_type_u":		"demon-strike",
		"u_adjust":		15,
		"skill_type_d":		"moon-blade",
		"d_adjust":		-50,
		"blade":		"demon-blade",
		"unarmed":		"demon-strike",
		"force":		"divineforce",
		"parry":		"demon-blade",
		"dodge":		"moon-blade",
		"magic":		"sheolmagic",
		"others1":		"demon-steps",
		"others2":		"fall-steps",
		"perform_unarmed_attack":"demon/unarmed/demon-strike/renmo",
		"perform_unarmed_attack2":"demon/force/divineforce/guishenpomie",
		"perform_weapon_attack":"demon/blade/demon-blade/npc_tiandirenmo",
		"perform_busy_d":"demon/dodge/demon-steps/lianhuanbabu",
//		"perform_busy_d":"demon/dodge/fall-steps/luoyeqiufeng",
        ]),
  	([      
		"group":		"fighter_w",
		"npc":         	"illusionstick",
		"name":			"紧那罗",
		"class":	      	"demon",
		"gender":		"男性",
		"skill_type_w":		"staff/illusionstick",
		"w_adjust":		100,
		"skill_type_u":		"kongshoudao",
		"u_adjust":		70,
		"skill_type_d":		"moon-blade",
		"d_adjust":		-50,
		"staff":		"illusionstick",
		"unarmed":		"demon-strike",
		"force":		"divineforce",
		"parry":		"illusionstick",
		"dodge":		"moon-blade",
		"magic":		"sheolmagic",
		"others1":		"fall-steps",
		"others2":		"fengyu-piaoxiang",
		"perform_unarmed_attack":"demon/unarmed/kongshoudao/yaozhan",
		"perform_weapon_attack":"demon/staff/illusionstick/menghuantianluo",
		"perform_busy_d":"demon/dodge/fall-steps/luoyeqiufeng",
		"perform_busy_u1":"bat/dodge/fengyu-piaoxiang/zonghengsihai",
        ]),
  	([      
		"group":		"fighter_w",
		"npc":                	"divineforce",
		"name":			"乾达婆",
		"class":	      	"demon",
		"gender":		"女性",
		"skill_type_u":		"demon-strike",
		"u_adjust":		15,
		"skill_type_d":		"moon-blade",
		"d_adjust":		-50,
		"unarmed":		"demon-strike",
		"force":		"divineforce",
		"parry":		"demon-strike",
		"dodge":		"moon-blade",
		"magic":		"sheolmagic",
		"others1":		"demon-steps",
		"perform_unarmed_attack":"demon/unarmed/demon-strike/renmo",
		"perform_unarmed_attack2":"demon/force/divineforce/manaflare",
		"perform_unarmed_attack3":"demon/force/divineforce/baocanshouque",
		"perform_unarmed_attack4":"demon/force/divineforce/disorder",
		"perform_busy_d":"no_dodge_busy",
        ]),
  	([      
		"group":		"fighter_w",
		"npc":                	"kaleidostrike",
		"name":			"阿修罗",
		"class":	      	"demon",
		"gender":		"男性",
		"skill_type_u":		"kaleidostrike",
		"u_adjust":		-15,
		// 使用时需附加apply/attack。 kld-strike coeff不高，可是高级别的影响巨大，此限。
		"skill_type_d":		"moon-blade",
		"d_adjust":		-50,
		"unarmed":		"kaleidostrike",
		"force":		"divineforce",
		"parry":		"demon-strike",
		"dodge":		"moon-blade",
		"magic":		"sheolmagic",
		"others1":		"fall-steps",
		"others2":		"fengyu-piaoxiang",
		"perform_unarmed_attack":"demon/unarmed/kaleidostrike/xukongyeyue",
		"perform_busy_d":"demon/dodge/fall-steps/luoyeqiufeng",
		"perform_busy_u1":"bat/dodge/fengyu-piaoxiang/zonghengsihai",
        ]),
  	([      
		"group":		"fighter_w",
		"npc":                	"dragonwhip",
		"name":			"龙",
		"class":	      	"demon",
		"gender":		"男性",
		"skill_type_w":		"whip/dragonwhip",
		"w_adjust":		-5,
		"skill_type_u":		"demon-strike",
		"u_adjust":		15,
		"skill_type_d":		"moon-blade",
		"d_adjust":		-50,
		"whip":		"dragonwhip",
		"unarmed":		"demon-strike",
		"force":		"divineforce",
		"parry":		"thunderwhip",
		"dodge":		"moon-blade",
		"magic":		"sheolmagic",
		"others1":		"demon-steps",
		"others2":		"fall-steps",
		"others3":		"thunderwhip",
		"perform_unarmed_attack":"demon/unarmed/demon-strike/renmo",
		"perform_unarmed_attack2":"demon/dodge/demon-steps/lianhuanbabu",
		"perform_weapon_attack":"demon/whip/dragonwhip/thousandfeather",
		"perform_weapon_attack2":"demon/whip/dragonwhip/firestorm",
		"perform_busy_d":"demon/dodge/fall-steps/luoyeqiufeng",
		"perform_busy_w":"demon/whip/dragonwhip/thousandfeather",
        ]),
  	([      
		"group":		"fighter_w",
		"npc":                	"daimonsword",
		"name":			"天",
		"class":	      	"demon",
		"gender":		"男性",
		"skill_type_w":		"sword/daimonsword",
		"w_adjust":		10,
		"skill_type_u":		"demon-strike",
		"u_adjust":		15,
		"skill_type_d":		"moon-blade",
		"d_adjust":		-50,
		"sword":		"daimonsword",
		"unarmed":		"demon-strike",
		"force":		"divineforce",
		"parry":		"13-sword",
		"dodge":		"moon-blade",
		"magic":		"sheolmagic",
		"others1":		"demon-steps",
		"others2":		"13-sword",
//		"others1":		"fall-steps",
//		"others3":		"fengyu-piaoxiang",
		"perform_unarmed_attack":"demon/unarmed/demon-strike/renmo",
		"perform_unarmed_attack2":"demon/force/divineforce/wudumiaodi",
		"perform_weapon_attack":"demon/sword/daimonsword/libie",
		"perform_weapon_attack2":"demon/sword/daimonsword/chousi",
		"perform_weapon_attack3":"demon/sword/daimonsword/duanchang",
		"perform_busy_d":"demon/dodge/demon-steps/lianhuanbabu",
//		"perform_busy_d":"demon/dodge/fall-steps/luoyeqiufeng",
//		"perform_busy_u1":"bat/dodge/fengyu-piaoxiang/zonghengsihai",

        ]),
 	([      
		"group":		"fighter_w",
		"npc":                	"mixed_demon",
		"name":			"天龙八部",
		"class":	      	"demon",
		"gender":		"男性",
		"skill_type_w":		"blade/demon-blade",
		"w_adjust":		20,
		"skill_type_u":		"kaleidostrike",
		"u_adjust":		10,
		"skill_type_d":		"moon-blade",
		"d_adjust":		-30,
		"whip":			"dragonwhip",
		"blade":		"demon-blade",
		"sword":		"daimonsword",
		"unarmed":		"kaleidostrike",
		"force":		"divineforce",
		"parry":		"demon-strike",
		"dodge":		"moon-blade",
		"magic":		"sheolmagic",
		"others1":		"demon-steps",
		"perform_unarmed_attack2":"demon/force/divineforce/wudumiaodi",
		"perform_unarmed_attack4":"demon/force/divineforce/manaburst",
		"perform_unarmed_attack5":"demon/force/divineforce/baocanshouque",
		"perform_weapon_attack":"demon/force/divineforce/disorder",
		"perform_weapon_attack3":"demon/whip/dragonwhip/thousandfeather",
		"perform_weapon_attack4":"demon/whip/dragonwhip/firestorm",
		"perform_unarmed_attack_g":"demon/blade/demon-blade/npc_tiandirenmo",
		"perform_busy_u1":"demon/force/divineforce/npc_summon4",
		"perform_busy_u2":"demon/force/divineforce/npc_summon5",
		"perform_busy_u3":"demon/sword/daimonsword/libie",
		"perform_busy_d_g":"demon/sword/daimonsword/chousi",
		"perform_busy_u_g":"demon/sword/daimonsword/duanchang",
		"perform_busy_d":"demon/dodge/demon-steps/lianhuanbabu",
		"perform_busy_w":"demon/whip/dragonwhip/thousandfeather",
        ]),

	// 魔教另种方案，性别对应。

  	([      
		"group":		"fighter_w",
		"npc":                	"daimonsword2",
		"name":			"天",
		"class":	      	"demon",
		"gender":		"女性",
		"skill_type_w":		"blade/heavendance",
		"skill_type_u":		"demon-strike",
		"skill_type_d":		"fengyu-piaoxiang",
		"blade":		"heavendance",
		"unarmed":		"demon-strike",
		"force":		"divineforce",
		"parry":		"demon-strike",
		"dodge":		"fengyu-piaoxiang",
		"magic":		"sheolmagic",
		"others1":		"zensword",
		"others2":		"zen",
		"others3":		"xiaodao",
		"perform_unarmed_attack":"demon/unarmed/demon-strike/renmo",
		"perform_unarmed_attack2":"demon/force/divineforce/wudumiaodi",
		"perform_weapon_attack":"demon/blade/heavendance/yuexierenjing",
//		"perform_busy_d":"demon/dodge/demon-steps/lianhuanbabu",
        ]),

 	([      
		"group":		"fighter_w",
		"npc":                	"dragonwhip2",
		"name":			"龙",
		"class":	      	"demon",
		"gender":		"女性",
		"skill_type_u":		"luoriquan",
		"u_adjust":		15,
		"skill_type_d":		"moon-blade",
		"d_adjust":		-50,
		"unarmed":		"luoriquan",
		"force":		"divineforce",
		"parry":		"luoriquan",
		"dodge":		"moon-blade",
		"magic":		"sheolmagic",
		"others1":		"fengyu-piaoxiang",
		"others1":		"fall-steps",
		"perform_unarmed_attack":"demon/unarmed/luoriquan/changrijiangjin",
		"perform_busy_d":"demon/dodge/fall-steps/luoyeqiufeng",
		"perform_busy_u1":"bat/dodge/fengyu-piaoxiang/zonghengsihai",
        ]),

  	([      
		"group":		"fighter_w",
		"npc":                	"kaleidostrike2",
		"name":			"阿修罗",
		"class":	      	"demon",
		"gender":		"女性",
		"skill_type_u":		"kaleidostrike",
		"u_adjust":		-15,
		// 使用时需附加apply/attack。 kld-strike coeff不高，可是高级别的影响巨大，此限。
		"skill_type_d":		"moon-blade",
		"d_adjust":		-50,
		"unarmed":		"kaleidostrike",
		"force":		"divineforce",
		"parry":		"demon-strike",
		"dodge":		"moon-blade",
		"magic":		"sheolmagic",
		"others1":		"fall-steps",
		"others2":		"fengyu-piaoxiang",
		"perform_busy_d":"demon/dodge/fall-steps/luoyeqiufeng",
		"perform_busy_u1":"bat/dodge/fengyu-piaoxiang/zonghengsihai",
        ]),

  	([      
		"group":		"fighter_w",
		"npc":                	"divineforce2",
		"name":			"乾达婆",
		"class":	      	"demon",
		"gender":		"男性",
		"skill_type_u":		"demon-strike",
		"u_adjust":		15,
		"skill_type_d":		"moon-blade",
		"d_adjust":		-50,
		"unarmed":		"demon-strike",
		"force":		"divineforce",
		"parry":		"demon-strike",
		"dodge":		"moon-blade",
		"magic":		"sheolmagic",
		"others1":		"demon-steps",
		"perform_unarmed_attack":"demon/unarmed/demon-strike/renmo",
		"perform_unarmed_attack2":"demon/force/divineforce/lesserdeathgrip",
		"perform_unarmed_attack3":"demon/force/divineforce/baocanshouque",
		"perform_unarmed_attack4":"demon/force/divineforce/terror",
		"perform_busy_d":"no_dodge_busy",
        ]),

  	([      
		"group":		"fighter_w",
		"npc":                	"demonblade2",
		"name":			"迦楼罗",
		"class":	      	"demon",
		"gender":		"女性",
		"skill_type_u":		"spicyclaw",
		"skill_type_d":		"moon-blade",
		"d_adjust":		-50,
		"unarmed":		"spicyclaw",
		"force":		"divineforce",
		"parry":		"spicyclaw",
		"dodge":		"moon-blade",
		"magic":		"sheolmagic",
		"others1":		"music",
		"others2":		"demon-steps",
		"others3":		"fall-steps",
		"perform_unarmed_attack":"demon/unarmed/spicyclaw/extrahit1",
		"perform_unarmed_attack2":"demon/unarmed/spicyclaw/extrahit2",
		"perform_unarmed_attack3":"demon/unarmed/spicyclaw/extrahit3",
		"perform_unarmed_attack4":"demon/unarmed/spicyclaw/extrahit4",
		"perform_unarmed_attack5":"demon/unarmed/spicyclaw/extrahit5",
		"perform_busy_u":"demon/unarmed/demon-strike/npc_by_shimian",
//		"perform_busy_u":"demon/dodge/demon-steps/lianhuanbabu",
		"perform_busy_u1":"demon/dodge/fall-steps/luoyeqiufeng",
        ]),

	([      
		"group":		"fighter_w",
		"npc":                	"feixiansword2",
		"name":			"摩呼罗迦",
		"class":	      	"demon",
		"gender":		"女性",
		"skill_type_w":		"sword/demosword",
		"w_adjust":		10,
		"skill_type_u":		"demon-strike",
		"u_adjust":		15,
		"skill_type_d":		"moon-blade",
		"d_adjust":		-50,
		"sword":		"daimonsword",
		"unarmed":		"demon-strike",
		"force":		"divineforce",
		"parry":		"demon-strike",
		"dodge":		"moon-blade",
		"magic":		"sheolmagic",
		"others1":		"fall-steps",
		"others2":		"zen",
		"others3":		"xiaodao",
		"perform_unarmed_attack":"demon/unarmed/demon-strike/renmo",
		"perform_unarmed_attack2":"demon/force/divineforce/guishenpomie",
		"perform_weapon_attack":"demon/sword/zensword/menghuankonghua",
		"perform_weapon_attack2":"demon/sword/demosword/zhutianjianzhen",
		"perform_busy_d":"legend/dodge/fall-steps/luoyeqiufeng",
        ]),

   	([      
		"group":		"fighter_w",
		"npc":         	"illusionstick2",
		"name":			"紧那罗",
		"class":	      	"demon",
		"gender":		"女性",
		"skill_type_w":		"spells/devil-spells",
		"w_adjust":		40,
		"skill_type_u":		"kongshoudao",
		"u_adjust":		70,
		"skill_type_d":		"moon-blade",
		"d_adjust":		-50,
		"spells":		"devil-spells",
		"unarmed":		"demon-strike",
		"force":		"divineforce",
		"parry":		"illusionstick",
		"dodge":		"moon-blade",
		"magic":		"sheolmagic",
		"others1":		"fall-steps",
		"others2":		"fengyu-piaoxiang",
		"others3":		"eagle-claw",
//		"perform_weapon_attack":"demon/staff/illusionstick/menghuantianluo",
		"perform_busy_d":"demon/dodge/fall-steps/luoyeqiufeng",
		"perform_busy_u1":"bat/dodge/fengyu-piaoxiang/zonghengsihai",
		"perform_busy_u2":"fugui/unarmed/eagle-claw/shizhiqinlong",
        ]),

  	([      
		"group":		"fighter_w",
		"npc":                	"sheolmagic2",
		"name":			"夜叉",
		"class":	      	"demon",
		"gender":		"女性",
		"skill_type_u":		"demon-strike",
		"u_adjust":		15,
		"skill_type_d":		"moon-blade",
		"d_adjust":		-50,
		"unarmed":		"demon-strike",
		"force":		"divineforce",
		"parry":		"demon-strike",
		"dodge":		"moon-blade",
		"magic":		"sheolmagic",
		"others1":		"bloodystrike",
		"others2":		"liangyi-force",
		"others3":		"demon-steps",
		"perform_busy_u1":"demon/unarmed/demon-strike/rufengsibi",
		"perform_busy_u2":"demon/dodge/demon-steps/lianhuanbabu",
		"perform_busy_u3":"lama/unarmed/bloodystrike/fofawubian",
        ]),

});


mapping query_npc(string group_name, string npc_name, int special){
	
	int total,i,x,n,m;
	string npc;
	
	total=sizeof(npctype);
	n=1;
	m=total;
	
	if (npc_name=="random") {
		if (group_name=="random") x=random(total);	
		else while(n) {
			x=random(total);
			if (npctype[x]["group"]==group_name) n=0;
			}
	} else {
		while (m--) {
			if (npctype[m]["npc"]==npc_name) {
				x=m; break;		
			}
		} 
	}	
	return npctype[x];
}



int total_npc(){
	return sizeof(npctype);
}

mapping *npclist(){
	return npctype;
}