https://leetcode.com/problems/longest-consecutive-sequence/

        
'''
Ideas -- 
1. Brute Force Approach -- O(n2)
2. using sorting - O(nlogn)
3. use hashmap - O(n)
'''

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:    
        Max = 0
        Count = 0

        num_set = set(nums)

        for num in num_set:  
            Count = 0
            if num-1 not in num_set:
                temp = num
                while(temp in num_set):
                    temp += 1
                    Count += 1

            if(Count > Max):
                Max = Count;

        return Max;


