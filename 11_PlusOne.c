/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

IDEA --
Take care carry if any. And if carry goes on till first digit, then one more integer sapce would be needed at the start.
*/

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    if(!digitsSize) 
    {
        *returnSize = 0;
        return NULL;
    }
    int size = digitsSize+1;
    
    *returnSize = digitsSize;
    
    int *a = malloc(sizeof(int)*size);
    memset(a, 0x00, sizeof(int)*size);

    int i = 0, j = size -1;
    int c = 1;
    int temp = 0;
    
    for(i = digitsSize -1; i >=0 ; i--, j--)
    {
        a[j] = (digits[i] + c)%10;
        c = (digits[i] + c)/10;
    }
    
    if(c)
    {
        a[0] = c;
        *returnSize += 1;
        return a;
    }
    
    return &a[1];
}

