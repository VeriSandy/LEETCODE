/*
Diameter of Binary Tree --

Idea -- 
Calculate the longest path at right node, left node.
Longest path would be max of(dia(right_subtree), dia(left_subtree) 
                            height(right_subtree) + height(left_subtree) + including root)

*/
int max(int a, int b)
{
    return a>b?a:b;
}

int diameterOfBinaryTreeUtility(struct TreeNode* root, int *h)
{
    if(root == NULL) return 0;
    
    int hl = 0, hr = 0;
    
    int ld = diameterOfBinaryTreeUtility(root->left, &hl);
    int rd = diameterOfBinaryTreeUtility(root->right, &hr);
    
    *h = max(hl,hr)+1;
    
    return max(hl+hr+1, max(ld,rd));
}

int diameterOfBinaryTree(struct TreeNode* root)
{
    if(root == NULL) return 0;
    
    int h = 0;
    
    return diameterOfBinaryTreeUtility(root, &h) -1;
}
========================================================

int max(int a, int b)
{
    return a>b?a:b;
}

int Height(struct TreeNode* root)
{
    if(root == NULL) return 0;
    
    int l = Height(root->left);
    int r = Height(root->right);
    
    return l>r?l+1:r+1;
}

int diameterOfBinaryTreeUtility(struct TreeNode* root)
{
    if(root == NULL) return 0;
    
    int l = Height(root->left);
    int r = Height(root->right);
    
    int ld = diameterOfBinaryTreeUtility(root->left);
    int rd = diameterOfBinaryTreeUtility(root->right);
    
    return max(l+r+1, max(ld,rd));
}

int diameterOfBinaryTree(struct TreeNode* root)
{
    if(root == NULL) return 0;
    
    return diameterOfBinaryTreeUtility(root) -1;
}
