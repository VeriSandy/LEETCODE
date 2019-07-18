


typedef struct node
{
    int data;
    struct node *next, *prev;
}NODE;

typedef struct
{
    NODE *front, *rear;
    int size;
}QUE;


QUE *CreateQueue()
{
    QUE *q = malloc(sizeof(QUE));
    q->rear = NULL;
    q->front = NULL;
    q->size = 0;
    return q;
}

int DeQueue(QUE *q)
{
    NODE *n = q->front;
    
    q->front = q->front->next;
        
    if(q->front == NULL)
        q->rear = NULL;
    else
        q->front->prev = NULL;
    
    n->next = NULL;
    int data = n->data;
    free(n);
    n = NULL;

    q->size--;
    return data;
}


int DeQueueBack(QUE *q)
{
    NODE *n = q->rear;
    
    q->rear = q->rear->prev;
        
    if(q->rear == NULL)
        q->front = NULL;
    else
        q->rear->next = NULL;
    
    n->next = NULL;
    n->prev = NULL;
    
    int data = n->data;
    free(n);
    n = NULL;

    q->size--;
    return data;
}

void EnQueue(QUE *q, int data)
{
    NODE *n = malloc(sizeof(NODE));
    n->next = NULL;
    n->prev = NULL;
    n->data = data;
    
    if(q->front == NULL)
        q->front = n;
    else
    {
        n->prev = q->rear;
        q->rear->next = n;
    }
    
    q->rear = n;
    q->size++;
    return;
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    
    *returnSize = 0;
    int *a = NULL;
    if(numsSize == 0) return a;
    
    int i = 0, data, l = 0;
    QUE *q = CreateQueue();
    a = malloc(sizeof(int)*(numsSize-k+1));
    
    while(i < k)
    {
        while(q->size > 0 && nums[q->rear->data] < nums[i])
            DeQueueBack(q);
        
        EnQueue(q, i);
        //printf("%d\n", q->front->data);
        i++;
    }
    
    while(i < numsSize)
    {
        data = q->front->data;
        //printf("%d\n", nums[data]);
        a[l] = nums[data];
        
        while(q->size > 0  && q->front->data < i-k+1)
            DeQueue(q);
        
        while(q->size > 0 && nums[q->rear->data] < nums[i])
            DeQueueBack(q);
        
        EnQueue(q, i);
        
        i++;
        l++;
    }
    
    //printf("%d\n", nums[q->front->data]);
    a[l] = nums[q->front->data];
    DeQueue(q);
    
    free(q);
    q = NULL;
    
    *returnSize = i-k+1;
    return a;
}
