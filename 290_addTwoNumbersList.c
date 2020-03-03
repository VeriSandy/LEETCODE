
/*
How about use recursion here.
Go till end.We need a carry as well.

Count no of nodes in both lists.
Add recursively, if both nodes exist add both else add only the existing one in the output list.
*/

struct ListNode* addTwoNumbersUtil(struct ListNode* l1, struct ListNode* l2, int *c, int n1, int n2)
{  
    int temp;
    
    //printf("l1->val = %d and l2->val = %d\n", l1->val,  l2->val);
    
    if(l1->next == NULL && l2->next == NULL)
    {
        temp = l1->val + l2->val;
        *c = temp/10;
        l1->val = temp%10;
        n2--;
        n1--;
        return;
    }
    
    if(n1 > n2)
    {
        //printf("Calling l2  [%d] \n",n1);
        n1--;
        addTwoNumbersUtil(l1->next, l2, c, n1, n2);
        temp = l1->val + *c;
    }        
    else
    {
        //printf("Calling l12 [%d %d]\n",n1, n2);
        n1--;
        n2--;
        addTwoNumbersUtil(l1->next, l2->next, c, n1, n2);
        
        temp = l1->val + l2->val + *c;
    }
    
    *c = (temp)/10;
    l1->val = temp%10;
    
    //printf("carry = %d and temp = %d\n", *c,  temp);
    
    return;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    if(l1 == NULL) return l2;
    
    if(l2 == NULL)  return l1;
    
    int c = 0, n1 = 0, n2 = 0;
    
    struct ListNode *node = l1;
    
    while(node)
    {
        node  = node->next;
        n1++;
    }
    
    node = l2;
    while(node)
    {
        node  = node->next;
        n2++;
    }
    
    if(n1 >= n2)
        addTwoNumbersUtil(l1, l2, &c, n1, n2);
    else
        addTwoNumbersUtil(l2, l1, &c, n2, n1);
    
    node = l2;
    if(n1 >= n2) node = l1;
    
    if(!c) return node;
    

    struct ListNode *temp = malloc(sizeof(struct ListNode));
    temp->val = c;
    temp->next = node;
    node = temp;
    
    /*
    while(node)
    {
        printf("%d  ", node->val);
        node  = node->next;
    }
    */
    
    return temp;
}
