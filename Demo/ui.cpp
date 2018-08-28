#include "ui.h"
#include "Font.h"
#include "renderer.h"

namespace UI
{
	Font *defaultFont;


	void MainMenu() {

	}
	bool Initialize() {
		defaultFont = new Font(getRendererDevice(), 16);
		MainMenu();

		return true;
	}

	void Release() {
		if (defaultFont) {
			delete defaultFont;
			defaultFont = nullptr;
		}
	}
	void Render(LPDIRECT3DDEVICE9 device)
	{
		if (defaultFont)
			defaultFont->Draw("Привет", { 20, 20, 200, 100 });
	}
}