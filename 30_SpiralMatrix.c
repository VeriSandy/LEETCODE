
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){

    if(matrixSize == 0 || matrixColSize == NULL) 
    {
        *returnSize = 0;
        return NULL;
    }
    
    *returnSize = matrixSize *(*matrixColSize);
    
    int *a = malloc(sizeof(int)*(*returnSize));
    
    int i = 0, j = 0, k = 0;
    int n = 0;
    int r = matrixSize;
    int c = *matrixColSize;
    
    
    while(i < r && j < c)
    {
        //for top row
        for(k = i ; k < c; k++)
            a[n++] = matrix[i][k];
        
        i++; //top row is done
        
        //for right column
        for(k = j+1 ; k < r; k++)
            a[n++] = matrix[k][c-1];
        
        c--; //right column is done
        
        
        //if stil we have any row left
        if(i < r)
        {
            //for bottom row
            for(k = c-1 ; k >= j; k--)
                a[n++] = matrix[r-1][k];
            
            r--; //bottom row is done
        }
        
        //if stil we have any column left
        if(j < c)
        {
            //for left column
            for(k =  r-1 ; k >= i; k--)
                a[n++] = matrix[k][j];

            j++; //left column is done
        }
    }
    
    return a;
}

