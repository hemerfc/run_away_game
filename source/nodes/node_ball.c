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

// functions
void ball_update_func(NODE *node) 
{
	//240 × 160
	if(node->pos_x + node->hitbox_offset_x + node->hitbox_w >= FRAME_WIDTH || node->pos_x + node->hitbox_offset_x <= 0)
		node->spd_x *= -1;
	if(node->pos_y + node->hitbox_offset_y + node->hitbox_h >= FRAME_HEIGHT || node->pos_y + node->hitbox_offset_y <= 0)
		node->spd_y *= -1; 

	// move left/right
	node->pos_x += node->spd_x;

	// move up/down
	node->pos_y += node->spd_y;
	
	obj_set_pos(node->obj, node->pos_x, node->pos_y);
}

// functions
void ball_draw_func(NODE *node) 
{
	obj_set_pos(node->obj, node->pos_x, node->pos_y);
}

u16 node_ball_create(NODE_LIST *node_list, u16 tile_idx) 
{
	u16 pos_x, pos_y;
	s16 spd_x, spd_y;

	/* generate a random position */
	pos_x = rand() % (FRAME_WIDTH - 32);
	pos_y = rand() % (FRAME_HEIGHT - 32);	
	
	/* generate a random direction speed */
	spd_x = (rand() & 1)?2:-2;
	spd_y = (rand() & 1)?2:-2;

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
	node->spd_x = spd_x;
	node->spd_y = spd_y;
	node->hitbox_w = 32;
	node->hitbox_h = 32;
	node->enabled = true;
	node->obj = &obj_buffer[idx];
	node->node_list = node_list;

	obj_set_attr(node->obj, 
		ATTR0_SQUARE,					// Square, regular sprite
		ATTR1_SIZE_32x32,					// 8x8px, 
		ATTR2_PALBANK(0) | tile_idx); 	// palbank 0, tile 0

	obj_set_pos(node->obj, node->pos_x, node->pos_y);

	node->update = &ball_update_func;
	node->draw = &ball_draw_func;

	return idx;
}
