//
//! \file game_state.h
//!   Game State module
//! \date 20220729
//! \author Hemerson F. Camargo
//
// === NOTES ===

#pragma once

#include <tonc.h>
#include "tonc.h"

typedef enum stage
{
    STAGE_INTRO = 1,
    STAGE_TITLE = 2,
    STAGE_MAIN = 3,
    STAGE_GAMEOVER = 4
} STAGE;

typedef struct game_state 
{
    STAGE current_stage;
	STAGE previous_stage;
} GAME_STATE;

extern void game_state_init();
extern void game_state_update();
extern void game_state_draw();

extern bool game_state_is_gameover();
extern void game_state_set_stage(STAGE stage);