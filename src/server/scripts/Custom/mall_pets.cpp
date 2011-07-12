#include "ScriptPCH.h"

class GOcage_kurken : public GameObjectScript
{
    public:

        GOcage_kurken()
            : GameObjectScript("GOcage_kurken")
        {
        }

	void CreatePet(Player *player, GameObject * pGO, uint32 entry) {

        if(player->getClass() != CLASS_HUNTER)
            return;
 
        if(player->GetPet()) {
            pGO->MonsterWhisper("You already have a pet, you should stable it first.", player->GetGUID());
            player->PlayerTalkClass->CloseGossip();
            return;
        }
 
        Creature *creatureTarget = pGO->SummonCreature(entry, player->GetPositionX(), player->GetPositionY()+2, player->GetPositionZ(), player->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 500);
        if(!creatureTarget) return;
        
        Pet* pet = player->CreateTamedPetFrom(creatureTarget, 0);
        if(!pet) return;
 
        // kill original creature
        creatureTarget->setDeathState(JUST_DIED);
        creatureTarget->RemoveCorpse();
        creatureTarget->SetHealth(0);                       // just for nice GM-mode view
 
        pet->SetPower(POWER_HAPPINESS, 1048000);
 
        //pet->SetUInt32Value(UNIT_FIELD_PETEXPERIENCE,0);
        //pet->SetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP, uint32((Trinity::XP::xp_to_level(70))/4));
 
        // prepare visual effect for levelup
        pet->SetUInt32Value(UNIT_FIELD_LEVEL, player->getLevel() - 1);
        pet->GetMap()->Add((Creature*)pet);
        // visual effect for levelup
        pet->SetUInt32Value(UNIT_FIELD_LEVEL, player->getLevel());
 
        
        if(!pet->InitStatsForLevel(player->getLevel()))
            sLog->outError ("Pet Create fail: no init stats for entry %u", entry);
 
        pet->UpdateAllStats();
        
        // caster have pet now
        player->SetMinion(pet, true);
 
        pet->SavePetToDB(PET_SAVE_AS_CURRENT);
        pet->InitTalentForLevel();
        player->PetSpellInitialize();
        
        //end
        player->PlayerTalkClass->CloseGossip();
        pGO->MonsterWhisper("Pet added. You might want to feed and name it.", player->GetGUID());
    }


        bool OnGossipHello(Player* player, GameObject* pGO)
        {
            if (player->getClass() == CLASS_HUNTER)
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "I want to buy this Core Hound (Exotic) for 400 Arena Points", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
				player->SEND_GOSSIP_MENU(300005, pGO->GetGUID());
				return true;
			}
			return false;
			//Are you sure you want to buy this pet?300006
			//A securely locked cage with an exotic beast inside.. I'm going to need knowledge in the Beast Mastery talent if i want to have this pet. 300009
			//A securely locked cage with a beast inside.. 300005
        }

		#define GOSSIP_SURE_YES  "Yes, i want to pay 400 Arena Points for this beast."
		#define GOSSIP_SURE_NO  "No, i don't want it."
		#define GOSSIP_BACK  "<-- Back"

		bool OnGossipSelect(Player *player, GameObject *pGO, uint32 uiSender, uint32 uiAction)
		{
			player->PlayerTalkClass->ClearMenus();
			switch(uiAction)
				{
					case GOSSIP_ACTION_INFO_DEF + 1:
						player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_YES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
						player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
						player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
						player->SEND_GOSSIP_MENU(300006, pGO->GetGUID());
					break;

					case GOSSIP_ACTION_INFO_DEF + 2:
						if (player->HasSpell(53270)) // exotic taming
							{
								uint32 currpoints = player->GetArenaPoints();

								if (currpoints >= 2000)
									{
									CreatePet(player, pGO, 17447);
									player->SetArenaPoints(currpoints - 400); // deduct 400 AP's
									// TODO: ADD EXOTIC CHECK
									Creature* hemet = player->FindNearestCreature(55000,20,true);
									hemet->MonsterSay("Excellent choice! That Core Hound is one of Northrend's rarest!", LANG_UNIVERSAL, NULL);
									}
								else
								player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
								player->SEND_GOSSIP_MENU(300006, pGO->GetGUID());
							}
						else
							pGO->MonsterWhisper("This is an Exotic beast, you need the [Beast Mastery] talent if you want this pet.", player->GetGUID());
					break;

					case GOSSIP_ACTION_INFO_DEF + 3:
						player->PlayerTalkClass->CloseGossip();
					break;

					case GOSSIP_ACTION_INFO_DEF + 4:	
						player->PlayerTalkClass->ClearMenus();
							{
							player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "I want to buy this Core Hound (Exotic) for 400 Arena Points", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
							player->SEND_GOSSIP_MENU(300005, pGO->GetGUID());
							return true;
							}
						break;
				}
		}
};
class GOcage_croco : public GameObjectScript
{
    public:

