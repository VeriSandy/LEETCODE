/*
Ideas --
1. Backtracking + Permutations.
    0 - 11(1 1 1 1) 
    0 - 59(1 1 1 1 1 1)


    //for 2 leds on
    //both can be from hours
    //both can be from minutes
    //one can be from hour and one can be from minutes

    //for 3 leds on
    //all can from hours
    //all can be from minutes
    //some can from hours and some can be from minutes


    //choose hours
    //orchoose minutes.
    //or choose both

    //in hours, all four leds can't be there.
    //Hours can't be more than 11.
    //in minutes all 6 can't be there.
    // minutes can't be more than 59.
    //turn on i leds for hours.
    //and n-i leds for minutes.

    //generate list of hours, if i LEDs are on.
    //generate list of minutes, if i LEDs are on.
    //and choose from that list.
    //Like for one hour there can be multiple minutes.

2. Other than back tracking 
Try another method. 

Possible hours - {0 t0 11};
Posssible Minutes - {0 to 59}
See For each possibilty, if number of set bits is matching with given set bits, return that combination.
*/

int fib(int n)
{
    if(n <= 1) return 1;
    
    int i = 1;
    int total = 1;
    while(i <= n)
    {
        total = total*i;
        i++;
    }
    return total;
}

//cal ncr = n!/(r!(n-r)!);
int CountTotal(int n, int r)
{
    if(n <= 0 || r <= 0) return 0;
    return (fib(n)/(fib(r)*fib(n-r)));
}

//generate different configurations of time
void Utility(int *a, int start, int end, int *out, int *count,int sum, int counter)
{
    if(end <= 0) 
    {
        out[*count] = 0;
        return;
    }
    if(counter == 0)
    {
        out[*count] = sum;
        *count += 1;
        return;
    }
    int i = start;
    for(; i < end ;i++)
    {
        Utility(a, i+1, end, out, count,sum+a[i],counter-1);
    }
    return;
}


int readBinaryWatchUtility(int num)
{
    if(num == 0) 
    {
        return 1; 
    }
    
    int num1[] = {1, 2, 4 ,8};
    int num2[] = {1, 2, 4, 8, 16, 32};
    
    int count = 0, totalcount = 0;
    int i = 0;
    while(i <= num && i <= 3)
    {
        if(num -i > 5)
        {
            i++;
            continue;
        }
        
        int count1 = CountTotal(4, i);
        int count2 = CountTotal(6, num-i);
        
        if(count1 <= 0) count1 = 1;
        if(count2 <= 0) count2 = 1;
        
        //printf("count1 = %d, count2 = %d\n", count1, count2);
        
        int *out1 = malloc(sizeof(int)*count1);
        int *out2 = malloc(sizeof(int)*count2);
        
        count = 0;
        Utility(num1, 0, 4, out1, &count,0,i);
        count = 0;
        Utility(num2, 0, 6, out2, &count,0,num-i);
        
        int p = 0, q = 0;
        
        for(;p < count1;p++)
        {
            if(out1[p] > 11)
                continue;
            
            for(q = 0;q < count2;q++)
            {
                if(out2[q] > 59)
                    continue;
                totalcount++;
                //printf("%d:%02d\n", out1[p], out2[q]);
            }
        }
        
        free(out1);
        out1 = NULL;
        free(out2);
        out2 = NULL;
        i++;
    }
    //printf("%d\n", totalcount);
    //*returnSize = 0;
    return totalcount;
}


char **readBinaryWatch(int num, int* returnSize)
{       
    int totalcount =  readBinaryWatchUtility(num);
    char **output = malloc(sizeof(char *)*totalcount);
    int i = 0;
    
    if(num == 0) 
    {
        *returnSize = 1;
        output[0] = malloc(6); //6 for "00:00" 
        memset(output[0], 0, 6);
        sprintf(output[0], "0:00");
        return output; 
    }
    
    //printf("-------------\n");
    
    int num1[] = {1, 2, 4 ,8};
    int num2[] = {1, 2, 4, 8, 16, 32};
    
    int count = 0, counter = 0;
    i = 0;
    while(i <= num && i <= 3)
    {
        if(num - i > 5)
        {
            i++;
            continue;
        }
        
        //choose hours
        //orchoose minutes.
        //or choose both
        
        //in hours, all four leds can't be there.
        //Hours can't be more than 11.
        //in minutes all 6 can't be there.
        // minutes can't be more than 59.
        //turn on i leds for hours.
        //and n-i leds for minutes.
        
        //generate list of hours, if i LEDs are on.
        //generate list of minutes, if i LEDs are on.
        //and choose from that list.
        //Like for one hour there can be multiple minutes.
        
        //calculate possible numbers.
        //Utility(num1, 0, i, out1)
        int count1 = CountTotal(4, i);
        int count2 = CountTotal(6, num-i);
        
        if(count1 <= 0) count1 = 1;
        if(count2 <= 0) count2 = 1;
        
        //printf("count1 = %d, count2 = %d\n", count1, count2);
        
        int *out1 = malloc(sizeof(int)*count1);
        int *out2 = malloc(sizeof(int)*count2);
        
        //generate list of hours, if i LEDs are on.
        //generate list of minutes, if i LEDs are on.
        count = 0;
        Utility(num1, 0, 4, out1, &count,0,i);
        count = 0;
        Utility(num2, 0, 6, out2, &count,0,num-i);
        
        int p = 0, q = 0;
        
        for(;p < count1;p++)
        {
            if(out1[p] > 11)
                continue;
            
            for(q = 0;q < count2;q++)
            {
                if(out2[q] > 59)
                    continue;
                output[counter] = malloc(6); //6 for "00:00" 
                memset(output[counter], 0, 6);
                sprintf(output[counter], "%d:%02d", out1[p], out2[q]);
                //printf("%s\n", output[counter]);
                counter++;
            }
        }
        
        free(out1);
        out1 = NULL;
        free(out2);
        out2 = NULL;
        i++;
    }
    //printf("%d\n", counter);
    *returnSize = counter;
    return output;
}
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int SetBits(int n)
{
    int count = 0;
    while(n)
    {
        n = n & (n-1);
        count++;
    }
    return count;
}

int readBinaryWatchUtil(int num)
{
    int i = 0, j = 0, count = 0;
    
    for(i = 0; i < 12; i++)
    {
        for(j = 0; j < 60; j++)
        {
            if(SetBits(i) + SetBits(j) == num)
            {
                count++; 
            }
        }
    }
    
    return count;
}

char **readBinaryWatch(int num, int* returnSize)
{
    int count = readBinaryWatchUtil(num);
    char **output = malloc(sizeof(char *)*count);
    *returnSize = count;
    
    if(num == 0)
    {
        output[0] = malloc(6); //6 for "00:00" 
        memset(output[0], 0, 6);
        sprintf(output[0], "0:00");
        return output;   
    }
    
    int i = 0, j = 0;
    count = 0;
    
    for(i = 0; i < 12; i++)
    {
        for(j = 0; j < 60; j++)
        {
            if(SetBits(i) + SetBits(j) == num)
            {
                output[count] = malloc(6); //6 for "00:00" 
                memset(output[count], 0, 6);
                sprintf(output[count], "%d:%02d", i, j);
                //printf("%s\n", output[count]);
                count++;
            }
        }
    }
    return output;
}
