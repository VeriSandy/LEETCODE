/*
Idea -- 
Use 4 for loops.
*/

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes)
{
    *returnSize = n;
    int **a = malloc(sizeof(int *)*n);
    *returnColumnSizes = malloc(sizeof(int)*n);
    int i = 0;
    
    for(i = 0; i < n ; i++)
    {
        a[i] = malloc(sizeof(int)*n);
        (*returnColumnSizes)[i] = n;
    }
    
    int p = 0, r = n, q = 0, c = n;
    int count = 1;
    while(p < r && q < c)
    {
        for(i = q; i < c ; i++)
        {
            a[p][i] = count;
            count++;
        }
        p++; //one top row complete
        
        for(i = p; i < r ; i++)
        {
            a[i][c-1] = count;
            count++;
        }
        c--; //one last column complete
        
        if(p < r)//if any row left
        {
            for(i = c-1; i >= q  ; i--)
            {
                a[r-1][i] = count;
                count++;
            }
            r--;//one last row complete
        }
        
        if(q < c)//if any column left
        {
            for(i = r-1; i >= p ; i--)
            {
                a[i][q] = count;
                count++;
            }
            q++;//one column from front complete
        }
    }
    return a;
}
