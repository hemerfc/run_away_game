//
//! \file sprite.c
//!   Sprite module
//! \date 20210928
//! \author Hemerson F. Camargo
//
// === NOTES ===

#include <tonc.h>
#include "sprite.h"

// the index is the sprite id, the value is the index of sprite in tile_mem
// if the value is > -1, then the sprite is loaded in tile_mem
s16 sprite_loaded_list[SPRITE_LIST_LEN];
u16 nextTileMenIdx;
u16 nextOamIdx;

OBJ_ATTR obj_buffer[OBJ_BUFFER_LEN];
OBJ_AFFINE *obj_aff_buffer= (OBJ_AFFINE*)obj_buffer;

void sprite_init()
{
    nextTileMenIdx = 0;
    nextOamIdx = 0;

	for (u16 i = 0; i < SPRITE_LIST_LEN; i++)
	{
		sprite_loaded_list[i] = -1;        
	}

    oam_init(obj_buffer, OBJ_BUFFER_LEN);

	
}

u16 sprite_prepare(u16 sprite_id, const void *tilesSrc, size_t tilesLen, const void *palletSrc, size_t palletLen)
{	
    // if the sprite is not loaded
    if(sprite_loaded_list[sprite_id] < 0)
    {
        // load the sprite in tile_mem and set in the sprite_loaded_list
        memcpy32(&tile_mem[4][nextTileMenIdx], tilesSrc, tilesLen/4);
        memcpy32(pal_obj_mem, palletSrc, palletLen/4);  
        sprite_loaded_list[sprite_id] = nextTileMenIdx;

        // calculate the next tile index
        nextTileMenIdx = nextTileMenIdx+(tilesLen/(8*8/2));
    }

    u16 oam_idx = nextOamIdx;
    // set the next oam index
    nextOamIdx = nextOamIdx + 1;

    // get the oam data
	OBJ_ATTR *obj = &obj_buffer[oam_idx];

	obj_set_attr(obj, 
		ATTR0_SQUARE,					                    // Square, regular sprite
		ATTR1_SIZE_32x32,				                    // 32x32px, 
		ATTR2_PALBANK(0) | sprite_loaded_list[sprite_id]); 	// palbank 0, tile 0

    return oam_idx;
}

void sprite_draw(u16 oam_idx, u16 pos_x, u16 pos_y)
{
    OBJ_ATTR *obj = &obj_buffer[oam_idx];

    obj_set_pos(obj, pos_x, pos_y);
}

void sprite_draw_all()
{
    /// TODO: oam count deve ser calculado
    oam_copy(oam_mem, (OBJ_ATTR (*))&obj_buffer, OBJ_BUFFER_LEN);
}