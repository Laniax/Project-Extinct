#include "ScriptPCH.h"
enum SpellIDs{

    //These are the spellIDs that are used to learn the professions.
    SPELL_ALCHEMY               = 51304,
    SPELL_BLACKSMITHING         = 51300,
    SPELL_COOKING               = 51296,
    SPELL_ENCHANTING            = 51313,
    SPELL_ENGINEERING           = 51306,
    SPELL_FIRSTAID              = 45542,
    SPELL_HERBALISM             = 50300,
    SPELL_INSCRIPTION           = 45363,
    SPELL_JEWELCRAFTING         = 51311,
    SPELL_LEATHERWORKING        = 51302,
    SPELL_TAILORING             = 51309,
    SPELL_MINING                = 50310,
    SPELL_FISHING               = 51294,
    SPELL_SKINNING              = 50305,

    //visual
    SPELL_VISUAL                = 43659,
};

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

    #define GOSSIP_SURE_YES  "Yes"
    #define GOSSIP_SURE_NO  "No"
    #define GOSSIP_BACK  "<-- Back"

    #define GOSSIP_TEXT_STARTNUMBER 50000 // Number where your DB text entries started minus one, for example: if your first number started on 20001, put 20000 in here. (leave default if your not sure)


    //initial gossip menu.
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

        player->SEND_GOSSIP_MENU(GOSSIP_TEXT_STARTNUMBER + 1, pGO->GetGUID());
        return true;
    }


    bool OnGossipSelect(Player *pPlayer, GameObject *pGO, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();

        switch (uiAction)
        {
            // Confirmations
            case GOSSIP_ACTION_INFO_DEF + 1:
            case GOSSIP_ACTION_INFO_DEF + 2:
            case GOSSIP_ACTION_INFO_DEF + 3:
            case GOSSIP_ACTION_INFO_DEF + 4:
            case GOSSIP_ACTION_INFO_DEF + 5:
            case GOSSIP_ACTION_INFO_DEF + 6:
            case GOSSIP_ACTION_INFO_DEF + 7:
            case GOSSIP_ACTION_INFO_DEF + 8:
            case GOSSIP_ACTION_INFO_DEF + 9:
            case GOSSIP_ACTION_INFO_DEF + 10:
            case GOSSIP_ACTION_INFO_DEF + 11:
            case GOSSIP_ACTION_INFO_DEF + 12:
            case GOSSIP_ACTION_INFO_DEF + 13:
            case GOSSIP_ACTION_INFO_DEF + 14:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_YES, GOSSIP_SENDER_MAIN, uiAction + 20);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
                pPlayer->SEND_GOSSIP_MENU((GOSSIP_TEXT_STARTNUMBER + (uiAction - 999)), pGO->GetGUID());
                break;

            //If you hit yes on the confirmation
            case GOSSIP_ACTION_INFO_DEF + 21: LearnProfession(pPlayer, SKILL_ALCHEMY, SPELL_ALCHEMY, pGO, 1, false); break; // alchemy
            case GOSSIP_ACTION_INFO_DEF + 22: LearnProfession(pPlayer, SKILL_BLACKSMITHING, SPELL_BLACKSMITHING, pGO, 2, false); break; // blacksmithing
            case GOSSIP_ACTION_INFO_DEF + 23: LearnProfession(pPlayer, SKILL_COOKING, SPELL_COOKING, pGO, 3, true); break; // cooking
            case GOSSIP_ACTION_INFO_DEF + 24: LearnProfession(pPlayer, SKILL_ENCHANTING, SPELL_ENCHANTING, pGO, 4, false); break; // enchanting
            case GOSSIP_ACTION_INFO_DEF + 25: LearnProfession(pPlayer, SKILL_ENGINERING, SPELL_ENGINEERING, pGO, 5, false); break; // engineering
            case GOSSIP_ACTION_INFO_DEF + 26: LearnProfession(pPlayer, SKILL_FIRST_AID, SPELL_FIRSTAID, pGO, 6, true); break; // first aid
            case GOSSIP_ACTION_INFO_DEF + 27: LearnProfession(pPlayer, SKILL_HERBALISM, SPELL_HERBALISM, pGO, 7, false); break; // herbalism
            case GOSSIP_ACTION_INFO_DEF + 28: LearnProfession(pPlayer, SKILL_INSCRIPTION, SPELL_INSCRIPTION, pGO, 8, false); break; // inscription
            case GOSSIP_ACTION_INFO_DEF + 29: LearnProfession(pPlayer, SKILL_JEWELCRAFTING, SPELL_JEWELCRAFTING, pGO, 9, false); break; // jewelcrafting
            case GOSSIP_ACTION_INFO_DEF + 30: LearnProfession(pPlayer, SKILL_LEATHERWORKING, SPELL_LEATHERWORKING, pGO, 10, false); break; // leatherworking
            case GOSSIP_ACTION_INFO_DEF + 31: LearnProfession(pPlayer, SKILL_TAILORING, SPELL_TAILORING, pGO, 11, false); break; // tailoring
            case GOSSIP_ACTION_INFO_DEF + 32: LearnProfession(pPlayer, SKILL_MINING, SPELL_MINING, pGO, 12, false); break; // mining
            case GOSSIP_ACTION_INFO_DEF + 33: LearnProfession(pPlayer, SKILL_FISHING, SPELL_FISHING, pGO, 13, true); break; // fishing
            case GOSSIP_ACTION_INFO_DEF + 34: LearnProfession(pPlayer, SKILL_SKINNING, SPELL_SKINNING, pGO, 14, false); break; // skinning

            //Back to main button
            case GOSSIP_ACTION_INFO_DEF + 100:
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

                            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXT_STARTNUMBER + 1, pGO->GetGUID());
                            break;
                }
                return true;
        }

    void LearnProfession(Player* pPlayer, uint32 SkillID, uint32 SpellLearnID, GameObject* pGO, int internalID, bool secondary)
    {
        QueryResult result = QueryResult(NULL);

        if (secondary || pPlayer->GetFreePrimaryProfessionPoints() > 0)
        {
            //Visuals
            pPlayer->CastSpell(pPlayer, SPELL_VISUAL, 1);
            pPlayer->CastSpell(pPlayer, SPELL_VISUAL, 1);
            pPlayer->CastSpell(pPlayer, SPELL_VISUAL, 1);

            //Learn + skill the profession to 450.
            pPlayer->learnSpell(SpellLearnID, false);
            pPlayer->SetSkill(SkillID, pPlayer->GetSkillStep(SkillID),450,450);

            //Learn recipes
            result = WorldDatabase.Query("SELECT recipe FROM profession_recipes WHERE id = " + internalID);
            do
            {
                Field* fields = result->Fetch();
                uint32 recipe  = fields[0].GetUInt32();
                pPlayer->learnSpell(recipe, false);
            }
            while (result->NextRow());

        }
        else if (pPlayer->GetFreePrimaryProfessionPoints() == 0)
        {
                pPlayer->PlayerTalkClass->ClearMenus();
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
                pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXT_STARTNUMBER + 1, pGO->GetGUID());
        }
    }
};

void AddSC_mall_proff()
{
    new mall_proff;
}