/*
Use Sliding Window - 

To directly count the subarrays with exactly all 3 different chars is hard but to find the count of subarrays with at most 3 chars is easy. 

So the idea is to find the count of subarrays with at most 3 different chars, let it be C(K), and the count of subarrays with at most 2 different chars, let it be C(K – 1). And finally take their difference, C(K) – C(K – 1) which is the required answer.

Count of subarrays with at most 3 different chars can be easily calculated through the sliding window technique. 

The idea is to keep expanding the right boundary of the window till the count of distinct chars in the window is less than or equal to 3 AND when the count of distinct chars inside the window becomes more than 3, start shrinking the window from the left till the count becomes less than or equal to 3. 

Also for every expansion, keep counting the subarrays as right–left+1 where right and left are the boundaries of the current window.

More about this -- 
https://leetcode.com/problems/subarrays-with-k-different-integers/

*/

int Util(char* s, int K)
{    
    int hash[3] = {0};
    int size = 0, right = 0, left = 0, count = 0, res = 0;
    int l = strlen(s);
    
    while(right < l)
    {
        if(!hash[s[right] - 'a'])
            size++;

        hash[s[right] - 'a']++;
        
        while(size > K)
        {
            if(hash[s[left] - 'a'])
            {
                hash[s[left] - 'a']--;
                if(!hash[s[left] - 'a'])
                    size--;
            }
            left++;
        }
        
        count += right -left +1;
        right++;
    }
    return count;
}


int numberOfSubstrings(char *s)
{
    int K = 3;
    return Util(s, K) - Util(s, K-1);
}
