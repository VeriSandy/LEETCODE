/*
Flatten Binary Tree to Linked List

Idea -- 
Something like recursion, should work.
Have one stack, keep right node of root in list.
make left of root, right of node, and left point to null
*/

struct TreeNode* flattenUtility(struct TreeNode* root, struct TreeNode **last)
{
    if(root == NULL) return NULL;
        
    if(root->left == NULL && root->right == NULL)
    {
        *last = root;
        return root;
    }
    
    struct TreeNode *temp1 = root->left;
    struct TreeNode *temp2 = root->right;
    
    root->left = NULL;
    root->right = flattenUtility(temp1,last);
    
    if(root->right)//right  chiild of root exist, then add to the right of last node.
        (*last)->right = flattenUtility(temp2,last);
    else
        root->right = flattenUtility(temp2,last);
    
    return root;
}

void flatten(struct TreeNode* root)
{
    if(root == NULL)
        return;
    
    struct TreeNode* last = NULL;//need to track the last right node
    root = flattenUtility(root, &last);
    return;
}
