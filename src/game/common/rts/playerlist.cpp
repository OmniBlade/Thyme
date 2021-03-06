/**
 * @file
 *
 * @author OmniBlade
 *
 * @brief Contains a list of players in the game.
 *
 * @copyright Thyme is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */
#include "playerlist.h"

#ifndef THYME_STANDALONE
PlayerList *&g_thePlayerList = Make_Global<PlayerList *>(0x00A2B688);
#else
PlayerList *g_thePlayerList = nullptr;
#endif
