/*
Serialize and Deserialize Binary Tree

Serialize string is kind of level order traversal of tree.
*/

#define null '$'

int *preArray = NULL;

void PreOrder(struct TreeNode* root,int *count, int *i)
{
    if(root)
    {
        *count += 1;
        *i += 1;
        PreOrder(root->left, count, i);
        PreOrder(root->right, count, i);
    }
    else
        *count += 1;
    return;
}

void serializeUtil(struct TreeNode* root,int *count, char *s, int *preArray, int *i)
{
    if(root)
    {
        //this is dummy, val is int and can't accomodate in char
        //either keep val as multibyte character, then we need a delimiter to seperate 
        //the next val from previous.
        
        //Keep it as dummy, keep values in Preorder array.
        s[*count] = 'a';
        preArray[*i] = root->val;
        *count += 1;
        *i += 1;
        serializeUtil(root->left, count, s, preArray, i);
        serializeUtil(root->right, count, s, preArray, i);
    }
    else
    {
        s[*count] = '$';
        *count += 1;
    }
    return;
}

/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root)
{
    int count = 0;
    int i = 0;
    PreOrder(root, &count, &i);
    
    char *s = malloc(count+1);
    preArray = malloc(sizeof(int)*i);
    
    memset(s, 0, count+1);
    
    count = 0;
    i = 0;
    serializeUtil(root, &count, s, preArray, &i);
    return s;
}

struct TreeNode* deserializeUtil(char* data, int *index, int *i)
{
    if(data == NULL || data[*index] == '$')
        return NULL;   
    
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = preArray[*i];
    *index  += 1;
    *i += 1; 
    root->left = deserializeUtil(data, index, i);
    *index  += 1;
    root->right = deserializeUtil(data, index, i);
    return root;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data)
{
    int i = 0, j = 0;
    struct TreeNode* root = deserializeUtil(data, &i, &j);
    
    free(preArray);
    preArray = NULL;
    return root;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
