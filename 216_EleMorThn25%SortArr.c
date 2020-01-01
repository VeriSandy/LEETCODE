/*
1. Linear searching.


*/

int findSpecialInteger(int* arr, int arrSize)
{
    int i = 0;
    int hash[100001] = {0};
    
    int count = 0, index = 0;
    int maxtimes = arrSize/4.0 + 1;
    
    while(i < arrSize)
    {
        hash[arr[i]]++;
        
        if(hash[arr[i]] > count)
        {
            count = hash[arr[i]];
            index = arr[i];
            if(count >= maxtimes)
                break;
        }
        i++;
    }
    
    return index;
}
