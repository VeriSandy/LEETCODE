/**
 * Note: The returned array must be malloced, assume caller calls free().
*/

/*
1. Do square of each element and sort it.
2. Sort it based on the abs(arr[i]). Then take square of each element.
3. Use two pointer approach put elements in correct order of their ABS value in new array.
Square can also be done at the same time.

*/

int ABS(int a)
{
    return a>0?a:-a;
}

int* sortedSquares(int* A, int ASize, int* returnSize)
{
    int i = 0;
    int *out = malloc(sizeof(int)*ASize);
    
    int l = 0, r = ASize -1;
    int temp = 0, k = ASize -1;
    
    while(l < r)
    {
        if(ABS(A[l]) < ABS(A[r]))
        {
            out[k--] = A[r]*A[r];
            r--;
            //printf("out[%d] = %d\n", k+1, out[k+1]);
        }
        else if(ABS(A[l]) > ABS(A[r]))
        {
            out[k--] = A[l]*A[l];
            l++;
            //printf("out[%d] = %d\n", k+1, out[k+1]);
        }
        else
        {
            out[k--] = A[r]*A[r];
            r--;
            //printf("out[%d] = %d\n", k+1, out[k+1]);
            out[k--] = A[l]*A[l];
            l++;
            //printf("out[%d] = %d\n", k+1, out[k+1]);
        }
    }
    
    if(l == r)
    {
        out[k] = A[l]*A[l];
        //printf("out[%d] = %d\n", k, out[k]);
    }
    
    
    *returnSize = ASize;
    return out;
}


