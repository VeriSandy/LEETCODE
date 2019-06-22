//Use DFS approachm, backtracking mechanism

bool Util(char** board, int i, int j, int boardSize, int* boardColSize, 
           int vis[boardSize][*boardColSize], char *word, int k)
{
    if(strlen(word) == k)
        return true;
    
    if(i >= 0 && j >= 0 && i < boardSize && j < *boardColSize
       && word[k] == board[i][j] && !vis[i][j])
    {    
        printf("%c %d %d %d %c %d\n", word[k], i, j , k, board[i][j], vis[i][j]);
        vis[i][j] = 1;
       
        if(Util(board, i+1, j, boardSize, boardColSize, vis, word, k+1) == true)
            return true;
        
        if(Util(board, i, j+1, boardSize, boardColSize, vis, word, k+1) == true)
            return true;
    
        if(Util(board, i-1, j, boardSize, boardColSize, vis, word, k+1) == true)
            return true;
        
        if(Util(board, i, j-1, boardSize, boardColSize, vis, word, k+1) == true)
            return true;    
        
        //if we reached here means we didnt find thw word
        vis[i][j] = 0;
    
        return false;
    }   
    
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){

    int l = strlen(word);
    
    //printf("%s\n", word);
    
    if(boardSize == 0 || boardColSize == NULL || l == 0 )
    {
        /*//printf("%d %d\n",boardSize, l);
        if(l == 0)
            return true;
        */
        return false;
    }
    
    //if(l == 0) return false;
    
    //printf("%s\n", word);
    
    int vis[boardSize][*boardColSize];
    
    memset(vis, 0x00, sizeof(vis));
    
    int i = 0, j = 0, k = 0;
    
    
    for(i = 0; i < boardSize; i++)
    {
        for(j = 0; j < *boardColSize; j++)
        {
            k = 0;
            if(board[i][j] == word[k] && 
               Util(board, i, j, boardSize, boardColSize, vis, word, k) == true)  
                return true;
        }
    }
    return false;
}


