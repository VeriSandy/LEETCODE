/*

Closest divisor(whose product is num) are when we have complete sqare root.
like 25 
then 5 5 are the Closest divisor whose product is 125.

A perfect square would have a side of SQRT(X) so start from there and work downward.

int X = ...
for(int i=sqrt(x);i>0;i--) {
  // integer division discarding remainder:
  int j = X/i;
  if( j*i == X ) {
    // closest pair is (i,j)
    return (i,j);
  }
}

*/

int ABS(int a)
{
    return a>0?a:-a;
}

int* closestDivisors(int num, int* returnSize){

    int y1= 0;
    int x1 = sqrt(num+1);
    int n1 = num+1;

    while(n1%x1)
    {
        x1--;
    }
    

    y1 = n1/x1;
    
    int diff1 = ABS(x1-y1);
    
    
    int x2 = sqrt(num+2);
    
    int n2 = num+2;
    
    while(n2%x2)
    {
        x2--;
    }

    int y2 = n2/x2;
    
    //printf("%d %d\n", x2, y2);
    
    int diff2 = ABS(x2-y2);
    
    
    int *out = malloc(sizeof(int)*2);
    
    if(diff1 < diff2)
    {
        out[0] = x1;
        out[1] = y1;
    }
    else
    {
        out[0] = x2;
        out[1] = y2;
    }
    
    *returnSize = 2;
    return out;
}


