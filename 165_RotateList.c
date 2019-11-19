/*
Ideas -- 
1. Every time you pluck one node from end and put it in front.
2. How about reverse list, have an end pointer, everytime you pluck one node from front and plug it in end. And finally reverse it.
*/

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode *cur = NULL, *prev = NULL;   
    while(head)
    {
        cur = head->next;
        head->next = prev;
        prev = head;
        head = cur;
    }
    head = prev;
    return head;
}


struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if(head == NULL || head->next == NULL) return head;
    struct ListNode *cur,*last = NULL;
    
    cur  = reverseList(head);
    head = cur;
    int i = 0, len = 0;
    
    while(cur && cur->next)
    {
        cur = cur->next;
        len++;
    }
    len++;
    last = cur;
    k = k%len; 
    
    while(i < k)
    {
        cur = head;
        head = head->next;
        cur->next = NULL;
        last->next = cur;
        last = last->next;
        i++;
    }
    
    cur = reverseList(head);
    head = cur;
    
    return head;
}
