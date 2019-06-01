/*
The count-and-say sequence is the sequence of integers with the first five terms as following:
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
Note: Each term of the sequence of integers will be represented as a string.

IDEA -- 
For ith term read the (i-1)th term

Loop for that term.
Count same digits if any and enter them in array. 
*/

char * countAndSay(int n)
{
    char *s = malloc(5000);
    char *temp = malloc(5000);
    memset(s, 0x00, 5000);
    memset(temp, 0x00, 5000);
    
    s[0] = '1';
    
    if(n == 1) return s;

    int i = 1, j = 0, k = 0, l = 0;
    int count = 1;
    
    while(i < n)
    {
        memset(temp, 0x00, 5000);
        strcpy(temp, s);
        memset(s, 0x00, 5000);        
        j = 1;
        k = 0;
        l = 0;
        count = 1;
        while(temp[j])
        {
            if(temp[k] == temp[j])
                count++;
            else
            {
                s[l++] = count + '0';
                s[l++] = temp[k];
                k = j;
                count = 1;
            }
            j++;
        }
        s[l++] = count + '0';
        s[l++] = temp[k];                  
        i++;
    }
    return s;
}
