/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/*
//use sorting and then use two loops
//do not use realloc, as it takes lot of time and memory ==> you will get memory limit exceeded.

*/
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int i = 0;
    int found = 0;
    int l = 0;
    int r = numsSize - 1;
    int count = 0;
    int *size = malloc(sizeof(int));
    *size = 3;
    
    qsort(nums, numsSize, sizeof(int), cmpfunc);

    int k = 0;
    
    for(i = 0; i < numsSize -2; i++)
    {
        if(nums[i] > 0 || nums[i] + nums[i+1] + nums[i+2] > 0) break;
        
        if(i > 0 && nums[i] == nums[i-1])
            continue;
        
        l = i+1;
        r = numsSize - 1;
        while(l < r)
        {
            if(nums[i] + nums[l] + nums[r] == 0)
            {
                count++;
                l++;
                r--;                
                while(l < r && nums[l] == nums[l-1])
                    l++;
                while(l < r && nums[r] == nums[r+1])
                    r--;
            }  
            else if(nums[i] + nums[l] + nums[r] < 0)
                l++;
            else
                r--;
        }
    }
    
    k = 0;
    
    int **arr = malloc(sizeof(int *) * count);
    *returnColumnSizes = malloc(sizeof(int)*count);
    
    for(i = 0; i < count; i++)
    {
        arr[i] = malloc(sizeof(int)*3);
         (*returnColumnSizes)[i] = 3;
    }
         
    for(i = 0; i < numsSize -2; i++)
    {
        if(nums[i] > 0 || nums[i] + nums[i+1] + nums[i+2] > 0) break;
        
        //just to avoid duplicates
        if(i > 0 && nums[i] == nums[i-1])
            continue;
        
        l = i+1;
        r = numsSize - 1;
        while(l < r)
        {
            if(nums[i] + nums[l] + nums[r] == 0)
            {
                //printf("%d %d %d\n", arr[k-1][0], arr[k-1][1], arr[k-1][2]); 
                arr[k][0] = nums[i];
                arr[k][1] = nums[l];
                arr[k][2] = nums[r];
                k++;
                //printf("%d %d %d\n", nums[i], nums[l], nums[r]); 
                l++;
                r--;
                
                //just to avoid duplicates
                while(l < r && nums[l] == nums[l-1])
                    l++;
                //just to avoid duplicates
                while(l < r && nums[r] == nums[r+1])
                    r--;
            }  
            else if(nums[i] + nums[l] + nums[r] < 0)
                l++;
            else
                r--;
        }
    }
    
    *returnSize = count;
    return arr;
}
