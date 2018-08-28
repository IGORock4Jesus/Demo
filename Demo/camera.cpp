#include "camera.h"
#include "window.h"
#include "renderer.h"

namespace 
{
	D3DXMATRIX view, proj;
	D3DXVECTOR3 eye{ 0, 10, -100 };
}

void renderCamera(LPDIRECT3DDEVICE9 device) {
	D3DXMatrixLookAtLH(&view, &eye, &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 1, 0));
	D3DXMatrixPerspectiveFovLH(&proj, D3DX_PI * 0.25f, (float)getWindowWidth() / (float)getWindowHeight(), 0.1f, 10000.0f);

	device->SetTransform(D3DTS_VIEW, &view);
	device->SetTransform(D3DTS_PROJECTION, &proj);
}

void initializeCamera() {
	D3DXMatrixLookAtLH(&view, &eye, &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 1, 0));
	D3DXMatrixPerspectiveFovLH(&proj, D3DX_PI * 0.25f, (float)getWindowWidth() / (float)getWindowHeight(), 0.1f, 10000.0f);
}

void moveCamera(D3DXVECTOR3 vector) {
	eye += vector;
}