//
//! \file node.c
//!   player screen of the game
//! \date 20210928
//! \author Hemerson F. Camargo
//
// === NOTES ===

#include <stdlib.h>
#include <tonc.h>
#include "node.h"
#include "node_ball.h"
#include "node_player.h"
#include "node_home_room.h"

void node_list_init(NODE_LIST *node_list)
{
	for (u16 i = 0; i < NODE_LIST_LEN; i++)
	{
		NODE *node = &node_list->nodes[i];
		node->id = 0;
		node->type = NTYPE_DELETE;
	}
}

void node_list_finish(NODE_LIST *node_list)
{
}

void node_list_update(NODE_LIST *node_list)
{
	for (u16 i = 0; i < NODE_LIST_LEN; i++)
	{	
		NODE *node = &node_list->nodes[i];

		if(node->enabled)
		{
			switch (node->type)
			{
			case NTYPE_BALL:
				node_ball_update(node_list, node);
				break;
			case NTYPE_PLAYER:
				node_player_update(node_list, node);
				break;	
			case NTYPE_HOME_ROOM:
				node_home_room_update(node_list, node);
				break;			
			}
		}
	}
}

void node_list_draw(NODE_LIST *node_list)
{
	for (u16 i = 0; i < NODE_LIST_LEN; i++)
	{	
		NODE *node = &node_list->nodes[i];

		if(node->enabled)
		{
			switch (node->type)
			{
			case NTYPE_BALL:
				node_ball_draw(node);
				break;
			case NTYPE_PLAYER:
				node_player_draw(node);
				break;			
			case NTYPE_HOME_ROOM:
				node_home_room_draw(node);
				break;
			}
		}
	}
}

/// return the first avaiable node
u16 node_list_get_empty(NODE_LIST *node_list)
{	
	NODE *node;
	u16 type;
	
	for (u16 i = 0; i < NODE_LIST_LEN; i++)
	{
		node = &node_list->nodes[i];
		type = node->type;
		if(type == NTYPE_DELETE)
			return i;
	}
	return -1; 
}
