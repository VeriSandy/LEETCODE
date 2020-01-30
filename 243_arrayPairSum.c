/*

SORT them and take the sum of elements at odd indexes.
Sorting would help us to get the max possible element in our account. In case if element is positive.

*/


int compare(void *a, void *b)
{
    return (*(int *)a  - *(int *)b);
}



int arrayPairSum(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), compare);   
    
    int i = 0, sum = 0;
    
    while(i < numsSize)
    {
        sum += nums[i];
        i += 2;
    }
    
    return sum; 
}


