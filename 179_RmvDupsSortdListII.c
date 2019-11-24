struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    struct ListNode *cur = head, *prev = NULL, *temp = NULL;
    int dups = 0;
    
    while(cur && cur->next)
    {
        dups = 0;
        while(cur && cur->next && cur->val == cur->next->val)
        {
            temp = cur->next;
            cur->next = cur->next->next;
            
            free(temp);
            temp = NULL;
            dups = 1;
        }
        
        if(dups == 1)
        {
            temp = cur->next;
            
            if(prev == NULL)
                head = temp;
            else
                prev->next = temp;
            
            free(cur);
            cur = NULL;
            
            cur = temp;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}

