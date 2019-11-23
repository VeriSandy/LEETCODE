/*
since there are duplicates, so it wouldnt be logn always.
worst case complexity O(n).

1. Use linear search
2. Use binary search
*/

bool search(int* nums, int numsSize, int target)
{
    if(numsSize == 0)
        return false;
    
    int l = 0, h = numsSize -1, mid = 0;
    
    while(l <= h)
    {
        mid = (l+h)/2;
        
        if(nums[mid] == target || nums[l] == target 
           || nums[h] == target) 
                return true;
        
        //if left is sorted
        if(nums[l] < nums[mid])
        {
            if(target > nums[l] && target < nums[mid])
                h = mid -1;
            else
                l = mid+1;
        }
        //if right is sorted
        else if(nums[mid] < nums[h])
        {
            if(target > nums[mid] && target < nums[h])
                l = mid + 1;
            else
                h = mid-1;
        }
        else//do not know
        {
            l++;
            h--;
        }
    }
    return false;
}

=====================================

//using linear search
bool search(int* nums, int numsSize, int target)
{
    if(numsSize == 0)
        return false;
    
    int l = 0, h = numsSize -1, mid = 0;
    
    while(l <= h)
    {
        if(nums[l] == target)
            return true;
        l++;
    }
    
    return false;
}
