#include "Font.h"



void Font::Initial(LPDIRECT3DDEVICE9 device)
{
	D3DXCreateFont(device, size, 0, FW_REGULAR, 0, FALSE, RUSSIAN_CHARSET, OUT_TT_ONLY_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_ROMAN, "Consolas", &dxfont);
}

void Font::Release()
{
	if (dxfont) {
		dxfont->Release();
		dxfont = nullptr;
	}
}

Font::Font(LPDIRECT3DDEVICE9 device, int size)
	:size(size)
{
	Initial(device);
}


Font::~Font()
{
	Release();
}

void Font::BeforeReset(LPDIRECT3DDEVICE9 device)
{
	Release();
}

void Font::AfterReset(LPDIRECT3DDEVICE9 device)
{
	Initial(device);
}

void Font::Draw(std::string text, RECT rect)
{
	if (dxfont)
		dxfont->DrawTextA(nullptr, text.c_str(), text.length(), &rect, DT_CENTER | DT_VCENTER, 0xffffffff);
}
