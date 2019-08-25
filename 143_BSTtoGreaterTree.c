/*
Convert BST to Greater Tree
Idea -- 
Use kind of reverse Inorder here, 
Inorder gives, sorted array ascending order.
    
We need sort in descending order and keep adding the previous sum if any, in current code.
*/
void convertBSTUtilty(struct TreeNode* root, int *sum)
{
    if(root == NULL) return;
    
    convertBSTUtilty(root->right, sum);
    root->val += *sum;
    *sum = root->val;
    convertBSTUtilty(root->left, sum);
    return;
}

struct TreeNode* convertBST(struct TreeNode* root)
{
    int sum = 0;
    convertBSTUtilty(root, &sum);
    return root;
}
