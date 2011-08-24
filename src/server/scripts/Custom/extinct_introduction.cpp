#include "ScriptPCH.h"
#include "extinct.h"

enum Spells
{
    AURA_COMATOSE = 1,
};

class extinct_introduction : public InstanceMapScript
{
public:
    extinct_introduction() : InstanceMapScript("extinct_introduction", MAP_COMATOSE) { }

    struct extinct_introduction_InstanceScript : public InstanceScript
    {
        extinct_introduction_InstanceScript(Map* pMap) : InstanceScript(pMap) {}

        //called when someone loads a new instance
        void Load(const char* instance)
        {
            if (!instance)
            {
                //player->SendTransferAborted(MAP_COMATOSE, TRANSFER_ABORT_NOT_FOUND);
                return;
            }
        }

        void OnPlayerEnter(Player* player)
        {
            //gms should not get the event everytime they teleport here.
            if (player->isGameMaster())
                return;

            if (player->GetSession()->GetSecurity() > SEC_PLAYER)
            {
                //Player is NOT supposed to be here, probably cheater. (or unfortunate disconnect).
                player->TeleportTo(mall_mapId, mall_positionX, mall_positionY, mall_positionZ, mall_orientation);
                sLog->outError("Player: %d. AccountID: %e. Entered introduction zone while they have already done the introduction!",player->GetSession()->GetPlayerName(),player->GetSession()->GetAccountId());
            }

            player->AddAura(AURA_COMATOSE, player);
            int event = Extinct::GetIntroEvent(player);

            //In case someone logged out while doing the introduction, these are the checkpoints.
            switch (event)
            {
                case AWAKENING:
                    // player->Relocate(float x, float y, float z, float o);
                    // StartEventAwakening(Player* player);
                    break;
                case INVASION:
                    // player->Relocate(float x, float y, float z, float o);
                    // StartEventInvasion(Player* player);
                    break;
                case CRAWL:
                    // player->Relocate(float x, float y, float z, float o);
                    // StartEventCrawl(Player* player);
                    break;
                case ROCKET:
                    // player->Relocate(float x, float y, float z, float o);
                    // StartEventRocket(Player* player);
                    break;
                case CAMP:
                    // player->Relocate(float x, float y, float z, float o);
                    // StartEventCamp(Player* player);
                    break;
                case MAX_EVENTS:
                    // Player has already done intro but was not flagged as done? Hacker?
                    WorldLocation mall_location;
                    mall_location.m_mapId       = mall_mapId;
                    mall_location.m_positionX   = mall_positionX;
                    mall_location.m_positionY   = mall_positionY;
                    mall_location.m_positionZ   = mall_positionZ;
                    mall_location.m_orientation = mall_orientation;
                    player->SetHomebind(mall_location, mall_area_id);
                    player->TeleportTo(mall_mapId, mall_positionX, mall_positionY, mall_positionZ, mall_orientation);
                    player->GetSession()->SetSecurity(ACC_INTRO_DONE);
                    break;
            }
        }

    InstanceScript* GetInstanceScript(InstanceMap *map) const
    {
       return new extinct_introduction_InstanceScript(map);
    }
    };
};

class achievement_awakening : public AchievementCriteriaScript
{
    public:
        achievement_awakening() : AchievementCriteriaScript("achievement_awakening") { }

        bool OnCheck(Player* source, Unit* /*target*/)
        {
            if (!source)
                return false;

            if (Extinct::GetIntroEvent(source) == AWAKENING)
                return true;

            return false;
        }
};

void AddSC_extinct_introduction()
{
    new extinct_introduction();
    new achievement_awakening();
}