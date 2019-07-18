
/*
Use bitwise SUM or combination of xor and bitwise and.
*/

int getSumUtility(long long a, long long b)
{
    if(b == 0) return a;
    
    while(b)
    {
        long long carry = a & b & 0xffffffff; //limit to integer
        a = a ^ b;
        b = carry << 1;
    }
    
    return a;
}

int getSum(int a, int b)
{
    long long p = a;
    long long q = b;
    return (int) getSumUtility(p, q);
}
