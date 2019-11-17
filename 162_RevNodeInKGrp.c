struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    if(head == NULL || head->next == NULL) return head;
    
    struct ListNode *prev = head, *cur = head->next, *temp1 = NULL;
    struct ListNode *temp = head, *start = NULL, *end = NULL;
    struct ListNode *tempStart = NULL;
    
    int first = 0;
    
    int i = 0;
    while(temp)
    {
        start = temp;
        end = temp;
        i = 0;
        while(i < k && temp)
        {
            end = temp;
            temp = temp->next;
            i++;
        }
        
        //Either we are at end or we have k <= 1
        //So we simply can bail out from here.
        if(start == end || i < k)
        {
            //printf("get out\n");
            break;
        }
        
        cur = end->next;  
        //Rev Here.
        temp = start->next;
        tempStart = start;
        start->next = NULL;
        while(start != end)
        {          
            temp1 = temp->next;
            temp->next = start;
            start = temp;
            temp = temp1;
        }
        tempStart->next = cur;
        //Mark End of this reversal as prev.
        
        if(!first)
        {
            head = start;
            first = 1;
        }
        else
            prev->next = start;
        
        
        prev = tempStart;
        temp = prev->next;
    }
    
    return head;
}
