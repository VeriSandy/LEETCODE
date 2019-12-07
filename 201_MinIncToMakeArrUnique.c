/*
Ideas --

To make array unique, make all the element different but by keeping min moves.

Have a hash array, find the next empty slot for a number if number is repetitive.

Do not worry we need to only add so only find out next empty slot after any number.
*/
    
int ABS(int a)
{
    return a>0?a:-a;
}

int minIncrementForUnique(int* A, int ASize)
{
    if(ASize <= 0) return 0;
    int hash[40000] = {0};//we can safely use this hash of this size.
    int i = 0, j = 0, k = 40000;
    int totalMove = 0, flag = 0;
    
    while(i < ASize)
    {
        hash[A[i]]++;
        
        if(hash[A[i]] <= 1)
        {
            i++;
            continue;
        }
        
        j = A[i]+1;
        flag = 0;
        while(j < 40000)
        {
            if(hash[j] == 0)
            {
                hash[j]++;
                totalMove += ABS(j - A[i]);
                j++;
                flag = 1;
                break;
            }
            j++;
        }
        
        //If all the slots are filled above the A[i] in above hash array, we can only              move elements after 39999.

        if(!flag)
        {
            totalMove += ABS(k - A[i]);
            k++;
        }
        
        //once move(increase number) is made then that number is no more repetitive
        //so reduce hash count.
        hash[A[i]]--;
        i++;
    }
    return totalMove;
}


