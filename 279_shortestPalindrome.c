/*
Palindrome - a word, phrase, or sequence that reads the same backwards as forwards.

We need to know the largest possible palindrome from starting to plug smallest string to  make whole string palindrome.

1. 
We can use reverse(s) to find the largest palindrome at start.
Use a loop and compare string of size 1, 2, 3 ... l; From the start of s and last of reverse(s)

And when we know that, we just add the reverse of remaining string i.e which is not palindrome, at the start of given string.

2.  
KMP's part can be used her to know the largest possible palindrome from starting.
For that we need to create another string by combining "s + '#' + reverse(s)", this will help us to know largest possible palindrome from starting.
    
Here, LPS method in KMP algo to analyze the pattern, can be used.

And when we know that, we just add the reverse of remaining string i.e which is not palindrome, at the start of given string.

NOTE: '#' is a delimter and we need to add that.

For example, take the string "aaaa"
Had we not inserted "#" in the middle, the new string would be 
"aaaaaaaa"
"aaaaaaaa" and the largest prefix size would be 7 corresponding to "aaaaaaa" which would be obviously wrong. Hence, a delimiter is required at the middle.
*/

========================================================================
KMP. O(n)
========================================================================

void rev(char *s)
{
    int l = strlen(s);
    int l1 = l/2, i = 0;
    char ch;
    
    while(i < l1)
    {
        ch = s[i];
        s[i] = s[l-1-i];
        s[l-1-i] = ch;
        i++;
    }
    return;
}

void fillLPS(char *s, int *lps)
{
    int l = strlen(s), i = 1, len = 0;
    
    lps[0] = 0;
    
    //AAACAAAAAC
    while(i < l)
    {
        if(s[i] == s[len])
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
                lps[i] = 0;
                i++;
            }
        }
    }
    
    /*
    i = 0;
    while(i < l)
    {
        printf("%d ", lps[i]);
        i++;
    }
    */
    
    return;
}

char *shortestPalindrome(char *s)
{
    int l = strlen(s), i = 0;
    char ch;
    
    if(l <= 1) return s;
    
    char *tempStr = malloc(2*l+1+1);
    memset(tempStr,0,2*l+1+1);
    
    char *revStr = malloc(l+1);
    memset(revStr,0,l+1);
    strcpy(revStr,s);
    rev(revStr);
    
    strcat(tempStr,s);
    strcat(tempStr,"#");
    strcat(tempStr,revStr);
    
    //printf("%s %s %s\n", s, revStr, tempStr);
    
    int lps[2*l+1];
    fillLPS(tempStr,lps);
    
    i = l - lps[2*l];
    
    char *outStr = malloc(l+i+1);
    memset(outStr,0,l+1+i);
    strncpy(outStr, revStr, i);
    //printf("%d %d %s\n", i,lps[2*l], outStr);
    strcat(outStr, s);
    //printf("%s\n", outStr);
    return outStr;
}

========================================================================
Brute Force. O(n2)
========================================================================
char *shortestPalindrome(char *s)
{
    int l = strlen(s), i = 0, j = 0;
    
    if(l <= 1) return s;
    
    char *revStr = malloc(l+1);
    memset(revStr,0,l+1);
    strcpy(revStr,s);
    rev(revStr);
    
    char *tempStr1 = malloc(l+1);
    memset(tempStr1,0,l+1);
    
    char *tempStr2 = malloc(l+1);
    memset(tempStr2,0,l+1);
    
    //printf("%s %s\n", s, revStr);
    
    i = 0;
    while(i < l)
    {
        memset(tempStr2,0,l+1);
        memset(tempStr1,0,l+1);
        
        strncpy(tempStr1, s, l-i);
        strcpy(tempStr2, &revStr[i]);
        
        //printf("%s %s %d\n", tempStr1, tempStr2, i);
        
        if(!strcmp(tempStr1, tempStr2))
            break;
        
        i++;
    }
    
    char *outStr = malloc(l+i+1);
    memset(outStr,0,l+1+i);
    
    strncpy(outStr, revStr, i);
    //printf("%d %s\n", i,outStr);
    
    strcat(outStr, s);
    //printf("%s\n", outStr);
    
    return outStr;
}
