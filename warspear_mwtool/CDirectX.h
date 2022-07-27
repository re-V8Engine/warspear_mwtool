#pragma once

class CDirectX
{
private:
	IDirect3D9Ex* d3dinterface;
	IDirect3DDevice9Ex* device;
	D3DPRESENT_PARAMETERS params;
	ID3DXLine* line;
	ID3DXFont* font;

public:
	CDirectX(HWND hwnd);
	~CDirectX();

	void BeginRender();
	void EndRender();
	IDirect3DDevice9Ex* getDevice() { return device; };
	void Destroy();

	static constexpr int ScreenWidth = 1920;
	static constexpr int ScreenHeight = 1080;
};
	

