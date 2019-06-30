/*
Binary Tree Zigzag Level Order Traversal
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

Use Two Stacks

*/
typedef struct node
{
    struct TreeNode *tNode;
    struct node *next;
}NODE;

typedef struct
{
    NODE *top;
}STK;

typedef struct
{
    NODE *front, *rear;
}QUE;

STK *CreateStack()
{
    STK *q = malloc(sizeof(STK));
    q->top = NULL;
    return q;
}

void Push(STK *q, struct TreeNode *t)
{
    NODE *n =  malloc(sizeof(NODE));
    n->tNode = t;
    n->next = q->top;
    q->top = n;
    return;
}

struct TreeNode *Pop(STK *q)
{
    if(q->top == NULL)
        return NULL; 
    NODE *n = q->top;
    struct TreeNode *t = q->top->tNode;
    q->top = q->top->next;
    free(n);
    n = NULL;
    return t;
}

QUE *CreateQueue()
{
    QUE *q = malloc(sizeof(QUE));
    q->front  = q->rear = NULL;
    return q;
}

void EnQueue(QUE *q, struct TreeNode *t)
{
    NODE *n =  malloc(sizeof(NODE));
    n->tNode = t;
    n->next = NULL;
    
    if(q->front == NULL)
        q->front = n;
    else
        q->rear->next = n;
    
    q->rear = n;
    return;
}

struct TreeNode *DeQueue(QUE *q)
{
    if(q->front == NULL)
        return NULL;
        
    NODE *n = q->front;
    struct TreeNode *t = q->front->tNode;
    q->front = q->front->next;
    if(q->front == NULL)
        q->rear = NULL;
    
    free(n);
    n = NULL;
    return t;
}

int Height(struct TreeNode* t)
{
    if(t)
    {
        int l = Height(t->left);
        int r = Height(t->right);
        return l>r?l+1:r+1;
    }
    return 0;
}


int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){

    *returnSize = 0;
    int **a = NULL;
    *returnColumnSizes = NULL;
    
    if(root == NULL)
        return a;
    
    int size = Height(root);
    a = malloc(sizeof(int *)*size);
    *returnColumnSizes = malloc(sizeof(int)*size);  

    int i = 0;
    QUE *q = CreateQueue();
    EnQueue(q, root);
    
    //insert a dummy node
    struct TreeNode* dummy = NULL;
    EnQueue(q, dummy);
    
    i = 0;
    int count = 0;
    
    //this part is only to allocate the memory.
    while(q->front)//queue is not empty
    {
        struct TreeNode* t = DeQueue(q);     
        if(t == NULL)//dummy node
        {  
            (*returnColumnSizes)[i] = count;
            a[i] = malloc(sizeof(int)*count); 
            count = 0;
            i++;            
            EnQueue(q, dummy);     
            t = q->front->tNode;
            if(t == NULL)
            {
                DeQueue(q);
                break;//break the loop
            }
            continue;
        }
        count++;
        if(t->left)
            EnQueue(q, t->left);
        if(t->right)
            EnQueue(q, t->right);
    }
    
    //Below is the main part which does zig zag traversal
    STK *stk1 = CreateStack();
    STK *stk2 = CreateStack();
    Push(stk1, root);

    i = 0;
    count = 0;
    struct TreeNode* t;  
    while(stk1->top || stk2->top)
    {
        while(stk1->top)
        {
            t = Pop(stk1);
            a[i][count] = t->val;
            if(t->left)
                Push(stk2, t->left);
            if(t->right)
                Push(stk2, t->right);
            count++;
        }
        i++;
        count = 0;
        while(stk2->top)
        {
            t = Pop(stk2);
            a[i][count] = t->val;
            if(t->right)
                Push(stk1, t->right);
            if(t->left)
                Push(stk1, t->left);
            count++;
        }
        i++;
        count = 0; 
    }   
    
    *returnSize = size;
    return a;
}
