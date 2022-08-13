//
//! \file tileset.h
//!   Tileset module
//! \date 20220729
//! \author Hemerson F. Camargo
//
// === NOTES ===

#pragma once

#include <tonc.h>
#include "global.h"
#include "sprite.h"
#include "body.h"

typedef struct tileset_item {
	BODY body;
	u8 obj_buffer_idx;
    u16 type;
} TILESET_ITEM;

#define TILESET_MAX_LEN 32

extern TILESET_ITEM TILESET[TILESET_MAX_LEN][TILESET_MAX_LEN];

extern void tileset_init();
extern void tileset_update();
extern void tileset_draw();
