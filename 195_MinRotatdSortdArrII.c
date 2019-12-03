/*
Use binary search

If left array is sorted, keep a[l] as min and right side of the array actual min.
If right array is sorted, keep a[mid] as min and left side of the array actual min.

[HANDS UP] ==> Here problem may come due to duplicate elements.

If sorted array is rotated then one part will always be sorted.

But because of duplicates if you are not sure, which part to hunt.
Then make it behave like linear search.
So complexity will be definitely more than O(logn).
Worst O(n). - Take all the duplicates, only linear search will work out.

NOTE -- This approach will fail if array is sorted in decending order
But as per the problem statement that should not be the case.

2. Linear search can also be used. 
*/
int findMin(int* arr, int numsSize)
{
    if(numsSize == 0) return 0;
    
    if(numsSize == 1) return arr[0];
    
    int l = 0, r = numsSize -1, mid = 0;
    int min = INT_MAX;
    
    /* Linear search
    int min = arr[0];
    
    while(l <= r)
    {
        if(min > arr[l])
            min = arr[l];
        l++;
    }
    */
    
    while(l <= r)
    {
        mid = (l+r)/2;
        
        if(min > arr[mid])
            min = arr[mid];
        
        else if(min > arr[l])
            min = arr[l];
        
        else if(min > arr[r])
            min = arr[r];
        
        //If left part is sorted
        else if(arr[l] < arr[mid])
        {
            if(min > arr[l])
                min = arr[l];
            
            l = mid+1; 
        }
        //If right part is sorted
        else if(arr[mid] < arr[r])
        {
            if(min > arr[mid])
                min = arr[mid];
            r = mid-1;
        }
        //if you do not know what is going on
        //make it behave like linear search
        else
        {
            l++;
            r--;
        }
    }
    return min;
}
