/*
1. Looks recursion.
2. It can be solved using two loops, considering each subarray.

NonNegative.
*/

//DP(Two loops)
bool checkSubarraySum(int* nums, int numsSize, int k)
{
    if(numsSize <= 1)
        return false;
    
    int dp[numsSize];
    memset(dp, 0, sizeof(dp));
    int i  = 1, j = 0;
    dp[0] = nums[0];
    
    while(i < numsSize)
    {
        dp[i] = dp[i-1] + nums[i];
        i++;
    }
    
    i = 1;
    while(i < numsSize)
    {
        if((k && dp[i]%k == 0) || (!k && !dp[i])) return true;
        
        j = 0;
        while(j < i -1)
        {            
            if((k && (dp[i] - dp[j])%k == 0) || (!k && !(dp[i] - dp[j]))) return true;
            
            j++;
        }
        i++;
    }
    
    return false;
}
================================================================================================
//two loops.
bool checkSubarraySum(int* nums, int numsSize, int k)
{
    long sum = 0;
    
    if(numsSize <= 1)
        return false;
    
    int i  = 0, j = 0;
    
    while(i < numsSize -1)
    {
        sum = nums[i];
        j = i+1;
        while(j < numsSize)
        {            
            sum += nums[j];
            if((!k && !sum) || (k && sum%k == 0))
                return true;
            j++;
        }
        i++;
    }
    
    return false;
}
================================================================================================
//Recursion
bool checkSubarraySumUtil(int* nums, int start, int n, int k, long sum)
{ 
    if(n - start <= 1) return false;
    
    if(k && (sum%k == 0)) return true;

    return checkSubarraySumUtil(nums, start, n-1, k, sum-nums[n-1]) 
            ||
            checkSubarraySumUtil(nums, start+1, n, k, sum-nums[start]);
}

bool checkSubarraySum(int* nums, int numsSize, int k)
{
    long sum = 0;
    
    if(numsSize <= 1)
        return false;
    
    int i  = 1;
    
    sum = nums[0];
    
    while(i < numsSize)
    {
        sum += nums[i];

        if(!nums[i] && !nums[i-1]&& !k)
            return true;
        i++;
    }
    
    if(k) return checkSubarraySumUtil(nums, 0, numsSize, k, sum);
    return false;
}
