//Counting Bits

int* countBits(int num, int* returnSize)
{
    int *a = malloc(sizeof(int)*(num+1));
    int i = 1, count = 0, j = 0;
    
    a[0] = 0;
    
    while(i <= num)
    {
        count = 1;
        j = i;
        while((j = j & (j-1)))
            count++;
        a[i] = count;
        i++;
    }
    *returnSize = num+1;
    return a;
}
