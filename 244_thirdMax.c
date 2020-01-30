int thirdMax(int* nums, int numsSize)
{
    int i = 0;
    
    long a = LONG_MIN, b = LONG_MIN, c = LONG_MIN;
    
    while(i < numsSize)
    {
        if(nums[i] == a || nums[i] == b || nums[i] == c)
            ;
        else if(nums[i] > a)
        {
            c = b;
            b = a;
            a = nums[i];
        }
        else if(nums[i] > b)
        {
            c = b;
            b = nums[i];
        }
        else if(nums[i] > c)
        {
            c = nums[i];
        }
        
        //printf("%d %d %d\n", a, b, c);
        
        i++;
    }
    
    if(c != LONG_MIN)
        return c;
    
    return a;
}


