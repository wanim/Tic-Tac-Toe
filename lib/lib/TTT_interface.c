/**
* @file     TTT_interface.c
* @brief    This file contain source codes for Tic-Tac-Toe game interface.
*/

#include "TTT_interface.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <windows.h>

const char *erridx[] =
{
    "\n",
    "Incorrect input!\n",
    "This place is already occupied. Try another!\n",
    "Congratulations. You win!\n",
    "You lose!\n",
    "Dead heat!\n"
};

enum { M_NOERROR = 0, M_INCORRECT_INPUT, M_INCORRECT_PLACE, M_WIN, M_LOSE, M_DEAD_HEAT };

void redraw_tab(GsT* gs)
{
    printf("%c | %c | %c", gs->ptable[0], gs->ptable[1], gs->ptable[2]);
    printf("\n- - - - -\n");
    printf("%c | %c | %c", gs->ptable[3], gs->ptable[4], gs->ptable[5]);
    printf("\n- - - - -\n");
    printf("%c | %c | %c\n", gs->ptable[6], gs->ptable[7], gs->ptable[8]);
}

void draw_instr(GsT* gs)
{
    system("cls");
    printf("%s %s %s %c\n\n\n", STR_CONTROLS, STR_EXTABLE, STR_SIGN, gs->usrMark);
}

void wellcome(GsT* gs)
{
    printf("%s %s", STR_WELCOME, STR_ENTNAME);
    gets_s((char*)&(gs->name), 32);
    status_init(gs);
}

void draw_menu(GsT* gs)
{
    system("cls");
    printf("Hello, %s\n\n", gs->name);
    printf("%s", STR_MENU);
    printf("%s", erridx[gs->errNum]);
    gs->errNum = M_NOERROR;
}

void print_help()
{
    system("cls");
    printf("%s", STR_HELP);
    system("pause");
}

void get_key(GsT* gs)
{
    char c;
    printf("%s", STR_CHOIS);
    scanf_s(" %c", &(gs->chr), 1);
    while ((c = getchar()) != '\n' && c != EOF);    /* flush everything else */

    switch (gs->chr)
    {
        case '1':
            start_game(gs);
            break;

        case '2':
            print_help();
            break;

        case '0':
            return;

        default:
            gs->errNum = M_INCORRECT_INPUT;
    }
}

void start_game(GsT* gs)
{
    char c;	
    while (1)
    {
        draw_instr(gs);

        if (gs->aiMark == 'x' && gs->errNum < 3)
        {
            ai_turn(gs);
        }

        redraw_tab(gs);

        printf("%s", erridx[gs->errNum]);

        if (gs->errNum > 2)
        {
            status_cleanup(gs);
            system("pause");
            return;
        }
        gs->errNum = M_NOERROR;

        printf("%s", STR_CHOIS);
        scanf_s(" %c", &(gs->chr), 1);
        while ((c = getchar()) != '\n' && c != EOF);    /* flush everything else */

        if (gs->chr < '0' || gs->chr > '9')
        {
            gs->errNum = M_INCORRECT_INPUT;     
        }
        else if (gs->chr == '0')
        {
            status_cleanup(gs);
            return;
        }
        else if (gs->ptable[gs->chr - '0' - 1] != 0)
        {
            gs->errNum = M_INCORRECT_PLACE; 
        }
        else
        {
            user_turn(gs, gs->chr - '0' - 1);

            if (gs->aiMark == 'o' && gs->errNum < 3)
            {
                ai_turn(gs);
            }
        }
    }
}
