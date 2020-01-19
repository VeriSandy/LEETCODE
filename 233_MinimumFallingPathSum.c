/*
If (i, j) is selected
then we need to have MIN((i+1, j-1), (i+1, j), (i+1., j+1))
*/

int MIN(int a, int b)
{
    return a<b?a:b;
}

int minFallingPathSumUtil(int **A, int ASize, int *AColSize, int i, int j)
{
    if(i < 0|| j < 0  || j >= *AColSize)  return 0;

    return  A[i][j] + 
                MIN(j-1>=0?minFallingPathSumUtil(A, ASize, AColSize, i-1, j-1):INT_MAX
                , MIN(minFallingPathSumUtil(A, ASize, AColSize, i-1, j)
                , (j+1)<*AColSize?minFallingPathSumUtil(A,ASize,AColSize,i-1, j+1):INT_MAX));
}

int minFallingPathSum(int** A, int ASize, int* AColSize)
{
    int i = 0, j = 0;
    int min = INT_MAX;
    
    //for(i = *AColSize -1; i >= 0; i--)
    //    min = MIN(min, minFallingPathSumUtil(A, ASize, AColSize, ASize -1, i));
    
    
    int dp[ASize][*AColSize];
    memset(dp, 0, sizeof(dp));
    
    for(j = 0; j < *AColSize; j++)
        dp[ASize-1][j] = A[ASize-1][j];
    
    for(i = ASize -2; i >= 0; i--)
    {
        for(j = 0; j < *AColSize; j++)
        {
            dp[i][j] = A[i][j] +
                        MIN((j-1)>=0?dp[i+1][j-1]:INT_MAX, 
                                MIN(dp[i+1][j], 
                                    (j+1)<*AColSize?dp[i+1][j+1]:INT_MAX));
            
            //printf("d[%d][%d] = %d\n", i, j, dp[i][j]);
        }
    }
    
    for(j = 0; j < *AColSize; j++)
    {
        min = MIN(min, dp[0][j]);
    }
    return min;
}
               

