/*
Idea -- 
Total num of paths
Using root node + right subtree paths + left subrtee paths
*/
void Util(struct TreeNode* root, int sum, int *count)
{
    if(root == NULL) return;
    
    if(root->val == sum)
        *count = *count +1;
    Util(root->left, sum - root->val, count);
    Util(root->right, sum - root->val, count);
    
    return;
}

int pathSum(struct TreeNode* root, int sum)
{
    if(root == NULL) return 0;
    int count  = 0;
    Util(root, sum, &count);
    return count + pathSum(root->left, sum) + pathSum(root->right, sum);
}
