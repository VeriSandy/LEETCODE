int divide(int dividend, int divisor){
    
    long temp1 = dividend, temp2 = divisor, prev = 0 ;
    long count = 1;
    long temp = divisor;
    
    
    if(!dividend) return 0;
    
    int sign1 = 0; //for dividend
    int sign2 = 0; //for divisor
    
    
    if(dividend < 0) 
    {
        sign1 = 1;
        temp1 = ((long)dividend)*-1; 
    }
    
    if(divisor < 0 ) 
    {
        sign2 = 1;
        temp2 = ((long)divisor)*-1; 
        temp = ((long)divisor)*-1; 
    }
    
    if(temp1 < temp2) return 0;
    
    //if multiplication and division is not allowed
    //then use addition
    //double it everytime
    while(1)
    {
        prev = temp2;
        //for ex if temp2 is 3
        //temp2 would be 6, 12, 24, 48, 96
        //this way we can save some iterations
        temp2 = temp2 + temp2;

        if(temp2 > temp1)
            break;
        
        count = count + count;
        
        if(count > ((long)INT_MAX + 1))
            break;
    }
    
    //printf("%ld %ld %ld %ld", prev, count, temp1, INT_MAX + 1);
    
    while(prev <= temp1)
    {
        prev += temp;
        if(prev > temp1)
            break;
        count++;
        
        if(count > ((long)INT_MAX + 1))
            return INT_MAX;
    }
    
    //if both signs are not same
    
    if(sign1 != sign2)
        count = count* -1;
    
    if(count < 0 && count < INT_MIN)
        return INT_MAX;
    
    if(count > 0 && count > INT_MAX) return INT_MAX;
    
    return count;
}


