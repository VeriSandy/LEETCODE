/*
To make all elements equal - 
Make array sorted

To make all elements equal to A[i]. 
We need to increase all elements lessor than A[i], up to A[i]
and need to decrease all elements greater than A[i], up to A[i].

Need to try this for all the elements to find out the min.

*/

long ABS(long a)
{
    return a>0?a:-a;
}

int compare(void *a, void *b)
{
    return (*(int *)a  - *(int *)b);
}

int minMoves2(int* nums, int numsSize)
{
    if(numsSize <= 1) return 0;
    

    qsort(nums, numsSize, sizeof(int), compare);
    
    
    int i = 0;
    long sum = 0, min  = INT_MAX;
    long temp = 0, sum1[numsSize], temp1 = 0;
    long temp2 = 0, temp3 = 0;
    memset(sum1, 0, sizeof(sum1));
    
    while(i < numsSize)
    {
        sum1[i] = sum + nums[i];
        sum += nums[i];
        i++;
    }
    
    //printf("%d\n", sum);
    
    i = 0;
    while(i < numsSize)
    {
        if(i == 0)
        {
            temp1 = (numsSize-i-1);
            temp = ABS((long)(sum - sum1[i]) - temp1*nums[i]);
            //printf("%d %d %d \n", temp, (sum - sum1[i]), (numsSize-i-1)*nums[i]);
        }
        
        else if(i == numsSize -1)
        {
            temp1 = i;
            temp = ABS((long)(temp1*nums[i]) - (long)sum1[i-1]);
        }
        
        else
        {
            temp1 = i;
            temp2 = (numsSize-i-1);
            temp = ABS( (long)(temp1*nums[i]) -  (long)(sum1[i-1])) //steps tp increase the previous elements to nums[i] 
                  + ABS((long)(sum - sum1[i]) - temp2*nums[i]);
            
        }

        
        //printf("%d\n", temp);
        //
        if(min > temp)
            min = temp;
        i++;
    }
    
    return min;
}
