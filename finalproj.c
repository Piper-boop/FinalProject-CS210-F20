#include <stdio.h>
#include <stdlib.h>
#include "finalproj.h"

PlayerInformation setPlayerInformation(PlayerInformation player){
   char name[100];
   printf( "Enter a name(no spaces):");
   scanf("%s",name);
   strcpy(&player.name,name);
   char color[100];
   printf( "Enter a color :");
   scanf("%s",color);
   strcpy(&player.color,color);
   return player;
} 
int* initializeTournament(){
    int numRows = 0; 
    int numColumns = 2;
    printf("How many games would you like to play?");
    scanf("%d",&numRows);
    int r = numRows;
    int c = numColumns; 
    int *arr = (int *)malloc(r * c * sizeof(int)); 
    int i = 0;
    int j = 0; 
    for (i = 0; i <  r; i++){ 
      for (j = 0; j < c; j++){ 
         *(arr + i*c + j) = 0; 
      }
    }
    return arr;
}
void createDisplayArea(PlayerInformation player){
    printf("\
    ------------------\
    |       %s        |\
    |-----------------|\
    |                 |\
    |       %s        |\
    |                 |\
    |                 |\
    -------------------\
    ",&player.name,&player.color);

} 
/* void display5x5GameBoard(){
  
    printf("\
     -------- -------- -------- -------- -------- \
    |        |        |        |        |        |\
    |   %c   |   %c   |   %c   |   %c   |   %c   |\
     -------- -------- -------- -------- -------- \
    |        |        |        |        |        |\
    |   %c   |   %c   |   %c   |    %c  |    %c  |\
     -------- -------- -------- -------- -------- \
    |        |        |        |        |        |\
    |    %c  |    %c  |    %c  |   %c   |    %c  |\
     -------- -------- -------- -------- -------- \
    |        |        |        |        |        |\
    |    %c  |    %c  |    %c  |   %c   |   %c   |\
     -------- -------- -------- -------- -------- \
    |        |        |        |        |        |\
    |    %c  |    %c  |    %c  |    %c  |    %c  |\
     -------- -------- -------- -------- -------- ");
}
void display6x6GameBoard(){
  
    printf("\
     -------- -------- -------- -------- -------- -------- \
    |        |        |        |        |        |        |\
    |   %c   |   %c   |   %c   |   %c   |   %c   |    %c  |\
     -------- -------- -------- -------- -------- -------- \
    |        |        |        |        |        |        |\
    |   %c   |   %c   |   %c   |    %c  |    %c  |   %c   |\
     -------- -------- -------- -------- -------- -------- \
    |        |        |        |        |        |        |\
    |    %c  |    %c  |    %c  |   %c   |    %c  |   %c   |\
     -------- -------- -------- -------- -------- -------- \
    |        |        |        |        |        |        |\
    |    %c  |    %c  |    %c  |   %c   |   %c   |   %c   |\
     -------- -------- -------- -------- -------- -------- \
    |        |        |        |        |        |        |\
    |    %c  |    %c  |    %c  |    %c  |    %c  |   %c   |\
     -------- -------- -------- -------- -------- -------- \
    |        |        |        |        |        |        |\
    |    %c  |   %c   |   %c   |    %c  |   %c   |    %c  |\
     -------- -------- -------- -------- -------- -------- \
  ");
}
void display8x8GameBoard(){
  
    printf("\
     -------- -------- -------- -------- -------- -------- -------- --------\
    |        |        |        |        |        |        |        |        |\
    |   %c   |   %c   |   %c   |   %c   |   %c   |    %c  |   %c   |   %c   |\
     -------- -------- -------- -------- -------- -------- -------- --------\
    |        |        |        |        |        |        |        |        |\
    |   %c   |   %c   |   %c   |    %c  |    %c  |   %c   |    %c  |   %c   |\
     -------- -------- -------- -------- -------- -------- -------- --------\
    |        |        |        |        |        |        |        |        |\
    |    %c  |    %c  |    %c  |   %c   |    %c  |   %c   |    %c  |   %c   |\
     -------- -------- -------- -------- -------- -------- -------- --------\
    |        |        |        |        |        |        |        |        |\
    |    %c  |    %c  |    %c  |   %c   |   %c   |   %c   |   %c   |   %c   |\
     -------- -------- -------- -------- -------- -------- -------- --------\
    |        |        |        |        |        |        |        |        |\
    |    %c  |    %c  |    %c  |    %c  |    %c  |   %c   |    %c  |    %c  |\
     -------- -------- -------- -------- -------- -------- -------- --------\
    |        |        |        |        |        |        |        |        |\
    |    %c  |   %c   |   %c   |    %c  |   %c   |    %c  |   %c   |   %c   |\
     -------- -------- -------- -------- -------- -------- -------- --------\
    |        |        |        |        |        |        |        |        |\
    |    %c  |   %c   |    %c  |    %c  |    %c  |    %c  |   %c   |   %c   |\
     -------- -------- -------- -------- -------- -------- -------- --------\
    |        |        |        |        |        |        |        |        |\
    |    %c  |    %c  |    %c  |   %c   |   %c   |   %c   |    %c  |   %c   |\
     -------- -------- -------- -------- -------- -------- -------- --------");
}  */
int playerTurn(){
    printf("Enter a valid column");
    int column = 0;
    scanf("%d",&column);
    while (column <= 0 || column > 8){
        printf("Error, invalid column");
        scanf("%d",&column);
    }
    return column;
}
void displayVictoryMessage(int victory,PlayerInformation currentPlayer){
    if(victory == 1){
        PlayerInformation victor = currentPlayer;
        printf("Player %s wins!!!",&victor.name);
    }
} 
int testForWin(int* gameArray,int r, int c){
    int rowCount = 0;
    int i = 0;
    int j = 0; 
    for (i = 0; i <  r; i++){ 
      for (j = 0; j < c; j++){ 
         if(*(gameArray + i*c + j) == 0 || *(gameArray + i*c + j) == 0){
             rowCount++;
         }
      }
    }
    int columnCount = 0;
    i = 0;
    j = 0; 
    for (i = 0; i <  c; i++){ 
      for (j = 0; j < r; j++){ 
         if(*(gameArray + i*c + j) == 0 || *(gameArray + i*c + j) == 0){
             columnCount++;
         }
      }
    }
    if(rowCount >= 4 || columnCount >= 4){
        return 1;
    }
    else{
        return 0;
    }
}
void updateBoard(int* gameArray,int r,int currentColumn,int currentPlayer){
    int initialRow = r;
    int playerChit;
    if(currentPlayer == 1){
        playerChit = 0;
    }
    else{
        playerChit = 1;
    }
    int i = 0;
    for (i = 0; i <  r; i++){ 
         if(*(gameArray + i*currentColumn) == 0 || *(gameArray + i*currentColumn) == 1){
           initialRow = initialRow - 1;  
         }
         else{
            *(gameArray + i*currentColumn) = playerChit;
         }
    }
}