char *addBinary(char *a, char *b)
{
    int l1 = strlen(a);
    int l2 = strlen(b);
    
    if(l1 == 0) return b;
    if(l2 == 0) return a;
    
    int k = 0, car = 0;
    char *c = NULL;
    if(l2 > l1)
    {
        c = malloc(l2+2);  
        k = l2+1;
    }
    else
    {
        c = malloc(l1+2);
        k = l1+1;
    }
    memset(c,0,k+1);
    
    l1--;
    l2--;
    k--;
    //printf("%d %d %d\n",l1,l2,k);
    while(l1 >= 0 && l2 >= 0)
    {
        if((a[l1] - '0') && (b[l2] - '0'))
        {
            if(car == 1)
                c[k] = '1';
            else
            {
                c[k] = '0';
                car = 1;
            }
        }
        else if((a[l1] - '0') || (b[l2] - '0'))
        {
            if(car == 1)
                c[k] = '0';
            else
                c[k] = '1';
        }
        else
        {
            c[k] = '0';
            if(car == 1)
                c[k] = '1';
            car = 0;
        }
        //printf("%c",c[k]);
        k--;
        l1--;
        l2--;
    }
    
    while(l2 >= 0)
    {
        if((b[l2] - '0'))
        {
            if(car == 1)
                c[k] = '0';
            else
                c[k] = '1';
        }
        else
        {
            c[k] = '0';
            if(car == 1)
                c[k] = '1';
            car = 0;
        }
        //printf("%c",c[k]);
        k--;
        l2--;
    }
    while(l1 >= 0)
    {
        if((a[l1] - '0'))
        {
            if(car == 1)
                c[k] = '0';
            else
                c[k] = '1';
        }
        else
        {
            c[k] = '0';
            if(car == 1)
                c[k] = '1';
            car = 0;
        }
        //printf("%c",c[k]);
        k--;
        l1--;
    }
    if(car)
    {
        c[k] = '1';
        //printf("%c",c[k]);
        k--;
    }
    k++;
    //printf("\n%d\n", k);
    
    return k == 0?c:c+1;
}
