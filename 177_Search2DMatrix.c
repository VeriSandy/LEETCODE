/*
Ideas --
1. 
Find the row first, where traget does belong, then look for target in that particular row.

So there is two way binary search.
First to find row 
then second on that row

2. Start from top right corner

    if target == matrix[m][n])
    return true
    if target > matrix[m][n])
        check in next row 
    if target < matrix[m][n])
        check in previous column
    else
        return false;
*/

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int l = 0, h = *matrixColSize -1;
    int mid = 0, rowNum = 0;
    
    if(matrixSize == 0 || (*matrixColSize) == 0)
        return false;
    
    if(target > matrix[matrixSize-1][h] || target < matrix[0][0])
        return false;
    
    while(l < matrixSize && h >= 0 )
    {
        if(matrix[l][h] == target)
            return true;
        
        if(matrix[l][h] > target)
        {
            //All the elements next rows of this column will be greater than this               
            //one, so element can't be in this column 'h', so check in previous one
            h--;
        }
        else
        {
            //All the elements in this row will be lessor than this                             
            // one, so element can't be in this row 'l', so check in next one
            l++;
        }
    }
    
    return false;
}

========================================


bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int l = 0, h = matrixSize-1;
    int mid = 0, rowNum = 0;
    
    if(matrixSize == 0 || (*matrixColSize) == 0)
        return false;
    
    while(l +1< h)
    {
        mid = (l+h)/2;
        
        if(matrix[mid][(*matrixColSize) -1] == target)
            return true;
        
        if(matrix[mid][(*matrixColSize) -1] > target)
        {
            //so element lies from l to mid row
            h = mid;   
        }
        else
        {
            //so element lies from mid+1 to h row
            l = mid;
        }
    }
    
    //Finally we will have here two rows.
    //decide which is target row.
    
    rowNum = l;
    if(target >= matrix[h][0])
        rowNum = h;
    
    printf("%d %d %d\n", l, h,rowNum);
   
    l = 0;
    h = *matrixColSize -1;
    while(l <= h)
    {
        mid = (l+h)/2;

        if(matrix[rowNum][mid] == target)
            return true;
        
        if(matrix[rowNum][mid] > target)
            h = mid -1;   
        else
            l = mid+1;
    }
    
    return false;
}
