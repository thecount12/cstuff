#include <u.h>
#include <libc.h>
#include <draw.h>
enum{
	F♯3 = 0x3d, G3 = 0x41, G♯3 = 0x44, A3 = 0x49, A♯3 = 0x4d, B3 = 0x51,
	C4 = 0x56, C♯4 = 0x5b, D4 = 0x61, D♯4 = 0x67, E4 = 0x6d, F4 = 0x73,
	F♯4 = 0x7a, G4 = 0x81, G♯4 = 0x89, A4 = 0x91, A♯4 = 0x9a, B4 = 0xa3,
	C5 = 0xac, C♯5 = 0xb7, D5 = 0xc2, D♯5 = 0xcd, E5 = 0xd9
};
uchar ■[0x10000] = {
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0x3f,0xff,0xc7,0xff,0xff,0xff,0x1f,0xff,0x8f,0xff,
	0xff,0xff,0x9f,0xff,0x1f,0xff,0xff,0xff,0x8f,0xff,0x1f,0xff,
	0xff,0xff,0xcf,0xfe,0x3f,0xff,0xff,0xff,0xcf,0xfe,0x7f,0xff,
	0xff,0xff,0xc7,0xfc,0xff,0xff,0xff,0xff,0xa3,0xf1,0xff,0xff,
	0xff,0xff,0x90,0x83,0xff,0xff,0xff,0xff,0x98,0x07,0xff,0xff,
	0xff,0xff,0x90,0x07,0xff,0xff,0xff,0xff,0x90,0x07,0xff,0xff,
	0xff,0xff,0x80,0x07,0xfb,0xff,0xff,0xff,0x80,0x03,0xf7,0xff,
	0xff,0xff,0x80,0x07,0xef,0xff,0xff,0xff,0x80,0x07,0xcf,0xff,
	0xff,0xff,0x90,0x07,0x9f,0xff,0xff,0xff,0x98,0x0e,0x3f,0xff,
	0xff,0xff,0x8c,0x18,0x7f,0xff,0xff,0xff,0xc0,0x00,0xff,0xff,
	0xff,0xff,0xe0,0x03,0xff,0xff,0xff,0xff,0x00,0x07,0xff,0xff,
	0xff,0xfc,0x00,0x0f,0xff,0xff,0xff,0xf8,0x00,0x0f,0xff,0xff,
	0xff,0xf1,0xe0,0x1f,0xff,0xff,0xff,0xf3,0xf0,0x07,0xff,0xff,
	0xff,0xf3,0xf8,0x01,0xff,0xff,0xff,0xf7,0xf8,0x00,0xff,0xff,
	0xff,0xf7,0xe0,0x10,0xff,0xff,0xff,0xf4,0x00,0x1c,0x7f,0xff,
	0xff,0xf0,0x00,0x1e,0x7f,0xff,0xff,0xf0,0x71,0x1e,0x3f,0xff,
	0xff,0xe3,0xe0,0x9f,0x3f,0xff,0xff,0xe7,0xc0,0x9f,0x3f,0xff,
	0xff,0xe7,0x80,0x1f,0x3f,0xff,0xff,0xcf,0x80,0x0f,0x3f,0xff,
	0xff,0xcf,0x80,0x0f,0x1f,0xff,0xff,0xcf,0x80,0x0f,0x9f,0xff,
	0xff,0xcf,0xc0,0x0f,0x9f,0xff,0xff,0x8f,0xc0,0x4f,0x9f,0xff,
	0xff,0x9f,0xe0,0xcf,0xff,0xff,0xff,0x9f,0xff,0xcf,0xff,0xff,
	0xff,0x9f,0xff,0xcf,0xff,0xff,0xff,0x9f,0xff,0xcf,0xff,0xff,
	0xff,0x3f,0xff,0x9f,0xff,0xff,0xff,0x3f,0xff,0x9f,0xff,0xff};
