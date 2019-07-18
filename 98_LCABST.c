
/*
Lowest Common Ancestor.

If root’s value is greater than both p and q then our LCA lies in left side of the node, 
if it’s is smaller than both p and q, then LCA lies on right side. 
Otherwise root is LCA.
*/

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) 
{
    if(root == NULL) return NULL;
    
    //if both values are lower than root, search in left subtree.
    if(root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
    
    //if both values are higher than root, search in right subtree.
    if(root->val < p->val && root->val < q->val)
        return  lowestCommonAncestor(root->right, p, q);
    
    //otherwise
    return root;
}


=======================

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) 
{
    if(root == NULL) return NULL;
    
    if(root == p || root == q)
        return root;
    
    struct TreeNode *l = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *r = lowestCommonAncestor(root->right, p, q);
    
    if(l && r)
        return root;
    
    return l?l:r;
}
