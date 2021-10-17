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
#include "rooms/room.h"

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

	game_state.current_room = ROOM_HOME;
	ROOMS previous_room = 0;

	mmStart( SFX_SND0, MM_PLAY_LOOP );

	do
	{
		if(previous_room != game_state.current_room)
		{
			room_finish(&game_state);

			switch (game_state.current_room)
			{
				case ROOM_HOME: 
					room_home_create(&game_state);
				break;		
				case ROOM_MAIN:
					room_main_create(&game_state);
				break;
				case ROOM_GAMEOVER:
					room_gameover_create(&game_state);
				break;
			}
			previous_room = game_state.current_room;
		}

		/* process game logic */
		room_update(&game_state);
		
		/* update maxmod audio */
		mmFrame();
		
		/* wait for new frame (SWI 5) */		
		VBlankIntrWait();
	}
	while(game_state.current_room > 0);

	return 0;
}
