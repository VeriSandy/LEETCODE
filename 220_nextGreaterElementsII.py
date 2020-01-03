'''
Make a temporary array of length of given array + copy more n-1 elments to temp array from first array and find the next greater element for all elements in temp arrray but return only for first n elements

1,4,5,8,6,3
4,5,8,-1,8,4

1 4 5 8 6 3 1 4 5 8
4 5 8 -1 8 4 4 5 8 -1


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
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        
        orgLen = len(nums)
        i = 0
        
        temp = []
        
        if(orgLen == 0):
            return temp
        
        temp.extend(nums)
        temp.extend(nums)
        temp.pop() #remove last element.
        
        nextGreater1 = []
        nextGreater = []
        stack = []

        l = len(temp)
        i = l-1
        
        #print(l)
        
        while(i >= 0):
            #1 4 5 8 6 3 1 4 5 8
            while(len(stack) and stack[-1] <= temp[i]):
                stack.pop()
            
            if(len(stack) == 0):
                nextGreater1.append(-1)
            else:
                nextGreater1.append(stack[-1])
                
            stack.append(temp[i])
            i -= 1
        
        i = 0
        while(i < orgLen):
            nextGreater.append(nextGreater1.pop())
            i += 1
        
        return nextGreater
        
        
