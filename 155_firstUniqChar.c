//use hashing here

int firstUniqChar(char * s)
{
    int hash[26] = {0};
    int i= 0;
    
    while(s[i])
    {
        hash[s[i] -'a']++;
        i++;
    }
    
    i = 0;
    while(s[i])
    {
        if(hash[s[i] -'a'] == 1)
            return i;
        i++;
    }
    
    return -1;
}

