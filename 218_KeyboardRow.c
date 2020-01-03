/*
Have one hash map for all 26 letters and allocate number as per their rownumber.
Check each word for all characters, if all characters refers to same number in hash array.
else they can't be formed using one row.
*/

char ** findWords(char ** words, int wordsSize, int* returnSize)
{
    char row1[] = {"qwertyuiop"};
    char row2[] = {"asdfghjkl"};
    char row3[] = {"zxcvbnm"};
    
    int i = 0, j = 0;
    int len = 0, count = 0, first = 0, sec = 0, flag = 0;
    
    
    int hash[26] = {0};
    
    len = strlen(row1);
    j = 0;
    while(j < len)
    {
        hash[row1[j] - 'a'] = 1;
        j++;
    }
    
    len = strlen(row2);
    j = 0;
    while(j < len)
    {
        hash[row2[j] - 'a'] = 2;
        j++;
    }

    len = strlen(row3);
    j = 0;
    while(j < len)
    {
        hash[row3[j] - 'a'] = 3;
        j++;
    }
    
    i = 0;
    while(i < wordsSize)
    {
        len = strlen(words[i]);
        first = words[i][0] < 97?hash[words[i][0]+32 - 'a']:hash[words[i][0] - 'a'];
        j = 1;
        flag = 0;
        while(j < len)
        {
            sec = words[i][j] < 97?hash[words[i][j]+32 - 'a']:hash[words[i][j] - 'a'];
            if(first != sec)
            {   
                flag = 1;
                break;
            }
            j++;
        }
        count += !flag?1:0; 
        i++;
    }
    //printf("%d\n", count);
    
    char **out = malloc(sizeof(char *)*count);
    count = 0;
    i = 0;
    while(i < wordsSize)
    {
        len = strlen(words[i]);
        first = words[i][0] < 97?hash[words[i][0]+32 - 'a']:hash[words[i][0] - 'a'];
        j = 1;
        flag = 0;
        while(j < len)
        {
            sec = words[i][j] < 97?hash[words[i][j]+32 - 'a']:hash[words[i][j] - 'a'];
            if(first != sec)
            {   
                flag = 1;
                break;
            }
            j++;
        }
        if(!flag)
        {
            out[count] = malloc(len+1);
            memset(out[count], 0, len+1);
            strcpy(out[count], words[i]);
            count++;
        }
        i++;
    }
    
    *returnSize = count;
    return out;
}


