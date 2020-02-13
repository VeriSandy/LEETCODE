bool checkIfExist(int* arr, int arrSize)
{
    int min = INT_MAX, max = INT_MIN;
    
    int i = 0, flag = 0;
    int countZero = 0;
    
    while(i < arrSize)
    {
        if(min > arr[i])
            min = arr[i];
        
        if(max < arr[i])
            max = arr[i];
        
        if(!(arr[i]%2))
            flag = 1;
        
        if(arr[i] == 0)
        {
            countZero++;
            if(countZero >= 2)
                return true;
        }
            
        i++;
    }
    
    if(!flag) return false;
    
    int *hash = malloc(sizeof(int)*(max - min +1));
    memset(hash, -1, sizeof(int)*(max - min +1));
    
    printf("%d\n", hash[0]);
    
    i = 0;
    int temp, j,i1 = 0;
    
    while(i < arrSize)
    {
        i1 = arr[i] - min;
        hash[i1] = i;  
        i++;
    }
    
    
    i = 0;
    while(i < arrSize)
    {
        temp = 2*arr[i];
        j = temp - min;
        i1 = arr[i] - min;
        printf("%d %d\n", i1, j);
        
        if(j>= 0 && j < max - min +1 && hash[j] != -1 && hash[i1] != -1 && hash[j] != hash[i1])
            return true;
        
        i++;
    }
    
    return false;
}


