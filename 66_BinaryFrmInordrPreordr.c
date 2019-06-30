/*
Given preorder and inorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]

Use the concept - 
PreOrder gives the root.
And Inorder will give you, no of elements in right and left subtree.
Take care of corner cases, when only left subtree exist
and only right subtree exist.

Better use hashing concept to search the elements. As it might give O(n2). 
In case of skewed trees
FOr ex - Pre ==>[1,2,3,4] and In==> [4,3,2,1]

*/

struct TreeNode* buildTreeUtil(int* pre, int prel, int preh,int* in, int inl, int inh, int h)
{
    if(prel < 0 || inl < 0 || prel > preh || inl > inh || preh > h || inh > h)
        return NULL;
    
    struct TreeNode* t = malloc(sizeof(struct TreeNode));
    t->val = pre[prel];
    t->left = NULL;
    t->right = NULL;
    
    int inIndex = 0, preIndex = 0;
    
    //This search might give O(n2) complexity
    //as in case of skewed trees
    //Pre ==>[1,2,3,4] and In==> [4,3,2,1]
    //Better thing for searching is use hash map
    for(inIndex = inl; inIndex <= inh ; inIndex++)
    {
        if(pre[prel] == in[inIndex])
            break;
    }
    
    if(inIndex == inl)//there is no left subtree
        t->right = buildTreeUtil(pre, prel+1, preh, in, inIndex+1, inh, h);
    else if(inIndex == inh)//there is no right subtree
        t->left = buildTreeUtil(pre, prel+1, preh, in, inl, inIndex-1, h);
    else
    {
        int d = inIndex - inl; //these many elements will be there in left subtree
        preIndex = prel+d;
        
        t->left = buildTreeUtil(pre, prel+1, preIndex, in, inl, inIndex-1, h);
        t->right = buildTreeUtil(pre, preIndex+1, preh, in, inIndex+1, inh, h);
    }
    
    return t;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    if(preorderSize == 0) return NULL;
    struct TreeNode* t = NULL;
    t = buildTreeUtil(preorder, 0,preorderSize -1,inorder, 0, inorderSize-1, preorderSize-1);   
    return t;
}
