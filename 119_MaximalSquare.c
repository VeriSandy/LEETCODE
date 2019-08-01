/*
Maximal Square --

1) Construct a sum matrix S[R][C] for the given M[R][C].
     a)    Copy first row and first columns as it is from M[][] to S[][]
     b)    For other entries, use following expressions to construct S[][]
         If M[i][j] is 1 then
            S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1
         Else
            S[i][j] = 0
2) Find the maximum entry in S[R][C]

This will give max size of square.

*/
int Min(int a, int b)
{
    return a>b?b:a;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize)
{
    if(matrixSize == 0) return 0;
    
    int s[matrixSize][*matrixColSize];
    memset(s, 0, sizeof(s));
    
    int i = 0, j = 0;
    
    for(i = 0; i < *matrixColSize; i++)
        s[0][i] = matrix[0][i] - '0';
    
    for(i = 0; i < matrixSize; i++)
        s[i][0] = matrix[i][0] - '0';
    
    
    for(i = 1; i < matrixSize; i++)
    {
        for(j = 1; j < *matrixColSize; j++)    
        {
            if(matrix[i][j] == '1')
                s[i][j] = Min(s[i-1][j], Min(s[i][j-1], s[i-1][j-1])) +1;
            else
                s[i][j] = 0;
        }
    }
    
    int max = 0;   
    for(i = 0; i < matrixSize; i++)
    {
        for(j = 0; j < *matrixColSize; j++)    
        {
            if(max < s[i][j])
                max = s[i][j];
        }
    }
    return max*max;
}

