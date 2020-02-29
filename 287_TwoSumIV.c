/*
1.  Traverse tree ==> can be inorder traversal
    For every node. see. if value exist there ==> using BST search

2.  Traverse tree ==> can be inorder traversal
    Keep the data in array.
    Then use two pointer approach to see if values exist.
*/

bool SearchTarget(struct TreeNode* root, int num)
{
    if(root == NULL) return false;
    
    if(num == root->val) return true;
    
    else if (num < root->val) 
        return SearchTarget(root->left, num);
    
    return SearchTarget(root->right, num);
        
}

void findTargetUtil(struct TreeNode* root, struct TreeNode* head, int k, bool *ret)
{
    if(root)
    {
        findTargetUtil(root->left,head, k, ret);
        
        //condition {k-root->val != root->val} to make sure that we are not looking for same item.
        //ex. - target = 4, root->val =2
        //we will search for same 2 and will return true
        if(k-root->val != root->val && SearchTarget(head, k-root->val))
        {
            *ret = true;
            return;
        }
        findTargetUtil(root->right,head, k, ret);
    }
    return;
}

bool findTarget(struct TreeNode* root, int k)
{
    if(root == NULL) return false;
    
    bool ret = false;
    
    findTargetUtil(root,root,k,&ret);
    
    return ret;
}
