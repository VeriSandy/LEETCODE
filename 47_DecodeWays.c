
//Total ways == Fix one digit 1 * no ofways(length-1) 
//              + fix two digits * noofways(length-2)
    
//Use DP
int numDecodingsUtil(char *s)
{
    int l = strlen(s);    
    if(l == 0) return 1;
        
    int j = 0;
    /*
    int d[l+1];
    for(j = 0; j <= l; j++)
        d[j] = 0;
    
    d[0] = 1;
    d[1] = 1;
    
    */
    
    int first = 1, second = 1;
    int temp = 0;
    
    for(j = 2; j <= l; j++)
    {
        temp = 0;
        
        if(s[j-1] != '0')
            temp = second;
        
        if(s[j-2] == '1' || (s[j-2] == '2' && s[j-1] < '7'))
            temp += first;
        
        first = second;
        second = temp;
    }
    
    //return d[l];
    return second;
}

int numDecodings(char *s){
    int l = strlen(s);
    
    //if it is start with 0 so 0 can't be matched with anything.
    if(l == 0 || (s[0] - '0' == 0)) return 0;
    
    int i = atoi(s);
    
    if(!i) return 0;
    
    return numDecodingsUtil(s);
}
=======================
//using recursion
int numDecodingsUtil(char *s)
{
    int l = strlen(s);
    
    if(s[0] - '0' == 0) return 0;
    
    if(l <= 1) return 1;
    
    int temp = 0;

    if(s[0] != '0')
        temp = numDecodingsUtil(&s[1]);
    
    if(s[0] == '1' || (s[0] == '2' && s[1] < '7'))
        temp += numDecodingsUtil(&s[2]);
    
    return temp;
}

int numDecodings(char *s){
    int l = strlen(s);
    
    //if it is start with 0 so 0 can't be matched with anything.
    if(l == 0 || (s[0] - '0' == 0)) return 0;
    
    int i = atoi(s);
    
    if(!i) return 0;
    
    return numDecodingsUtil(s);
}
