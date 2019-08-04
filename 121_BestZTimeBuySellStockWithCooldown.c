/*
Best Time to Buy and Sell Stock with Cooldown--

IDEA -- 
buy[i]: Max profit till index i and it is ending with a buy.
sell[i]: Max profit till index i and it is ending with a sell.


buy[i]: To make a decision whether to buy at i, we either take a rest, by just using the old decision at i - 1, or sell at/before i - 2, then buy at i, We cannot sell at i - 1, then buy at i, because of cooldown.

sell[i]: To make a decision whether to sell at i, we either take a rest, by just using the old decision at i - 1, or buy at/before i - 1, then sell at i.

*/

int Max(int a, int b)
{
    return a>b?a:b;
}

int maxProfit(int* prices, int pricesSize)
{
    if(pricesSize <= 1) return 0;
    int i = 0;
    /*
    int sell[pricesSize];
    int buy[pricesSize];
    buy[0] =  -prices[0];
    sell[0] =  0;
    for(i = 1; i < pricesSize; i++)
    {
        buy[i] = Max(buy[i-1], i >= 2?sell[i-2] - prices[i]: 0 - prices[i] );
        sell[i] = Max(sell[i-1], buy[i-1]+prices[i]);
    }

    return sell[pricesSize-1];
    */
    
    //optimized version - 
    //represent buy/sell[i], buy/sell[i - 1], buy/sell[i-2]

    int b0 = 0, b1 = 0, b2 = 0;
    int s0 = 0, s1 = 0, s2 = 0;
    
    b1 = -prices[0];
    
    for(i = 1; i < pricesSize; i++)
    {
        b0 = Max(b1, s2 - prices[i]);
        s0 = Max(s1, b1 + prices[i]);
        
        s2 = s1;
        b1 = b0;
        s1 = s0;
    }
    
    return s0;
}

