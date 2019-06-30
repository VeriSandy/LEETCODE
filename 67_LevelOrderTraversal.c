/*
Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

Idea -- Use Queue
And NULL as a delimiter
*/

typedef struct node
{
    struct TreeNode *tNode;
    struct node *next;
}NODE;

typedef struct
{
    NODE *front, *rear;
}QUE;

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

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){

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
    
    EnQueue(q, root);
    EnQueue(q, dummy);    
    i = 0;
    count = 0;
    while(q->front)//queue is not empty
    {
        struct TreeNode* t = DeQueue(q);
        if(t == NULL)//dummy node
        {  
            printf("\n");
            //printf("i = %d count = %d\n", i , count);
            count = 0;
            i++;            
            EnQueue(q, dummy);     
            t = q->front->tNode;
            if(t == NULL)
                break;//break the loop
            continue;
        }
        //printf("%d ", t->val);
        a[i][count] = t->val;
        count++;
        if(t->left)
            EnQueue(q, t->left);
        if(t->right)
            EnQueue(q, t->right);
    }
    
    *returnSize = size;
    return a;
}
