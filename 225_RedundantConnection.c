/*
Tree has no cycle and its connected
N nodes ==> 1, 2, 3 .... N
Given ==> edges. u < v.


There is one extra edge which will form a cycle.
So we can use Union-Find Algorithm to check the cycle and we just need to return the first edge which forms the cycle.

*/

int abs(int a)
{
    return a < 0 ? -a :a;
}

int find(int *parent, int i)
{
    if(parent[i] <= -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int *parent, int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    
    if(xset != yset)
    {
        if(abs(parent[xset]) < abs(parent[yset]))
        {
            parent[yset] += parent[xset];
            parent[xset] = yset; 
        }
        else
        {
            parent[xset] += parent[yset];
            parent[yset] = xset; 
        }
    }
}


int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize)
{
    int i = 0, j = 0;
    
    int *parent = malloc(sizeof(int)*edgesSize);
    memset(parent, -1, sizeof(int)*edgesSize);
    
    while(i < edgesSize)
    {
        int x = find(parent, edges[i][0] -1);    
        int y = find(parent, edges[i][1] -1);
        
        //printf("%d %d\n", x, y);
        
        if(x == y)
        {
            break;    
        }
        
        Union(parent, x, y);
        
        i++;
    }
    
    int *out = malloc(sizeof(int)*2);
    
    out[0] = edges[i][0];
    out[1] = edges[i][1];
                
    *returnSize = 2;
    return out;
}
