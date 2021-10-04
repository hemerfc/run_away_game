//
//! \file node_ball.h
//!   Node module
//! \date 20210928
//! \author Hemerson F. Camargo
//
// === NOTES ===

#ifndef NODE_BALL_H
#define NODE_BALL_H

#include <tonc.h>
#include "../global.h"
#include "node_list.h"

extern u16 node_ball_create(NODE_LIST *node_list, u16 pos_x, u16 pos_y, u16 tile_idx);
extern void node_ball_update(NODE *node);
extern void node_ball_draw(NODE *node);

#endif // NODE_BALL_H

