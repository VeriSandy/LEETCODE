/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
nums = [2, 7, 11, 15], target = 9
return [0, 1].

Points to remember -- 
1. Input can be negative
2. Index to be searched should be inside the hash table allowed indexes.
3. Target index should be not be same as the given element.
*/

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    if(numsSize <= 1)
    {
        *returnSize = 0;
        return  NULL;
    }
    
    *returnSize = 2;
    int *a = malloc(sizeof(int) *2);
    int i = 0;
    int min = nums[0], max = nums[0];
    
    for(i = 1; i < numsSize; i++)
    {
        if(min > nums[i])
            min = nums[i];
        
        if(max < nums[i])
            max = nums[i];
    }
    
   // printf("%d %d\n", min, max);
    
    int temp = 0;
    int *h = malloc(sizeof(int)*(max - min +1));
    memset(h, -1, sizeof(int)*(max - min +1));
    
    
    for(i = 0; i < numsSize; i++)
            h[nums[i] - min] = i;
    
    
    for(i = 0; i < numsSize; i++)
    {
        temp = target - nums[i];
    
        if((temp - min >= 0) && (temp -min <= max - min) && h[temp - min] > -1 && h[temp - min] != i)
        {
            printf("%d %d\n", temp, temp-min);
            a[0] = i;
            a[1] = h[temp - min];
            free(h);
            h = NULL;
            return a;
        }
    }
    return NULL;
}
