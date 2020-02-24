/*
Have each word indexed.

For each letter in pattern it should have a corresponding word in str.

If letter is same in pattern that should have same word in str. Pattern letter can be pushed to hash - 
If the letter is existing in hash it should have same word as it is for stored index.
If not push to hash.

And each different letter should have a different word.
*/

bool wordPattern(char *pattern, char *str)
{
    
    int  hash[26] = {0};
    int i = 0, j = 0, l = 0, max = 0, count = 0;
    l = strlen(str);
    
    
    int l1 = strlen(pattern);
    if(!l1 || !l) return false;
     
    char *tempSTR = malloc(l+1);
    strcpy(tempSTR, str);
    tempSTR[l] = '\0';
    
    char *token = strtok(str, " ");
    l = strlen(token);
    max = l;
    count++;
    //printf("%s %d %d\n", token, l, max);
    
    while((token = strtok(NULL, " ")))
    {
        l = strlen(token);
        if(l > max)
            max = l;
        //printf("%s %d %d\n", token, l, max);
        count++;
    }    
    

    char **s = malloc(sizeof(char *)*count);
    count = 0;
    s[count] = malloc(max +1);
    memset(s[count], 0, max+1);
    
    token = strtok(tempSTR, " ");
    strcpy(s[count], token);
    //printf("%s %d\n", s[count], count);
    count++;
    
    while((token = strtok(NULL, " ")))
    {
        s[count] = malloc(max +1);
        memset(s[count], 0, max+1);
        strcpy(s[count], token);
        //printf("%s %d\n", s[count], count);
        count++;
    }
    //printf("count %d\n", count);
    
    
    //check if for same letter in pattern has same word or not.
    i = 0;
    l = strlen(pattern);
    
    if(count != l) return false;
    
    while(i < l)
    {
        //printf("%c %s\n", pattern[i], s[i]);
        if(hash[pattern[i]-'a'])
        {
            //printf("%s %s\n", s[i], s[hash[pattern[i]-'a'] - 1]);
            if(strcmp(s[i], s[hash[pattern[i]-'a'] -1]))
                return false;
        }
        else
        {
            hash[pattern[i]-'a'] = i+1;//just to avoid 0 value against 0th index.
        }
        i++;
    }
    
    //check if each pattern points to different string before returning true.
    i = 0;
    while(i < 26)
    {
        if(hash[i])
        {
            j = i+1;
            while(j < 26)
            {
                if(hash[j])
                {
                    //printf("%d %d %s %s\n", i, j, s[hash[i] - 1], s[hash[j] - 1]);
                    if(!strcmp(s[hash[i] - 1], s[hash[j] - 1]))
                        return false;
                }
                j++;
            }
        }
        i++;
    }
    
    return true;
}


