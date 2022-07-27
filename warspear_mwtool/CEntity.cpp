#include "stdafx.h"

EntityCollector::EntityCollector(CMemory* _mem) : mem(_mem)
{
}

void EntityCollector::CollectFromContainer(void* containerAddress)
{
	if (!mem->Read<EntityContainer>(&tLocalContainer, (DWORD)containerAddress))
		return;

	if (tLocalContainer.entity)
	{
		//if (mem.Read<Entity>(&localEntity, (DWORD)localContainer.entity, mem.getHandle()))
		if (find(pEntityList.begin(), pEntityList.end(), tLocalContainer.entity) == pEntityList.end())
		{
			pEntityList.push_back(tLocalContainer.entity);
		}
	}

	EntityContainer* next2 = (tLocalContainer.next2 != tLocalContainer.next1) ? tLocalContainer.next2 : nullptr;

	if (tLocalContainer.next1)
		CollectFromContainer(tLocalContainer.next1);
	if (next2)
		CollectFromContainer(next2);
}

void EntityCollector::CollectEntities(void* headContainer)
{
	pEntityList.clear();

	if (!headContainer)
		return;

	CollectFromContainer(headContainer);
}
