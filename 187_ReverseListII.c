struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    if(m == n)
        return head;
    
    struct ListNode *tempHead = NULL, *tempEnd = NULL, *prev = NULL, *cur = head, *temp = NULL;
    
    int i = 1;
    
    while(i < m && cur)
    {
        tempHead = cur;
        cur = cur->next;
        i++;
    }
    
    tempEnd = cur;
    
    while(i <= n && cur)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
        i++;
    }
    
    if(m > 1)
        tempHead->next = prev;
    else
        head = prev;
    
    tempEnd->next = cur;
    
    return head;
}
