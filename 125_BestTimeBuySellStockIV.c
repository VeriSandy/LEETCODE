/*
REQ: Best Time to Buy and Sell Stock and you may complete at most k transactions.
If p transaction is done from 0 to i, then remaining k-p should be done in i+1 to n.

This shuold be calculated for each i(strictly for 0 to i - 2(k-p)) then find the max of those.
Simply cant be done in one pass.

Need something like DP.
Let profit[t][i] represent max profit using at most t transactions up to day i --

profit[t][i] = max
                {
                    1. profit[t][i-1], 
                    2. max(price[i] – price[j] + profit[t-1][j]))  0 <= j <= i-1 
                }
                
to understand, assume t = 1, 2
*/

int Max(int a, int b)
{
    return a>b?a:b;
}

int maxProfitLower(int* prices, int pricesSize)
{
    int i = 0, max = 0; 
    for(i = 1; i < pricesSize; i++)
        max += Max(0, prices[i] - prices[i-1]);   
    return max;
}

//Complexity(kn)
int maxProfit(int k, int* prices, int pricesSize)
{
    if(pricesSize <= 1) return 0;
    
    //For k more than this, we can only maximum do this
    if (k >= pricesSize/2) 
        return maxProfitLower(prices, pricesSize);
    
    int i = 0;
    
    int profit[k+1][pricesSize];
    memset(profit, 0, sizeof(profit));
    
    int prvMax = 0;
    //for pricesSize = 0, everyting will be zero.
    //if k = 0, everyting will be zero
    
    int  j = 1, m = 0;
    for(i = 1; i <= k; i++)
    {
        prvMax = INT_MIN;
        for(j = 1; j < pricesSize; j++)
        {
            // /*optimized version
            //max(prices[i] – prices[j] + profit[t-1][j])) can be rerwritten
            // ===> prices[i] + max(profit[t-1][j] – prices[j])
            // ===>
            // price[i]
            // + max(profit[t-1][i-1] – prices[i-1], profit[t-1][j] – prices[j]) //for j = 0 to i-2;
            //   ==> 
            //  prices[i] + max(profit[t-1][i-1] – prices[i-1], prvMax);
            // */
            prvMax = Max(profit[i-1][j-1] - prices[j-1], prvMax);
            profit[i][j] = Max(profit[i][j-1], prvMax + prices[j]);
        }
    }
    return profit[k][pricesSize-1];
}

/*
//Complexity O(kn2)
int maxProfit(int k, int* prices, int pricesSize)
{
    if(pricesSize <= 1) return 0;
    
    //just to avoid extra loop
    if(k > pricesSize)
        k = pricesSize/2;
    
    int i = 0;

    int profit[k+1][pricesSize];
    memset(profit, 0, sizeof(profit));

    int prvMax = 0;
    
    //for pricesSize = 0, everyting will be zero.
    //if k = 0, everyting will be zero
    int  j = 1, m = 0;;
    for(i = 1; i <= k; i++)
    {
        for(j = 1; j < pricesSize; j++)
        {
            prvMax = 0;
            for(m = 0; m < j; m++)
            {
                prvMax = Max(prvMax, prices[j] -  prices[m] +  profit[i-1][m]);
            }
            profit[i][j] = Max(profit[i][j-1], prvMax);
        }
    }
    return profit[k][pricesSize-1];
}*/
