#include "window.h"
#include "camera.h"
#include "graphics.h"
#include <windowsx.h>
#include <string>


extern Camera camera;
std::string gLog;


namespace {
	HWND handle;
	LPCSTR windowClass = "Demo Window";
	int width, height;
	D3DXVECTOR2 lastPoint;
	constexpr float MOUSE_SPEED = 0.1f;
	bool isRButtonDown;
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
	case WM_KILLFOCUS:
		stopRendering();
		return 0;
	case WM_SETFOCUS:
		startRendering();
		return 0;

	case WM_RBUTTONDOWN: {
		lastPoint = D3DXVECTOR2(GET_X_LPARAM(l), GET_Y_LPARAM(l));
		isRButtonDown = true;
		return 0;
	}
	case WM_RBUTTONUP: {
		isRButtonDown = false;
		return 0;
	}
	case WM_MOUSEMOVE:
	{
		if (w == MK_RBUTTON && isRButtonDown) {
			D3DXVECTOR2 p(GET_X_LPARAM(l), GET_Y_LPARAM(l));
			D3DXVECTOR2 diff = p - lastPoint;
			lastPoint = p;
			camera.Pitch(diff.y * MOUSE_SPEED);
			camera.Yaw(diff.x * MOUSE_SPEED);
			OutputDebugString(("diff={" + std::to_string(diff.x) + ", " + std::to_string(diff.y) + "}\n").c_str());
		}
	}
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
	width = 600;// GetSystemMetrics(SM_CXSCREEN);
	height = 600;// GetSystemMetrics(SM_CYSCREEN);

	handle = CreateWindow(windowClass, windowClass, WS_POPUPWINDOW, 0, 0, width, height, HWND_DESKTOP, nullptr, hinstance, nullptr);
	if (!handle)
		return false;

	ShowWindow(handle, SW_NORMAL);

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
