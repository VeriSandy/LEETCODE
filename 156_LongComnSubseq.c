/*
common subsequence -- 

1. Use recursion
    if(both characters are same)
    count = 1+ util(++text1, ++text2);
    else
    count = max(util(++text1, ++text2), 
                max(util(text1, ++text2), util(++text1, text2)));
    return count;
    
2. use DP.

*/

int MAX(int a, int b)
{
    return a>b?a:b;
}

/*
int longestCommonSubsequence(char *text1, char *text2)
{
    int l1 = strlen(text1);
    int l2 = strlen(text2);
    
    if(l1 == 0 || l2 == 0) return 0;
    int i = 0, max = 0;
    int count = 0;
    if(*text1 == *text2)
        count = 1+ longestCommonSubsequence(&text1[i+1], &text2[i+1]);
    else 
        count = 
                MAX(longestCommonSubsequence(text1, &text2[i+1]), 
                    MAX(longestCommonSubsequence(&text1[i+1], &text2[i+1]), 
                        longestCommonSubsequence(&text1[i+1],text2)));
    
    return count;
}
*/
    
int longestCommonSubsequence(char *text1, char *text2)
{
    int l1 = strlen(text1);
    int l2 = strlen(text2);
    if(l1 == 0 || l2 == 0) return 0;
    
    int dp[l1+1][l2+1];
    int i = 0, j = 0;
    
    //for l1 = 0
    for(i = 0; i <= l2; i++)
        dp[0][i] = 0;
    //for l2 = 0
    for(i = 0; i <= l1; i++)
        dp[i][0] = 0;     
    
    for(i = 1; i <= l1; i++)
    {
        for(j = 1; j <= l2; j++)
        {
            if(text1[i-1] == text2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = MAX(dp[i-1][j-1],
                               MAX(dp[i][j-1],dp[i-1][j]));
        }
    }
    return dp[l1][l2];
}



