
/*
Merge Sorted Array

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Note:
The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
Output: [1,2,2,3,5,6]

IDEA -- 

Use the rest space in first array. 
Copy all elements from first to last in first array. 
Now use merge sort funda to merge the first arary(on new positioned elements) and second array.
*/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){

    int i = m-1;
    int j = nums1Size-1;
    
    while(i >= 0)
    {
        nums1[j] = nums1[i];
        i--;
        j--;
    }
    
    i = nums1Size-m;
    j = 0;
    int k = 0;
    
    while(i < nums1Size && j < n)
    {
        if(nums1[i] < nums2[j])
        {
            nums1[k] = nums1[i];
            i++;
        }
        else
        {
            nums1[k] = nums2[j];
            j++;            
        }
        k++;
    }
    
    while(j < n)
    {
        nums1[k] = nums2[j];
        j++;
        k++;
    }
    
    while(i < nums1Size)
    {
        nums1[k] = nums1[i];
        i++;
        k++;
    }
    return;
}
