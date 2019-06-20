//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

//Use first row and column, as memory to keep the value 0 for other columns and rows

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){

    int i = 0, j = 0;
    int rflag = 1, cflag = 1;
    /*
    //for first row
    for(i = 0; i < *matrixColSize; i++)
    {
        if(matrix[0][i] == 0)
        {
            rflag = 0;  
            break;
        }
    }
    //for first column
    for(j = 0; j < matrixSize; j++)
    {
        if(matrix[j][0] == 0)
        {
            cflag = 0;
            break;
        }   
    }
    
    */
        
    for(i = 0; i < matrixSize; i++)
    {
        for(j = 0; j < *matrixColSize; j++)
        {
            if(i == 0 && matrix[0][j] == 0)
                rflag = 0; 
            
            if(j == 0 && matrix[i][0] == 0)
                cflag = 0; 
            
            if(matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    
    for(i = 1; i < matrixSize; i++)
    {
        for(j = 1; j < *matrixColSize; j++)
        {
            if(matrix[0][j] == 0 || matrix[i][0] == 0)
                matrix[i][j] = 0;
        }
    }
    
    if(rflag == 0)
        for(j =  0; j < *matrixColSize; j++)
            matrix[0][j] = 0;
    
    if(cflag == 0)
        for(j =  0; j < matrixSize; j++)
            matrix[j][0] = 0;
    
    return;
}
