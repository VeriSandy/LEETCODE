/*
Edit Distance
Ideas -- 

Insert
Delete
Replace

If something like DFS, where do we have other nodes of graph, other than source and destination.

Since it is min, looks like at last DP can be applied to find the min.

One idea is
1. 
    a. If length is equal, then repalce source with destination character.
    b. If source length is less then repalce source with destination character and insert additional characters.
    c. If source length is more then repalce source with destination character and delete additional characters.
    
But this would not give min distance/operations.

2. Recursion -- 
    Start traversing from one end.
    a. if(last chars are same, then recur for m-1, n-1)
    b. Else find the min of three operations
        i.      insert (m, n-1)
        ii.     remove (m-1, n)
        iii.    replace (m-1, n-1)
        

3. DP
    Recursion will end up in too much time comlexity.
    And there are many sub-problems are repeating, So go for DP.
*/

int min(int a, int b, int c)
{
    return a<b?(c<a?c:a):(c<b?c:b);
}
/*
int minDistanceUtility(char * word1, char * word2, int l1, int l2)
{
    if(l1 == 0) return l2;
    if(l2 == 0) return l1;
    
    if(word1[l1-1] == word2[l2-1])
        return minDistanceUtility(word1, word2, l1-1, l2-1);
    
    return 1 + min( minDistanceUtility(word1, word2, l1, l2-1), //add
                    minDistanceUtility(word1, word2, l1-1, l2), //remove 
                    minDistanceUtility(word1, word2, l1-1, l2-1)//replace
                  );
}

int minDistance(char * word1, char * word2)
{
    int l1 = strlen(word1);
    int l2 = strlen(word2);
    if(l1 == 0) return l2;
    if(l2 == 0) return l1;
    
    return minDistanceUtility(word1, word2, l1, l2);
}
*/
int minDistance(char * word1, char * word2)
{
    int l1 = strlen(word1);
    int l2 = strlen(word2);
    if(l1 == 0) return l2;
    if(l2 == 0) return l1;
    
    int dp[l1+1][l2+1];
    int i = 0,j = 0;
    
    for(i = 0; i <= l2; i++)
        dp[0][i] = i;
    for(i = 0; i <= l1; i++)
        dp[i][0] = i;
    
    for(i = 1; i <= l1; i++)
    {
        for(j = 1; j <= l2; j++) 
        {
            if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
        }
    }
    return dp[l1][l2];
}
