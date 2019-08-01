/*
Maximal Rectangle --

Use the similar concept as  - Given Array of Bars and need to find the max area.

1. Find max area in 1st row
2. Find max area in second row after adding same column in second row.
3. And so on

*/

int findMaxArea(int *a, int n)
{
    int st[n]; //stack
    int top = -1;
    int i = 0, max = 0;
    
    while(i < n)
    {
        if(top == - 1 || a[st[top]] <= a[i])
        {
            st[++top] = i;
            i++;
        }
        else
        {
            int j = st[top];
            top--;
            
            int temp = a[j]*((top == -1)?i:i - st[top] -1);
            
            if(max < temp)
                max = temp;
        }
    }
    while(top >= 0)
    {
        int j = st[top];
        top--;

        int temp = a[j]*((top == -1)?i:i - st[top] -1);

        if(max < temp)
            max = temp; 
    }
    return max;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize)
{
    if(matrixSize == 0) return 0;
    int i = 0, j = 0;
    
    int mat[matrixSize][*matrixColSize];
    for(i = 0; i < matrixSize; i++)
        for(j = 0; j < *matrixColSize; j++)
            mat[i][j] = matrix[i][j] - '0';
    
    int max = 0, temp = 0;
    max = findMaxArea(mat[0], *matrixColSize);

    for(i = 1; i < matrixSize; i++)
    {
        for(j = 0; j < *matrixColSize; j++)
            if(mat[i][j])
                mat[i][j] += mat[i-1][j];
        
        temp = findMaxArea(mat[i], *matrixColSize);
        if(max < temp)
            max = temp;
        
    }
    
    return max;
}
