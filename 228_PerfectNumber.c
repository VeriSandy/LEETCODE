/*
In the given conditions, a number can be maximum devided by half of it.

If number is odd it can only divided by odd numbers and it 
One way of doing it, check from 1 to n/2, which all numbers it can be divided with 
add all those.

*/

bool checkPerfectNumber(int num)
{
    if(num <= 1) return false;
    
    int n = num/2, i = 1;
    long sum = 0;
    
    int odd = num%2;
    
    while(i <= num/2)
    {
        sum += num%i?0:i;
        
        if(odd)
            i += 2;
        else
            i++;
    }
    
    return (num == sum);
}
