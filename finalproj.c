#include <stdio.h>
#include <stdlib.h>
#include "finalproj.h"
void setPlayerInformation(PlayerInformation* player){
   char name[100];
   printf( "Enter a name(no spaces):");
   scanf("%s",name);
   strcpy(player->name,name);
   char color[100];
   printf( "Enter a color :");
   scanf("%s",color);
   strcpy(player->color,color);
} 
int** initializeTournament(int numRows){
    int numColumns = 2;
    int r = numRows;
    int c = numColumns; 
    int **arr = (int **)malloc(r * sizeof(int*)); 
    for (int i = 0;i < r;i++){
        arr[i] = malloc(c*sizeof(int));
    } 
    for (int i = 0; i <  r; i++){ 
      for (int j = 0; j < c; j++){ 
         //*(arr + i*c + j) = 0; 
         arr[i][j] = 0;
       }
    }
    return arr;
}
void createDisplayArea(PlayerInformation player){
    printf("\
    ------------------\n\
    |       %s        |\n\
    |-----------------|\n\
    |                 |\n\
    |       %s        |\n\
    |                 |\n\
    |                 |\n\
    -------------------\n",&player.name,&player.color);

} 
int playerTurn(int r){
    printf("Enter a valid column");
    int column=0;
    scanf("%d",&column);
    while (column <= 0 || column > r){
        printf("Error, invalid column");
        scanf("%d",&column);
    }
    return column;
}
void updateBoard(int** gameArray,int r,int userColumn,int currentPlayer){
    int initialRow = r-1;
    int playerChit;
    int currentColumn = userColumn - 1;
    if(currentPlayer == 1){
        playerChit = 1;
    }
    else{
        playerChit = 2;
    }
    
    while (initialRow >= 0){
        if(gameArray[initialRow][currentColumn] == 1 || gameArray[initialRow][currentColumn] == 2){
            initialRow = initialRow - 1;  
        }
        else{
            gameArray[initialRow][currentColumn] = playerChit; 
            break;
        } 
    }
} 
char** formatViewArray(int** gameArray,int r, int c,PlayerInformation player1,PlayerInformation player2){
    char **formatView = (char **)malloc(r * sizeof(char*)); 
    for (int i = 0;i < r;i++){
        formatView[i] = malloc(c*sizeof(char));
    } 
    for (int i = 0; i <  r; i++){ 
      for (int j = 0; j < c; j++){  
         formatView[i][j] = 'E';
       }
    }
    for (int i = 0; i <  r; i++){ 
      for (int j = 0; j < c; j++){ 
         if (gameArray[i][j] == 1){
             formatView[i][j] = player1.color[0];
         } 
         else if (gameArray[i][j] == 2){
             formatView[i][j] = player2.color[0];
            } 
         else{
             formatView[i][j] = 'E';
         }
      }
    }
    return formatView;
} 
void display5x5GameBoard(char** formatView){
  
    printf("\
     -------- -------- -------- -------- -------- \n\
    |        |        |        |        |        |\n\
    |   %c   |   %c   |   %c   |   %c   |   %c   |\n\
     -------- -------- -------- -------- -------- \n\
    |        |        |        |        |        |\n\
    |   %c   |   %c   |   %c   |   %c   |   %c   |\n\
     -------- -------- -------- -------- -------- \n\
    |        |        |        |        |        |\n\
    |   %c   |   %c   |   %c   |   %c   |   %c   |\n\
     -------- -------- -------- -------- -------- \n\
    |        |        |        |        |        |\n\
    |   %c   |   %c   |   %c   |   %c   |   %c   |\n\
     -------- -------- -------- -------- -------- \n\
    |        |        |        |        |        |\n\
    |   %c   |   %c   |   %c   |   %c   |    %c  |\n\
     -------- -------- -------- -------- -------- \n",formatView[0][0],formatView[0][1],\
     formatView[0][2],formatView[0][3],formatView[0][4],formatView[1][0],formatView[1][1],\
     formatView[1][2],formatView[1][3],formatView[1][4],formatView[2][0],formatView[2][1],\
     formatView[2][2],formatView[2][3],formatView[2][4],formatView[3][0],formatView[3][1],\
     formatView[3][2],formatView[3][3],formatView[3][4],formatView[4][0],formatView[4][1],\
     formatView[4][2],formatView[4][3],formatView[4][4]);
}
void display6x6GameBoard(char** formatView){
  
    printf("\
     -------- -------- -------- -------- -------- -------- \n\
    |        |        |        |        |        |        |\n\
    |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |\n\
     -------- -------- -------- -------- -------- -------- \n\
    |        |        |        |        |        |        |\n\
    |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |\n\
     -------- -------- -------- -------- -------- -------- \n\
    |        |        |        |        |        |        |\n\
    |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |\n\
     -------- -------- -------- -------- -------- -------- \n\
    |        |        |        |        |        |        |\n\
    |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |\n\
     -------- -------- -------- -------- -------- -------- \n\
    |        |        |        |        |        |        |\n\
    |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |\n\
     -------- -------- -------- -------- -------- -------- \n\
    |        |        |        |        |        |        |\n\
    |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |\n\
     -------- -------- -------- -------- -------- -------- \n",\
     formatView[0][0],formatView[0][1],formatView[0][2],formatView[0][3],formatView[0][4],formatView[0][5],\
     formatView[1][0],formatView[1][1],formatView[1][2],formatView[1][3],formatView[1][4],formatView[1][5],\
     formatView[2][0],formatView[2][1],formatView[2][2],formatView[2][3],formatView[2][4],formatView[2][5],\
     formatView[3][0],formatView[3][1],formatView[3][2],formatView[3][3],formatView[3][4],formatView[3][5],\
     formatView[4][0],formatView[4][1],formatView[4][2],formatView[4][3],formatView[4][4],formatView[4][5],\
     formatView[5][0],formatView[5][1],formatView[5][2],formatView[5][3],formatView[5][4],formatView[5][5]);
} 
int testForWin(int** gameArray,int r, int c){
    int rowCount = 0;
    for (int i = 0; i <  r; i++){ 
      for (int j = 0; j < c; j++){ 
         if(gameArray[i][j] == 1 || gameArray[i][j] == 2){
             rowCount++;
         }
      }
      if (rowCount >= 4){
          break;
      }
      else{
          rowCount = 0;
      }
    }
    int columnCount = 0; 
    for (int i = 0; i <  c; i++){ 
      for (int j = 0; j < r; j++){ 
         if(gameArray[j][i] == 1 || gameArray[j][i] == 2){
             columnCount++;
         }
      }
      if (columnCount >= 4){
          break;
      }
      else{
          columnCount = 0;
      }
    }
    if(rowCount >= 4 || columnCount >= 4){
        return 1;
    }
    else{
        return 0;
    }
}
int computerTurn(int** gameArray,int r, int c){
    int rowCount = 0;
    for (int i = 0; i <  r; i++){ 
      for (int j = 0; j < c; j++){ 
         if(gameArray[i][j] == 1 || gameArray[i][j] == 2){
             rowCount++;
             if(rowCount >= 3){
                return j+1;
            }
         }
      }
    if (rowCount >= 4){
      break;
    }
    else{
        rowCount = 0;
    }
    }
    int columnCount = 0;
    for (int i = 0; i <  c; i++){ 
      for (int j = 0; j < r; j++){ 
         if(gameArray[j][i] == 1 || gameArray[j][i] == 2){
             columnCount++;
             if(columnCount >= 3){
                return i;
            }
         }
        if (columnCount >= 4){
          break;
        }
        else{
          columnCount = 0;
        }
      }
    columnCount = 0;
    }
    return (rand() % r)+1;
}
void displayVictoryMessage(int victory,PlayerInformation currentPlayer){
    if(victory == 1){
        PlayerInformation victor = currentPlayer;
        printf("Player %s wins!!!",&victor.name);
    }
} 
void saveGame(int** gameArray,int r, int c){
    FILE *fileName = fopen("savedGame.txt", "w");
    for (int i = 0; i <  c; i++){ 
      for (int j = 0; j < r; j++){
        fprintf(fileName,"%d",gameArray[i][j]);
    }
}
}