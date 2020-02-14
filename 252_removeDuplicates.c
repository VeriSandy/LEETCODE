//Use stack
char * removeDuplicates(char *S)
{
    int l = strlen(S), i = 0, j = -1, count = 0;
    char stk[l+1];
    
    while(i < l)
    {
        if(j > -1 && S[i] == stk[j])
        {
            j--;
        }
        else
            stk[++j]  = S[i];
        i++;
    }
    
    if(j < 0)
        return "";
    
    //printf("%d\n", j);
    char *out = malloc(j+2);
    out[j+1] = '\0';
    
    while(j >= 0)
    {
        out[j] = stk[j];
        //printf("%d\n", j);
        j--;
    }
    
    return out;
}


