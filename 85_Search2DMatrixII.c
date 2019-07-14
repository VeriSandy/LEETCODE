/*
Search a 2D Matrix II

Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

IDEA -- 
//start from top right. 
//if target is less, then search in previous column as you can only get lessor element in previuos columns 
//if target is more, then search in next row.
*/

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    
    int i = 0, j = 0;
    int l = 0, r = 0;
    
    if(matrixRowSize == 0 || matrixColSize == 0 || 
       target < matrix[0][0] || target > matrix[matrixRowSize -1][matrixColSize -1])
        return false;
    
    
    i = 0, j = matrixColSize -1;
    
    while(i < matrixRowSize && j >= 0)
    {
        if(matrix[i][j] == target)
            return true;
        
        else if(matrix[i][j] > target)
            j--;
        else
            i++;
    }
    
    return false;
}
