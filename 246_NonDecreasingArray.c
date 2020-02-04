/*
Examine all the elements.

let p is given index for which nums[p] > nums[p+1].

If this is not only once then return false.
If this never happens return true.


Now if it is unique ->

If p == 0, then we can change nums[p] = nums[p+1], return true

If p == len-2, then we can change nums[p+1] = nums[p], return true.

Otherwise(nums[p-1], nums[p], nums[p+1], nums[p+2] will definitely exist)
if nums[p-1] <= nums[p+1] then we can change nums[p] to a number between nums[p-1] and nums[p+1], return true.

or nums[p] <= nums[p+2] then we can change nums[p+1] to a number between nums[p] and nums[p+2], return true.

*/

bool checkPossibility(int* nums, int numsSize)
{
    int i = 0;
    int p = INT_MIN;
    
    while(i < numsSize -1)
    {
        if(nums[i] > nums[i+1])
        {
            if(p != INT_MIN)
                return false;
            
            p = i;
        }
        i++;
    }
    return p == INT_MIN || p == 0 || p == numsSize -2 
            || nums[p-1] <= nums[p+1] || nums[p] <= nums[p+2];
}
