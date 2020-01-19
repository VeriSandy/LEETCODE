/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int NoZero(int n)
{
    while(n)
    {
        if(!(n%10)) return 0;
        n = n/10;
    }
    
    return 1;
}

int* getNoZeroIntegers(int n, int* returnSize)
{
    *returnSize = 2;
    int *out = malloc(sizeof(int)*2);
    
    int i = 1;
    
    while(i < n)
    {
        if(NoZero(i) && NoZero(n-i))
            break;
        i++;
    }
    
    out[0] = i;
    out[1] = n-i;
    return out;
}
