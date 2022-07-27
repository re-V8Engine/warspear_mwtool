#include "stdafx.h"



extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam); //imgui connect


LRESULT CWindow::WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	if (ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam))
		return true;

	switch (msg)
	{
	case WM_PAINT:
		//d3d tick
		//cout << "AMA WM_PAINT!!!!!!!111" << endl;
		return 0;

	case WM_ERASEBKGND:
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default:
		auto val = DefWindowProc(hwnd, msg, wparam, lparam);
		return val;
	}
}

bool CWindow::ProcessMessage()
{
	MSG msg;

	while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		if (msg.message == WM_QUIT)
		{
			return false;
		}
		return true;
	}
	return false;
}

void CWindow::Destroy()
{
	DestroyWindow(hwnd);
	UnregisterClass(wcx.lpszClassName, wcx.hInstance);
}
CWindow::CWindow()
{
	ZeroMemory(&wcx, sizeof(wcx));
	wcx.cbSize = sizeof(wcx);
	wcx.hInstance = GetModuleHandle(NULL);
	wcx.lpfnWndProc = WndProc;
	wcx.lpszClassName = L"AMA DUMMY!";
	wcx.style = CS_HREDRAW | CS_VREDRAW;
	wcx.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);
	if (RegisterClassEx(&wcx))
	{
		hwnd = CreateWindowEx(WS_EX_TOPMOST | WS_EX_LAYERED,
			wcx.lpszClassName,
			wcx.lpszClassName,
			WS_POPUP,
			(int)pos.x,
			(int)pos.y,
			CDirectX::ScreenWidth,
			CDirectX::ScreenHeight,
			NULL,
			NULL,
			wcx.hInstance,
			NULL);
		if (hwnd)
		{
			SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 255, LWA_ALPHA | LWA_COLORKEY);
			ShowWindow(hwnd, 1);
			DwmExtendFrameIntoClientArea(hwnd, &margin);
		}

	}
}
CWindow::~CWindow()
{
	Destroy();
}