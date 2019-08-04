
/*
Best Time to Buy and Sell Stock III --

REQ: Two times only, allowed.

Basic idea, for each i 
    max profit, from 0 to i + max profit, from i to n.
And finally max of this array.

This can be done using two arrays as well as using one array 
*/

int Max(int a, int b)
{
    return a>b?a:b;
}

int maxProfit(int* prices, int pricesSize)
{
    if(pricesSize <= 1) return 0;
    
    int rightProfit[pricesSize], leftProfit[pricesSize], i = 0;
    rightProfit[pricesSize -1] = 0;
    leftProfit[0] = 0;
    
    int max = 0, min = 0;
    
    i = pricesSize -2;
    max = prices[pricesSize -1];
    while(i >= 0)
    {         
        if(max < prices[i])
            max = prices[i];
        
        rightProfit[i] = Max(rightProfit[i+1], max - prices[i]);
        //This can be placed above also and if current element is greater than right max, 
        //so diff will be zero, that is correct but by keeping it here, diff will be negative.
        //But it will not change end result, as we need max profit at right side of i.
        //if(max < prices[i])
        //   max = prices[i];
        
        //printf("rightProfit[i] = %d\n", rightProfit[i]);
        i--;
    }
    
    i = 1;
    min = prices[0]; 
    while(i < pricesSize)
    {         
        if(min > prices[i])
            min = prices[i];
        
        leftProfit[i] = Max(leftProfit[i-1], prices[i] -min);
        //printf("leftProfit[i] = %d\n", leftProfit[i]);
        i++;
        
    }
    
    i = 0;
    max = leftProfit[i] + rightProfit[i];
    i++;
    
    while(i < pricesSize)
    {
        if(max < leftProfit[i] + rightProfit[i])
            max = leftProfit[i] + rightProfit[i];
        
        //printf("max = %d\n", max);
        i++;
    }
    
    return max;
}

==============================================================
//Using one array---
int maxProfit(int* prices, int pricesSize)
{
    if(pricesSize <= 1) return 0;
    
    int Profit[pricesSize],i = 0;
    Profit[pricesSize -1] = 0;
    
    int max = 0, min = 0;
    
    i = pricesSize -2;
    max = prices[pricesSize -1];
    while(i >= 0)
    {         
        if(max < prices[i])
            max = prices[i];
        
        Profit[i] = Max(Profit[i+1], max - prices[i]);
        i--;
    }
    
    i = 1;
    min = prices[0];
    while(i < pricesSize)
    {         
        if(min > prices[i])
            min = prices[i];
        
        Profit[i] = Max(Profit[i-1], Profit[i] + prices[i] -min);
        i++;
        
    }
    return Profit[pricesSize-1];
}
