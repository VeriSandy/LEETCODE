'''
Find next greater element for each element in second array and put it in hashmap(as we are given distinct element array). 
Now for first array, find the value of correspoding element in hashmap.

Find Next Greater element ==?
1. 
    Start from the last element and push it into stack.
    Now if ith element of array > top of stack, pop while ithElement >= top(Stack) or stack       is empty.

    If stack is empty then next greater element of element of array is -1 
    and if not then next greater element of element of array is top(Stack).

    Push ithElement to stack.

    O(n)
2. 
Otherwise use two for loops to find next greater element. O(n2)
'''
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        #find next greater element for all elements in list 2.
        
        stk = []
        hashMap = {}
        nextGreater = []
        
        l = len(nums2)
        i = l-1
        
        while(i >= 0):
            while(len(stk) and stk[-1] <= nums2[i]):
                stk.pop()
            
            if(len(stk) == 0):
                hashMap[nums2[i]] = -1
            else:
                hashMap[nums2[i]] = stk[-1]
                
            stk.append(nums2[i])
            i -= 1
        
        i = 0
        l = len(nums1)
        while(i < l):
            nextGreater.append(hashMap[nums1[i]])
            i += 1
        
        return nextGreater
