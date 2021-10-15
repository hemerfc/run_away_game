//
//! \file node.h
//!   Node module
//! \date 20210928
//! \author Hemerson F. Camargo
//
// === NOTES ===
#pragma once

#include <tonc.h>

typedef struct node NODE;

typedef struct node_list NODE_LIST;
typedef void (*fn_node_update) (NODE *node);
typedef void (*fn_node_draw) (NODE *node);

typedef struct node {
	u16 id;
	u16 type;    
	bool collidable; 
	NODE_LIST *node_list;

	// POSITION
	s16 pos_x;
	s16 pos_y;
	
	// SPEED
	s16 spd_x;
	s16 spd_y;

	// HITBOX
	s16 hitbox_offset_x;
	s16 hitbox_offset_y;
	s16 hitbox_w;
	s16 hitbox_h;
	bool enabled;

	// OBJ DATA 
	u16 tile_idx;
	u32 obj_buffer_id;
	OBJ_ATTR *obj;

	// functions
	fn_node_update update;
	fn_node_draw draw;
} NODE;

