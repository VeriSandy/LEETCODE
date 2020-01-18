/*
    Even number of piles arranged ==> n
    piles[i] > 0
    
    End with most stones.
    If Alex wins return true.
    
    Alex starts first. So Alex need to highest stones to win. 
    
    Alex, can pickup fom beg or end. Next Lee has tp pickup.
    
    If Alex 
        1. picks up from beg.
            a. Lee can pickup next from beg 
            b. or from end.
        2. picks from end.
            a. Lee can pickup from beg.
            b. Or from end.
    
    Or in another words.
    If Alex 
        1. picks up from beg. Next he can pick up
            a. from (beg+2, end) 
            b. or (beg+1, end -1)  
        2. picks from end. Next he can pick up
            a. from (beg+1, end -1) 
            b. or (beg, end -2)
    
*/
int MAX(int a, int b)
{
    return a>b?a:b;
}

//recursion
int stoneGameUtil(int* piles, int beg, int end)
{
    if(beg > end)
        return 0;
    
    
    int Alex  = MAX(piles[beg] + 
                    MAX(stoneGameUtil(piles,beg+2,end),stoneGameUtil(piles,beg+1, end-1))
                    ,
                    piles[end] + 
                    MAX(stoneGameUtil(piles,beg,end-2),stoneGameUtil(piles,beg+1,end-1)));
    return Alex;
}

bool stoneGame(int* piles, int pilesSize)
{
    int i = 0;
    long sum = 0;
    
    while(i < pilesSize)
    {
        sum += piles[i];
        i++;
    }
    
    int Alex =  0;//stoneGameUtil(piles, 0, pilesSize-1);
    
    int dp[pilesSize][pilesSize];
    int gap = 0, j = 0;
    int x, y, z;
    
    //We are trying to find out the share of Alex for length of array of size gap.
    // i.e, array of length 1, 2, 3, 4 and so on
    
    for(gap = 0; gap < pilesSize; gap++)
    {
        for(i = 0, j = gap; j < pilesSize; j++, i++)
        {
            x = (i+2 <= j)?dp[i+2][j]:0;
            y = (i+1 <= j-1)?dp[i+1][j-1]:0;
            z = (i <= j-2)?dp[i][j-2]:0;
            
            dp[i][j] = MAX(piles[i] + MAX(x, y)
                           ,
                           piles[j] + MAX(y,z));
        }
    }
    
    Alex = dp[0][pilesSize-1];
    
    return Alex > sum - Alex;
}
