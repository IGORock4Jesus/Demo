#include "window.h"
#include "graphics.h"


int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE, LPSTR, int) {
	initializeWindow(hinstance);
	initializeGraphics();

	enterMessageLoop();

	releaseGraphics();
	releaseWindow();

	return 0;
}


