
//using binary search approach
int searchInsert(int* nums, int numsSize, int target)
{
    if(numsSize == 0)
        return 0;
    if(target > nums[numsSize -1])
        return numsSize;
    if(target < nums[0])
        return 0;
    
    int i = 0;
    numsSize--;
    
    
    /*
    Note the condition here, this is not start <= end
    Start <= end, might end up in a loop 
    think about the case 
    [1,3,4,5] and look for 5 or 6
    In binary search start <= end condition applies 
    and in next loop if required should either start at mid +1
    or end at mid -1. Not, end at mid or start with mid.
    This will end up in a loop in some situations.
    
    Take this exmaple and use Binary search with this conidion start <= end
    and start at end and end at mid.
    [1,3,4,5] and look for 5 or 6
    
    Binary search
    while(i <= numsSize)
    {
        if(nums[(i+numsSize)/2] == target)
            return (i+numsSize)/2;
        else if(nums[(i+numsSize)/2] > target)
        {
            numsSize =  (i+numsSize)/2; 
        }
        else
            i = (i+numsSize)/2;
    }
    
    */
    
    //This condition will end always in two number array
    while(i+1 < numsSize)
    {
        if(nums[(i+numsSize)/2] == target)
            return (i+numsSize)/2;
        else if(nums[(i+numsSize)/2] > target)
        {
            numsSize =  (i+numsSize)/2; 
        }
        else
            i = (i+numsSize)/2;
    }
    
    if(nums[numsSize] < target)
        return numsSize +1;
    else if(nums[i] >= target)
        return i;
    else
        return numsSize;
}

=========================================
//Using linear search

int searchInsert(int* nums, int numsSize, int target)
{
    if(numsSize == 0)
        return 0;
    
    if(target > nums[numsSize -1])
        return numsSize;
    
    int i = 0, temp = numsSize;
    int mid = 0;
    
    while(i < temp && target > nums[i])
    {
        i++;
    }
    
    return i;
}


