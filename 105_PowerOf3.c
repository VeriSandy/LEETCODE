/*
1. Using loop
2. Use integer limitations
*/
bool isPowerOfThree(int n)
{
    if(n == 0) return 0;
    
    while(n%3 == 0)
        n /= 3;
    
    return n == 1;
}
==============
//Use integer limitations
bool isPowerOfThree(int n)
{
    if(n == 1) return true;

    if(n < 3) return false;

    int maxPowerAllowed = (int)log(INT_MAX)/log(3);
    printf("%d\n", maxPowerAllowed);

    int temp = pow(3, maxPowerAllowed);

    return temp%n == 0;
}
