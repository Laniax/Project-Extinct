#define MAP_COMATOSE        726

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

class Extinct
{
    public:
       static bool HandleComatoseAreaTrigger(Player *player, uint32 Trigger);
       static bool GetIntroEvent(Player* player);
};
