#include "ScriptPCH.h"

class mall_proff : public GameObjectScript
{
public:
    mall_proff() : GameObjectScript("mall_proff") { }

	#define GOSSIP_TEXT_ALCHEMY             "Alchemy"
	#define GOSSIP_TEXT_BLACKSMITHING       "Blacksmithing"
	#define GOSSIP_TEXT_COOKING             "Cooking"
	#define GOSSIP_TEXT_ENCHANTING          "Enchanting"
	#define GOSSIP_TEXT_ENGINEERING         "Engineering"
	#define GOSSIP_TEXT_FIRSTAID            "First Aid"
	#define GOSSIP_TEXT_HERBALISM           "Herbalism"
	#define GOSSIP_TEXT_INSCRIPTION         "Inscription"
	#define GOSSIP_TEXT_JEWELCRAFTING       "Jewelcrafting"
	#define GOSSIP_TEXT_LEATHERWORKING      "Leatherworking"
	#define GOSSIP_TEXT_TAILORING           "Tailoring"
	#define GOSSIP_TEXT_MINING              "Mining"
	#define GOSSIP_TEXT_FISHING             "Fishing"
	#define GOSSIP_TEXT_SKINNING            "Skinning"

    bool OnGossipHello(Player *player, GameObject * pGO)
    {
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_ALCHEMY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_BLACKSMITHING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_COOKING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_ENCHANTING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_ENGINEERING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_FIRSTAID, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_HERBALISM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_INSCRIPTION, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_JEWELCRAFTING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_LEATHERWORKING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_TAILORING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_MINING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_FISHING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_SKINNING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14);
        
		player->SEND_GOSSIP_MENU(50001, pGO->GetGUID());
        return true;
    }