        GOcage_croco()
            : GameObjectScript("GOcage_croco")
        {
        }

	void CreatePet(Player *player, GameObject * pGO, uint32 entry) {

        if(player->getClass() != CLASS_HUNTER)
            return;
 
        if(player->GetPet()) {
            pGO->MonsterWhisper("You already have a pet, you should stable it first.", player->GetGUID());
            player->PlayerTalkClass->CloseGossip();
            return;
        }
 
        Creature *creatureTarget = pGO->SummonCreature(entry, player->GetPositionX(), player->GetPositionY()+2, player->GetPositionZ(), player->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 500);
        if(!creatureTarget) return;
        
        Pet* pet = player->CreateTamedPetFrom(creatureTarget, 0);
        if(!pet) return;
 
        // kill original creature
        creatureTarget->setDeathState(JUST_DIED);
        creatureTarget->RemoveCorpse();
        creatureTarget->SetHealth(0);                       // just for nice GM-mode view
 
        pet->SetPower(POWER_HAPPINESS, 1048000);
 
        //pet->SetUInt32Value(UNIT_FIELD_PETEXPERIENCE,0);
        //pet->SetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP, uint32((Trinity::XP::xp_to_level(70))/4));
 
        // prepare visual effect for levelup
        pet->SetUInt32Value(UNIT_FIELD_LEVEL, player->getLevel() - 1);
        pet->GetMap()->Add((Creature*)pet);
        // visual effect for levelup
        pet->SetUInt32Value(UNIT_FIELD_LEVEL, player->getLevel());
 
        
        if(!pet->InitStatsForLevel(player->getLevel()))
            sLog->outError ("Pet Create fail: no init stats for entry %u", entry);
 
        pet->UpdateAllStats();
        
        // caster have pet now
        player->SetMinion(pet, true);
 
        pet->SavePetToDB(PET_SAVE_AS_CURRENT);
        pet->InitTalentForLevel();
        player->PetSpellInitialize();
        
        //end
        player->PlayerTalkClass->CloseGossip();
        pGO->MonsterWhisper("Pet added. You might want to feed and name it.", player->GetGUID());
    }


        bool OnGossipHello(Player* player, GameObject* pGO)
        {
            if (player->getClass() == CLASS_HUNTER)
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "I want to buy this Crocolisk for 20000 Honor.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
				player->SEND_GOSSIP_MENU(300005, pGO->GetGUID());
				return true;
			}
			return false;
			//Are you sure you want to buy this pet?300006
			//A securely locked cage with an exotic beast inside.. I'm going to need knowledge in the Beast Mastery talent if i want to have this pet. 300009
			//A securely locked cage with a beast inside.. 300005
        }

		#define GOSSIP_SURE_YES_2K  "Yes, i want to pay 20000 Honor for this beast."
		#define GOSSIP_SURE_NO  "No, i don't want it."
		#define GOSSIP_BACK  "<-- Back"

		bool OnGossipSelect(Player *player, GameObject *pGO, uint32 uiSender, uint32 uiAction)
		{
			player->PlayerTalkClass->ClearMenus();
			switch(uiAction)
				{
					case GOSSIP_ACTION_INFO_DEF + 1:
						player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_YES_2K, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
						player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
						player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
						player->SEND_GOSSIP_MENU(300006, pGO->GetGUID());
						return true;
					break;

					case GOSSIP_ACTION_INFO_DEF + 2:
						{
								uint32 currpoints = player->GetHonorPoints();
								if (currpoints >= 2000)
									{
									CreatePet(player, pGO, 55555);
									player->SetHonorPoints(currpoints - 20000); // deduct 20k HP's
									}
								else
								player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
								player->SEND_GOSSIP_MENU(300006, pGO->GetGUID());
								return true;
						}
					break;

					case GOSSIP_ACTION_INFO_DEF + 3:
						player->PlayerTalkClass->CloseGossip();
						return true;
					break;

					case GOSSIP_ACTION_INFO_DEF + 4:	
						player->PlayerTalkClass->ClearMenus();
							{
							player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "I want to buy this Crocolisk for 20000 Honor.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
							player->SEND_GOSSIP_MENU(300005, pGO->GetGUID());
							return true;
							}
						break;
				}
		}
};
class GOcage_ravager : public GameObjectScript
{
    public:

