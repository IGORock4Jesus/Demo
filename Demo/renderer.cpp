#include "renderer.h"
#include <d3dx9.h>
#include "window.h"
#include "graphics.h"


namespace {
	LPDIRECT3D9 direct;
	LPDIRECT3DDEVICE9 device;
	struct Texture
	{
		std::string filename;
		int id;
	};

}

LPDIRECT3DDEVICE9 beginRenderScene(){
	device->Clear(0, nullptr, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER|D3DCLEAR_STENCIL, 0xff404040, 1.0f, 0);
	device->BeginScene();
	return device;
}

void endRenderScene() {
	device->EndScene();
	device->Present(0, 0, 0, 0);
}

bool initializeRenderer() {
	if (!(direct = Direct3DCreate9(D3D_SDK_VERSION)))
		return false;

	HWND hwnd = getWindowHandle();
	D3DPRESENT_PARAMETERS pp{ 0 };
	pp.BackBufferFormat = D3DFMT_A8R8G8B8;
	pp.BackBufferWidth = getWindowWidth();
	pp.BackBufferHeight = getWindowHeight();
	pp.hDeviceWindow = hwnd;
	pp.Windowed = true;
	pp.AutoDepthStencilFormat = D3DFMT_D24S8;
	pp.EnableAutoDepthStencil = true;
	pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	if (FAILED(direct->CreateDevice(0, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &pp, &device)))
		return false;

	device->SetRenderState(D3DRS_LIGHTING, FALSE);
	// Устанавливаем коэффициенты смешивания таким образом,
	// чтобы альфа-компонента определяла прозрачность
	device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);

	return true;
}

void releaseRenderer() {
	if (device) {
		device->Release();
		device = nullptr;
	}
	if (direct) {
		direct->Release();
		direct = nullptr;
	}
}


LPDIRECT3DDEVICE9 getRendererDevice() {
	return device;
}
