int minFlips(int a, int b, int c)
{
    int size = sizeof(int)*8;
    printf("%d\n", size);
    int i = 0, count = 0, j = 1;
    
    while(i < size)
    {        
        //if c's bit 1 then we need to make sure at least one bit of either a or b is 1
        if(c & j)
        {
            if(!(a&j) && !(b&j))
                count++;
            
            //printf("[1] %d %d %d\n", i, j, count);
        }
        //if c's bit 0 then we need to make sure bith bits of a's and b's are 0
        else
        {
            if(a & j)
                count++;
            if(b & j)
                count++;
            
            //printf("%d %d %d\n", i, j, count);
        }
        
        i++;
        // 0 1 1 1 1
        // 1 0 1 0 0
        
        // 0 1 0 0 0
        if(i < size -1)
            j <<= 1;
    }
    
    return count;
}
