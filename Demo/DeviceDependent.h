#pragma once

#include <d3d9.h>


// объект, зависящий от устройства
class DeviceDependent
{
public:
	virtual void BeforeReset(LPDIRECT3DDEVICE9 device) = 0;
	virtual void AfterReset(LPDIRECT3DDEVICE9 device) = 0;

	DeviceDependent();
	~DeviceDependent();
};