
/*
To find out the min difference, Find out min differnce from all pairs.

Other way, we need array sorted in increasing order and then find the min diff between two elements. 
==> This would be easiest way as need to find the difference only between two consecutive elements in sorted array. Other absolute differences for an element will be more than these.
*/

int compare(void *a, void *b)
{
    return (*(int *)a  - *(int *)b);
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes)
{
    //sort the numbers.
    qsort(arr, arrSize, sizeof(int), compare);
    
    int i = 1, count = 0;
    long minDiff = LONG_MAX;
    
    while(i < arrSize)
    {
        if(arr[i] - arr[i-1] < minDiff)
        {
            minDiff = arr[i] - arr[i-1];  
            count = 1;
        }
        else if(arr[i] - arr[i-1] == minDiff)
            count++;
        i++;
    }
    
    printf("%d\n", count);
    
    int **out = malloc(sizeof(int *)*count);
    *returnColumnSizes = malloc(sizeof(int)*count);
    count = 0;
    i = 1;
    while(i < arrSize)
    {
        if(arr[i] - arr[i-1] == minDiff)
        {
            out[count] = malloc(sizeof(int *)*2);
            (*returnColumnSizes)[count] = 2;
            out[count][0] = arr[i-1];
            out[count][1] = arr[i];
            count++;
        }
        i++;
    }
    
    *returnSize  = count;
    return out;
}
