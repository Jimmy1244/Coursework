#ifndef BGR_H
#define BGR_H

#pragma pack(push)
#pragma pack(1)
typedef struct ssBGR {
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char pad;
} sBGR;
typedef sBGR *pBGR;
#pragma pack(pop)

#endif