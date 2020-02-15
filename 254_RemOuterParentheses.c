/*
Use stack.

Exploit the fact the string is valid.

if first time you see '(' do not push.

If '(' push to stack. Keep count of these.
else if ')'
    Keep reducing the count, and push these till count > 0
    Once you hit the count 0 that means next ')' is the outer one. 
    Then copy all parentheses(form 0 to last) from stack to output array.
*/

char * removeOuterParentheses(char *S)
{
    int l = strlen(S);
    char stk[l+1];
    int i = 0, j = -1, k = 0, first = 0, count = 0, counter = 0;
    
    char *out = malloc(l+1);
    
    while(i < l)
    {
        if(S[i] == '(')
        {
            if(first)
            {
                stk[++j] = S[i];
                count++;
            }
            else
                first = 1;
            //printf("%d %d\n", count, j);
        }
        else
        {
            if(count > 0)
            {
                stk[++j] = S[i];
                count--;
                //printf("==>%d %d\n", count, j);
            }
            else
            {
                counter = 0;
                while(counter <= j)
                {
                    out[k] = stk[counter];
                    k++;
                    counter++;
                }
                
                first = 0;
                j = -1;
            }
        }
        i++;
    }
    
    out[k] = '\0';
    //printf("%s\n", out);
    return out;
}


