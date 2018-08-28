#pragma once

#include <Windows.h>

bool initializeWindow(HINSTANCE hinstance);
void releaseWindow();
void closeWindow();
HWND getWindowHandle();
int getWindowWidth();
int getWindowHeight();
void enterMessageLoop();