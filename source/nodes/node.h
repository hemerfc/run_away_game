//
//! \file node.h
//!   Node module
//! \date 20210928
//! \author Hemerson F. Camargo
//
// === NOTES ===

#ifndef NODE_H
#define NODE_H

#include <tonc.h>
#include "../global.h"

#define NTYPE_DELETE 0
#define NTYPE_PLAYER 1
#define NTYPE_BALL 2

typedef struct node {
	u16 id;
	u16 type;    
	bool collidable; 
	
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

#endif // NODE_H

