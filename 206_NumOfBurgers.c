/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
1.  Looks like recursion.
    Jumbo burger - 4 tomato slices + 1 cheese slice
    Small Burger - 2 tomato slices + 1
    
2. Can be solve by two below eqautions 
    4*Jumbo+2*Small = tomatoSlices
    Jumbo+Small = cheeseSlices
    
    So we need to find out the value of Jumbo and Small, which gives both equations true.
    Jumbo max can go tomatoSlices/4+1
    Small max can go to tomatoSlices/2+1
    
    So two loops.
    
    int total1 = tomatoSlices/4+1;
    int total2 = tomatoSlices/2+1;
    for(i = 0; i <= total1; i++)
    {
        total2 = (tomatoSlices -i)/2+1;
        for(j = 0; j <= total2; j++)
        {
            if((4*i+2*j == tomatoSlices) && (i+j == cheeseSlices))
            {
                printf("%d %d\n", i, j);
                int *out = malloc(sizeof(int)*2);
                *returnSize = 2;
                out[0] = i;
                out[1] = j;
                return out;
            }
        }
    }
    
    Wait this can be replaced by one loop as we need j which also has the value 
    j = cheeseSlices -i. So why to bear burden of two loops.
    
    //We need a 'j', which gives i+j == cheeseSlices
    //and 4*i+2*j == tomatoSlices
    //So why two loops
    //Just concentrate on that j.

    int total1 = tomatoSlices/4+1;//this will max number of Jumbo Burgers
    int Temp = 0;
    
    for(i = 0; i <= total1; i++)
    {
        j = cheeseSlices - i;
        Temp = 4*i+2*j;
        
        if((Temp == tomatoSlices))
        {
            printf("%d %d\n", i, j);
            int *out = malloc(sizeof(int)*2);
            *returnSize = 2;
            out[0] = i;
            out[1] = j;
            return out;
        }
    }
    
    Still we are going from 0 to tomatoSlices/4+1.
    This can be further reduced to a binary search.
    
*/

int* numOfBurgers(int tomatoSlices, int cheeseSlices, int* returnSize)
{
    int i = 0, j = 0;
    
    int total1 = tomatoSlices/4+1;
    int Temp = 0;
    
    //We need a 'j', which gives i+j == cheeseSlices
    //and 4*i+2*j == tomatoSlices
    //So why two loops
    //Just concentrate on that j.

    /*
    for(i = 0; i <= total1; i++)
    {
        j = cheeseSlices - i;
        Temp = 4*i+2*j;
        
        if((Temp == tomatoSlices))
        {
            printf("%d %d\n", i, j);
            int *out = malloc(sizeof(int)*2);
            *returnSize = 2;
            out[0] = i;
            out[1] = j;
            return out;
        }
    }
    */
    
    //This can be further reduced to binary search.
    int l = 0, r = tomatoSlices/4+1;
    int mid = 0;
    int Small = 0;
    
    while(l <= r)
    {
        mid = (l+r)/2; //Number of Jumbo Burgers
        Small = cheeseSlices - mid;//Number of Small Burgers
        
        Temp = 4*mid + 2*Small;
        
        if(Temp == tomatoSlices)
        {
            int *out = malloc(sizeof(int)*2);
            *returnSize = 2;
            out[0] = mid;
            out[1] = Small;
            return out;
        }
        else if(Temp > tomatoSlices)
            r = mid -1;
        else
            l = mid+1;
    }
    
    *returnSize = 0;
    return NULL;
}
