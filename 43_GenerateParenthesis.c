/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//We can use recursion

int fact(int n)
{
    if(n <= 0 ) return 1;  
    int f[n+1];  
    int i = 0;
    f[0] = 1;
    for(i = 1; i <= n; i++)
        f[i] = i*f[i-1];
    return f[n];
}

void PermUtil(char *s, int pos, int open, int close, int h, char **a, int *count)
{
    if(close == h)
    {
        strcpy(a[*count], s);
        //printf("%s\n", s);
        s[h] == '\0';
        *count += 1;
        return;
    }
    
    if(open > close)
    {
        s[pos] = ')';
        PermUtil(s, pos+1, open, close+1, h, a, count);
    }
    
    if(open < h)
    {
        s[pos] = '(';
        PermUtil(s, pos+1, open+1, close, h, a, count);    
    }
    return;
}

char ** generateParenthesis(int n, int* returnSize)
{  
    *returnSize = 0; 
    if(n == 0) return NULL;
    
    //form a string
    int i = 0;
    int total = fact(n);//this is approximate no, it would be lessor than this
    int count = 0;
    int l = 2*n;
    
    char str[l+1];
    memset(str, 0, sizeof(str));
    
    char **a = malloc(sizeof(char *)*total);
    for(i = 0; i < total; i++)
        a[i] = malloc(sizeof(char)*(l+1));
     
    PermUtil(str, 0, 0, 0, n, a, &count);

    //printf("%d\n", count);
    
    *returnSize = count; 
    return a;
}

