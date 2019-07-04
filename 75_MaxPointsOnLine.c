/*
Max Points on a Line - 
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

//Basic Funda -- find out slope of each point with each point
//and print the max no of  points which has same slope.

//use the hash map kind of structure to track the same slope
//list can be used in c. As there is no uordered map kind of data structure.
//so use list here as unordered map.


//if two point are (x1, y1) and (x2, y2) then their slope will be 
//(y2 – y1) / (x2 – x1) which can be a double value and can cause 
//precision problems. To get rid of the precision problems, we treat 
//slope as pair ((y2 – y1), (x2 – x1)) and instead of ratio, reduce pair 
//by their gcd before inserting into map.

//used List here to store the Xdiff, Ydiff and count.

*/
typedef struct
{
    int Xdiff;
    int Ydiff;
    int count;
}Item;

typedef struct node
{
    Item item;
    struct node *next;
}NODE;

NODE *GetNode(int Xdiff, int Ydiff)
{
    NODE *n = malloc(sizeof(NODE));
    n->next = NULL;
    n->item.Xdiff = Xdiff;
    n->item.Ydiff = Ydiff;
    n->item.count = 1;
    
    return n;
}

int IncCount(NODE **n, int Xdiff, int Ydiff)
{
    NODE *cur = *n;
    NODE *temp = *n;
    
    if(cur == NULL)
    {
        temp = GetNode(Xdiff, Ydiff);
        *n = temp;
        return temp->item.count;
    }
    
    while(cur)
    {
        if(cur->item.Xdiff == Xdiff && cur->item.Ydiff == Ydiff)
        {
            cur->item.count++;
            return cur->item.count;
        }
        temp = cur;
        cur = cur->next;
    }
    
    temp->next = GetNode(Xdiff, Ydiff);
    return temp->item.count;
}

void ClearList(NODE **n)
{
    NODE *cur = *n;
    NODE *temp = *n;
    
    while(cur)
    {
        temp = cur;
        cur = cur->next;
        free(temp);
        temp = NULL;
    }
    *n = NULL;
    return;
}

int GCD(int a, int b)
{
    if(b == 0) return a;
    
    return GCD(b, a%b);
}

int Max(int a, int b)
{
    return a>b?a:b;
}

int maxPoints(int** points, int pointsSize, int* pointsColSize){

    if(pointsSize == 0 || *pointsColSize == 0) return 0;
    
    //points should be more than 2.
    
    if(pointsSize <= 2) return pointsSize;
    
    int i = 0, j = 0, k = 0;
    
    int CurMax = 0, MAX = 0;
    
    int Verticals = 0, Common = 0;
    int Xdiff = 0, Ydiff = 0;
    int mygcd = 0;
    int temp = 0;
    
    NODE *n  = NULL;
    
    //Basic Funda -- find out slope of each point with each point
    //and print the max no of  points which has same slope.
    
    //use the hash map kind of structure to track the same slope
    //list can be used in c. As there is no uordered map kind of data structure.
    //so use list here as unordered map.
    
    
    //if two point are (x1, y1) and (x2, y2) then their slope will be 
    //(y2 – y1) / (x2 – x1) which can be a double value and can cause 
    //precision problems. To get rid of the precision problems, we treat 
    //slope as pair ((y2 – y1), (x2 – x1)) and instead of ratio, reduce pair 
    //by their gcd before inserting into map.
    
    //used List here to store the Xdiff, Ydiff and count.
    
    for(i = 0; i < pointsSize -1; i++)
    {
        Verticals = 0, Common = 0, CurMax = 0;
        for(j = i+1; j < pointsSize; j++)
        {   
            Xdiff = (points[j][0] - points[i][0]);
            Ydiff = (points[j][1] - points[i][1]);
            
            if(!Xdiff && !Ydiff)
                Common++;//common points
            else if(!Ydiff)
                Verticals++;//make 90 degree with x-axis
            else
            {
                mygcd = GCD(Xdiff, Ydiff);
                //reduce each Xdiff and Ydiff by gcd   
                Xdiff /= mygcd;
                Ydiff /= mygcd;
                
                temp = IncCount(&n, Xdiff, Ydiff);
                printf("%d\n", temp);
                
                CurMax = Max(CurMax, temp);
            }
        }
        CurMax = Max(CurMax, Verticals);
        
        //+1, for any two points there will be a line.
        MAX = Max(MAX, CurMax+Common+1);
        ClearList(&n);
    }
    
    return MAX;
}
