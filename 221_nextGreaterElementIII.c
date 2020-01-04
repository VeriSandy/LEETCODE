/*
Put digits in an array.

If all the digits are in decreasing order or  all digits are same then no next integer possiblem as it is already in its max form.

Else find the first smaller digit (smaller just from its next digit). If you see the pattern all the digits from last are arranged in increasing order till this pointvexcept this smaller digit.

Replace this smaller digit with the just greater digit than this and greater digit should be from the reamining digits(after this smaller digit till last of this array). These two digits should be exchanged with each other.

Arrange all the digits(from last till next of the smaller digit position) in increasing order. And if you notice this would be just reversal of all the digits from last till next of the smaller digit position.

Finally you have your array, just convert it into a number.

123
132
213
231
321
5132
5213
112
*/

int nextGreaterElement(int n)
{
    if(n == 0) return -1;
    
    int temp = n, count = 0, len = 0;
    int CheckForMaxNoFlag = 1, PrevNo = 0;
    int i = 0, j = 0;
    
    //count the number of digits
    while(temp)
    {
        temp = temp/10;
        count++;
    }
    
    
    //fill the array
    int arr[count];
    temp = n;
    len = count;
    
    count--;
    arr[count] = temp%10;
    PrevNo = arr[count];
    temp = temp/10;
    //printf("%d %d\n", arr[count], count);
    
    count--;
    while(count >= 0)
    {
        arr[count] = temp%10;
        
        if(arr[count] < PrevNo)
            CheckForMaxNoFlag = 0;
        
        PrevNo = arr[count];
        
        //printf("%d %d\n", arr[count], count);
        temp = temp/10;
        count--;
    }
    
    //all digits are in decreasing order or all digits are same so bail out
    if(CheckForMaxNoFlag) return -1;
    

    
    //next thing is to find ==> next number of array.
    //so find first non increasing digit from back towards front.
    i = len -2;
    while(i >= 0)
    {
        if(arr[i] < arr[i+1])
            break;
        
        i--;
    }
    
    printf("first lower digit %d\n", arr[i]);
    
    //find first digit > arr[i] from backside and replace them with each other
    j = len -1;
    while(j > i)
    {
        if(arr[j] > arr[i])
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            break;
        }
        j--;
    }
    
    //Arrange the number(from i+1 position to last) in its min form.
    j = i+1;
    i = len -1;
    while(j < i)
    {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        j++;
        i--;
    }
    
    long temp1 = 0;
    i = 0;
    while(i < len)
    {
        temp1 = temp1*10 + arr[i];
        i++;
    }
    
    printf("%ld\n", temp1);
    
    return temp1 > INT_MAX?-1:temp1;
}


