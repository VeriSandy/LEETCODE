/*
1. find all the subarrays and add min from each array.

To get the min of each subarray, array can be sorted first then select the first elment as it would be min of all in a subarraya.

==============================================================================
HOLD ON 
==============================================================================

SORTING WILL NOT WORK HERE, array would be modified, results will differ.
ex - [3,1,2] --> 9 but after sorting it will give answer 10.


2. 
We need something like

sum = SUM(f(i) * A[i])
where f(i) is the number of subarrays, in which A[i] is the minimum.

To get f(i), we need to find out:
left[i], the length of strict bigger numbers on the left of A[i],
right[i], the length of bigger numbers on the right of A[i].

Or 
Use monotonus increasing stack.

consider 
[2, 9, 7, 8, 3, 4, 6, 1]

Previous less element than 3 is 2 and distance between 3 and 2 is 4.
Next less element than 3 is 1 and distance between 3 and 1 is 3.

How many subarrays with 3 being its minimum value? ==> 4*3 times

9 7 8 3 
9 7 8 3 4 
9 7 8 3 4 6 
7 8 3 
7 8 3 4 
7 8 3 4 6 
8 3 
8 3 4 
8 3 4 6 
3 
3 4 
3 4 6

consider 
[2, 9, 7, 3, 4, 3]

Previous less than 3(4th element) is 2 and distance between 3 and 2 is 3.
Next less than 3(4th element) is NO element. So distance is (size - i) i.e. 3

How many subarrays with this 3 being its minimum value? ==> 3*3 times

9 7 3 
9 7 3 4
9 7 3 4 3
7 3 
7 3 4
7 3 4 3
3 
3 4
3 4 3

[2, 9, 7, 3, 4, 3]

How about the last element 3.
Previous less or "equal to" than 3(last element) is 3 and distance between 3 and 3 is 2.
Next less than 3(last element) is NO element. So distance is (size - i) i.e. 1

How many subarrays with 3 being its minimum value? ==> 2*1 times

4 3
3

==============================================================================
Ultimate goal is we need to find out how many times A[i] is used in a subarray.
==============================================================================

https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step

https://leetcode.com/problems/sum-of-subarray-minimums/discuss/170750/C++JavaPython-Stack-Solution

*/

int sumSubarrayMins(int* A, int ASize)
{
    int stackP[ASize], stackN[ASize], left[ASize], right[ASize];
    
    int i = 0, sum = 0, top1 = -1, top2 = -1, j = 0, temp = 0;
    
    for(i = 0; i < ASize; i++)
    {
        //for left of A[i]
        while(top1 != -1 && A[stackP[top1]] > A[i]) 
            top1--;
        
        left[i] = (top1 == -1) ?(i+1):(i - stackP[top1]);
        stackP[++top1] = i;
        
        
        //for right of A[i]
        right[i] = ASize - i;
        while(top2 != -1 && A[stackN[top2]] > A[i])
        {
            temp = stackN[top2];
            top2--;
            right[temp] = i - temp;
        }
        stackN[++top2] = i;  
    }
    
    /*
    for(i = 0; i < ASize; i++)
        printf("%d -> %d and %d -> %d\n", A[i], left[i], A[i], right[i]);
    */
    
    for(i = 0; i < ASize; i++)
    {
        sum = (sum+left[i]*right[i]*A[i])%1000000007;
    }
    return sum%1000000007;
}
