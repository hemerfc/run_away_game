//
//! \file globals.h
//!   Global variables
//! \date 20210928
//! \author Hemerson F. Camargo
//
// === NOTES ===

#ifndef GLOBAL_H
#define GLOBAL_H

#include <tonc.h>
#include "rooms/room.h"

extern GAME_STATE game_state;
extern OBJ_ATTR obj_buffer[128];
extern OBJ_AFFINE *obj_aff_buffer;

#define FRAME_WIDTH 240
#define FRAME_HEIGHT 160

#endif // GLOBALS_H

