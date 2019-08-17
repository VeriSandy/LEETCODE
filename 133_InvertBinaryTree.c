//Invert Binary Tree

struct TreeNode* invertTree(struct TreeNode* root)
{   
    if(!root) return root;
    
    struct TreeNode *temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
}

/*
//python solution 
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:

        if(root == None):
            return root

        temp = root.left
        root.left = self.invertTree(root.right)
        root.right = self.invertTree(temp)
        return root
        
 */