#define GOSSIP_SURE_YES  "Yes"
#define GOSSIP_SURE_NO  "No"
#define GOSSIP_BACK  "<-- Back"

	bool OnGossipSelect(Player *pPlayer, GameObject *pGO, uint32 /*uiSender*/, uint32 uiAction)
    {
		QueryResult result = QueryResult(NULL);
        pPlayer->PlayerTalkClass->ClearMenus();
        switch (uiAction)
        {
			//#####################
			//###CONFIRMATIONS!!###
			//#####################
            case GOSSIP_ACTION_INFO_DEF+1: //alchemy
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_YES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 15);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
                pPlayer->SEND_GOSSIP_MENU(50002, pGO->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2: //blacksmith
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_YES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 17);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
                pPlayer->SEND_GOSSIP_MENU(50003, pGO->GetGUID());
                break;
			case GOSSIP_ACTION_INFO_DEF+3: //cooking
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_YES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 18);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
                pPlayer->SEND_GOSSIP_MENU(50004, pGO->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+4: //enchanting
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_YES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 19);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
                pPlayer->SEND_GOSSIP_MENU(50005, pGO->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+5: //engineering
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_YES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 20);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
                pPlayer->SEND_GOSSIP_MENU(50006, pGO->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+6: //first aid
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_YES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 21);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
                pPlayer->SEND_GOSSIP_MENU(50007, pGO->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+7: //herbalism
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_YES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 22);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
                pPlayer->SEND_GOSSIP_MENU(50008, pGO->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+8: //inscription
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_YES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 23);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
                pPlayer->SEND_GOSSIP_MENU(50009, pGO->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+9: //jewelcrafting
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_YES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 24);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
                pPlayer->SEND_GOSSIP_MENU(50010, pGO->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+10: //leatherworking
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_YES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 25);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
                pPlayer->SEND_GOSSIP_MENU(50011, pGO->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+11: //tailoring
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_YES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 26);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
                pPlayer->SEND_GOSSIP_MENU(50012, pGO->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+12: //mining
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_YES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 27);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
                pPlayer->SEND_GOSSIP_MENU(50013, pGO->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+13: //fishing
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_YES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 28);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
                pPlayer->SEND_GOSSIP_MENU(50014, pGO->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+14: //skinning
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_YES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 29);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
                pPlayer->SEND_GOSSIP_MENU(50015, pGO->GetGUID());
                break;


			//#####################
			//######ACTIONS!!######
			//#####################
			case GOSSIP_ACTION_INFO_DEF+16: //IF NOT SURE
				pPlayer->CLOSE_GOSSIP_MENU();
				break;

			case GOSSIP_ACTION_INFO_DEF+15: //alchemy
				if (pPlayer->GetFreePrimaryProfessionPoints() > 0)
				{
				pPlayer->learnSpell(51304, false);
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->SetSkill(171, pPlayer->GetSkillStep(171),450,450);
				if (pPlayer->IsActiveQuest(50001))
					pPlayer->CompleteQuest(50001); //Enrich Me, Machine!
				{
				result = WorldDatabase.Query("SELECT recipe FROM profession_recipes WHERE id = 1");
				do
				{
					Field* fields = result->Fetch();
					uint32 recipe  = fields[0].GetUInt32();

					pPlayer->learnSpell(recipe, false);
				}
				while (result->NextRow());
				/*pPlayer->PlayerTalkClass->ClearMenus();
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Master of Transmutation", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 33); //transmuations - 17
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Master of Potions", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 34);// potions - 18
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Master of Elixirs", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 35);// elixirs - 19
				pPlayer->SEND_GOSSIP_MENU(50017, pGO->GetGUID());*/
				}
				}

				else if (pPlayer->GetFreePrimaryProfessionPoints() == 0)
				{
					pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
					pPlayer->SEND_GOSSIP_MENU(50016, pGO->GetGUID());
				}
                break;
            case GOSSIP_ACTION_INFO_DEF+17: //blacksmith
				if (pPlayer->GetFreePrimaryProfessionPoints() > 0)
				{
				pPlayer->learnSpell(51300, false);
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->SetSkill(164, pPlayer->GetSkillStep(164),450,450);
				if (pPlayer->IsActiveQuest(50001))
					pPlayer->CompleteQuest(50001); //Enrich Me, Machine!
				{
				result = WorldDatabase.Query("SELECT recipe FROM profession_recipes WHERE id = 2");
				do
				{
					Field* fields = result->Fetch();
					uint32 recipe  = fields[0].GetUInt32();

					pPlayer->learnSpell(recipe, false);
				}
				while (result->NextRow());
				}
				pPlayer->CLOSE_GOSSIP_MENU();
				}
				else if (pPlayer->GetFreePrimaryProfessionPoints() == 0)
				{
					pPlayer->PlayerTalkClass->ClearMenus();
					pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
					pPlayer->SEND_GOSSIP_MENU(50016, pGO->GetGUID());
				}
                break;
			case GOSSIP_ACTION_INFO_DEF+18: //cooking
				{
				pPlayer->learnSpell(51296, false);
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->SetSkill(185, pPlayer->GetSkillStep(185),450,450);
				{
				result = WorldDatabase.Query("SELECT recipe FROM profession_recipes WHERE id = 3");
				do
				{
					Field* fields = result->Fetch();
					uint32 recipe  = fields[0].GetUInt32();

					pPlayer->learnSpell(recipe, false);
				}
				while (result->NextRow());
				}
				pPlayer->CLOSE_GOSSIP_MENU();
				}
                break;
            case GOSSIP_ACTION_INFO_DEF+19: //enchanting
				
				if (pPlayer->GetFreePrimaryProfessionPoints() > 0)
				{
				pPlayer->learnSpell(51313, false);
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->SetSkill(333, pPlayer->GetSkillStep(333),450,450);
				if (pPlayer->IsActiveQuest(50001))
					pPlayer->CompleteQuest(50001); //Enrich Me, Machine!
				{
				result = WorldDatabase.Query("SELECT recipe FROM profession_recipes WHERE id = 4");
				do
				{
					Field* fields = result->Fetch();
					uint32 recipe  = fields[0].GetUInt32();

					pPlayer->learnSpell(recipe, false);
				}
				while (result->NextRow());
				}
				pPlayer->CLOSE_GOSSIP_MENU();
				}
				else if (pPlayer->GetFreePrimaryProfessionPoints() == 0)
				{
					pPlayer->PlayerTalkClass->ClearMenus();
					pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
					pPlayer->SEND_GOSSIP_MENU(50016, pGO->GetGUID());
				}
                break;
            case GOSSIP_ACTION_INFO_DEF+20: //engineering
				
				if (pPlayer->GetFreePrimaryProfessionPoints() > 0)
				{
				pPlayer->learnSpell(51306, false);
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->SetSkill(202, pPlayer->GetSkillStep(202),450,450);
				if (pPlayer->IsActiveQuest(50001))
					pPlayer->CompleteQuest(50001); //Enrich Me, Machine!
				{
				result = WorldDatabase.Query("SELECT recipe FROM profession_recipes WHERE id = 5");
				do
				{
					Field* fields = result->Fetch();
					uint32 recipe  = fields[0].GetUInt32();

					pPlayer->learnSpell(recipe, false);
				}
				while (result->NextRow());
				}
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Gnomish Engineering", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 31); //gnomish - 15
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Goblin Engineering", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 32);// goblin - 16
				pPlayer->SEND_GOSSIP_MENU(50017, pGO->GetGUID());
				}
				if (pPlayer->GetFreePrimaryProfessionPoints() == 0)
				{
					pPlayer->PlayerTalkClass->ClearMenus();
					pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
					pPlayer->SEND_GOSSIP_MENU(50016, pGO->GetGUID());
				}
                break;
            case GOSSIP_ACTION_INFO_DEF+21: //first aid
				{
				pPlayer->learnSpell(45542, false);
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->SetSkill(129, pPlayer->GetSkillStep(129),450,450);
				{
				result = WorldDatabase.Query("SELECT recipe FROM profession_recipes WHERE id = 6");
				do
				{
					Field* fields = result->Fetch();
					uint32 recipe  = fields[0].GetUInt32();

					pPlayer->learnSpell(recipe, false);
				}
				while (result->NextRow());
				}
				pPlayer->CLOSE_GOSSIP_MENU();
				}
                break;
            case GOSSIP_ACTION_INFO_DEF+22: //herbalism
				if (pPlayer->GetFreePrimaryProfessionPoints() > 0)
				{
				pPlayer->learnSpell(50300, false);
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->SetSkill(182, pPlayer->GetSkillStep(182),450,450); 
				if (pPlayer->IsActiveQuest(50001))
					pPlayer->CompleteQuest(50001); //Enrich Me, Machine!
				pPlayer->CLOSE_GOSSIP_MENU();
				}
				else if (pPlayer->GetFreePrimaryProfessionPoints() == 0)
				{
					pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
					pPlayer->SEND_GOSSIP_MENU(50016, pGO->GetGUID());
				}
                break;
            case GOSSIP_ACTION_INFO_DEF+23: //inscription
				
				if (pPlayer->GetFreePrimaryProfessionPoints() > 0)
				{
				pPlayer->learnSpell(45363, false);
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->SetSkill(773, pPlayer->GetSkillStep(773),450,450);
				if (pPlayer->IsActiveQuest(50001))
					pPlayer->CompleteQuest(50001); //Enrich Me, Machine!
				{
				result = WorldDatabase.Query("SELECT recipe FROM profession_recipes WHERE id = 8");
				do
				{
					Field* fields = result->Fetch();
					uint32 recipe  = fields[0].GetUInt32();

					pPlayer->learnSpell(recipe, false);
				}
				while (result->NextRow());
				}
				pPlayer->CLOSE_GOSSIP_MENU();
				}
				else if (pPlayer->GetFreePrimaryProfessionPoints() == 0)
				{
					pPlayer->PlayerTalkClass->ClearMenus();
					pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
					pPlayer->SEND_GOSSIP_MENU(50016, pGO->GetGUID());
				}
                break;
            case GOSSIP_ACTION_INFO_DEF+24: //jewelcrafting
				
				if (pPlayer->GetFreePrimaryProfessionPoints() > 0)
				{
				pPlayer->learnSpell(51311, false);
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->SetSkill(755, pPlayer->GetSkillStep(755),450,450);
				if (pPlayer->IsActiveQuest(50001))
					pPlayer->CompleteQuest(50001); //Enrich Me, Machine!
				{
				result = WorldDatabase.Query("SELECT recipe FROM profession_recipes WHERE id = 9");
				do
				{
					Field* fields = result->Fetch();
					uint32 recipe  = fields[0].GetUInt32();

					pPlayer->learnSpell(recipe, false);
				}
				while (result->NextRow());
				}
				pPlayer->CLOSE_GOSSIP_MENU();
				}
				else if (pPlayer->GetFreePrimaryProfessionPoints() == 0)
				{
					pPlayer->PlayerTalkClass->ClearMenus();
					pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
					pPlayer->SEND_GOSSIP_MENU(50016, pGO->GetGUID());
				}
                break;
            case GOSSIP_ACTION_INFO_DEF+25: //leatherworking
				
				if (pPlayer->GetFreePrimaryProfessionPoints() > 0)
				{
				pPlayer->learnSpell(51302, false);
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->SetSkill(165, pPlayer->GetSkillStep(165),450,450);
				if (pPlayer->IsActiveQuest(50001))
					pPlayer->CompleteQuest(50001); //Enrich Me, Machine!
				{
				result = WorldDatabase.Query("SELECT recipe FROM profession_recipes WHERE id = 10");
				do
				{
					Field* fields = result->Fetch();
					uint32 recipe  = fields[0].GetUInt32();

					pPlayer->learnSpell(recipe, false);
				}
				while (result->NextRow());
				}
				pPlayer->CLOSE_GOSSIP_MENU();
				}
				else if (pPlayer->GetFreePrimaryProfessionPoints() == 0)
				{
					pPlayer->PlayerTalkClass->ClearMenus();
					pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
					pPlayer->SEND_GOSSIP_MENU(50016, pGO->GetGUID());
				}
                break;
            case GOSSIP_ACTION_INFO_DEF+26: //tailoring
				
				if (pPlayer->GetFreePrimaryProfessionPoints() > 0)
				{
				pPlayer->learnSpell(51309, false);
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->SetSkill(197, pPlayer->GetSkillStep(197),450,450);
				if (pPlayer->IsActiveQuest(50001))
					pPlayer->CompleteQuest(50001); //Enrich Me, Machine!
				{
				result = WorldDatabase.Query("SELECT recipe FROM profession_recipes WHERE id = 11");
				do
				{
					Field* fields = result->Fetch();
					uint32 recipe  = fields[0].GetUInt32();

					pPlayer->learnSpell(recipe, false);
				}
				while (result->NextRow());
				}
				pPlayer->CLOSE_GOSSIP_MENU();
				}
				else if (pPlayer->GetFreePrimaryProfessionPoints() == 0)
				{
					pPlayer->PlayerTalkClass->ClearMenus();
					pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
					pPlayer->SEND_GOSSIP_MENU(50016, pGO->GetGUID());
				}
                break;
            case GOSSIP_ACTION_INFO_DEF+27: //mining
				
				if (pPlayer->GetFreePrimaryProfessionPoints() > 0)
				{
				pPlayer->learnSpell(50310, false);
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->SetSkill(186, pPlayer->GetSkillStep(186),450,450);
				if (pPlayer->IsActiveQuest(50001))
					pPlayer->CompleteQuest(50001); //Enrich Me, Machine!
				{
				result = WorldDatabase.Query("SELECT recipe FROM profession_recipes WHERE id = 12");
				do
				{
					Field* fields = result->Fetch();
					uint32 recipe  = fields[0].GetUInt32();

					pPlayer->learnSpell(recipe, false);
				}
				while (result->NextRow());
				}
				
				pPlayer->CLOSE_GOSSIP_MENU();
				}
				else if (pPlayer->GetFreePrimaryProfessionPoints() == 0)
				{
					pPlayer->PlayerTalkClass->ClearMenus();
					pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
					pPlayer->SEND_GOSSIP_MENU(50016, pGO->GetGUID());
				}
                break;
            case GOSSIP_ACTION_INFO_DEF+28: //fishing
				{
				pPlayer->learnSpell(51294, false);
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->SetSkill(356, pPlayer->GetSkillStep(356),450,450);
				pPlayer->CLOSE_GOSSIP_MENU();
				}
                break;
            case GOSSIP_ACTION_INFO_DEF+29: //skinning
				
				if (pPlayer->GetFreePrimaryProfessionPoints() > 0)
				{
				pPlayer->learnSpell(50305, false);
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->CastSpell(pPlayer, 43659, 1); //visual
				pPlayer->SetSkill(393, pPlayer->GetSkillStep(393),450,450);
				if (pPlayer->IsActiveQuest(50001))
					pPlayer->CompleteQuest(50001); //Enrich Me, Machine!
				pPlayer->CLOSE_GOSSIP_MENU();
				}
				else if (pPlayer->GetFreePrimaryProfessionPoints() == 0)
				{
					pPlayer->PlayerTalkClass->ClearMenus();
					pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
					pPlayer->SEND_GOSSIP_MENU(50016, pGO->GetGUID());
				}
                break;
				//###################
				//##SPECIALIZATIONS##
				//###################


				//ENGINEERING
			case GOSSIP_ACTION_INFO_DEF+31: // gnomish engineering
				{
					if (pPlayer->HasSkill(202))
					{
						if (pPlayer->HasSpell(20222)) //goblin
						{
							pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
							pPlayer->SEND_GOSSIP_MENU(50018, pGO->GetGUID());//TODO: Je hebt al goblin/gnome, Unlearnen?
							return true;
						}
				else
				{
						pPlayer->learnSpell(20219, false);
				{
				result = WorldDatabase.Query("SELECT recipe FROM profession_recipes WHERE id = 15");
				do
				{
					Field* fields = result->Fetch();
					uint32 recipe  = fields[0].GetUInt32();

					pPlayer->learnSpell(recipe, false);
				}
				while (result->NextRow());
				}
						pPlayer->CLOSE_GOSSIP_MENU();
						}
					}
				}
				
					break;
				case GOSSIP_ACTION_INFO_DEF+32: // goblin engineering
					
				{
					if (pPlayer->HasSkill(202))
					{
						if (pPlayer->HasSpell(20219))
						{
							pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
							pPlayer->SEND_GOSSIP_MENU(50018, pGO->GetGUID());
							return true;
						}
						else
						{
						pPlayer->learnSpell(20222, false);
				{
				result = WorldDatabase.Query("SELECT recipe FROM profession_recipes WHERE id = 16");
				do
				{
					Field* fields = result->Fetch();
					uint32 recipe  = fields[0].GetUInt32();

					pPlayer->learnSpell(recipe, false);
				}
				while (result->NextRow());
				}
						pPlayer->CLOSE_GOSSIP_MENU();
						}
					}
				}
					break;

					//ALCHEMY
				case GOSSIP_ACTION_INFO_DEF+33: // Xmute
				{
					if (pPlayer->HasSkill(171))
					{
						if (pPlayer->HasSpell(28677)/* exixir*/ || pPlayer->HasSpell(28675))
						{
							pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
							pPlayer->SEND_GOSSIP_MENU(50018, pGO->GetGUID());
							return true;
						}
						else
						{
						pPlayer->learnSpell(28672, false);
						pPlayer->CLOSE_GOSSIP_MENU();
						}
					}
				}
				break;
				case GOSSIP_ACTION_INFO_DEF+34: // Potion
				{
					if (pPlayer->HasSkill(171))
					{
						if (pPlayer->HasSpell(28672) || pPlayer->HasSpell(28677)/* exixir*/)
						{
						pPlayer->learnSpell(28675, false);
						pPlayer->CLOSE_GOSSIP_MENU();
						}
						else
						{							
							pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
							pPlayer->SEND_GOSSIP_MENU(50018, pGO->GetGUID());
						}
					}
				}
				break;
				case GOSSIP_ACTION_INFO_DEF+35: // Elixir
					
				{
					if (pPlayer->HasSkill(171))
					{
						if (pPlayer->HasActiveSpell(28672) || pPlayer->HasActiveSpell(28675))
						{
							pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
							pPlayer->SEND_GOSSIP_MENU(50018, pGO->GetGUID());
							return true;
						}
						else
						{
						pPlayer->learnSpell(28677, false);
						pPlayer->CLOSE_GOSSIP_MENU();
						}
					}
				}
					break;
			case GOSSIP_ACTION_INFO_DEF+30: //BACK TO MAIN MENU
				 pPlayer->PlayerTalkClass->ClearMenus();
					 {
							pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_ALCHEMY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
							pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_BLACKSMITHING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
							pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_COOKING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
							pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_ENCHANTING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
							pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_ENGINEERING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
							pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_FIRSTAID, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
							pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_HERBALISM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
							pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_INSCRIPTION, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
							pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_JEWELCRAFTING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
							pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_LEATHERWORKING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
							pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_TAILORING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
							pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_MINING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
							pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_FISHING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
							pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_SKINNING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14);
					        
							pPlayer->SEND_GOSSIP_MENU(50001, pGO->GetGUID());
							return true;
						}
				break;
				}
				return true;
		}
					
};

//registering
void AddSC_mall_proff()
{
	new mall_proff;
}