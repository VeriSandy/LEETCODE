typedef struct node
{
    int data;
    struct node *next;
}NODE;

typedef struct 
{
    NODE *top1;
    NODE *top2;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    
    MinStack *stk = malloc(sizeof(MinStack));
    
    stk->top1 = stk->top2 = NULL;
    
    return stk;
}

void minStackPush(MinStack* obj, int x) 
{
    NODE *n1  = malloc(sizeof(NODE));
    n1->data = x;
    n1->next = obj->top1;
    obj->top1  = n1;
    
    
    NODE *n2  = malloc(sizeof(NODE));
    n2->data = x;
    if(obj->top2 != NULL && x > obj->top2->data)
        n2->data = obj->top2->data;
    n2->next = obj->top2;
    obj->top2  = n2;
    return;
}

void minStackPop(MinStack* obj)
{
    if(obj->top1 == NULL) return ;
    
    NODE *temp = obj->top1;
    obj->top1 = obj->top1->next;
    free(temp);
    temp = NULL;
    
    temp = obj->top2;
    obj->top2 = obj->top2->next;
    free(temp);
    temp = NULL;    
    
    return;
}

int minStackTop(MinStack* obj) {
    
    if(obj->top1 == NULL)
        return INT_MIN;
    
    int data = obj->top1->data;
    
    return data;
}

int minStackGetMin(MinStack* obj) {
        
    if(obj->top2 == NULL)
        return INT_MIN;
    
    int data = obj->top2->data;
    
    return data;
}

void minStackFree(MinStack* obj) {
    
    NODE *temp = NULL;
        
    while(obj->top1)
    {
        temp = obj->top1;
        obj->top1 = obj->top1->next;
        free(temp);
        temp = NULL;
        
        temp = obj->top2;
        obj->top2 = obj->top2->next;
        free(temp);
        temp = NULL;
    }
    
    free(obj);
    obj = NULL;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
