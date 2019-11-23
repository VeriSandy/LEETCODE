int fib(int N)
{
    if(N <= 1)
        return N;
    
    int a = 0, b = 1, c;
    
    while(N >= 2)
    {
        c = a + b;
        a = b;
        b = c;
        N--;
    }
    return c;
}
