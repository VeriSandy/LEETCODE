/*
Find All Anagrams in a String --

Ideas ---
1.  Check at index if anagram exist. 
    At every index, need to verify the anagram. O(length of s * length of p)

2.  Above method can be improved usinh hash table.
    Keep p in hash table(size 26).
    Traverse s once, see if any letter of s belong to p.
    Visit only till len(s) - len(p) +1.
    If any angaram, possible in last that can be of len(p) length.
    But need to check if anagram exist or not at that index.

    Also, while traversing s, keep adding next elements in hash table, keep removing initial 
    elements from hash table.
*/

int* findAnagrams(char * s, char * p, int* returnSize)
{
    *returnSize = 0;
    int *a = NULL;
    int lp = strlen(p), ls = strlen(s), i = 0, j = 0, k = 0, flag = 0;
    if(lp == 0 || (ls < lp)) return a;
    
    int l = ls - lp, count = 0;
    int hash1[26];
    memset(hash1, 0, sizeof(hash1));
    
    int hash2[26];
    memset(hash2, 0, sizeof(hash2));
    
    a = malloc(sizeof(int)*(l+1));
    
    while(i < lp)
    {
        hash1[p[i] - 'a']++;
        hash2[s[i] - 'a']++;
        i++;
    }

    while(j <= l)
    {
        if(hash1[s[j] - 'a'])
        {
            k = 0;
            flag = 0;
            while(k < 26)
            {
                if(hash1[k] != hash2[k])
                {
                    flag = 1;
                    break;
                }
                k++;
            }
            if(flag == 0)
            {
                //printf("%d ", j);
                a[count] = j;
                count++;
            }
        }
        
        
        hash2[s[j] - 'a']--;
        if(j < l)
            hash2[s[i] - 'a']++;
        j++;
        i++;
    }
    
    //printf("\n%d\n", count);
    *returnSize = count;
    return a;
}

