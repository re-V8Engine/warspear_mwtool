#pragma once

enum TargetState
{
	TARGET_ALIVE,
	TARGET_DYING,
	TARGET_DEAD,
	TARGET_LOOTABLE,
	TARGET_FINAL
};

class CTarget
{
private:
	Entity* entity;
	vector<Entity>* alive;
	vector<Entity>* corpse;

	TargetState state;
	short uid;
	DWORD address;
	wstring name;



	bool bAlive;
	bool bDying = false;
	bool isLootable = false;
	int lootCount = 0;
	int prevColor = 0;

	CMemory* mem;

public:
	CTarget(Entity* entity, CMemory* mem, vector<Entity>* alive, vector<Entity>* corpse);
	bool Validate();
	void Update();
	void SetEntity(Entity* entity) { this->entity = entity; }
	Entity* GetEntity() { return entity; }
	short GetUID() { return uid; }
	DWORD GetAddress() { return address; }
	wstring GetName() { return name; }
	bool isAlive() { return bAlive; };
	void SetAlive(bool value) { bAlive = value; }
	bool isDying();
	void SetDying(bool value) { bDying = value; }
	bool hasLoot();
	void SetLootCount(int value) { lootCount = value; }
	void SetColor(int value) { prevColor = value; }
	int GetLootCount() { return lootCount; }

	TargetState GetState() { return state; };
};