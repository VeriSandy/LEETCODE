int compare(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), compare);
    
    int i = 0, j = 0, l = 0, r = 0, k = 0;
    int count = 0, temp = 0;
    
    for(i = 0; i < numsSize -3; i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        
        for(j = i+1; j < numsSize -2; j++)
        {
            if(j > i+1 && nums[j] == nums[j-1]) continue;
            
            l = j+1;
            r = numsSize - 1;
            while(l < r)
            {
                temp = nums[i] + nums[j] + nums[l] + nums[r];
                if(temp == target)
                {
                    l++;
                    r--;
                    count++;
                    
                    while(l < r && nums[l] == nums[l-1])
                        l++;
                    while(l < r && nums[r] == nums[r+1])
                        r--;
                }
                else if(temp > target)
                    r--;
                else
                    l++;
            }
        }
    }
    
    int **a = malloc(sizeof(int *)*count);
    *returnColumnSizes = malloc(sizeof(int)*count);
    
    for(i = 0; i < count; i++)
    {
        a[i] = malloc(sizeof(int)*4);
        (*returnColumnSizes)[i] = 4;
    }
    
    for(i = 0; i < numsSize -3; i++)
    {
        //avoid duplicates
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for(j = i+1; j < numsSize -2; j++)
        {
            //avoid duplicates
            if(j > i+1 && nums[j] == nums[j-1]) continue;
            
            l = j+1;
            r = numsSize - 1;
            while(l < r)
            {
                temp = nums[i] + nums[j] + nums[l] + nums[r];
                if(temp == target)
                {
                    a[k][0] = nums[i];
                    a[k][1] = nums[j];
                    a[k][2] = nums[l];
                    a[k][3] = nums[r];
                    
                    l++;
                    r--;
                    k++;
                    
                    //avoid duplicates
                    while(l < r && nums[l] == nums[l-1])
                        l++;
                    //avoid duplicates
                    while(l < r && nums[r] == nums[r+1])
                        r--;
                }
                else if(temp > target)
                    r--;
                else
                    l++;
            }
        }
    }
    *returnSize = count;
    return a;   
}
