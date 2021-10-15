//
//! \file node_ball.c
//!   ball module
//! \date 20211003
//! \author Hemerson F. Camargo
//
// === NOTES ===

#include <stdlib.h>
#include <tonc.h>
#include "node.h"
#include "node_list.h"
#include "node_room_gameover.h"

void room_gameover_update_func(NODE *node) 
{
	// go to next stage
	if(key_hit(KEY_A))
	{
		game_state_set_room(&game_state, ROOM_MAIN);
	}
}

void room_gameover_draw_func(NODE *node) 
{
	char str_seconds[20];

	tte_set_pos(80, 70);
	tte_write("GAME OVER!");
	
	itoa(game_state.player_live_seconds,str_seconds,10);	
	tte_set_pos(120, 80);
	tte_write(str_seconds);
}

u16 node_room_gameover_create(NODE_LIST *node_list) 
{
	u16 idx = node_list_get_empty(node_list);

	// if don`t have any node avaiable
	if(idx == -1)
		return idx;

	NODE *node = &node_list->nodes[idx];

	node->id = idx;
	node->type = NTYPE_ROOM_GAMEOVER;
	node->enabled = true;
	node->node_list = node_list;

	node->update = &room_gameover_update_func;
	node->draw = &room_gameover_draw_func;

	return idx;
}
