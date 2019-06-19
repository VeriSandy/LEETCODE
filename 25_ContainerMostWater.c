/*

Note 1 : When you consider a1 and aN, then the area is (N-1) * min(a1, aN).
Note 2 : The base (N-1) is the maximum possible.

This implies that if there was a better solution possible, it will definitely have the Height greater than min(a1, aN).
 Base * Height > (N-1) * min(a_1, a_N) 
We know that, Base min(a1, aN)
This means that we can discard min(a1, aN) from our set and look to solve this problem again from the start.
If a1 < aN, then the problem reduces to solving the same thing for a2, aN.
Else, it reduces to solving the same thing for a1, aN-1
C++JavaPythonC#PHP
*/

int min(int a, int b)
{
    return a>b?b:a;
}

int max(int a, int b)
{
    return a>b?a:b;
}

int maxArea(int* height, int heightSize)
{    
    if(heightSize <= 0 ) return 0;
    int area = 0;
    int l = 0;
    int r = heightSize - 1;
    
    while(l < r){
        area = max(area, min(height[l], height[r])*(r-l));
        
        if(height[l] < height[r]) l++;
        
        else r--;
    }

    return area;
}



