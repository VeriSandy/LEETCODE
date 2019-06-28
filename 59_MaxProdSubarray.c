/*
//kadane' algorithm will not work here.
//as there can be negative elememnts
//and sign changes if even no of negatives are there.

// ex - [2, 0, -1, -10, -5]
// [-2,-1,-5,-3]
// [2, -5, -3]


traverse array from left to right keeping two variables minVal and maxVal which represents the minimum and maximum product value till the ith index of the array. Now, if the ith element of the array is negative that means now the values of minVal and maxVal will be swapped as value of maxVal will become minimum by multiplying it with a negative number. Now, compare the minVal and maxVal.

The value of minVal and maxVal depends on the current index element or the product of the current index element and the previous minVal and maxVal respectively.

*/
int max(int a, int b)
{
    return a>b?a:b;
}

int min(int a, int b)
{
    return a>b?b:a;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int maxProduct(int* nums, int numsSize)
{
    int maxProd = 1;    
    int curMax = 1;
    int curMin = 1;
    
    int i = 0;    
    if(numsSize < 0) return 0;
    if(numsSize == 1) return nums[0];
    
    maxProd = nums[0];
    curMax = nums[0];
    curMin = nums[0];
    
    for(i = 1; i < numsSize; i++)
    {
        if(nums[i] < 0)
            swap(&curMax, &curMin);
        
        curMax = max(curMax*nums[i], nums[i]);
        curMin = min(curMin*nums[i], nums[i]);
        
        if(maxProd < curMax)
            maxProd = curMax;
    }
    
    return maxProd;
}

