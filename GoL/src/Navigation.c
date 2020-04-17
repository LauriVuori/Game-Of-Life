/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/

#include "main.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:Navigation
 DESCRIPTION: Menu with options, move with arrows
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
int Navigation(void){
    int choice, highlight = 0;
    int i = 0;              
    char choices[ARRAY_SIZE][ARRAY_SIZE] = {
                            "Start game with live cells",
                            "exit",
    };

//print game of life on screen
attron(COLOR_PAIR(LIVE));
mvaddstr(5,5, " ______     ______     __    __     ______        ______     ______      __         __     ______   ______");
mvaddstr(6,5, "/\\  ___\\   /\\  __ \\   /\\  -./  \\   /\\  ___\\      /\\  __ \\   /\\  ___\\    /\\ \\       /\\ \\   /\\  ___\\ /\\  ___\\");
mvaddstr(7,5, "\\ \\ \\__ \\  \\ \\  __ \\  \\ \\ \\-./\\ \\  \\ \\  __\\      \\ \\ \\/\\ \\  \\ \\  __\\    \\ \\ \\____  \\ \\ \\  \\ \\  __\\ \\ \\  __\\"); 
mvaddstr(8,5, " \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_\\ \\ \\_\\  \\ \\_____\\     \\ \\_____\\  \\ \\_\\       \\ \\_____\\  \\ \\_\\  \\ \\_\\    \\ \\_____\\");
mvaddstr(9,5, "  \\/_____/   \\/_/\\/_/   \\/_/  \\/_/   \\/_____/      \\/_____/   \\/_/        \\/_____/   \\/_/   \\/_/     \\/_____/");
attroff(COLOR_PAIR(DEFAULT));

    WINDOW * menuwindow = newwin(WIN_HEIGHT, WIN_WIDTH, WIN_START_Y, WIN_START_X);
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
        if (choice == ENTER){ // enter
            return highlight;
            break;
        }
    }

}