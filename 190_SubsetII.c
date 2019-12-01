/*
1. Sort the array.
    Fix from one end, one by one , gernerate recursively till last(keep including the next next elements).
    For duplicates, dont consider that set where current element is same as previous one.
*/

int compare(void *a, void *b)
{
    return (*(int *)a  - *(int *)b);
}

void subsetsWithDupUtil(int *nums, int start, int numsSize, 
                        int *temp, int counter, int *count)
{
    if(start > numsSize) return;
    
    if(counter > 0)
    {
        *count += 1;
        int j = 0;
        while(j < counter)
        {
            //printf("%d ", temp[j]);
            j++;
        }
        //printf("\n");        
    }
    
    int i = 0; 
    for(i = start; i < numsSize; i++)
    {
        if(i > start && nums[i] == nums[i-1])
            continue;
        
        temp[counter] = nums[i];
        counter++;
        //printf("counter = %d %d\n", counter, i);
        subsetsWithDupUtil(nums, i+1, numsSize, temp, counter, count);
        counter--;
    }
    
    return;
}

void FillArrayUtil(int *nums, int start, int numsSize, int *temp, int counter, 
                        int *count, int **out, int *returnColumnSizes)
{
    if(start > numsSize) return;
    
    if(counter > 0)
    {
        out[*count] = malloc(sizeof(int)*counter);
        returnColumnSizes[*count] = counter;
        int j = 0;
        while(j < counter)
        {
            out[*count][j] = temp[j];
            j++;
        }
        *count += 1;
    }
    
    int i = 0; 
    for(i = start; i < numsSize; i++)
    {
        if(i > start && nums[i] == nums[i-1])
            continue;
        
        temp[counter] = nums[i];
        counter++;
        FillArrayUtil(nums, i+1, numsSize, temp, counter, count, out, returnColumnSizes);
        counter--;
    }
    
    return;
}


int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), compare);
    
    int *temp = malloc(sizeof(int)*numsSize);
    int count = 0;
    
    subsetsWithDupUtil(nums, 0, numsSize, temp, 0, &count);
    //printf("count = %d\n", count);
    
    int **out = malloc(sizeof(int *)*(count+1));
    *returnColumnSizes = malloc(sizeof(int)*(count+1));
    
    count = 0;
    FillArrayUtil(nums, 0, numsSize, temp, 0, &count, out, *returnColumnSizes);
    //printf("count = %d\n", count);
    
    out[count] = malloc(sizeof(int)*1);
    (*returnColumnSizes)[count] = 0;
    
    *returnSize = count+1;
    return out;
}

