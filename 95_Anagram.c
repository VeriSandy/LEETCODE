
/*
1. Can be used two loops, to match each character.

2. Sorting can be used.

3. Hashing can be used
*/

bool isAnagram(char * s, char * t){

    int l1 = strlen(s), l2 = strlen(t), i = 0;
    
    if(l1 != l2) return false;
    
    int hash1[256], hash2[256];
    
    memset(hash1, 0, sizeof(hash1));
    memset(hash2, 0, sizeof(hash2));
    
    while(i < l1)
    {
        hash1[s[i]]++;
        hash2[t[i]]++;
        i++;
    }
    
    i = 0;
    while(i < 256)
    {
        if(hash1[i] != hash2[i]) return false;
        i++;
    }
    
    return true;
}

