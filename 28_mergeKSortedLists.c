

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
Ideas - 
1. Start with first keep merging with second and assign this back to first list. Continue till we left with only one list(merged with all). O(n2)

2. Use Divide and Conquer Approach

If there are K lists of N size.

Pair up K lists and merge each pair in linear time using O(1) space. After first cycle, K/2 lists are left each of size 2*N. After second cycle, K/4 lists are left each of size 4*N and so on. We repeat the procedure until we have only one list left.

O(NKlogK)

*/

struct ListNode* mergeTwoList(struct ListNode* list1, struct ListNode* list2)
{
    if(list1 == NULL) return list2;
    
    if(list2 == NULL) return list1;
    
    if(list1->val < list2->val)
    {
        list1->next = mergeTwoList(list1->next, list2); 
        return list1;
    }
    list2->next = mergeTwoList(list1, list2->next); 
    return list2;
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
 
    if(listsSize == 0) return NULL;
    
    if(listsSize == 1) return lists[0];
    
    int i = 0, j = 0;
    int last = listsSize-1;
    
    while(last) //==> logK times
    {
        i = 0;
        j = last;
        
        while(i < j)//NK every time
        {
            lists[i] = mergeTwoList(lists[i], lists[j]);
            
            i++;
            j--;
            
            if(i >= j)
                last = j;
        }
    }
    return lists[0];
}
