//
//! \file room_.c
//!   room_run module
//! \date 20210928
//! \author Hemerson F. Camargo
//
// === NOTES ===

#include <stdlib.h>
#include <tonc.h>
#include "room.h"
#include "../global.h"
#include "../nodes/node.h"
#include "../nodes/node_ball.h"
#include "../nodes/node_player.h"
#include "../nodes/node_room_home.h"
#include "../nodes/node_room_gameover.h"
#include "all_gfx.h"

#include "../nodes/node.h"
#include "../nodes/node_list.h"

void room_basic_create(GAME_STATE *game_state)
{	
	oam_init(obj_buffer, 128);

	REG_DISPCNT= DCNT_OBJ | DCNT_OBJ_1D | DCNT_MODE0 | DCNT_BG0;
	
	// Base TTE init for tilemaps
	tte_init_se(
		0,						// Background number (0-3)
		BG_CBB(0)|BG_SBB(31),	// BG control
		0,						// Tile offset (special cattr)
		CLR_RED,				// Ink color
		14,						// BitUnpack offset (on-pixel = 15)
		NULL,					// Default font (sys8) 
		NULL);					// Default renderer (se_drawg_s)
}

void room_home_create(GAME_STATE *game_state)
{
	room_basic_create(game_state);

	u16 charTilesIdx = 0;
	memcpy32(&tile_mem[4][charTilesIdx], charTiles, charTilesLen);
	memcpy32(pal_obj_mem, charPal, charPalLen);

	u16 ballTilesIdx = charTilesIdx+(charTilesLen/(8*8/2));
	memcpy32(&tile_mem[4][ballTilesIdx], ballTiles, ballTilesLen);
	memcpy32(pal_obj_mem, ballPal, ballPalLen);

	node_list_init(&game_state->node_list);
	node_ball_create(&game_state->node_list, ballTilesIdx);
	node_ball_create(&game_state->node_list, ballTilesIdx);
	node_ball_create(&game_state->node_list, ballTilesIdx);
	node_ball_create(&game_state->node_list, ballTilesIdx);
	node_ball_create(&game_state->node_list, ballTilesIdx);
	node_room_home_create(&game_state->node_list);
}

void room_gameover_create(GAME_STATE *game_state)
{
	room_basic_create(game_state);

	node_list_init(&game_state->node_list);
	node_room_gameover_create(&game_state->node_list);
}

void room_main_create(GAME_STATE *game_state)
{
	room_basic_create(game_state);

	u16 charTilesIdx = 0;
	memcpy32(&tile_mem[4][charTilesIdx], charTiles, charTilesLen);
	memcpy32(pal_obj_mem, charPal, charPalLen);

	u16 ballTilesIdx = charTilesIdx+(charTilesLen/(8*8/2));
	memcpy32(&tile_mem[4][ballTilesIdx], ballTiles, ballTilesLen);
	memcpy32(pal_obj_mem, ballPal, ballPalLen);

	node_list_init(&game_state->node_list);
	node_ball_create(&game_state->node_list, ballTilesIdx);
	node_ball_create(&game_state->node_list, ballTilesIdx);

	/* TODO: CHECK IF PLAYER IS COLLIDING WITH THIS BALLS BEFORE START */
	node_player_create(&game_state->node_list, 96, 32, charTilesIdx);
}

void room_finish(GAME_STATE *game_state)
{
	node_list_finish(&game_state->node_list);
}

void room_update(GAME_STATE *game_state)
{
	key_poll();

	node_list_update(&game_state->node_list);
	
	// start frame drawing
	vid_vsync();

	tte_erase_screen();
	node_list_draw(&game_state->node_list);
	
	oam_copy(oam_mem, obj_buffer, 3); // TODO: oam count deve ser calculado
}

void game_state_set_room(GAME_STATE *game_state, ROOMS room)
{
	game_state->current_room = room;
}