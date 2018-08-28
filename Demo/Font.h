#pragma once

#include <string>
#include <d3dx9.h>
#include "DeviceDependent.h"


class Font : public DeviceDependent
{
	LPD3DXFONT dxfont;
	int size;

	void Initial(LPDIRECT3DDEVICE9 device);
	void Release();
public:
	Font(LPDIRECT3DDEVICE9 device, int size=16);
	~Font();
	
	// Унаследовано через IDeviceDependent
	virtual void BeforeReset(LPDIRECT3DDEVICE9 device) override;
	virtual void AfterReset(LPDIRECT3DDEVICE9 device) override;

	void Draw(std::string text, RECT rect);
};

