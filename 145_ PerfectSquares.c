/*
Perfect Squares --
Ideas -- 
    1. Need to find out the min count of all solutions. So use Recursion.
    2. Above reursion will have so many common subproblems, think if we need to get the solutions 
    for n = 6, n == 4 can be achieved by by reducing 2 'one time' or 1 'two times'. Here use DP.
*/

int min(int a, int b)
{
    return a>b?b:a;
}

/*
//recursion 
int numSquaresUtilty(int k, int *a, int n)
{
    if(k < 0)
        return INT_MAX;
    
    if(k == 0)
        return 0;
    
    int i = 0, count = INT_MAX;
    for(i = 0; i < n; i++)
    {
        if(k - a[i] >= 0)
            count = min(count, 1 + numSquaresUtilty(k - a[i], a, n));
    }
    return count;
}

*/
//DP
int numSquares(int n)
{
    if(n <= 1) return n;
    
    int srt = sqrt(n);
    int m = srt*srt;
    printf("%d", m);
    
    int a[srt], i = 0, j = 0;
    
    for(i = 1; i <= srt; i++)
        a[i-1] = i*i;
    
    //return numSquaresUtilty(n, a, srt);
    
    //DP
    int dp[n+1];
    dp[0] = 0;
    for(i = 1; i <= n; i++)
    {
        //Each sum can be representd by sum of 1s. 
        dp[i] = i;
        for(j = 0; j < srt; j++)
        {
            if(i < a[j]) break;
            
            dp[i] = min(dp[i], 1 + dp[i - a[j]]);
        }
    }
    return dp[n];
}
