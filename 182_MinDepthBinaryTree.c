/*
Min depth is not min height.
Like - [1,null,2] it should return 2. Not 1(min height)
Reason  - we need to return length of shortest path from root to leaf node and in above example root is not leaf, so return path length from root to 2(leaf).
*/

int minDepth(struct TreeNode* root)
{
    if(root == NULL) return 0;
    
    //if no child, return 1.
    if(root->left == NULL && root->right == NULL)
        return 1;
    
    //in case of left child , consider left side path.
    if(root->left && root->right == NULL)
        return 1 + minDepth(root->left);
    
    //in case of right child , consider right side path.
    if(root->left == NULL && root->right)
        return 1 + minDepth(root->right);
    
    //if both child consider min.
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    
    return (l > r?r+1:l+1);
}
