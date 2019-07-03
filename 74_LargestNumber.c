/*
Largest Number - 
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:
Input: [10,2]
Output: "210"
*/

int compare(const void *a, const void *b)
{
    char s1[16] = {0}, s2[16] = {0}, s[32] = {0}, str[32] = {0};
    int i = 30, temp = *((int *)a);
    long long p = 0, q = 0;
    
    //if any element is 0.
    if(temp == 0)
    {
        s1[0] = '0';
    }
    else
    {
        while(temp)
        {
            s[i] = temp%10 + '0';
            temp = temp/10;
            i--;
        }
        i++; 
        strcat(s1, &s[i]);
    }
   
    i = 30;
    temp = *((int *)b);
    
    //if any element is 0.
    if(temp == 0)
    {
        s2[0] = '0';
    }
    else
    {
        while(temp)
        {
            s[i] = temp%10 + '0';
            temp = temp/10;
            i--;
        }
        i++;
        strcpy(s2, &s[i]);
    }
    
    memset(s, 0, sizeof(s));
    
    strcat(s, s1);
    strcat(s, s2);
    strcat(str, s2);
    strcat(str, s1);
    
    
    //printf("%d %d %s %s %s %s %ld %ld\n", 
    //      *((int *)a), *((int *)b), s1, s2, s, str);
    
    
    //we want in reverse order
    //first large, so reverse it.
    //return q - p;
    return strcmp(str, s);
}

char * largestNumber(int* nums, int numsSize){
    
    if(numsSize == 0) return NULL;
    
    qsort(nums, numsSize, sizeof(int), compare);
    
    int i = 0, j = 14;
    char s[16] = {0};    
    int count = 0;
    int temp = 0;
    
    int flag = 0;
    
    while(i < numsSize)
    {
        j = 14;
        temp = nums[i];
        if(nums[i] > 0)
            flag = 1;
        
        memset(s, 0, 16);
        
        if(temp == 0)
        {
            s[j] = '0';
            j--;
            count++;
        }
        else
        {
            while(temp)
            {
                s[j] = temp%10 + '0';
                temp = temp/10;
                j--;
            }
        }
        printf("%d ", nums[i]);
        i++;
        count += 14-j;
    }
    //printf("%d\n", count);
    
    //in case all the elements are 0.
    if(flag == 0)
    {
        char *str = malloc(1 +1);
        memset(str, 0, 1+1);
        str[0] = '0';
        return str;
    }
    
    i = 0;
    char *str = malloc(count +1);
    memset(str, 0, count+1);
    
    while(i < numsSize)
    {
        j = 14;
        temp = nums[i];
        memset(s, 0, 16);
        if(temp == 0)
        {
            s[j] = '0';
            j--;
            count++;
        }
        else
        {
            while(temp)
            {
                s[j] = temp%10 + '0';
                temp = temp/10;
                j--;
            }
        }
        i++;
        j++;
        strcat(str, &s[j]);
    }
    //printf("%s\n", str);
    return str;
}


