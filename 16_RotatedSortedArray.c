/*
Search in Rotated Sorted Array
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).
Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

IDEA --
Remember in sorted rotated array one part would be sorted.
*/
int search(int* nums, int numsSize, int target)
{ 
    int start = 0, end = numsSize -1, mid = 0;
    
    while(start <= end)
    {
        mid = (start + end)/2;
        
        if(nums[mid] == target) return mid;
        
        if(nums[start] <= nums[mid])//if left part is sorted, '=' sign if start and mid are same.
        {
            if(target < nums[mid] && target >= nums[start])//see if you are sure left part
                end = mid-1;
            else //else go to right part
                start = mid +1;
        }
        //else if(nums[mid] <= nums[end]) //if right part is obvious, this is obvious
        else
        {
            if(target > nums[mid] && target <= nums[end])//see if you are sure right part
                start = mid +1;
            else//else got to left part
                end = mid-1;            
        }
    } 
    return -1;
}
