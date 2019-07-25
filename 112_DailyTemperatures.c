/*
Daily Temperatures
In nutshell, need to distance of next greater element.
*/

int* dailyTemperatures(int* T, int TSize, int* returnSize)
{
    int *st, *a = NULL;
    int top = -1, i = 0;
    
    st = malloc(sizeof(int)*TSize);
    memset(st, 0, sizeof(int)*TSize);
    a = malloc(sizeof(int)*TSize);
    memset(a, 0, sizeof(int)*TSize);
    top++;
    
    for(i = 1; i < TSize; i++)
    {
        while(top != -1 && T[st[top]] < T[i])
        {
            a[st[top]] = i - st[top];
            //printf("st[top] = %d, a[st[top]] = %d\n", st[top],a[st[top]]);
            st[top] = 0;
            top--;
        }
        st[++top] = i;
        //printf("top = %d, st[top] = %d\n", top, st[top]);
    }
    
    *returnSize = TSize;
    return a;
}
