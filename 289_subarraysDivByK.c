/*
1.  
Use two loops, find each SubArray. O(n2)
Look for each subarray start with A[i] upto end, if SUM is divisible by K.

2.
Let there be a subarray (i, j) whose sum is divisible by K
sum(i, j) = sum(0, j) - sum(0, i-1)

Sum can be written as ==> q*K + rem where q. Thus,     
sum(i, j) = (q1*K+rem1) - (q2*K+rem2)
sum(i, j) = (q1 - q2)k + rem1-rem2

To have sum(i,j) divisible by K, rem1-rem2 should be divisible by K((q1 - q2)k is obviously divisible by K). Since both rem1 and rem2 < K so (rem1-rem2) can't be > K. So to have (rem1-rem2) divisible by K, rem1 should be equal to rem2 and that would be make rem1-rem2 == 0 and that would be sum divisible by K. Where
rem1 = Sum of subarray (0, j) % k
rem2 = Sum of subarray (0, i-1) % k 

Take one modulus array of size K to keep the sum(i.e. prefix sum)%K in the array. This will give the count of sub-arrays has same modulus sum%K. Obviously we need only of size K as any sum%K can't be >= K.

From this modulus array, we need to find out how many total sub-arrays for one sum%K i.e. of course Nc2 {((N-1)*N)/2}. Finally sum all the counts. 


Why (tempSum%K+K)%K; ?
Since tempSum%K can be negative so just to make sure we have positive modulus add K to temp%K and again take mod.

Why additional ==> count += mod[0];
mod[0] will also contain all subarrays in from (0 to j), those should be added seperately. 
Also if count is more than >1 for mod[0] that means there are subarrays with mod 0 from (i to j for i > 0) and that count will be covered by ((N-1)*N)/2.

https://www.geeksforgeeks.org/count-sub-arrays-sum-divisible-k/

3. 
Use hasing concept, here similar to "Subarray Sums equal to K"
But in that we are keeping the sums in hash table and checks if sum is K or if sum is > K then check if sum-K already exist.
   
To get the number of subarrays(as in the given problem) are divisible by K, sum should be eqaul to multiple of K i.e K, 2K, 3K and so on.
   
*/
int subarraysDivByK(int *A, int ASize, int K)
{    
    int i= 0, j = 0;
    int count = 0;
    long mod[K];
    long long tempSum = 0;
    memset(mod, 0, sizeof(mod));
    
    while(i < ASize)
    {
        tempSum += A[i];
        count  = (tempSum%K+K)%K;
        mod[count]++;
        i++;
    }
    
    i = 0;
    count = 0;
    while(i < K)
    {
        count +=  ((mod[i]-1)*mod[i])/2;
        i++;
    }
    
    count += mod[0];
    
    return count;
}
