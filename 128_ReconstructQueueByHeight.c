/*
Queue Reconstruction by Height --
Idea ---
Sort elements in decreasing order of height but in increasing order of k for same height.
Now see where each element can be placed in the final output array.

//See if like insertion sort can be applied.
//If k of element is zero than make sure there is no greater element in front of this element.
//If k > 0 then make only the no of element greater in front of this element should be eqaul to k.
*/

int compare(const void *pa, const void *pb) 
{
    const int *a = *(const int **)pa;
    const int *b = *(const int **)pb;
    
    if(a[0] != b[0])
        return b[0] - a[0];
    else
        return a[1] - b[1];
}

int** reconstructQueue(int** people, 
int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes)
{
    int **a = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    if(peopleSize == 0) return a;
    
    int i = 0, j = 0, count = 0, pos = 0;
    
    a = malloc(sizeof(int *)*peopleSize);
    *returnColumnSizes = malloc(sizeof(int)*peopleSize);
    for(i = 0; i < peopleSize; i++)
    {
        a[i] = malloc(sizeof(int)*(*peopleColSize));
        (*returnColumnSizes)[i] = *peopleColSize;
    }
    
    qsort(people, peopleSize, sizeof(people[0]), compare);
    
    a[0][0] = people[0][0];
    a[0][1] = people[0][1];    
    
    for(i = 1; i < peopleSize; i++)
    {
        count = 0;
        pos = 0;
        for(j = 0; j < i; j++)
        {
            if(people[i][1] > count)
            {
                pos++;
                if(people[i][0] <= a[j][0])
                    count++;
            }
            else
                break;
        }
        //Shift Elements
        for(j = i; j > pos; j--)
        {
            a[j][0] = a[j-1][0];
            a[j][1] = a[j-1][1];
        }
        a[pos][0] = people[i][0];
        a[pos][1] = people[i][1];
    }
   //for(i = 0; i < peopleSize; i++)
   //     printf("[%d %d] ", a[i][0], a[i][1]);
    *returnSize = peopleSize;
    return a;
}
