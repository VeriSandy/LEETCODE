'''
1. Use two loops
in first loops traverse the whole array
in second loop check atmost k elements if there is similar element like a[i]

2. Use sliding window concept and hashing.
Use window of size K +1.
once you encounter any element which exists in hash table is answer
'''

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        
        hashMap = {}
        i = 0
        j = 0
        l = len(nums)
        
        while(i <= k and i < l):
            if nums[i] in hashMap:
                return True
            hashMap[nums[i]] = i
            i += 1
        
        while(i < l):
            del hashMap[nums[j]]
            if nums[i] in hashMap:
                return True
            hashMap[nums[i]] = i
            i += 1
            j += 1
        
        return False
