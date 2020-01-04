/*
N rooms => 0, 1, 2, 3, --- N-1.

Each room has keys ==> So you can connect to other rooms.

These rooms are like graph nodes, and you have to visit all the nodes.

One node(room) tells you what all neighbors you have.

1. Here DFS can be used ==> O(n)

2. or disjoint-set data structure can be used. O(logn)

*/

void canVisitAllRoomsUtil(int** rooms, int roomsSize, int* roomsColSize, int v, int *vis)
{
    vis[v] = 1;
    int j = 0;
    while(j < roomsColSize[v])
    {
        if(!vis[rooms[v][j]])
           canVisitAllRoomsUtil(rooms, roomsSize, roomsColSize, rooms[v][j], vis);
        j++;
    }
    
    return;
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize)
{
    //Starting point is 0.
    int vis[roomsSize];
    memset(vis, 0, sizeof(vis));
    
    canVisitAllRoomsUtil(rooms, roomsSize, roomsColSize, 0, vis);
    
    int i = 0;
    
    while(i < roomsSize)
    {
        if(!vis[i]) return false;
        i++;
    }
    
    return true;
}


