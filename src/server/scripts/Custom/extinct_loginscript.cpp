
#include "ScriptPCH.h"
AchievementEntry const* WELCOME_TO_PROJECT_EXTINCT = GetAchievementStore()->LookupEntry(5000);

class extinct_loginscript : public PlayerScript
{
    public:
        extinct_loginscript() : PlayerScript("extinct_loginscript") { }

            void OnLogin(Player * pPlayer)
            {
                if (pPlayer->HasAtLoginFlag(AT_LOGIN_FIRST))
                {
                    pPlayer->SetSpecsCount(2);
                    pPlayer->SendTalentsInfoData(false);

                    pPlayer->CastSpell(pPlayer,58351,1); //visual
                    if (pPlayer->getClass() != CLASS_DEATH_KNIGHT)
                        pPlayer->removeSpell(50977); //remove visual-learned spell..

                    pPlayer->RewardSpecialty();
                    pPlayer->RemoveAtLoginFlag(AT_LOGIN_FIRST); // en weer removen zodat het volgende login niet gebeurt ;)
                    pPlayer->GetAchievementMgr().CompletedAchievement(WELCOME_TO_PROJECT_EXTINCT);
                    pPlayer->SaveToDB();
                }
                if (pPlayer->GetSession()->GetSecurity() == SEC_PLAYER)
                        pPlayer->TeleportTo(726,1,1,1,1,0); // trigger introduction -- coords N.Y.I.

                pPlayer->LearnExtraSpells();
                pPlayer->RewardDonator();
                pPlayer->UnlearnTalentsYouShouldNotHave();
                pPlayer->SaveToDB();
            }
};

void AddSC_extinct_loginscript()
{
    new extinct_loginscript();
}