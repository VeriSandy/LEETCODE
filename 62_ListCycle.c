bool hasCycle(struct ListNode *head) {
 
    if(head == NULL) return false;
    
    struct ListNode *fast = head;
    
    struct ListNode *slow = head;

    while(fast)
    {
        fast = fast->next;
        if(fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        if(fast == slow)
            return true;
    }
    
    return false;
}
