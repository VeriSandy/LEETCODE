/*
This is problem is same as to evaluate the infix expression.

So take two stacks for it. One for numbers and other for operators.

A. Start traversing each char one by one in string.
If it is 
    1. A number: push it onto the int stack.
    2. A left parenthesis: push it onto the operator stack.
    3. A right parenthesis:
        3.1 While top of the operator stack is not a left parenthesis,
            3.1.a Pop the operator from the operator stack.
            3.1.b Pop the number stack twice, getting two operands.
            3.1.c Apply the operator to the operands, in the correct order.
            3.1.d Push the result onto the number stack.
        3.2 Pop the left parenthesis from the operator stack.
        
    4. An operator
        4.1 While the operator stack is not empty, and the top of 
            operator stack has the same or greater precedence as thisOp,
            4.1.a Pop the operator from the operator stack.
            4.1.b Pop the number stack twice, getting two operands.
            4.1.c Apply the operator to the operands, in the correct order.
            4.1.d Push the result onto the number stack.
         2 Push operator onto the operator stack.
         
B. Once string is over, check the operator stack 

1. While the operator stack is not empty,
    1.1 Pop the operator from the operator stack.
    1.2 Pop the number stack twice, getting two operands.
    1.3 Apply the operator to the operands, in the correct order.
    1.4 Push the result onto the number stack.
    
    
2. Finally you will have result at top of number stack.

*/


int precdence(char ch)
{
    if(ch == '*' || ch == '/') return 2;
    else if (ch == '+' || ch == '-') return 1;
    return 0;
}

int calculate(char *s)
{
    int i = 0, j = 0, l = strlen(s);
    long sum = 0, flag = 0, a, b;
    char sign;
    
    long stackInt[l];
    char stackChar[l+1];
    int topInt = -1, topChar = -1;
    
    while(i < l)
    {
        if(s[i] == ' ')
        {
            i++;
        }
        
        else if(s[i] == '(')
        {
            stackChar[++topChar] = '(';
            i++;
        }
        
        else if(s[i] == ')')
        {
            while(topChar != -1 && stackChar[topChar] != '(')
            {
                sign = stackChar[topChar--];
                
                b = stackInt[topInt--];
                a = stackInt[topInt--];
                
                if(sign == '+')
                    stackInt[++topInt] = a+b;
                else if(sign == '-')
                    stackInt[++topInt] = a-b;
                else if(sign == '*')
                    stackInt[++topInt] = a*b;
                else if(sign == '/')
                    stackInt[++topInt] = a/b;
            }
            stackChar[topChar--];
            i++;
        }
        
        else if(s[i] == '+'  || s[i] == '-' || s[i] == '*'  || s[i] == '/')
        {
            while(topChar != -1 && precdence(s[i]) <= precdence(stackChar[topChar]))
            {
                sign = stackChar[topChar--];
                
                b = stackInt[topInt--];
                a = stackInt[topInt--];
                
                if(sign == '+')
                    stackInt[++topInt] = a+b;
                else if(sign == '-')
                    stackInt[++topInt] = a-b;
                else if(sign == '*')
                    stackInt[++topInt] = a*b;
                else if(sign == '/')
                    stackInt[++topInt] = a/b;
            }
            stackChar[++topChar] = s[i];
            //printf("%c %c,topChar = %d,topInt = %d\n",s[i],stackChar[topChar],topChar,topInt);
            i++;
        }
        else//number
        {
            a = 0;
            while(i < l && s[i] >= '0' && s[i] <= '9')
            {
                a = a*10 + (s[i]  - '0');
                i++;
            }
            stackInt[++topInt] = a;
            //printf("%d %d, topChar = %d, topInt = %d\n", a, stackInt[topInt], topChar, topInt);
        }
    }
    
    //printf("%d %d\n", topChar, topInt);
    
    while(topChar != -1)
    {
        sign = stackChar[topChar--];

        b = stackInt[topInt--];
        a = stackInt[topInt--];

        if(sign == '+')
            stackInt[++topInt] = a+b;
        else if(sign == '-')
            stackInt[++topInt] = a-b;
        else if(sign == '*')
            stackInt[++topInt] = a*b;
        else if(sign == '/')
            stackInt[++topInt] = a/b;
    }
    
    return stackInt[topInt];
}


