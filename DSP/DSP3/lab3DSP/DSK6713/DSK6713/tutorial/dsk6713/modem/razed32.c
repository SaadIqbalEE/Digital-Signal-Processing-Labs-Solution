#include "razedcos.h"

/*************************************
Raised Cosine Shaping Filter (alpha = 0.5, 4 samples/baud)
**************************************/

int raisedCosineTable[SIZE_SHAPING_FILTER] = 
{        /*annie*/
	0x9,
	0x12,
	0x1b,
	0x24,
	0x2d,
	0x36,
	0x3e,
	0x46,
	0x4c,
	0x52,
	0x57,
	0x5b,
	0x5e,
	0x5f,
	0x5f,
	0x5e,
	0x5b,
	0x57,
	0x52,
	0x4c,
	0x45,
	0x3e,
	0x36,
	0x2d,
	0x25,
	0x1d,
	0x15,
	0xe,
	0x8,
	0x4,
	0x1,
	0x0,
	0x1,
	0x4,
	0xa,
	0x13,
	0x1e,
	0x2b,
	0x3c,
	0x4e,
	0x63,
	0x7a,
	0x93,
	0xad,
	0xc8,
	0xe4,
	0xff,
	0x119,
	0x132,
	0x148,
	0x15c,
	0x16b,
	0x177,
	0x17c,
	0x17c,
	0x175,
	0x166,
	0x14f,
	0x12f,
	0x106,
	0xd3,
	0x97,
	0x50,
	0x0,
	0xffffffa7,
	0xffffff43,
	0xfffffed7,
	0xfffffe62,
	0xfffffde6,
	0xfffffd63,
	0xfffffcdc,
	0xfffffc51,
	0xfffffbc4,
	0xfffffb36,
	0xfffffaaa,
	0xfffffa22,
	0xfffff9a0,
	0xfffff925,
	0xfffff8b5,
	0xfffff852,
	0xfffff7fe,
	0xfffff7bc,
	0xfffff78f,
	0xfffff777,
	0xfffff779,
	0xfffff796,
	0xfffff7d1,
	0xfffff82a,
	0xfffff8a5,
	0xfffff943,
	0xfffffa04,
	0xfffffaeb,
	0xfffffbf7,
	0xfffffd2a,
	0xfffffe83,
	0x0,
	0x1a6,
	0x36f,
	0x55c,
	0x76b,
	0x99a,
	0xbe7,
	0xe4e,
	0x10ce,
	0x1362,
	0x1607,
	0x18b9,
	0x1b75,
	0x1e36,
	0x20f7,
	0x23b5,
	0x266a,
	0x2913,
	0x2ba9,
	0x2e2a,
	0x3090,
	0x32d7,
	0x34fa,
	0x36f7,
	0x38c9,
	0x3a6c,
	0x3bde,
	0x3d1c,
	0x3e24,
	0x3ef3,
	0x3f88,
	0x3fe2,
	0x4000,
	0x3fe2,
	0x3f88,
	0x3ef3,
	0x3e24,
	0x3d1c,
	0x3bde,
	0x3a6c,
	0x38c9,
	0x36f7,
	0x34fa,
	0x32d7,
	0x3090,
	0x2e2a,
	0x2ba9,
	0x2913,
	0x266a,
	0x23b5,
	0x20f7,
	0x1e36,
	0x1b75,
	0x18b9,
	0x1607,
	0x1362,
	0x10ce,
	0xe4e,
	0xbe7,
	0x99a,
	0x76b,
	0x55c,
	0x36f,
	0x1a6,
	0x0,
	0xfffffe83,
	0xfffffd2a,
	0xfffffbf7,
	0xfffffaeb,
	0xfffffa04,
	0xfffff943,
	0xfffff8a5,
	0xfffff82a,
	0xfffff7d1,
	0xfffff796,
	0xfffff779,
	0xfffff777,
	0xfffff78f,
	0xfffff7bc,
	0xfffff7fe,
	0xfffff852,
	0xfffff8b5,
	0xfffff925,
	0xfffff9a0,
	0xfffffa22,
	0xfffffaaa,
	0xfffffb36,
	0xfffffbc4,
	0xfffffc51,
	0xfffffcdc,
	0xfffffd63,
	0xfffffde6,
	0xfffffe62,
	0xfffffed7,
	0xffffff43,
	0xffffffa7,
	0x0,
	0x50,
	0x97,
	0xd3,
	0x106,
	0x12f,
	0x14f,
	0x166,
	0x175,
	0x17c,
	0x17c,
	0x177,
	0x16b,
	0x15c,
	0x148,
	0x132,
	0x119,
	0xff,
	0xe4,
	0xc8,
	0xad,
	0x93,
	0x7a,
	0x63,
	0x4e,
	0x3c,
	0x2b,
	0x1e,
	0x13,
	0xa,
	0x4,
	0x1,
	0x0,
	0x1,
	0x4,
	0x8,
	0xe,
	0x15,
	0x1d,
	0x25,
	0x2d,
	0x36,
	0x3e,
	0x45,
	0x4c,
	0x52,
	0x57,
	0x5b,
	0x5e,
	0x5f,
	0x5f,
	0x5e,
	0x5b,
	0x57,
	0x52,
	0x4c,
	0x46,
	0x3e,
	0x36,
	0x2d,
	0x24,
	0x1b,
	0x12,
	0x9
};

