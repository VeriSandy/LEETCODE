/*
Idea -- 

Tree is height balanced - 
1. if( Height(left) - Height(R)) <= 1.
2. Left Subtree is Height Balanced.
2. Right Subtree is Height Balanced.
return true;
ELse
    return False.
*/

int ABS(int a)
{
    return (a >0?a:-a);
}

//calculate height in same function
bool UtilBalanced(struct TreeNode* root, int *h)
{
    if(root == NULL) return true;
    
    int hl = 0, hr = 0;
    
    bool l = UtilBalanced(root->left, &hl);
    bool r = UtilBalanced(root->right, &hr);
    
    if(ABS(hl-hr) >1) return false;
    
    *h = hl>hr?hl+1:hr+1;
    
    return l && r;
}

bool isBalanced(struct TreeNode* root)
{
    int h = 0;
    return UtilBalanced(root, &h);
}
