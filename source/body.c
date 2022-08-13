//
//! \file body.c
//!   Body module
//! \date 20220802
//! \author Hemerson F. Camargo
//
// === NOTES ===

#include <tonc.h>
#include <stdlib.h>
#include "body.h"

bool point_vs_rect(s16 point_x, s16 point_y, s16 rect_x, s16 rect_y, s16 rect_width, s16 rect_height)
{
    return (point_x >= rect_x && point_y >= rect_y && point_x < rect_x + rect_width && point_y < rect_y + rect_height);
}

bool rect_vs_rect(s16 rect1_x, s16 rect1_y, s16 rect1_width, s16 rect1_heigth, s16 rect2_x, s16 rect2_y, s16 rect2_width, s16 rect2_heigth)
{
    return (rect1_x < rect2_x + rect2_width && rect1_x + rect1_width > rect2_x && rect1_y < rect2_y + rect2_heigth && rect1_y + rect1_heigth > rect2_y);
}