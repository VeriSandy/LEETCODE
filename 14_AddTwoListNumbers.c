/*

You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    if(l1 == NULL) return l2;
    
    if(l2 == NULL) return l1;
    
    int c = 0, temp = 0;
    struct ListNode *p = NULL, *temp1 = l1, *prev = NULL;
    
    while(l1 && l2)
    {
        temp = l1->val + l2->val +c;
        l1->val = temp%10;
        c = temp/10;
        
        p = l2;
        l2 = l2->next;
        free(p);
        p = NULL;
        
        prev = l1;
        l1 = l1->next;
    }
    
    if(l2)
    {
        prev->next = l2;
        l1 = l2;
    }
    
    while(l1)
    {
        temp = l1->val +c;
        l1->val = temp%10;
        c = temp/10;
        prev = l1;
        l1 = l1->next;
    }
    
    if(c)
    {
        struct ListNode *list = malloc(sizeof(struct ListNode));
        list->next = NULL;
        list->val = c;
        prev->next = list;
    }
    
    return temp1;
}

