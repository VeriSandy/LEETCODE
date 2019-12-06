/*
Dimesnions of Matrix -- n,m
Indices.

*/

int oddCells(int n, int m, int** indices, int indicesSize, 
             int* indicesColSize)
{
    int i = 0, j = 0;
    int count = 0;
    
    int r[n];
    int c[m];
    
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    
    for(i = 0; i < indicesSize; i++)
    {
        r[indices[i][0]]++;
        c[indices[i][1]]++;
    }
    
    //ex - 
    //if [1,1] ==> row ==> all elements of first amd row are +1
    //[0,2] ==> column ==> all elements of 2nd column are +2.
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if((r[i] + c[j])%2)
                count++;
        }
    }

    return count;
}


