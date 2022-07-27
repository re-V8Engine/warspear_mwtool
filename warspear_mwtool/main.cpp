#include "stdafx.h"

/*
DWORD WINAPI GUI(LPVOID PARAMS)
{
	CGUI* ui = new CGUI;
	while (true)
	{
		ui->Render();
		Sleep(1);
	}
	delete ui;
}*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	AllocConsole();
	FILE* file = nullptr;
	freopen_s(&file, "CONIN$", "r", stdin);
	freopen_s(&file, "CONOUT$", "w", stdout);
	setlocale(LC_ALL, "rus");

	cout << "initializing window..." << endl;
	CWindow wnd;

	//CreateThread(0, 0, &GUI, 0, 0, 0);
	CHack hack(wnd);
	hack.Init();
	while (wnd.ProcessMessage())
	{
		hack.Tick();
	}

/*

	CMemory& mem = CMemory::getInstance();
	CHack* hack = new CHack;
	mem.get_handle_pid(hack);*/

	system("pause");
}