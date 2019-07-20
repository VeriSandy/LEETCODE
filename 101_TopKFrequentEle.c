/*

Top K Frequent Elements

1. Using two loops(not allowed)

2. Sort the array(not allowed)

3. Position based approach, cant be used 
    As dont know about the elements range
   
4. Hashing also wouldnt work, need to sort hash table based on frequency. O(nlogn)

5. How about building min heap of k items(based on number of occurances), for occurances hash table can be used.

For top frequent k elements, scan hash
If element > root of heap, then replace root and heapify
else ignore
At last, this heap will have top k frequent elements

*/

typedef struct
{
    int ele;
    int fre;
}Item;

void MinHeapify(Item *Heap, int index, int n)
{
    int smallest = index;
    int l = 2*index + 1;
    int r = 2*index + 2;
    
    if(l < n && Heap[l].fre < Heap[smallest].fre)
        smallest = l;
    
    if(r < n && Heap[r].fre < Heap[smallest].fre)
        smallest = r;   
    
    if(smallest != index)
    {
        Item temp = Heap[index];
        Heap[index] = Heap[smallest];
        Heap[smallest] = temp;
        MinHeapify(Heap, smallest, n);
    }
    return;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){

    int i = 0, j = 0, max = nums[0], min = nums[0];
    
    for(i = 1; i < numsSize; i++)
    {
        if(max < nums[i])
            max = nums[i];
        
        if(min > nums[i])
            min = nums[i];
    }
    
    Item *hash = malloc(sizeof(Item)*(max - min +1));
    memset(hash, 0, sizeof(Item)*(max - min +1));
    
    for(i = 0; i < max - min +1; i++)
        hash[i].ele = i+min;
    
    for(i = 0; i < numsSize; i++)
        hash[nums[i] - min].fre++;
    
    Item Heap[k];
    for(i = 0; i < max - min +1 && j < k; i++)
    {
        if(hash[i].fre)
        {
            Heap[j] = hash[i];
            j++;
        }
    } 

    //Build Min heap
    j = (k-1)/2;
    while(j >= 0)
    {
        MinHeapify(Heap, j, k);
        j--;        
    }
    
    for(; i < max - min +1; i++)
    {
        if(hash[i].fre && Heap[0].fre < hash[i].fre)
        {
            Heap[0] = hash[i];
            MinHeapify(Heap, 0, k);
        }
    }
    
    //Extract elements
    int l = k;
    for(i = 0; i < l -1; i++)
    {
        Item temp = Heap[0];
        Heap[0] = Heap[l-1];
        Heap[l-1] = temp;
        l--;
        MinHeapify(Heap, 0, l);
    }
    
    
    int *a = malloc(sizeof(int) *k);
    for(i = 0; i < k; i++)
        a[i] = Heap[i].ele;
    
    free(hash);
    hash = NULL;
    
    *returnSize = k;
    return a;
}

