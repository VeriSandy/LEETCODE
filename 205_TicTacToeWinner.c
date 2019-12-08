/*
Draw - when no one is winning.
Pending -> Some palces are still empty and no is winning.
Win -> When some one wins at the end of all inputs.
*/

char * tictactoe(int** moves, int movesSize, int* movesColSize)
{
    int result1 = 0, result2 = 0;
    
    char *out = malloc(8);
    memset(out, 0, 8);
    
    if(movesSize < 5)
    {
        strcpy(out, "Pending");
        return out;
    }
    
    char temp[3][4];
    memset(temp, 0, sizeof(temp));
    
    int i = 0, flag = 0;
    
    while(i < movesSize)
    {
        if(!flag)
        {
            temp[moves[i][0]][moves[i][1]] = 'X';
            flag = 1;
        }
        else
        {
            temp[moves[i][0]][moves[i][1]] = 'O';
            flag = 0;   
        }
        i++;
    }
    
    /*
    int j = 0, k = 0;
    while(j < 3)
    {
        k = 0;
        while(k < 3)
        {
            printf("%c ", temp[j][k]);
            k++;
        }
        printf("\n");
        j++;
    }*/
        
    //Check if A wins.
    //if (1,1) is X then only check diagonals, 1st column, 1st row
    //if (0,0) is X then only check 0th row and 0th column
    //if (2,2) is X then only check 2th row and 2th column
    if(
       temp[1][1] == 'X' && 
           ((temp[1][0] == 'X' && temp[1][2] == 'X')
        || (temp[0][0] == 'X' && temp[2][2] == 'X')
        || (temp[0][2] == 'X' && temp[2][0] == 'X')
        || (temp[0][1] == 'X' && temp[2][1] == 'X'))
        
        ||  temp[0][0] == 'X' && 
            ((temp[0][1] == 'X' && temp[0][2] == 'X')
        ||   (temp[1][0] == 'X' && temp[2][0] == 'X'))
             
        ||  temp[2][2] == 'X' &&
            ((temp[2][0] == 'X' && temp[2][1] == 'X')
        ||   (temp[0][2] == 'X' && temp[1][2] == 'X'))

      )
    {
        result1 = 1;
    }
        
    //Check if B wins
   if(
       temp[1][1] == 'O' && 
           ((temp[1][0] == 'O' && temp[1][2] == 'O')
        || (temp[0][0] == 'O' && temp[2][2] == 'O')
        || (temp[0][2] == 'O' && temp[2][0] == 'O')
        || (temp[0][1] == 'O' && temp[2][1] == 'O'))
        
        ||  temp[0][0] == 'O' && 
            ((temp[0][1] == 'O' && temp[0][2] == 'O')
        ||   (temp[1][0] == 'O' && temp[2][0] == 'O'))
             
        ||  temp[2][2] == 'O' &&
            ((temp[2][0] == 'O' && temp[2][1] == 'O')
        ||   (temp[0][2] == 'O' && temp[1][2] == 'O'))

      )
    {
        result2 = 1;
    }
    
    if((result1 && result2) || (!result1 && !result2))
    {
        if(i == 9)
            strcpy(out, "Draw");
        else
            strcpy(out, "Pending");
        return out;
    }
    else if(result1)
    {
        strcpy(out, "A");
        return out;        
    }
    
    strcpy(out, "B");
    return out;           
}

