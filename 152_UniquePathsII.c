/*
Unique Paths --
1. Paths from start to finish. Use recursion.
    Start from (0,0), move either down or right. When reach to finish line increase count by 1.
    
2. Use DP.
*/
//DP
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize)
{
    if(obstacleGridSize == 0 || *obstacleGridColSize == 0) return 0;
    
    int i = 0, j = 0, count = 0;
    long dp[obstacleGridSize][*obstacleGridColSize];
    memset(dp, 0, sizeof(dp));
    
    dp[0][0] = obstacleGrid[0][0] == 0?1:0;
    
    if(obstacleGrid[obstacleGridSize-1][*obstacleGridColSize-1] == 1 || obstacleGrid[0][0] == 1) return 0;
    
    
    for(i = 1; i < obstacleGridSize; i++)
        if(obstacleGrid[i][0] == 0)
            dp[i][0] = 1;
        else
            break;
    
    for(j = 1; j < *obstacleGridColSize; j++)
        if(obstacleGrid[0][j] == 0)
            dp[0][j] = 1;
        else
            break;
    
    for(i = 1; i < obstacleGridSize; i++)
    {
        for(j = 1; j < *obstacleGridColSize; j++)
        {
            if(obstacleGrid[i-1][j] == 0)
                dp[i][j] = dp[i-1][j]; 
            
            if(obstacleGrid[i][j-1] == 0)
                dp[i][j] += dp[i][j-1];   
        }
    }
    
    printf("%d\n", dp[obstacleGridSize-1][*obstacleGridColSize-1]);
    
    return dp[obstacleGridSize-1][*obstacleGridColSize-1];
}
================================================================
//recursion1
void helper(int **a, int m, int n, int i, int j, int *count)
{
    if(i == m-1 && j == n-1)
    {
        *count += 1;
        return;
    }
    
    if(i+1 >= 0 && i +1 < m && a[i+1][j] == 0)
        helper(a, m, n, i+1, j, count);
    
    if(j+1 >= 0 && j +1 < n && a[i][j+1] == 0)
        helper(a, m, n, i, j+1, count);
    
    return;
}
//recursion2
void helper1(int **a, int m, int n, int i, int j, int *count)
{
    if(i == 0 && j == 0)
    {
        *count += 1;
        return;
    }
    
    if(i-1 >= 0 && i-1 < m && a[i-1][j] == 0)
        helper1(a, m, n, i-1, j, count);
    
    if(j-1 >= 0 && j-1 < n && a[i][j-1] == 0)
        helper1(a, m, n, i, j-1, count);
    
    return;
}


int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize)
{
    if(obstacleGridSize == 0 || *obstacleGridColSize == 0) return 0;
    int i = 0, j = 0, count = 0;
    
    //if(obstacleGrid[i][j] == 0)
    //    helper(obstacleGrid, obstacleGridSize, *obstacleGridColSize, i, j, &count);
    
    //printf("%d\n", count);
    
    count = 0;
    i = obstacleGridSize-1, j = (*obstacleGridColSize)-1;
    
    if(obstacleGrid[i][j] == 0)
        helper1(obstacleGrid, obstacleGridSize, *obstacleGridColSize, i, j, &count);
    
    printf("%d\n", count);
    
    return count;
}

