int lengthOfLastWord(char * s)
{
    int l = strlen(s);
    
    if(l == 0) return 0;
    
    l--;
    while(l >= 0 && s[l] == ' ')
        l--;
    
    if(l == -1) return 0;
    
    int i = 0;
    //printf("%c\n", s[l]);
    while(l >=0 && s[l] != ' ')
    {
        i++;
        l--;
    }
    
    return i;
}
