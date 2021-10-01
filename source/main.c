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
#include "home.h"
#include "room.h"

int main()
{
	u16 currentStage = 1;
	u16 result;

	srand(time(NULL));

	do
	{
		switch (currentStage)
		{
			case ST_MAIN_HOME:
				result = home_run();
				if (result == 1)
					currentStage = ST_MAIN_PLAYING;
			break;		
			case ST_MAIN_PLAYING:
				result = room_run();
				if (result == 1)
					currentStage = ST_MAIN_HOME;
			break;
			case ST_MAIN_GAMEOVER:
			break;		
			default:
				break;
		}
	}
	while(currentStage > 0);

	return 0;
}
