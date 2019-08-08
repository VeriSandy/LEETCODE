/*
Triples with Bitwise AND Equal To Zero

Ideas --

1. Have all the combinations, and count which ANDs to 0. O(n3)
2. Something with hash
if we store AND of all two numbers.O(n2)
Hash table will not be more than 65536 elements.

Now in third and with the hash array, see if bitwise AND is zero.
so total O(n2) + O(65536*n)
*/
    
int countTriplets(int* A, int ASize)
{
    if(ASize <= 0) return 0;
    
    int i = 0, j = 0, k = 0, count = 0;
    
    int hash[65536];
    memset(hash, 0, sizeof(hash));
    
    for(i = 0; i < ASize; i++)
    {
        for(j = 0; j < ASize; j++)
        {
            hash[A[i] & A[j]]++;
        }
    }
    
    for(i = 0; i < ASize; i++)
    {
        for(j = 0; j < 65536; j++)
        {
            if(hash[j] && ((j & A[i]) == 0))
                count += hash[j];
        }
    }
    return count;
}
