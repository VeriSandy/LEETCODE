
/*
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

