/*
Implement strStr()
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. 
This is consistent to C's strstr() and Java's indexOf().

IDEA -- 
USE KMP ALGORITHM for this.
*/

//take example abcaba
//lps should 0 0 0 1 2 1
void LPS(char *s, int M, int *lps)
{
    int i = 1, len = 0;
    
    lps[0] = 0;
    
    while(i < M)
    {
        if(s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(!len)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len -1];
            }
        }
    }
    return;
}


int strStr(char *haystack, char *needle){
    
    int M = strlen(needle);
    int N = strlen(haystack);
    
    if(!M) 
        return 0;
    
    if(!N) 
        return -1;
    
    
    int i = 0, j = 0;
    
    int lps[M];
    
    
    LPS(needle, M, lps);
    
    while(i < N)
    {
        if(haystack[i] == needle[j])
        {
            i++;
            j++;
        }
        
        if(j == M)
            return (i-j);
        
        else if( i < N && haystack[i] != needle[j])
        {
            if(!j) 
                i++;
            else
                j = lps[j-1];
        }
    }
    
    return -1;
}
