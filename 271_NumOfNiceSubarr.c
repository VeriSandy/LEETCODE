/*
Use Sliding window.
    
To directly count the subarrays with exactly K odd nums is hard but to find the count of subarrays with at most K odd nums is easy.

So the idea is to find the count of subarrays with at most K odd nums, let it be C(K), and the count of subarrays with at most (K – 1) odd nums, let it be C(K – 1) and finally take their difference, C(K) – C(K – 1) which is the required answer.

Count of subarrays with at most K odd nums can be easily calculated through the sliding window technique. 
The idea is to keep expanding the right boundary of the window till the count of odd nums in the window is less than or equal to K and when the count of odd nums inside the window becomes more than K, start shrinking the window from the left till the count becomes less than or equal to K. 
Also for every expansion, keep counting the subarrays as right–left+1 where right and left are the boundaries of the current window.
      
More about this logic.
https://leetcode.com/problems/subarrays-with-k-different-integers/
*/

int atMostK(int* nums, int numsSize, int k)
{
    if(numsSize < k) return 0;
    
    int right = 0, left = 0, count = 0, res = 0;
    
    while(right < numsSize)
    {
        if(nums[right]%2)
            count++;
        
        while(count > k)
        {
            if(nums[left]%2)
                count--;
            
            left++;
        }      
        res += right -left +1;
        right++;
    }   
    
    return res;
}

int numberOfSubarrays(int* nums, int numsSize, int k)
{
    return atMostK(nums,numsSize,k) - atMostK(nums,numsSize,k-1); 
}
