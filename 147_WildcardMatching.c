 /*
Wildcard Matching --
Idea --
Have to deal with each possible combination.

If character is ‘*’
    1. We can ignore ‘*’ character and move to next character in the Pattern.
    2. ‘*’ character matches with one or more characters in Text. Here we will move to next character in the string.
    
If character is ‘?’
    We can ignore current character in Text and move to next character in the Pattern and Text.
    
else
If current character in Text matches with current character in Pattern, we move to next character in the Pattern and Text. If they do not match, wildcard pattern and Text do not match.

*/
bool isMatch(char * s, char * p)
{
    int l1 = strlen(s);
    int l2 = strlen(p);
    
    if(!l1 && !l2) return true;
    
    int i = 0, j = 0, flag = 0;
    bool dp[l1+1][l2+1];
    memset(dp, false, sizeof(dp));
    
    //dp[i][j] == matching for string length i and pattern of length j.
    
    dp[0][0] = true;
    
    //For pattern of length i and string length 0.
    //like a*, a*b*
    for(i = 1; i <= l2; i++)
    {
        if(p[i-1] == '*')
            dp[0][i] = dp[0][i-1];
    }
    
    for(i = 1; i <= l1; i++)
    {
        for(j = 1; j <= l2; j++)
        {
            if(p[j-1] == '*')
            {                
                dp[i][j] = dp[i][j-1] || dp[i-1][j];   
            }
            //if it is '?' then it will match any character
            //or if both chars is matching in string and pattern
            //then this would be same as of tring of len i-1 and pat of len j-1
            else if(p[j-1] == '?'
                   || p[j-1] == s[i-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    return dp[l1][l2];
}

