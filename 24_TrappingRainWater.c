


int min(int a, int b)
{
    return a>b?b:a;
}

int trap(int* height, int heightSize){
     
    if(heightSize <= 0 ) return 0;
    
    int left[heightSize];
    int right[heightSize];
    int total = 0;
    
    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));
    
    
    int i = 0;
    
    left[0] = height[0];
    
    for(i = 1; i < heightSize; i++)
    {
        if(height[i] > left[i-1])
            left[i] = height[i];
        else
            left[i] = left[i-1];
    }
    
    right[heightSize-1] = height[heightSize-1];
    
    for(i = heightSize -2 ; i >= 0; i--)
    {
        if(height[i] > right[i+1])
            right[i] = height[i];
        else
            right[i] = right[i+1];
    }
    
    //calculate total water trapped
    //min of(left max, right max) - height of that bar
    for(i = 0; i < heightSize; i++)
        total +=  min(left[i], right[i]) - height[i];
    
    return total;
}


