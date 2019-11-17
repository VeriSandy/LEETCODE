'''
We can traverse each element using for loop.

If you see a element arr[i], we are only interested to know if we have seen element arr[i] - difference.

If we have seen that means longest seq of arr[i] is longest seq of (arr[i] - difference) + 1.

ELse it would be 1.

So The longest seq for arr[i] ==>  (arr[i] -difference) + 1.

This can be achieved using hash table as well. Store count of elements arr[i].
'''

class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        dp = {}
        ans = 1;
        for i in arr:
            count = 1
            if(i-difference in dp):
                count += dp[i-difference]
            dp[i] = count
            ans = max(ans, dp[i]);
        return ans
    
==================================================================================    
/*
Longest Subsequence 
1. Using Recursion

If L(i) ==> If i is end of array then Longest Arithmetic Subsequence at pos i

L(i) = 1 + L(maxL(j)) if(a[i] -a[j] == difference) Where  0 <= j < i
or 
L(i) = 1 if no such j exist
*/

int longestSubsequence(int* arr, int arrSize, int difference)
{
    int i = 0, j = 0;
    
    if(arrSize == 1) return 1;

    int Max = 0, count = 0, temp = 0;

    int dp[arrSize];
    dp[0] = 1;

    for(i = 1; i < arrSize; i++)
    {
        dp[i] = 1;
        for(j = 0; j < i; j++)
        {
            if(arr[i] - arr[j] == difference)
                dp[i] = dp[j] +1;
        }

        if(Max < dp[i])
            Max = dp[i];
    }
    return Max;
}
