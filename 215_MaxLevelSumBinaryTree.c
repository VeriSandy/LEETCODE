/*
1. Use level order sum, find sum at one level
return min level of max sum.

2. Use BFS + level order concept.
BFS == visit the neighbors first. Then visit the neighbors of neighbors.
i.e Indirectly level by level.
*/

int Height(struct TreeNode* root)
{
    if(root == NULL) return 0;
    
    int l = Height(root->left);
    int r = Height(root->right);
    
    return l>r?l+1:r+1;
}


void BFS(struct TreeNode* root, int level, int *temp)
{
    if(root == NULL) return;
    
    temp[level] += root->val;
    
    BFS(root->left, level+1, temp);
    BFS(root->right, level+1, temp);
    
    return ;
}


int maxLevelSum(struct TreeNode* root)
{
    if(root == NULL) return 0;
    
    int h = Height(root);//will give you no of levels.
    
    //get the sum at each level
    int *temp = malloc(sizeof(int)*h);
    
    BFS(root, 0, temp);
    
    int i = 1, max = 0, level = 0;
    
    max = temp[0];
    
    while(i < h)
    {
        if(max < temp[i])
        {
            max = temp[i];
            level = i+1;
        }
        i++;
    }
    
    return level;
}

=============================================================================================================================
//Complete level order traversal

int Height(struct TreeNode* root)
{
    if(root == NULL) return 0;
    
    int l = Height(root->left);
    int r = Height(root->right);
    
    return l>r?l+1:r+1;
}

void SumUtility(struct TreeNode* root, int base, int level, int *sum)
{
    if(base > level || root == NULL)
        return;
    
    if(base == level)
    {
        *sum += root->val;
    }
    
    SumUtility(root->left, base+1, level, sum);
    SumUtility(root->right, base+1, level, sum);
    
    return;
}

int maxLevelSum(struct TreeNode* root)
{
    if(root == NULL)
        return 1;
    
    int h = Height(root);
    
    int i = 0;
    int sum = 0;
    int max = INT_MIN, level = 0;
    
    while(i < h)
    {
        sum = 0;
        SumUtility(root, 0, i, &sum);
        i++;
        //printf("%d \n", sum);
        
        if(sum > max)
        {
            level = i;
            max = sum;
        }
    }
    
    return level;
}
