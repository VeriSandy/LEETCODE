//using DP + O(n) space
int max(int a, int b)
{
    return a>b?a:b;
}

int rob(int* nums, int numsSize)
{
    if(numsSize == 0) return 0;
    
    if(numsSize == 1) return nums[0];
    
    int d[numsSize];
    memset(d, 0, sizeof(d));
    
    d[0] = nums[0];
    d[1] = max(nums[0], nums[1]);

    int i;
    for(i = 2; i < numsSize; i++)
        d[i] = max(d[i-1], nums[i] + d[i-2]);
    
    return d[numsSize-1];
}

======================================================
//with constatnt space, using DP
int max(int a, int b)
{
    return a>b?a:b;
}

int rob(int* nums, int numsSize)
{
    if(numsSize == 0) return 0;
    
    if(numsSize == 1) return nums[0];
    
    int first = nums[0];
    int second = max(nums[0], nums[1]);
    int temp = 0;

    int i;
    for(i = 2; i < numsSize; i++)
    {
        temp = max(second, nums[i] + first);
        
        first = second;
        second = temp;
    }
    
    return second;
}


======================================================
//using Recursion
int max(int a, int b)
{
    return a>b?a:b;
}

int rob(int* nums, int numsSize)
{
    if(numsSize == 0) return 0;
    
    if(numsSize == 1) return nums[0];
    
    if(numsSize == 2)
        return max(nums[0], nums[1]);
    
    return max(nums[0]+ rob(&nums[2], numsSize - 2), rob(&nums[1], numsSize - 1));
}
