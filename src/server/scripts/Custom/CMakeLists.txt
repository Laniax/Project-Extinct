# Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  Custom/extinct.h
  Custom/extinct.cpp
  Custom/extinct_loginscript.cpp
  Custom/extinct_map_ashenvale.cpp
  Custom/extinct_pet_cages.cpp
  Custom/extinct_profession_o_matic.cpp
  Custom/extinct_mall_npcs.cpp
  Custom/extinct_restrictions.cpp
  Custom/extinct_introduction.cpp
  Custom/extinct_commandscript.cpp
)

message("  -> Prepared: Custom")
