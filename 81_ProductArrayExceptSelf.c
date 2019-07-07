/*
Product of Array Except Self -- 
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:
Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? 
(The output array does not count as extra space for the purpose of space complexity analysis.)

IDEA--
//we need left and right multiplication around that element.
//we can use two seperate arrays, or one array and one temp varaible.
//and use the same array, used to calculate the product
*/
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    
    int *a = malloc(sizeof(int)*numsSize);
    
    *returnSize = numsSize;

    int i = 0, leftside = 1;
    
    a[numsSize -1] = 1;
    
    for(i = numsSize - 2; i >= 0; i--)
        a[i] = nums[i+1] *a[i+1];
    
    leftside = nums[0];
      
    
    for(i = 1; i < numsSize; i++)
    {
        a[i] = a[i] *leftside;
        leftside = leftside*nums[i];
    }
    
    return a;
}
