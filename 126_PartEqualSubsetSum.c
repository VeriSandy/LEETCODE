/*
Partition Equal Subset Sum

1. Partitioning into two
If sum of whole array is even, then can be partitioned.
ex - 
    1. 24, 17, 5 ==> sum 46, but cant be partitioned.
    2. 42
    3. 1, 2, 3, 4, 5, 6, 7
    4. 1, 2, 3, 5, 7, 8 
But in case of Odd sum, can't be done.
*/

//DP Solution
bool canPartition(int* nums, int numsSize)
{
    if(numsSize <= 1) return false;
   
    int i = 0, j = 0;
    long sum = 0;
   
    for(i = 0; i < numsSize; i++)
        sum += nums[i];
    
    if(sum%2) return false;
    sum = sum/2;

    //int dp[sum+1][n];
    int dp[sum+1][numsSize+1];
    
    //if sum is zero
    for(i = 0;  i <= numsSize; i++)
        dp[0][i] = true;
    
    //if 0 elements 
    for(i = 1;  i <= sum; i++)
        dp[i][0] = false;
    
    for(i = 1;  i <= sum; i++)
    {
        //we can take this from 0 to numsSize-1
        //for  simplicity, start with 1 to numsSize
        //for(j = 0;  j < numsSize; j++)
        for(j = 1;  j <= numsSize; j++)
        {
            //dp[i][j] = dp[i][j-1] || dp[i-nums[j-1]][j-1];
            dp[i][j] = dp[i][j-1];
            if(i >= nums[j-1])
                dp[i][j] = dp[i][j-1] || dp[i-nums[j-1]][j-1];
        }
    }
    return dp[sum][numsSize];
}

/* recursive way
bool canPartitionzutility(int* nums, int start, int end, int sum)
{
    if(start >= end || sum < 0) return false;
    
    if(sum == 0) return true;
    
    int i = start;
    
    if(canPartitionzutility(nums, i+1, end, sum - nums[i])
      || canPartitionzutility(nums, i+1, end, sum))
        return true;
    
    return false;
}

bool canPartition(int* nums, int numsSize)
{
    if(numsSize <= 1) return false;
   
    int i = 0;
    long sum = 0, sum1 = 0;
   
    for(i = 0; i < numsSize; i++)
        sum += nums[i];
    
    if(sum%2) return false;
    
    sum1 = sum/2;
    sum = 0;
    i = 0;
    
    if(canPartitionzutility(nums, i+1, numsSize, sum1 - nums[i])
      || canPartitionzutility(nums, i+1, numsSize, sum1))
        return true;
    
    return false;
}
*/
