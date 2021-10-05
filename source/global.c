//
//! \file globals.h
//!   Global variables
//! \date 20210928
//! \author Hemerson F. Camargo
//
// === NOTES ===

#include <tonc.h>
#include "global.h"
#include "rooms/room.h"

GAME_STATE game_state;
OBJ_ATTR obj_buffer[128];
OBJ_AFFINE *obj_aff_buffer= (OBJ_AFFINE*)obj_buffer;