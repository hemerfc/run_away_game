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

void player_collide_with_screen_edge(NODE *node)
{
	//240 × 160
	if(node->pos_x + node->hitbox_offset_x + node->hitbox_w > FRAME_WIDTH)
		node->pos_x = FRAME_WIDTH - node->hitbox_w - node->hitbox_offset_x;

	if(node->pos_x + node->hitbox_offset_x < 0)	
		node->pos_x = -node->hitbox_offset_x;

	if(node->pos_y + node->hitbox_offset_x + node->hitbox_h >  FRAME_HEIGHT)
		node->pos_y = FRAME_HEIGHT - node->hitbox_h - node->hitbox_offset_y;

	if(node->pos_y + node->hitbox_offset_y < 0)
		node->pos_y = -node->hitbox_offset_y;
}

bool player_collide_with_node(NODE *node1, NODE *node2)
{
	if (node2->type == NTYPE_BALL)
	{
		// calc the centers
		u16 node_x = node1->pos_x + node1->hitbox_offset_x + (node1->hitbox_w/2);
		u16 node_y = node1->pos_y + node1->hitbox_offset_y + (node1->hitbox_h/2);

		u16 node2_x = node2->pos_x + (node2->hitbox_w/2);
		u16 node2_y = node2->pos_y + (node2->hitbox_h/2);

		u16 cat_a = abs(node_x - node2_x);
		u16 cat_b = abs(node_y - node2_y);

		u16 dist = Sqrt((cat_a * cat_a) + (cat_b * cat_b));

		if(dist <= 20)
		{
			return true;
		}
	}

	return false;
}

void player_collide_with_any_node(NODE *node)
{
	/* iterate all nodes */
	for (u16 i = 0; i < NODE_LIST_LEN; i++)
	{
		/* ignore if is the same node */
		if (i == node->id)
			continue;
	
		NODE *node2 = &node->node_list->nodes[i];

		if(player_collide_with_node(node, node2))
			game_state_set_room(&game_state, ROOM_GAMEOVER);
	}
}

void player_update_func(NODE *node) 
{
	// update the position x , y, base on keypad pressed buttons */
	node->pos_x += node->spd_x*key_tri_horz();
	node->pos_y += node->spd_y*key_tri_vert();	

	player_collide_with_screen_edge(node);
	
	player_collide_with_any_node(node);

	/* update the clock that is the score */
    game_state.player_tick_counter += 1;
	if(game_state.player_tick_counter >= 60)
	{
		game_state.player_live_seconds += 1;
		game_state.player_tick_counter = 0;
	}
}

void player_draw_func(NODE *node) 
{
	char str_score[20];

	/* TODO: ADD PLAYER ANIMATION FOR WALKING AND DYING */
	obj_set_pos(node->obj, node->pos_x, node->pos_y);
	
	/* update the score */
	itoa(game_state.player_live_seconds,str_score,10);	
	/* print the score */
	tte_set_pos(10, 10);
	tte_write(str_score);
}

u16 node_player_create(NODE_LIST *node_list, u16 pos_x, u16 pos_y, u16 tile_idx) 
{	
	game_state.player_live_seconds = 0;
	game_state.player_tick_counter = 0;

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
	node->spd_x = 2;
	node->spd_y = 2;
	node->hitbox_offset_x = 8;
	node->hitbox_offset_y = 8;
	node->hitbox_w = 16;
	node->hitbox_h = 32;
	node->enabled = true;
	node->obj = &obj_buffer[idx];
	node->node_list = node_list;

	obj_set_attr(node->obj, 
		ATTR0_SQUARE,					// Square, regular sprite
		ATTR1_SIZE_32x32,				// 32x32px, 
		ATTR2_PALBANK(0) | tile_idx); 	// palbank 0, tile 0

	obj_set_pos(node->obj, node->pos_x, node->pos_y);

	node->update = &player_update_func;
	node->draw = &player_draw_func;

	return idx;	
}
