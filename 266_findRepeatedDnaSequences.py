'''
Create temporary hashmap for strings.
Push first substr of 10 chars into temporary hashmap.

Start traversing given string from 10th char. See if it does exist in temporary hashmap.
Then add it output list if it is not there in output.
'''
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        
        l = len(s)
        if(l <= 10):
            return []
        
        tempDict = {}
        resDict = {}
        res = []
        
        k1 = 0
        SubStr = s[0:10]
        tempDict[SubStr] = k1
        k1 += 1
        
        i = 10
        j = 0
        k2 = 0
        while(i < l):
            SubStr = s[j+1:j+11]
            
            if SubStr in tempDict:
                if SubStr not in resDict:
                    res.append(SubStr)
                    resDict[SubStr] = k2
                    k2 += 1
                    print(SubStr)
            else:
                tempDict[SubStr] = k1
                k1 += 1
                
            i += 1
            j += 1
            
        return res
        
   ======================================================================================================
   C Solution but time limit exceeded
   ======================================================================================================
 char **findRepeatedDnaSequences(char *s, int* returnSize)
{
    char buff[10+1];
    int l = strlen(s), i = 0, j = 0, flag = 0, count = 0;
    int hash[26] = {0};
    
    if(l <= 10)
    {
        *returnSize = 0;
        return "";
    }
    
    while(i <= l-11)
    {
        j = 0;
        memset(buff, 0, 11);
        
        while(j < 10)
        {
            buff[j] = s[i+j];
            j++;
        }
        //printf("%s\n", buff);
        
        j = i+1;
        flag = 0;
        
        if(strstr(&s[j], buff) != NULL)
            flag = 1;
        
        if(flag)
        {            
            count++;
            //printf("%d %s\n", count, buff);
            
            
            
        }
        i++;
    }
    
    char **out = malloc(sizeof(char *)*count);
    
    i = 0;
    count = 0;
    while(i <= l-11)
    {
        j = 0;
        memset(buff, 0, 11);
        
        while(j < 10)
        {
            buff[j] = s[i+j];
            j++;
        }
        
        j = i+1;
        flag = 0;
        
        if(strstr(&s[j], buff) != NULL)
            flag = 1;
        
        if(flag)
        {
            j = 0;
            flag = 0;
            while(j < count)
            {
                if(strstr(out[j], buff) != NULL)
                {
                    flag = 1;
                    break;
                }
                j++;
            }
            if(!flag)
            {
                out[count] = malloc(11);            
                strncpy(out[count], buff,10);
                out[count][10] = '\0';
                //printf("%d %s\n", count, out[count]);
                count++;
            }
        }
        i++;
    }
    
    *returnSize = count;
    return out;
}

   
