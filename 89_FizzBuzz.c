
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    
    *returnSize = n;
    char **a = NULL;
    if(n == 0 ) return a;
    
    a = malloc(sizeof(char *)*n);
    int i = 1, k = 0;
    
    while(i <= n)
    {
        if(i%3 == 0 && i%5 == 0)
        {
            a[k] = malloc(9);
            memset(a[k], 0, 9);
            strcpy(a[k], "FizzBuzz");
        }
        else if(i%3 == 0)
        {
            a[k] = malloc(5);
            memset(a[k], 0, 5);
            strcpy(a[k], "Fizz");
        }
        else if(i%5 == 0)
        {
            a[k] = malloc(5);
            memset(a[k], 0, 5);
            strcpy(a[k], "Buzz");
        }
        else
        {
            int count = 0, j = i;
            while(j)
            {
                count++;
                j /= 10;
            }
            
            a[k] = malloc(count+1);
            memset(a[k], 0, count+1);
            sprintf(a[k], "%d", i);
        }
     
        printf("%s\n", a[k]);
        i++;
        k++;
    }
    
    
    return a;
}

