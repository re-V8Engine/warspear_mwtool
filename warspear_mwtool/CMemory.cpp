#include "stdafx.h"

const wstring CMemory::exeName = L"warspear.exe";


BOOL CALLBACK EnumWindowProc(HWND hwnd, LPARAM lParam)
{
	CMemory* memory = (CMemory*)lParam;
	DWORD lpdwProcessId = memory->getPid();
	GetWindowThreadProcessId(hwnd, &lpdwProcessId);
	if (lpdwProcessId == memory->getPid())
	{
		memory->setHWND(hwnd);
		return FALSE;
	}
	return TRUE;
};

void CMemory::UpdateHWND()
{
	EnumWindows(EnumWindowProc, (LPARAM)&(*this));
}

DWORD CMemory::GetBaseAddress()
{
	MODULEENTRY32 me;
	me.dwSize = sizeof(MODULEENTRY32);
	HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, GetProcessId(handle));
	if (Module32First(snap, &me) == TRUE)
	{
		if (!_wcsicmp(me.szModule, exeName.c_str()))
		{
			DWORD moduleAddress = (DWORD)me.modBaseAddr;
			return moduleAddress;
		}
		else
		{
			while (Module32Next(snap, &me) == TRUE)
			{
				if (!_wcsicmp(me.szModule, exeName.c_str()))
				{
					DWORD moduleAddress = (DWORD)me.modBaseAddr;
					return moduleAddress;
				}
			}
		}
	}
	CloseHandle(snap);
	return{ 0 };
}

void CMemory::SendKey(WPARAM key)
{
	int scan = MapVirtualKey(key, 0);
	LPARAM lparam = 0x00000001 | (LPARAM)(scan << 16);
	PostMessage(hwnd, WM_KEYDOWN, key, lparam);
	PostMessage(hwnd, WM_KEYDOWN, key, lparam);
	PostMessage(hwnd, WM_KEYUP, key, 0);
}

CMemory::CMemory()
{

}


void CMemory::Update()
{
	UpdateAddress();
	UpdateHWND();
}

void CMemory::UpdateAddress()
{
	tAddress.baseAddress = GetBaseAddress();
	tAddress.game = tAddress.baseAddress + dwMainOffset;
	tAddress.localPlayer = ReadOffset<DWORD>(tAddress.game, 2, 0x18, 0x34);
	tAddress.cursor = ReadOffset<DWORD>(tAddress.game, 3, 0x18, 0x7A0, 0x66C);
	tAddress.aliveEntityTree = ReadOffset<DWORD>(tAddress.game, 2, 0x18, 0x30);
	tAddress.corpseTree = ReadOffset<DWORD>(tAddress.game, 2, 0x18, 0x3C);
	tAddress.collectableTree = ReadOffset<DWORD>(tAddress.game, 2, 0x18, 0x44);
	tAddress.lootName = ReadOffset<DWORD>(tAddress.game, 5, 0x30, 0xE8, 0x184, 0x4, 0x290);
}

CMemory::~CMemory()
{
}
