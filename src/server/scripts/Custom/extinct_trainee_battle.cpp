
#include "ScriptPCH.h"
enum
{
	NPC_WARRIOR		=	500004,
	NPC_MAGE		=	500003,
	SPELL_FROSTBOLT =	59855
};

class mall_dummy_mage : public CreatureScript
{
    public:

        mall_dummy_mage()
            : CreatureScript("mall_dummy_mage")
        {
        }

        struct mall_dummy_mageAI : public ScriptedAI
        {
            mall_dummy_mageAI(Creature *c) : ScriptedAI(c) {}

            void UpdateAI(const uint32 uiDiff) //dit gebeurt elke map load, das ongeveer elke 50ms.
            {
				if (!me->getVictim())//geen target - aka out of combat
				{
				Unit* enemy_dummy = me->FindNearestCreature(NPC_WARRIOR, 15.0f);//Zoek warrior binnen 15f en noem deze enemy_dummy
				me->AI()->DoSpellAttackIfReady(SPELL_FROSTBOLT);
				me->AI()->AttackStart(enemy_dummy); //val enemy_dummy aan (om in combat te houden)
				}
				else
				{
				me->AI()->DoSpellAttackIfReady(SPELL_FROSTBOLT);
				}
			}
		};

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mall_dummy_mageAI(creature);
        }

};

class mall_dummy_warrior : public CreatureScript
{
    public:

        mall_dummy_warrior()
            : CreatureScript("mall_dummy_warrior")
        {
        }

        struct mall_dummy_warriorAI : public ScriptedAI
        {
            mall_dummy_warriorAI(Creature *c) : ScriptedAI(c) {}

            void UpdateAI(const uint32 uiDiff) //dit gebeurt elke map load, das ongeveer elke 50ms.
            {
				if (!me->getVictim())//geen target - aka out of combat
				{
				Unit* enemy_dummy = me->FindNearestCreature(NPC_MAGE, 15.0f);//Zoek target dummy binnen 15f en noem deze enemy_dummy
				me->AI()->DoMeleeAttackIfReady();
				me->AI()->AttackStart(enemy_dummy); //val enemy_dummy aan (om in combat te houden)
				}
				else
				{
				me->AI()->DoMeleeAttackIfReady();
				}
			}
		};

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mall_dummy_warriorAI(creature);
        }

};

void AddSC_mall_dummy_mage()
{
    new mall_dummy_mage();
	new mall_dummy_warrior();
}
