#define MAP_COMATOSE        725

enum Mall_Position
{
     mall_mapId       = 1,
     mall_positionX   = 1,
     mall_positionY   = 1,
     mall_positionZ   = 1,
     mall_orientation = 1,
     mall_area_id     = 1,
};

enum IntroEvents
{
    AWAKENING,
    INVASION,
    CRAWL,
    ROCKET,
    CAMP,
    MAX_EVENTS,
};

AchievementEntry const* DEEP_SLUMBER = GetAchievementStore()->LookupEntry(5001);
AchievementEntry const* STILL_KICKIN = GetAchievementStore()->LookupEntry(5002);
AchievementEntry const* TO_INFINITY_AND_BEYOND = GetAchievementStore()->LookupEntry(5003);
AchievementEntry const* LIKE_A_BAD_BOND_MOVIE = GetAchievementStore()->LookupEntry(5004);

class Extinct
{
    public:
       static bool HandleComatoseAreaTrigger(Player *player, uint32 Trigger);
       static bool GetIntroEvent(Player* player);
};
