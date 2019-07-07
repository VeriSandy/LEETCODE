/*
Given an array, rotate the array to the right by k steps, where k is non-negative.
Example 1:
Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

1. Take temporary array, copy k elements, shift other elements back in array and copy back elements from temorary array 
to original array. Need Space here.
2. Shift elements, one by one. O(k*n) 
3. A Juggling Algorithm) - Instead of moving one by one, divide the array in different sets where number of sets is equal to 
GCD of n and d and move the elements within sets. O(n).

*/

int GCD(int a, int b)
{
    if(b == 0) return a;
    
    return GCD(b, a%b);
}
void rotate(int* nums, int numsSize, int k){
    int i = 0, j = 0, ii = 0, temp;
    
    if(numsSize == 0 || k == numsSize || k <= 0 ) return;
        
    if(k > numsSize)
        k = k%numsSize;
    
    k = numsSize - k;//some manipulation for shift right.
    //k right shift is equivalent to shifting (k-n)th element back.
    
    int MyGCD = GCD(k, numsSize);
    //printf("%d %d %d", MyGCD, k, numsSize);
    for(i = 0 ; i < MyGCD; i++)
    {
        temp = nums[i];
        ii = i;
        while(1)
        {
            j = (ii+k)%numsSize;
            if(j == i)//came back where started
                break;
            nums[ii] = nums[j];
            ii = j;//move to next element 
        }
        nums[ii] = temp;
    } 
    return nums;
}
