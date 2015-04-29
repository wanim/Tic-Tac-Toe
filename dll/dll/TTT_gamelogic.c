/**
* @file		TTT_gamellogic.c
* @brief	This file contain source codes for Tic-Tac-Toe game logic.
*/

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "TTT_gamelogic.h"
#include <string.h>


enum { M_NOERROR, M_INCORRECT_INPUT, M_INCORRECT_PLACE, M_WIN, M_LOSE, M_DEAD_HEAT };


DLL_EXPORT void user_turn(_gs* gs, const uint8_t pos)
	{
		gs->ptable[pos] = gs->usrMark;

		if (chk_win(gs, gs->usrMark) == 1)
		{
			gs->errNum = M_WIN;
		}
		else if (dead_heat(gs))
		{
			gs->errNum = M_DEAD_HEAT;
		}
	}

DLL_EXPORT void ai_turn(_gs* gs)
	{
		int _rand = rand()%9;

		while (gs->ptable[_rand] != 0)
		{
			_rand = rand() % 9;
		}

		gs->ptable[_rand] = gs->aiMark;

		if (chk_win(gs, gs->aiMark) == 1)
		{
			gs->errNum = M_LOSE;
		}
		else if (dead_heat(gs))
		{
			gs->errNum = M_DEAD_HEAT;
		}
	}

DLL_EXPORT void status_cleanup(_gs* gs)
	{
		char temp = gs->usrMark;
		gs->usrMark = gs->aiMark;
		gs->aiMark = temp;
		gs->errNum = 0;
		gs->chr = 0;
		memset(gs->ptable, 0, 9);
	}

DLL_EXPORT void status_init(_gs* gs)
{
	gs->usrMark = 'x';
	gs->aiMark = 'o';
	gs->chr = 0;
	gs->errNum = 0;
	memset(gs->ptable, 0, 9);
}

DLL_EXPORT uint8_t dead_heat(_gs* gs)
	{
		void* pos = memchr(&gs->ptable, 0, 9);

		if (!pos)
		{
			return 1;
		}
		return 0;
	}

DLL_EXPORT uint8_t chk_win(_gs* gs, const uint8_t sign)
	{
	if (sign == (gs->ptable[0] & gs->ptable[1] & gs->ptable[2]) ||
		sign == (gs->ptable[3] & gs->ptable[4] & gs->ptable[5]) ||
		sign == (gs->ptable[6] & gs->ptable[7] & gs->ptable[8]) ||
		sign == (gs->ptable[0] & gs->ptable[3] & gs->ptable[6]) ||
		sign == (gs->ptable[1] & gs->ptable[4] & gs->ptable[7]) ||
		sign == (gs->ptable[2] & gs->ptable[5] & gs->ptable[8]) ||
		sign == (gs->ptable[0] & gs->ptable[4] & gs->ptable[8]) ||
		sign == (gs->ptable[2] & gs->ptable[4] & gs->ptable[6]))
		{
			return 1;
		}
		return 0;
	}
