/*
Next Permutation --

1. Find out all the permutations. Then select the next one.

2. See carefully, you just need to find lexicographically next greater number except one case when array is sorted in decreasing order.
 
Here scan array from right, find the first element when a[i] < a[i+1]. If we swap these two numbers we should be done. But to get the lexicographically next greater number, swap a[i] with just greater than a[i], i.e a[j].

Another point, after ith element, array should be in increasing order. So sort it.

*/

int compare(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

void nextPermutation(int* nums, int numsSize)
{
    if(numsSize <= 1) return;
    
    int i = numsSize -2, flag = 0, smallest = nums[i], j = 0;
    
    while(i >= 0)
    { 
        if(nums[i] < nums[i+1])
        {
            //Find the smallest greater than nums[i] on the right side.
            j = i+2;
            smallest = i+1;
            while(j < numsSize && nums[j] > nums[i])
            {
                if(nums[smallest] > nums[j])
                    smallest = j;
                j++;
            }
            
            int temp = nums[i];
            nums[i] = nums[smallest];
            nums[smallest] = temp;
            
            flag = 1;
            
            //After Swap, sort the array. So min would be just after that.
            qsort(&nums[i+1], numsSize - (i+1), sizeof(int), compare);
            break;
        }
        i--;
    }
    
    if(flag == 0)//means, already in decreasing order.
    {
        qsort(nums, numsSize, sizeof(int), compare);
    }
    return;
}
