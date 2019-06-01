/*
Remove Duplicates from Sorted Array

Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Given nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the returned length.

Ideas -- 
1. Use two loops, if element is repeating, shift all elements to left. => O(n2)
2. Use single loop, shift only those elements, which are non repeating, leave all others.
   Use two index approach here. One for keeping track of non repeating elements and other for traversing array.
   If element is repeating then contniue, if not then move it back to non repeating list. 
*/

int removeDuplicates(int* nums, int numsSize){

    int i = 0, j = 0;
    
    
    if(!numsSize) return 0;
    
    for(i = 1 ; i < numsSize ; i++)
    {
        if(nums[i] == nums[j])
            continue;
        nums[++j] = nums[i];
    }
    
   return j+1;
}


