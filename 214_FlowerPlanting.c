/*
Represent them in a graph i.e. building the adjacency list representation

Keep track of flowers, assigned to neighbors of vertex i
Assign min available flower to vertex i
*/

int* gardenNoAdj(int N, int** paths, int pathsSize, 
                 int* pathsColSize, int* returnSize)
{
    int **adjacency = malloc(sizeof(int *)*N);
    int *flowers = calloc(N,sizeof(int));
    int neighFlower[5] = {1,0,0,0,0};
    int i = 0, j = 0;
    
    //to keep track of neighbors of vertex i
    int *neighbors = calloc(N,sizeof(int));
    
    for(; i < N; i++)
        adjacency[i] = calloc(3,sizeof(int));
    
    //building the adjacency list representation
    for(i = 0; i < pathsSize; i++)
    {
        adjacency[paths[i][0] -1][neighbors[paths[i][0] -1]++] = paths[i][1] -1;
        adjacency[paths[i][1] -1][neighbors[paths[i][1] -1]++] = paths[i][0] -1;
    }
    
    //assign flowers
    for(i = 0; i < N; i++)
    {
        //mark flowers assigned to neighbors of vertex i
        for(j = 0; j < neighbors[i]; j++)
        {
            //printf("nighbor of %d %d\n", i+1, adjacency[i][j]+1);
            neighFlower[flowers[adjacency[i][j]]] = 1;
        }
        
        for(j = 4; j >= 1; j--)
        {
            //assign min available flower to this vertex
            if(neighFlower[j] == 0)
                flowers[i] = j;
            else
                neighFlower[j] = 0;
        }
    }    
    
    *returnSize = N;
    return flowers;
}


