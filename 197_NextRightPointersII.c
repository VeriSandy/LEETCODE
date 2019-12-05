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

3. Use preorder approach,reursive approach. Since this is not mention here, what kind of tree it is. So have to use pretty generalise approach.

4. Use Iterative approach.

*/

//Using level order traversal, use recursion.
class Solution {
public:
    
    int Height(Node* root)
    {
        if(root == NULL) return 0;
        
        int l = Height(root->left);
        int r = Height(root->right);
        
        return l>r?l+1:r+1;
    }
    
    void ConnectUtil(Node* root, int cur, int level, Node **t)
    {
        if(root == NULL) return;
        
        if(cur == level)
        {
            if(*t)
                (*t)->next = root;
            *t = root;
        }
        
        ConnectUtil(root->left, cur+1, level, t);
        ConnectUtil(root->right, cur+1, level, t);
        
        return;
    }
    
    Node* connect(Node* root)
    {
        if(root == NULL) return NULL;
        
        int h = Height(root), i = 0;
        
        Node *t;
        
        for(i = 0; i < h; i++)
        {
            t = NULL;
            ConnectUtil(root, 0, i, &t);
        }
        
        return root;
    }
};

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Use Iterative approach.
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
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Use preorder approach,reursive approach.
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
        
        //why this is first.
        //to conenct all the nodes at same level first, before moving to next level.
        if(root->next)
        {
            connect(root->next);
        }
        
        if(root->left)
        {
            if(root->right)
            {
                root->left->next = root->right;
                root->right->next = getNextRight(root);
            }
            else
                root->left->next = getNextRight(root);
            
            connect(root->left);
        }
        
        else if(root->right)
        {
            root->right->next = getNextRight(root);
            connect(root->right);
        }
        else
            connect(getNextRight(root));
        
        return root;
    }
};
