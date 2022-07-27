#include "stdafx.h"

CCursor::CCursor(DWORD address)
{
}

CCursor::~CCursor()
{
}

void CHack::Init()
{
	FindGameWindows();
	controller = new Controller(_instance);
}

void CHack::FindGameWindows()
{
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);
	HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (Process32First(snap, &pe) == TRUE)
	{
		if (!_wcsicmp(pe.szExeFile, CMemory::exeName.c_str()))
		{
			_instance.push_back(new PrimaryInstance(OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe.th32ProcessID), pe.th32ProcessID));
		}
		else
		{
			while (Process32Next(snap, &pe) == TRUE)
			{
				if (!_wcsicmp(pe.szExeFile, CMemory::exeName.c_str()))
				{
					_instance.push_back(new PrimaryInstance(OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe.th32ProcessID), pe.th32ProcessID));
				}
			}
		}
	}
	CloseHandle(snap);
}

void CHack::Tick()
{
	//_instance[0]->Update();
	gui.Setup(_instance[0]->getLocalPlayer(),_instance[0]->getAlive(), _instance[0]->getCorpse(), _instance[0]->getCollectable());
	d3d.BeginRender();
	gui.Render();
	d3d.EndRender();
	
	//_instance[0]->Loot(L"Wasteland Coyote");
	//Bot(L"", 6);
	
	//controller->Follower();
}

void CHack::Bot(wstring name, int distance)
{
	switch (botState)
	{
	case BOT_INIT:
		if (_instance[0]->InitTarget(name, distance))
		{
			botState = BOT_COMBAT;
		}
		break;
	case BOT_COMBAT:
		if (!_instance[0]->Attack())
		{
			botState = BOT_LOOT;
		}
		
		break;
	case BOT_WAITING:	
		if (TRUE)
		{
		}
		botState = BOT_LOOT;
		break;
	case BOT_LOOT:
		if (!_instance[0]->Loot())
		{
			botState = BOT_FINAL;
		}
		break;
	case BOT_FINAL:
		if (!_instance[0]->EndLoot())
		{
			botState = BOT_INIT;
		}
		break;
	default:
		break;
	}
}

CHack::CHack(CWindow& wnd) : wnd(wnd) , d3d(wnd.getHwnd()), gui(wnd.getHwnd(), d3d.getDevice())
{
	
}

CHack::~CHack()
{

}
