/*
Target Sum --

Idea --
This is a classic knapsack problem
in knapsack, we decide whether we choose this element or not
in this question, we decide whether we add this element or minus it

So start with a two dimensional array dp[i][j] which means the number of ways for first i-th element to reach a sum j

we can easily observe that dp[i][j] = dp[i-1][j+nums[i]] + dp[i-1][j-nums[i],

Another part which is quite confusing is return value, here we return dp[sum+S], why is that?
because dp's range starts from -sum --> 0 --> +sum
so we need to add sum first, then the total starts from 0, then we add S

*/
//DP Solution.
int findTargetSumWays(int* nums, int numsSize, int S)
{
    int i = 0, j = 0;
    
    int sum = 0;
    for(i = 0; i < numsSize; i++)
        sum += nums[i];
    
    if (S < -sum || S > sum) { return 0;}
    
    int Ways[numsSize+1][2*sum+1];    
    memset(Ways, 0, sizeof(Ways));
    
    Ways[0][0+sum] = 1;
    
    for(i = 1; i <= numsSize ; i++)
    {
        for(j = 0; j <2*sum+1; j++)
        {
            Ways[i][j] += (j-nums[i-1]  >= 0)?Ways[i-1][j-nums[i-1]]:0;
            Ways[i][j] += (j+nums[i-1]  < 2*sum+1)?Ways[i-1][j+nums[i-1]]:0;
        }
    }
    return Ways[numsSize][S+sum];
}

============================================================================
//Recursion solution
int findTargetSumWaysUtil(int* nums, int i, int numsSize, int S, int sum)
{
    if(i == numsSize)
    {
        if(sum == S)
            return 1;
        else
            return 0;
    }
    
    return  findTargetSumWaysUtil(nums, i+1, numsSize, S, sum+nums[i])
            +findTargetSumWaysUtil(nums, i+1, numsSize, S, sum-nums[i]);
}

int findTargetSumWays(int* nums, int numsSize, int S)
{
    int i = 0, sum = 0;
    return findTargetSumWaysUtil(nums, i, numsSize, S, sum);
}
