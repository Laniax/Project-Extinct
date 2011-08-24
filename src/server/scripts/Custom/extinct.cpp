
#include "ScriptPCH.h"
#include "extinct.h"

// Called when an areatrigger inside the Comatose map is triggered.
bool Extinct::HandleComatoseAreaTrigger(Player *player, uint32 Trigger)
{
    uint32 plGUID = player->GetGUID();
    switch (Trigger)
    {
        case 1: // Awakening Done
            //extinct_introduction::StartEventInvasion(player);
            player->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_INTRO_AWAKE);
            WorldDatabase.PQuery("UPDATE `table` SET `event` = '1' WHERE accountid = '%d'", plGUID); // table to be made.
            return true; break;
        case 2: // Invasion Done
            //extinct_introduction::StartEventCrawl(player);
            player->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_INTRO_SURVIVE_INVASION);
            WorldDatabase.PQuery("UPDATE `table` SET `event` = '2' WHERE accountid = '%d'", plGUID); // table to be made.
            return true; break;
        case 3: // Crawl Done
            //extinct_introduction::StartEventRocket(player);
            player->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_INTRO_CRAWL_TO_FREEDOM);
            WorldDatabase.PQuery("UPDATE `table` SET `event` = '2' WHERE accountid = '%d'", plGUID); // table to be made.
            return true; break;
        case 4: // Rocket Done
            //extinct_introduction::StartEventCamp(player);
            player->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_INTRO_ROCKET_RIDE);
            WorldDatabase.PQuery("UPDATE `table` SET `event` = '3' WHERE accountid = '%d'", plGUID); // table to be made.
            return true; break;
        case 5: // Camp Done
            player->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_INTRO_REACH_CAMP);
            WorldDatabase.PQuery("UPDATE `table` SET `event` = '4' WHERE accountid = '%d'", plGUID); // table to be made.
            player->GetSession()->SetSecurity(ACC_INTRO_DONE);
            return true; break;
    }
    return false;
}

// Retrieves the introduction event the player is last saved on.
bool Extinct::GetIntroEvent(Player* player)
{
    uint32 plGUID = player->GetGUID();
    QueryResult result = WorldDatabase.PQuery("SELECT event FROM table WHERE accountid = '%d' LIMIT 1", plGUID); // table to be made.

    if (result)
    {
        Field* fields = result->Fetch();
        uint32 event  = fields[0].GetUInt32();

        if (event)
            return event;
    }
    return false;
}