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
    ROOM_HOME,
    ROOM_MAIN
} ROOMS;

typedef struct game_state 
{    
    NODE_LIST node_list;
    ROOMS current_room; 
} GAME_STATE;

extern void room_home_create(GAME_STATE *game_state);
extern void room_main_create(GAME_STATE *game_state);

extern void room_update(GAME_STATE *game_state);

extern void game_state_set_room();

#endif // ROOM_H
