/*Ideas -- 
Queen can attack each other if another queen is in same row or column or in cross lines.
We have to try all the options, where all we can put the queens.

In Same Row need not to check as we are filling one '1' in one row at a time.

For columns have one row extra to keep count of elements in same column if count is already one in one column, go for another column.

Need to check in cross lines, with respect to current row/cloumn index.
*/

bool CheckCrosses(int **temp, int n, int i, int j)
{
    int k = i+1;
    int l = j-1;
    //check cross in left side of temp[i][j]
    while(k < n && l >= 0)
    {
        if(temp[k][l] == 1)
            return false;
        k++;
        l--;
    }
    k = i+1;
    l = j+1;
    //check cross in right side of temp[i][j]
    while(k < n && l < n)
    {
        if(temp[k][l] == 1)
            return false;
        k++;
        l++;
    }
    return true;
}

void CountUtil(int **temp, int row, int n, int *count, int counter)
{
    if(counter == n)
        *count += 1;
    
    if(row < 0) return;
    
    int i = row, j = n-1;
    while(j >= 0)
    {
        //check column count
        //if column count is > 0 in one column go for another column.
        if(temp[n][j] > 0 || !CheckCrosses(temp, n, i,j))
        {
            j--;
            continue;
        }
        //increase column count to keep track in same coulmn
        temp[n][j] += 1;
        temp[i][j] = 1;
        counter++;
        CountUtil(temp, i-1, n, count, counter);
        temp[i][j] = 0;
        temp[n][j] -= 1;
        counter--;
        
        j--;
    }
}

int totalNQueens(int n)
{
    //maintain one row extra to keep track elements in same column
    int **temp = malloc(sizeof(int *)*(n+1));
    int i = 0, j = 0, k = 0;
    temp[n] = malloc(sizeof(int)*n);
    
    while(i < n)
    {
        temp[i] = malloc(sizeof(int)*n);
        memset(temp[i], 0, sizeof(int)*n);
        temp[n][i] = 0;
        i++;
    }
    
    int count = 0;
    CountUtil(temp, n-1, n, &count, 0);
    
    return count;
}
