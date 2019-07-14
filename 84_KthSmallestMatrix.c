/*
Kth Smallest Element in a Sorted Matrix
Given a n x n matrix where each of the rows and columns are sorted in ascending order, 
find the kth smallest element in the matrix.

IDEA --
1. One way of doing it, is have all the elements copied to one more array and then sort it.
2. Build a min heap and then find the kth element
*/

typedef struct
{
    int val, r, c;
}HEAP;


 void Swap(HEAP *a, HEAP *b)
 {
     HEAP temp = *a;
     *a = *b;
     *b = temp;
     return;
 }

void minHeapify(HEAP *h, int i, int n)
{
    int l = 2*i+1, r = 2*i +2;
    int smallest = i;
    
    if(l < n && h[l].val < h[smallest].val)
        smallest = l;
       
    if(r < n && h[r].val < h[smallest].val)
        smallest = r; 
    
    if(i != smallest)
    {
        Swap(&h[i], &h[smallest]);
        minHeapify(h, smallest, n);
    }
    return;
}

void buildHeap(HEAP *h, int n)
{
    int i= (n-1)/2;
    
    while(i >= 0)
    {
        minHeapify(h, i, n);
        i--;
    }
    
    return;
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k)
{
    if(matrixSize == 0 || *matrixColSize == 0 || 
       k <= 0 || k > matrixSize*(*matrixColSize))
        return INT_MIN;
    
    HEAP h[*matrixColSize];
    memset(h, 0, sizeof(int)*(*matrixColSize));
    
    int i = 0;
    for (i = 0; i < *matrixColSize; i++)
    {
        h[i].val = matrix[0][i];
        h[i].r = 0;
        h[i].c = i;
    }
    
    buildHeap(h, *matrixColSize);
    HEAP temp;
    
    printf("%d\n", h[0].val);
    for(i= 0; i < k; i++)
    {
        temp = h[0];
        
        int val = temp.r < (matrixSize -1)?matrix[temp.r+1][temp.c]:INT_MAX;
        
        h[0].val = val;
        h[0].r += 1;
        
        minHeapify(h, 0, matrixSize);
    }
    
    return temp.val;
}

