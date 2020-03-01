/*
1. Two loops. 

2. Hash Table.

3. Sort the array.
*/

int* smallerNumbersThanCurrent(int *nums, int numsSize, int* returnSize)
{
    if(!numsSize)
    {
        *returnSize = numsSize;
        return NULL;
    }
    
    int hash[101] = {0}, i = 0;

    int *out = malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    
    while(i < numsSize)
    {
        hash[nums[i]]++;
        i++;
    }
    
    i = 0;
    int prevCount = 0, temp = 0;
    while(i <= 100)
    {
        if(hash[i])
        {
            temp = hash[i];
            hash[i] = prevCount;
            prevCount += temp;
        }
        i++;
    }
    
    i = 0;
    while(i < numsSize)
    {
        out[i] = hash[nums[i]];
        i++;
    }
    return out;
}


