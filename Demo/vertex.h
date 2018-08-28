#pragma once

#include <d3dx9.h>

struct Vertex
{
	D3DXVECTOR3 pos;
	D3DCOLOR color;
};

#define VERTEX_FVF (D3DFVF_XYZ|D3DFVF_DIFFUSE)
#define VERTEX_SIZE (sizeof(Vertex))