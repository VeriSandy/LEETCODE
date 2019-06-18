/*
Idea -- 
Use stack inplace of recursion.
1. If root has left child, keep pushing till root->left is NULL
2. Remove the last pushed node from the stack, print it. 
3. See if the last removed node has right child, Push it to Stack, set this to root.
4. Repeat above steps till stack is not empty.
*/

typedef struct node
{
    struct TreeNode* t;
    struct node *next;
}NODE;

typedef struct stack
{
    int size;
    NODE *top;
}STACK;


STACK *CreateStack()
{
    STACK *stk = malloc(sizeof(STACK));
    stk->size = 0;
    stk->top = NULL;
    return stk;
}

void PushStack(STACK *stk, struct TreeNode* data)
{
    NODE *temp = malloc(sizeof(struct TreeNode));
    temp->t = data;
    temp->next = stk->top;
    stk->top = temp;
    stk->size++;
}

struct TreeNode* PopStack(STACK *stk)
{
    if(stk->top == NULL) return NULL;
    
    NODE *temp = stk->top;
    struct TreeNode* t= temp->t;
    stk->top = stk->top->next;
    free(temp);
    temp = NULL;
    stk->size--;
    return t;
}

int IsEmpty(STACK *stk)
{
    return (stk->top == NULL);
}

int noOfNodes(struct TreeNode* root)
{
    if(!root) return 0;
    
    return 1+ noOfNodes(root->left) + noOfNodes(root->right);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int n = noOfNodes(root);
    //printf("%d\n", n);
    *returnSize = n;
    
    int *a = malloc(sizeof(int)*n);
    memset(a, 0x00, sizeof(int)*n);
    int l = 0;
    
    if(!n) return a;
    //Iorder
    //you need to first process, left then root then right side.    
    STACK *stk = CreateStack(); 
    PushStack(stk, root);
    
   //struct TreeNode* root1 = PopStack(stk);
   //     printf("%d ", root1->val);
    
    while(!IsEmpty(stk))
    {
        if(root && root->left)
        {
            PushStack(stk, root->left);
            root = root->left;
            continue;
        }
        
        struct TreeNode* temp = PopStack(stk);    
        //printf("%d ", temp->val);
        a[l++] = temp->val;
        
        if(temp->right)
        {
            PushStack(stk, temp->right);
            root = temp->right;
        }
    }  
    return a;
}
