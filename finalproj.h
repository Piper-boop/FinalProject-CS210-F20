
/** labXX.c
* ===========================================================
* Name: Name, Date
* Section:
* Project: 
* Purpose: 
* ===========================================================
*/


// *** function header example *** //
/**   ----------------------------------------------------------
* @fn  
* @brief <high level description of purpose of the function>
* @param <explanation of each of the function parameters>
* @return <explanation of what the function returns>
*/ 
// *** header file guard example *** //
#ifndef FinalFUNCTS_H
#define FinalFUNCTS_H 
#include <stdio.h>
#include <math.h>
#include <string.h> 

typedef struct PlayerInformation_struct {
    char name;
    char color; 
} PlayerInformation;


// Function prototypes, constants, etc go here...
PlayerInformation setPlayerInformation(PlayerInformation player);
int* initializeTournament();
void createDisplayArea(PlayerInformation player);
int playerTurn();
void displayVictoryMessage(int victory,PlayerInformation currentPlayer);
int testForWin(int* gameArray,int r, int c);
void updateBoard(int* gameArray,int r,int currentColumn,int currentPlayer);


#endif //FinalFUNCTS_H