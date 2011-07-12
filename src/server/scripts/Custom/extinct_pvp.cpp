
#include "ScriptPCH.h"
#include "Player.h"

class extinct_pvp : public PlayerScript
{
    public:
		extinct_pvp() : PlayerScript("extinct_pvp") { }

			void OnLogin(Player * pPlayer)
			{
				if (pPlayer->HasAtLoginFlag(AT_LOGIN_FIRST))
				{    					
					pPlayer->SetSpecsCount(2); //dual specs
					pPlayer->SendTalentsInfoData(false);

					pPlayer->CastSpell(pPlayer,58351,1); //visual
					if (pPlayer->getClass() != CLASS_DEATH_KNIGHT)
						pPlayer->removeSpell(50977); //remove visual-learned spell.. tis een DK spell dus unlearn hem niet van een DK..lol

					pPlayer->RewardSpecialty(); //Specialty is een first-time-login only iets.
					pPlayer->RemoveAtLoginFlag(AT_LOGIN_FIRST); // en weer removen zodat het volgende login niet gebeurt ;)
					pPlayer->SaveToDB();
				}
				pPlayer->LearnExtraSpells();
				pPlayer->RewardDonator();
				pPlayer->UnlearnTalentsYouShouldNotHave();
			}

			void OnPlayerEnterMap(Map* /*map*/, Player* player)
			{
				player->DurabilityRepairAll(false,0,false);
			}
};

void AddSC_extinct_pvp()
{
    new extinct_pvp();
}