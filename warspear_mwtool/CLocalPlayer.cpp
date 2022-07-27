#include "stdafx.h"

void CLocalPlayer::setState()
{
	if (player.anim == 1)
	{
		state = PLAYER_WALKING;
	}
	state = PLAYER_IDLE;
}
