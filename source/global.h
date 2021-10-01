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

extern OBJ_ATTR obj_buffer[128];
extern OBJ_AFFINE *obj_aff_buffer;

#define ST_MAIN_HOME 1
#define ST_MAIN_PLAYING 2
#define ST_MAIN_GAMEOVER 3

#endif // GLOBALS_H

