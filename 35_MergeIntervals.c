/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct 
{
    int x, y;
}Time;
    

int Part(Time *a, int l, int h)
{
    int i = l;
    int index = l;
    
    while(i < h)
    {
        if(a[i].x < a[h].x)
        {
            Time temp = a[i];
            a[i] = a[index];
            a[index] = temp;
            index++;
        }
        i++;
    }
    
    Time temp = a[h];
    a[h] = a[index];
    a[index] = temp;
    
    return index;
}


void QSort(Time *a, int l, int h)
{
    if(l <= h)
    {
        int p = Part(a, l, h);
            
        QSort(a, l, p-1);
        QSort(a, p+1, h);
    }
    return;
}


int** merge(int** intervals, int intervalsSize, int* intervalsColSize, 
            int* returnSize, int** returnColumnSizes)
{
    int i = 0;
    int j = 0;
    int count = 0;

    int **a = NULL;
    *returnColumnSizes = NULL;

    *returnSize = 0;
    
    if(intervalsSize == 0 || *intervalsColSize == 0)
        return a;

    Time temp[intervalsSize];

    
    for(i = 0; i < intervalsSize; i++)
    {
        temp[i].x = intervals[i][0];
        temp[i].y = intervals[i][1];
    }
    
    QSort(temp, 0, intervalsSize -1);
    
    Time temp1[intervalsSize];
    
    for(i = 0; i < intervalsSize; i++)
    {
        temp1[i].x = temp[i].x;
        temp1[i].y = temp[i].y;
    }
    
   // for(i = 0; i < intervalsSize; i++)
   //     printf("(%d %d)\n", temp[i].x, temp[i].y);    
    
    Time t;
    
    for(i = 0; i < intervalsSize -1; i++)
    {
        if(temp1[i].y >= temp1[i+1].y)
        {
            temp1[i+1].x = temp1[i].x;
            temp1[i+1].y = temp1[i].y;
        }
        
        else if(temp1[i].y >= temp1[i+1].x 
                && temp1[i].y <= temp1[i+1].y)
        {
            temp1[i+1].x = temp1[i].x;          
        }
        
        else//if(if(time[i].y < time[i+1].x)), we need another memory to store it
        {
            count++;  
            printf("(%d %d)\n", temp1[i].x, temp1[i].y); 
        }
    }   
    
    //increase count by 1 as last one will not be counted in above loop
    count++;
    printf("%d\n", count);
    printf("(%d %d)\n", temp1[i].x, temp1[i].y); 
   
    a = malloc(sizeof(int *)*count);
    *returnColumnSizes = malloc(sizeof(int)*count);
    
    for(i = 0; i < count; i++)
    {
        a[i] = malloc(sizeof(int)*2);
         (*returnColumnSizes)[i] = 2;
    }
    

    for(i = 0; i < intervalsSize -1; i++)
    {
        if(temp[i].y >= temp[i+1].y)
        {
            temp[i+1].x = temp[i].x;
            temp[i+1].y = temp[i].y;
        }
        
        else if(temp[i].y >= temp[i+1].x 
                && temp[i].y <= temp[i+1].y)
            temp[i+1].x = temp[i].x;          

        else
        {
            a[j][0] = temp[i].x;
            a[j][1] = temp[i].y;
            j++;
        }
    }
    
    a[j][0] = temp[i].x;
    a[j][1] = temp[i].y;
    
    
    *returnSize = count;
    
   // return NULL;
    
    return a;
}
