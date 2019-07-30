/*
Palindromic Substrings --

Ideas -- 
1. Using two loops, find all the substrings and check for the palindrome.
This is going to take O(n3), as two loops + find palindrome.

2.Think about the case 
    a. All single letters are going to be palindrome.
    b. If a substr from, i to j is palindrome. Then see substrings from i to j-1,
    from i+1 to j.
    Here total count would be 
    1+ Count(i, j -1) + Count(i+1, j) - Count(i+1, j -1)
    
    c. If a substr from, i to j is not palindrome. Then see substrings from i to j-1,
    from i+1 to j.
    Here total count would be 
    Count(i, j -1) + Count(i+1, j) - Count(i+1, j -1)
    WHERE Count(i+1, j -1) ==> COMMON, PALINDROME SUBSTRINGS.
    
    RECURSION SOLUTION --
    
    Initial Values : i = 0, j = n-1;
    Given string 'str'  
    CountPS(i, j)  
        // If length of string is 2 then check both character are same or not 
        If (j == i+1)
            return str[i] == str[j]

        Else If str[i..j] is PALINDROME 
            return  1 + countPS(i+1, j) + countPS(i, j-1) - countPS(i+1, j-1);

        Else // if NOT PALINDROME 
            return  countPS(i+1, j) + countPS(i, j-1) -  countPS(i+1 , j-1);
*/

int countSubstrings(char * s)
{
    if(s == NULL) return 0;
    
    int l = strlen(s), i = 0, j = 0, k = 0;
    
    int dp[l][l];
    memset(dp, 0, sizeof(dp));
    
    int p[l][l];
    memset(p, 0, sizeof(p));
    
    //printf("l = %d\n",l);
    
    for(i = 0 ; i < l; i++)
        p[i][i] = 1;
    
    for(i = 0 ; i < l-1; i++)
    {
        if(s[i] == s[i+1])
        {
            dp[i][i+1] = 1;
            p[i][i+1] = 1;
        }
    }
    
    for(k = 2 ; k < l; k++)
    {
       for(i = 0 ; i < l - k; i++) 
       {
           j = i + k;
           
           if(s[i] == s[j] && p[i+1][j-1])
                p[i][j] = 1;
           
           if(p[i][j])
               dp[i][j] += 1 + dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
            else
                dp[i][j] += dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
           
           //printf("dp[%d][%d] = %d\n",i, j, dp[i][j]);
       }
    }
    
    return dp[0][l-1] + l;
}

