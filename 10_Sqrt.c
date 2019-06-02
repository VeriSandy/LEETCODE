/*
Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

IDEA -- 
1. Use math library sqrt function.
2. start from 1 and calculate till given value is reached.
3. Use binary search algo. 
   find mid, see if mid*mid == x return 
   if mid *mid < x
   sqrt would be in mid+1 to x
   or sqrt would be in 0 to mid-1
*/
=====================

int mySqrt(int x){

    long long start = 1;
    long long end = x;
    int ans = 0;
    
    while(start <= end)
    {
        if(start * start == end)
            return start;
        
        if(start *start < end && ((start + 1) *(start + 1) > end))
        {
            return start;
        }
        start++;
    }
    
    return ans;
}

============================

int mySqrt(int x){

    int start = 0;
    int end = x;
    int mid = 0;
    int ans = 0;
    
    while(start < end)
    {
        mid = (start + end)/2;
        
        if(mid * mid == x)
            return mid;
        
        if(mid * mid < x)
        {
            start = mid+1;
            ans = mid;
        }
        else
            end = mid - 1;
    }
    
    return ans;
}
======================

int mySqrt(int x){

    int i = (int )sqrt(x);
    
    return i;
}


