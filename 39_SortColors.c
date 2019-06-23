

void sortColors(int* nums, int numsSize){

    int temp = 0;
    
    if(numsSize <= 1) return;

    int l = 0, r = numsSize - 1, mid = 0;
    
    
    while(mid <= r)
    {
        if(nums[mid] == 2)
        {
            temp = nums[mid];
            nums[mid] = nums[r];
            nums[r] = temp;
            
            r--;
        }        
        else if(nums[mid] == 0)
        {
            temp = nums[l];
            nums[l] = nums[mid];
            nums[mid] = temp;
            
            l++;
            mid++;
        }
        else
            mid++;
    }
    
    return;
}


