/*
Lowest Common Ancestor of a Binary Tree

Ideas -- 
1. 
    a. Find path from root to p and store it in array.
    b. Find path from root to q and store it in another array.
    c. Traverse both paths till the values in arrays are same. 
    d. Return the common element just before the mismatch. 

2. Use the another approach here, similar to LCA in BST.
If root’s value is greater than both p and q then our LCA lies in left side of the node, 
if it’s is smaller than both p and q, then LCA lies on right side. 
Otherwise root is LCA.

3. Parent pointer approach also can be used. 
Find out the path length for each. Traverse up equal to diff from the larger path length.
And then move up together for both, unless you have the same parent.

*/

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, 
                                      struct TreeNode* p, struct TreeNode* q)
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
