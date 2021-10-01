//
// all_gfx.h
//
// One header to rule them and in the darkness bind them
// Date: 2021-09-30 02:17:12

#ifdef __cplusplus
extern "C" {
#endif

//{{BLOCK(ball)

//======================================================================
//
//	ball, 32x32@4, 
//	+ palette 32 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 64 + 512 = 576
//
//	Time-stamp: 2021-09-30, 02:17:11
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.17
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BALL_H
#define GRIT_BALL_H

#define ballTilesLen 512
extern const unsigned int ballTiles[128];

#define ballPalLen 64
extern const unsigned short ballPal[32];

#endif // GRIT_BALL_H

//}}BLOCK(ball)

//{{BLOCK(char)

//======================================================================
//
//	char, 32x32@4, 
//	+ palette 32 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 64 + 512 = 576
//
//	Time-stamp: 2021-09-30, 02:17:12
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.17
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CHAR_H
#define GRIT_CHAR_H

#define charTilesLen 512
extern const unsigned int charTiles[128];

#define charPalLen 64
extern const unsigned short charPal[32];

#endif // GRIT_CHAR_H

//}}BLOCK(char)

#ifdef __cplusplus
};
#endif
