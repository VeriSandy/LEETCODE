/*
Combination Sum --
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.
Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

Ideas -- 
Looks like something recursion

To take care of the repeatitive solutions - 
1. Sort the array first.
2. To avoid repeatitive solutions you have to find solutions, start with lower element and then bigger  elements, like in case of [2,3,5], 8 -   
2,3,3 (not 3,3,2 or 3,2,3)
3,5 (not 5,3)

This way we can keep duplicate solutions away.
    
*/

void findSolutions(int *a, int n, int target, int i, int *count)
{
    if(target < 0)
        return;
    
    if(target == 0)
    {
        //printf("findSolutions() - found a solution\n");
        *count += 1;
        return;
    }
    while(i < n)
    {
        findSolutions(a, n, target -a[i], i, count);
        //once you are done with solutions start with this index
        //look for further solutions, which lies ahead.
        i++;
    }
    /*
    This will result in repeatitive solutions
    like in case of [2,3,5], 8
    2,3,3 and 3,2,3 or 3,3,2
    
    //to avoid repeatitive solutions you have to find solutions 
    start with lower element and then bigger element
    like 
    2,2,2,2
    2,3,3 (not 3,3,2 or 3,2,3)
    3,5 (not 5,3)
    This way we can keep dups away.
    
    for(i = 0; i < n ; i++)
    {
        if(target -a[i] == 0)
            printf("found a solution\n");
        
        else if(target - a[i] > 0)
           findSolutions(a, n, target -a[i], i);
        
        //else ignore in case of negative 
    }
    */
    return;
}

void findSolutions2(int *candidates, int n, int target, int i, int *count, 
                    int *returnColumnSizes, int *temp, int k, int **a)
{
    if(target < 0)
        return;
    
    if(target == 0)
    {
        a[*count] = malloc(sizeof(int)*k);
        returnColumnSizes[*count] = k;
        
        //printf("k = %d and array - ", k);
        int j = 0;
        while(j < k)
        {
            a[*count][j] = temp[j];
            //printf("%d ", temp[j]);
            j++;
        }
        //printf("\n");
        *count += 1;
        return;
    }
    
    while(i < n)
    {
        temp[k] = candidates[i];//put elements in temp array(kind of stack)
        k++;
        findSolutions2(candidates, n, target-candidates[i], i, count, returnColumnSizes, temp, k, a);
        i++;
        k--;//back tracking, kind of pop element
    }
}

int compare(void const *a, void const *b)
{
    return *(int *)a - *(int *)b;
}

int** combinationSum(int* candidates, int candidatesSize, int target, 
                     int* returnSize, int** returnColumnSizes)
{
    int **a = NULL;
    *returnSize = 0;
    *returnColumnSizes =  NULL;
    int i = 0, count = 0, k = 0;
    
    //First sort the array.
    qsort(candidates, candidatesSize, sizeof(int), compare);
    
    findSolutions(candidates, candidatesSize, target, i, &count);
    
    a = malloc(sizeof(int *)*count);
    memset(a, 0, sizeof(int *)*count);
    *returnColumnSizes = malloc(sizeof(int)*count);
    memset(*returnColumnSizes, 0, sizeof(int)*count);
    
    int *temp = malloc(sizeof(int)*target);//max array size
    memset(temp, 0, sizeof(int)*target); 
    i = 0, count = 0;
    
    findSolutions2(candidates, candidatesSize, target, i, &count, 
                   *returnColumnSizes, temp, k, a);
   
    free(temp);
    temp = NULL;
    
    /*
    i = 0, k = 0;
    while(i < count)
    {
        k = 0;
        while(k < (*returnColumnSizes)[i])
        {
            printf("%d ", a[i][k]);
            k++;
        }
        printf("\n");
        i++;
    }
    */
    *returnSize = count;
    return a;
}

