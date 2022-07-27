#pragma once

enum PlayerState
{
	PLAYER_IDLE,
	PLAYER_WALKING,
	PLAYER_COMBAT,
	PLAYER_LOOT,
	PLAYER_INTERACT,
	PLAYER_CROSSING, //переход на другую локацию
	PLAYER_PASSAGE //переход внутрь помещения, пещеры, etc...
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

