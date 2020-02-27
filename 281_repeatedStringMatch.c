/*
Normal strstr kind a problem. BUT need to take care of corner cases that's all.

If len(A) > len(B) ==> either B is already substr of A or string "AA" will contain B otherwise return -1.

Else ==> HERE COMES THE MONSTER

To expedite things, check if both the strings has same set of characters if not BAIL OUT(HURRAY!!!), USE HASH.

TO compare B with A, first make len(tempStr) at least equal to len(B) then start comparing after each strcat.

Take extra size of temporary string 3*B+1 so no SEGV.

THAT IS ALL!!!!
*/

int repeatedStringMatch(char *A, char *B)
{
    int lA = strlen(A), lB = strlen(B);
    
    char *tempStr = NULL;
    
    int hash[26] = {0}, i = 0;
    
    if(lA > lB)
    {        
        if(strstr(A, B))
            return 1;
        
        tempStr = malloc(lA*2+1);
        memset(tempStr, 0, lA*2+1);
        strcat(tempStr, A);
        strcat(tempStr, A);
        
        if(strstr(tempStr, B))
            return 2;
        
        return -1;
    }
    
    
    while(i < lA)
    {
        hash[A[i] - 'a']++;
        i++;
    }
    
    i = 0;
    while(i < lB)
    {
        if(!hash[B[i] - 'a']) return -1;
        i++;
    }
    
    tempStr = malloc(lB*3+1);
    memset(tempStr, 0, lB*3+1);
    
    int count = 0, l = 0;
    
    while(l+lA <= lB)
    {
        strcat(tempStr, A);
        count++;
        l += lA;
    }
    
    //printf("%d\n", count);
    
    while(l <= 3*lB && l+lA <= 3*lB)
    {
        if(strstr(tempStr, B))
            return count;
        
        strcat(tempStr, A);
        count++;
        
        l += lA;
    }
    
    return -1;
}
