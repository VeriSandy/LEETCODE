/*
    Min time visting all nodes
    Min time to go to any node from any node, wherever possible is diagonal,otherwise 
    go up/down, right/left.
    
    So technically from (x1,y1) to (x2,y2)
    min time would be max(abs(x2-x1), abs(y2-y1))
*/

int ABS(int a)
{
    return a<0?-a:a;
}

int MAX(int a, int b)
{
    return a>b?a:b;
}

int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize)
{
    if(pointsSize <= 1) return 0;
    
    int i = 0;
    int TotalTime = 0;
    
    for(i = 0; i < pointsSize -1; i++)
        TotalTime += MAX(ABS(points[i+1][0] - points[i][0]), 
                        ABS(points[i+1][1] - points[i][1]));
    
    return TotalTime;
}
