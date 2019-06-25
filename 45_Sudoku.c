
/*
generally we need these validations

1. Numbers should be with in 1-9 range, inclusive
2. No repeatition in each row
3. No repeatition in each column
4. No repeatition in each 3x3 matrix
*/

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    
    //column wise validation
    int i = 0, j = 0, k = 0, l = 0;
    int size = 10;
    int hash[size];
    char temp;
    int temp1 = 0;
    int sz = 3;
    
    memset(hash, 0, sizeof(hash));
    
    for(j = 0; j < *boardColSize; j++)
    {
        for(i = 0; i < boardSize; i++)
        {
            temp = board[i][j];
            
            if(temp != '.')
            {
                temp1 = temp - '0';
                
                if(temp1 < 1 && temp1 > 9 )
                    return false;
            
                hash[temp1]++;
            }
        }
        
        for(l = 1; l < size; l++)
        {
            if(hash[l] > 1)
                return false;
        }   
        memset(hash, 0, sizeof(hash));
    }
    
    for(i = 0; i < boardSize; i++)
    {
        for(j = 0; j < *boardColSize;j++)
        {
            temp = board[i][j];
            
            if(temp != '.')
            {
                temp1 = temp - '0';
                
                if(temp1 < 1 && temp1 > 9 )
                    return false;
            
                hash[temp1]++;
            }
        }
        
        for(l = 1; l < size; l++)
        {
            if(hash[l] > 1)
                return false;
        }  
        memset(hash, 0, sizeof(hash));   
    }
    
        
    for(k = 0; k < boardSize; k++)
    {
        for(j = (3*k)%9; j < sz+ (3*k)%9 ;j++)
        {
            for(i = 3*(k/3); i < sz + 3*(k/3) ; i++)
            {
                printf("(%d, %d, %d)\n", i, j, k);
                temp = board[i][j];

                if(temp != '.')
                {
                    temp1 = temp - '0';

                    if(temp1 < 1 && temp1 > 9 )
                        return false;

                    hash[temp1]++;
                }
            }  
        }
                
        for(l = 1; l < size; l++)
        {
            if(hash[l] > 1)
                return false;
        }  
        memset(hash, 0, sizeof(hash));  
    }
    return true;
}


