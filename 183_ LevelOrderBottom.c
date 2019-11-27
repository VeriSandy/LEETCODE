/*
Idea -- 
One way of doing it.
Write level order in up to bottom and then reverse it.

2. How about doing it recursivley
print last level first then pre last level up and then.. to top
*/


int Height(struct TreeNode* root)
{
    if(root == NULL) return 0;
    
    int l = Height(root->left);
    int r = Height(root->right);
    
    return l>r?l+1:r+1;
}
void UtilBottomLevel(struct TreeNode* root, int base, int level, int *k)
{
    if(root == NULL) return;

    if(base == level)
    {
        *k += 1;
        //printf("%d ", root->val);
        return;
    }
    
    UtilBottomLevel(root->left, base+1, level, k);
    UtilBottomLevel(root->right, base+1, level, k);
    
    return;
}

void UtilBottomLevelFillArray(struct TreeNode* root, int base, int level, 
                                int** out, int *k, int j)
{
    if(root == NULL) return;

    if(base == level)
    {
        out[j][*k] = root->val;
        *k += 1;
    }
    
    UtilBottomLevelFillArray(root->left, base+1, level, out, k, j);
    UtilBottomLevelFillArray(root->right, base+1, level, out, k, j);
    
    return;
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    int h = Height(root);
    
    //printf("h = %d\n", h);
    //We need an array. 
    //We need a temp array.
    int **out = malloc(sizeof(int *)*h);
    *returnColumnSizes = malloc(sizeof(int)*h);
    
    //temp length array, should pow(2,h)
    //int *temp = malloc(sizeof(int)*((int)pow(2,h)));
    //This temp array, is faling when Height is 751 :-(
    //So allocate array once and then fill in second time.
    int i = 0, k = 0;
    
    //allocate memory
    for(i = 0; i < h; i++, k = 0)
    {
        UtilBottomLevel(root, 0, h-i-1, &k);
        out[i] = malloc(sizeof(int)*k);
        (*returnColumnSizes)[i] = k;
        
        //printf("\n");
    }
    
    //fill array.
    for(i = 0; i < h; i++, k = 0)
    {
        UtilBottomLevelFillArray(root, 0, h-i-1, out, &k, i);
    }
    
    *returnSize = h;
    return out;
}
