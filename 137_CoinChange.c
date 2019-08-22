/*
//Need to try with each combination, use recursion. If it is exceeding time limit, use DP.

reursion - 
for amount V.
if V = 0 then min required 0
if V > 0 = min(1+ minCoins(V-coin[i])
                    where 0 <= i < n
                    and coin[i] <= V
                    
For DP.
Use bottom up approach
*/

int min(int a, int b)
{
    return a>b?b:a;    
}

int coinChange(int* coins, int coinsSize, int amount)
{   
    if(amount == 0) return 0;
    if(amount < 0 || coinsSize == 0) return -1;
    
    int dp[amount+1];
    int i = 0, j = 0;
    dp[i] = 0;
    
    for(i = 1; i <= amount; i++)
    {
        dp[i] = INT_MAX;
        for(j = 0; j < coinsSize; j++)
        {
            if(i >= coins[j])
            {
                int temp = dp[i-coins[j]];   
                if(temp == INT_MAX)//in case of INT_MAX, just continue;
                    continue;
                else
                    dp[i] = min(dp[i], 1+temp); 
            }
        }
    }
    return (dp[amount] == INT_MAX)?-1:dp[amount];
}
=================================================
/*
Recursion Approach
int coinChange(int* coins, int coinsSize, int amount)
{   
    if(amount == 0) return 0;
    
    if(amount < 0 || coinsSize == 0) return -1;
    
    int i = 0;
    int Min = INT_MAX;
    
    for(i = 0; i < coinsSize; i++)
    {
        int temp = coinChange(coins, coinsSize, amount-coins[i]);   
        if(temp == -1)
            continue;
        else
            Min = min(Min, 1+temp);   
    }
    return (Min == INT_MAX)?-1:Min;
}
*/

