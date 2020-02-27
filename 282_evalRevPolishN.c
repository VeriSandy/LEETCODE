/*
use stack for it.

1) Create a stack to store values.

2) Scan the given expression and do following for every scanned element.
    (a) If the element is a number, push it into the stack
    (b) If the element is a operator, pop operands for the operator from stack. Evaluate the   operator and push the result back to the stack
    
3) When the expression is ended, the number in the stack is the final answer

*/

int evalRPN(char **tokens, int tokensSize)
{
    long stack[tokensSize];
    int top = -1,  i = 0;
    int ii, jj;
    
    while(i < tokensSize)
    {
        if(strlen(tokens[i]) == 1 && (tokens[i][0] == '+' || tokens[i][0] == '-'
          || tokens[i][0] == '/' || tokens[i][0] == '*'))
        {
            jj = stack[top--];
            //printf("%d\n", top);
            ii = stack[top--];
            
            if(tokens[i][0] == '+')
                stack[++top] = ((long)ii)+jj;
            else if(tokens[i][0] == '/')
                stack[++top] = ((long)ii)/jj;
            else if(tokens[i][0] == '*')
                stack[++top] = ((long)ii)*jj;
            else if(tokens[i][0] == '-')
                stack[++top] = ((long)ii)-jj;
        }
        else
            stack[++top] = atoi(tokens[i]);
        
        i++;
    }
    
    return stack[top];
}


