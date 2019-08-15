/*
Subsets.

IDEA -- 
1. Get the size of power set
    powet_set_size = pow(2, set_size)
2  Loop for counter from 0 to pow_set_size
     (a) Loop for i = 0 to set_size
          (i) If ith bit in counter is set
               Print ith element from set for this subset
*/

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int** subsets(int* nums, int numsSize, 
              int* returnSize, int** returnColumnSizes)
{   
    int **a;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    
    if(numsSize == 0) return a;
    
    qsort(nums, numsSize, sizeof(int), compare);
    
    //No of subsets ==> pow(2,no of elements)
    //max size of subset is equal to numsSize.
    
    int Total = pow(2, numsSize);
    int i = 0, j = 0, k = 0;
    a = malloc(sizeof(int *)*Total);
    *returnColumnSizes = malloc(sizeof(int)*Total);
    
    for(i = 0; i < Total; i++)
    {
        a[i] = malloc(sizeof(int)*numsSize);

        for(j = 0, k = 0; j < numsSize; j++)
        {
            if(i & (1 << j))
            {
                a[i][k] = nums[j];
                k++;
                printf("%d ", nums[j]);
            }
            //j++;
        }
        (*returnColumnSizes)[i] = k;
        printf("\n");
    }
    
    *returnSize = Total;
    return a;
}


==================================

'''
Python
Back Tracking
'''

class Solution:
    
    def Util(self, nums, _lists, tempList):
        
        l1 = list(tempList)
        
        if l1 not in _lists: #to avoid the duplicates
            _lists.append(l1)
            
        count = 0
        for i in nums:
            tempList.append(i)
            count += 1
            self.Util(nums[count:], _lists, tempList)
            tempList.pop()
    
    def subsets(self, nums: List[int]) -> List[List[int]]:
        _lists = []
        tempList = []
        self.Util(nums, _lists, tempList)
        return _lists
        
