#include "stdafx.h"


void CDirectX::BeginRender()
{
	device->SetRenderState(D3DRS_ZENABLE, false);
	device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	device->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
	device->Clear(NULL, NULL, D3DCLEAR_TARGET, NULL, 1, NULL);
	device->BeginScene();
}
void CDirectX::EndRender()
{
	device->EndScene();
	device->PresentEx(NULL, NULL, NULL, NULL, NULL);
}
void CDirectX::Destroy()
{
	if (line) line->Release();
	if (font) font->Release();
	if (device) device->Release();
	if (d3dinterface) d3dinterface->Release();
}
CDirectX::CDirectX(HWND hwnd)
{
	Direct3DCreate9Ex(D3D_SDK_VERSION, &d3dinterface);
	if (d3dinterface)
	{
		ZeroMemory(&params, sizeof(params));
		params.Windowed = TRUE;
		params.SwapEffect = D3DSWAPEFFECT_DISCARD;
		params.hDeviceWindow = hwnd;
		params.MultiSampleQuality = DEFAULT_QUALITY;
		params.BackBufferFormat = D3DFMT_A8R8G8B8;
		params.BackBufferWidth = CDirectX::ScreenWidth;
		params.BackBufferHeight = CDirectX::ScreenHeight;
		params.EnableAutoDepthStencil = TRUE;
		params.AutoDepthStencilFormat = D3DFMT_D16;
		d3dinterface->CreateDeviceEx(D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			hwnd,
			D3DCREATE_HARDWARE_VERTEXPROCESSING,
			&params,
			0,
			&device);
		if (device)
		{
			D3DXCreateLine(device, &line);
			if (line)
			{
				line->SetAntialias(TRUE);
				D3DXCreateFont(device,
					18,
					NULL,
					FW_NORMAL,
					NULL,
					false,
					DEFAULT_CHARSET,
					OUT_TT_ONLY_PRECIS,
					CLEARTYPE_QUALITY,
					DEFAULT_PITCH,
					L"Calibri",
					&font);
				if (!font)
					MessageBoxW(NULL, L"D3DXCreateFont failed!", L"Fatal Error", MB_OK);
			}
			else
				MessageBoxW(NULL, L"D3DXCreateLine failed!", L"Fatal Error", MB_OK);
		}
		else
			MessageBoxW(NULL, L"CreateDeviceEx failed!", L"Fatal Error", MB_OK);
	}
	else
		MessageBoxW(NULL, L"CreateDeviceEx failed!", L"Fatal Error", MB_OK);
}
CDirectX::~CDirectX()
{
	Destroy();
}