/*
To make all elements equal. 

We can think another way that rather than increasing n-1 elements as one move, decrease only one element.

1.  Find out at each step which element is highest and then decrease it by 1.
    This will take n2.

2.  Another mathematical way can be - 
    Decrease all the elements to smallest element and count the moves.
    Since there is only operation allowed so we can only decrease.
    (Not like Minimum Moves to Equal Array Elements II).
    And we can only make all the elements equal by making all other elements equal to SmallestElement.
    
    So get the sum of other n-1 elements. ==> Sum
    Moves = Sum - (n-1)*SmallestElement
*/

int minMoves(int* nums, int numsSize)
{
    if(numsSize <= 1) return 0;
    
    int i = 0;
    long sum = 0, min  = nums[0];
    
    while(i < numsSize) sum += nums[i++];
    
    i = 0;
    while(i < numsSize)
    {
        if(min > nums[i]) min = nums[i];
        i++;
    }
    
    long temp = numsSize*min;
    
    return (sum - temp);
}
