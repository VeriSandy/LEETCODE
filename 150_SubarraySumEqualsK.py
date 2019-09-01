'''
Subarray Sum Equals K --

Ideas -- 
1. Use two loops, find each SubArray.O(n2)

2. 
Use hasing concept, here. 
Store sum so far, in var currsum.
Also maintain count of different values of currsum in a hashmap. 
If value of currsum == k, increment count of subarrays by one. 
When Currsum exceeds desired sum by currsum – k, then if this value is removed from currsum then desired sum can be obtained.
From the map find number of subarrays previously found having sum equal to currsum-k. Add this number to count. As we remove all those array from this subarray, desired sum can be obtained.

Also, when currsum == k, find subarrays in hashmap, have sum == 0. Excluding those subarrays from current subarray gives new subarrays having desired sum. So add that number also in count.

Complexity - O(n) + O(n){Space}.

'''

#Pyhton Solution + C Solution 

from collections import defaultdict 

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        
        curSum = 0
        prevSum = defaultdict(int) # or defaultdict(lambda : 0)
        count = 0
        
        for i in nums:
            curSum += i;
            
            if(curSum == k):
                count += 1
            
            if((curSum - k) in prevSum):
                count += prevSum[curSum - k]
            
            prevSum[curSum] += 1
            
        return count
        
        
        
###############################################################

/*
Idea -- 
1. Use two loops, find each SubArray.O(n2)
*/
int subarraySum(int* nums, int numsSize, int k)
{    
    int i= 0, j = 0;
    int count = 0;
    
    int temp = k;
    int sum = 0;
    
    for(i = 0; i < numsSize; i++)
    {
        sum = 0;
        for(j = i; j < numsSize; j++)
        {
            sum += nums[j];
            //Do not break here, when sum == k, as next element can be zero, that will make one more subarray from i to j.
            if(sum == k) 
                count++;
        }
    }
    return count;
}
