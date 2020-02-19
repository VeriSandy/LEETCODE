/*
Use Stack
if '(' push in stack
else
    if(stack is not empty and top of stack is '(')
        pop
    else
        push

finally return the number of elements in stack.
*/
int minAddToMakeValid(char * S)
{
    int l = strlen(S);
    
    char stack[l+1];
    int top = -1, i = 0;
    
    while(i < l)
    {
        if(S[i] == '(')
            stack[++top] = S[i];
        else
        {
            if(top != -1 && stack[top] == '(')
                top--;
            else
                stack[++top] = S[i];
        }
        //printf("%c %d\n", S[i], top);
        i++;
    }
    
    return top+1;
}
