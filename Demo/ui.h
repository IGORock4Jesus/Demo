#pragma once

#include <d3dx9.h>

namespace UI
{
	bool Initialize();
	void Release();
	void Render(LPDIRECT3DDEVICE9 device);
}