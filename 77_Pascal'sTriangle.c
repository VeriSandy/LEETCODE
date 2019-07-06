/*



*/

int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    int **a = malloc(sizeof(int *)*numRows);
    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof(int)*numRows);
    
    int i = 0, j = 0;

    for(i = 0; i < numRows; i++)
    {
        a[i] = malloc(sizeof(int)*(i+1));
        (*returnColumnSizes)[i] = i+1;
    }

    if(numRows == 0)
        return a;
    
    if(numRows == 1)
    {
        a[0][0] = 1;
        return a;
    }
    
    a[0][0] = 1;
    a[1][0] = 1;
    a[1][1] = 1;
    
    if(numRows == 2)
        return a;
    
    for(i = 2; i < numRows; i++)
    {
        a[i][0] = 1;
        a[i][i] = 1;
        for(j = 1 ; j < i ; j++)
            a[i][j] = a[i-1][j-1] + a[i-1][j];
    }
    
    return a;
}
