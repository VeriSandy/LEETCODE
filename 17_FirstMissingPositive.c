/*
First Missing Positive
Given an unsorted integer array, find the smallest missing positive integer.
Example 1:
Input: [1,2,0]
Output: 3
Example 2:
Input: [3,4,-1,1]
Output: 2
Example 3:
Input: [7,8,9,11,12]
Output: 1

IDEA -- 
Seperate positive numbers from others
Now change the sign of numbers, at a[a[i]th posiiton
in second traversal, return the position of number which is non negative.

If all numbers are negative, return 1(smallest positive)
*/

int ABS(int i )
{
    return i>0?i:-i;
}

int firstMissingPositive(int* a, int numsSize)
{
    int i = 0, j = 0;
    int flag = 0;
    
    //seperate positive numbers from others.
    for(i = 0 ; i < numsSize; i++)
    {
        if(a[i] <= 0 )
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j++;
        }
        
        if(a[i] > 0 )flag = 1;
    }
    
    if(!flag) //all negative
    {
        return 1;// 1 woule be least positive
    }
    
    //printf("j = %d ", j);

    //change the sign of numbers, at a[a[i]]th posiiton
    //dont forget to take absolute of a[i]
    for(i = j ; i < numsSize; i++)
    {
        if(ABS(a[i]) - 1 < numsSize - j)
        {
            if( a[ABS(a[i]) - 1 + j] > 0 )//dont change sign if number is already negative
                a[ABS(a[i]) - 1 + j] =  -a[ABS(a[i]) - 1 + j];
         
        }
    }
    
   //for(i = j ; i < numsSize; i++)
   //     printf("%d ", a[i]);
    
    for(i = j ; i < numsSize; i++)
    {
        if(a[i] >= 0)
            return (i - j + 1);
    }
    
    //If you got here, you made all negative
    //think initial case [1,2,3] or [1]
    //need to return next number now.
    return numsSize - j + 1;
}
