/*
IDEA -- 
Create the string of min length(from given strings array)
See how many characters are matching with each string in strings array
return only min one.
*/

char * longestCommonPrefix(char ** strs, int strsSize){

    if(strsSize == 0) return "";
    
    
    int i = 0;
    int len = strlen(strs[i]);
    int l = 0;
    int j = 0;
    
    for(i = 1; i < strsSize; i++)
    {
        l = strlen(strs[i]);
        if(len > l)
        {
            len = l;
            j = i;
        }
    }
    
    char *str = malloc(len+1);
    strcpy(str, strs[j]);
    str[len] = '\0';
        
    for(i = 0; i<strsSize; i++)
    {
        for(j = 0; j < len; j++)
        {
            if(str[j] != strs[i][j])
                break;
        }
        str[j] = '\0';
        len = j;
    }
    
    return str;
}


