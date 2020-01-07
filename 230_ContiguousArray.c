/*
Treat 0 as -1 and find largest array of sum 0.

Use hashmap here. Store the sum here. max sum can be 50000 and min -50000

If existing is sum is there in hash table that means we have subarray of sum 0 in between from the index where sum was as this one till this index.

Else store sum in hash map.

Also if sum is zero that means this subarray of sum zero has length i+1.

*/

int findMaxLength(int* nums, int numsSize)
{
    if(numsSize <= 1) return 0;
    
    int i = 0, maxLen = 0, sum = 0, curLen = 0;
    int hash[100001] = {0};
    
    while(i < numsSize)
    {
        sum += !nums[i]?-1:1;
        
        //printf("sum [%d] and sum+50000 = %d and %s\n",sum, sum+50000, hash[sum+50000]?"exist":"doesn't exist");
        
        if(!sum)
            curLen = i+1;
        
        else if(hash[sum+50000])
            curLen = (i+1) - hash[sum+50000];
        // Please do not replace the index if it does exist in hash table 
        // as we need the longest array.
        else
            hash[sum+50000] = i+1;//avoid zeroth index
            
        if(curLen > maxLen)
                maxLen = curLen;
        
        i++;
    }
    
    return maxLen;
}
