/*
Ideas --
1. Sort and then remove - O(nlogn) + O(n)
2.  Two pointer approach.
    keep one pointer fixed at elements which are not equal to val.
    O(n)
*/

int removeElement(int* nums, int numsSize, int val)
{
    int i = 0, j = 0;
    
    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] != val)
        {
            nums[j] = nums[i];
            j++;
        }
    }
    
    return j;
}

=================================

int compare(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

int removeElement(int* nums, int numsSize, int val)
{
    if(numsSize <= 0 ) return numsSize;
    qsort(nums, numsSize, sizeof(int), compare);
    
    int i = 0, j = 0;
    int start = -1;
    int end = -1;
    
    while(i < numsSize)
    {
        if(start == -1 && nums[i] == val)
            start = i;
        
        if(nums[i] == val)
            end = i;
        i++;
    }
    
    i = end;
    j = start;
    if(i > -1 && j > -1){
        while( i+1 < numsSize)
        {
            nums[j] = nums[i+1];
            i++;
            j++;
        }}
    
    return (i > -1 && j > -1)?(numsSize - (end -start +1)):numsSize;
}
