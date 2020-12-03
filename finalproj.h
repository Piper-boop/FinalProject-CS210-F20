/** changeMe.c
* ==============================================================
* Name: Piper Gray, Fall 2020
* Section: M3/4A
* Project: Final Project - Connect 4
* Description: A game where you connect 4 chits
* Documentation Statement: C3C Jcob Dunn helped me figure out how to pass a 2D array. 
* ==============================================================
* UserManual/Instructions:
*   Simply follow all commands given by the game software.
*   E indicates an empty box
 *
 *  Bonus Features (upto 10 pts) - List here
 *  1) Includes option to restart the game ("Would you like to play again?")
 *  2)
 *  3)
 *
 *  Required Programming Skills (must have 5 of 6):
 *   1) Dynamic Memory Allocation
 *          What you did to meet this req: I have a dynamically allocated board array.
 *              File: (finalprojmain.c)
 *              Line#: (29)
 *   2) Pointers
 *          What you did to meet this req: I use an 2D array of pointers
 *              File:finalprojmain.c
 *              Line#:29
 *   3) File I/O
 *          What you did to meet this req: I have the ability to save the current game array
 *              File:finalprojmain.c
 *              Line#:45
 *   4) Structs
 *          What you did to meet this req: I have two struct identities
 *              File:finalprojmain.c
 *              Line#:19
 *
 *   5) Processing of Array Data
 *          What you did to meet this req: I go through gameArray to test for win.
 *              File:finalproj.c
 *              Line#:154
 *
 *  Required Advanced Programming Skills (1 or more):
 *   1) 2D Dynamic Memory
 *          What you did to meet this req: I have a dynamic array aloocated to track tournament
 *              File: finalproj.c
 *              Line#:14
 *   List any changes or omissions from stated shall requirements (from
 *   your design) also describe any functionality that isn't working.
 *      Requirement changes/omissions:
 *          1)N/A
 *          2)
 *          3)
 *
 *      Errors:
 *          1)There is nothing that is not working but my board display looks a little weird.
 *          2)
 *
 *   How many hours did you spend on this project: 15
 *   How many lines of code did you write in total: 468 (373 made the final cut)
 *
*/

#ifndef FinalFUNCTS_H
#define FinalFUNCTS_H 
#include <stdio.h>
#include <math.h>
#include <string.h> 
typedef struct PlayerInformation_struct {
    char name[50];
    char color[50]; 
} PlayerInformation;


// Function prototypes, constants, etc go here...
void setPlayerInformation(PlayerInformation* player);
int** initializeTournament(int numRows);
void createDisplayArea(PlayerInformation player);
int playerTurn(int r);
void displayVictoryMessage(int victory,PlayerInformation currentPlayer);
int testForWin(int** gameArray,int r, int c);
void updateBoard(int** gameArray,int r,int currentColumn,int currentPlayer);
char** formatViewArray(int** gameArray,int r, int c,PlayerInformation player1,PlayerInformation player2);
void display5x5GameBoard(char** formatView);
void display6x6GameBoard(char** formatView);
int computerTurn(int** gameArray,int r, int c);
void saveGame(int** gameArray,int r, int c);

#endif //FinalFUNCTS_H