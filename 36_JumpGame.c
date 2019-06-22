//we just need to find out, if we can move to next element, that's all
//for that just we shouldnt have any place, where we can't move further
//problem will arise only when we have zeros in between

bool canJump(int* nums, int numsSize){
    int i = 0;
    int remain_max = 0;
    
    if(numsSize <= 0 ) return false;
    
    if(numsSize == 1) return true;
    
    
    if(nums[0] == 0) return false;
    
    
    remain_max = nums[0];
        
    for(i = 1; i < numsSize -1; i++)
    {
        remain_max--;
        
        if(remain_max < nums[i])
            remain_max = nums[i];
        
        if(!remain_max)
            return false;
    }

    return true;
}
