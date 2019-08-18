'''
House Robber III --
IDEA -- recursive relation

If taking root, then add it with grandchildren.
If not taking root, call for its children
Finally max of these two.

This would be max of 
1. root + max(childs of right node) + max(childs of left node)
2. max(right child) + max(left child)

val at any node can be rememebr to make it fast.
'''
//pyhton solution 
class Solution:
    def rob(self, root: TreeNode) -> int:
        
        def GrandChildRob(root, dct):
            temp1 = (robUtility(root.right.left, dct) + robUtility(root.right.right, dct)) if root.right else 0
            temp2 = (robUtility(root.left.left, dct) + robUtility(root.left.right, dct)) if root.left else 0
            return temp1 + temp2
            
        def robUtility(root, dct):
            if(root == None):
                return 0
            
            val = dct.get(root)
            if(val is not None):
                return val
            
            tempGrandChild = root.val + GrandChildRob(root, dct)
            
            tempChild = robUtility(root.right, dct) + robUtility(root.left, dct)
            
            dct[root] = max(tempGrandChild, tempChild)
            return dct[root]
        
        
        if(root == None):
            return 0
        dct = {}
        return robUtility(root, dct)
    
'''
//c recursion    
 int max(int a, int b)
{
    return a>b?a:b;
}

int rob(struct TreeNode* root)
{
        if(root == NULL) return 0;
        int Max = 0;
    
        int temp1 = root->right?(rob(root->right->left) + rob(root->right->right)):0;
        int temp2 = root->left?(rob(root->left->left) + rob(root->left->right)):0;
        int temp = root->val + temp1 + temp2;
            
        int tempRight = root->right?rob(root->right):0;
        int tempLeft = root->left?rob(root->left):0;
    
        int temp3 = tempRight + tempLeft;
    
        Max = max(temp, temp3);
        return Max;
}
'''
