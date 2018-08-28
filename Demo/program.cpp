#include "window.h"
#include "graphics.h"
#include "ui.h"


int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE, LPSTR, int) {
	initializeWindow(hinstance);
	initializeGraphics();
	UI::Initialize();

	enterMessageLoop();

	UI::Release();
	releaseGraphics();
	releaseWindow();

	return 0;
}


