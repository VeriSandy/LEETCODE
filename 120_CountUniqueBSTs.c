/*
Unique Binary Search Trees --
Idea -- 
Use DP here. 

for  n = 3
There will be one root. Other two nodes can be either side or 1-1 can be on both sides.
i.e. 
count[2]*count[0] + count[1]*count[1] + count[0]*count[2]

for n = 4
count[3]*count[0] + count[2]*count[1] + count[1]*count[2] + count[0]*count[3]
Use the same concept for others also. 

Further above realtion can be optimized as most the calculation is repeating two times.
*/
int numTrees(int n)
{
    if(n < 0) return 0;
    
    if(n == 0 || n == 1) return 1;
    
    int num[n+1];
    num[0] = 1;
    num[1] = 1;
    
    int i = 2, j = 1;
    int sum = 0, temp = 0;
    
    while(i <= n)
    {
        num[i] = 0;
        j = 1;
        temp = i/2;
        
        while(j <= temp)
        {

            num[i] += 2*num[j-1] * num[i-j];
            //printf("i = %d, j = %d, j-1 = %d, i-j = %d & num[i] = %d\n", i, j, j-1, i-j, num[i]);
            j++;
        }
        
        if(i%2)
            num[i] += num[j-1] * num[i-j];
        
        i++;
    }
    
    return num[n];
}
