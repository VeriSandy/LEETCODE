/*
Majority Element --
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.

IDEA -- 
use moore's voting algorithm
Basic idea of the algorithm is that if we cancel out each occurrence of an element e with all the other elements that are different from e then e will exist till end if it is a majority element.

*/

int majorityElement(int* a, int numsSize){

    int i = 0;
    
    int index = 0;
    int count = 1;
    
    for(i = 1; i < numsSize; i++)
    {
        if(a[index] == a[i])
            count++;
        else
            count--;
        
        if(!count)
        {
            index = i;
            count = 1;
        }
    }
    
    return a[index];
}

