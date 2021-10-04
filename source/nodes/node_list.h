//
//! \file node.h
//!   Node list module
//! \date 20210928
//! \author Hemerson F. Camargo
//
// === NOTES ===

#ifndef NODE_LIST_H
#define NODE_LIST_H

#include <tonc.h>
#include "../global.h"
#include "node.h"

#define NODE_LIST_LEN 128
#define NTYPE_DELETE 0
#define NTYPE_PLAYER 1
#define NTYPE_BALL 2

typedef struct node_list {    
	NODE nodes[NODE_LIST_LEN];
} NODE_LIST;

extern void node_list_init(NODE_LIST *NODE_LIST);

extern void node_list_update(NODE_LIST *NODE_LIST);

extern void node_list_draw(NODE_LIST *NODE_LIST);

extern u16 node_list_get_empty(NODE_LIST *NODE_LIST);

extern void node_list_finish(NODE_LIST *NODE_LIST);

#endif // NODE_LIST_H

