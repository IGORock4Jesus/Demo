#include "window.h"
#include "camera.h"

extern Camera camera;

namespace {
	HWND handle;
	LPCSTR windowClass = "Demo Window";
	int width, height;
}

LRESULT CALLBACK WndProc(HWND h, UINT m, WPARAM w, LPARAM l) {
	switch (m)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_KEYDOWN:
		if (w == 0x57)
			camera.Fly(1);
		else if (w == 0x53)
			camera.Fly(-1);
		if (w == 0x41)
			camera.Strafe(-1);
		else if (w == 0x44)
			camera.Strafe(1);
		if (w == 0x52)
			camera.Walk(1);
		else if (w == 0x46)
			camera.Walk(-1);
		return 0;
	default:
		return DefWindowProc(h, m, w, l);
	}
}
bool initializeWindow(HINSTANCE hinstance) {
	WNDCLASS wc{ 0 };
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hInstance = hinstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = windowClass;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wc);
	width = GetSystemMetrics(SM_CXSCREEN);
	height = GetSystemMetrics(SM_CYSCREEN);

	handle = CreateWindow(windowClass, windowClass, WS_POPUPWINDOW, 0, 0, width, height, HWND_DESKTOP, nullptr, hinstance, nullptr);
	if (!handle)
		return false;

	ShowWindow(handle, SW_MAXIMIZE);

	return true;
}
void releaseWindow() {
	handle = nullptr;
}
void closeWindow() {
	CloseWindow(handle);
}
HWND getWindowHandle() {
	return handle;
}
int getWindowWidth() {
	return width;
}
int getWindowHeight() {
	return height;
}
void enterMessageLoop() {
	MSG msg{ 0 };
	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
