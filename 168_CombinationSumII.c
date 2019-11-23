
/*
Ideas --
Sort and use recursion.

To get the elements in array, use one local array.
Keep filling the array. Once you go for iteration fill it and pop it once you come back.

To avoid duplicates, See if there was same element as current, from start to current -1. If yes then do not use this as solution set.

And since we are in sorted order. So just need to check if previous element was same as current element. If yes then do not count it in solution Else march further.
*/

int compare(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}


/*
int ShouldNotContinue(int *a, int start, int n)
{
    int i = start;
    
    while(i < n)
    {
        if(a[i] == a[n])
            return 1;
        
        i++;
    }
    return 0;
}
*/

void UtilCount(int *a, int start, int end, int target, int *count)
{ 
    if(target < 0)
        return;
    
    if(target == 0)
    {
        *count += 1;
        return;
    }
    
    int i = start;
    for(i = start; i < end; i++)
    {
        //To avoid duplicates
        
        /*Since we are in sorted order, 
        so no need to traverse whole array again & again
        if(ShouldNotContinue(a,start,i))
            continue; */
        
        //This will execute much faster if we are in sorted order.
        if(i > start && a[i] == a[i-1])
            continue;
        
        UtilCount(a, i+1, end, target-a[i], count);
    }
    
    return;
}

void UtilCount2(int *a, int start, int end, int target, int *count, 
                int *temp, int k, int **b, int *returnColumnSizes)
{ 
    if(target < 0)
        return;
    
    if(target == 0)
    {
        returnColumnSizes[*count] = k;
        b[*count] = malloc(sizeof(int)*k);
        int j = 0;      
        while(j < k)
        {
            b[*count][j] = temp[j];
            //printf("%d ", temp[j]);
            j++;
        }
        *count += 1;
        //printf("\n");
        return;
    }
    
    int i = start;
    
    for(i = start; i < end; i++)
    {
        //To avoid duplicates
        
        /*Since we are in sorted order, 
        so no need to traverse whole array again & again
        if(ShouldNotContinue(a,start,i))
            continue; */
        
        //This will execute much faster if we are in sorted order.
        if(i > start && a[i] == a[i-1])
            continue;
        
        temp[k] = a[i];
        k++;
        UtilCount2(a, i+1, end, target-a[i], count, temp, k, b, returnColumnSizes);
        k--;
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target,
                      int* returnSize, int** returnColumnSizes)
{
    
    qsort(candidates, candidatesSize, sizeof(int), compare);
    
    int count = 0, k = 0;
    
    //first count no of total sets
    UtilCount(candidates, 0, candidatesSize, target, &count);
    printf("%d\n", count);
    
    int **a = malloc(sizeof(int *)*count);
    *returnColumnSizes =  malloc(sizeof(int)*count);
    int *temp = malloc(sizeof(int)*target);
    count = 0;
    
    //fill in each set in array.
    UtilCount2(candidates, 0, candidatesSize, target, &count,
                  temp,k,a,*returnColumnSizes);
    
    *returnSize = count;
    
    free(temp);
    temp = NULL;
    return a;
}
