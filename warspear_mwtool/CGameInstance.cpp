#include "stdafx.h"

//attaker pool maybe impl later
/*
void CGameInstance::PushToAttackerPool(wstring name, int distance)
{
	for (auto entity = tAlive.begin(); entity != tAlive.end(); entity++)
	{
		if (entity->name == name)
		{
			if (CalcDistance(tLocalPlayer.posX, tLocalPlayer.posY,
				entity->posX, entity->posY) < distance)
			{
				attackerPool.push_back(&*entity);
			}
		}
	}
	return;
}

void CGameInstance::UpdateAttackerPool()
{
	for (auto entity = tAlive.begin(); entity != tAlive.end(); entity++)
	{
		if ((DWORD)entity->targetPtr == tAddress.localPlayer)
		{
			attackerPool.push_back(&*entity);
		}
	}
} //impl later maybe*/


void PrimaryInstance::Click(__int16 x, __int16 y)
{
	MoveCursor(x, y);
	mem.SendKey(VK_RETURN);
}

void PrimaryInstance::MoveCursor(__int16 x, __int16 y)
{
	int visx = x * 0x180000;
	int visy = y * 0x180000;
	mem.Write<__int16>(&x, tAddress->cursor + 0x8);
	mem.Write<__int16>(&y, tAddress->cursor + 0xA);
	mem.Write<int>(&visx, tAddress->cursor + 0xC);
	mem.Write<int>(&visy, tAddress->cursor + 0x10);
}

bool PrimaryInstance::InitTarget(wstring name, int distance)
{
	for (auto entity = tAlive.begin(); entity != tAlive.end(); entity++)
	{
		if (entity->name == name)
		{
			if (CalcDistance(tLocalPlayer.posX, tLocalPlayer.posY,
				entity->posX, entity->posY) < distance)
			{
				target = new CTarget(&*entity, &mem, &tAlive, &tCorpse);
				return true;
			}
		}
	}
	return false;
}

bool PrimaryInstance::Attack()
{
	if (target)
	{
		if (target->GetState() == TARGET_ALIVE)
		{
			Click(target->GetEntity()->posX, target->GetEntity()->posY);
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool PrimaryInstance::Loot()
{
	if (target->GetState() == TARGET_LOOTABLE)
	{
		Click(target->GetEntity()->posX, target->GetEntity()->posY);
		return false;	
	}
	else if (target->GetState() == TARGET_FINAL)
	{
		return false;
	}
	return true;
}

bool PrimaryInstance::EndLoot()
{
	if (target->GetState() == TARGET_FINAL)
	{
		if (target->hasLoot())
		{
			Click(target->GetEntity()->posX, target->GetEntity()->posY);
			return true;
		}
		delete target;
		target = nullptr;
		return false;
	}
	return true;
}

/*
PrimaryInstance::PrimaryInstance(HANDLE _handle, DWORD _pid) : Instance(_handle, _pid)
{

}*/

/*
PrimaryInstance::~PrimaryInstance()
{
}
*/

PrimaryInstance::PrimaryInstance(HANDLE _handle, DWORD _pid) : mem(_handle, _pid)
{
	mem.Update();
	tAddress = mem.getAddress();
}

PrimaryInstance::~PrimaryInstance()
{

}

short PrimaryInstance::CalcDistance(short from_x, short from_y, short to_x, short to_y)
{
	return sqrt(pow((from_x - to_x), 2) + pow((from_y - to_y), 2));
}

void PrimaryInstance::UpdateGameObjects(vector<Entity>& list, DWORD tree)
{
	DWORD treeTop;
	mem.Read<DWORD>(&treeTop, tree); //update treetop
	EntityCollector collector(&mem);
	collector.CollectEntities((void*)treeTop);
	vector<Entity*>* pEntityList = collector.getEntityList();;
	list.clear();

	if (!pEntityList->empty())
	{
		for (auto pEntity = pEntityList->begin(); pEntity != pEntityList->end(); ++pEntity)
		{
			Entity temp;

			if (mem.Read<Entity>(&temp, (DWORD)*pEntity))
			{
				temp.address = (DWORD)*pEntity;
				list.push_back(temp);
			}
		}
	}
}

void PrimaryInstance::Update()
{
	//Fetch localplayer info
	mem.Read<Entity>(&tLocalPlayer, tAddress->localPlayer);

	//fetch entities
	UpdateGameObjects(tAlive, tAddress->aliveEntityTree);
	UpdateGameObjects(tCorpse, tAddress->corpseTree);
	UpdateGameObjects(tCollectable, tAddress->collectableTree);
	lootCount = mem.ReadOffset<DWORD>(tAddress->game, 5, 0x18, 0x34, 0x364, 0x28, 0x10);
	if (target)
	{
		target->Validate();
		target->SetLootCount(lootCount);
		target->Update();
	}
}
