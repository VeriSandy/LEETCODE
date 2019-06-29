/*
Convert Sorted Array to Binary Search Tree
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the 
two subtrees of every node never differ by more than 1.

exploit the sorted array.
Assign mid to root and divide array in two parts.
assign left mid to left child of root
assign right id to right child of root.

And go on recursively.

*/

 struct TreeNode* BuildTree(int *nums, int l, int h)
 {
    if(l > h) return NULL;
    struct TreeNode* t = malloc(sizeof(struct TreeNode));
    int mid  = (l+h)/2;
    t->val = nums[mid];
    t->left = NULL;
    t->right = NULL;
    t->left = BuildTree(nums, l, mid-1);
    t->right = BuildTree(nums, mid+1, h);
    return t;
 }

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if(numsSize == 0) return NULL;
    int i = 0;    
    struct TreeNode* t = NULL;
    t = BuildTree(nums, 0, numsSize-1);
    return t;
}

