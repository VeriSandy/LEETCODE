/*
Three passes --> 1 day pass, 7 day pass, month pass
costs[] = {}

Days of the array --> days[]

min cost
min of three.
either buy day pass for every day. 
or buy week passess to travel
or month passes.
or combination of these.

Have dp[i] ==> MinCost from ith day to end.

dp[i] = min(costs[0]+dp[i+1], costs[1]+dp[i+7], costs[2]+dp[i+30])

*/

int MIN(int a, int b)
{
    return a<b?a:b;
}

int mincostTicketsUtl(int *days, int daysSize, int* costs, int costsSize, 
                      int day, int weekStart,int MonthStart)
{
    if(day >= daysSize) return 0;
    
    int dayPassCost, weekPassCost, monthPassCost;
    
    //lets take day pass today.
    dayPassCost = costs[0] + mincostTicketsUtl(days,daysSize,costs,costsSize,day+1,
                                               weekStart,MonthStart);
    
    //lets take week day pass
    if(!weekStart)
    weekPassCost = costs[1] + mincostTicketsUtl(days,daysSize,costs,costsSize,day+1,                                            days[day],MonthStart);
    else
    weekPassCost =    
        (days[day] <= weekStart+6)?
        mincostTicketsUtl(days,daysSize,costs,costsSize,day+1,weekStart,MonthStart):
        costs[1] + mincostTicketsUtl(days,daysSize,costs,costsSize,day+1,days[day],MonthStart);
    
    
    //lets take month pass
    if(!MonthStart)
    monthPassCost = costs[2]+mincostTicketsUtl(days,daysSize,costs,costsSize,day+1,                                            weekStart,days[day]);
    else
    monthPassCost = 
        (days[day] <= MonthStart+29)?
                mincostTicketsUtl(days,daysSize,costs,costsSize,day+1,weekStart,MonthStart):
        costs[2] + mincostTicketsUtl(days,daysSize,costs,costsSize,day+1, 
                                     weekStart,days[day]);
    
    return MIN(dayPassCost, MIN(weekPassCost, monthPassCost));
}

int mincostTickets(int* days, int daysSize, int* costs, int costsSize)
{
    //return mincostTicketsUtl(days, daysSize, costs, costsSize, 0, 0, 0);
    int dp[366];
    memset(dp, 0, sizeof(dp));
    int i = daysSize - 1, j = 0;
    int dayPassCost, weekPassCost, monthPassCost;
    
    for(j=365; j >= 0 && i >= 0; j--)
    {
        if(j != days[i])
        {
            if(j != 365)
                dp[j] = dp[j+1];
            continue;
        }
        dayPassCost = (j+1)<=365?dp[j+1]:0;
        dayPassCost += costs[0];

        weekPassCost = (j+7)<=365?dp[j+7]:0;
        weekPassCost += costs[1];
        
        monthPassCost = (j+30)<=365?dp[j+30]:0;
        monthPassCost += costs[2];
        
        //printf("%d %d %d\n", dayPassCost, weekPassCost, monthPassCost);
        
        dp[j] = MIN(dayPassCost, MIN(weekPassCost, monthPassCost));
        
        //printf("%d\n", dp[j]);
        i--;
    }
    
    return dp[j+1];
}
