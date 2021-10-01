
@{{BLOCK(ball)

@=======================================================================
@
@	ball, 32x32@4, 
@	+ palette 32 entries, not compressed
@	+ 16 tiles not compressed
@	Total size: 64 + 512 = 576
@
@	Time-stamp: 2021-09-30, 02:17:11
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.17
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global ballTiles		@ 512 unsigned chars
	.hidden ballTiles
ballTiles:
	.word 0x00000000,0x00000000,0x00000000,0x30000000,0x33300000,0x33330000,0x33330000,0x33333000
	.word 0x33300000,0x33333300,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333
	.word 0x00000333,0x00333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333
	.word 0x00000000,0x00000000,0x00000000,0x00000003,0x00000333,0x00003333,0x00003333,0x00033333
	.word 0x33333300,0x33333300,0x33333330,0x33333330,0x33333330,0x33333333,0x33333333,0x33333333
	.word 0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333
	.word 0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333
	.word 0x00333333,0x00333333,0x03333333,0x03333333,0x03333333,0x33333333,0x33333333,0x33333333

	.word 0x33333333,0x33333333,0x33333333,0x33333330,0x33333330,0x33333330,0x33333300,0x33333300
	.word 0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333
	.word 0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333
	.word 0x33333333,0x33333333,0x33333333,0x03333333,0x03333333,0x03333333,0x00333333,0x00333333
	.word 0x33333000,0x33330000,0x33330000,0x33300000,0x30000000,0x00000000,0x00000000,0x00000000
	.word 0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333300,0x33300000
	.word 0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x00333333,0x00000333
	.word 0x00033333,0x00003333,0x00003333,0x00000333,0x00000003,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global ballPal		@ 64 unsigned chars
	.hidden ballPal
ballPal:
	.hword 0x0320,0x000A,0x391F,0x3B7F,0x7BDE,0x1E9B,0x30B6,0x0000
	.hword 0x35DF,0x633E,0x0D71,0x44C4,0x6770,0x4E08,0x0421,0x0421
	.hword 0x0842,0x0842,0x0842,0x0842,0x0842,0x0842,0x0842,0x0842
	.hword 0x0C63,0x0C63,0x0C63,0x0C63,0x0C63,0x0C63,0x0C63,0x0C63

@}}BLOCK(ball)
