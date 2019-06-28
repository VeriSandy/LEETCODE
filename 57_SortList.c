/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
IDEA -- Use merge sort concept
1. Divide in two parts 
2. sort them recursivley 
3. and finally merge them
*/

//sorted merge
struct ListNode* Merge(struct ListNode* a, struct ListNode* b)
{
    if(a == NULL) return b;
    
    if(b == NULL) return a;
    
    if(a->val < b->val)
    {
        a->next = Merge(a->next, b);
        return a;
    }
    
    b->next = Merge(a, b->next);
    return b;
}

void Split(struct ListNode* head, struct ListNode **a, struct ListNode **b)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* prev = NULL;
    
    while(fast)
    {
        fast = fast->next;
        if(fast)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    *a = head;
    *b = slow;
     prev->next = NULL;
}

struct ListNode* sortList(struct ListNode* head){

    if(head == NULL || head->next == NULL) return head;
    
    //divide in two parts
    //then sort them recursivley and finally merge them
    
    struct ListNode* a = NULL;
    struct ListNode* b = NULL;
    
    Split(head, &a, &b);

    a = sortList(a);
    b = sortList(b);

    return Merge(a, b);
}


