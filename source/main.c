//
//! \file main.c
//!   Entry point of game
//! \date 20210927
//! \author Hemerson F. Camargo
//
// === NOTES ===

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <tonc.h>
#include <maxmod.h>
#include "all_gfx.h"
#include "soundbank_bin.h"
#include "soundbank.h"
#include "global.h"
#include "player.h"
#include "game_state.h"
#include "sprite.h"
#include "tileset.h"

int main()
{
 	srand(time(NULL));
    
	/* enable vblank irq */
	irq_init(NULL);
	irq_add(II_VBLANK, NULL);

	/* initialise maxmod with soundbank and 8 channels */
    mmInitDefault((mm_addr)soundbank_bin, 8);
    mmSetModuleVolume(1024);
    mmSetJingleVolume(1024);

	mmStart( SFX_SND0, MM_PLAY_LOOP );

	// --- Init window ---
	REG_WIN0H= 0;
	REG_WIN0V= SCREEN_HEIGHT;  

	// DCNT_OBJ    - ENABLE SPRITE MODE
	// DCNT_OBJ_1D - SPRITES ARE SET TO 1D MEMORY 
	// DCNT_MODE0  - TILEMOD 0, HAVE 4 BACKGROUND WITHOUT ROTATION
	// DCNT_BGx    - ENABLE BACKGROUND 1 TO 4
	REG_DISPCNT= DCNT_OBJ | DCNT_OBJ_1D | DCNT_MODE0 | DCNT_BG0 | DCNT_BG1;// | DCNT_WIN0; // | DCNT_BG2 | DCNT_BG3;// | DCNT_WIN0;
	//REG_WININ= WIN_BUILD(WIN_BG0|WIN_BG2, 0);
	//REG_WINOUT= WIN_BUILD(WIN_BG0|WIN_BG1, 0);

	// prepare sprites
	sprite_init();
	
	tileset_init();

	//game_state_init();
	player_init(100, 100);

	// --- Enable stuff ---
	// REG_WININ= WIN_BUILD(WIN_BG0|WIN_BG2, 0);
	// REG_WINOUT= WIN_BUILD(WIN_BG0|WIN_BG1, 0);

	do
	{
		/* update the keys */
		key_poll();
		/* update maxmod audio */
		mmFrame();		
		/* wait for new frame (SWI 5) */		
		VBlankIntrWait();
		// clear screen
		tte_erase_screen();
		
		// process game logic 
		game_state_update();
		player_update();
		
		// draw frame
		//game_state_draw();
		player_draw();

		sprite_draw_all();
	}
	while(!game_state_is_gameover());

	return 0;
}
