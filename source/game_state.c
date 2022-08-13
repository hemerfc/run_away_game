//
//! \file game_state.h
//!   Game State module
//! \date 20220729
//! \author Hemerson F. Camargo
//
// === NOTES ===

#include <tonc.h>
#include "game_state.h"

GAME_STATE game_state;

void game_state_init()
{
	game_state.current_stage = STAGE_TITLE;
	game_state.previous_stage = 0;
}

void game_state_update()
{
	if (game_state.current_stage != game_state.previous_stage)
	{
		switch (game_state.current_stage)
		{
			case STAGE_INTRO:
				//room_home_create(&game_state);
				break;
			case STAGE_TITLE:
				//room_main_create(&game_state);
				break;
			case STAGE_MAIN:
				//room_gameover_create(&game_state);
				break;
			case STAGE_GAMEOVER:
				//room_gameover_create(&game_state);
				break;
		}
		game_state.previous_stage = game_state.current_stage;
	}
}


void game_state_draw()
{
		switch (game_state.current_stage)
		{
			case STAGE_INTRO:
				//room_home_create(&game_state);
				break;
			case STAGE_TITLE:
				//room_main_create(&game_state);
				break;
			case STAGE_MAIN:
				//room_gameover_create(&game_state);
				break;
			case STAGE_GAMEOVER:
				//room_gameover_create(&game_state);
				break;
		}
}

bool game_state_is_gameover()
{
	return false;
}

void game_state_set_stage(STAGE stage)
{
	game_state.current_stage = stage;
}