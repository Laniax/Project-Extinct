#include "ScriptPCH.h"

/*
INFO:

This script features:

[AshenvaleMallScript]
- Give buffs to those who enter the zone when the opposing faction's boss is dead.
- Remove buffs to those who leave the zone.

[ashenvale_mall_horde_boss]
- Script for the Horde boss.
- Give Alliance buff upon death.
- Remove Alliance buff upon respawn.
- Fears the target every 15secs.
- Summons 3 hounds at 50% hp.
- Yells for help (zone-wide) at 30% hp.

[ashenvale_mall_alliance_boss]
- Script for the Alliance boss.
- Give Horde buff upon death.
- Remove Horde buff upon respawn.
- Fears the target every 15secs.
- Summons 3 hounds at 50% hp.
- Yells for help (zone-wide) at 30% hp.

[KNOWN BUGS]:
- UNTESTED!

[TO DO]:
- Test (:

*/
enum IDs
{
    ALLIANCE_BOSS_GUID        = 8919614,
    HORDE_BOSS_GUID            = 8918766,

    ZONE_ASHENVALE            = 331,
    BOSS_DEATH_BUFF            = 16609,
};

enum Texts
{
    TEXT_DEATH_HORDE        = 1000000, // Horde boss dies. (yell)
    TEXT_DYING_HORDE        = 1000001, // Horde boss at 30% hp, Yells for assist.
    TEXT_MINIONS_HORDE        = 1000002, // horde boss summons minions. (yell)

    TEXT_DEATH_ALLIANCE        = 1000005, // Alliance boss dies. (yell)
    TEXT_DYING_ALLIANCE        = 1000006, // Alliance boss at 30% hp, Yells for assist.
    TEXT_MINIONS_ALLIANCE    = 1000007, // Alliance boss summons minions. (yell)
};

enum Spells
{
    SPELL_FEAR                = 72321,
};

void RemoveBuffFromFaction(uint32 faction, Map* map)
{
    Map::PlayerList const &PlayerList = map->GetPlayers();
     if (!PlayerList.isEmpty())
            for (Map::PlayerList::const_iterator itr = PlayerList.begin(); itr != PlayerList.end(); ++itr)
               if (Player* plr = itr->getSource())
               {
                        switch(faction)
                        {
                            case TEAM_ALLIANCE:
                                if (plr->getFaction() == TEAM_ALLIANCE)
                                    plr->RemoveAura(BOSS_DEATH_BUFF);
                            break;
                            case TEAM_HORDE:
                                if (plr->getFaction() == TEAM_HORDE)
                                    plr->RemoveAura(BOSS_DEATH_BUFF);
                            break;
                        }
               }
}

void AddBuffToFaction(uint32 faction, Player* player)
{
    Map* map = player->GetMap();
    Map::PlayerList const &PlayerList = map->GetPlayers();
     if (!PlayerList.isEmpty())
            for (Map::PlayerList::const_iterator itr = PlayerList.begin(); itr != PlayerList.end(); ++itr)
               if (Player* plr = itr->getSource())
               {
                        switch(faction)
                        {
                            case TEAM_ALLIANCE:
                                if (plr->getFaction() == TEAM_ALLIANCE)
                                    plr->AddAura(BOSS_DEATH_BUFF, plr);
                            break;
                        case TEAM_HORDE:
                                if (plr->getFaction() == TEAM_HORDE)
                                    plr->AddAura(BOSS_DEATH_BUFF, plr);
                            break;
                        }
                }
}

class AshenvaleMallScript : public MapScript<Map>
{
    public:
        AshenvaleMallScript() : MapScript(1) { } //1 = kalimdor (mapid)

    void OnPlayerEnter(Map* map, Player* player)
    {
        if (!player)
            return;

        if (!player->GetZoneId() == ZONE_ASHENVALE)
            return;

        Unit* alliance_boss = map->GetCreature(ALLIANCE_BOSS_GUID);

        if (!alliance_boss)
            sLog->outArena("Could not get creature alliance_boss");

        if (alliance_boss->isDead() && player->getFaction() == TEAM_HORDE)
        {
            player->AddAura(BOSS_DEATH_BUFF, player);
        }

        Unit* horde_boss = map->GetCreature(HORDE_BOSS_GUID);

        if (!horde_boss)
            sLog->outArena("Could not get creature horde_boss");

        if (horde_boss->isDead() && player->getFaction() == TEAM_ALLIANCE)
        {
            player->AddAura(BOSS_DEATH_BUFF, player);
        }
    }

    void OnPlayerLeave(Map* map, Player* player)
    {
        if (!player)
            return;

        if (!player->GetZoneId() == ZONE_ASHENVALE)
            return;

        if (player->GetAura(BOSS_DEATH_BUFF))
            player->RemoveAura(BOSS_DEATH_BUFF);
    }
};

class ashenvale_mall_horde_boss : public CreatureScript
{
    public:

        ashenvale_mall_horde_boss() : CreatureScript("ashenvale_mall_horde_boss") { }

