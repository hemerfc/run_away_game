//
//! \file node_ball.c
//!   ball module
//! \date 20211003
//! \author Hemerson F. Camargo
//
// === NOTES ===

#include <stdlib.h>
#include <tonc.h>
#include "../global.h"
#include "node.h"
#include "node_list.h"
#include "node_player.h"

u16 node_player_create(NODE_LIST *node_list, u16 pos_x, u16 pos_y, u16 tile_idx) 
{	
	u16 idx = node_list_get_empty(node_list);

	// if don`t have any node avaiable
	if(idx == -1)
		return idx;

	NODE *node = &node_list->nodes[idx];

	node->id = idx;
	node->type = NTYPE_PLAYER;
	node->collidable = true;
	node->pos_x = pos_x;
	node->pos_y = pos_y;
	node->spd_x = 0;
	node->spd_y = 0;
	node->hitbox_w = 32;
	node->hitbox_h = 40;// compensa o tamanho do sprite
	node->enabled = true;
	node->obj = &obj_buffer[idx];

	obj_set_attr(node->obj, 
		ATTR0_SQUARE,					// Square, regular sprite
		ATTR1_SIZE_32x32,				// 32x32px, 
		ATTR2_PALBANK(0) | tile_idx); 	// palbank 0, tile 0

	obj_set_pos(node->obj, node->pos_x, node->pos_y);

	return idx;	
}

void node_player_update(NODE_LIST *node_list, NODE *node) 
{
	u16 dist = 0;
	char str_dist[20];

	// move left/right
	node->pos_x += 2*key_tri_horz();
	// move up/down
	node->pos_y += 2*key_tri_vert();	
	

	// iterate all nodes
	for (u16 i = 0; i < NODE_LIST_LEN; i++)
	{
		if (i == node->id)
			continue;
	
		NODE *node_i = &node_list->nodes[i];
		if(node_i->type == NTYPE_BALL)
		{
			// calc the centers
			u16 node_x = node->pos_x + (node->hitbox_w/2);
			u16 node_y = node->pos_y + (node->hitbox_h/2);

			u16 node_i_x = node_i->pos_x + (node_i->hitbox_w/2);
			u16 node_i_y = node_i->pos_y + (node_i->hitbox_h/2);

			u16 cat_a = abs(node_x - node_i_x);
			u16 cat_b = abs(node_y - node_i_y);

			dist = Sqrt((cat_a * cat_a) + (cat_b * cat_b));

			if(dist <= 23)
			{
				game_state_set_room(&game_state, ROOM_HOME);
			} 
		}
	}

	
	itoa(dist, str_dist, 10);
	tte_set_pos(0, 5);
	tte_write(str_dist); 

	// go to next stage
	if(key_hit(KEY_START))
	{
		game_state_set_room(&game_state, ROOM_HOME);
	}
}

void node_player_draw(NODE *node) 
{
	obj_set_pos(node->obj, node->pos_x, node->pos_y);
}
