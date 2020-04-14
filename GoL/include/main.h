/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Global constants */
#define KEY_1 49 
#define KEY_2 50 
#define KEY_3 51 
#define KEY_4 52
#define KEY_5 53
#define KEY_6 54
#define KEY_7 55
#define ENTER 10

#define MIN_RAND 0
#define MAX_RAND 2
#define MIN_RAND_DEATH 0
#define MAX_RAND_DEATH 100

#define BOARD_WIDTH 50 //100 max
#define BOARD_HEIGHT 25 //75 max

#define UP_ARROW 450
#define DOWN_ARROW 456

#define DEFAULT 1
#define LIVE 2
#define INFECTED 3

//MENU
#define ARRAY_SIZE 1000
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

/* Global structures */
struct cell{

int current;  /* current situation, which is visible on screen */
int future;   /* temporary calculation area for next round calculation */
int generation;

};

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
void RandBoard(struct cell start[BOARD_HEIGHT][BOARD_WIDTH]);
int CountNeighbour(struct cell Neighbour[BOARD_HEIGHT][BOARD_WIDTH],int cRow, int cCol);
void EvalFutureBoard(struct cell FutBoard[BOARD_HEIGHT][BOARD_WIDTH]);
void Spawn_virus_cells(struct cell SpawnVirus[BOARD_HEIGHT][BOARD_WIDTH]);
void ClearVirus(struct cell board[BOARD_HEIGHT][BOARD_WIDTH]);
void Drawboard(struct cell Drawboard[BOARD_HEIGHT][BOARD_WIDTH]);
int Checkinfected(struct cell infected[BOARD_HEIGHT][BOARD_WIDTH],int cRow, int cCol);
void kokgalaxy(struct cell galaxy[BOARD_HEIGHT][BOARD_WIDTH]);
int Navigation(void);

