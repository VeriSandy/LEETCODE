
//use DFS

void CountIslands(char **grid, int i, int j, int m, int n, int vis[m][n])
{
    int row[] = {0, 1,  0, -1};
    int col[] = {1, 0, -1,  0};
    
    vis[i][j] = 1;
    
    int k = 0;
    
    for(k = 0; k < 4; k++)
    {
            
        if(i+row[k] >= 0 && i+row[k] < m && j+col[k] >= 0 && j+col[k] < n
            && grid[i+row[k]][j+col[k]] == '1' && vis[i+row[k]][j+col[k]] == 0)               
            CountIslands(grid, i+row[k], j+col[k], m, n, vis);
    }
    return;
}



int numIslands(char** grid, int gridSize, int* gridColSize){

    if(gridSize == 0 || *gridColSize == 0) return 0;
    
    int vis[gridSize][*gridColSize];
    
    memset(vis, 0x00, sizeof(vis));
    
    int i = 0, j = 0, count = 0;
    
    for(i = 0; i < gridSize; i++)
    {
        for(j = 0; j < *gridColSize; j++)
        {   
            if(grid[i][j] == '1' && vis[i][j] == 0)
            {
                CountIslands(grid, i, j, gridSize, *gridColSize, vis);
                count++;
            }
        }
    }
    
    return count;
}


