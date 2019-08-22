/*
    Longest Increasing Subsequence --
    
    DP Approach.
    For any i.
    if a[i] > a[j] then at least lis[i] = lis[j] +1
    Where 0 < j < i.
*/

int lengthOfLIS(int* nums, int numsSize)
{
    int i = 0, j = 0;
    if(numsSize <= 1) return numsSize;
    
    int Max = 0, count = 0, temp = 0;
    
    int dp[numsSize];
    dp[0] = 1;
    
    
    for(i = 1; i < numsSize; i++)
    {
        dp[i] = 1;
        for(j = 0; j < i; j++)
        {
            if(nums[j] < nums[i] && dp[i] < dp[j] +1)
                dp[i] = dp[j] +1;
        }
        
        if(Max < dp[i])
            Max = dp[i];
    }
    return Max;
}
