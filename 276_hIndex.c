/*
Here find number of elemnents,which are greater than or equal to the count of elements.

Sort array here, start from back side with count '0.
Go till the point from element is >= count and  keep increasing the count.
Since all the elements will be >= current element so it satifies the problem statement.

Hashing can also be used rather than sorting.
Nad. here also - Start from back side with count '0.
Go till the point from element is >= count and  keep increasing the count.
Since all the elements will be >= current element so it satifies the problem statement.

*/

int compare(void *a, void *b)
{
    return (*(int *)a  - *(int *)b);
}

int hIndex(int* citations, int citationsSize)
{
    qsort(citations, citationsSize, sizeof(int), compare);
    int j = citationsSize -1, max = 0, count = 1;

    while(j >= 0)
    {
        if(citations[j] >=  count)
        {
            max = count;
        }
        count++;
        j--;
    }
    
    return max;
}


