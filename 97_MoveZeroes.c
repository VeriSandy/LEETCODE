//keep count of zeroth position

void moveZeroes(int* nums, int numsSize){
    
    if(numsSize == 0) return;
    int i = 0, count = 0;
    while(i < numsSize)
    {
        if(nums[i])
            nums[count++] = nums[i];
        i++;
    }
    
    while(count < numsSize)
        nums[count++] = 0;
    
    return;
}

