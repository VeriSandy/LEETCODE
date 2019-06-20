

/*
if len(T) > len(S) return NULL;
or if(len(T) == 0 || len(S) == 0 ) return NULL

KEEP T in hash table

Start Traversing S.

Keep increamenting count if any character is in HASH[T] and count is less than HASH[T].
once you hit count == len(T).

Try and see if you can reuce the window size. 
By removing extra needed character  or unnecessary character from cur window. 

*/


char * minWindow(char * s, char * t){
    
    int min_window = INT_MAX;
    int cur_window = 0;
    
    int lt = strlen(t);
    int ls = strlen(s);
    
    if(lt > ls || ls == 0 || lt == 0) return "";
    
    int i = 0;
    
    int start = 0;
    int st = -1;

    int count = 0;
    
    int hash_T[256];
    memset(hash_T, 0x00, sizeof(hash_T));
    
    int hash_S[256];
    memset(hash_S, 0x00, sizeof(hash_S));
    
    for(i = 0; i < lt; i++)
        hash_T[t[i]]++;
    
    i = 0;
    
    while(i < ls)
    {
        hash_S[s[i]]++;
        
        if(hash_T[s[i]] && hash_S[s[i]] <= hash_T[s[i]])
            count++;
        
        if(count == lt)//matched
        {
            //see if you can reduce the window size
            while(hash_S[s[start]] > hash_T[s[start]] || hash_T[s[start]] == 0)
            {
                if(hash_S[s[start]] > hash_T[s[start]])
                    hash_S[s[start]]--;
                
                start++;
            }
            
            cur_window = i - start + 1;
            
            if(min_window > cur_window){             
                min_window  = cur_window;
                st = start;
            }
            
        }       
        i++;
    }
 
    if(st == -1)
        return "";
    
    char *str = malloc(min_window +1);
    memset(str, 0x00, min_window +1);
    
    strncat(str, &s[st], min_window);
    
    return str;
}
