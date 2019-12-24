/*
1. Count no of digits in each number and count all even digit numbers. 

2. Use sprintf, to write number in a buffer and count all even digit numbers.

sprintf return the number of characters printed (excluding the null byte used to end output to strings).
*/

int findNumbers(int* nums, int numsSize)
{
    char temp[512];
    int count = 0;
    int l = 0, i = 0;
    
    while(numsSize > i)
    {
        memset(temp, 0, 512);
        l = sprintf(temp, "%d", nums[i]);
        if(l%2 == 0)
            count++;
        i++;
    }
    
    return count;
}
