/*
Find the Duplicate Number

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. 
Assume that there is only one duplicate number, find the duplicate one.
Example 1:
Input: [1,3,4,2,2]
Output: 2
Example 2:
Input: [2,2,2,2,2]
Output: 2

Note:
  You must not modify the array (assume the array is read only).
  You must use only constant, O(1) extra space.
  Your runtime complexity should be less than O(n2).
  There is only one duplicate number in the array, but it could be repeated more than once.


//IDEA -- if array is modifiable, then there can be lot many approaches. Like sorting, adding some value at indexes.

//Here in this problem, only below approach suits.
//So, here is an an approach that is based on Floyd’s cycle finding algorithm. We use this to detect loop in a linked list.
//The idea is to consider array items as linked list nodes.
//This idea is taken from 
//https://www.geeksforgeeks.org/find-duplicates-constant-array-elements-0-n-1-o1-space/

*/

int findDuplicate(int* nums, int numsSize)
{
    if(numsSize == 1) return nums[0];
    
    int slow = nums[0];
    int fast = nums[nums[0]];
    
    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    fast = 0;
    
    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    
    return slow;
}

