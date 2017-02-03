#pragma once
#include <d3dx9.h>
#define  DIFFUESE(alpha){D3DCOLOR_ARGB(255,255,255,alpha)}
struct VERTEX2D
{
	float x, y, z;
	float rhw;
	D3DCOLOR diffuse;
	float tu, tv;
};