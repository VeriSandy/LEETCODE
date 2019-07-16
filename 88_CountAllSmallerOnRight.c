/*
Count of Smaller Numbers After Self

You are given an integer array nums and you have to return a new counts array. 
The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

IDEAS -- 
    1. use two loops approach -- O(n2)
    2. Use BST, as smaller will be in left subtree and others will be in right
*/

typedef struct tree
{
    int data;
    struct tree *left, *right;
    int lessor;
}TREE;

TREE *NewNode(int data)
{
    TREE *t = malloc(sizeof(TREE));
    t->data = data;
    t->left = t->right = NULL;
    t->lessor = 0;
    return t;
}

TREE* insert(TREE* node, int data, int *count)
{
    if(node == NULL)
    {
        return NewNode(data);
    }
    
    if(data < node->data)
    {
        node->lessor++;
        node->left = insert(node->left, data, count);
    }
    else if (data > node->data)
    {
        *count += node->lessor +1;
        node->right = insert(node->right, data, count);
    }
    else
    {
        *count += node->lessor;
        node->right = insert(node->right, data, count);
    }
    return node;
}

int* countSmaller(int* nums, int numsSize, int* returnSize)
{
    int *low = (int *)malloc(sizeof(int)*numsSize);
    memset(low, 0, sizeof(int)*numsSize);

    int i;
    TREE *t = NULL;
    for (i = numsSize -1; i >=0; i--) 
        t = insert(t, nums[i], &low[i]);
    
    *returnSize = numsSize;
    return low;
}
