#include "graphics.h"
#include "renderer.h"
#include "camera.h"
#include <thread>
#include "grid.h"
#include <list>
#include "ui.h"

Camera camera;

namespace
{
	std::thread thread;
	bool runned;
	std::list<DeviceDependent*> dependents;
}

struct Vertex
{
	D3DXVECTOR3 pos;
	D3DCOLOR color;
};

void renderTestPrimitive(LPDIRECT3DDEVICE9 device) {
	device->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE);
	Vertex vs[] = {
		{{-10, 10, 0}, 0xffff0000},
		{{10, 10, 0}, 0xff00ff00},
		{{10, -10, 0}, 0xfff0000f},
		{{-10, -10, 0}, 0xff000ff0},
	};
	device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vs, sizeof(Vertex));
}

void rendering() {
	while (runned)
	{
		auto device = beginRenderScene();

		camera.Render(device);

		renderGrid(device);
		renderTestPrimitive(device);

		UI::Render(device);

		endRenderScene();

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void startRendering() {
	if (runned)return;
	runned = true;
	thread = std::thread(rendering);
}

void stopRendering() {
	if (!runned)return;
	runned = false;
	if (thread.joinable())
		thread.join();
}
void preReset(LPDIRECT3DDEVICE9 device) {
	for (auto d : dependents) {
		d->BeforeReset(device);
	}
}
void postReset(LPDIRECT3DDEVICE9 device) {
	for (auto d : dependents) {
		d->AfterReset(device);
	}
}
bool initializeGraphics() {
	if (!initializeRenderer())
		return false;
	registerPreReset(preReset);
	registerPostReset(postReset);
	startRendering();
	return true;
}

void releaseGraphics()
{
	stopRendering();
	releaseRenderer();
}

void registerDependent(DeviceDependent* dependent) {
	dependents.push_back(dependent);
}
void unregisterDependent(DeviceDependent* dependent) {
	dependents.remove(dependent);
}