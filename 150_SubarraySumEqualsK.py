'''
Subarray Sum Equals K --

Ideas -- 

1. SLIDING WINDOW. ==>>>>>> WHY SLIDING WINDOW WILL NOT WORK HERE ?

[28,54,7,-70,22,65,-6]
100

curr_index=0, total_sum=28
curr_index=1, total_sum=82
curr_index=2, total_sum=89
curr_index=3, total_sum=19
curr_index=4, total_sum=41
curr_index=5, total_sum=106
curr_index=6, total_sum=100

Here the sum of the first six elements is 106, as our window size becomes bigger than 100 we will remove the element at 0th index (28) from it. But we could get 100 if we include -6 in the sum which would have made it to 100. Because of the negative numbers, the sum doesn't work as expected.

Now if the questions were to find a non-continuous subarray, then we could have sorted the array and used a sliding window technique which would have worked even with negative values as the sum would be always increasing and we won't get unpredictable sum.

2. Use two loops, find each SubArray.O(n2)
Look for each subarray start with A[i] to end if SUM is K.

3. 
Use hasing concept, here. 
Store sum so far, in var currsum.
Also maintain count of different values of currsum in a hashmap. 
If value of currsum == k, increment count of subarrays by one. 
When Currsum exceeds desired sum by currsum – k, then if this value is removed from currsum then desired sum can be obtained.
From the map find number of subarrays previously found having sum equal to currsum-k, 
add this number to count. As we remove all those array from this subarray, desired sum can be obtained.

Also, when currsum == k, find subarrays in hashmap, have sum == 0. Excluding those subarrays from current subarray 
gives new subarrays having desired sum, so add that number also in count.

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