        struct ashenvale_mall_horde_bossAI : public ScriptedAI
        {
            ashenvale_mall_horde_bossAI(Creature *c) : ScriptedAI(c) {}

            uint32 TankFear_Timer;
            bool yelled, minions;

            void Reset()
            {
                TankFear_Timer = 15000; // 15 sec till first fear

                if (minions)
                    DespawnMinions();

                yelled = false;
                minions = false;

            }

            void JustDied(Unit* killer)
            {
                me->MonsterSay(TEXT_DEATH_HORDE,LANG_UNIVERSAL, killer->GetGUID());
                Map::PlayerList const &PlayerList = killer->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = PlayerList.begin(); itr != PlayerList.end(); ++itr)
                    {
                        if (Player* plr = itr->getSource())
                        {
                            if (plr->getFaction() == TEAM_ALLIANCE)
                            plr->AddAura(BOSS_DEATH_BUFF, plr);
                        }
                    }
                //hack to despawn
                //    DespawnMinions();
                //killer->AddAura(BOSS_DEATH_BUFF, killer);
                //AddBuffToFaction(TEAM_ALLIANCE, killer);
            }

            void JustRespawned()
            {
            //    RemoveBuffFromFaction(TEAM_HORDE, killer);
            }

            void SummonMinions(Unit* pVictim)
            {
                if (Creature *Hound = DoSpawnCreature(32163, float(irand(-9, 9)), float(irand(-9, 9)), 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000))
                    Hound->AI()->AttackStart(pVictim);
            }
            void DespawnMinions()
            {
                    Creature* Hound = me->FindNearestCreature(32163, 20.0f);
                    Hound->DespawnOrUnsummon();

                    Creature* SecondHound = me->FindNearestCreature(32163, 20.0f);
                    SecondHound->DespawnOrUnsummon();

                    Creature* ThirdHound = me->FindNearestCreature(32163, 20.0f);
                    ThirdHound->DespawnOrUnsummon();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim()) // no target
                    return;

                if (TankFear_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_FEAR);
                    TankFear_Timer = 15000;
                } else TankFear_Timer -= diff;

                if (me->HealthBelowPct(30))
                {
                    if (!yelled)
                    {
                        me->MonsterYellToZone(TEXT_DYING_HORDE, LANG_ORCISH, me->getVictim()->GetGUID());
                        yelled = true;
                    }
                }
                if (me->HealthBelowPct(50))
                {
                    if (!minions)
                    {
                        me->MonsterYell(TEXT_MINIONS_HORDE, LANG_ORCISH, me->getVictim()->GetGUID());
                        SummonMinions(me->getVictim());
                        SummonMinions(me->getVictim());
                        SummonMinions(me->getVictim());
                        minions = true;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new ashenvale_mall_horde_bossAI(creature);
        }
};

class ashenvale_mall_alliance_boss : public CreatureScript
{
    public:

        ashenvale_mall_alliance_boss() : CreatureScript("ashenvale_mall_alliance_boss") { }

        struct ashenvale_mall_alliance_bossAI : public ScriptedAI
        {
            ashenvale_mall_alliance_bossAI(Creature *c) : ScriptedAI(c) {}

            uint32 TankFear_Timer;
            bool yelled, minions;

            void Reset()
            {
                TankFear_Timer = 15000; // 15 sec till first fear
                yelled = false;
                minions = false;
            }

            void JustDied(Creature* /*killer*/)
            {
                DoScriptText(TEXT_DEATH_ALLIANCE, me);
//                AddBuffToFaction(TEAM_HORDE, me->GetMap());
            }

            void JustRespawned()
            {
                //RemoveBuffFromFaction(TEAM_HORDE, me->GetMap());
            }

            void SummonMinions(Unit* pVictim)
            {
                if (Creature *Hound = DoSpawnCreature(19207, float(irand(-9, 9)), float(irand(-9, 9)), 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000))
                    Hound->AI()->AttackStart(pVictim);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim()) // no target
                    return;

                if (TankFear_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_FEAR);
                    TankFear_Timer = 15000;
                } else TankFear_Timer -= diff;

                if (me->HealthBelowPct(30))
                {
                    if (yelled = false)
                    {
                        me->MonsterYellToZone(TEXT_DYING_ALLIANCE, LANG_COMMON, me->getVictim()->GetGUID());
                        yelled = true;
                    }
                }
                if (me->HealthBelowPct(50))
                {
                    if (minions = false)
                    {
                        me->MonsterYell(TEXT_MINIONS_ALLIANCE, LANG_COMMON, me->getVictim()->GetGUID());
                        SummonMinions(me->getVictim());
                        SummonMinions(me->getVictim());
                        SummonMinions(me->getVictim());
                        minions = true;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };


        CreatureAI* GetAI(Creature* creature) const
        {
            return new ashenvale_mall_alliance_bossAI(creature);
        }
};

void AddSC_Ashenvale_scripts()
{
    new AshenvaleMallScript();
    new ashenvale_mall_horde_boss();
    new ashenvale_mall_alliance_boss();
}