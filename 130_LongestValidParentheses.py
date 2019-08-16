'''
###Longest Valid Parentheses

Start by pushing −1 onto the stack.

For every ‘(’ encountered, we push its index onto the stack.

For every ‘)’ encountered, we pop the topmost element and subtract the current element's index from the top element of the stack, which gives the length of the currently encountered valid string of parentheses. If while popping the element, the stack becomes empty, we push the current element's index onto the stack. 
In this way, we keep on calculating the lengths of the valid substrings, and return the length of the longest valid string at the end.

'''
class Solution:
    def longestValidParentheses(self, s: str) -> int:    
        stk = []
        stk.append(-1)
        k = 0
        Max = 0
        for i in s:
            if(i == '('):
                stk.append(k)
            if(i == ')'):
                val = stk.pop()
                if(len(stk) == 0):
                    stk.append(k)
                else:
                    Max = max(Max, k - stk[-1])
            k += 1
        
        return Max
            
