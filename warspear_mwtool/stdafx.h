#pragma once

using namespace std;

#include <iostream>
#include <vector>
#include <string>

//Windows shit
#include <windows.h>
#pragma comment(lib, "ntdll.lib")
#include <TlHelp32.h>
#include <dwmapi.h>
#pragma comment(lib, "dwmapi.lib")
#include <stddef.h>

//DirectX shit
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#include <d3d9.h>
#include <d3dx9.h>

//imgui shit
#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "imgui/imconfig.h"
#include "imgui/imstb_rectpack.h"
#include "imgui/imstb_textedit.h"
#include "imgui/imstb_truetype.h"
#include "imgui/imgui_impl_dx9.h"
#include "imgui/imgui_impl_win32.h"
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>

//Main shit
#include "main.h"
#include "Structures.h"
#include "CMemory.h"
#include "CWindow.h"
#include "CDirectX.h"
#include "CEntity.h"
#include "CTarget.h"
#include "CLocalPlayer.h"
#include "CGameInstance.h"
#include "Controller.h"
#include "CGUI.h"
#include "CHack.h"


