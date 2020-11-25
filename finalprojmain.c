#include "finalproj.h"
#include "finalproj.c"
void main(){
    initializeTournament();
    //Initialize game board model
    int numRows = 0; int numColumns = 0;
    printf("Please enter a size of board: 5X5,6X6, or 8X8");
    scanf("%d %d",&numRows,&numColumns);
    int r = numRows;
    int c = numColumns; 
    int *gameArray = (int *)malloc(r * c * sizeof(int));
    //Allow player selection 
    PlayerInformation player1;
    setPlayerInformation(player1);
    PlayerInformation player2;
    setPlayerInformation(player2);
 
    //Initialize player model
    //char playermodel[2][2]; 
    //Initialize the game loop
    char playagain = 'y';
    while(playagain == 'y'){
        int victory = 0; 
        int currentPlayer = 1;
        while(victory == 0){ 
            int currentColumn = playerTurn();
            updateBoard(gameArray,r,currentColumn,currentPlayer);
            //update column in FormatViewArray
           /*  switch(r) {
                case '5':
                    display5x5GameBoard();
                    break; //optional
                case '6':
                    display6x6GameBoard();
                    break; //optional
                case '8':
                    display8x8GameBoard();
                    break; //optional
            } */
            //UNCOMMENT TO TEST FOR VICTORY//
           /*  int *testArray = (int *)malloc(r * c * sizeof(int)); 
            int i = 0;
            int j = 0; 
            for (i = 0; i < 1; i++){ 
            for (j = 0; j < 4; j++){ 
                   *(testArray + i*c + j) = 1; 
                 }
            } */
            victory = testForWin(gameArray,r,c);

            if(currentPlayer == 1){
                currentPlayer = 2;
            }  
            else{
                currentPlayer = 1;
            }        
        }
        if(currentPlayer == 1){
            displayVictoryMessage(victory,player1); 
        }
        else{
            displayVictoryMessage(victory,player2); 
        }
    }
    //Player turn 

    //Update model with column selection (1s and 0s)
    
    //FormatViewArray 

   

    //Call view to update board 

} 