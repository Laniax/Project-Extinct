#include "ScriptPCH.h"
#include "Chat.h"
enum
{
    EVENT_TOKEN        = 32569,
    GM_ROBE            = 2586,
    GM_SLIPPERS        = 11508,
    GM_HOOD            = 12064,
};

class extinct_commandscript : public CommandScript
{
    public:
        extinct_commandscript() : CommandScript("extinct_commandscript") { }

        static bool HandleGiveTokenCommand(ChatHandler* handler, const char* args)
        {
            uint32 currenttokens;
            Player* target = handler->getSelectedPlayer();

            if (!*args)
            {
                currenttokens = target->GetItemCount(EVENT_TOKEN, true);
                handler->PSendSysMessage("Player %d has: %s", target->GetSession()->GetPlayerName(), currenttokens);
                return true;
            }

            char* ccount = strtok ((char*) args, " ");
            uint32 count = atoi (ccount);

            if (!target)
                target = handler->GetSession()->GetPlayer();

            if (count == 0)
                return false;

            //Subtract
            if (count < 0)
            {
                target->DestroyItemCount(EVENT_TOKEN, -count, true, false);
                handler->PSendSysMessage(LANG_REMOVEITEM, EVENT_TOKEN, -count, handler->GetNameLink(target).c_str());
                return true;
            }

            target->AddItem(EVENT_TOKEN, count);

            return true;
        }
        static bool HandleGiveOutfitCommand(ChatHandler* handler, const char* args)
         {
             Player* player = handler->GetSession()->GetPlayer();
             Player* target = handler->getSelectedPlayer();

             if (target->GetSession()->GetSecurity() == SEC_GAMEMASTER)
             {
                 player->AddItem(GM_ROBE,1);
                 player->AddItem(GM_SLIPPERS,1);
                 player->AddItem(GM_HOOD,1);
             }
             else
                 handler->PSendSysMessage("Player is not a GM thus cannot receive GM clothes.");
             return true;
         }

        ChatCommand* GetCommands() const
        {
            static ChatCommand ExtinctCommandTable[] =
            {
                { "givetoken",      SEC_GAMEMASTER,   true,   &HandleGiveTokenCommand,             "", NULL },
                { "gmoutfit",       SEC_GAMEMASTER,   true,   &HandleGiveOutfitCommand,            "", NULL },
                { NULL,             0,                  false,  NULL,                            "", NULL }
            };
            return ExtinctCommandTable;
        }
};

void AddSC_extinct_commandscript()
{
    new extinct_commandscript();
}
