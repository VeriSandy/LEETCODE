/*
mapping should be same for each character in s with correspoding char in t.

Since no charset is given assume worst.

two character shouldnt have same mapping
*/

bool isIsomorphic(char *s, char *t)
{
    int hash[257] = {0};
    
    int i = 0, j, l = strlen(s), temp1, temp2 ;
    
    while(i < l)
    {
        temp1 = s[i];
        temp2 = t[i];
        
        if(hash[temp1])
        {
            //printf("%c %c\n", s[i],(hash[s[i]-'a']-1)+'a');
            if(temp2 != hash[temp1]-1) return false;
        }
        else
            hash[temp1] = temp2+1;
        i++;
    }
    
    i = 0;
    while(i < 257)
    {
        if(hash[i])
        {
            j = i+1;
            while(j < 257)
            {
                if(hash[j])
                {
                    if(hash[i] == hash[j])
                        return false;
                }
                j++;
            }
        }
        i++;
    }
    
    return true;
}
