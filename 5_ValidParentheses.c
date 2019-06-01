/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true


Solution - Use Stack for this purpose. 
if any open brace, keep pushing in stack. 
If any close brace, pop an item from stack see if it is according to the close brace.

*/


typedef struct stack
{
    char *st;
    int top;
    int size;
}STACK;


STACK *CreateStack(int size)
{
    STACK *s = malloc(sizeof(STACK));
    s->top = -1;
    s->size = 0;
    s->st = malloc(size);
    
    return s;
}

void Push(STACK *s, char c)
{
    s->top++;
    s->st[s->top] = c;
    
    return;
}

char Pop(STACK *s)
{
    char c = s->st[s->top];
    s->top--;
    return c;
}

bool isValid(char * s){

    int l = strlen(s);
    STACK *stk = CreateStack(l);
    
    while(*s)
    {
        switch(*s)
        {
            case '(':
            case '{':
            case '[':
                    Push(stk, *s);
                    break;
            case ')':
                    if(stk->top == -1 || (stk->top > -1 && Pop(stk) != '('))
                        return false;
                    break; 
            case ']':
                    if(stk->top == -1 || (stk->top > -1 && Pop(stk) != '['))
                        return false;
                    break;
            case '}':
                    if(stk->top == -1 || (stk->top > -1 && Pop(stk) != '{'))
                        return false;
                    break;
        }
        s++;
    }
    
    if(stk->top > -1 ) return false;
    
    return true;   
}
