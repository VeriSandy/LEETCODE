
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int l = 0, r = numbersSize -1;
    
    
    
    while(l <= r)
    {
        if(numbers[l] + numbers[r] == target)
            break;
        
        else if (numbers[l] + numbers[r] > target)
            r--;
        else
            l++;
    }
    
    *returnSize = 2;
    
    int *a = malloc(sizeof(int)*2);
    a[0] = l+1;
    a[1] = r+1;
    
    return a;
}
