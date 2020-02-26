/*
This is similar to https://leetcode.com/problems/h-index/
Here find number of elemnents,which are greater than or equal to the count of elements.

Go till the point from element is >= count and  keep increasing the count.
Since all the elements will be >= current element so it satifies the problem statement.

Binary search can also be used to look for the elements.

*/

int hIndex(int* citations, int citationsSize)
{
    int r = citationsSize -1, l = 0, max = 0, count = 1;
    int mid = 0;

    while(l <= r)
    {
        mid = (l+r)/2;
        count = citationsSize - mid;
        if(citations[mid] >=  count)
        {
            if(max < count)
                max = count;
            r = mid -1;
        }
        else
            l = mid+1;
    }
    
    return max;
}
