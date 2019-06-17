/*
Use other approach here similar to two same size sorted array.

if(size of both arrays are > 2)
if m1 === median of first array, m2 == of another 
if(m1 < m2) then median wil lie a1[m1/2 -1] to a2[m2/2]
and if(m1 > m2) then median wil lie a2[m2/2 -1] to a1[m1/2]

O(log m + log n)


Base cases:
The smaller array has only one element
Case 0: N = 0, M = 2
Case 1: N = 1, M = 1.
Case 2: N = 1, M is odd
Case 3: N = 1, M is even
The smaller array has only two elements
Case 4: N = 2, M = 2
Case 5: N = 2, M is odd
Case 6: N = 2, M is even

Case 0: There are no elements in first array, return median of second array. If second array is also empty, return -1.

Case 1: There is only one element in both arrays, so output the average of A[0] and B[0].

Case 2: N = 1, M is odd
Let B[5] = {5, 10, 12, 15, 20}
First find the middle element of B[], which is 12 for above array. There are following 4 sub-cases.
…2.1 If A[0] is smaller than 10, the median is average of 10 and 12.
…2.2 If A[0] lies between 10 and 12, the median is average of A[0] and 12.
…2.3 If A[0] lies between 12 and 15, the median is average of 12 and A[0].
…2.4 If A[0] is greater than 15, the median is average of 12 and 15.
In all the sub-cases, we find that 12 is fixed. So, we need to find the median of B[ M / 2 – 1 ], B[ M / 2 + 1], A[ 0 ] and take its average with B[ M / 2 ].

Case 3: N = 1, M is even
Let B[4] = {5, 10, 12, 15}
First find the middle items in B[], which are 10 and 12 in above example. There are following 3 sub-cases.
…3.1 If A[0] is smaller than 10, the median is 10.
…3.2 If A[0] lies between 10 and 12, the median is A[0].
…3.3 If A[0] is greater than 12, the median is 12.
So, in this case, find the median of three elements B[ M / 2 – 1 ], B[ M / 2] and A[ 0 ].

Case 4: N = 2, M = 2
There are four elements in total. So we find the median of 4 elements.

Case 5: N = 2, M is odd
Let B[5] = {5, 10, 12, 15, 20}
The median is given by median of following three elements: B[M/2], max(A[0], B[M/2 – 1]), min(A[1], B[M/2 + 1]).

Case 6: N = 2, M is even
Let B[4] = {5, 10, 12, 15}
The median is given by median of following four elements: B[M/2], B[M/2 – 1], max(A[0], B[M/2 – 2]), min(A[1], B[M/2 + 1])

Remaining Cases:
Once we have handled the above base cases, following is the remaining process.
1) Find the middle item of A[] and middle item of B[].
…..1.1) If the middle item of A[] is greater than middle item of B[], ignore the last half of A[], let length of ignored part is idx. Also, cut down B[] by idx from the start.
…..1.2) else, ignore the first half of A[], let length of ignored part is idx. Also, cut down B[] by idx from the last.

*/

double median(int *a, int n)
{   
    if(n == 0) return -1;//if size is zero
    
    if(n == 1) return a[0];
    
    if(n%2 == 0)
        return (a[n/2] + a[n/2 -1])/2.0;
    
    return a[n/2];
}

double Med3(int a, int b , int c)
{   
    int temp[3] = {0};
        
    temp[0] = a;
    temp[1] = b;
    temp[2] = c;
    
    int i = 0, j = 0;
    int num = 0;
    
    for(i = 1; i < 3; i++)
    {   
        num = temp[i]; 
        for(j = i -1 ; j >= 0 && temp[j] > num; j--)
                temp[j+1] = temp[j];
        temp[j+1] = num;
    }
    return temp[1];
}


double Med4(int a, int b , int c, int d)
{
    int temp[4] = {0};
   
    temp[0] = a;
    temp[1] = b;
    temp[2] = c;
    temp[3] = d;

    int i = 0, j = 0;
    int num = 0;

    for(i = 1; i < 4; i++)
    {
        num = temp[i];
        for(j = i -1 ; j >= 0 && temp[j] > num; j--)
                temp[j+1] = temp[j];
        temp[j+1] = num;
    }
    return (temp[1] + temp[2])/2.0;
}

double Med2(int a, int b)
{
    return (a+b)/2.0;
}

int max(int a, int b)
{
    return a>b?a:b;
}

int min(int a, int b)
{
    return a>b?b:a;
}

double getMedian(int *a, int n, int *b, int m)
{
    if(n == 0) return median(b, m);
    if(n == 1)
    {   
        if(m == 1) 
            return Med2(a[0], b[0]);
        
        if(m & 1)//if m is odd
            return Med2(b[m/2], Med3(b[m/2-1], a[0], b[m/2+1]));
        
        //m is even
        
        return Med3(b[m/2], b[m/2-1], a[0]);
    }    
    else if(n == 2)
    {   
        if(m == 2) 
            return Med4(a[0], a[1], b[0], b[1]);
        
        if(m & 1)//overall m+n would be odd
            return Med3(b[m/2], max(a[0], b[m/2 -1]), min(a[1], b[m/2+1]));

        
        return Med4(b[m/2], b[m/2-1], max(a[0], b[m/2 -2]), min(a[1], b[m/2+1]));
    }
    
    int n1 = (n-1)/2;
    int m1 = (m-1)/2;
    
    if(a[n1] < b[m1])
        return getMedian(a+n1, n/2+1, b, m - n1);
    
    return getMedian(a, n/2+1, b+n1, m - n1);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    
    if(nums1Size < nums2Size)
        return getMedian(nums1, nums1Size, nums2, nums2Size);
    
    return getMedian(nums2, nums2Size, nums1, nums1Size);
}
