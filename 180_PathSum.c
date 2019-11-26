bool hasPathSum(struct TreeNode* root, int sum)
{
    if(root == NULL)
        return false;
    
    if(sum == root->val && root->left == NULL && root->right == NULL)
        return true;
    
    return hasPathSum(root->left, sum - root->val) 
                ||
                hasPathSum(root->right, sum - root->val);
}


