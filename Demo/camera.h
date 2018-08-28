#pragma once

#include <d3dx9.h>

void renderCamera(LPDIRECT3DDEVICE9 device);
void initializeCamera();
void moveCamera(D3DXVECTOR3 vector);