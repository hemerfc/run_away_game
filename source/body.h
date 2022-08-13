//
//! \file player.h
//!   Player module
//! \date 20220729
//! \author Hemerson F. Camargo
//
// === NOTES ===

#pragma once

#include <tonc.h>
#include "global.h"
#include "sprite.h"

typedef struct body {
    // position
	s16 x;
	s16 y;
    // size
	s16 width;
	s16 heigth;
    // speed
	s16 spd_x;
	s16 spd_y;
} BODY;

bool point_vs_rect(s16 point_x, s16 point_y, s16 rect_x, s16 rect_y, s16 rect_width, s16 rect_height);

bool rect_vs_rect(s16 rect1_x, s16 rect1_y, s16 rect1_width, s16 rect1_heigth, s16 rect2_x, s16 rect2_y, s16 rect2_width, s16 rect2_heigth);

//bool dynamic_body_vs_body(const BODY* body_dynamic, const float fTimeStep, const BODY* body_static,
//    olc::vf2d& contact_point, olc::vf2d& contact_normal, float& contact_time)