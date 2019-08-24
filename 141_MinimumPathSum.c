/*
Minimum Path Sum --

Idea --
1. 
Min cost would be, min sum cost path out of all paths.
To find the min, use recursion. 

grid[i][j] + min(minPathSumUtilty(grid, m, n, i+1, j), 
                        minPathSumUtilty(grid, m, n, i, j+1))
                        
2. 
Since MinCost(m,n) will end up in recursion like 
MinCost(m, n-1) and MinCost(m-1, n)
After creating tree, there will be some subproblems being solved repeatedly

DP can also be used. 
DP[i][j] is min of matrix (i+1)X(j+1) size.

in general
DP[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j])

*/

int min(int a, int b)
{
    return a>b?b:a;
}

/*
//Recursion
int minPathSumUtilty(int **a, int m, int n, int i, int j)
{
    if(i > m-1 || j > n-1) return INT_MAX;
    
    if(i == m-1 && j == n-1)
        return a[m-1][n-1];
    
    return a[i][j] + min(minPathSumUtilty(a, m, n, i+1, j), 
                        minPathSumUtilty(a, m, n, i, j+1));
}

int minPathSum(int** grid, int gridSize, int* gridColSize)
{
    if(gridSize <= 0 || *gridColSize <= 0)
        return 0;   
    return minPathSumUtilty(grid, gridSize, *gridColSize, 0, 0);
}

*/
//DP
int minPathSum(int** grid, int gridSize, int* gridColSize)
{
    if(gridSize <= 0 || *gridColSize <= 0)
        return 0;
    
    int dp[gridSize][*gridColSize];
    dp[0][0] = grid[0][0];
    
    int i = 0, j = 0;
    
    for(i = 1; i < gridSize; i++)
        dp[i][0] = grid[i][0] + dp[i-1][0];
    
    for(i = 1; i < *gridColSize; i++)
        dp[0][i] = grid[0][i] + dp[0][i-1];
    
    for(i = 1; i < gridSize; i++)
    {
        for(j = 1; j < *gridColSize; j++)
        {
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return dp[gridSize-1][(*gridColSize)-1];
}
