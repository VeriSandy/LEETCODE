int countNegatives(int** grid, int gridSize, int* gridColSize)
{
    int i = 0, l = 0, r = 0, count = 0, mid = 0;
    
    while(i < gridSize)
    {
        l = 0;
        r = *gridColSize -1;
        while(l <= r)
        {
            mid = (l+r)/2;
            if(grid[i][mid] < 0)
            {
                count += r - mid +1;
                r = mid -1;
            }
            else
                l = mid+1;
        }
        
        //printf("%d\n", count);
        i++;
    }
    
    return count;
}


