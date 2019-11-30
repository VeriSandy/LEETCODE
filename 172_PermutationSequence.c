/*
1.  Backtracking
    Generate all the permutations and return whichever is required.
    In between, you have to make it in Order it.
    After fixed number, everything should be in increasing order.
2. Is there a way to optimize it ????? There is if you can reach to number nearest to k.
*/

void  MakeInOrder(char *str, int start, int end)
{
    if(start == end) return;
    
    int hash[10] = {0};
    
    int i = start;
    while(str[i])
    {
        hash[str[i] - '0']++;
        i++; 
    }
    
    i = start;
    int j = 1;
    while(str[i])
    {
        while(hash[j] == 0)
            j++;
        
        str[i] = j + '0';
        i++;
        j++;
    }
    return;
}


void PermutationUtil(char *str, int l, int h ,int *k,int *temp)
{
    if(l == h)
    {
        *k -= 1;
        if(*k == 0)
        {
            strcpy(temp, str);
            return;
        }
        return;
    }
    
    int i = l;
    char temp1;
    
    for(i = l; i < h; i++)
    {
        temp1 = str[i];
        str[i] = str[l];
        str[l] = temp1;
        
        //after pos l everything should be in increasing order.
        char buff[h+1];
        memset(buff, 0, h+1);
        strcpy(buff, &str[l+1]);
        MakeInOrder(str, l+1, h-1);
        
        PermutationUtil(str, l+1, h,k,temp);
        strcpy(&str[l+1], buff);
        
        if(*k == 0)
            return;
        
        temp1 = str[i];
        str[i] = str[l];
        str[l] = temp1;
    }
}

char * getPermutation(int n, int k)
{
    int i = 0;
    
    char str[n+1];
    str[n] = '\0';
    
    while(i < n)
    {
        str[i] = i+1 + '0';
        i++;    
    }
    
    char *temp  = malloc(sizeof(int)*(n+1));
    temp[n] = '\0'; 
    
    PermutationUtil(str, 0, n, &k,temp);
    
    return temp;
}   
