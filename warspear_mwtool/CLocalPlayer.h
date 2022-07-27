#pragma once

enum PlayerState
{
	PLAYER_IDLE,
	PLAYER_WALKING,
	PLAYER_COMBAT,
	PLAYER_LOOT,
	PLAYER_INTERACT,
	PLAYER_CROSSING, //������� �� ������ �������
	PLAYER_PASSAGE //������� ������ ���������, ������, etc...
};

class CLocalPlayer
{
private:
	Entity player;
	PlayerState state;
public:
	void setState();
	PlayerState* getState() { return &state; }
};

