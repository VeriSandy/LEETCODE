int subtractProductAndSum(int n)
{
    long sum = 0;
    long mul = 1;
    
    int temp = 0;
    
    while(n)
    {
        temp = n%10;
        n = n/10;
        sum += temp;
        mul *= temp;
    }
    
    return mul - sum;
}
