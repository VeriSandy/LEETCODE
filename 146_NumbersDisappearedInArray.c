/*
//Find All Numbers Disappeared in an Array

Ideas --
n == size of array.
a[i] is bw 1 to n. 
Some elements appear twice there.
make the elements negative at the positions as elements in array.
print the the positive elements in array.
*/

int Abs(int a)
{
    return a>0?a:-a;
}

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
    int *a = NULL;
    *returnSize = 0;
    if(numsSize <= 0) return a;
    
    int i = 0, count = 0, k = 0;
    for(i = 0; i < numsSize; i++)
    {
        if(nums[Abs(nums[i]) -1] > 0)
            nums[Abs(nums[i]) -1] = -nums[Abs(nums[i]) -1];
        else
            count++;
    }
    
    a = malloc(sizeof(int)*count);
    
    for(i = 0; i < numsSize; i++)
    {
        if(k == count)
            break;
        if(nums[i] > 0)
        {
            //printf("%d %d \n", i+1, count); 
            a[k++] = i+1;
        }
        
    }
    *returnSize = count;
    return a;
}
