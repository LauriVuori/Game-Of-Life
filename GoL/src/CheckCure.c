#include "game_of_life.h"

int CheckCure(struct cell Cure[BOARD_HEIGHT][BOARD_WIDTH],int cRow, int cCol){
int row,colum, Mcol, Mrow, Cured;

        for (row = -1; row < 2; row++){
            for (colum = -1; colum < 2; colum++){
                Mrow = (BOARD_HEIGHT + row + cRow) % BOARD_HEIGHT;
                Mcol = (BOARD_WIDTH + colum + cCol) % BOARD_WIDTH;
                
                    if (Cure[Mrow][Mcol].current == 3){
                        Cured = 3;
                        return Cured;
                    }
                    else if (Cure[Mrow][Mcol].current == 1){
                        Cured = 1;
                        return Cured;
                    }
            }
        }
    return 0;
}