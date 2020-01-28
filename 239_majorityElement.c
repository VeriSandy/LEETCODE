/*
Use moorey voting algorithm.
At most there can be two majority elements.
*/

int* majorityElement(int* nums, int numsSize, int* returnSize)
{
    int first = INT_MAX, sec = INT_MAX;
    int count1 = 0, count2 = 0;
   
    int i = 0;
    while(i < numsSize)
    {
        if(first == nums[i])
            count1++;
        
        else if(sec == nums[i])
            count2++;
        
        else if(!count1)
        {
            first = nums[i];
            count1++;
        }
        else if(!count2)
        {
            sec = nums[i];
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
        i++;
    }
    
    
    count1 = 0;
    count2 = 0;
    
    i = 0;
    while(i < numsSize)
    {
        if(first == nums[i])
            count1++;
        
        else if(sec == nums[i])
            count2++;
        i++;
    }
    
    int count = 0;
    
    if(count1 > numsSize/3) count++;
    if(count2 > numsSize/3) count++;
    int *out = malloc(sizeof(int)*count);
    
    count = 0;
    if(count1 > numsSize/3) 
        out[count++] = first;
    if(count2 > numsSize/3) 
        out[count++] = sec;
    
    *returnSize = count;
    return out;
}


