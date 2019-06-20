
//using recursion
double POW(double x, long int n)
{
    if(n == 0) return 1;
    
    if(n%2 == 0)
        return POW(x, n/2) * POW(x, n/2);
    
    return x * POW(x, n/2) * POW(x, n/2);
}

//using iteration
/*
double POW(double x, long int n)
{
    double res = 1;
    
    while(n > 0)
    {
        if(n & 1)
            res = res * x;
        
        n = n>>1;
        x = x*x;
    }
    
    return res;
}

*/

double myPow(double x, int n)
{
    if(n >= 0)
        return POW(x, n);
    
    long int n1 = ((long)n)*-1;
    
    return 1/POW(x, n1);
}


