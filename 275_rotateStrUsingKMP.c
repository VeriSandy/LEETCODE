/*
If string A is rotated to B then if we concatenate B two times then A will exist there as it is in BB. So just find A in BB. 

To search KMP algo can be used.

Also A is converted to B then length of both strings should be same otherwise this might give the wrong result.
Ex - 
A = "abcabc"
B = "abc"

A does exist in BB this will return true and that is wrong.

*/

void FillLPS(int *lps, int M, char *pat)
{
    int i = 1, len = 0;
    lps[0] = 0;
    
    while(i < M)
    {
        if(pat[i]  == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i]  = 0;
                i++;
            }
        }
    }
    return;
}

bool KMPSearch(char *str, char *pat)
{
    int N = strlen(str);
    int M = strlen(pat);
    
    if(M == 0 || N == 0) return true;
    
    int lps[M];
    int i = 0, j = 0;
    
    FillLPS(lps, M, pat);
    
    while(i < N)
    {
        if(str[i] == pat[j])
        {
            i++;
            j++;
        }
        
        if(j == M)
        {
            j = lps[j-1];
            return true;
        }
        else if(i < N && str[i] != pat[j])
        {
            if(j)
                j = lps[j-1];
            else
                i++;
        }
    }
    return false;
}

bool rotateString(char *A, char *B)
{
    int l1 = strlen(A);
    int l2 = strlen(B);

    if(l1 != l2) return false;
    
    char *str = malloc(2*l2+1);
    memset(str, 0, 2*l2+1);
    strcat(str, B);
    //printf("%s\n", str);
    strcat(str, B);
    
    //printf("%s\n", str);
    
    //if(strstr(str, A))
    //    return  true;
    
    if(KMPSearch(str, A))
        return  true;
    
    return false;
}

