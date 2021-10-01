//
//! \file node.h
//!   Node module
//! \date 20210928
//! \author Hemerson F. Camargo
//
// === NOTES ===

#ifndef NODES_H
#define NODES_H

#include <tonc.h>
#include "global.h"

#define NODE_BUFFER_LEN 128
#define NTYPE_DELETE 0
#define NTYPE_PLAYER 1
#define NTYPE_BALL 2

typedef struct node {
	u16 id;
	u16 type;    
	
	// POSITION
	u16 pos_x;
	u16 pos_y;
	// SPEED
	s16 spd_x;
	s16 spd_y;
	// HITBOX
	u16 hitbox_x;
	u16 hitbox_y;
	u16 hitbox_w;
	u16 hitbox_h;
	bool enabled;
	void* node_data;

	// OBJ DATA 
	u16 tile_idx;
	u32 obj_buffer_id;
	OBJ_ATTR *obj;
} NODE;

typedef struct node_buffer {    
	NODE nodes[NODE_BUFFER_LEN];
} NODE_BUFFER;

extern void node_buffer_init(NODE_BUFFER *node_buffer);

extern void node_buffer_update(NODE_BUFFER *node_buffer);

extern void node_buffer_finish(NODE_BUFFER *node_buffer);

extern u16 node_ball_create(NODE_BUFFER *node_buffer, u16 pos_x, u16 pos_y, u16 tile_idx);

extern void node_ball_update(NODE *node);

extern u16 node_player_create(NODE_BUFFER *node_buffer, u16 pos_x, u16 pos_y, u16 tile_idx);

extern void node_player_update(NODE *node);

#endif // RING_BUFFER_H

