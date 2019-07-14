/*
Game of Life

IDEA -- 
//Use these numbers for inplace
//From 0 to 1 ==>  5
//From 1 to 0 ==> -5
*/

int CountNeighbours(int **board, int i, int j, int m, int n)
{
    int k = 0, count = 0;
    
    int r[] = {-1,-1,0,1,1,1,0,-1};
    int c[] = {0, 1, 1,1,0,-1,-1,-1};
    
    for(k=0; k<8; k++)
    {
        if(i+r[k] >= 0 && i+r[k] < m && j+c[k] >= 0 && j+c[k] < n 
           && (board[i+r[k]][j+c[k]] == 1 || board[i+r[k]][j+c[k]] == -5))
            count++;
    }
    return count;
}

void gameOfLife(int** board, int boardSize, int* boardColSize)
{    
    int i = 0, j = 0, count = 0;
    
    for(i = 0 ; i < boardSize; i++)
    {
        for(j = 0 ; j < *boardColSize; j++)
        {
            count = CountNeighbours(board, i, j, boardSize, *boardColSize);
            
            //printf("count = %d\n", count);
            
            if(board[i][j] == 1 && (count < 2 || count > 3))
                    board[i][j] = -5;
                  
            else if(board[i][j] == 0 && count == 3)
                    board[i][j] = 5;
        }
    }
    
    for(i = 0 ; i < boardSize; i++)
    {
        for(j = 0 ; j < *boardColSize; j++)
        {   
            if(board[i][j] == 5)
                    board[i][j] = 1;
                  
            else if(board[i][j] == -5)
                    board[i][j] = 0;
        }
    }
    return;
}

