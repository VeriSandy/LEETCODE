
/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as 
possible, and interprets them as a numerical value.
The string can contain additional characters after those that form the integral number, which are ignored and have no 
effect on the behavior of this function.
If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists 
because either str is empty or it contains only whitespace characters, no conversion is performed.
If no valid conversion could be performed, a zero value is returned.
Note:
Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.

Input: "words and 987"
Output: 0

Input: "-91283472332"
Output: -2147483648

Input: ""20000000000000000000"
Output: 2147483647

Idea -- Follow all the instructions given in problem

*/
int myAtoi(char * str){
    
    long num = 0;
    int i = 0;
    int sign = 0; //1 for positive sign , 2 for negative sign, 0 for no sign
    int l = strlen(str);
    
    if(l == 0) return 0;
    
    //strip leading spaces if any
    while(str[i++] == ' ');
    i--;
    
    if(i == l) return 0;

    
    if(str[i] == '-')
    {
        sign = 2;
        i++;
    }
    else if(str[i] == '+')
    {
        sign = 1;
        i++;
    }
    
    //check if string is like "abccd " or "+abnasb" or "-adanndas"
    
    if(str[i] - '0' < 0 || str[i] - '0' > 9)
        return 0;
    
    //printf("%d ", i);
    while(i < l && str[i] - '0' >= 0 && str[i] - '0' <= 9)
    {
        num = num*10 + str[i] - '0';
        
        //we just need till INT_MAX, if more bail out from here itself
        //if you go more, might overflow long
        if(num > INT_MAX)
            break;
        i++;
    }
    
    if(sign == 2)
        num = -num;
    
    if(num > 0 && num > INT_MAX)
        return INT_MAX;
    
    if(num < 0 && num < INT_MIN)
        return INT_MIN;
    
    return num;
}
