#pragma once
#include "stdafx.h"
struct Address
{
	DWORD baseAddress;
	DWORD game;
	DWORD localPlayer;
	DWORD cursor;
	DWORD aliveEntityTree;
	DWORD corpseTree;
	DWORD collectableTree;
	DWORD lootName;
	DWORD lootCount;
};
struct Offset
{
	const DWORD posX = 0x8;
	const DWORD posY = 0xA;
	const DWORD alpha = 0x14;
	const DWORD red = 0x18;
	const DWORD green = 0x1C;
	const DWORD blue = 0x20;
	const DWORD sightDirecion = 0x24;
	const DWORD name = 0x58;
	const DWORD uid = 0xEC;
	const DWORD health = 0xF4;
	const DWORD mana = 0xFC;
	const DWORD state = 0x128;
	const DWORD walkDistance = 0x230;
	const DWORD target = 0x268;
	const DWORD agression = 0x2AC;
};

struct Entity
{
	char pad_0x0000[0x8]; //0x0000
	__int16 posX; //0x0008 
	__int16 posY; //0x000A 
	char pad_0x000C[0x8]; //0x000C
	__int32 Alpha; //0x0014 
	__int32 Red; //0x0018 
	__int32 Green; //0x001C 
	__int32 Blue; //0x0020 
	__int32 lookDirection; //0x0024 
	char pad_0x0028[0x30]; //0x0028
	wchar_t name[20]; //0x0058 
	//char pad_0x0070[0x84]; //0x0070
	char pad_0x0070[0x6C]; //0x0070not correct
	__int16 uid; //0x00EC
	char pad_0x00EE[0x6]; //0x00EE
	__int32 health; //0x00F4 
	char pad_0x00C8[0x4]; //0x00F8
	__int32 mana; //0x00FC 
	char pad_0x0100[0xC]; //0x0100
	__int16 destinatonX;//10C
	__int16 destinatonY;//10E
	char pad_0x110[0x18]; //0x110
	__int32 anim; //0x0128 
	char pad_0x012C[0x4]; //0x012C
	__int32 animDuration; //0x130
	char pad_0x0134[0xFC]; //0x0134
	__int32 moveDistance; //0x0230 
	char pad_0x0234[0x34]; //0x0234
	Entity* targetPtr; //0x0268 
	char pad_0x026C[0x40]; //0x026C
	__int32 isAgressed; //0x02AC 
	DWORD address;

};

struct EntityContainer
{
	EntityContainer* prev; //0x0
	EntityContainer* next1; //0x4
	EntityContainer* next2; //0x8
	char pad1[0x8]; //pad to expand size
	Entity* entity; //0x14
};
