bool detectCapitalUse(char * word)
{
    int i = 1, l = strlen(word);
    int FirstFlag = 0, SecFlag = 0, ThirdFlag = 0;
    
    FirstFlag = (65 <= word[0] && word[0] <= 90)?2:1;
    
    while(i < l)
    {
        //printf("%d\n", word[i]);
        if(i == 1)
        {
            SecFlag = (65 <= word[i] && word[i] <= 90)?2:1;
            
            //printf("%d %d\n", FirstFlag ,SecFlag);
            
            if(SecFlag > FirstFlag) return false;
            
            i++;
            
            continue;
        }
        
        ThirdFlag = (65 <= word[i] && word[i] <= 90)?2:1;
        
       //printf("%d %d\n", FirstFlag ,SecFlag);
        
        if(SecFlag != ThirdFlag)
            return false;

        i++;
    }
    
    return true;
}


