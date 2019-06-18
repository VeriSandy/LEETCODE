
/*
Let X[0..n-1] be the input sequence of length n and L(0, n-1) be the length of the longest palindromic subsequence of X[0..n-1].

If last and first characters of X are same, then L(0, n-1) = L(1, n-2) + 2.
Else L(0, n-1) = MAX (L(1, n-1), L(0, n-2)).

1. This can be solved by recursion.

2. DP
*/

//Using Recursion 


int max(int a, int b)
{
    return a>b?a:b;
}

int PalSubSeq(char *s, int l, int h){
    
    if(!s) return 0;
    
    if(l == h) return 1;
    
    if(s[l] == s[h] && l+1 == h) return 2;
 
    if(s[l] == s[h])
        return PalSubSeq(s, l+1, h -1) + 2;
    
    return max(PalSubSeq(s, l, h -1), PalSubSeq(s, l+1, h));   
}


int longestPalindromeSubseq(char * s){
    
    int l = strlen(s);
    if(l == 0) return 0;
    
    return PalSubSeq(s, 0, l-1);
}


======================================
//Using DP
int max(int a, int b)
{
    return a>b?a:b;
}


int longestPalindromeSubseq(char * s)
{
    int l = strlen(s);
    
    if(l <= 1) return l;    
    
    
    int lps[l][l];
    memset(lps, 0, sizeof(lps));
    
    int i = 0, j = 0, k = 0;
    
    //string of length 1, is always palindrome
    for(i = 0; i < l ; i++)
        lps[i][i] = 1;
    
    
    //for more than 1 length
    for(k = 2; k <= l ; k++)
    {
        for(i = 0; i < l - k +1; i++)
        {
            j = i+ k - 1;
            
            if(s[i] == s[j] && i+1 == j)
                lps[i][j] = 2;
            
            else if (s[i] == s[j])
                lps[i][j] = lps[i+1][j-1] + 2;
            
            else
                lps[i][j] = max(lps[i+1][j], lps[i][j-1]);
        }
    }
    return lps[0][l-1];
}
