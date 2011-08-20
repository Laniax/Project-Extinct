#include "ScriptPCH.h"

enum Spells
{
    AURA_COMATOSE = 1,
};

enum Events
{
    AWAKENING,
    INVASION,
    CRAWL,
    ROCKET,
    CAMP,
};

class extinct_introduction : public InstanceMapScript
{
public:
    extinct_introduction() : InstanceMapScript("extinct_introduction", 726) { }

    struct extinct_introduction_InstanceScript : public InstanceScript
    {
        extinct_introduction_InstanceScript(Map* pMap) : InstanceScript(pMap) {}

        //called when someone loads a new instance
        void Load(const char* instance)
        {
            if (!instance)
            {
                //kick player from world (due to this being startlocation)
            }
            // guids
        }

        virtual void OnPlayerEnter(Player* player)
        {
            //gms should not get the event everytime they teleport here.
            if (player->isGameMaster())
                return;

            if (player->GetSession()->GetSecurity() > SEC_PLAYER)
            {
                //Player is NOT supposed to be here, probably cheater. (or unfortunate disconnect).
                //player->TeleportTo(mapid, x,y,z,orientation, options);
                sLog->outError("Player: %d. AccountID: %e. Entered introduction zone while they have already done the introduction!",player->GetSession()->GetPlayerName(),player->GetSession()->GetAccountId());
            }

            player->AddAura(AURA_COMATOSE, player);
            int event = GetCompletedEncounterMask(); // might need to get this in a different way cuz of instance resets, maybe a dirty achievement check?

            //In case someone logged out while doing the introduction, these are the checkpoints.
            switch (event)
            {
                case AWAKENING:
                    break;
                case INVASION:
                    break;
                case CRAWL:
                    break;
                case ROCKET:
                    break;
                case CAMP:
                    break;
                default:
                    break;
            }
        }

    InstanceScript* GetInstanceScript(InstanceMap *map) const
    {
       return new extinct_introduction_InstanceScript(map);
    }
    };
};

void AddSC_extinct_introduction()
{
    new extinct_introduction();
}