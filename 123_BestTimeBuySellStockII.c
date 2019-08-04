/*
Find out local minima, local maxima
And right side max.

Or Keep adding profit if next element is greater than current, 
finally it will result in max profit.
*/

int maxProfit(int* prices, int pricesSize)
{
    if(pricesSize <= 1) return 0;
    
    int i  = 0, max = 0;
    
    while(i < pricesSize -1)
    {
        if(prices[i] < prices[i+1])
            max += prices[i+1] - prices[i];
        
        i++;
    }   
    return max;
}

//=========================================================

int maxProfit(int* prices, int pricesSize)
{
    if(pricesSize <= 1) return 0;
    int i  = 0, start = 0, end = 0, max = 0;
    
    while(i < pricesSize -1)
    {
        while(i < pricesSize -1 && prices[i] >= prices[i+1])
            i++;
        start = i;
        
        if(i == pricesSize -1)
            break;
        
        while(i < pricesSize -1 && prices[i] < prices[i+1])
            i++;
        
        end = i;
        max += prices[end] - prices[start];
    }
    return max;
}
