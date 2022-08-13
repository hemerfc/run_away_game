//
//! \file player.c
//!   Player module
//! \date 20220729
//! \author Hemerson F. Camargo
//
// === NOTES ===

#include <tonc.h>
#include <stdlib.h>
#include "all_gfx.h"
#include "player.h"
#include "global.h"
#include "sprite.h"
#include "body.h"

PLAYER player;

#define SPRITE_OFFSET_X (-8)
#define SPRITE_OFFSET_Y (-12)

/**
 * \brief Limit the player's position to the screen size
 */ 
void player_collide_with_screen_edge()
{
	//240 × 160
	if(player.body.x + player.body.width > FRAME_WIDTH)
		player.body.x = FRAME_WIDTH - player.body.width;

	if(player.body.x < 0)	
		player.body.x = 0;

	if(player.body.y + player.body.heigth > FRAME_HEIGHT)
		player.body.y = FRAME_HEIGHT - player.body.heigth;

	if(player.body.y < 0)
		player.body.y = 0;
}

/*
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
	// iterate all nodes 
	for (u16 i = 0; i < NODE_LIST_LEN; i++)
	{
		// ignore if is the same node 
		if (i == node->id)
			continue;
	
		NODE *node2 = &node->node_list->nodes[i];

		if(player_collide_with_node(node, node2))
			game_state_set_room(&game_state, ROOM_GAMEOVER);
	}
}
*/

/**
 * \brief Initialize the player
 * \param pos_x Initial position X
 * \param pos_y Initial position Y
 */
void player_init(u16 pos_x, u16 pos_y)
{	
	player.live_seconds = 0;
	player.tick_counter = 0;

	player.body.x = pos_x;
	player.body.y = pos_y;
	player.body.width = 16;
	player.body.heigth = 20;
	player.body.spd_x = 2;
	player.body.spd_y = 2;

	// load gfx if not load, and prepare sprite on oam 
	player.obj_buffer_idx = sprite_prepare(CHAR_SPRITE_ID, charTiles, charTilesLen, charPal, charPalLen);

	sprite_draw(player.obj_buffer_idx, player.body.x + SPRITE_OFFSET_X, player.body.y + SPRITE_OFFSET_Y);
}

/**
 * \brief Update the player
 */
void player_update() 
{
	// update the position x , y, base on keypad pressed buttons 
	player.body.x += player.body.spd_x * key_tri_horz();
	player.body.y += player.body.spd_y * key_tri_vert();	

	player.live_seconds = player.body.y;
	itoa(player.live_seconds,player.str_score,10);

	player_collide_with_screen_edge();
	
	// player_collide_with_any_node(node);

	/* update the clock that is the score */
    player.tick_counter += 1;
	if(player.tick_counter >= 60)
	{
		//player.live_seconds += 1;
		//player.tick_counter = 0;
		/* update the score */
		//itoa(player.live_seconds,player.str_score,10);	
	}
}

/**
 * \brief Draw the player
 */
void player_draw() 
{	
	/* TODO: ADD PLAYER ANIMATION FOR WALKING AND DYING */
	sprite_draw(player.obj_buffer_idx, player.body.x + SPRITE_OFFSET_X, player.body.y + SPRITE_OFFSET_Y);
	
	/* print the score */
	tte_set_pos(10, 10);
	tte_write(player.str_score);
}
