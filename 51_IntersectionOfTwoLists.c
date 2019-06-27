/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    if(headA == NULL || headB == NULL) return NULL;
    
    
    int d1 = 0, d2 = 0;
    
    struct ListNode *temp1 = headA, *temp2 = headB;
    
    while(temp1)
    {
        temp1 = temp1->next;
        d1++;
    }
    
    temp2 = headB;
    
    while(temp2)
    {
        temp2 = temp2->next;
        d2++;
    }
    
    int d = d1- d2;
    int i = 0;
    
    temp1 = headA;
    temp2 = headB;
    
    
    if(d > 0)
    {
        while(i < d)
        {
            temp1 = temp1->next;
            i++;
        }
    }
    
    else{
        d = -d;
        i = 0;
        while(i < d)
        {
            temp2 = temp2->next;
            i++;
        }
    }
    
    while(temp1 && temp2)
    {
        if(temp1 == temp2)
            return temp1;
        temp2 = temp2->next;
        temp1 = temp1->next;
    }
    
    return NULL;
}
