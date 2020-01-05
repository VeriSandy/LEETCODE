
/*
Since it is given that it is BST so exploit that property. Use Inorder as it will 
give the sorted array.

Now, we need to count the number of same elements ==> CurCount
PrevCount ==> Keep the prev count of same elements there.

TotalCount ==> Will keep the count of "most frequently occured elements" i.e. if any one element is most frequently occured element then TotalCount = 1 and if there are two elements which are most frequently occured elements then TotalCount = 2.

If PrevCount < CurCount ==> Implies we got highest frequency element from the previous ones. So totalCount also change here and it would be reset to 1.

*/

void Inorder(struct TreeNode* root, int *prevCount, int *curCount, 
             int *totalCount, int *first, int *prev)
{
    if(root == NULL)
        return;
    
    Inorder(root->left, prevCount, curCount, totalCount, first, prev);
    
    if(*first == 0)
    {
        *prev = root->val;
        *first = 1;
        *curCount = 1;
    }
    else
    {
        if(*prev == root->val)
        {
            *curCount += 1;
        }
        else if(*prev < root->val)
        {
            if(*prevCount < *curCount)
            {
                *prevCount = *curCount;
                *totalCount = 1;
            }
            else if(*prevCount == *curCount)
            {
                *totalCount += 1;
            }
            *curCount = 1;
            *prev = root->val;
        }
    }
    
    Inorder(root->right, prevCount, curCount, totalCount, first, prev);
    return;
}

void InorderUtil(struct TreeNode* root, int *prevCount, int *curCount, 
             int *totalCount, int *first, int *prev, int *out, int max)
{
    if(root == NULL)
        return;
    
    InorderUtil(root->left, prevCount, curCount, totalCount, first, prev, out, max);
    
    if(*first == 0)
    {
        *prev = root->val;
        *first = 1;
        *curCount = 1;
    }
    else
    {
        if(*prev == root->val)
        {
            *curCount += 1;
        }
        else if(*prev < root->val)
        {
            if(*prevCount < *curCount)
            {
                *prevCount = *curCount;
                out[0] = *prev;
                *totalCount = 1;
            }
            else if(*prevCount == *curCount)
            {
                //have this condition here.
                //as it can be that we have more number of "lower frequency" elements
                //than the actual "the most frequently" ones.
                //so dont go out of bounds, 
                //we will get it reset when *prevCount < *curCount
                if(*totalCount < max)
                    out[*totalCount] = *prev;
                
                *totalCount += 1;
                //printf("%d\n", *totalCount);
            }
            *curCount = 1;
            *prev = root->val;
        }
    }
    
    InorderUtil(root->right, prevCount, curCount, totalCount, first, prev, out, max);
    return;
}


int* findMode(struct TreeNode* root, int* returnSize)
{
    if(root == NULL)
    {    
        *returnSize = 0;
        return NULL;
    }
    int curCount = 0, totalCount = 0, first = 0, prev = 0, prevCount = 0;
    Inorder(root, &prevCount, &curCount, &totalCount, &first, &prev);
    
    if(prevCount < curCount)
    {
        prevCount = curCount;
        totalCount = 1;
    }
    else if(prevCount == curCount)
    {
        totalCount += 1;
    }
    
    printf("%d %d\n", prevCount, totalCount);
    
    
    int max = totalCount;
    int *out = malloc(sizeof(int)*totalCount);
    curCount = 0, totalCount = 0, first = 0, prev = 0, prevCount = 0;
    InorderUtil(root, &prevCount, &curCount, &totalCount, &first, &prev, 
                out, max);
    
    if(prevCount < curCount)
    {
        prevCount = curCount;
        totalCount = 1;
        out[0] = prev;
    }
    else if(prevCount == curCount)
    {
        if(totalCount < max)
            out[totalCount] = prev;
        totalCount += 1;
    }
    
    *returnSize = totalCount;
    return out;
}
