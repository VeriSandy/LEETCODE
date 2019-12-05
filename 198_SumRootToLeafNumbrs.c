/*
Idea -- 
keep a path sum in temp variable and add it to the existing sum when you reach to a leaf.

Calculate all path sum using recursion.

*/

void sumNumbersUtil(struct TreeNode* root, int temp, int *sum)
{
    if(root == NULL) return;
    
    if(root->left == NULL && root->right == NULL)
    {
        temp = temp*10+root->val;
        *sum += temp;
        return;
    }
    
    sumNumbersUtil(root->left, temp*10+root->val, sum);
    sumNumbersUtil(root->right, temp*10+root->val, sum);
    return;
}


int sumNumbers(struct TreeNode* root)
{
    int temp = 0;
    int sum = 0;
    sumNumbersUtil(root, temp, &sum);
    return sum;
}
