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
     $game_of_life$ 

 2.  DESCRIPTION

 3.  VERSIONS
       Original:
         $Date$ / $Lauri Vuori$

       Version history:

**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include <ncurses.h>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */


/* Global constants */
#define BASIC 1
#define WIN_TOPBOT '-'
#define WIN_SIDES  '|'
#define WIN_TBLC   '+'
#define WIN_TBRC   '+'

/* Global variables */

/* Global structures */

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
void Start_menu(void);
/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

int main(void){
    initscr (); 
    clear ();   
    nodelay (stdscr, TRUE);	
    
    start_color (); 
    init_pair (BASIC, COLOR_RED, COLOR_BLACK); 
    bkgd (COLOR_PAIR (BASIC)); 
    noecho ();

    Start_menu();


    nodelay (stdscr, FALSE);
    getch ();
    endwin ();

} /* end of main */

/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
void Start_menu(void){
    int choice, highlight = 0;
    int i = 0;
    char choices[10][255] = {
                            "Start game",
                            "exit",
                            
    };

    WINDOW * menuwindow = newwin(15, 15, 15, 15);
    wborder(menuwindow, WIN_SIDES, WIN_SIDES, WIN_TOPBOT, WIN_TOPBOT, WIN_TBLC, WIN_TBLC, WIN_TBRC, WIN_TBRC);
    refresh();
    wrefresh(menuwindow);

    keypad(menuwindow, true);

    while(1){
       
        for (i = 0; i < 2; i++){
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
                
                    if (highlight == -1){ //TODO: ALARAJA
                        highlight = highlight+1;
                    }
                break;
        
            case KEY_DOWN:
                highlight++;
                    
                    if (highlight == 2){ // TODO:YLÄRAJA
                        highlight = highlight-1;
                    }
                break;
        default:
        break;
        }
        if (choice == 10){ // enter
            break;
        }
    }
}
/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/