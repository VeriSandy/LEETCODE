/*
Ideas --
1. 
How about counting sqaures of 
1*1 ==> count no of 1's
2*2 ==> at every element if you can find 2*2 ones, if yes then ans++;
3*3 ==> Repeat as above.
up to  min of(m, n)

2. 
or rather than going again and again to each index.
How about finding max size sqare at one index. 
This way you know no of squares at each index. 
Ex - if 3*3 is max square that means

1*1 == 1
2*2 == 1
3*3 == 1
*/

int countSquares(int** matrix, int matrixSize, int* matrixColSize)
{
    int i = 0, j = 0;
    int k = 0, l = 0;
    int TotalCount = 0, maxSize = 0, localSize = 0;
    int flag = 1;
    int innerflag = 1;
    
    for(i = 0; i < matrixSize; i++)
    {
        for(j = 0; j < *matrixColSize; j++)
        {
            maxSize = 0;
            localSize = 0;
            flag = 1;
            k = i;
            l = j;
            
            //These inner loops to see what is the max size of square at this index.
            if(matrix[k][l])
            {
                while(k <= maxSize+i && k < matrixSize)
                {
                    l = j;
                    innerflag = 1;
                    
                    while(l <= maxSize+j && l < *matrixColSize)
                    {
                        if(matrix[k][l] == 0)
                        {
                            flag = 0;
                            break;
                        }
                        //increase the size when you are done with one sqaure matrix
                        //like 1*1 or 2*2 or 3*3 so on.
                        //else simply bail out from here.
                        if(l == maxSize+j && k == maxSize+i)
                        {
                            maxSize++;
                            
                            innerflag = 0;
                            break;
                        }
                        l++;
                    }
                    
                    localSize = maxSize;
                    
                    if(!flag)
                        break;
                    
                    //go for another row.
                    if(innerflag)
                        k++;
                    
                    //innerflag is to indicate that we are going to check sqare matrix
                    //of next size but only when next size is inside given boundaries.
                    else
                    {
                        //reset k here.
                        if(k <=  maxSize+i && k < matrixSize)
                            k = i;
                        //If not so bail out.
                        else
                            break;
                    }
                }    
                TotalCount += localSize;
            }  
        }
    }
    return TotalCount;
}

