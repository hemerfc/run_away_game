//
//! \file room_.c
//!   room_run module
//! \date 20210928
//! \author Hemerson F. Camargo
//
// === NOTES ===

#include <tonc.h>
#include "room.h"
#include "../global.h"
#include "../nodes/node.h"
#include "../nodes/node_ball.h"
#include "../nodes/node_player.h"
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
		CLR_YELLOW,				// Ink color
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
	node_ball_create(&game_state->node_list, 10, 10, ballTilesIdx);
	node_ball_create(&game_state->node_list, 150, 100, ballTilesIdx);
	node_ball_create(&game_state->node_list, 1, 1, ballTilesIdx);
	node_ball_create(&game_state->node_list, 50, 200, ballTilesIdx);
	node_ball_create(&game_state->node_list, 200, 30, ballTilesIdx);
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
	node_player_create(&game_state->node_list, 96, 32, charTilesIdx);
	node_ball_create(&game_state->node_list, 10, 10, ballTilesIdx);
	node_ball_create(&game_state->node_list, 150, 100, ballTilesIdx);
}

void room_finish(GAME_STATE *game_state)
{
	node_list_finish(&game_state->node_list);
}

void room_update(GAME_STATE *game_state)
{
	u16 result = 0;
	
	while(result == 0)
	{
		key_poll();

		node_list_update(&game_state->node_list);
		
		// go to next stage
		if(key_hit(KEY_A))
			result = 1;

		// start frame drawing
		vid_vsync();

		//tte_erase_screen();
		//tte_set_pos(0, 0);
		//tte_write("stage01 screen!");

		node_list_draw(&game_state->node_list);
		
		oam_copy(oam_mem, obj_buffer, 3); // TODO: oam count deve ser calculado
	}

	room_finish(game_state);
}
