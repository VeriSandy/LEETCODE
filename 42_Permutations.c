/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 
 //Use backtracing here

int fact(int n)
{
    if(n <= 0 ) return 1;
    
    int f[n+1]; 
    
    int i = 0;
    f[0] = 1;
    
    for(i = 1; i <= n; i++)
        f[i] = i*f[i-1];
    
    return f[n];
}


void PermUtil(int *nums, int l, int h, int total, int **a, int *count)
{
    if(l == h)
    {
        int j = 0;
        int temp = *count;
        while(j < h)
        {
            a[temp][j] = nums[j];
            j++;
        }
        *count += 1;
    }
    
    int i = 0;
    
    for(i = l; i < h; i++)
    {
        int temp = nums[i];
        nums[i] = nums[l];
        nums[l] = temp;
        
        PermUtil(nums,l+1, h, total, a, count);
        
        temp = nums[i];
        nums[i] = nums[l];
        nums[l] = temp;
    }
    return;
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{  
    *returnSize = 0;
    *returnColumnSizes = NULL;
    
    
    if(numsSize == 0) return NULL;
    
    int total = fact(numsSize);
    int count = 0;
        
    int i = 0, j = 0;
    
    
    *returnSize = total;
    
    int **a = malloc(sizeof(int *)*total);
    
    *returnColumnSizes = malloc(sizeof(int) * total);

    for(i = 0; i < total; i++)
    {
        a[i] = malloc(sizeof(int)*numsSize);
        (*returnColumnSizes)[i] = numsSize;    
    }
        
    PermUtil(nums, 0, numsSize, total, a, &count);

    return a;
}
