#include "ScriptPCH.h"
#include "extinct.h"

enum Spells
{
    AURA_COMATOSE            = 1, //TBM (to be made)
    SPELL_SLEEP              = 52742,
    SPELL_CAMERA_SHAKE       = 44681,
};

const Position EventStartPositions[5] =
{
    //Awakening
    {6195.070801f, 6318.850586f, 9.848952f, 4.885195f},
    //Invasion
    {1f, 0f, 0f, 0f},
    //Crawl
    {1f, 0f, 0f, 0f},
    //Rocket
    {1f, 1f, 1f, 1f},
    //Camp
    {1f, 1f, 1f, 1f},
};

Position const AwakeningAreaTrigger = {6195.070801f, 6318.850586f, 9.848952f, 4.885195f}; //fake coords, trigger TBM (to be made)

class StandUpEvent : public BasicEvent
{
    public:
        StandUpEvent(Player* player) : BasicEvent(), _player(player) { }

        bool Execute(uint64 /*eventTime*/, uint32 /*diff*/)
        {
            //trigger custom animation: SLEEP_UP + Hard walk slowly tweening into crawling.
            _player->GetMotionMaster()->MovePoint(0, AwakeningAreaTrigger); //then trigger a walk to the areatrigger.
            _player->CastSpell(_player, SPELL_CAMERA_SHAKE,1);

            //areatrigger will take it from there ;)
            return true;
        }

    private:
        Player* _player;
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
                return;
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
                     player->Relocate(EventStartPositions[0]);
                     StartEventAwakening(player);
                    break;
                case INVASION:
                     player->Relocate(EventStartPositions[1]);
                     StartEventInvasion(player);
                    break;
                case CRAWL:
                     player->Relocate(EventStartPositions[2]);
                     StartEventCrawl(player);
                    break;
                case ROCKET:
                     player->Relocate(EventStartPositions[3]);
                     StartEventRocket(player);
                    break;
                case CAMP:
                     player->Relocate(EventStartPositions[4]);
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

            player->SetClientControl(player, 0);   //player will not be able to move - script generated movement instead.
            player->CastSpell(player, SPELL_SLEEP, 1);
            player->Say("What.. whe.. where am I?", LANG_UNIVERSAL);
            player->m_Events.AddEvent(new StandUpEvent(*player), player->m_Events.CalculateTime(2000)); // 2 sec
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

void AddSC_extinct_introduction()
{
    new extinct_introduction();
}