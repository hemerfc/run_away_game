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
	node->hitbox_x = pos_x+8;
	node->hitbox_y = pos_y+8;
	node->hitbox_w = 32;
	node->hitbox_h = 32;
	node->enabled = true;
	node->obj = &obj_buffer[idx];

	obj_set_attr(node->obj, 
		ATTR0_SQUARE,					// Square, regular sprite
		ATTR1_SIZE_32x32,				// 32x32px, 
		ATTR2_PALBANK(0) | tile_idx); 	// palbank 0, tile 0

	obj_set_pos(node->obj, node->pos_x, node->pos_y);

	return idx;	
}

void node_player_update(NODE *node) 
{
	// move left/right
	node->pos_x += 2*key_tri_horz();
	// move up/down
	node->pos_y += 2*key_tri_vert();
}

void node_player_draw(NODE *node) 
{
	obj_set_pos(node->obj, node->pos_x, node->pos_y);
}
