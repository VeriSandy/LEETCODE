


bool containsDuplicate(int* nums, int numsSize)
{
    if(numsSize <= 1) return false;
    
    int i = 0;
    int max = nums[0], min = nums[0];
    
    for(i = 1; i < numsSize; i++)
    {
        if(max < nums[i])
            max = nums[i];
        if(min > nums[i])
            min = nums[i];
    }
    
    int hash[max - min +1];
    memset(hash, 0, sizeof(hash));
    
    
    for(i = 0; i < numsSize; i++)
    {
        hash[nums[i] - min]++;
        if(hash[nums[i] - min] > 1)
            return true;
    }
    return false;
}


