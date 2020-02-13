/*
Use window concept.
*/

int numOfSubarrays(int* arr, int arrSize, int k, int threshold)
{
    int i = 0, count = 0, j = 0;
    long sum = 0;
    
    while(i < k && i < arrSize)
    {
        sum += arr[i];
        i++;
    }
    //printf("%d\n", sum);
    if(sum/k >= threshold) count++;
    
    while(i < arrSize)
    {
        sum += (arr[i]-arr[j]);
        //printf("%d\n", sum);
        if(sum/k >= threshold) count++;
        i++;
        j++;
    }
    
    return count;
}


