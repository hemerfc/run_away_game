//
//! \file home.c
//!   Home screen of the game
//! \date 20210928
//! \author Hemerson F. Camargo
//
// === NOTES ===

#include "home.h"
#include "global.h"

void home_init()
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

void home_finish()
{
}

u16 home_run()
{
	u16 result = 0;

	home_init();

	while(result == 0)
	{
		vid_vsync();
		key_poll();

		tte_erase_screen();
		
		tte_set_pos(0, 0);
		tte_write("Home screen!");

		// go to next stage
		if(key_hit(KEY_A))
			result = 1;
	}

	home_finish();

	return result;
}