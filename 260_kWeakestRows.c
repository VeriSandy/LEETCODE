/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


/*
Hashing can be used instead of sorting the output array
*/
typedef struct
{
    int data;
    int index;
}ITEM;

int compare(void *a, void *b)
{
    ITEM *a1 = (ITEM *)a;
    ITEM *b1 = (ITEM *)b;
    
    return (a1->data  - b1->data);
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize)
{
    int i = 0, l = 0, r = 0, j = 0, mid = 0;
    
    ITEM *out = malloc(sizeof(ITEM)*matSize);
    
    int *out1 = malloc(sizeof(int)*k);
    *returnSize = k;
    
    for(i = 0; i < matSize; i++)
    {
        l = 0; 
        r = *matColSize -1;
        while(l <= r)
        {
            mid = (l+r)/2;
            
            if(mat[i][mid])
            {
                if(mid + 1 <= r)
                {
                    if(mat[i][mid+1] == 0)
                    {
                        out[j].data = mid +1;
                        out[j].index = j;
                        //printf("a[%d] = %d\n", j, out[j].data);
                        j++;
                        break;
                    }
                    else
                        l = mid+1;
                }
                else
                {
                    out[j].data = mid +1;
                    out[j].index = j;
                    //printf("a[%d] = %d\n", j, out[j].data);
                    j++;
                    break;
                }
            }
            else
                r = mid -1;
        }
        if(r < 0)
        {
            out[j].data = 0;
            out[j].index = j;
            //printf("a[%d] = %d\n", j, out[j].data);
            j++;
        }
        //printf("%d %d\n", l, r);
    }
    
    qsort(out, matSize, sizeof(ITEM), compare);
    
    for(i = 0; i < k; i++)
        out1[i] = out[i].index;
    
    return out1;
}
