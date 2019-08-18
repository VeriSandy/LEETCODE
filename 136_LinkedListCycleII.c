
struct ListNode *detectCycle(struct ListNode *head)
{ 
    if(head == NULL) return NULL;
    
    struct ListNode *slow = head, *fast = head, *prev = NULL;
    int flag = 0;
    
    while(slow && fast)
    {
        fast = fast->next;
        if(fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        if(slow == fast)
        {
            flag = 1;
            break;
        }
    }
    
    if(!flag) return NULL;
    
    fast = head;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    } 
    return fast;
}
