//Use just two Pointers
struct ListNode* swapPairs(struct ListNode* head)
{
    if(head == NULL || head->next == NULL) return head;
    
    struct ListNode *prev = head, *cur = head->next;
    
    //Keep the head safe here.
    prev->next = cur->next;
    cur->next = prev;
    head = cur;
    cur = prev->next;
    
    while(cur && cur->next)
    {
        prev->next = cur->next;
        prev = prev->next;
        
        cur->next = prev->next;
        prev->next = cur;
        
        prev = cur;
        cur = cur->next;
    }
    return head;
}
