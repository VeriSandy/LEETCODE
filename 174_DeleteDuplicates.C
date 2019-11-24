struct ListNode* deleteDuplicates(struct ListNode* head)
{   
    if(head == NULL || head->next == NULL)
        return head;

    struct ListNode *cur = head, *temp = NULL;
    
    while(cur && cur->next)
    {
        if(cur->val == cur->next->val)
        {
            temp = cur->next;
            cur->next = cur->next->next;
            
            free(temp);
            temp = NULL;
        }
        else
            cur = cur->next;
    }
    return head;
}

