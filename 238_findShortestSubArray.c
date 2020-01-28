/*
Use hashing to see the frequency of each.
Put Starting index and Ending index also part of that hash table.

Find out the element with max frequency and with min diff in starting and ending index.
*/
typedef struct
{
    int count;
    int start;
    int end;
}HASH;

int findShortestSubArray(int* nums, int numsSize)
{
    HASH *h  = malloc(sizeof(HASH)*50000);
    memset(h, 0, sizeof(HASH)*50000);
    int i = 0;
    int maxFreq = 0;
    
    while(i < numsSize)
    {
        if(!h[nums[i]].count)
            h[nums[i]].start = i;
        
        h[nums[i]].count++;
        h[nums[i]].end = i;
        
        if(maxFreq < h[nums[i]].count)
            maxFreq = h[nums[i]].count;
        
        i++;
    }
    
    i = 0;
    int Shortest = INT_MAX;
    while(i < numsSize)
    {
        if(h[nums[i]].count == maxFreq)
        {
            if(Shortest > (h[nums[i]].end - h[nums[i]].start)+1)
                Shortest = (h[nums[i]].end - h[nums[i]].start)+1;
        }
        i++;
    }
    
    return Shortest;
}


