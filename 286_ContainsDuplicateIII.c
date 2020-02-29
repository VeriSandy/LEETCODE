/*
1. Use two loops
in first loops traverse the whole array
in second loop check atmost k elements if there is any element satfies "absolute difference between nums[i] and nums[j] is at most t"

O(kn)

2. Use sliding window concept and hashing.
Use window of size K +1.

Every time, this window need to be searched for any element satfies "absolute difference between nums[i] and nums[j] is at most t" ==> O(k)

Overall O(kn)

3. Use sliding window concept and hashing.
Use window of size K +1.

Every time, this window need to be searched for any element which satfies "absolute difference between nums[i] and nums[j] is at most t"

Everytime you insert an element in the window, use a mechanism to keep the min at starting.
So by just looking at first element it is certain that condition satfies, rather than searching whole window.

Like Ordered map ==> Overall O(nlogk).

Min Heap ==> Insert an element ==> O(logk)
Min Heap ==> delete an element ==> for deletion element index need to be found out and that can take k comparisons. ==> O(k) 
So overall O(nk)
*/

/*
//min heap
void InsertHeap(int *arr, int i)
{
    int smallest = arr[i];
    int par = i/2, temp = 0;
    
    while(i && arr[par] > arr[i])
    {
        temp = arr[par];
        arr[par] = arr[i];
        arr[i] = temp;
        
        i = par;
        par = i/2;
    }
    return;
}

void DeleteHeap(int *arr, int data, int n)
{
    
}
*/

long ABS(long a)
{
    return a>0?a:-a;
}

bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t)
{
    if(t < 0 || numsSize <= 1) return false;
    
    int i = 0, j = 0, count = 0;
    int *arr = malloc(sizeof(int)*(k+1));
    long temp = 0;
    
    arr[0] = nums[i++];
    
    while(i < numsSize && i <= k)
    {
        j = 0;
        while(j < i)
        {
            temp = ABS(((long)arr[j])-((long)nums[i]));
            if(temp <= t)  return true;
            j++;
        }
        arr[i] = nums[i];
        i++;
    }
    
    while(i < numsSize)
    {
        j = 0;
        arr[count%(k+1)] = INT_MAX;
        while(j < (k+1))
        {
            temp = ABS(((long)arr[j])-((long)nums[i]));
            if(temp <= t)  return true;
            j++;
        }
        
        arr[count%(k+1)] = nums[i];
        i++;
        count++;
    }
    return false;
}
