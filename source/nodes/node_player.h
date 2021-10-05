//
//! \file node_player.h
//!   Player module
//! \date 20210928
//! \author Hemerson F. Camargo
//
// === NOTES ===

#ifndef NODE_PLAYER_H
#define NODE_PLAYER_H

#include <tonc.h>
#include "node.h"
#include "node_list.h"

extern u16 node_player_create(NODE_LIST *node_list, u16 pos_x, u16 pos_y, u16 tile_idx);

extern void node_player_update(NODE_LIST *node_list, NODE *node);

extern void node_player_draw(NODE *node);

#endif // NODE_PLAYER_H

