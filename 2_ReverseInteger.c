/*
Given a 32-bit signed integer, reverse digits of an integer.
Example 1:
Input: 123
Output: 321
Example 2:
Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer 
range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed 
integer overflows.


Remember -- 
TO avoid integer overflow, take long and then see if it beyond the limits of integer

*/


int reverse(int x){
    
    long temp = 0;
    int flag = 0;
    
    int base = pow(2,31);
    
    
    if(x < 0) 
        flag = 1;
    
    while(x)
    {
        temp = temp*10 + x%10;
        x = x/10;
    }
    
    if(temp < -base || temp > base -1)
        return 0;
    
    return temp;
}
