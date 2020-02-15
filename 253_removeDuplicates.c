/*
Use Stack
*/

char * removeDuplicates(char * s, int k)
{
    int l = strlen(s);
    
    char *stk = malloc(l+1);
    int i = 0, j = -1, cur = 0, count = 0 ;
    
    while(i < k-1 && i < l)
    {
        stk[++j] = s[i];
        i++;
    }
    
    //printf("%d %d\n", i,j);
    
    while(i < l)
    {
        if(j >= k -2)
        {
            cur = j;
            count = 0;
            while(count < k-1 && stk[cur] == s[i])
            {
                //printf("%d %d %c %c\n", cur,count, stk[cur], s[i]);
                cur--;
                count++;
            }
            if(count == k-1)
                j = j - count;
            else
            {
                stk[++j] = s[i];
                //printf("Pushed -- %d %d %c\n",i,j,stk[j]);
            }
            
            //printf("%d %d\n", i,j);
        }
        else
        {
            stk[++j] = s[i];
            //printf("Push -- %d %d %c\n",i,j,stk[j]);
        }
        i++;
    }
    
    char *out = malloc(j+2);
    out[j+1] = '\0';
    i = j;
    while(i >= 0)
    {
        out[i] = stk[i];
        i--;
    }
    
    //printf("%s\n", out);
    return out;
}


