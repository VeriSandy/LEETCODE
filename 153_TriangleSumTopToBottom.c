/*
Given a triangle, find the minimum path sum from top to bottom --
Idea --
1. 
Choose min of each row and then add, and those too adjacent numbers
Need to have a recursion relation.

Obnservation --
Adjacent of 0,0 is 1,0 or 1,1
Adjacent of 1,1 is  2,1, 2, 2
Adjacent of 1,0 is 2,0 and 2,1
In short adjacent elements are , +1 and 0 of next row from current element.

2.  If you make tree of above recursion relation, there are so many repeating subprobmes. Use DP.
*/

int min(int a, int b)
{
    return a>b?b:a;
}
//Dp    
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
{
    if(triangleSize < 1 || *triangleColSize < 1) return 0; 
    
    
    if(triangleSize == 1) return triangle[0][0];
    
    int i = 0, j = 0, Min = INT_MAX;
    int dp[triangleSize][triangleSize];
    memset(dp, 0, sizeof(dp));
    
    dp[0][0] = triangle[0][0];
    
    for(i = 1; i < triangleSize; i++)
    {
        Min = INT_MAX;
       for(j = 0; j <= i; j++)
       {
           int left = INT_MAX;
           int right = INT_MAX;
           if(j -1 >= 0)
               left = dp[i-1][j-1];
           if(j <= i-1)
               right = dp[i-1][j];
           
           dp[i][j] = triangle[i][j]  + min(left, right);
           
           Min = min(Min, dp[i][j]);
       }
    }
    //printf("%d\n", Min);
    return Min;
}

/*
//Recursion ---
int helper(int **a, int m, int n, int start, int end)
{
    if(m >=n) return 0;
    
    start = start > 0?start:0;
    end = end <= m+1?end:m+1;
    
    int i = 0, Min = INT_MAX;
    for(i = start; i <= end; i++)
        Min = min(Min, a[m][i]+helper(a, m+1, n, i, i+1));
    
    return Min;
}

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
{
    if(triangleSize < 1 || *triangleColSize < 1) return 0; 
    return helper(triangle, 0, triangleSize, 0, 0);
}
*/
