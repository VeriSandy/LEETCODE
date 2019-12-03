/*
Use binary search

If left array is sorted, keep a[l] as min and right side of the array actual min.
If right array is sorted, keep a[mid] as min and left side of the array actual min.

NOTE -- This approach will fail if array is sorted in decending order
But as per the problem statement that should not be the case.

*/
int findMin(int* arr, int numsSize)
{
    if(numsSize == 0) return 0;
    
    if(numsSize == 1) return arr[0];
    
    int l = 0, r = numsSize -1, mid = 0;
    int min = INT_MAX;
    while(l <= r)
    {
        mid = (l+r)/2;
        //If left part is sorted
        if(arr[l] <= arr[mid])
        {
            if(min > arr[l])
                min = arr[l];
            l = mid+1;
        }
        //If right part is sorted
        else if(arr[mid] <= arr[r])
        {
            if(min > arr[mid])
                min = arr[mid];
            r = mid-1;
        }
    }
    return min;
}

