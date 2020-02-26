================================================================
Iteration
================================================================
typedef struct node
{
    struct TreeNode *data;
    struct node *next;
}NODE;

typedef struct
{
    NODE *que, *rear;
    int size;
}QUEUE;

QUEUE *CrateQueue()
{
    QUEUE *q = malloc(sizeof(QUEUE));
    q->rear = q->que = NULL;
    q->size = 0;
    
    return q;
}

struct TreeNode *DeQueue(QUEUE *q)
{
    NODE *node = q->que;
    
    q->que = q->que->next;
    q->size--;
    if(!q->size)
        q->que = q->rear = NULL;
    
    return node->data;
}

void EnQueue(QUEUE *q, struct TreeNode *data)
{
    NODE *node = malloc(sizeof(NODE));
    node->data = data;
    node->next = NULL;
    
    if(q->rear == NULL)
        q->rear = q->que = node;
    else
    {
        q->rear->next = node;
        q->rear = node;
    }
    q->size++;
    
    return;
}


bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false;
    
    //Create Queue.
    QUEUE *queue1 = CrateQueue();
    QUEUE *queue2 = CrateQueue();
    
    struct TreeNode *node1, *node2;
    
    EnQueue(queue1, p);
    EnQueue(queue2, q);
    
    while(queue1->size && queue2->size)
    {
        node1 = DeQueue(queue1);
        node2 = DeQueue(queue2);
        
        printf("%d %d\n", node1->val, node2->val);
        if(node1->val != node2->val) return false;
        
        if(node1->left && node2->left)
        {
            //printf("PLeft %d %d\n", node1->left->val, node2->left->val);
            EnQueue(queue1, node1->left);
            EnQueue(queue2, node2->left);
        }
        else if(!node1->left && !node2->left);
        else
            return false;
        
        if(node1->right && node2->right)
        {
            //printf("Pright %d %d\n", node1->right->val, node2->right->val);
            EnQueue(queue1, node1->right);
            EnQueue(queue2, node2->right);
        }
        else if(!node1->right && !node2->right);
        else
            return false;
    }
    
    return true;
}

================================================================
Recusrion
================================================================

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if(p == NULL && q == NULL) return true;
    
    if(p == NULL || q == NULL) return false;
    
    if(p && q && p->val == q->val)
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    
    return false;
}
