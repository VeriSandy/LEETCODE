/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//iteration
struct ListNode* reverseList(struct ListNode* head){
    
    if(head == NULL || head->next == NULL) return head;
    
    struct ListNode* cur = head;
    struct ListNode *prev = NULL, *temp = NULL;
    
    while(cur)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    
    return prev;
}

//recursion
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL) return NULL;
    
    struct ListNode* first = head;
    static struct ListNode *rev = NULL;
    
    if(first->next == NULL) 
    {
        rev = first;
        return first;
    }
    
    reverseList(first->next);
    
    first->next->next = first;
    first->next = NULL;
    
    return rev;
}
