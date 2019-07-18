void reverseString(char* s, int sSize)
{
    if(sSize == 0) return;
    
    int i = 0, l = sSize/2;
    char temp;
    
    while(i < l)
    {
        temp = s[i];
        s[i] = s[sSize-1-i];
        s[sSize-1-i] = temp;
        i++;
    }
    
    return;
}

