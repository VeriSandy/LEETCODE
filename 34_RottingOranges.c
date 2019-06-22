

typedef struct
{   
    int x, y ;
}Data;

typedef struct node
{   
    Data data;
    struct node  *next;
}NODE;

typedef struct queue
{   
    NODE *front, *rear;
    int size;
}QUEUE;


QUEUE *CreateQueue()
{   
    QUEUE *que = malloc(sizeof(QUEUE));
    que->front = que->rear = NULL;
    que->size = 0;
    
    return que;
}

Data Front(QUEUE *que)
{   
    return que->front->data;
}

void EnQueue(QUEUE *que, Data data)
{
    NODE *n = malloc(sizeof(NODE));
    n->next = NULL;
    n->data  = data;

    if(!que->front)
        que->front = n;
    else
        que->rear->next = n;
    que->rear = n;

    que->size++;

    return;
}

Data DeQueue(QUEUE *que)
{
    NODE *t = que->front;

    que->front = que->front->next;
    if(que->front == NULL)
        que->rear = NULL;

    que->size--;

    Data data = t->data;

    free(t);
    return data;
}

int checkAll(int** a, int gridSize, int* gridColSize)
{   
    int i = 0, j = 0; 
    for(i = 0; i < gridSize; i++)
    {   
        for(j = 0; j < *gridColSize; j++)
        {   
            //if any orange couldn't get roted
            if(a[i][j] == 1)
                return 0;
        }
    }
    
    return 1;
}

int orangesRotting(int** arr, int gridSize, int* gridColSize){
    if(!gridSize || !(*gridColSize)) return 0;

    int ans = 0;
    Data data;

    int i = 0, j = 0;
    Data temp = {0};
    int flag = 0;


    QUEUE *q = CreateQueue();
   
    for(i = 0; i < gridSize; i++)
    {
        for(j = 0; j < *gridColSize; j++)
        {
            if(arr[i][j] == 2)
            {
                data.x = i;
                data.y = j;
                EnQueue(q, data);
                //printf("%d %d\n", data.x, data.y);
            }
        }
    }

    //delimiter node
    data.x = -1;
    data.y = -1;
    EnQueue(q, data);

    while(q->size)
    {
            flag = 0;
            temp = DeQueue(q);
            while(temp.x != -1)
            {
                //printf("%d %d\n", temp.x, temp.y);
                if(temp.x + 1 >= 0 && temp.x + 1 < gridSize && temp.y >= 0 && 
                   temp.y < *gridColSize && arr[temp.x +1 ][temp.y] == 1)
                {
                    if(!flag)
                        ans++;
                    flag = 1;
                    Data d = {temp.x+1, temp.y};
                    EnQueue(q, d);
                    arr[temp.x+1][temp.y] = 2;
                }

                if(temp.x - 1 >= 0 && temp.x - 1 < gridSize && temp.y >= 0 && 
                   temp.y < *gridColSize && arr[temp.x -1 ][temp.y] == 1)
                {
                    if(!flag)
                        ans++;
                    flag = 1;
                    Data d = {temp.x-1, temp.y};
                    EnQueue(q, d);
                    arr[temp.x-1][temp.y] = 2;
                }

                if(temp.x>= 0 && temp.x< gridSize && temp.y + 1>= 0 && 
                   temp.y + 1< *gridColSize && arr[temp.x][temp.y+1] == 1)
                {
                    if(!flag)
                        ans++;
                    flag  = 1;
                    Data d = {temp.x, temp.y+1};
                    EnQueue(q, d);
                    arr[temp.x][temp.y+1] = 2;
                }

                if(temp.x>= 0 && temp.x< gridSize && temp.y - 1>= 0 && 
                   temp.y - 1< *gridColSize && arr[temp.x][temp.y-1] == 1)
                {
                    if(!flag)
                        ans++;
                    flag  = 1;
                    Data d = {temp.x, temp.y-1};
                    EnQueue(q, d);
                    arr[temp.x][temp.y-1] = 2;
                }
   
                temp = DeQueue(q);
            }
            if(temp.x == -1)
            {
                EnQueue(q, temp);

                temp = Front(q);
                if(temp.x == -1)
                    break;
            }
    }

    return checkAll(arr, gridSize, gridColSize)?ans:-1;

}
