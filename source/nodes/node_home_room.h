//
//! \file node_ball.h
//!   Node module
//! \date 20210928
//! \author Hemerson F. Camargo
//
// === NOTES ===

#ifndef NODE_HOME_ROOM_BALL_H
#define NODE_HOME_ROOM_BALL_H

#include <tonc.h>
#include "../global.h"
#include "node_list.h"

u16 node_home_room_create(NODE_LIST *node_list);
void node_home_room_update(NODE_LIST *node_list, NODE *node);
void node_home_room_draw(NODE *node);

#endif // NODE_HOME_ROOM_BALL_H

