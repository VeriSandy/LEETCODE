/*
Take care of 0, 1, negative numbers.
Check if numbers are only divisible by 2, 3 or 5. 
To check if num is divisble by k, keep deviding num by k and see if at last you get 1.
*/

int maxDivide(int a, int b) 
{ 
  while (a%b == 0)
      a = a/b;  
  return a; 
} 

bool isUgly(int num)
{
    if(num <= 0) return false;
    if(num == 1 ) return true;
    
    
    num = maxDivide(num, 2);
    num = maxDivide(num, 3);
    num = maxDivide(num, 5);
    
    return num == 1;
}
