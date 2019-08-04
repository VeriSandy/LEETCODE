
//Best Time to Buy and Sell Stock
//find out right greatest element for each.

int maxProfit(int* prices, int pricesSize)
{
    if(pricesSize <= 1) return 0;
    
    int i  = pricesSize -3;
    int rightMax = prices[pricesSize -1];
    int max = rightMax - prices[pricesSize -2];
    
    while(i >= 0)
    {
        rightMax = rightMax > prices[i+1]?rightMax:prices[i+1];
        
        if(rightMax - prices[i] > max)
            max = rightMax - prices[i];
        
        i--;
    }
    
    if(max < 0)
        return 0;
    
    return max;
}
