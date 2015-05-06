/**
* @file     TTT_interface.h
* @brief    This file contains description, function prototypes and other definitions for Tic-Tac-Toe interface.
*/

#ifndef TTT_INTERFACE_H_INCLUDED
#define TTT_INTERFACE_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>

#define DLL_IMPORT __declspec(dllimport) 

typedef struct _gs
{
    char ptable[9];
    char usrMark;
    char aiMark;
    uint8_t errNum;
    char name[32];
    char chr;
}GsT;

DLL_IMPORT void user_turn(GsT* gs, const uint8_t pos);
DLL_IMPORT void ai_turn(GsT* gs);
DLL_IMPORT void status_cleanup(GsT* gs);
DLL_IMPORT void status_init(GsT* gs);
DLL_IMPORT uint8_t dead_heat(GsT* gs);
DLL_IMPORT uint8_t chk_win(GsT* gs, const uint8_t sign);


#define STR_HELP        "Tic-Tac-Toe is a game for two players, X and O, \nwho take turns marking the spaces in a 3x3 grid. \nThe player who succeeds in placing three respective marks \nin a horizontal, vertical, or diagonal row wins the game.\n\n"
#define STR_CONTROLS    "Keys: \n1-9 \tto choose place for sign \nEnter \tto place sign \n0 \tto stop current game\n\n"
#define STR_EXTABLE     "Places table: \n\n1 | 2 | 3 \n- - - - - \n4 | 5 | 6 \n- - - - - \n7 | 8 | 9\n\n"
#define STR_CHOIS       "My choice: "
#define STR_SIGN        "Your sign for this round is: "
#define STR_WELCOME     "Wellcome to \"Tic-Tac-Toe\" game!\n"
#define STR_ENTNAME     "Please enter your name: "
#define STR_MENU        "Type 1 to start game \nType 2 to see game rules \nType 0 to exit \n\n"

/**
* @brief    Draws key definitions to console
*/
void draw_instr(GsT* gs);

/**
* @brief    Greets user
*/
void wellcome(GsT* gs);

/**
* @brief    Draws menu
*/
void draw_menu(GsT* gs);

/**
* @brief    Prints help to  console
*/
void print_help();

/**
* @brief    Gets command from user
*/
void get_key(GsT* gs);

/**
* @brief    Starts game
*/
void start_game(GsT* gs);


#endif /* TTT_INTERFACE_H_INCLUDED */
