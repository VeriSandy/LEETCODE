/*
Unique Binary Search Trees II
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Idea --
Start with 1 to end, assigning each one root.
For a root, left and right subtree will have subtree different different structures.

*/
struct TreeNode* NewNode(int n)
{
    struct TreeNode *t = malloc(sizeof(struct TreeNode));
    t->val = n;
    t->right = NULL;
    t->left = NULL;   
    return t;
}

struct TreeNode **constructTrees(int start, int end, int *retsize)
{
    if(start > end)
    {
        //just to have loop run at least once.
        *retsize = 1;
        struct TreeNode **temp = malloc(sizeof(struct TreeNode*));
        temp[0] = NULL;
        return temp;
    }
    
    struct TreeNode **temp = malloc(sizeof(struct TreeNode*));
    *retsize = 0;
    int i = 0;
    for(i = start; i <= end; i++)
    {
        int leftSize = 0, rightSize = 0;
        struct TreeNode **leftTree = constructTrees(start, i-1, &leftSize);
        struct TreeNode **rightTree = constructTrees(i+1, end, &rightSize);
        temp = realloc(temp, (leftSize*rightSize + *retsize)*sizeof(struct TreeNode*));
        
        int left = 0, right = 0;
        for(left = 0; left < leftSize; left++)
        {
            for(right = 0; right < rightSize; right++)
            {
                temp[*retsize] = NewNode(i);
                temp[*retsize]->left = leftTree[left];
                temp[*retsize]->right = rightTree[right];
                (*retsize)++;
            }
        }
    }
    return temp;
}

struct TreeNode** generateTrees(int n, int* returnSize)
{
    if(n == 1)
    {
        struct TreeNode **temp = malloc(sizeof(struct TreeNode*));
        *returnSize = 1;
        temp[0] = NewNode(1);
        return temp;
    }
    if(n == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    return constructTrees(1, n, returnSize);
}
