
/*
House Robber II --

Any element can be taken or not.
if any element is choosen, then next can't be taken.
If first is taken, last can't and if last is taken then first can't.
Can be solved recursively and using DP.

Intially, take max of rob(nums, numsSize -1){here first element is taken, so last can't take} and
rob(nums+1, numsSize -1){here first element is not taken, so last can be taken}.

Final DP Relation ------
Let dp[i] represents the maximum value stolen so far on reaching house i. 
We can calculate the value of dp[i] as following –
dp[i] = max (nums[i] + dp[i-2], dp[i-1])

nums[i] + dp[i-2] is the case when thief decided to rob house i. In that situation maximum value will be the current value of house + maximum value stolen till last robbery at house not adjacent to house i which will be house i-2.  
 
dp[i-1] is the case when thief decided not to rob house i. So he will check adjacent house for maximum value stolen till now.
*/

int max(int a, int b)
{
    return a>b?a:b;
}

int robUtility(int* nums, int numsSize)
{
    if(numsSize <= 0 ) return 0;

    if(numsSize == 1) return nums[0];
    
    if(numsSize  == 2)
        return nums[0]>nums[1]?nums[0]:nums[1];
    
    int dp[numsSize], i = 0;
    
    dp[0] = nums[0];
    
    dp[1] = max(nums[0], nums[1]);
    
    for(i = 2; i < numsSize; i++)
        dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
    
    return dp[numsSize-1];
}

int rob(int* nums, int numsSize)
{
    if(numsSize <= 0 ) return 0;
    
    if(numsSize == 1) return nums[0];
    
    if(numsSize  == 2)
        return nums[0]>nums[1]?nums[0]:nums[1];
    
    return max(robUtility(nums, numsSize -1), robUtility(&nums[1], numsSize -1));
}

//dp2
int max(int a, int b)
{
    return a>b?a:b;
}

int robUtility(int* nums, int numsSize)
{
    if(numsSize <= 0 ) return 0;

    if(numsSize == 1) return nums[0];
    
    if(numsSize  == 2)
        return nums[0]>nums[1]?nums[0]:nums[1];
    
    int dp[numsSize], i = 0;
    
    dp[0] = nums[0];
    
    dp[1] = max(nums[0], nums[1]);
    
    for(i = 2; i < numsSize; i++)
        dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
    
    return dp[numsSize-1];
}

int rob(int* nums, int numsSize)
{
    if(numsSize <= 0 ) return 0;
    
    if(numsSize == 1) return nums[0];
    
    if(numsSize  == 2)
        return nums[0]>nums[1]?nums[0]:nums[1];
    
    return max(max(nums[0] + robUtility(&nums[2], numsSize -3), 
                        nums[numsSize-1] + robUtility(&nums[1], numsSize -3)),
                 nums[1] + robUtility(&nums[3], numsSize -3));
}
//recursion1
int max(int a, int b)
{
    return a>b?a:b;
}

int robUtility(int* nums, int numsSize)
{
    if(numsSize <= 0 ) return 0;
    
    if(numsSize == 1) return nums[0];
    
    if(numsSize  == 2)
        return nums[0]>nums[1]?nums[0]:nums[1];
    
    return max(nums[numsSize -1] + robUtility(nums, numsSize -2),
                 nums[numsSize -2] + robUtility(nums, numsSize -3));
}

int rob(int* nums, int numsSize)
{
    if(numsSize <= 0 ) return 0;
    
    if(numsSize == 1) return nums[0];
    
    if(numsSize  == 2)
        return nums[0]>nums[1]?nums[0]:nums[1];
    
    return max(max(nums[0] + robUtility(&nums[2], numsSize -3), 
                        nums[numsSize-1] + robUtility(&nums[1], numsSize -3)),
                 nums[1] + robUtility(&nums[3], numsSize -3));
}
