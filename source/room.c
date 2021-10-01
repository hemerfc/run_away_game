//
//! \file room_.c
//!   room_run module
//! \date 20210928
//! \author Hemerson F. Camargo
//
// === NOTES ===

#include <tonc.h>
#include "room.h"
#include "global.h"
#include "node.h"
#include "all_gfx.h"

NODE_BUFFER nodes;

void room_init()
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

	u16 charTilesIdx = 0;
	memcpy32(&tile_mem[4][charTilesIdx], charTiles, charTilesLen);
	memcpy32(pal_obj_mem, charPal, charPalLen);

	u16 ballTilesIdx = charTilesIdx+(charTilesLen/(8*8/2));
	memcpy32(&tile_mem[4][ballTilesIdx], ballTiles, ballTilesLen);
	memcpy32(pal_obj_mem, ballPal, ballPalLen);

	node_buffer_init(&nodes);
	node_player_create(&nodes, 96, 32, charTilesIdx);
	node_ball_create(&nodes, 10, 10, ballTilesIdx);
	node_ball_create(&nodes, 150, 100, ballTilesIdx);
}

void room_finish()
{
	node_buffer_finish(&nodes);
}

u16 room_run()
{
	u16 result = 0;

	room_init();
	
	while(result == 0)
	{
		key_poll();

		node_buffer_update(&nodes);
		
		// go to next stage
		if(key_hit(KEY_A))
			result = 1;

		// start frame drawing
		vid_vsync();

		tte_erase_screen();
		tte_set_pos(0, 0);
		tte_write("stage01 screen!");

		oam_copy(oam_mem, obj_buffer, 3); // TODO: oam count deve ser calculado
	}

	room_finish();

	return result;
}