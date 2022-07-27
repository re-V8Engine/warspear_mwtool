#pragma once

enum CursorIcon
{
	CURSOR_CIRCLE,
	CURSOR_HAND,
	CURSOR_SWORD,
	CURSOR_INTERACT,
	CURSOR_CROSS,
	CURSOR_ARROWUP,
	CURSOR_ARROWDOWN,
	CURSOR_ARROWRIGHT,
	CURSOR_ARROWLEFT,
	CURSOR_ARROWCAVE
};

/*
enum PlayerState
{
	PLAYER_STATE_IDLE,
	PLAYER_STATE_WALK,
	PLAYER_STATE_FIGHT,
	PLAYER_STATE_LOOT,
	PLAYER_STATE_INTERACT
};*/

class CCursor
{
private:
	Vector2D pos;
	Vector2D vis_pos;
	__int32 cursor_icon;

public:

	__int32 getCursorIcon() { return cursor_icon; }
	CCursor(DWORD address);
	~CCursor();
};

/*
class Instance
{
private:
	string title;
protected:
	CMemory mem;
	Address* tAddress;

	Entity tLocalPlayer;
	vector<Entity> tAlive;
	vector<Entity> tCorpse;
	vector<Entity> tCollectable;

	int lootCount = 0;

	CTarget* target;
public:
	void Update();
	void UpdateGameObjects(vector<Entity>& list, DWORD tree);
	short CalcDistance(short from_x, short from_y, short to_x, short to_y);
	void Click();
	void MoveCursor();

	bool InitTarget();

	Instance(HANDLE _handle, DWORD _pid);
	~Instance();



};*/
class PrimaryInstance
{
private:
	string title;
	CMemory mem;
	Address* tAddress;

	Entity tLocalPlayer;
	vector<Entity> tAlive;
	vector<Entity> tCorpse;
	vector<Entity> tCollectable;

	int lootCount = 0;

	CTarget* target;
public:

	void Update();
	void UpdateGameObjects(vector<Entity>& list, DWORD tree);
	short CalcDistance(short from_x, short from_y, short to_x, short to_y);

	vector<Entity>* getAlive() { return &tAlive; }
	vector<Entity>* getCorpse() { return &tCorpse; }
	vector<Entity>* getCollectable() { return &tCollectable; }
	Entity* getLocalPlayer() { return &tLocalPlayer; }

	void Click(__int16 x, __int16 y);
	void MoveCursor(__int16 x, __int16 y);

	bool InitTarget(wstring name, int distance);
	bool Attack();
	bool Loot();
	bool EndLoot();

	PrimaryInstance(HANDLE handle, DWORD pid);
	~PrimaryInstance();
};