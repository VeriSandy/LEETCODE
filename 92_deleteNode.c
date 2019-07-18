void deleteNode(struct ListNode* node) {
    
    struct ListNode* temp = node->next;
    
    node->val = temp->val;
    
    node->next = node->next->next; 
    
    free(temp);
    temp = NULL;
    
    return;
}
