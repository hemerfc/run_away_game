//
//! \file player.h
//!   Player module
//! \date 20220729
//! \author Hemerson F. Camargo
//
// === NOTES ===

#pragma once

#include <tonc.h>
#include "global.h"
#include "sprite.h"
#include "body.h"

typedef struct player {
	BODY body;
	u8 obj_buffer_idx;
    u16 live_seconds;
    u16 tick_counter; 
	char str_score[20];
} PLAYER;

extern void player_init(u16 pos_x, u16 pos_y);
extern void player_update();
extern void player_draw();
