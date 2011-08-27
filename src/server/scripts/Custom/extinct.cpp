#include "extinct_introduction.cpp"
#include "ScriptPCH.h"
//#include "extinct.h"

// Called when an areatrigger inside the Comatose map is triggered.
bool Extinct::HandleComatoseAreaTrigger(Player *player, uint32 Trigger)
{
    uint32 plGUID = player->GetGUID();
    switch (Trigger)
    {
        //Awakening is triggered in the OnPlayerEnter function.
        case 1: // Awakening Done
            extinct_introduction::extinct_introduction_InstanceScript::StartEventInvasion(player);
            player->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_INTRO_AWAKE);
            CharacterDatabase.PQuery("UPDATE `extinct_introduction` SET `event` = '1' WHERE guid = '%d'", plGUID);
            return true; break;
        case 2: // Invasion Done
            extinct_introduction::extinct_introduction_InstanceScript::StartEventCrawl(player);
            player->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_INTRO_SURVIVE_INVASION);
            CharacterDatabase.PQuery("UPDATE `extinct_introduction` SET `event` = '2' WHERE guid = '%d'", plGUID);
            return true; break;
        case 3: // Crawl Done
            extinct_introduction::extinct_introduction_InstanceScript::StartEventRocket(player);
            player->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_INTRO_CRAWL_TO_FREEDOM);
            CharacterDatabase.PQuery("UPDATE `extinct_introduction` SET `event` = '3' WHERE guid = '%d'", plGUID);
            return true; break;
        case 4: // Rocket Done
            extinct_introduction::extinct_introduction_InstanceScript::StartEventCamp(player);
            player->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_INTRO_ROCKET_RIDE);
            CharacterDatabase.PQuery("UPDATE `extinct_introduction` SET `event` = '4' WHERE guid = '%d'", plGUID);
            return true; break;
        case 5: // Camp Done
            player->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_INTRO_REACH_CAMP);
            CharacterDatabase.PQuery("UPDATE `extinct_introduction` SET `event` = '5' WHERE guid = '%d'", plGUID);
            player->GetSession()->SetSecurity(ACC_INTRO_DONE);
            return true; break;
    }
    return false;
}

// Retrieves the introduction event the player is last saved on.
bool Extinct::GetIntroEvent(Player* player)
{
    uint32 plGUID = player->GetGUID();
    QueryResult result = CharacterDatabase.PQuery("SELECT `event` FROM `extinct_introduction` WHERE guid = '%d' LIMIT 1", plGUID); // table to be made.

    if (result)
    {
        Field* fields = result->Fetch();
        uint32 event  = fields[0].GetUInt32();
        return event;
    }
    else
    {
        CharacterDatabase.PQuery("INSERT INTO `extinct_introduction` (`guid`, `event`) VALUES ('%f', 0);", plGUID); // table to be made
        return 0;
    }
    return false;
}