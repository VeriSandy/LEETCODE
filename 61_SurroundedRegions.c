//Visit borders first
//Mark all the reachable O's in this, as visited

//In next visit, mark all non visited O's as X

void SolveUtility(char **board, int i, int j, int m, int n, int vis[m][n])
{
    int r[] = {0, 1,  0, -1};
    int c[] = {1, 0, -1,  0};
    
    vis[i][j] = 1;
    int k = 0;
    
    for(k = 0; k < 4; k++)
    {
        if(i + r[k] >= 0 && i + r[k] < m && j + c[k] >= 0 && j + c[k] < n 
           && vis[i+r[k]][j+c[k]] == 0 && board[i+r[k]][j+c[k]] == 'O')
            
                SolveUtility(board, i+r[k], j+c[k], m, n, vis);        
    }
    
    return;
}

void solve(char** board, int boardSize, int* boardColSize){
    if(boardSize < 3) return;
    int i = 0;
    int j = 0;
    
    int vis[boardSize][*boardColSize];
    memset(vis, 0x00, sizeof(vis));
    
    for(j = 0; j < *boardColSize; j++)
        if(board[0][j] == 'O' && vis[0][j] == 0)
            SolveUtility(board, 0, j, boardSize, *boardColSize, vis);
    
    for(j = 0; j < *boardColSize; j++)
        if(board[boardSize-1][j] == 'O' && vis[boardSize-1][j] == 0)
            SolveUtility(board, boardSize-1, j, boardSize, *boardColSize, vis);
    
    for(i = 0; i < boardSize; i++)
        if(board[i][0] == 'O' && vis[i][0] == 0)
            SolveUtility(board, i, 0, boardSize, *boardColSize, vis);
    
    for(i = 0; i < boardSize; i++)
        if(board[i][*boardColSize-1] == 'O' && vis[i][*boardColSize-1] == 0)
            SolveUtility(board, i, *boardColSize-1, boardSize, *boardColSize, vis);    
    
    
    for(i = 1; i < boardSize; i++)
    {
        for(j = 1; j < *boardColSize; j++)
        {
            if(board[i][j] == 'O' && vis[i][j] == 0)
            {
                board[i][j] = 'X';
                vis[i][j] = 1;
            }
        }
    }
    
    return;
}


