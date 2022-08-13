//
//! \file sprite.h
//!   Sprite modules
//! \date 20220731
//! \author Hemerson F. Camargo
//
// === NOTES === 

#pragma once

#include <tonc.h>

#define SPRITE_LIST_LEN 512
#define OBJ_BUFFER_LEN 128

extern OBJ_ATTR obj_buffer[OBJ_BUFFER_LEN];
extern OBJ_AFFINE *obj_aff_buffer;

void sprite_init();
u16 sprite_prepare(u16 sprite_id, const void *tilesSrc, size_t tilesLen, const void *palletSrc, size_t palletLen);
void sprite_draw(u16 oam_idx, u16 pos_x, u16 pos_y);
void sprite_draw_all();

