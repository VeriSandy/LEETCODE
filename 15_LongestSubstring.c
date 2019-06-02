/*
Given a string, find the length of the longest substring without repeating characters.
Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
Ex - 4
"dvdf" ==> 3

IDEAS -- 
1. Find out all the substring and check if there is any repeatition of characters ==> O(n3)
2. Traverse once, Use hasing for each substring. 
   Once you get the repeatition, clear hash table, start with next char where you started earlier. O(n2) + space
3. Use sliding window concept here.
Keep going till you dont get repeatition and keep pushing in hash.

Once you hit the repeatition, remove all the characters from your window and hash table, till repeatitive element is removed from the window. Dont forget to reduce count while removing elements from window.
Now this window is clean, you can scan further for next max count.

So all the elements are scanned only twice. O(2n) ==> o(n) + space
*/

int lengthOfLongestSubstring(char * s){
    
    int l = strlen(s);
    int i = 0, k = 0, j = 0;
    int max = 0, count= 0;
    
    int *hash = malloc(sizeof(int)*128);
    memset(hash, 0x00, sizeof(int)*128);
    
    
    //printf("%d ", 'a');
    
    while(i < l)
    {
        if(!hash[s[i]])
        {
           hash[s[i]]++;
           count++;
            i++;
        }
        else
        {
            if(count > max)
                max = count;
            
            //=========
            //Use sliding window concept
            //count max for each string starts at j 
            hash[s[j]]--;
            count--;
            j++;
            //==========
            
            /*
            //==========
            //Use sliding window concept
            while(s[j] != s[i])
            {
               hash[s[j]]--;
               j++;
               count--;
            }
            //this is for, when s[j] == s[i]
            hash[s[j]]--;
            count--;
            j++;
            //==========
            */
            
            /*
            //==========
            count = 0;
            
            j++;
            i = j; //start i from the next character, ex - abcadf
            memset(hash, 0x00, sizeof(int)*256);
            //==========
            */
        }
    }
    
    
    //take care for the last character count
    //or single character
    if(count > max)
        max = count;    
    return max;
}
