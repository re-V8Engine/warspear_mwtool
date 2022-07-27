#include "stdafx.h"

CTarget::CTarget(Entity* entity, CMemory* mem, vector<Entity>* alive, vector<Entity>* corpse) : entity(entity), mem(mem), alive(alive), corpse(corpse)
{
	address = entity->address;
	uid = entity->uid;
	name = entity->name;
}

bool CTarget::Validate()
{
	if (entity->address == address)
		return true;
	else
		mem->Read<Entity>(entity, address);
	return false;
	
}

void CTarget::Update()
{
	system("cls");
	wcout << "State: " << state;
	switch (state)
	{
	case TARGET_ALIVE:
		mem->Read<Entity>(entity, address);
		if (entity->anim == 6)
			state = TARGET_DYING;
		break;
	case TARGET_DYING:
		for (auto _entity : *alive)
		{
			if (_entity.address == address)
			{
				return;
			}
		}
		state = TARGET_DEAD;
		break;
	case TARGET_DEAD:
		for (auto _entity : *corpse)
		{
			if (_entity.name == name)
			{
				if (_entity.Red > 0)
				{
					mem->Read<Entity>(entity, _entity.address);
					prevColor = _entity.Red;
					state = TARGET_LOOTABLE;
					return;
				}
			}
		}
		state = TARGET_FINAL;
		break;
	case TARGET_LOOTABLE:
		if (lootCount < 1)
		{
			break;
		}
		state = TARGET_FINAL;
		break;
	case TARGET_FINAL:
		break;
	default:
		break;
	}
}

bool CTarget::isDying()
{
	if (!isAlive())
		bDying = true;
	return bDying;
}

bool CTarget::hasLoot()
{
	if (lootCount > 0)
	{
		isLootable = true;
	}
	else
		isLootable = false;
	return isLootable;
}
