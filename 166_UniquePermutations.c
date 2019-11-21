
/*
Ideas -- 

Use backtracking concept for it.
Combinations start with one number(fix that number), fix one number then recursively fix till we left with one number.
Now fix another number and so on.

For Unique combinations -> 
If the next fixed number has been seen in the previous number dont print the permutations for it. 
    
*/
int fib(int n)
{
    int f[n+1];
    f[0] = 0;
    f[1] = 1;
    
    int i = 0;
    
    for(i = 2; i <=n ; i++)
        f[i] = i*f[i-1];
    
    return f[n];
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return ;
}

int ShouldNotSwap(int *a, int start, int n)
{
    int i = start;
    
    while(i < n)
    {
        if(a[n] == a[i])
            return 1;
        i++;
    }

    return 0;
}

void Util(int* nums, int l, int h, int **arr, int *n)
{
    if(l == h)
    {
        int j = 0;
        while(j < h)
        {
            arr[*n][j] = nums[j];
            j++;
        }
        *n += 1;
        return;
    }
    
    int i = l;
    
    for(i = l; i < h; i++)
    {
        if(i > l && ShouldNotSwap(nums, l, i))
            continue;
        
        swap(&nums[i], &nums[l]);
        Util(nums, l+1, h, arr, n);
        swap(&nums[i], &nums[l]);
    }
    return;
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, 
                    int** returnColumnSizes)
{
    //no of max permutations
    int total = fib(numsSize);
    //printf("%d %d %d\n", total, nums[0], nums[1]);
    
    int n = 0, i = 0, min = nums[0], max = nums[0];
    int **a = malloc(sizeof(int *)*total);
    *returnColumnSizes = malloc(sizeof(int)*total);
    for(i = 0; i < total; i++)
    {
        a[i] = malloc(sizeof(int)*numsSize);
        (*returnColumnSizes)[i] = numsSize;
    }
    
    Util(nums, 0, numsSize, a, &n);
    //printf("%d\n", n);
    *returnSize = n;
    return a;
}
