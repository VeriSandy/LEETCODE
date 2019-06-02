/*
Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.
Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

IDEA -- 
KADANE' ALGORITHM
*/

int MAX(int a, int b)
{
    return a>b?a:b;
}

int maxSubArray(int* nums, int numsSize){

    if(!numsSize) return 0;
    
    int max = nums[0];
    int cursum = nums[0];
    int i = 0;
    
    for(i = 1; i < numsSize; i++)
    {
        cursum = MAX(nums[i]+cursum, nums[i]);
        if(cursum > max)
            max = cursum;
    }
    return max;
}


