/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int first(int* nums, int numsSize, int target)
{
    int i = 0, l = 0, h = numsSize -1;
    int mid = 0;

    printf("%d %d\n", l, h);
    
    while(l <= h)
    {
        mid = (l+h)/2;
        
        if(nums[mid] == target)
        {
            if(mid - 1 >= l && nums[mid - 1] == target)
                h = mid - 1;
            else
                return mid;
        }
        else if(nums[mid] < target)
            l = mid +1;
        else
            h = mid -1;
    }
    
    return -1;
}


int last(int* nums, int numsSize, int target)
{
    int i = 0, l = 0, h = numsSize -1;
    int mid = 0;

    while(l <= h)
    {
        mid = (l+h)/2;
        
        if(nums[mid] == target)
        {
            if(mid + 1 <= h && nums[mid + 1] == target)
                l = mid + 1;
            else
                return mid;
        }
        else if(nums[mid] < target)
            l = mid +1;
        else
            h = mid -1;
    }
    
    return -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){

    int *a = malloc(sizeof(int) *2 );
    
    *returnSize = 2;
    
    a[0] = first(nums, numsSize, target);
    
    a[1] = last(nums, numsSize, target);

    return a;
}
