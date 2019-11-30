/*
Ideas -- 
    1. Get the middle node, make the root of tree
        recursivley find the middle node of left half make the root of left child 
        and make the middle node of right half the root of right child
        O(NLogN)
        
    2. If we convert List into array, searching middle element would take only constant time
        So complexity would come down to O(n).
        
*/

struct TreeNode *NewNode(int data)
{
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* sortedListToBST(struct ListNode* head)
{
    if(head == NULL) return NULL;
    
    if(head->next == NULL) 
        return NewNode(head->val);
    
    //find the middle node.
    struct ListNode *slow = head, *fast = head, *prev = head;
    
    while(fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    
    fast = slow->next;
    slow->next = NULL;
    prev->next = NULL;
    
    struct TreeNode *root = NewNode(slow->val);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(fast);
    
    return root;
}
===================================================
struct TreeNode *NewNode(int data)
{
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* sortedListToBSTUtility(int *a, int l, int h)
{
    if(l > h) return NULL;
    //find the middle node.
    int mid = (l+h)/2;
    struct TreeNode *root = NewNode(a[mid]);
    
    root->left = sortedListToBSTUtility(a, l, mid -1);
    root->right = sortedListToBSTUtility(a, mid+1, h);
    
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head)
{
    if(head == NULL) return NULL;
    
    if(head->next == NULL) 
        return NewNode(head->val);
    
    int i = 0;
    struct ListNode *cur = head;
    
    while(cur)
    {
        cur = cur->next;
        i++;
    }
    
    
    int *a = malloc(sizeof(int)*i);
    
    i = 0;
    cur = head;
    
    while(cur)
    {
        a[i] = cur->val;
        cur = cur->next;
        i++;
    }
    //printf("%d\n", i);
    return sortedListToBSTUtility(a,0,i-1);
}
