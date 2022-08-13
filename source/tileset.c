//
//! \file plataform.c
//!   Player module
//! \date 20220729
//! \author Hemerson F. Camargo
//
// === NOTES ===

#include <tonc.h>
#include <stdlib.h>
#include "all_gfx.h"
#include "tileset.h"
#include "global.h"
#include "sprite.h"
#include "body.h"
#include "spritesheet.h"

TILESET_ITEM TILESET[TILESET_MAX_LEN][TILESET_MAX_LEN];

//typedef struct { u32 data[8]; } BLOCK;

//! Get the screen entry index for a tile-coord pair.
/*! This is the fast (and possibly unsafe) way.
*   \param bgcnt    Control flags for this background (to find its size)
*/
uint tileset_se_index_fast(uint tx, uint ty, u16 bgcnt)
{
    uint n= tx + ty*32;
    if(tx >= 32)
        n += 0x03E0;
    if(ty >= 32 && (bgcnt&BG_REG_64x64)==BG_REG_64x64)
        n += 0x0400;
    return n;
}

void tileset_load_map64x64(unsigned short sbb, const short unsigned *map)
{
  int iy;
  BLOCK *src= (BLOCK*)map;
  BLOCK *dst0= (BLOCK*)se_mem[sbb];
  BLOCK *dst1= (BLOCK*)se_mem[sbb+1];

  for(iy=0; iy<32; iy++)
  {
      // Copy row iy of the left half
    *dst0++= *src++;     *dst0++= *src++;

      // Copy row iy of the right half
    *dst1++= *src++;     *dst1++= *src++;
  }
  
  BLOCK *dst2= (BLOCK*)se_mem[sbb+2];
  BLOCK *dst3= (BLOCK*)se_mem[sbb+3];
  for(iy=0; iy<32; iy++)
  {
      // Copy row iy of the left half
    *dst2++= *src++;     *dst2++= *src++;

      // Copy row iy of the right half
    *dst3++= *src++;     *dst3++= *src++;
  }
}

/**
 * \brief Initialize the tileset
 */
void tileset_init()
{	
	// --- Init BG 0 ---
	// memcpy32(pal_bg_mem, spritesheetPal, spritesheetPalLen/4);
	// memcpy32(tile_mem[0], spritesheetTiles, spritesheetTilesLen/4);
	// memcpy32(se_mem[24], spritesheetMap, spritesheetMapLen/4);	

	dma3_cpy(pal_bg_mem, spritesheetPal, spritesheetPalLen);
	dma3_cpy(tile_mem[0], spritesheetTiles, spritesheetTilesLen);
	// this copie screm blocs on sequence, but this is not right

  tileset_load_map64x64(24, spritesheetMap);

	REG_BG0CNT= BG_PRIO(1)|BG_CBB(0)|BG_SBB(24)|BG_REG_64x64;
	REG_BG0HOFS= 0; 
	REG_BG0VOFS= 0;	

	// --- Init BG 1 ---
  // Base TTE init for tilemaps on BG 0
	tte_init_se(
		1,						// Background number (0-3)
		BG_PRIO(0)|BG_CBB(2)|BG_SBB(31),	// BG control
		0,						// Tile offset (special cattr)
		CLR_RED,			// Ink color
		14,						// BitUnpack offset (on-pixel = 15)
		NULL,					// Default font (sys8) 
		NULL);	

	//// --- Init BG 1 (mask) ---
	//const TILE tile= 
	//{{
	//	0xF2F3F2F3, 0x3F2F3F2F, 0xF3F2F3F2, 0x2F3F2F3F, 
	//	0xF2F3F2F3, 0x3F2F3F2F, 0xF3F2F3F2, 0x2F3F2F3F
	//}};
	//tile_mem[0][32]= tile;
	//pal_bg_bank[4][ 2]= RGB15(12,12,12);
	//pal_bg_bank[4][ 3]= RGB15( 8, 8, 8);
	//pal_bg_bank[4][15]= RGB15( 0, 0, 0);
	//se_fill(se_mem[29], 0x4020);	//
	//REG_BG1CNT= BG_CBB(0)|BG_SBB(29);	//
	//// --- Init BG 0 (text) ---
	//tte_init_chr4c_b4_default(0, BG_CBB(2)|BG_SBB(28));
	//tte_init_con();
	//tte_set_margins(8, 8, 232, 40);	//
	//// Base TTE init for tilemaps
	//tte_init_se(
	//	0,						// Background number (0-3)
	//	BG_CBB(0)|BG_SBB(31),	// BG control
	//	0,						// Tile offset (special cattr)
	//	CLR_RED,				// Ink color
	//	14,						// BitUnpack offset (on-pixel = 15)
	//	NULL,					// Default font (sys8) 
	//	NULL);
	
	

	//// --- Init window ---
	//REG_WIN0H= 0;
	//REG_WIN0V= SCREEN_HEIGHT;	//
}

/**
 * \brief Update the player
 */
void plataform_update() 
{

}

/**
 * \brief Draw the player
 */
void plataform_draw() 
{
}
