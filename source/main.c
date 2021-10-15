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
#include "all_gfx.h"
#include "global.h"
#include "rooms/room.h"

int main()
{
 	srand(time(NULL));

	game_state.current_room = ROOM_HOME;
	ROOMS previous_room = 0;

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
		
		room_update(&game_state);
	}
	while(game_state.current_room > 0);

	return 0;
}
