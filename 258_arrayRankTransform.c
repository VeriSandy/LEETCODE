

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* arrayRankTransform(int* arr, int arrSize, int* returnSize)
{
    if(arrSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    
    int min = INT_MAX, max = INT_MIN, i = 0;
    
    while(i < arrSize)
    {
        if(min > arr[i])
            min = arr[i];
        
        if(max < arr[i])
            max = arr[i];
        
        i++;
    }
    
    int *hash = malloc(sizeof(int)*(max - min +1));
    memset(hash, 0, sizeof(int)*(max - min +1));
    
    i = 0;
    while(i < arrSize)
    {
        hash[arr[i] - min] = 1;
        i++;
    }
    
    i = 0;
    int count = 1;
    while(i < max - min +1)
    {
        hash[i] = hash[i]?count++:0;
        //printf("%d\n", hash[i]);
        i++;
    }
    
    i = 0;
    int *out = malloc(sizeof(int)*arrSize);
    *returnSize = arrSize;
    
    
    while(i < arrSize)
    {
        out[i] = hash[arr[i] -min];
        //printf("%d\n", out[i]);
        i++;
    }
    
    return out;
}


