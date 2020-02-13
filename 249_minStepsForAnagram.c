/*
    Use hashing to see what all characters are there in one string.
    
    Keep adding in hash table with chars for one string and same time keep reducing
    in hash table the chars of second string.
    
    return the count/2(as we need to change only one char for two differences) of non zero         entries in hash table
*/

int minSteps(char * s, char * t)
{
    int l = strlen(s);
    int count = 0,i = 0;
    int hash[26] = {0};
    
    while(i < l)
    {
        hash[s[i] - 'a']++;
        hash[t[i] - 'a']--;
        i++;
    }
    
    i = 0;
    while(i < 26)
    {
        //printf("%d\n", hash[i]);
        count += hash[i] < 0?-hash[i]:hash[i];
        i++;
    }
    
    return count/2;
}


