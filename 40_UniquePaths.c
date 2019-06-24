/*
A robot is located at the top-left corner of a m x n grid.
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid.

How many possible unique paths are there?
*/

//recursion
int uniquePaths(int m, int n)
{       
    if(m == 1 || n == 1) return 1;   
    return uniquePaths(m-1, n) + uniquePaths(m, n-1);
}

//DP
int uniquePaths(int m, int n)
{       
    if(m == 0 || n == 0) return 0;
    
    
    int i = 0, j = 0;
    int count[m][n];    
    memset(count, 0, sizeof(count));

    for(i = 0; i < m ; i++)
        count[i][0] = 1;
    
    for(i = 0; i < n ; i++)
        count[0][i] = 1;
    
    for(i = 1; i < m ; i++)
    {
        for(j = 1; j < n ; j++)
        {
            count[i][j] = count[i-1][j] + count[i][j-1] ;
        }
    
    }
    
    return count[m-1][n-1];
}

//DFS way
void Utility(int i, int j, int m, int n, int *count)
{
    if(i == m -1 && j == n-1)
    { 
        *count = *count + 1;
        //printf("%d\n", *count);
        return;
    }
    
    if(i+1 >= 0 && i+1 < m && j >= 0 && j < n)
        Utility(i+1, j, m, n, count);
        
    if(i >= 0 && i < m && j+1 >= 0 && j+1 < n)
        Utility(i, j+1, m, n, count);
    
    return;
}

int uniquePaths(int m, int n){
    if(m == 0 || n == 0) return 0;
    int i = 0, j = 0;
    int count = 0;
    Utility(i, j, m, n, &count);
    return count;
}
