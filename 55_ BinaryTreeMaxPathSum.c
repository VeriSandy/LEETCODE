/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
Max path sum would be max of 
1. left subtree max path + root
2. right subtree max path + root
3. sum including left, right and root
4. only root

Also we need max path for parent, so thats what we have to return
*/

//Here max funtion nedd little change
//as if i have only negative nodes, it might result in zero.
//for ex - [-3,-10,-1] or [-3, -10, 0]
int max(int a, int b, int flag)
{
    //if all elements are negative
    if(flag)
    {
       if(a == 0) return b;
       if(b == 0) return a; 
    }
    return a > b?a:b;
}


int maxPathSumUtility(struct TreeNode* root, int *res, int flag)
{
    if(root == NULL) return 0;
    
    int LSum = maxPathSumUtility(root->left, res, flag);
    int RSum = maxPathSumUtility(root->right, res, flag);
    
    int single_sum = max(max(LSum, RSum, flag)+root->val, root->val, flag);
    
    int Max = max(single_sum, LSum + RSum + root->val, flag);
    
    *res = max(*res, Max, flag);
    
    return single_sum;
}

void InOrder(struct TreeNode* root, int *flag)
{
    if(root)
    {
       InOrder(root->left, flag);
       if(root->val >= 0 )
       {
           *flag = 0;
           return;
       }
       InOrder(root->right, flag); 
    }
    return;
}

int maxPathSum(struct TreeNode* root){

    if(root == NULL) return 0;
    
    if(root->left == NULL && root->right == NULL)
        return root->val;
    
    int res = 0;
    
    //See if all elements are negative
    //In that case 0 can be treated as highest
    int flag = 1;
    
    InOrder(root, &flag);
    
    maxPathSumUtility(root, &res, flag);
    
    return res;
}
