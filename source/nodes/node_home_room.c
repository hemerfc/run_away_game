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
#include "node_home_room.h"

u16 node_home_room_create(NODE_LIST *node_list) 
{
	u16 idx = node_list_get_empty(node_list);

	// if don`t have any node avaiable
	if(idx == -1)
		return idx;

	NODE *node = &node_list->nodes[idx];

	node->id = idx;
	node->type = NTYPE_HOME_ROOM;
	node->enabled = true;
	
	return idx;
}

void node_home_room_update(NODE_LIST *node_list, NODE *node) 
{
	// go to next stage
	if(key_hit(KEY_A))
	{
		game_state_set_room(&game_state, ROOM_MAIN);
	}
}

void node_home_room_draw(NODE *node) 
{		
	tte_set_pos(0, 0);
	tte_write("Home screen!");
}
