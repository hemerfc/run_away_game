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
#include "node_ball.h"

u16 node_ball_create(NODE_LIST *node_list, u16 pos_x, u16 pos_y, u16 tile_idx) 
{
	u16 idx = node_list_get_empty(node_list);

	// if don`t have any node avaiable
	if(idx == -1)
		return idx;

	NODE *node = &node_list->nodes[idx];

	node->id = idx;
	node->type = NTYPE_BALL;
	node->collidable = true;
	node->pos_x = pos_x;
	node->pos_y = pos_y;
	node->spd_x = 2;
	node->spd_y = 2;
	node->hitbox_x = pos_x;
	node->hitbox_y = pos_y;
	node->hitbox_w = 32;
	node->hitbox_h = 32;
	node->enabled = true;
	node->obj = &obj_buffer[idx];
	
	obj_set_attr(node->obj, 
		ATTR0_SQUARE,					// Square, regular sprite
		ATTR1_SIZE_32x32,					// 8x8px, 
		ATTR2_PALBANK(0) | tile_idx); 	// palbank 0, tile 0

	obj_set_pos(node->obj, node->pos_x, node->pos_y);

	return idx;
}

void node_ball_update(NODE *node) 
{
	//240 × 160
	if(node->pos_x + node->hitbox_w >= 240 || node->pos_x <= 0)
		node->spd_x *= -1; 
	if(node->pos_y + node->hitbox_h >= 160 || node->pos_y <= 0)
		node->spd_y *= -1; 

	// move left/right
	node->pos_x += node->spd_x;

	// move up/down
	node->pos_y += node->spd_y;
	
	obj_set_pos(node->obj, node->pos_x, node->pos_y);
}

void node_ball_draw(NODE *node) 
{	
	obj_set_pos(node->obj, node->pos_x, node->pos_y);
}
