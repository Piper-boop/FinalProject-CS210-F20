#include <stdlib.h>
#include <stdio.h>
#include <process.h>
#include "finalproj.h"
void main(){
    //Initialize Tournament
    //FIX ME
    int numGames = 0; 
    printf("How many games would you like to play?");
    scanf("%d",&numGames);
    int** tournamentScore = initializeTournament(numGames);
    int numRows = 0; 
    int numColumns = 0;
    printf("Please enter a size of board: 5 5, or 6 6");
    scanf("%d %d",&numRows,&numColumns);
    int r = numRows;
    int c = numColumns; 
    //Allow player selection 
    PlayerInformation player1;
    setPlayerInformation(&player1);
    PlayerInformation player2;
    setPlayerInformation(&player2);
    createDisplayArea(player1);
    createDisplayArea(player2);
    int gameCount = 0;
    //GAME LOOP
    char playagain = 'y';
    while(playagain == 'y'){
        int **gameArray = (int **)malloc(r * sizeof(int*)); 
        for (int i = 0;i < r;i++){
            gameArray[i] = malloc(c*sizeof(int));
        } 
        for (int i = 0; i < r; i++){ 
            for (int j = 0; j < c; j++){ 
                gameArray[i][j] = 0;
            }
        }
        int victory = 0; 
        char saveGameChar = 'n';
        while(victory == 0){ 
            printf("Would you like to save the game? (y/n)");
            while ((getchar()) != '\n');
            scanf("%c",&saveGameChar);
            if(saveGameChar == 'y'){
                saveGame(gameArray,r,c);
            }
            int currentColumn = playerTurn(r);
            updateBoard(gameArray,r,currentColumn,1);
            char** formatView = formatViewArray(gameArray,r,c,player1,player2);
            printf("%s TURN\n",&player1.name);
            if(r==5){
                 display5x5GameBoard(formatView);
            }
            else{
                 display6x6GameBoard(formatView);
            }
            victory = testForWin(gameArray,r,c);
            if(victory == 1){
                displayVictoryMessage(victory,player1);
                tournamentScore[gameCount][0]=1;
                break;
            }
            currentColumn = computerTurn(gameArray,r,c);
            updateBoard(gameArray,r,currentColumn,2);
            formatView = formatViewArray(gameArray,r,c,player1,player2);
            printf("%s TURN\n",&player2.name);
            if(r==5){
                 display5x5GameBoard(formatView);
            }
            else{
                 display6x6GameBoard(formatView);
            }
            victory = testForWin(gameArray,r,c);
            if(victory == 1){
                displayVictoryMessage(victory,player2);
                tournamentScore[gameCount][1]=1;
            }
        }
    gameCount++;
    if(gameCount >= numGames){
        break;
    }
    printf("Would you like to play again (y/n)");
    while ((getchar()) != '\n');
    scanf("%c",&playagain);
    } 
int player1Count = 0;
int player2Count = 0;
for (int i = 0; i < numGames; i++){ 
    //*(arr + i*c + j) = 0; 
    if(tournamentScore[i][0] == 1){
        player1Count++;
    };
}
for (int i = 0; i < numGames; i++){ 
    //*(arr + i*c + j) = 0; 
    if(tournamentScore[i][1] == 1){
        player2Count++;
    };
}
if(player1Count > player2Count){
    printf("Player %s wins the tournament",&player1.name);
}
else{
    printf("Player %s wins the tournament",&player2.name);
}

system("pause");
}        