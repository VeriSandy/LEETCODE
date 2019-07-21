/*
Find Median from Data Stream

With respect to "C" Language
1. Sort the array every time. And find median.
Here every time, need to change the array size. => o(nlogn) + resizing the array.

2. And if linked list, then eveytime, it is going to take O(n) to find median and O(n) to insert the element if sorted order is maintained.
so overall O(n2) for n elements.
And if array is used then that need to be resizable also need to shift the elements.

3. AVL Tree, can be used. Insertion will take O(logn) time and fiend median will take O(1) time.
Problem would be with repeatition. 

4. Two heaps can also be maintained. Max heap for lower half and Min heap for other half. Keep one element diff at a time, else you have to shift element one to another.
*/

typedef struct
{
    int *minHeap;
    int *maxHeap;
    int cap;
    int minHeapSize;
    int maxHeapSize;
}MedianFinder;

/** initialize your data structure here. */
MedianFinder* medianFinderCreate()
{
    MedianFinder *obj = malloc(sizeof(MedianFinder));
    obj->cap = 100;
    obj->minHeapSize = 0;
    obj->maxHeapSize = 0;
    obj->minHeap = malloc(sizeof(int)*obj->cap);
    obj->maxHeap = malloc(sizeof(int)*obj->cap);
    return obj;
}

void resize(MedianFinder *obj) 
{
    if(obj == NULL) return;
    obj->cap *= 2;
    obj->minHeap = realloc(obj->minHeap, obj->cap*sizeof(int));
    obj->maxHeap = realloc(obj->maxHeap, obj->cap*sizeof(int));
    
    return;
}

void swap(int *a, int *b)
{
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
    return;
}

void InsertMinHeap(int *a, int i, int num)
{
    a[i] = num;
    
    int p = (i-1)/2;

    while(p >= 0 && a[i] < a[p])
    {
        swap(&a[i], &a[p]);
        i = p;
        p = (i-1)/2;
    }
    return;
}

void InsertMaxHeap(int *a, int i, int num)
{
    a[i] = num;
    int p = (i-1)/2;

    while(p >= 0 && a[i] > a[p])
    {
        swap(&a[i], &a[p]);
        i = p;
        p = (i-1)/2;
    }
    return;
    
}

void MinHeapify(int *num, int index, int size)
{
    int smallest = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;

    if (left_child < size && num[smallest] > num[left_child]) {
        smallest = left_child;
    }

    if (right_child < size && num[smallest] > num[right_child]) {
        smallest = right_child;
    }

    if (smallest != index) {
        swap(&num[smallest], &num[index]);
        MinHeapify(num, smallest, size);
    }
    return;
}

void MaxHeapify(int *num, int index, int size) 
{
    int largest = index;

    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;

    if (left_child < size && num[largest] < num[left_child]) {
        largest = left_child;
    }

    if (right_child < size && num[largest] < num[right_child]) {
        largest = right_child;
    }

    if (largest != index) {
        swap(&num[largest], &num[index]);
        MaxHeapify(num, largest, size);
    }
    return;
}

void medianFinderAddNum(MedianFinder* obj, int num)
{
    if(obj == NULL) return;
    
    int tmp;
    
    if (obj->maxHeapSize == obj->cap || obj->minHeapSize == obj->cap)
        resize(obj);

    //If min heap size is equal or more, insert in max heap.
    if (obj->minHeapSize >= obj->maxHeapSize) 
    {
        //In case new element is more than obj->minHeap[0]
        //so swap element with root of min heap and insert in max heap
        if (obj->minHeapSize != 0 && obj->minHeap[0] < num) 
        {
            tmp = obj->minHeap[0];
            obj->minHeap[0] = num;
            num = tmp;
            MinHeapify(obj->minHeap, 0, obj->minHeapSize);
        }
        InsertMaxHeap(obj->maxHeap, obj->maxHeapSize, num);
        obj->maxHeapSize++;
    }
    else 
    {
        //In case new element is less than obj->maxHeap[0]
        //so swap element with root of max heap and insert in min heap
        if (obj->maxHeapSize != 0 && obj->maxHeap[0] > num) 
        {
            tmp = obj->maxHeap[0];
            obj->maxHeap[0] = num;
            num = tmp;
            MaxHeapify(obj->maxHeap, 0, obj->maxHeapSize);
        }
        InsertMinHeap(obj->minHeap, obj->minHeapSize, num);
        obj->minHeapSize++;
    }
    return;
}

double medianFinderFindMedian(MedianFinder* obj)
{
    if(obj == NULL) return 0;

    //If size is equal.
    if (obj->minHeapSize == obj->maxHeapSize)    
        return ((obj->minHeap[0] + obj->maxHeap[0])/2.0);
    else 
        return (double)obj->maxHeap[0];
}

void medianFinderFree(MedianFinder* obj) 
{
    if(obj == NULL) return;
    free(obj->minHeap);
    obj->minHeap = NULL;
    free(obj->maxHeap);
    obj->maxHeap = NULL;
    free(obj);
    obj = NULL;
    return;
}
