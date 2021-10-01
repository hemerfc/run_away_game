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

void node_buffer_init(NODE_BUFFER *node_buffer)
{
	for (u16 i = 0; i < NODE_BUFFER_LEN; i++)
	{
		NODE *node = &node_buffer->nodes[i];
		node->id = 0;
		node->type = NTYPE_DELETE;
	}
}

void node_buffer_finish(NODE_BUFFER *node_buffer)
{
}

void node_buffer_update(NODE_BUFFER *node_buffer)
{
	for (u16 i = 0; i < NODE_BUFFER_LEN; i++)
	{	
		NODE *node = &node_buffer->nodes[i];

		if(node->enabled)
		{
			switch (node->type)
			{
			case NTYPE_BALL:
				node_ball_update(node);
				break;
			case NTYPE_PLAYER:
				node_player_update(node);
				break;			
			}
		}
	}
}
/// return the first avaiable node
u16 node_buffer_get_empty(NODE_BUFFER *node_buffer)
{	
	NODE *node;
	u16 type;
	
	for (u16 i = 0; i < NODE_BUFFER_LEN; i++)
	{
		node = &node_buffer->nodes[i];
		type = node->type;
		if(type == NTYPE_DELETE)
			return i;
	}
	return -1; 
}

u16 node_ball_create(NODE_BUFFER *node_buffer, u16 pos_x, u16 pos_y, u16 tile_idx) 
{
	u16 idx = node_buffer_get_empty(node_buffer);

	// if don`t have any node avaiable
	if(idx == -1)
		return idx;

	NODE *node = &node_buffer->nodes[idx];

	node->id = idx;
	node->type = NTYPE_BALL;
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

u16 node_player_create(NODE_BUFFER *node_buffer, u16 pos_x, u16 pos_y, u16 tile_idx) 
{	
	u16 idx = node_buffer_get_empty(node_buffer);

	// if don`t have any node avaiable
	if(idx == -1)
		return idx;

	NODE *node = &node_buffer->nodes[idx];

	node->id = idx;
	node->type = NTYPE_PLAYER;
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
	
	obj_set_pos(node->obj, node->pos_x, node->pos_y);
}
