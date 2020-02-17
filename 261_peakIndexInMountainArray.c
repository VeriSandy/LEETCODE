

int peakIndexInMountainArray(int* a, int ASize)
{
    int l = 0, r = ASize -1, mid = 0;
    
    while(l <= r)
    {
        mid = (l+r)/2;
        
        if(a[mid] > a[mid -1] && a[mid] > a[mid+1])
        {
            return mid;
        }
        
        else if(a[mid] < a[mid+1])
            l = mid+1;
        
        else if(a[mid -1] > a[mid])
            r = mid -1;
    }
    
    return mid;
}


