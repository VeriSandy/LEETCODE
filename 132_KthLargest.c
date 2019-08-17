/*
//Kth Largest Element in an Array

One way is sort and find it.
Another - Build a min heap of k elements. at last ,return root.
*/
int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int findKthLargest(int* nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), compare);
    return nums[numsSize -k];
}

//pyhton
/*

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums.sort()
        return nums[-k]
*/