        GOcage_ravager()
            : GameObjectScript("GOcage_ravager")
        {
        }

	void CreatePet(Player *player, GameObject * pGO, uint32 entry) {

        if(player->getClass() != CLASS_HUNTER)
            return;
 
        if(player->GetPet()) {
            pGO->MonsterWhisper("You already have a pet, you should stable it first.", player->GetGUID());
            player->PlayerTalkClass->CloseGossip();
            return;
        }
 
        Creature *creatureTarget = pGO->SummonCreature(entry, player->GetPositionX(), player->GetPositionY()+2, player->GetPositionZ(), player->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 500);
        if(!creatureTarget) return;
        
        Pet* pet = player->CreateTamedPetFrom(creatureTarget, 0);
        if(!pet) return;
 
        // kill original creature
        creatureTarget->setDeathState(JUST_DIED);
        creatureTarget->RemoveCorpse();
        creatureTarget->SetHealth(0);                       // just for nice GM-mode view
 
        pet->SetPower(POWER_HAPPINESS, 1048000);
 
        //pet->SetUInt32Value(UNIT_FIELD_PETEXPERIENCE,0);
        //pet->SetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP, uint32((Trinity::XP::xp_to_level(70))/4));
 
        // prepare visual effect for levelup
        pet->SetUInt32Value(UNIT_FIELD_LEVEL, player->getLevel() - 1);
        pet->GetMap()->Add((Creature*)pet);
        // visual effect for levelup
        pet->SetUInt32Value(UNIT_FIELD_LEVEL, player->getLevel());
 
        
        if(!pet->InitStatsForLevel(player->getLevel()))
            sLog->outError ("Pet Create fail: no init stats for entry %u", entry);
 
        pet->UpdateAllStats();
        
        // caster have pet now
        player->SetMinion(pet, true);
 
        pet->SavePetToDB(PET_SAVE_AS_CURRENT);
        pet->InitTalentForLevel();
        player->PetSpellInitialize();
        
        //end
        player->PlayerTalkClass->CloseGossip();
        pGO->MonsterWhisper("Pet added. You might want to feed and name it.", player->GetGUID());
    }


        bool OnGossipHello(Player* player, GameObject* pGO)
        {
            if (player->getClass() == CLASS_HUNTER)
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "I want to buy this Ravager.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
				player->SEND_GOSSIP_MENU(300005, pGO->GetGUID());
				return true;
			}
			return false;
			//Are you sure you want to buy this pet?300006
			//A securely locked cage with an exotic beast inside.. I'm going to need knowledge in the Beast Mastery talent if i want to have this pet. 300009
			//A securely locked cage with a beast inside.. 300005
        }

		#define GOSSIP_SURE_YES_RAV  "Yes, i want this Ravager."
		#define GOSSIP_SURE_NO  "No, i don't want it."
		#define GOSSIP_BACK  "<-- Back"

		bool OnGossipSelect(Player *player, GameObject *pGO, uint32 uiSender, uint32 uiAction)
		{
			player->PlayerTalkClass->ClearMenus();
			switch(uiAction)
				{
					case GOSSIP_ACTION_INFO_DEF + 1:
						player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_YES_RAV, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
						player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SURE_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
						player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GOSSIP_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
						player->SEND_GOSSIP_MENU(300006, pGO->GetGUID());
					break;

					case GOSSIP_ACTION_INFO_DEF + 2:
						CreatePet(player, pGO, 55556);
					break;

					case GOSSIP_ACTION_INFO_DEF + 3:
						player->PlayerTalkClass->CloseGossip();
					break;

					case GOSSIP_ACTION_INFO_DEF + 4:	
						player->PlayerTalkClass->ClearMenus();
							{
							player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "I want to buy this Ravager.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
							player->SEND_GOSSIP_MENU(300005, pGO->GetGUID());
							return true;
							}
						break;
				}
		}
};

void AddSC_mall_pets()
{
	new GOcage_kurken();
	new GOcage_croco();
	new GOcage_ravager();
}