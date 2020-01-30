int abs(int a)
{
    return a>0?a:-a;
}

int* findDuplicates(int* nums, int numsSize, int* returnSize)
{
    int i = 0, count = 0, k = 0, max = INT_MIN;
    
    
    while(i < numsSize)
    {
        //nums[abs(nums[i]) -1] *= -1;
        if(max < nums[i])
            max = nums[i];
        i++;
    }
    
    i = 0;
    max++;
    while(i < numsSize)
    {
        nums[nums[i]%max -1] += max;
        
        if(nums[nums[i]%max -1]/max == 2)
        {
            count++;
            //printf("%d ", nums[i]%max);
        }
        i++;
    }
    

    /*
    i = 0;
    count = 0;
    while(i < numsSize)
    {
        //if(nums[i] > 0)
        if(nums[i]/max == 2)
        {
            count++;
        printf("%d ", i+1);
        }
        i++;
    }
    */
        
   int *out = malloc(sizeof(int)*count);

    i = 0;
    while(i < numsSize)
    {
        //if(nums[i] > 0)
        if(nums[i]/max == 2)
            out[k++] = i+1;
        ;
        i++;
    }
    
    
    *returnSize = count;
    return out;
}


