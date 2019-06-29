/*
Valid Palindrome - 
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Use normal palindrome approach.
But skip from both sides if non alphanumeric character
*/

class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        l = len(s)
        if(l == 0):
            return True
 
        s = s.lower()
    
        j = 0
        k = l-1
        
        while(j <= k):
            
            while(j <= k and s[j].isalnum() == False):
                j += 1
            
            while(j <= k and s[k].isalnum() == False):
                k -= 1
            
            if(j <= k and s[j] != s[k]):
                return False
            
            j += 1
            k -= 1
            
        return True
        
