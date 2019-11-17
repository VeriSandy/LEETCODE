//Target
//Try sorting + two loops
//Follow the same method as triplets sum
//Just update the sum once you have closest sum.

int cmpfunc(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

int ABS(int a)
{
    return a>0?a:-a;
}

int threeSumClosest(int* nums, int numsSize, int target)
{
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    
    int i = 0,l = 0, r = 0, sum = 0;
    sum = nums[i] + nums[i+1] + nums[numsSize-1];
    int temp = 0;
    int diff = ABS(sum - target);
    
    for(i = 0; i < numsSize -2; i++)
    {
        l = i+1;
        r = numsSize -1;
        while(l < r)
        {
            temp = nums[i] + nums[l] + nums[r];
            if(ABS(temp - target) < diff)
            {
                sum = temp;
                diff = ABS(temp - target);
            }
            
            if(temp == target)
            {
                l++;
                r--;
            }
            else if(temp > target)
                r--;
            else
                l++;
        } 
    }
    return sum;
}


