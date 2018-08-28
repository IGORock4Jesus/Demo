#pragma once

#include <d3dx9.h>


class Mesh
{
public:
	Mesh();
	~Mesh();

	void Render(LPDIRECT3DDEVICE9 device);
};

