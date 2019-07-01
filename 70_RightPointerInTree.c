/*
Populating Next Right Pointers in Each Node

You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. 
The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node.
If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
*/

class Solution {
    
public:
    
    int Height(Node *root)
    {
        if(root)
        {
            int l = Height(root->left);
            int r = Height(root->right);
            
            return l>r?l+1:r+1;
        }
        return 0;
    }
    
    void ConnectUtility(Node *root, int cur, int level, Node **t)
    {   
        if(cur > level || root == NULL) return;
        
        if(cur == level)
        {
            if(*t != NULL)
            {
                //printf("t == %d root = %d", (*t)->val, root->val);
                (*t)->next = root;
            }
            else
                printf("%d ", root->val);
            *t = root;
            
            //printf("%d ", root->val);
        }
        
        ConnectUtility(root->left, cur+1, level, t);
        ConnectUtility(root->right, cur+1, level, t);
        
        return;
    }
    
    Node* connect(Node* root){
        
        if(root == NULL) return NULL;
                
        int h = Height(root);
        int i = 0;
        Node *t = NULL;
        
        for(i = 0; i < h; i++)
        {
            t = NULL;
            ConnectUtility(root, 0, i, &t);
            //printf("\n");   
        }
        return root;
    }
};
