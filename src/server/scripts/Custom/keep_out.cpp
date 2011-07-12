
#include "ScriptPCH.h"
//#include "OutdoorPvPWG.h"

class keep_out : public CreatureScript
{
    public:
		keep_out() : CreatureScript("keep_out") {  }

	struct keep_outAI : public Scripted_NoMovementAI
    {
		keep_outAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
        {
            pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            pCreature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_NORMAL, true);
            pCreature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
        }

        void Reset(){}

        void EnterCombat(Unit* /*pWho*/){}

        void AttackStart(Unit* /*pWho*/){}

        void MoveInLineOfSight(Unit *pWho)
        { 
			{
					if (!pWho || !pWho->IsInWorld()) // als pWho niet bestaat, of niet in de wereld is..
						 return;					// stop er dan mee
					if (!me->IsWithinDist(pWho, 65.0f, false))	// als pWho verder weg is als 65yards..
						 return;								// stop er dan mee

					Player *player = pWho->GetCharmerOrOwnerPlayerOrPlayerItself();

					if (!player || player->isGameMaster() || player->IsBeingTeleported()) //als er geen speler is, als het een GM is, of als die al geteleport word..
						 return;															// stop er dan mee
					if (me->isInBackInMap(pWho, 30.0f))
					{
						me->Whisper(300010,LANG_UNIVERSAL, pWho->GetGUID()); // Player krijgt een whisper
						pWho->ToPlayer()->TeleportTo(0,-11138.699219f,-1748.891357f,-29.736399f,1.289355f); // en ten slote teleporten we naar de xyz van mall ;)
					}
			}
			me->SetOrientation(me->GetHomePosition().GetOrientation());
            return;
		}

		void UpdateAI(const uint32 /*diff*/){}
	};
};

/*class wg_only : public CreatureScript
{
    public:

        wg_only()
            : CreatureScript("wg_only") {}

		CreatureAI* GetAI(Creature* pCreature) const
        {
                        return new wg_onlyAI(pCreature);
        }

        struct wg_onlyAI : public ScriptedAI
        {
            wg_onlyAI(Creature *c) : ScriptedAI(c) {}

            bool OnGossipHello(Player* pPlayer, Creature* pCreature)
            {
				OutdoorPvPWG* wg;
				uint32 defenders = wg->getDefenderTeam();
				if (defenders == TEAM_ALLIANCE && pPlayer->getFaction() == ALLIANCE)
				{
					pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
					pPlayer->SEND_GOSSIP_MENU(50001,me->GetGUID()); //todo new npc_text entry (success)
				}

				if (defenders == TEAM_HORDE && pPlayer->getFaction() == HORDE)
				{
					pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
					pPlayer->SEND_GOSSIP_MENU(50001,me->GetGUID()); //todo new npc_text entry (success)
				}
				else
				{
					pPlayer->SEND_GOSSIP_MENU(300008,pCreature->GetGUID());
				}
            }

			bool OnGossipSelect(Player *player, Creature *pCreature, uint32 uiSender, uint32 uiAction)
			{
				switch (uiAction)
				{
					case GOSSIP_ACTION_INFO_DEF + 1:
						player->SEND_VENDORLIST(pCreature->GetGUID());
					break;
				}
			}
		};
};*/

class talent_reset : public CreatureScript
{
    public:

        talent_reset() : CreatureScript("talent_reset") {}

			bool OnGossipHello(Player* pPlayer, Creature* pCreature)
			{
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "I want to unlearn my talents", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "I want to cure my sickness", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
				
				pPlayer->PlayerTalkClass->SendGossipMenu(1, pCreature->GetGUID());
				
				return true;
			}

			bool OnGossipSelect(Player *pPlayer, Creature *pCreature, uint32 uiSender, uint32 uiAction)
			{
				pPlayer->PlayerTalkClass->ClearMenus();
				switch (uiAction)
				{
					case GOSSIP_ACTION_INFO_DEF + 4:
							pPlayer->CLOSE_GOSSIP_MENU();
							pPlayer->RemoveAura(15007);
					break;
					case GOSSIP_ACTION_INFO_DEF + 1:
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Yes", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "No", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
						pPlayer->PlayerTalkClass->SendGossipMenu(1, pCreature->GetGUID());
					break;

					case GOSSIP_ACTION_INFO_DEF + 2:
						pPlayer->resetTalents(true);
						pPlayer->SendTalentsInfoData(false);
						pPlayer->CLOSE_GOSSIP_MENU();
					break;

					case GOSSIP_ACTION_INFO_DEF + 3:
						pPlayer->CLOSE_GOSSIP_MENU();
					break;
				 }
			return true;
			}
};

class donor_only : public CreatureScript
{
    public:

        donor_only() : CreatureScript("donor_only") {}

			bool OnGossipHello(Player* pPlayer, Creature* pCreature)
			{
				if (pPlayer->GetSession()->GetSecurity() > SEC_PLAYER)
				{
					pPlayer->SEND_VENDORLIST(pCreature->GetGUID());
				//	pCreature->Whisper(300012,pPlayer->GetGUID(), true);
				}
				else
				{
					pPlayer->PlayerTalkClass->CloseGossip();
					pCreature->MonsterWhisper("I will only sell to donators.", pPlayer->GetGUID(), false);
				}
				return true;
			}
};

class donor_two_only : public CreatureScript
{
    public:

        donor_two_only() : CreatureScript("donor_two_only") {}

			bool OnGossipHello(Player* pPlayer, Creature* pCreature)
			{
				if (pPlayer->GetSession()->GetSecurity() > SEC_DONOR_ONE)  //als je hoger bent dan donor_one
				{
					pPlayer->SEND_VENDORLIST(pCreature->GetGUID());
				}
				else
				{
					pPlayer->PlayerTalkClass->CloseGossip();
					pCreature->MonsterWhisper("I will only sell to package 3 donators.", pPlayer->GetGUID(), false);
				}
				return true;
			}
};

void AddSC_keep_out()
{
    new keep_out();
	//new wg_only();
	new talent_reset();
	new donor_only(); 
}