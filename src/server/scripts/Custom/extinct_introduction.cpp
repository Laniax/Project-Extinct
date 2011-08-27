#include "ScriptPCH.h"
#include "extinct.h"

enum Spells
{
    AURA_COMATOSE = 1,
};

enum EventStartPositions
{
    //Awakening
    AWAKE_X = 1,
    AWAKE_Y = 1,
    AWAKE_Z = 1,
    AWAKE_O = 1,
    //Invasion
    INVA_X = 1,
    INVA_Y = 1,
    INVA_Z = 1,
    INVA_O = 1,
    //Crawl
    CRAWL_X = 1,
    CRAWL_Y = 1,
    CRAWL_Z = 1,
    CRAWL_O = 1,
    //Rocket
    ROCK_X = 1,
    ROCK_Y = 1,
    ROCK_Z = 1,
    ROCK_O = 1,
    //Camp
    CAMP_X = 1,
    CAMP_Y = 1,
    CAMP_Z = 1,
    CAMP_O = 1,
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
                     player->Relocate(AWAKE_X, AWAKE_Y, AWAKE_Z, AWAKE_O);
                     StartEventAwakening(player);
                    break;
                case INVASION:
                     player->Relocate(INVA_X, INVA_Y, INVA_Z, INVA_O);
                     StartEventInvasion(player);
                    break;
                case CRAWL:
                     player->Relocate(CRAWL_X, CRAWL_Y, CRAWL_Z, CRAWL_O);
                     StartEventCrawl(player);
                    break;
                case ROCKET:
                     player->Relocate(ROCK_X, ROCK_Y, ROCK_Z, ROCK_O);
                     StartEventRocket(player);
                    break;
                case CAMP:
                     player->Relocate(CAMP_X, CAMP_Y, CAMP_Z, CAMP_O);
                     StartEventCamp(player);
                    break;
                case MAX_EVENTS:
                    // Player has already done intro but was not flagged as done? Hacker/Disconnect?
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

        static void StartEventAwakening(Player* player)
        {
            sLog->outError("Player: %d. Triggered: Event Awakening!",player->GetSession()->GetPlayerName());
        }
        static void StartEventInvasion(Player* player)
        {
            sLog->outError("Player: %d. Triggered: Event Invasion!",player->GetSession()->GetPlayerName());
        }
        static void StartEventCrawl(Player* player)
        {
            sLog->outError("Player: %d. Triggered: Event Crawl!",player->GetSession()->GetPlayerName());
        }
        static void StartEventRocket(Player* player)
        {
            sLog->outError("Player: %d. Triggered: Event Rocket!",player->GetSession()->GetPlayerName());
        }
        static void StartEventCamp(Player* player)
        {
            sLog->outError("Player: %d. Triggered: Event Camp!",player->GetSession()->GetPlayerName());
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

class achievement_invasion : public AchievementCriteriaScript
{
    public:
        achievement_invasion() : AchievementCriteriaScript("achievement_invasion") { }

        bool OnCheck(Player* source, Unit* /*target*/)
        {
            if (!source)
                return false;

            if (Extinct::GetIntroEvent(source) == INVASION)
                return true;

            return false;
        }
};

class achievement_crawl : public AchievementCriteriaScript
{
    public:
        achievement_crawl() : AchievementCriteriaScript("achievement_crawl") { }

        bool OnCheck(Player* source, Unit* /*target*/)
        {
            if (!source)
                return false;

            if (Extinct::GetIntroEvent(source) == CRAWL)
                return true;

            return false;
        }
};

class achievement_rocket : public AchievementCriteriaScript
{
    public:
        achievement_rocket() : AchievementCriteriaScript("achievement_rocket") { }

        bool OnCheck(Player* source, Unit* /*target*/)
        {
            if (!source)
                return false;

            if (Extinct::GetIntroEvent(source) == ROCKET)
                return true;

            return false;
        }
};

class achievement_camp : public AchievementCriteriaScript
{
    public:
        achievement_camp() : AchievementCriteriaScript("achievement_camp") { }

        bool OnCheck(Player* source, Unit* /*target*/)
        {
            if (!source)
                return false;

            if (Extinct::GetIntroEvent(source) == CAMP)
                return true;

            return false;
        }
};

void AddSC_extinct_introduction()
{
    new extinct_introduction();
    new achievement_awakening();
    new achievement_invasion();
    new achievement_crawl();
    new achievement_rocket();
    new achievement_camp();
}