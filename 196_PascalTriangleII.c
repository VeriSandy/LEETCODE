/*
Idea
for 0th Index - 1 element 
1st Index - 2 elements
2nd Index - 3 elements

nth index - n+1
*/

int* getRow(int rowIndex, int* returnSize)
{
    int *out = malloc(sizeof(int)*(rowIndex+1));
    
    *returnSize = rowIndex+1;
    out[0] = 1; 
    if(rowIndex == 0)
        return out;
    
    out[1] = 1;
    if(rowIndex == 1)
        return out;
    
    int i = 2, j = 0;
    
    while(i <= rowIndex)
    {
        j = i;
        out[j] = out[i-1];
        j = i-1;
        while(j >= 1)
        {
            out[j] += out[j-1];
            j--;
        }
        i++;
    }
    
    return out;
}


