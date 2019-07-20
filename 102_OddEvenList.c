
struct ListNode* oddEvenList(struct ListNode* head)
{
    if(head == NULL || head->next == NULL) return head;
    
    struct ListNode *OddHead = head, *OddRear = head;
    head = head->next;
    OddRear->next = NULL;
    
    struct ListNode *EvenHead = head, *EvenRear = head;
    head = head->next;
    EvenRear->next = NULL;

    int flag = 1;
    
    while(head)
    {
        if(flag)
        {
            OddRear->next = head;
            head = head->next;
            OddRear = OddRear->next;
            OddRear->next = NULL;
        } 
        else
        {
            EvenRear->next = head;
            head = head->next;
            EvenRear = EvenRear->next;
            EvenRear->next = NULL;    
        }
        flag = !flag;
    }
    
    OddRear->next = EvenHead;
    
    return OddHead;
}
