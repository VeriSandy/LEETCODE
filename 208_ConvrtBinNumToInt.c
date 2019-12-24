/*
1. Either solve it by recursion

2. Or by iteration, need to count no of nodes here first to get the correct value multiplier i.e. pow(2, i).
*/

int getDecimalValueUtil(struct ListNode* head, int *i)
{
    if(head->next == NULL)
        return pow(2, *i)*head->val;
    
    int ret = getDecimalValueUtil(head->next, i);
    (*i)++;
    return pow(2, *i)*head->val + ret;
}

int getDecimalValue(struct ListNode* head)
{
    int i = 0;
    return getDecimalValueUtil(head, &i);
}


