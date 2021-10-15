//
//! \file home.h
//!   Home screen of the game
//! \date 20210928
//! \author Hemerson F. Camargo
//
// === NOTES ===

#ifndef ROOM_H
#define ROOM_H

#include <tonc.h>
#include "../nodes/node.h"
#include "../nodes/node_list.h"

typedef enum ROOMS
{
    ROOM_HOME = 1,
    ROOM_MAIN = 2,
    ROOM_GAMEOVER = 3
} ROOMS;

typedef struct game_state 
{    
    NODE_LIST node_list;
    ROOMS current_room; 
    u16 player_live_seconds;
    u16 player_tick_counter;
} GAME_STATE;

extern void room_home_create(GAME_STATE *game_state);
extern void room_main_create(GAME_STATE *game_state);
extern void room_gameover_create(GAME_STATE *game_state);

extern void room_update(GAME_STATE *game_state);
extern void room_finish(GAME_STATE *game_state);

extern void game_state_set_room(GAME_STATE *game_state, ROOMS room);

#endif // ROOM_H

