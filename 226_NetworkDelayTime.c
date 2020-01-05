/*
N network nodes ==> 1 to N

(u, v, w) ==> u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Need to calculate basically the time across longest path. 
Need to see if all the nodes can be visited are not.

DFS can be used for both operations.
If any node left unvisited then return -1.

Dont use visited array concept here as we need to see if it can visited in less time.

If signal has already arrived earlier to some node, don't need to broadcast anymore. Otherwise, broadcast the signal.

--OR--

Dijkstra algorithm can be used to find out the shortest path from source.

*/
//Dijkstra algorithm
typedef struct
{
    int weight;
    int target;
}Item;

int minDistanceVertex(int *dist, int *ShortestPathSet, int N)
{
    int min = INT_MAX, minIndex = 0;
    
    int i = 0;
    
    while(i < N)
    {
        if(!ShortestPathSet[i] && dist[i] <= min)
        {
            min = dist[i];
            minIndex = i;
        }
        i++;
    }
    
    return minIndex;
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int N, int K)
{
    int i = 0, j = 0;
    
    //create Graph Strcuture
    Item **graph = malloc(sizeof(Item *)*N);
    while(i < N)
    {
        graph[i] = malloc(sizeof(Item)*N);
        memset(graph[i], 0, sizeof(Item)*N);
        i++;
    }
    
    i = 0;
    while(i < timesSize)
    {
        graph[times[i][0]-1][times[i][1]-1].weight = times[i][2];
        graph[times[i][0]-1][times[i][1]-1].target = 1;
        i++;
    }
    
    /*
    for(i = 0; i < N; i++)
    {
        printf("%d --> ", i);
        for(j = 0; j < N; j++)
        {
            printf("%d ", graph[i][j]);    
        }
        printf("\n");
    } */

    // Dijkstra algorithm
    int dist[N]; //to have the shortest distance of ith vertex from source.
    int ShortestPathSet[N]; //To see if Shortest Path has been set for vertex i
    
    i = 0;
    while(i < N)
    {
        dist[i] = INT_MAX; //initially set all the distances inifinty
        ShortestPathSet[i] = 0;//as of now No Shortest Path has set
        i++;
    }
    
    dist[K-1] = 0;
    
    i = 0;
    while(i < N -1)
    {
        //choose the min distance vertex
        int u = minDistanceVertex(dist, ShortestPathSet, N);
        
        ShortestPathSet[u] = 1;
        printf("%d \n", u);
        
        for(j = 0; j < N ; j++)
        {
            //!ShortestPathSet[j] --> NOT SHORTLISTED
            //graph[u][j] --> EDGE EXIST
            //dist[u] != INT_MAX --> 
            if(!ShortestPathSet[j] && graph[u][j].target &&dist[u] != INT_MAX
                && (dist[u] + graph[u][j].weight < dist[j]))
                dist[j] = dist[u] + graph[u][j].weight;
        }
        i++;
    }
    
    i = 0;
    int max = 0;
    while(i < N)
    {
        if(dist[i] == INT_MAX) return -1;
        
        if(max < dist[i])
            max = dist[i];
        
        i++;
    }
    
    return max;
}
============================================================================================================
//DFS Approach

typedef struct 
{
    int target;
    int weight;
}item;

void  DFSUtil(item **graph, int *neighbors, int v, int *weights, int temp)
{
    if(temp >= weights[v])
        return;
    
    weights[v] = temp;
    
    int j = 0;
    while(j < neighbors[v])
    {
        DFSUtil(graph,neighbors,graph[v][j].target,weights, temp + graph[v][j].weight); 
        j++;
    }
    
    return;
}


int networkDelayTime(int** times, int timesSize, int* timesColSize, int N, int K)
{
    int i = 0, j = 0;
    
    //create Graph Strcuture
    item **graph = malloc(sizeof(item *)*N);
    int *weights = malloc(sizeof(int)*N); 
    while(i < N)
    {
        graph[i] = malloc(sizeof(item)*N);
        memset(graph[i], 0, sizeof(item)*N);
        weights[i] = INT_MAX;
        i++;
    }
    
    int *neighbors = malloc(sizeof(int)*N); 
    memset(neighbors, 0, sizeof(int)*N);
    
    i = 0;
    while(i < timesSize)
    {
        graph[times[i][0]-1][neighbors[times[i][0]-1]].target = times[i][1]-1;
        graph[times[i][0]-1][neighbors[times[i][0]-1]++].weight = times[i][2];
        i++;
    }

    DFSUtil(graph, neighbors, K-1, weights, 0);
    
    i = 0;
    int max = 0;
    while(i < N)
    {
        if(weights[i] == INT_MAX) return -1;
        
        if(max < weights[i])
            max = weights[i];
        
        i++;
    }
    
    return max;
}
