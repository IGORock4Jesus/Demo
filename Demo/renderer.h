#pragma once

#include <string>
#include <d3d9.h>



bool initializeRenderer();
void releaseRenderer();
LPDIRECT3DDEVICE9 getRendererDevice();

LPDIRECT3DDEVICE9 beginRenderScene();
void endRenderScene();

typedef void(*DeviceHandler)(LPDIRECT3DDEVICE9 device);

void registerPreReset(DeviceHandler handler);
void registerPostReset(DeviceHandler handler);