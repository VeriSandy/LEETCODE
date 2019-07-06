/*
Factorial Trailing Zeroes

Given an integer n, return the number of trailing zeroes in n!.
Example 1:
Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.

IDEA --
//no of zeroes will depend on
//no of 5's + no of multiple of 10's
//25 will be counted as two 5's 

//this will be indirectly equal to 
//floor(n/5) + floor(n/25) + floor(n/125) + ....

*/
int trailingZeroes(int n){
    if(n == 0) return 0;
    
    int count = 0;
    int i = 1;
    long mul = 5;
    
    while(n)
    {
        count += (n/mul);
        if(n <= mul)
            break;
        mul = mul *5;
    }

    return count;
}

