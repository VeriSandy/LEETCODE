void UtilCount(struct TreeNode* root, int sum, int* count, int *h)
{
    if(root == NULL)
        return;
    
    if(root->val == sum && root->right == NULL && root->left == NULL)
    {
        *count += 1;
        return;
    }
    
    int hl = 0, hr = 0;
    
    UtilCount(root->left, sum - root->val, count, &hl);
    UtilCount(root->right, sum - root->val, count, &hr);
        
    *h = (hl > hr)?hl+1:hr+1; 
    
    return;
}


void UtilFillArray(struct TreeNode* root, int sum, int* count,
                    int **out, int *returnColumnSizes, int *b, int k)
{
    if(root == NULL)
        return;
    
    b[k] = root->val;
    k++;
    if(root->val == sum && root->right == NULL && root->left == NULL)
    {
        int j = 0;
        out[*count] = malloc(sizeof(int)*k);
        returnColumnSizes[*count] = k;
        
        while(j < k)
        {
            out[*count][j] = b[j];
            //printf("%d ", b[j]);
            j++;
        }
        
        //printf("\n");
        *count += 1;
        return;
    }
    
    UtilFillArray(root->left, sum - root->val, count, out, returnColumnSizes, b, k);
    UtilFillArray(root->right, sum - root->val, count, out, returnColumnSizes, b, k);
    k--;
    
    return;
}

/*
int Height(struct TreeNode* root)
{
    if(root == NULL) return 0;
    
    int l = Height(root->left);
    int r = Height(root->right);
    
    return (l>r?l+1:r+1);
}
*/
    
int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes)
{
    //find count
    int count = 0, h = 0;
    UtilCount(root, sum, &count, &h);
    //printf("%d %d\n", count, h);
    
    
    //define arrays.
    int **out = malloc(sizeof(int *)*count);
    *returnColumnSizes = malloc(sizeof(int)*count);
    
    //Fill array
    //Have one temporary array to fill elements of one path.
    //For its size, get the height of tree, a path can't more than that length.
    //int hl = Height(root);
    //This height can also be calculated using count utility.
    int *b = malloc(sizeof(int) *(h+1));
    int k = 0;

    count = 0;
    UtilFillArray(root, sum, &count, out, *returnColumnSizes, b, k);
    
    //free(b);
    //b = NULL;
    
    *returnSize = count;
    return out;
}

