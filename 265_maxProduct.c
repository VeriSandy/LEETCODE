/*
1.  Take each word and find out another word which is not angaram of it.
    calculate the max product of lengths.
    
    Oveall O(n2)*26, also need to consider strlen operation.
    
2.  Represent Each letter a bit. It can accommodate in byte(hoping byte of size of 4 bytes)
    Here also we need to convert each word as bits.
    
    But if bitwise '&' of two integers is zero. So no common elements.
    That way we do need to check each bit here. O(n2).
    
*/


int maxProduct(char **word, int wordsSize)
{
    if(wordsSize <= 1) return 0;
    
    int BitForms[wordsSize],i = 0, j = 0, k = 0,l1=0,l2=0,max = 0, temp = 1, flag = 1;
    memset(BitForms, 0, sizeof(BitForms));
    
    while(i < wordsSize)
    {
        j = 0, l1 = strlen(word[i]);
        k = 0;
        while(j < l1)
        {
            temp = word[i][j] - 'a';
            k |= 1 << temp;
            
            //printf("%d %d\n", temp, k);
            j++;
        }
        BitForms[i] = k;
        //printf("%d \n", BitForms[i]);
        i++;
    }
    
    i = 0;
    while(i < wordsSize -1)
    {
        j = i+1;
        l1 = strlen(word[i]);
        while(j < wordsSize)
        {   
            k = 0, l2 = strlen(word[j]);
            flag = 1;
            
            if(!(BitForms[i] & BitForms[j])) //no common letters.
            {
                temp = l1*l2;
                if(max < temp)
                    max = l1*l2;
            }
            j++;
        }
        i++;
    }
    
    return max;
}

================================================================================================
int maxProduct(char **word, int wordsSize)
{
    if(wordsSize <= 1) return 0;
    
    int hash[26] = {0}, i = 0, j = 0, k = 0,l1=0,l2=0,max = 0, temp = 1, flag = 1;
    
    while(i < wordsSize -1)
    {
        j = 0, l1 = strlen(word[i]);
        memset(hash, 0, sizeof(hash));
        while(j < l1)
        {
            hash[word[i][j] - 'a']++;
            j++;
        }
        
        j = i+1;
        while(j < wordsSize)
        {
            k = 0, l2 = strlen(word[j]);
            flag = 1;
            while(k < l2)
            {
                if(hash[word[j][k]-'a'])
                {
                    flag = 0;
                    break;
                }
                k++;
            }
            if(flag)
            {
                temp = l1*l2;
                if(max < temp)
                    max = l1*l2;
            }
            j++;
        }
        i++;
    }
    
    return max;
}


