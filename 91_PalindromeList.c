
struct ListNode* ReverseList( struct ListNode* node)
{
    if(node == NULL || node->next == NULL) return node;
    
    struct ListNode* cur = node, *prev = NULL, *temp = NULL;
    
    while(cur)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    
    return prev;
}

bool isPalindrome(struct ListNode* head){

    if(head == NULL) return true;
    
    struct ListNode *slow = head, *fast = head;
    
    //get the middle node.
    while(fast && fast->next)
    {
        fast = fast->next;
        
        if(fast && fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    
    fast = slow->next;
    slow->next = ReverseList(fast);
    
    fast = slow->next;
    slow = head;
    
    while(slow && fast)
    {
        if(slow->val != fast->val)
            return false;
        slow = slow->next;
        fast = fast->next;
    }
    
    return true;
}

