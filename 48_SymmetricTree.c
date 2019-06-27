
'''
This is iterative approach. 
We use Queue here. Note that for a symmetric that elements at every level are palindromic.
In other words,
1. The left child of left subtree = right child of right subtree.
2. The right child of left subtree = left child of right subtree.

If we insert the left child of left subtree first followed by right child of the right subtree in the queue, we only need to ensure that these are equal.
Similarly, If we insert the right child of left subtree followed by left child of the right subtree in the queue, we again need to ensure that these are equal.

'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        
        if(root == None):
            return True
        
        if(not root.left and not root.right):
            return True
        
        q = []
        q.append(root)
        q.append(root)
        
        leftNode = 0
        rightNode = 0
        
        while(len(q) != 0):
            
            leftNode = q[0]
            q.pop(0)
            rightNode = q[0]
            q.pop(0)
            
            if(leftNode.val != rightNode.val):
                return False
            
            if(leftNode.left and rightNode.right):
                q.append(leftNode.left)
                q.append(rightNode.right)
                
            elif(leftNode.left or rightNode.right):
                return False
            
            if(leftNode.right and rightNode.left):
                q.append(leftNode.right)
                q.append(rightNode.left)
                
            elif(leftNode.right or rightNode.left):
                return False
            
        return True           
        
 ==========================================================
 
 //Recursion
 
 
bool isSymmetricUtility(struct TreeNode* root1, struct TreeNode* root2){
    
    if(root1 == NULL && root2 == NULL) return true;
    
    if(root1 == NULL || root2 == NULL) return false;
    
    if(root1->val == root2->val)
        return isSymmetricUtility(root1->left, root2->right) 
                && isSymmetricUtility(root1->right, root2->left);
    
    return false;
}



bool isSymmetric(struct TreeNode* root){

    if(!root) return true;
    
    
    return isSymmetricUtility(root, root);
}
