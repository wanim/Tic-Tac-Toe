/**
* @file     TTT_gamellogic.h
* @brief    This file contains description, function prototypes and other definitions for Tic-Tac-Toe game logic.
*/


#ifndef TTT_GAMELOGIC_H_INCLUDED
#define TTT_GAMELOGIC_H_INCLUDED

#include <stdint.h>

#define DLL_EXPORT __declspec(dllexport)

typedef struct _gs
{
    char ptable[9];
    char usrMark;
    char aiMark;
    uint8_t errNum;
    char name[32];
    char chr;
}GsT;

/**
* @brief    Function for user move
*/
DLL_EXPORT void user_turn(GsT* gs, const uint8_t pos);

/**
* @brief    Function for computer move
*/
DLL_EXPORT void ai_turn(GsT* gs);

/**
* @brief    Makes clean-up of game status, exchanges signs for user and pc
*/
DLL_EXPORT void status_cleanup(GsT* gs);

/**
* @brief    Makes initialization of game status structure
*/
DLL_EXPORT void status_init(GsT* gs);

/**
* @brief    Checks if dead heat situation is present
* @return   1   if present
* @return   0   if not
*/
DLL_EXPORT uint8_t dead_heat(GsT* gs);

/**
* @brief    Function that checks for win
* @return   1   if win
* @return   0   if not
*/
DLL_EXPORT uint8_t chk_win(GsT* gs, const uint8_t sign);

#endif /* TTT_GAMELOGIC_H_INCLUDED */