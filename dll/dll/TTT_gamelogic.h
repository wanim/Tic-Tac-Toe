/**
* @file		TTT_gamellogic.h
* @brief	This file contains description, function prototypes and other definitions for Tic-Tac-Toe game logic.
*/


#ifndef TTT_GAMELOGIC_H_INCLUDED
#define TTT_GAMELOGIC_H_INCLUDED

#include <stdint.h>

#define DLL_EXPORT __declspec(dllexport)

typedef struct GS
{
	char ptable[9];
	char usrMark;
	char aiMark;
	uint8_t errNum;
	char name[32];
	char chr;
}_gs;

/**
* @brief	Function for user move
*/
DLL_EXPORT void user_turn(_gs* gs, const uint8_t pos);

/**
* @brief	Function for computer move
*/
DLL_EXPORT void ai_turn(_gs* gs);

/**
* @brief	Makes clean-up of game status, exchanges signs for user and pc
*/
DLL_EXPORT void status_cleanup(_gs* gs);

/**
* @brief	Makes initialization of game status structure
*/
DLL_EXPORT void status_init(_gs* gs);

/**
* @brief	Checks if dead heat situation is present
* @return	1	if present
* @return	0	if not
*/
DLL_EXPORT uint8_t dead_heat(_gs* gs);

/**
* @brief	Function that checks for win
* @return	1	if win
* @return	0	if not
*/
DLL_EXPORT uint8_t chk_win(_gs* gs, const uint8_t sign);

#endif /* TTT_GAMELOGIC_H_INCLUDED */