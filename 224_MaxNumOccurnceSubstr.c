/*
Find such Substring, by using slide window concept(take the minSize as window size) and count the occurance in whole string.

Used minSize as window size, as this will give max count of maximum number of ocurrences.
*/

int FindOccurrances(char *s, char *text)
{
    char *p = s;
    int count = 0;
    
    p = strstr(s, text);
    
    while(p)
    {
        count++;
        s = p+1;
        p = strstr(s, text);
    }
    
    return count;
}


int maxFreq(char * s, int maxLetters, int minSize, int maxSize)
{
    int i = 0, j = 0, l = strlen(s);
    
    if(l < minSize) return 0;
    
    int HASH[26] = {0};
    int HashCount = 0, MaxOccurrances = 0, Occurrances = 0;
    char buff[maxSize+1];
    
    while(i < minSize)
    {
        if(HASH[s[i] - 'a'] == 0)
            HashCount++;
        HASH[s[i] - 'a']++;
        i++;
    }
    
    if(HashCount <= maxLetters)
    {
        memset(buff, 0, maxSize+1);
        strncpy(buff, s, minSize);
        MaxOccurrances = FindOccurrances(s, buff);
        //printf("%s %d\n", buff, MaxOccurrances);
    }
    
    while(i < l)
    {
        HASH[s[i- minSize] - 'a']--;//remove one character from left side of window
        
        if(HASH[s[i- minSize] -'a'] == 0)
            HashCount--;
        
        if(HASH[s[i] - 'a'] == 0)
            HashCount++;
        
        HASH[s[i] -'a']++;//add one character to hash table from right side of window
        
        if(HashCount <= maxLetters)
        {
            memset(buff, 0, maxSize+1);
            strncpy(buff, &s[i- minSize+1], minSize);
            
            //If this string has been checked before, there is no point to check again.
            //if where > 0 i.e. buff is present before this location 'i- minSize+1'
            //So it has already been checked.
            int where = &s[i- minSize+1] - strstr(s, buff);
            
            if(where <= 0)
            {
                Occurrances = FindOccurrances(&s[i- minSize+1], buff);        
                //printf("%s %d\n", buff, Occurrances);

                if(Occurrances > MaxOccurrances)
                    MaxOccurrances = Occurrances;
            }
        }
        i++;
    }
    return MaxOccurrances;
}
