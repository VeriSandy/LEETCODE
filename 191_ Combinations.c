/*
Ideas -- 
Need to generate subsets of k numbers out of 1...n

1. Can be done recursively. DFS based Approach
    
    Fix at first i.e.1, and recursivley look for other members of subsets having 1. 
    Now fix next number 2 and look for for other members of subsets having 2.
    And so on.
    
*/

void counterUtility(int start, int n, int k, int *count,int counter)
{
    if(k == counter)
    {
        *count += 1;
        return;
    }
    
    int i = start;
    for(; i <= n ; i++)
    {
        counter++;
        counterUtility(i+1, n, k, count, counter);
        counter--;
    }
    return ;
}


void combineUtility(int start, int n, int k, int *count, int *temp, 
                    int counter, int **out)
{
    if(k == counter)
    {
        int p = 0;
        while(p < k)
        {
            out[*count][p] = temp[p];
            p++;
        }
        *count += 1;
        return;
    }
    
    int i = start;
    for(; i <= n ; i++)
    {
        temp[counter] = i;
        counter++;
        combineUtility(i+1, n, k, count, temp, counter, out);
        counter--;
    }
    return ;
}

int **combine(int n, int k, int *returnSize, int **returnColumnSizes)
{
    if(k <= 0)
    {
        *returnSize = 1;
        int **out = malloc(sizeof(int *)*1);
        *returnColumnSizes = malloc(sizeof(int)*1);
        
        out[0] = malloc(sizeof(int)*1);
        (*returnColumnSizes)[0] = 0;
        
        return out;
    }
    
    if(k > n)
    {
        *returnSize = 0;
        return NULL;
    }
    
    int count = 0;
    counterUtility(1, n, k, &count, 0);
    
    int *temp = malloc(sizeof(int)*k);
    
    int **out = malloc(sizeof(int *)*count);
    *returnColumnSizes = malloc(sizeof(int)*count);
    int i = 0;
    
    while(i < count)
    {
        out[i] = malloc(sizeof(int)*k);
        (*returnColumnSizes)[i] = k;
        i++;
    }
    
    count = 0;
    combineUtility(1, n, k, &count, temp , 0, out);
    *returnSize = count;
    return out;
}