uchar □[0x10000] = {
	1, 0, 0x20, 0, 0, /* wave form enable */
	5, 1, 1, 0, 0, /* OPL3 enable */
	4, 1, 0x1f, 0, 0, /* all channels 4-op */
/* Trem, Vib, Sus, KSR, Mult (nibble) L/R pairs */
	0x20, 0, 0xb2, 0, 0, 0x28, 0, 0xb2, 0, 0, /* S mod */
	0x20, 1, 0xb1, 0, 0, 0x28, 1, 0xb1, 0, 0, /* A I mod */
	0x21, 0, 0xb1, 0, 0, 0x29, 0, 0xb1, 0, 0, /* A II mod */
	0x21, 1, 0xb1, 0, 0, 0x29, 1, 0xb1, 0, 0, /* T mod */
	0x22, 0, 0xb0, 0, 0, 0x2a, 0, 0xb0, 0, 0, /* B mod */
	0x23, 0, 0xb2, 0, 0, 0x2b, 0, 0xb2, 0, 0, /* S car */
	0x23, 1, 0x31, 0, 0, 0x2b, 1, 0x31, 0, 0, /* A I car */
	0x24, 0, 0x31, 0, 0, 0x2c, 0, 0x31, 0, 0, /* A II car */
	0x24, 1, 0xb1, 0, 0, 0x2c, 1, 0xb1, 0, 0, /* T car */
	0x25, 0, 0x30, 0, 0, 0x2d, 0, 0x30, 0, 0, /* B car */
/* KSL (2 bits), Attenuation (6 bits) L/R pairs */
	0x40, 0, 0x1a, 0, 0, 0x48, 0, 0x1a, 0, 0, /* S mod */
	0x40, 1, 0x1a, 0, 0, 0x48, 1, 0x1a, 0, 0, /* A I mod */
	0x41, 0, 0x1a, 0, 0, 0x49, 0, 0x1a, 0, 0, /* A II mod */
	0x41, 1, 0x1a, 0, 0, 0x49, 1, 0x1a, 0, 0, /* T mod */
	0x42, 0, 0x1a, 0, 0, 0x4a, 0, 0x1a, 0, 0, /* B mod */
	0x43, 0, 0x06, 0, 0, 0x4b, 0, 0x00, 0, 0, /* S car */
	0x43, 1, 0x00, 0, 0, 0x4b, 1, 0x06, 0, 0, /* A I car */
	0x44, 0, 0x06, 0, 0, 0x4c, 0, 0x00, 0, 0, /* A II car */
	0x44, 1, 0x00, 0, 0, 0x4c, 1, 0x06, 0, 0, /* T car */
	0x45, 0, 0x06, 0, 0, 0x4d, 0, 0x00, 0, 0, /* B car */
/* Attack, Decay L/R pairs */
	0x60, 0, 0x60, 0, 0, 0x68, 0, 0x60, 0, 0, /* S mod */
	0x60, 1, 0x60, 0, 0, 0x68, 1, 0x60, 0, 0, /* A I mod */
	0x61, 0, 0x60, 0, 0, 0x69, 0, 0x60, 0, 0, /* A II mod */
	0x61, 1, 0x60, 0, 0, 0x69, 1, 0x60, 0, 0, /* T mod */
	0x62, 0, 0x60, 0, 0, 0x6a, 0, 0x60, 0, 0, /* B mod */
	0x63, 0, 0x30, 0, 0, 0x6b, 0, 0x30, 0, 0, /* S car */
	0x63, 1, 0x30, 0, 0, 0x6b, 1, 0x30, 0, 0, /* A I car */
	0x64, 0, 0x30, 0, 0, 0x6c, 0, 0x30, 0, 0, /* A II car */
	0x64, 1, 0x30, 0, 0, 0x6c, 1, 0x30, 0, 0, /* T car */
	0x65, 0, 0x30, 0, 0, 0x6d, 0, 0x30, 0, 0, /* B car */
/* Sustain, Release L/R pairs */
	0x80, 0, 0x54, 0, 0, 0x88, 0, 0x54, 0, 0, /* S mod */
	0x80, 1, 0x54, 0, 0, 0x88, 1, 0x54, 0, 0, /* A I mod */
	0x81, 0, 0x54, 0, 0, 0x89, 0, 0x54, 0, 0, /* A II mod */
	0x81, 1, 0x54, 0, 0, 0x89, 1, 0x54, 0, 0, /* T mod */
	0x82, 0, 0x54, 0, 0, 0x8a, 0, 0x54, 0, 0, /* B mod */
	0x83, 0, 0x74, 0, 0, 0x8b, 0, 0x74, 0, 0, /* S car */
	0x83, 1, 0x74, 0, 0, 0x8b, 1, 0x74, 0, 0, /* A I car */
	0x84, 0, 0x74, 0, 0, 0x8c, 0, 0x74, 0, 0, /* A II car */
	0x84, 1, 0x74, 0, 0, 0x8c, 1, 0x74, 0, 0, /* T car */
	0x85, 0, 0x74, 0, 0, 0x8d, 0, 0x74, 0, 0, /* B car */
/* Panning (R:0x20, L:0x10), Feedback (3 bits), Synthesis type */
	0xc0, 0, 0x10, 0, 0, 0xc3, 0, 0x21, 0, 0, /* Soprano */
	0xc0, 1, 0x10, 0, 0, 0xc3, 1, 0x21, 0, 0, /* Alto I */
	0xc1, 0, 0x10, 0, 0, 0xc4, 0, 0x21, 0, 0, /* Alto II */
	0xc1, 1, 0x10, 0, 0, 0xc4, 1, 0x21, 0, 0, /* Tenor */
	0xc2, 0, 0x10, 0, 0, 0xc5, 0, 0x21, 0, 0, /* Bass */
/* Io pur respiro, by Carlo Gesualdo (1560–1613) */
#define S 0xb0, 0, 0x38, 0, 0, 0xa0, 0,
#define S↓ 0xb0, 0, 0x38
#define S↑ 0xb0, 0, 0x18, 0, 0,
#define S☝ 0xb0, 0, 0x18, 1, 0,
#define AI 0xb0, 1, 0x38, 0, 0, 0xa0, 1,
#define AI↓ 0xb0, 1, 0x38
#define AI↑ 0xb0, 1, 0x18, 0, 0,
#define AI☝ 0xb0, 1, 0x18, 1, 0,
#define AII 0xb1, 0, 0x38, 0, 0, 0xa1, 0,
#define AII↓ 0xb1, 0, 0x38
#define AII↑ 0xb1, 0, 0x18, 0, 0,
#define AII☝ 0xb1, 0, 0x18, 1, 0,
#define T 0xb1, 1, 0x38, 0, 0, 0xa1, 1,
#define T↓ 0xb1, 1, 0x38
#define T↑ 0xb1, 1, 0x18, 0, 0,
#define T☝ 0xb1, 1, 0x18, 1, 0,
#define B 0xb2, 0, 0x38, 0, 0, 0xa2, 0,
#define B↓ 0xb2, 0, 0x38
#define B↑ 0xb2, 0, 0x18, 0, 0,
#define B☝ 0xb2, 0, 0x18, 1, 0,
#define ∪ ,0,0,
#define 𝅝 ,63,0,
#define 𝅗𝅥 ,31,0,
#define ♩ ,15,0,
#define ♪ ,7,0,
#define 𝅘𝅥𝅯 ,3,0,
/* measure 1 */
	S E4 ♩ S☝
	S↓ ♩ S☝
	S G4 ∪ AI B4 ♩ S↑ AI☝
	AI↓ ♩ AI☝
/* measure 2 */
	S E4 ∪ AI C5 ∪ AII E4 ♩ S↑ AI↑ AII☝
	S↓ ∪ AII↓ ♩ S↑ AII☝
	S D4 ∪ AI B4 ∪ AII G4 ∪ T B3 ♩ S↑ AI↑ AII↑ T☝
	S↓ ∪ AI↓ ∪ T↓ ♩ S↑ AI↑ T☝
/* measure 3 */
	AI G4 ∪ AII E4 ∪ T C4 ∪ B E4 ♩ AI↑ AII↑ T↑ B☝
	S B3 ∪ AII↓ ∪ B↓ ♩ S↑ AII↑ B☝
	S G3 ∪ AI E4 ∪ T B3 ∪ B G4 ♩ S↑ AI↑ T↑ B☝
	S↓ ∪ AI↓ ∪ T↓ ♩ S↑ AI↑ T☝
/* measure 4 */
	AII D4 ∪ B F♯4 ♩ AII☝
	T↓ ♩ T↑ B☝
	AII C♯4 ∪ T A♯3 ∪ B↓ ♩ AII↑ T☝
	AII↓ ∪ T↓ ♩ AII↑ T↑ B☝
/* measure 5 */
	0, 0, 0, 16, 0, T B3 ♩ T☝ T C♯4 ♩ T☝ T D4 ♩ T☝
/* measure 6 */
	AI A4 ∪ T↓ ♩ AI↑ T☝
	AI B4 ∪ T D♯4 ♩ AI↑ T☝
	AI C5 ∪ T E4 ♩ AI☝
	AI↓ ♩ T☝
/* measure 7 */
	AII E4 ∪ T A3 ♩ AI↑ AII☝
	AI C♯5 ∪ AII F♯4 ♩ AI↑ T☝
	AI D5 ♩ AII☝
	AII G4 ♩ AII☝
/* measure 8 */
	AII↓ ∪ T B3 ♩ AII☝
	AII G♯4 ♩ AI↑ AII↑ T☝
	AI C5 ∪ AII A4 ∪ T C4 ♩ T☝
	T↓ ♩ AI↑ T☝
/* measure 9 */
	AI B4 ∪ T D4 ♩ T☝
	T D♯4 ♩ AII↑ T☝
	AII G♯4 ∪ T E4 ∪ B E4 ♩ AI↑ AII☝
	AI C♯5 ∪ AII↓ ♩ AI↑ AII↑ T↑ B☝
/* measure 10 */
	AI D5 ∪ AII A4 ∪ T D4 ∪ B F♯4 ♩ AI↑ AII↑ B☝
	AI↓ ∪ AII A♯4 ∪ B G4 ♩ AII↑ B☝
	AII B4 ∪ B↓ ♩ AI↑ AII↑ T☝
	AI↓ ∪ AII↓ ∪ T↓ ♩ AI↑ AII↑ T☝
/* measure 11 */
	AI E5 ∪ AII C5 ∪ T G4 ♩ B☝
	B↓ ♩ AII↑ T↑ B☝
	AII B4 ∪ T E4 ∪ B G♯4, 16, 0,
	S B3 ♩ AI↑ AII↑ T↑ B☝
/* measure 12 */
	AI D5 ∪ B G4 ♩ S↑ AI☝
	S C4 ∪ AI G4 ∪ AII E4 ♩ S↑ AI↑ AII☝
	S D4 ∪ AI A4 ∪ AII F♯4 ♩ AI↑ AII☝
	AI B4 ∪ AII G4 ♩ S↑ AI↑ AII☝
/* measure 13 */
	S E4 ∪ AI↓ ∪ AII↓ ♩ S↑ AI☝
	S↓ ∪ AI C5 ♩ S↑ AI↑ AII☝
	S F♯4 ∪ AI D5 ∪ AII A4 𝅗𝅥 S↑ AII↑ B☝
/* measure 14 */
	S F4 ∪ AII A♯4 ∪ B↓ 𝅗𝅥 S↑ AI↑ AII☝
	S E4 ∪ AI B4 ∪ AII G4 ♩ AII☝
	AII↓ ♩ S↑ B☝
/* measure 15 */
	S C4 ∪ B E4 ♩ S↑ AI↑ AII☝
	AI A4 ∪ AII E4 ∪ T C4, 8, 0, S A3 ♪ S↑ AI↑ AII↑ T☝
	S B3 ∪ AI G♯4 ∪ T E4 ♩ S↑  T☝
	AII G♯4 ∪ T D4 ∪ B B4, 8, 0, S D4 ♪ S↑ AI↑ AII↑ T↑ B☝
/* measure 16 */
	S C♯4 ∪ AII A4 ∪ T E4 ∪ B A4, 8, 0, AI E5 ♪ S↑ AI☝
	S A3 ∪ AI C♯5 ♪ S☝ S E4 ♪ S↑ AI↑ AII↑ T↑ B☝
	S D4 ∪ AI B4 ♪ AI☝ AI D5 ♪ AI☝
	AI C5, 8, 0, AII A4 ♪ AI↑ AII☝
/* measure 17 */
	AI B4 ∪ AII G4, 8, 0, T G4 ♪ S↑ AI↑ AII↑ T☝
	S C4 ∪ AI G4 ∪ AII C4 ∪ T E4 ♩ S↑ AI↑ AII↑ T☝
	S E4 ∪ AI A4 ∪ T C4 ♪ T☝
		AII↓ ∪ T E4 ∪ B↓ ♪ S↑ AI↑ AII↑ T↑ B☝
	S F4 ∪ AII A3 ∪ T D4 ∪ B F4, 8, 0, AI A4 ♪ S↑ AI↑ T↑ B☝
/* measure 18 */
	AI F4 ∪ T↓ ∪ B D4 ♪ AI↑ T☝
		S↓ ∪ AI G4 ∪ T↓ 𝅘𝅥𝅯 AI☝ AI A4 𝅘𝅥𝅯 S↑ AI↑ AII↑ T☝
	S D4 ∪ AI G4 ∪ AII B3 ∪ T B3 ♪ AII☝ AII C4 ♪ AII↑ T☝
	AII D4 ∪ T A3 ♩ S↑ AI↑ AII☝
	S A3 ∪ AI F♯4 ∪ AII D4 ♩ S↑ AI↑ AII↑ T↑
	0xb2, 0, 0x18, 33, 0,
/* measure 19 */
	S F4 ∪ AI A4 ∪ AII D4 ∪ T A3 ∪ B F4 𝅝
/* measure 20 */
	S↑ AI↑ AII↑ T↑ B☝
	S C♯4 ∪ AI A♯4 ∪ AII F♯4 ∪ T C♯4 ∪ B F♯4 ♩
	S↑ AI↑ AII↑ T↑ B☝
	S↓ ∪ AI↓ ∪ AII↓ ∪ T↓ ∪ B↓ ♩ S↑ AI↑ AII↑ T↑ B☝
/* measure 21 */
	S↓ ∪ AI A4 ∪ AII↓ ∪ T↓ ∪ B↓ 𝅗𝅥 T↑ B☝
	T F♯3 ∪ B D4 ♩ S↑ AI↑ AII☝
	S B3 ∪ AI F♯4 ∪ AII B3 ♩ S↑ AI↑ AII↑ T↑ B☝
/* measure 22 */
	S A3 ∪ AI↓ ∪ AII C♯4 ∪ T↓ ∪ B C♯4 𝅗𝅥 S↑ AI↑ AII↑ T↑ B☝
	S G♯3 ∪ AI F4 ∪ AII↓ ∪ T G♯3 ∪ B↓ 𝅗𝅥 S↑ AI↑ AII↑ T↑
	0xb2, 0, 0x18, 33, 0,
/* measure 23 */
	S E4 ∪ AI A4 ∪ AII E4 ∪ T C4 ∪ B C4 𝅗𝅥 S↑ AI↑ AII↑ T↑ B☝
/* measure 24 */
	S A3 ♪ S☝ S C4 ♪ S☝
	S B3 ∪ AI G4 ♪ S↑ AI☝ S C4 ∪ AI A4 ♪ S↑ AI☝
	S D4 ∪ AI F4 ∪ AII D4 ♪ S↑ AI↑ AII☝
		S C4 ∪ AI G4 ∪ AII E4 𝅘𝅥𝅯 S☝ S B3 𝅘𝅥𝅯 S↑ AI↑ AII☝
	S C4 ∪ AI A4 ∪ AII C4 ♪ AI↑ AII☝
		AI G4 ∪ AII D4 𝅘𝅥𝅯 AI☝ AI F4 𝅘𝅥𝅯 S↑ AI↑ AII☝
/* measure 25 */
	S B3 ∪ AI G4 ∪ AII E4, 8, 0, B G4 ♪ S↑ AI↑ AII↑ B☝
	AI↓ ∪ AII↓ ∪ B E4 ♪ AI↑ B☝ AI C5 ∪ B↓ ♪ AI↑ AII↑ B☝
	AI B4 ∪ B↓ ♪ AI☝
		S G4 ∪ AI↓ ∪ AII B4 ∪ T E4 ♪ S↑ AI↑ AII↑ T☝
	S E4 ∪ AI↓ ∪ AII G♯4 ∪ T B3 ♪ S↑ AII↑ T☝
		S↓ ∪ AII↓ ∪ T↓ ♪ S↑ AII↑ T☝
/* measure 26 */
	S↓ ∪ AII↓ ∪ T↓ ♪ T☝ T E4 ♪ S↑ AI↑ AII↑ T↑ B☝
	S↓ ∪ AI C♯5 ∪ AII A4 ∪ T↓ ∪ B A4 ♩ S↑ AI↑ AII↑ B☝
	S↓ ∪ AI↓ ∪ AII↓ ∪ B↓ ♩ T☝
	T↓ ♪ S↑ AI↑ AII↑ B☝
		 S↓ ∪ AI↓ ∪ AII↓ ∪ B↓ ♪ S↑ AI↑ AII↑ T↑ B☝
/* measure 27 */
	S F♯4 ∪ AI D5 ∪ AII↓ ∪ T D4 ∪ B D4 ♩ S↑ AI↑ AII↑ T↑ B☝
	S G4 ∪ AI↓ ∪ AII B4 ∪ T↓ ∪ B G4 ♩ S↑ AI↑ AII↑ T↑ B☝
	S D4 ∪ AI B4 ∪ AII G4 ∪ T↓ ∪ B↓ 𝅗𝅥 S↑ AI↑ AII↑ T↑ B☝
/* measure 28 */
	S↓ ∪ AI G4 ∪ AII D4 ∪ T B3 ∪ B↓ 𝅗𝅥 S↑ AI↑ AII↑ T↑
	0xb2, 0, 0x18, 17, 0, B A♯4 ♩ B☝
/* measure 29 */
	T D4 ∪ B↓, 16, 0, AI↓ ♩ AI☝
	AI G♯4 ∪ AII F4 𝅗𝅥 AI↑ AII↑ T↑ B☝
/* measure 30 */
	AI A4 ∪ AII↓ ∪ T↓ ∪ B A4 𝅗𝅥 AII↑ T☝
	AII E4 ∪ T C♯4 𝅗𝅥 AI↑ AII↑ T↑ B☝
/* measure 31 */
	0xb2, 0, 0x18, 33, 0, S F4 𝅗𝅥 S☝
/* measure 32 */
	S↓ ∪ AII A4, 16, 0, T D4 ♩ T☝
	AI C5 ∪ T D♯4 𝅗𝅥 S↑ AI↑ AII↑ T☝
/* measure 33 */
	S E4 ∪ AI↓ ∪ AII↓ ∪ T E4 𝅗𝅥 AI↑ AI☝
	AI B4 ∪ AII G♯4 ♩ S↑ AI↑ AI☝
	S G4 ∪ AI E5 ∪ AII B4 ∪ B E4 ♩ T☝
/* measure 34 */
	T B3 ♩ S↑ AI↑ AII↑ T↑ B☝
	S E4 ∪ AI B4 ∪ AII G4 ∪ T↓ ∪ B↓ ♩ S↑ AI↑ AII↑ T↑ B☝
	S D♯4 ∪ AI↓ ∪ AII F♯4 ∪ T↓ ∪ B B3 𝅗𝅥 S↑ AI↑ AII↑ T↑ B☝
/* measure 35 */
	S E4 ∪ AI↓ ∪ AII G♯4 ∪ T↓ ∪ B E4 ♩ S↑ AI↑ AII↑ B☝
	S G4 ∪ AI E5 ∪ AII B4 ∪ B↓ ♩ T☝
	T↓ ♩ S↑ AI↑ AII↑ T↑ B☝
	S E4 ∪ AI G♯4 ∪ AII E4 ∪ T C♯4 ∪ B↓ ♩ S↑ AI↑ AII↑ T↑ B☝
/* measure 36 */
	S F4 ∪ AI C♯5 ∪ AII G4 ∪ T↓ ∪ B C♯4 𝅗𝅥 S↑ AI↑ AII↑ T↑ B☝
	S F♯4 ∪ AI↓ ∪ AII A♯4 ∪ T↓ ∪ B F♯4 𝅗𝅥 S↑ AI↑ AII↑ T↑ B☝
/* measure 37 */
	S↓ 𝅗𝅥 S☝ S B3 ∪ AI B4 ♪ S☝ S↓ ♪ S☝
	S↓ ∪ AI E4 ♪ S↑ AI☝ S↓ ∪ AI↓ ♪ S↑ AI☝
/* measure 38 */
	S G3 ∪ AI↓ ♪ AI☝ AI↓ ♪ AI☝
	AI C4 ∪ AII C5 ∪ T E4 ♩ S↑ AI↑ AII↑ T☝
	S A3 ∪ AI C5 ∪ AII E4 ∪ T A3 ♪ AII↑ T☝
		AII↓ ∪ T↓ ♪ S↑ AI↑ AII↑ T☝
	S↓ ∪ AI E5 ∪ AII↓ ∪ T↓ ∪ B C5 ♪ S↑ AII↑ T☝
		S↓ ∪ AII↓ ∪ T↓ ♪ S↑ AI↑ AII↑ T↑ B☝
/* measure 39 */
	S E4 ∪ AI G♯4 ∪ AII B4 ∪ T B3 ∪ B E4 ♪ AI↑ B☝
		AI↓ ∪ B↓ ♪ AI↑ AII↑ B☝
	AI↓ ∪ AII↓ ∪ B↓ ♪ AI↑ AII↑ B☝
		AI↓ ∪ AII↓ ∪ B↓ ♪ AI↑ AII↑ B☝
	AI A4 ∪ AII E4 ∪ T A3 ∪ B C♯4 ♪ AII☝ AII↓ ♪ S↑ AI↑ AII☝
	S A3 ∪ AI E5 ∪ AII↓ ♪ AI↑ AII☝
		AI↓ ∪ AII↓ ♪ S↑ AI↑ AII↑ B☝
/* measure 40 */
	S F4 ∪ AI A4 ∪ AII D4 ∪ B D4 ♪ AI☝ AI↓ ♪ AI↑ AII↑ T☝
	AI↓ ∪ AII A3 ∪ T D4 ♩ S↑ AII↑ T☝
	S A♯3 ∪ AII D4 ∪ T G3 ♪ S↑ T☝ S↓ ∪ T↓ ♪ S↑ AI↑ T☝
	S↓ ∪ AI G4 ∪ T↓ ♪ S↑ AII↑ T☝
		S↓ ∪ AII↓ ∪ T↓ ♪ S↑ AI↑ AII↑ T☝
/* measure 41 */
	S A3 ∪ AI F4 ∪ AII↓ ∪ T A3 𝅘𝅥𝅯 AI↑ AII☝
			AI G4 ∪ AII E4 𝅘𝅥𝅯 S↑ AI↑ AII☝
		S B3 ∪ AI F4 ∪ AII D4 𝅘𝅥𝅯 S↑ AI↑ AII☝
			S C4 ∪ AI G4 ∪ AII E4 𝅘𝅥𝅯 S↑ AI↑ AII☝
	S D4 ∪ AI A4 ∪ AII F4 𝅘𝅥𝅯 S☝ S E4 𝅘𝅥𝅯 S☝
		S D4 ∪ T B3 𝅘𝅥𝅯 S↑ T☝ S E4 ∪ T C4 𝅘𝅥𝅯 S↑ T☝
	S F4 ∪ T D4 𝅘𝅥𝅯 T☝ T E4 𝅘𝅥𝅯 T☝
		AI B4 ∪ T D4 𝅘𝅥𝅯 S↑ T☝ S G4 ∪ T E4 𝅘𝅥𝅯 S↑ AI↑ AII↑ T☝
	S A4 ∪ AI A4 ∪ AII D4 ∪ T F♯4 ♪ AI☝
		AI B4 𝅘𝅥𝅯 AI☝ AI C5 𝅘𝅥𝅯 AI↑ AII↑ B☝
/* measure 42 */
	AI D5 ♩ S↑ AI↑ T☝
	S D4 ∪ AI A4 ∪ T F♯4 ♩ S↑ AI↑ 0xb1, 1, 0x18, 17, 0,
	S G3 ∪ AI E4 ∪ AII G3 ∪ B C4 ♩ S↑ AII↑ B☝
/* measure 43 */
	S↓ ∪ AII C4 ∪ B↓ ♩ S↑ AI☝
	S A3 ∪ AI↓ ∪ T G3 𝅘𝅥𝅯 S☝ S B3 𝅘𝅥𝅯 S☝ S C4 𝅘𝅥𝅯 S☝ S D4 𝅘𝅥𝅯 S↑ T☝
	S E4 ∪ T G4, 8, 0, AI F4 𝅘𝅥𝅯 AI☝ AI G4 𝅘𝅥𝅯 AI☝
	AI A4 𝅘𝅥𝅯 AI☝ AI B4 𝅘𝅥𝅯 AI☝ AI C5 ♪ S↑ AI↑ AII↑ T↑ B☝
/* measure 44 */
	S C4 ∪ AI A4 ∪ AII↓ ∪ T F4 ∪ B F4 𝅝 S↑ AI↑ AII↑ T↑
/* measure 45 */
	0xb2, 0, 0x18, 33, 0,
	S A3 ∪ AI C5 ∪ AII F4 ∪ T C4 ∪ B↓ 𝅗𝅥 S↑ AI↑ AII↑ B☝
/* measure 46 */
	S↓ ∪ AI↓ ∪ AII↓ ∪ B↓ ♩ S↑ T☝
	S B3 𝅘𝅥𝅯 S☝ S C4 𝅘𝅥𝅯 S☝ S D4 𝅘𝅥𝅯 S☝ S E4 𝅘𝅥𝅯 S☝
	S F4 ♪ T☝ T D4 𝅘𝅥𝅯 T☝ T E4 𝅘𝅥𝅯 T☝
	T F4 𝅘𝅥𝅯 T☝ T G4 𝅘𝅥𝅯 T☝ T A4 ♪ S↑ AI↑ AII↑ T↑ B☝
/* measure 47 */
	S↓ ∪ AI A♯4 ∪ AII D4 ∪ T F4 ∪ B A♯4 𝅗𝅥 S↑ AI↑ AII↑ T↑ B☝
	T↓ ♪ T☝ T D4 ♪ T☝
	AII A4 ∪ T F4 ♪ AII☝ AII F4 ♪ AII☝
/* measure 48 */
	AI C5 ∪ AII G4 ♪ AI☝ AI B4 ♪ AI↑ T☝
	S G4 ∪ AI C5 ∪ T E4 ♪ S☝ S E4 ♪ S↑ AII↑ T☝
	S G4 ∪ AII E4 ∪ B C5 ♪ B☝ B B4 ♪ S↑ AI↑ AII↑ B☝
	S E4 ∪ AI↓ ∪ AII A4 ∪ B C5 ♪ AII☝ AII G4 ♪ S↑ AI↑ AII↑ B☝
/* measure 49 */
	AII A4 ∪ T D4 ∪ B F4 ♪ T☝ T C4 ♪ AII↑ T↑ B☝
	AII F4 ∪ T D4 ∪ B E4 ♪ B☝ B D4 ♪ AII↑ B☝
	AII G4 ∪ B E4 ♪ AII☝ AI A4 ∪ AII F♯4 ♪ AII↑ T☝
	AII G4 ∪ T C♯4 ♪ AI☝ AI G4 ♪ AI↑ T↑ B☝
/* measure 50 */
	S D4 ∪ AI B4 ∪ B D4 ♪ S↑ AII☝ S C♯4 ∪ AII↓ ♪ S↑ AI↑ AII☝
	S D4 ∪ AI A4 ∪ AII F4 ∪ T A4 ♪ S↑ AI↑ AII↑ T☝
		S A3 ∪ AI D5 ∪ AII D4 ∪ T F♯4 ♪ S↑ AI↑ AII↑ T☝
	AI B4 ∪ AII E4 ∪ T G4 ∪ B G4 ♪ AI↑ B☝
		AI C5 ∪ B E4 ♪ AII↑ B☝
	S G4 ∪ AII↓ ∪ B C5 ♪ S↑ AI☝
		S E4 ∪ AI↓ ♪ S↑ AI↑ AII↑ T↑ B☝
/* measure 51 */
	S F4 ∪ AI D5 ∪ T A4 ∪ B A4 ♪ AI☝ AI C♯5 ♪ S↑ AI↑ T☝
	AI D5 ∪ T↓ ♪ T☝ T G♯4 ♪ S↑ T↑ B☝
	S E4 ∪ T A4 ♩ AI↑ T☝
	AI C5 ∪ T↓ ♩ S↑ AI↑ T☝
/* measure 52 */
	AI D5 ∪ T D4 ♩ T☝ T↓ ♩ AI↑ T☝ T F♯4 𝅗𝅥 T☝
/* measure 53 */
	T G4 ♩ T☝
	S G4 ∪ AI C5 ∪ AII G4 ∪ T E4 ∪ B C4 ♪ S↑ AI↑ AII↑ T↑ B☝
		S↓ ∪ AI↓ ∪ AII↓ ∪ T↓ ∪ B↓ ♪ S↑ AI↑ AII↑ T↑ B☝
	S↓ ∪ AI↓ ∪ AII↓ ∪ T↓ ∪ B↓ 𝅗𝅥 AII↑ B☝
/* measure 54 */
	AII G3 ∪ B E4 𝅗𝅥 S↑ AI↑ AII↑ T↑ B☝
	S C♯4 ∪ AI G4 ∪ AII↓ ∪ T↓ ∪ B↓ ♩ S↑ AI↑ T☝
	S↓ ∪ AI↓ ∪ T↓ ♩ S↑ AI↑ AII↑ T↑ B☝
/* measure 55 */
	S D4 ∪ AI F♯4 ∪ AII D4 ∪ T A3 ∪ B D4 𝅗𝅥 S☝
	S↓ 𝅗𝅥 S↑ AI↑ AII↑ T↑ B☝
/* measure 56 */
	S↓ ♩ S☝ S C♯4 ♩ S☝ S C4 ∪ T F4 𝅗𝅥 S↑ T☝
/* measure 57 */
	S G3 ∪ T↓ ♩ T☝ T E4 ♩ T☝
	AI G4 ∪ AII A♯4 ∪ T D♯4 ∪ B D♯4 ♩ AI☝ AI↓ ♩ S↑ T↑ B☝
/* measure 58 */
	T A♯3 ∪ B↓ ♩ AI↑ B☝ AI F♯4 ∪ B D4 ♩ AI↑ AII↑ B☝
	AI F4 ∪ AII A♯4 ∪ B C♯4, 16, 0, S F4 ♩ AI↑ T↑ B☝
/* measure 59 */
	AI C5 ∪ B C4 ♩ S↑ AII☝ S↓ ∪ AII A4 ♩ S↑ AII☝
	S E4 ∪ AII G♯4 ♩ S☝ S D♯4 ♩ AI↑ AII↑ B☝
/* measure 60 */
	AII G4 ♩ S☝ S D4 ∪ T G4 ∪ B B4 ♩ S↑ AII↑ T↑ B☝
	T↓ ∪ B↓ ♩ T↑ B☝ AI B4 ∪ T E4 ∪ B G♯4 ♩ AI↑ T↑ B☝
/* measure 61 */
	AI↓ ∪ AII↓ ∪ T D♯4 ∪ B G4 ♩ AI↑ AII↑ T☝
	AI A♯4 ∪ AII↓ ∪ T D4 ♩ AI↑ AII☝
	AI A4 ∪ AII F♯4 ♩ AII↑ T☝
	AII F4 ∪ T D4 ♩ AI↑ T☝
/* measure 62 */
	AI G4 ∪ T↓ ♩ AII↑ T☝
	AII E4 ∪ T C♯4 ♩ T☝
	S G4 ∪ T C4 ♩ AII↑ T☝
	AII↓ ∪ T B3 ♪ T☝ T A3 ♪ S↑ AI↑ AII↑ T↑ B☝
/* measure 63 */
	S↓ ∪ AI B4 ∪ AII↓ ∪ T G3 ∪ B E4 ♪ T☝ T A3 ♪ S↑ AII↑ T☝
	S F♯4 ∪ AII D4 ∪ T B3 ♩ S↑ AII↑ T☝
	S F4 ∪ AII B3 ∪ T D4 ♩ AI↑ T☝
	AI↓ ∪ T↓ ♩ S↑ AII☝
/* measure 64 */
	S E4 ∪ AII G3 ♩ AI↑ AII↑ T☝
	AI A♯4 ∪ AII G4 ∪ T↓ ♩ AI↑ AII↑ T☝
	AI A4 ∪ AII↓ ∪ T C♯4 ♩ AII☝
	AII F4 ♩ AII↑ T☝
/* measure 65 */
	AII E4 ∪ T C4 𝅝 AI↑ AII↑ T☝
/* measure 66 */
	AI G♯4 ∪ AII↓ ∪ T B3 𝅝 S↑ AI↑ AII↑ T↑
	0xb2, 0, 0x18, 64, 0 /* whew */
};
void
↔(uchar *d, uchar *s){
	int i;
	for(i = 0; i < 48; i++){
		d[0] = (s[5] * 0x0202020202ULL & 0x010884422010ULL) % 1023;
		d[1] = (s[4] * 0x0202020202ULL & 0x010884422010ULL) % 1023;
		d[2] = (s[3] * 0x0202020202ULL & 0x010884422010ULL) % 1023;
		d[3] = (s[2] * 0x0202020202ULL & 0x010884422010ULL) % 1023;
		d[4] = (s[1] * 0x0202020202ULL & 0x010884422010ULL) % 1023;
		d[5] = (s[0] * 0x0202020202ULL & 0x010884422010ULL) % 1023;
		s += 6;
		d += 6;
	}
}
void
↕(uchar *d, uchar *s){
	int i;
	s += 6 * 47;
	for(i = 0; i < 48; i++){
		d[0] = s[0];
		d[1] = s[1];
		d[2] = s[2];
		d[3] = s[3];
		d[4] = s[4];
		d[5] = s[5];
		s -= 6;
		d += 6;
	}
}
Rectangle
sq48(Point p, int i){
	p.x += (i & 7) * 48;
	p.y += (i >> 3) * 48;
	return rectaddpt(Rect(0, 0, 48, 48), p);
}
Point
terra(double x, double y, double z){
	double t;
	t = y;
	y = t * 0.900968867902 - z * 0.433883739118;
	z = t * 0.433883739118 + z * 0.900968867902;
	z = 120.0 / (8.0 - z);
	return Pt(z * x, z * y);
}
void
tesseract(Point o, double k, double t, double adj){
	Point •[16];
	double s, c, x, y, z, w;
	int i;
	s = sin(t);
	c = cos(t);
	for(i = 0; i < 16; i++){
		t = 0.5 - (i & 1);
		y = 0.5 - (i >> 1 & 1);
		x = t * c - y * s;
		y = t * s + y * c;
		t = 0.5 - (i >> 2 & 1);
		w = 0.5 - (i >> 3);
		z = t * c - w * s;
		w = t * s + w * c;
		t = y;
		y = t * c - z * s;
		z = t * s + z * c;
		z = k / (2.3 - z) / (2.121 - w);
		•[i] = Pt(o.x + z * (x + adj), o.y + z * y);
	}
	line(screen, •[1], •[0], 0, 0, 2, display->white, ZP);
	line(screen, •[0], •[2], 0, 0, 2, display->white, ZP);
	line(screen, •[2], •[3], 0, 0, 2, display->white, ZP);
	line(screen, •[3], •[1], 0, 0, 2, display->white, ZP);
	line(screen, •[5], •[4], 0, 0, 2, display->white, ZP);
	line(screen, •[4], •[6], 0, 0, 2, display->white, ZP);
	line(screen, •[6], •[7], 0, 0, 2, display->white, ZP);
	line(screen, •[7], •[5], 0, 0, 2, display->white, ZP);
	line(screen, •[1], •[5], 0, 0, 2, display->white, ZP);
	line(screen, •[0], •[4], 0, 0, 2, display->white, ZP);
	line(screen, •[2], •[6], 0, 0, 2, display->white, ZP);
	line(screen, •[3], •[7], 0, 0, 2, display->white, ZP);
	line(screen, •[9], •[8], 0, 0, 2, display->white, ZP);
	line(screen, •[8], •[10], 0, 0, 2, display->white, ZP);
	line(screen, •[10], •[11], 0, 0, 2, display->white, ZP);
	line(screen, •[11], •[9], 0, 0, 2, display->white, ZP);
	line(screen, •[13], •[12], 0, 0, 2, display->white, ZP);
	line(screen, •[12], •[14], 0, 0, 2, display->white, ZP);
	line(screen, •[14], •[15], 0, 0, 2, display->white, ZP);
	line(screen, •[15], •[13], 0, 0, 2, display->white, ZP);
	line(screen, •[9], •[13], 0, 0, 2, display->white, ZP);
	line(screen, •[8], •[12], 0, 0, 2, display->white, ZP);
	line(screen, •[10], •[14], 0, 0, 2, display->white, ZP);
	line(screen, •[11], •[15], 0, 0, 2, display->white, ZP);
	line(screen, •[1], •[9], 0, 0, 2, display->white, ZP);
	line(screen, •[0], •[8], 0, 0, 2, display->white, ZP);
	line(screen, •[2], •[10], 0, 0, 2, display->white, ZP);
	line(screen, •[3], •[11], 0, 0, 2, display->white, ZP);
	line(screen, •[5], •[13], 0, 0, 2, display->white, ZP);
	line(screen, •[4], •[12], 0, 0, 2, display->white, ZP);
	line(screen, •[6], •[14], 0, 0, 2, display->white, ZP);
	line(screen, •[7], •[15], 0, 0, 2, display->white, ZP);
}
void
main(int, char**){
	Font *vga№1;
	Image *img, *words, *ant[8];
	Point o;
	Rectangle r, ☐;
	uchar *a, *b;
	double θ = PI / 4;
	int i, j, wctl, p[2];
	short m;
	vlong t = 0;
	char bekindrewind[] = "resize -r ................................................";
	uchar dblwid[16] = {
		0x00, 0x03, 0x0c, 0x0f, 0x30, 0x33, 0x3c, 0x3f,
		0xc0, 0xc3, 0xcc, 0xcf, 0xf0, 0xf3, 0xfc, 0xff
	};
	srand(nsec() ^ 9);
	if(initdraw(nil, nil, "RIP mycroftiv") < 0) sysfatal("initdraw: %r");
	if((wctl = open("/dev/wctl", ORDWR)) < 0) sysfatal("open: %r");
	read(wctl, bekindrewind + 10, 48);
	write(wctl, "resize -r 0 0 9999 9999", 23);
	getwindow(display, Refnone);
	☐ = screen->r;
	if(Dx(☐) < 780 || Dy(☐) < 580) sysfatal("c'mon, at least give me 800x600!");
	vga№1 = openfont(display, "/lib/font/bit/vga/unicode.font");
	if(vga№1 == nil) sysfatal("no vga? blasphemy!");
	if((i = open("/dev/audio", OWRITE)) < 0) sysfatal("open: %r");
	write(1, "r\ti\tm\ne\tn\ty\nq\t\tc\nu\t†\tr\ni\t\to\ne\tp\tf\ns\ta\tt\nc\tc\ti\na\te\tv\nt\n", 56);
	dup(i, 1); close(i);
	if(pipe(p) < 0) sysfatal("pipe: %r");
	switch(fork()){
	case -1:
		sysfatal("fork: %r");
	case 0:
		dup(p[1], 0); close(p[0]); close(p[1]);
		execl("/bin/games/opl3", "opl3", "-r", "16", nil);
		sysfatal("execl: %r");
	}
	close(p[1]);
	for(i = 0; i < 8; i++)
		if((ant[i] = allocimage(display, Rect(0, 0, 48, 48), GREY1, 1, DNofill)) == nil)
			sysfatal("allocimage: %r");
	for(i = 0; i < 288; i++) ■[i] ^= 255;
	loadimage(ant[0], ant[0]->r, ■, 288);
	↔(■ + 288, ■);
	loadimage(ant[1], ant[1]->r, ■ + 288, 288);
	↕(■ + 4 * 288, ■ + 288);
	loadimage(ant[4], ant[4]->r, ■ + 4 * 288, 288);
	↔(■ + 5 * 288, ■ + 4 * 288);
	loadimage(ant[5], ant[5]->r, ■ + 5 * 288, 288);
	for(a = ■ + 2 * 288, i = 0; i < 6; i++)
		for(j = 0; j < 8; j++)
			for(b = ■ + 40 * 6 + i; b >= ■; b -= 8 * 6)
				*a++ = b[0] << j >> 7 & 1
					| b[6] << j >> 6 & 2
					| b[12] << j >> 5 & 4
					| b[18] << j >> 4 & 8
					| b[24] << j >> 3 & 16
					| b[30] << j >> 2 & 32
					| b[36] << j >> 1 & 64
					| b[42] << j & 128;
	loadimage(ant[2], ant[2]->r, ■ + 2 * 288, 288);
	↕(■ + 3 * 288, ■ + 2 * 288);
	loadimage(ant[3], ant[3]->r, ■ + 3 * 288, 288);
	↔(■ + 6 * 288, ■ + 3 * 288);
	loadimage(ant[6], ant[6]->r, ■ + 6 * 288, 288);
	↕(■ + 7 * 288, ■ + 6 * 288);
	loadimage(ant[7], ant[7]->r, ■ + 7 * 288, 288);
	words = allocimage(display, Rect(0, 0, 352, 128), GREY1, 0, DBlack);
	img = allocimage(display, Rect(0, 0, 512, 1), CMAP8, 1, DNofill);
	if(words == nil || img == nil) sysfatal("allocimage: %r");
	string(words, ZP, display->white, ZP, vga№1, "    purple  chess fish");
	string(words, Pt(0, 16), display->white, ZP, vga№1, "   perfect chance far ");
	string(words, Pt(0, 32), display->white, ZP, vga№1, "   steeple  press wish");
	string(words, Pt(0, 48), display->white, ZP, vga№1, "steep-fact prance war ");
	unloadimage(words, Rect(0, 0, 176, 64), a, 1408);
	b = a + 1408 - 46;
	for(i = 0; i < 1408; i++){
		b += i % 22 ? 2 : 46;
		b[0] = b[44] = dblwid[a[i] >> 4];
		b[1] = b[45] = dblwid[a[i] & 15];
	}
	loadimage(words, words->r, a + 1408, 4 * 1408);
	for(i = 0; i < 48; i++) a[i] = 136; /* light */
	while(i < 96) a[i++] = 102; /* dark */
	while(i < 144) a[i++] = 166; /* purple */
	while(i < 192) a[i++] = 231; /* orange */
	while(i < 240) a[i++] = 159; /* visited */
	while(i < 288) a[i++] = 75; /* target */
	loadimage(img, img->r, a, 512);
	draw(screen, screen->r, display->black, nil, ZP);
	o.x = screen->r.min.x + screen->r.max.x - 8 * 48 >> 1;
	o.y = screen->r.min.y + screen->r.max.y - 8 * 48 >> 1;
	a = □ + 0x8000; b = a + 100;
	for(i = 0; i < 64; a[i++] = 1)
		draw(screen, sq48(o, i), img, nil, Pt(48 * ((i ^ i >> 3) & 1), 0));
	j = lrand() & 63;
	while(9){ /* purplechess */
		a[j] = 0;
		draw(screen, sq48(o, j), img, nil, Pt(144, 0));
		for(i = 0, m = 32; m; m >>= 1)
			if(a[j ^ m]) draw(screen, sq48(o, b[i++] = j ^ m), img, nil, Pt(240, 0));
		if(!i) break;
		r.min = Pt(o.x, o.y - 32);
		r.max = Pt(r.min.x + 160, r.min.y + 32);
		draw(screen, r, words, nil, Pt(0, j << 1 & 0x60));
		r.min.x = r.max.x; r.max.x = r.min.x + 112;
		draw(screen, r, words, nil, Pt(160, j << 3 & 0x60));
		r.min.x = r.max.x; r.max.x = r.min.x + 80;
		draw(screen, r, words, nil, Pt(272, j << 5 & 0x60));
		flushimage(display, 1);
		draw(screen, sq48(o, m = j), img, nil, Pt(192, 0));
		for(j = lrand() & 7; j >= i; j -= i);
		while(i--) if(i != j)
			draw(screen, sq48(o, b[i]), img, nil, Pt(48 * ((b[i] ^ b[i] >> 3) & 1), 0));
		j = b[j];
		if(m & 8){a[64] = 36; a[65] = 252; i = 12;}
		else{a[64] = 32; a[65] = 160; i = 8;}
		if(m & 4) a[64] += i;
		if(m & 2) a[64] += i << 1;
		if(m & 1) a[64] += i << 2;
		for(i = 0; i < 0x10000; i += 4){
			m = (3 * a[64] * t & t >> 7 | 4 * a[64] * t & t >> 2 | a[65] * t & t >> 6 | 9 * a[64] * t & t >> 4)
			^ ((t << 3) * (16 - (t >> 9 & 15)) | t << 3 | t << 2 | t << 1) /* kick */
			+ (t * t * t / (t & 255 | 1) | t + 0x4000 << 1 | t << 2 | t << 3 | t << 4); /* hat */
			■[i] = ■[i | 2] = m >> 4;
			■[i | 1] = ■[i | 3] = m >> 12;
			t++;
		}
		write(1, ■, 0x10000);
	}
	draw(words, words->r, display->black, nil, ZP);
	string(words, ZP, display->white, ZP, vga№1, "cross yr eyes");
	unloadimage(words, Rect(0, 0, 13 * 8, 16), a = ■, 13 * 16);
	b = ■ + 0x8000 - 28;
	for(i = 0; i < 13 * 16; i++){
		b += i % 13 ? 2 : 28;
		b[0] = b[26] = dblwid[a[i] >> 4];
		b[1] = b[27] = dblwid[a[i] & 15];
	}
	loadimage(words, Rect(0, 0, 2 * 13 * 8, 2 * 16), ■ + 0x8000, 4 * 13 * 16);
	a = b = ■;
	for(m = 0xff; m > 7; m >>= 1)
		for(i = 0; i < 1600; i++)
			*b++ = lrand() & m;
	while(b < ■ + 0x10000) *b++ = lrand() & 7;
	enum{
		ANT, WALK⑸,
		TERRA, FORM,
		PATH, WANDER,
		HYPER, CUBE,
		ULTRA, FILTER,
		SHRINK, MARCH,
		GROW, BOUNCE,
		UNPREDICTABLE, ELBOWS
	};
	m = ANT;
	sleep(999);
	write(p[0], □, 10105);
	t = nsec() + 50000000000LL; /* mm. 1–13 */
	while(9){
		if(nsec() > t) m++;
		switch(m){
		case ANT:
			for(i = 0; i < 64; i++) □[i] = 96;
			i = 0;
			m = WALK⑸;
		case WALK⑸:
			sleep(99);
			draw(screen, sq48(o, j), img, nil, Pt(□[j] ^= 240, 0));
			i = □[j] == 96 ? i + 2 & 7 : i + 6 & 7;
			j = j + (i == 0 ? 56 : i == 2 ? 1 : i == 4 ? 8 : 63) & 63;
			draw(screen, sq48(o, j), display->black, ant[i], ZP);
			break;
		case TERRA:
			for(i = 0; i < 256; i++) □[i] = i;
			while(i < 512) □[i++] = 217;
			loadimage(img, img->r, □, 512);
			r = Rect(-4, -4, 4, 4);
			o.x = ☐.min.x + ☐.max.x >> 1;
			o.y = ☐.min.y + ☐.max.y >> 1;
			θ = 0.0;
			t -= 8000000000LL; /* mm. 13–19 (24s) */
		case HYPER:
			t += 10000000000LL; /* mm. 23–31 (32s)*/
		case ULTRA:
			t += 6000000000LL; /* mm. 31–36 (22s)*/
		case PATH:
			t += 16000000000LL; /* mm. 19–23 (16s) */
			m++;
		case FORM: case WANDER: case CUBE: case FILTER:
			sleep(33);
			draw(screen, ☐, display->black, nil, ZP);
			for(i = 14; i < 25; i++){
				for(j = -8; j <= 8; j++)
					draw(screen, rectaddpt(r, addpt(o, terra(j, (a[j] - 8.0) * 0.6, i))), img, nil, Pt(a[j], 0));
				a += 17;
			}
			a -= 170;
			if(m >= WANDER)
				draw(screen, rectaddpt(Rect(-24, 200, 24, 248), o), img, ant[a - ■ & 1], Pt(288, 0));
			if(m >= CUBE){
				draw(screen, rectaddpt(Rect(-24, 200, 24, 248), o), img, ant[a - ■ & 1], Pt(288, 0));
				if(θ > 40.0){
					tesseract(addpt(o, terra(200, 100, 40)), 40 * 15, θ, -0.23);
					tesseract(addpt(o, terra(-200, 100, 40)), 40 * 15, θ, 0.23);
				}else{
					tesseract(addpt(o, terra(200, 100, θ)), θ * 15, θ, -0.23);
					tesseract(addpt(o, terra(-200, 100, θ)), θ * 15, θ, 0.23);
				}
				θ += 0.05;
			}
			if(m == FILTER)
				draw(screen, rectaddpt(Rect(-13 * 8, 70, 13 * 8, 102), o), words, nil, ZP);
			break;
		case SHRINK:
			while(Dx(screen->r) > 48 * 3 && Dy(screen->r) > 48 * 3){
				write(wctl, "resize -maxx -9 -maxy -9", 24);
				getwindow(display, Refnone);
			}
			while(Dx(screen->r) > 48 * 3){
				write(wctl, "resize -maxx -9", 15);
				getwindow(display, Refnone);
			}
			while(Dy(screen->r) > 48 * 3){
				write(wctl, "resize -maxy -9", 15);
				getwindow(display, Refnone);
			}
			j = 3 * 48 + 2 * Borderwidth;
			fprint(wctl, "resize -dx %d -dy %d", j, j);
			getwindow(display, Refnone);
			m = MARCH;
			t += 40000000000LL; /* mm. 37–46 */
			j = 2;
		case MARCH:
			sleep(199);
			switch(j & 6){
			case 2:
				write(wctl, "move -minx +48", 14);
				if(screen->r.max.x < ☐.max.x) break;
				j = 4;
			case 4:
				write(wctl, "move -miny +48", 14);
				if(screen->r.max.y < ☐.max.y) break;
				j = 6;
			case 6:
				write(wctl, "move -minx -48", 14);
				if(screen->r.min.x > ☐.min.x) break;
				j = 0;
			case 0:
				write(wctl, "move -miny -48", 14);
				if(screen->r.min.y > ☐.min.y) break;
				j = 2;
				continue;
			}
			getwindow(display, Refnone);
			draw(screen, screen->r, display->black, ant[j ^= 1], ZP);
			break;
		case GROW:
			i = Dx(☐);
			m = Dy(☐);
			if(i < m) m = i;
			i = m < 512 ? m : 512;
			while(Dx(screen->r) < i){
				write(wctl, "resize -dx +8 -dy +8", 20);
				getwindow(display, Refnone);
			}
			for(a = □; a - □ < 0xfff6;)
				for(i = 0, m = lrand(); i < 30; i += 3)
					*a++ = m >> i & 7;
			a = □; b = ■;
			j >>= 1;
			θ = 0.0;
			t += 34000000000LL; /* mm. 47–55 */
		case BOUNCE:
			sleep(99);
			switch(j){
			case 0: write(wctl, "move -minx +28 -miny -28", 24); break;
			case 1: write(wctl, "move -minx +28 -miny +28", 24); break;
			case 2: write(wctl, "move -minx -28 -miny +28", 24); break;
			case 3: write(wctl, "move -minx -28 -miny -28", 24); break;
			}
			getwindow(display, Refnone);
			if(screen->r.min.y == ☐.min.y || screen->r.max.y == ☐.max.y) j ^= 1;
			if(screen->r.max.x == ☐.max.x || screen->r.min.x == ☐.min.x) j ^= 3;
			for(i = 0; i < 0x10000; i++){
				m = a[i] + 1 & 7;
				b[i] = (a[i - 512 & 0xffff] == m)
					+ (a[i - 256 & 0xffff] == m)
					+ (a[i + 1 & 0xffff] == m)
					+ (a[i + 2 & 0xffff] == m)
					+ (a[i + 256 & 0xffff] == m)
					+ (a[i + 512 & 0xffff] == m)
					+ (a[i - 1 & 0xffff] == m)
					+ (a[i - 2 & 0xffff] == m)
					& 2 ? m : a[i];
			}
			r.max.x = screen->r.max.x;
			for(r.min = screen->r.min; r.min.y < screen->r.max.y; r.min.y = r.max.y){
				r.max.y = r.min.y + 2;
				for(i = 0; i < 512; i += 2)
					a[i] = a[i | 1] = *b++;
				loadimage(img, img->r, a, 512);
				draw(screen, r, img, nil, ZP);
			}
			if(a == ■){a = □; b = ■;}
			else{a = ■; b = □;}
			o.x = screen->r.min.x + screen->r.max.x >> 1;
			o.y = screen->r.min.y + screen->r.max.y >> 1;
			tesseract(o, 800.0, θ += 0.05, 0.0);
			m = BOUNCE;
			break;
		case UNPREDICTABLE:
			o.x = screen->r.min.x + screen->r.max.x >> 1;
			for(a = □; a - □ < 0xfff6;)
				for(i = 0, j = lrand(); i < 30; i += 3)
					*a++ = j >> i & 7;
			a = □; b = ■;
		case ELBOWS + 1: case ELBOWS + 3: case ELBOWS + 5:
			t += 12000000000LL; /* mm. 55–66 */
			m++;
		case ELBOWS: case ELBOWS + 2: case ELBOWS + 4: case ELBOWS + 6:
			sleep(99);
			for(i = 0; i < 0x10000; i++){
				j = a[i] + 1 & 7;
				b[i] = (a[i - 512 & 0xffff] == j)
					+ (a[i - 256 & 0xffff] == j)
					+ (a[i + 1 & 0xffff] == j)
					+ (a[i + 2 & 0xffff] == j)
					+ (a[i + 256 & 0xffff] == j)
					+ (a[i + 512 & 0xffff] == j)
					+ (a[i - 1 & 0xffff] == j)
					+ (a[i - 2 & 0xffff] == j)
					& 2 ? j : a[i];
			}
			r.max.x = screen->r.max.x;
			for(r.min = screen->r.min; r.min.y < screen->r.max.y; r.min.y = r.max.y){
				r.max.y = r.min.y + 2;
				for(i = 0; i < 512; i += 2)
					a[i] = a[i | 1] = m << 4 | *b++;
				loadimage(img, img->r, a, 512);
				draw(screen, r, img, nil, ZP);
			}
			if(a == ■){a = □; b = ■;}
			else{a = ■; b = □;}
			o.y = screen->r.min.y + 60;
			ellipse(screen, o, 40, 50, 4, display->white, ZP);
			o.y += 250;
			line(screen, o, Pt(o.x, o.y - 200), 0, 0, 4, display->white, ZP);
			line(screen, o, Pt(o.x - 40, o.y + 200), 0, 0, 4, display->white, ZP);
			line(screen, o, Pt(o.x + 40, o.y + 200), 0, 0, 4, display->white, ZP);
			o.y -= 170;
			i = lrand();
			r.min = subpt(o, Pt(40 + (i & 32), -80));
			r.max = addpt(o, Pt(40 + (i >> 9 & 32), 80));
			line(screen, o, r.min, 0, 0, 4, display->white, ZP);
			line(screen, o, r.max, 0, 0, 4, display->white, ZP);
			line(screen, Pt(o.x - 40, o.y + 160), r.min, 0, 0, 4, display->white, ZP);
			line(screen, Pt(o.x + 40, o.y + 160), r.max, 0, 0, 4, display->white, ZP);
			break;
		default:
			write(wctl, bekindrewind, sizeof(bekindrewind));
			exits(nil);
		}
		flushimage(display, 1);
	}
}

