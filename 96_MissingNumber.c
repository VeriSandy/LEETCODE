/*
Missing Number

IDEA --
1. Sort and then see missing element.

2. Hashing

3. Make number negative at position and see first positive number in second traversal.
Need to take care of 

1. '0' (if zero is at any pos and that pos is made negative).
2. One element which is greater than the size of array.

*/
int ABS(int a)
{
    return a>0?a:-a;
}

int missingNumber(int* nums, int numsSize){

    int i = 0;
    int ZeroAtPos = 0;//if zero is at any pos and that pos is made negative
    
    for(i = 0; i < numsSize; i++)
    {
        //dont go for element which is greater than the size of array.
        if(ABS(nums[i]) < numsSize)
        {
            nums[ABS(nums[i])] = -nums[ABS(nums[i])];
            if(nums[ABS(nums[i])] == 0)
                ZeroAtPos = 1;
        }
    }
    
    for(i = 0; i < numsSize; i++)
    {
        if(ZeroAtPos == 1)
        {
            if(nums[i] > 0)
                return i;  
        }
        else
        {
            if(nums[i] >= 0)
                return i;
        }
    }
    //if you reached till here, so all should be negative
    //[2,1,0]
    return numsSize;
}
