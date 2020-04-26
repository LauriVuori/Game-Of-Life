/***************************************************************************
 *   Copyright (C) $Year$ by $Lauri Vuori$   *
 *   $Email$   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************

 1.  NAME
     $Navigation.c$ 

 2.  DESCRIPTION
    Draw menu options
 3.  VERSIONS
       Original:
         $22.4.2020$ / $Lauri Vuori$

       Version history:

**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/

#include "game_of_life.h"

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */
/* Global constants */
#define MIN_MENU_OPTIONS -1
#define MAX_MENU_OPTIONS 2
#define WIN_HEIGHT 25
#define WIN_WIDTH 30
#define WIN_START_Y 0
#define WIN_START_X 120
#define OPTIONS 2
#define WIN_TOPBOT '-'
#define WIN_SIDES  '|'
#define WIN_TBLC   '+'
#define WIN_TBRC   '+'
/* Global variables */
/* Global structures */
/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------*/
/**
 * @fn int Navigation(void)
 * @brief Draw menu options
 * @return Options menu and return selected option
 */
/*********************************************************************/
int Navigation(void){
int choice, highlight = 0;
int i = 0;              
char choices[ARRAY_SIZE][ARRAY_SIZE] = {
                        "Start game with live cells",
                        "exit",
};
WINDOW * menuwindow = newwin(WIN_HEIGHT, WIN_WIDTH, WIN_START_Y, WIN_START_X);

/*print game of life on screen*/
attron(COLOR_PAIR(LIVE));
mvaddstr(5,5, " ______     ______     __    __     ______        ______     ______      __         __     ______   ______");
mvaddstr(6,5, "/\\  ___\\   /\\  __ \\   /\\  -./  \\   /\\  ___\\      /\\  __ \\   /\\  ___\\    /\\ \\       /\\ \\   /\\  ___\\ /\\  ___\\");
mvaddstr(7,5, "\\ \\ \\__ \\  \\ \\  __ \\  \\ \\ \\-./\\ \\  \\ \\  __\\      \\ \\ \\/\\ \\  \\ \\  __\\    \\ \\ \\____  \\ \\ \\  \\ \\  __\\ \\ \\  __\\"); 
mvaddstr(8,5, " \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_\\ \\ \\_\\  \\ \\_____\\     \\ \\_____\\  \\ \\_\\       \\ \\_____\\  \\ \\_\\  \\ \\_\\    \\ \\_____\\");
mvaddstr(9,5, "  \\/_____/   \\/_/\\/_/   \\/_/  \\/_/   \\/_____/      \\/_____/   \\/_/        \\/_____/   \\/_/   \\/_/     \\/_____/");
attroff(COLOR_PAIR(DEFAULT));

    wborder(menuwindow, WIN_SIDES, WIN_SIDES, WIN_TOPBOT, WIN_TOPBOT, WIN_TBLC, WIN_TBLC, WIN_TBRC, WIN_TBRC);
    refresh();
    wrefresh(menuwindow);

    keypad(menuwindow, TRUE);

    while(1){
       
        for (i = 0; i < MAX_MENU_OPTIONS; i++){
            if (i == highlight){
                wattron(menuwindow, A_REVERSE);
            }
            mvwprintw(menuwindow, i+1, 1, choices[i]);
            wattroff(menuwindow, A_REVERSE);

        }
        choice = wgetch(menuwindow);
        
        switch (choice){
            case KEY_UP: 
                highlight--;
                
                    if (highlight == MIN_MENU_OPTIONS){ 
                        highlight = MIN_MENU_OPTIONS+1;
                    }
                break;
        
            case KEY_DOWN: 
                highlight++;
                    
                    if (highlight == MAX_MENU_OPTIONS){ 
                        highlight = MAX_MENU_OPTIONS-1;
                    }
                break;
        default:
            break;
        }
        if (choice == ENTER){ 
            return highlight;
            break;
        }
    }

}