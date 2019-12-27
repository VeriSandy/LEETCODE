/*
It can be solved mathematically.

return the number, who is trusted by all i.e. count of trusts is N-1 and doesn't trust anyone i.e. count is 0.

else return -1

*/

int findJudge(int N, int** trust, int trustSize, int* trustColSize)
{
    int a[N+1];
    int b[N+1];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    
    int i = 0;
    
    for(; i < trustSize; i++)
    {
        a[trust[i][0]]++;
        b[trust[i][1]]++;
    }
    
    for(i = 1; i <= N; i++)
    {
        if(a[i] == 0 && b[i] == N-1)
            return i;
    }
    return -1;
}


