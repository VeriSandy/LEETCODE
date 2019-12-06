/*
Count Number of zeros. In one pass.
In another pass start from last.
Shift last element to i+CountZero as one zero will be replaced by two zeros.
everytime you meet zero, shifting position(i.e. CountZero) will reduce by 1.

Take care if i+CountZero is out of range then do not consider it simply move to next element.
*/

void duplicateZeros(int* arr, int arrSize)
{
    int i = 0, j = 0;
    
    int CountZero = 0;
    
    i = arrSize -1;
    
    while(i >= 0)
    {
        if(!arr[i])
            CountZero++;
        i--;
    }
    
    if(CountZero == 0) return;
    i = arrSize -1;
    
    //here once you meet zero, shifting positions will reduce by 1.
    //and once CountZero is zero, no more shifting needed
    while(i >= 0 && CountZero > 0)
    {
        if(arr[i])
        {
            
            if(i+CountZero >= arrSize)
            {
                i--;
                continue;
            }
            arr[i+CountZero] = arr[i];
        }
        else//if you meet a zero.
        {
            if(i+CountZero < arrSize)
                arr[i+CountZero] = 0;
            
            CountZero--;
            
            if(i+CountZero < arrSize)
                arr[i+CountZero] = 0;
        }
        i--;
    }
    
    return;
}


