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


/*
Ideas -- 
1. Using level order traversal, use recursion.

2. Using level order traversal, use queue method. 
Take one queue, put root node and mark with one delimiter.
while processing the queue, keep pushing the left and right child once you get the delimiter, push another delimter. 

For next node - 
While processing the queue 
remove front node and mark front node in queue as next node of popped node
If it is delimiter, mark next node as NULL.

3. Use preorder approach(mostly correct for complete binary tree or perfect binary tree), reursive approach.

4. Use Iterative approach.

*/
//1. Using level order traversal, use recursion.
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
======================================================================================================
 //3. Use preorder approach(mostly correct for complete binary tree or perfect binary tree), reursive approach.
class Solution { 
public:
  Node* connect(Node* root)
  {
      if(root == NULL) return NULL;

      if(root->left)
          root->left->next = root->right;

      if(root->right)
          root->right->next = root->next?root->next->left:NULL;

      connect(root->left);
      connect(root->right);

      return root;
  }
};
======================================================================================================
//4. Use Iterative approach
class Solution { 
public:
    
    
    Node* getNextRight(Node* root)
    {
        Node *temp = root->next;
        
        while(temp)
        {
            if(temp->left) return temp->left;
            if(temp->right) return temp->right;
            temp = temp->next;
        }
        
        return NULL;
    }
    
    Node* connect(Node* root)
    {
        if(root == NULL) return NULL;
        root->next = NULL;
        
        Node *p = root, *q = root;
        
        while(q)
        {
            p = q;
            
            while(p)
            {
                if(p->left)
                {
                    if(p->right)
                        p->left->next = p->right;
                    else
                        p->left->next = getNextRight(p);
                }

                if(p->right)
                    p->right->next = getNextRight(p);

                p = p->next;
            }
         
            if(q->left)
                q = q->left;
            else if(q->right)
                q = q->right;
            else
                q = getNextRight(q);
        }
        
        return root;
    }
};
