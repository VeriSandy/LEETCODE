/*
Ideas -- 
1.
Take all the substrings of s except s itself, see if s can be formed by any of those.


2. LPS of KMP's can be used here.

If length of s is l.

if lps[l-1] == l-1 ==> all the chars are same. return true
if lps[l-1] == 0 ==> no the chars are same. return false.

In short if s is formed my multiple copies of same string then at start also it would be same string.

and lps[l-1] will not be zero. 

l - lps[l -1] will give the size of the string using which whole string is formed.
{exmaples - "AAAA", "AABAABAAB", "ABCABCABC"}
size = l - lps[l-1]
So we can say if lps[l-1] is non zero and l%size == 0 then string is formed by the substring of size "size" otherwise not.

*/

============================================================
By LPS of KMP's
============================================================

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
    
    i = 0;
    
    /*
    while(i < M)
    {
        printf("%d ", lps[i]);
        i++;
    }
    printf("\n");
    */
    return;
}

bool repeatedSubstringPattern(char *s)
{
    int l = strlen(s);
    int size = 0;
    
    if(l <= 1) return false;
    
    int lps[l];
    LPS(s, l, lps);
    
    size = l - lps[l-1];
    
    return lps[l-1] && !(l%size);
}

============================================================
By comparing all the substrings of size upto l/2
============================================================

bool repeatedSubstringPattern(char *s)
{
    int l = strlen(s);
    int i = 0, j = 0, count = 0;
    
    if(l <= 1) return false;

    
    char *pat = malloc(l+1);
    memset(pat, 0, l+1);
    
    char *ptr = NULL;

    int l1 = l/2; //pattern till half of the length can be repeated otherwise it wouldn't 
    i = 1;
    while(i <= l1)
    {
        memset(pat, 0, l+1);
        strncpy(pat, s, i);
        //printf("%s\n",pat);
        j = i;
        count = i;
        while(s[j])
        {
            ptr = strstr(&s[j], pat);
            if(ptr)
            {
                //printf("%d %d %d %d\n", i, &s[j], ptr, count);
                if(ptr != &s[j])
                    break;
                j += i;
                count += i;
            }
            else
            {
                count = 0;
                break;
            }
        }
        
        //printf("%d\n",count);
        
        if(count == l) return true;
        
        i++;
    }
    
    return false;
}
