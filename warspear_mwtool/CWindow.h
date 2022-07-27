#pragma once

class CWindow
{
private:
	WNDCLASSEX wcx;
	RECT rect;
	Vector2D pos;
	Vector2D size = Vector2D(1920.0f, 1080.0f);
	MARGINS margin = { -1, -1, -1, -1 };
	HWND hwnd = nullptr;

public:
	CWindow();
	~CWindow();
	bool ProcessMessage();
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
	void Destroy();
	HWND getHwnd() { return hwnd; };
	Vector2D getSize() { return size; };
};