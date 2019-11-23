/*
Ideas -- 

1. Make all the combinations of given words and search for each combination.

2. Start traversing one by one character in given string.
See if any match you see of substrings in given string. 

To Match all the strings in words, use one visited array.
If vis[i] is 0 for corrspoding words[i] and then there is match. This has to be tried for all strings in words.

*/

int Match(char **words, char *temp, int *vis, int wordsSize)
{
    int i = 0;
    while(i < wordsSize)
    {
        if(!vis[i] && !strcmp(temp, words[i]))
        {
            vis[i] = 1;
            return 1;
        }
        i++;
    }
    return 0;
}

int* findSubstring(char *s, char **words, int wordsSize, int *returnSize)
{
    if(wordsSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    
    int i = 0;
    int SingleWordLength = strlen(words[0]);
    int strLen = strlen(s);
    
    int totalLength = SingleWordLength*wordsSize;
    
    if(strLen == 0 || strLen < totalLength)
    {
        *returnSize = 0;
        return NULL;
    }
    
    char *temp = malloc(SingleWordLength+1);
    memset(temp, 0, SingleWordLength+1);
    int *vis = malloc(sizeof(int)*wordsSize);
    memset(vis, 0, sizeof(int)*wordsSize);
    
    int j = 0, k = 0, l = 0;
    
    //max possible output array.
    int *output = malloc(sizeof(int)*(strLen - totalLength +1));
    //printf("%d\n", strLen - totalLength +1);
    
    if(SingleWordLength == 0)
    {
        *returnSize = strLen - totalLength +1;
        while(i < strLen - totalLength +1)
        {
            output[i] = i;
            i++;
        }
        return output;
    }
    
    /*
    //check if all letters are same of given string
    int allLettersSame = 1;
    
    j = 1;
    while(j < strLen)
    {
        if(s[j] != s[j-1])
        {
            allLettersSame = 0;
            break;
        }
        j++;
    }
    */
    
    while(i < (strLen - totalLength + 1))
    {
        l = i;
        strncpy(temp, &s[i], SingleWordLength);
        
        j = 0;
        while(Match(words, temp, vis, wordsSize))
        {
            //printf("matched %s\n", temp);
            i = i+SingleWordLength;
            memset(temp, 0, SingleWordLength+1);
            strncpy(temp, &s[i], SingleWordLength);
            j++;
        }
        
        memset(temp, 0, SingleWordLength+1);
        memset(vis, 0, sizeof(int)*wordsSize);
        
        if(j == wordsSize)
        {
            //printf("matched at %d\n", i - totalLength);
            output[k++] = i - totalLength;
        }
        
        //if(allLettersSame == 1)
        {
            i = l;
            i++;   
        }
        /*
        else
        {
        //we cant use this as think 
        about the cases
        "aaaaaaaa"
        ["aa","aa","aa"]
        
        or 
        "ababaab"
        ["ab","ba","ba"]
        
            if(j == 0)
            {
                i++;
            }
            else
                 i = l + SingleWordLength;
        }
        */
        //printf("i = %d\n", i);
    }
    
    *returnSize = k;
    return output;
}
