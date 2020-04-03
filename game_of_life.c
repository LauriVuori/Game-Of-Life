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
#include <time.h>
#include <stdlib.h>
//#include <ncurses.h>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */


/* Global constants */
#define MIN_RAND 0
#define MAX_RAND 2

/* Global variables */

/* Global structures */
struct cell{

int current;  /* current situation, which is visible on screen */
int future;   /* temporary calculation area for next round calculation */

};



/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/
/* 3 sääntöä- birth, death, survival
depends neibhpours

0 -> 1 vain jos 3 naapuria on hengissä = 0->1 >3 naapuria
1 -> 0 jos vähemmän kuin 2 hengissä tai enemmän kuin 3 ---- 
*/
int main(void){
srand(time(NULL));
            //   rivi  paikka
            //     y    x
struct cell board [10] [10] = {0, 0};

int row = 0, colum = 0;

  for (row = 0; row < 10; row++){
    for (colum = 0; colum < 10; colum++){
        board[row][colum].current=rand()%MAX_RAND+MIN_RAND;
    }
  }

// print current life
/*************************/
printf("current life\n");
    for (row = 0; row < 10; row++){
        for (colum=0;colum<10;colum++){
            printf("%d", board[row][colum]);
            /*if (board[row][colum].current>0){
                printf("%c", live);
            }
            else{
                printf("%c", empty);
            }*/
        }
        printf("\n");
    }
/*************************/

// print Future life
/*************************/
printf("Future life\n");
    for (row = 0; row < 10; row++){
        for ( colum = 0; colum < 10; colum++){
            printf("%d", board[row][colum]);
            /*if (board[row][colum].future>0){
                printf("%c", live);
            }
            else{
                printf("%c", empty);
            }*/
        }
        printf("\n");
    }

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