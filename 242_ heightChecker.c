int heightChecker(int* heights, int heightsSize)
{
    int hash[101] = {0};
    int i = 0, j = 0, count = 0;
    
    while(i < heightsSize)
    {
        hash[heights[i]]++;
        i++;
    }
    
    i = 1;
    j = 0;
    while(i <= 100 && j < heightsSize)
    {
        while(hash[i]--)
        {
            if(heights[j] != i)
                count++;
            j++;
        }
        i++;
    }
    
    //printf("%d\n", count);
    
    return count;
}


