/*
Ideas -- 
1. Use tow loops, outer loop for starting character
inner loop to frame the string starting from that character till end.
And check if new string framed is palindrome of greater length than the previous one.

2. Another way recursion
   if s is palindrome then this can give you max palidrome length.
   else
        max(of strings from s+1 to end and s to end -1)
   
3. Another way use DP.
Use a 2-D table to mark if string of length k, starting from i and ending i+k is palindrome or not. ==> table[i][i+k] = true
On this basis we can find out if any string of length k+2, starting from i -1 and ending i + k + 1 is palindrome or not. 
By just checking if char at position i-1 and i+k +1 same and if table[i][i+k] is true so this
string would be palindrome.
*/

char *longestPalindrome(char * s)
{
    int n = strlen(s);
    if(n == 0) return "";
    
    int i = 0, j = 0, k = 0;
    int start = 0;
    int maxlength = 1;
    int table[n][n];
    memset(table, 0, sizeof(table));
    
    //string of length one is always palindrome.  
    for(i = 0; i < n ; i++)
        table[i][i] = 1;
    
    //string of length two
    for(i = 0; i < n - 1; i++)
    {
        if(s[i] == s[i+1])
        {
            table[i][i+1] = 1;
            start = i;
            maxlength = 2;
        }
    }

    //for other sizes strings
    for(k = 3; k <= n; k++)
    {
        for(i = 0; i < n - k + 1; i++)//assume 3 length string i max should go to n - 3
        {
            j = i + k - 1;
            
            //for case of length 4 string
            //if first and last char are same
            //and table[i+1][j-1] is already palindrome
            if(table[i+1][j-1] && s[i] == s[j])
            {
                table[i][j] = 1;
                if(k > maxlength)
                {
                    start = i;
                    maxlength = k;
                }
            }
        }
    }
    
    char *string = malloc(sizeof(char) * (maxlength + 1));
    memset(string, 0x00, sizeof(char) * (maxlength + 1));
    j = 0;
    for(i = start; i < start + maxlength; i++)
    {
        string[j] = s[i];
        //printf("%c", string[j]);
        j++;
    }
    
    //printf(" %s\n",string);

    return string;
}
