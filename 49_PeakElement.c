
//use binary search here
//handle corner cases properly

int Peak(int *a, int l, int h )
{
    int mid = -1;
    
    while(l <= h)
    {
        mid = (l+h)/2;
        
        
        if(mid -1 < l && mid+1 >h )
            return mid;
        
        //for 2 elements and mid is 0 
        if(mid -1 < l && a[mid+1] > a[mid])
            return mid+1;
        
        //for 2 elements and mid is 1 
        else if(mid +1 > h && a[mid-1] > a[mid])
            return mid-1;
        
        else if(
            (mid -1 < l && a[mid+1] < a[mid])
                ||
           (mid + 1 > h && a[mid] > a[mid-1])
                ||
            (mid -1 >= l && mid+1 <= h && a[mid] > a[mid-1] && a[mid+1] < a[mid])
          )
            return mid;
        
        else if(mid + 1 <= h && a[mid+1] > a[mid])
            l = mid +1;
        
        else if(mid -1 >= l && a[mid-1] > a[mid])
            h = mid -1; 
    }
    return mid;
}




int findPeakElement(int* nums, int numsSize){
 
    if(numsSize <= 1) return 0;

    return Peak(nums, 0, numsSize-1);
}


