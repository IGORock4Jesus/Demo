#include "grid.h"
#include "vertex.h"

namespace
{
	LPDIRECT3DVERTEXBUFFER9 vb;
}



void renderGrid(LPDIRECT3DDEVICE9 device) {
	device->SetFVF(VERTEX_FVF);
	Vertex vs[22];
	for (int i = -5; i <= 5; i++)
	{
		vs[(i + 5) * 2] = { { i * 10.0f, 0.0f, -50.0f}, 0xff000000 };
		vs[(i + 5) * 2 + 1] = { { i * 10.0f, 0.0f, 50.0f}, 0xff000000 };
	}
	device->DrawPrimitiveUP(D3DPT_LINELIST, 11, vs, VERTEX_SIZE);

	for (int i = -5; i <= 5; i++)
	{
		vs[(i + 5) * 2] = { { -50.0f, 0.0f, i * 10.0f}, 0xff000000 };
		vs[(i + 5) * 2 + 1] = { { 50.0f, 0.0f, i * 10.0f}, 0xff000000 };
	}
	device->DrawPrimitiveUP(D3DPT_LINELIST, 11, vs, VERTEX_SIZE);
}
void initializeGrid(LPDIRECT3DDEVICE9 device) {

}