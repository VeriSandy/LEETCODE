int* decompressRLElist(int* nums, int numsSize, int* returnSize)
{
    
    int NoOfEle = 0;
    int i = 0, j = 0, k = 0;
    
    while(i < numsSize)
    {
        NoOfEle += nums[i];
        i += 2;
    }
    
    printf("%d\n",NoOfEle);
    
    int *out = malloc(sizeof(int)*NoOfEle);
    
    i = 0;
    while(i < numsSize-1)
    {
        j = 0;
        while(j < nums[i])
        {
           out[k++] = nums[i+1];
           j++;
        }
        i += 2;
    }
    
    *returnSize = NoOfEle;
    return out;
    
    //return NULL;
}

