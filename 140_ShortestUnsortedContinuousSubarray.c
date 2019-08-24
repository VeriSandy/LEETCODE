/*
Shortest Unsorted Continuous Subarray --
Idea -- 
1. Use Sorting
    a. Sort the array and see which all elements are not at correct position.
    b. First incorrect position will be start and last incorrect position will be end.
2. Using Hash, in hashing, elements will already be sorted.
*/

int compare(void const *a, void const *b)
{
    return *(int *)a - *(int *)b;
}

/*
Sorting --
int findUnsortedSubarray(int* nums, int numsSize)
{
    if(numsSize <= 0) return 0;
    
    
    int i = 0, j = 0, start = 0, end = 0, first = 0;
    
    int temp[numsSize];
    
    for(i = 0; i < numsSize; i++)
        temp[i] = nums[i];
    
    qsort(temp, numsSize, sizeof(int), compare);
    
    int posTemp = 0, posNums = 0;
    
    for(i = 0; i < numsSize; i++)
    {
        if(temp[i] != nums[i])
        {
            if(!first)
            {
                start = i;
                first = 1;
            }
            end = i;
        }
    }
    
    //printf("%d %d\n", start, end);
    return start == end?0:end -start +1;
}
*/
//Using hash
int findUnsortedSubarray(int* nums, int numsSize)
{
    if(numsSize <= 0) return 0;
    
    int i = 0, j = 0, start = 0, end = 0, first = 0;
    int Min = nums[0], Max = nums[0];
    for(i = 1; i < numsSize; i++)
    {   
        if(Min > nums[i])
            Min = nums[i];
        if(Max < nums[i])
            Max = nums[i];
    }

    int *hash = malloc(sizeof(int)*(Max-Min+1));
    memset(hash, 0, sizeof(int)*(Max-Min+1));   
    
    for(i = 0; i < numsSize; i++)
        hash[nums[i] - Min]++;

    for(i = 0; i < numsSize; i++)
    {
        while(j <= Max-Min+1 && !hash[j])
            j++;
        
        //printf("%d %d\n", j, nums[i]);
        hash[j]--;
        if((j+Min) != nums[i])
        {
            if(j > 0) j--;
            if(!first)
            {
                start = i;
                first = 1;
            }
            end = i;
        }
    }
    //printf("%d %d\n", start, end);
    return start == end?0:end -start +1;
}
