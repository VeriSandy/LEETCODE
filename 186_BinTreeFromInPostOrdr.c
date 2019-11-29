/*
Inorder ==> 9,3,15,20,7
PostOrder ==> 9,15,7,20,3

3 is the root
9,15,7,20,[3] ==> post

From IN we will know this is the left part that root and other is the right.
From POST order we kno this is the root.
So need to exploit both the traversal mechanisms

{9}left[3]right{15,20,7} ==>in
{9}right left{15,7,20} [3] ==> post

{9}right left{15,7,[20]} [3] ==> post
{9}left[3]right{{15}left [20] right{7}} ==>in
{9}right left{{15}left right{7} [20]} [3] ==> post

//no right
[15,20,7,3] ==> IN
[15,7,20,3] ==> POST

//no left
[3,15,20,7] ==> in
[15,7,20,3] ==> post

Surely We need recursion here.

O(n2)
Searching also takes O(n)
See if hashing can be used to get the indexes directly. So searching would take O(1).
So complexity can be reduced to O(n) from O(n2).
*/

struct TreeNode *NewNode(int data)
{
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, 
                           int* postorder, int postorderSize)
{
    if(inorderSize == 0 || postorderSize == 0) return NULL;
    
    struct TreeNode *root = NewNode(postorder[postorderSize -1]);
    
    int i = 0;
    
    //This is going to take O(n)
    //Is there a way to reduce it like O(1), hashing can be used.
    while(i < inorderSize && inorder[i] != postorder[postorderSize -1])
        i++;
    
    //in case if No left
    if(i == 0)
    {
        root->right = buildTree(&inorder[1], inorderSize-1, 
                                postorder, postorderSize-1);
    }
    //in case of no right
    if(i == inorderSize -1)
    {
       root->left = buildTree(inorder, inorderSize-1, postorder, postorderSize-1); 
    }
    else
    {
        //printf("%d\n", i);
        root->left = buildTree(inorder, i, postorder, i);
        root->right = buildTree(&inorder[i+1], inorderSize-i-1, 
                                &postorder[i], postorderSize-i-1);
    }
    
    return root;
}

