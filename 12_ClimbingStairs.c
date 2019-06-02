/*
Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Note: Given n will be a positive integer.
Example 1:
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

IDEA -- Use DP.
*/

int climbStairs(int n)
{
    if(n <= 1) return 1;
    
    int i = 0;
    int f[n+1];
    
    f[0] = 1;
    f[1] = 1;
        
    for(i = 2; i <= n; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
    
    return f[n];
}


